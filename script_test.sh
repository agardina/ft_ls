#!/bin/bash
#
# Script used to test the validity of the ft_ls program

### Global variables ###

DIFF_DIR=../diffs
home_dir=$HOME
test_dirs=("." "test" "test2" $home_dir)
test_index=0

### Test functions ###

##############################################################################
# Perform some comparison tests between ls and ./ft_ls on the given directory
# (the -l option is not used)
# Globals:
#	None
# Arguments:
#	Directory name, index of the directory in the test_dirs array
# Output:
#	Writes the number of passed tests to stdout
##############################################################################
tests_on_given_dir()
{
	options=("-1" "-1a" "-1t" "-1tu" "-1tU" "-1tuU" "-1tUu" "-1uU" "-1Uu" "-1rtU" "-1rtuU" "-1rtUu" "-1ruU" "-1rUu" "-1S" "-1rS" "-1St" "-1StU" "-1tS" "-1tUS" "-1F" "-1SF" "-1SFtUr")

	local i=1
	local nb_passed=0
	local nb_tests=${#options[*]}

	printf "Tests on %s: " $1

	for opt in ${options[*]}
	do
		do_test $opt" "$1
		if (( $? == 0 )); then
			(( nb_passed++ ))
		fi
		(( i++ ))
	done

	# Print the result
	printf "%d/%d passed\n" $nb_passed $nb_tests
}

#############################################################################
# Execute ls and ./ft_ls with the provided arguments and compare the results
# Global:
#	test_index
# Arguments:
# 	A string containing the options and arguments passed to ls and ./ft_ls
# Returns:
#	0 if the results are identical, 1 otherwise
#############################################################################
do_test()
{
	(( test_index++ ))

	local res=0

	local result_a=$DIFF_DIR/test"$test_index"_a.txt
	local result_b=$DIFF_DIR/test"$test_index"_b.txt
	local diff_file=$DIFF_DIR/test"$test_index"_diff.txt
	local diff_file_KO=$DIFF_DIR/test"$test_index"_diff_KO.txt

	echo ls" "$1 > $result_a && echo >> $result_a
	echo ls" "$1 > $result_b && echo >> $result_b

	ls $1 2> /dev/null | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> $result_a
	./ft_ls $1 2> /dev/null | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> $result_b

	# Diff
	diff $result_a $result_b > $diff_file
	if (( $? == 0 )) ; then
		res=0
	else
		res=1
		mv $diff_file $diff_file_KO
	fi
	echo -n "./ft_" | cat - $result_b > $DIFF_DIR/temp && mv $DIFF_DIR/temp $result_b

	return $res
}

########################################################################
# Perform some basic comparison tests between ls and ./ft_ls
# Globals:
#	None
# Arguments:
#	None
# Output:
#	For each test category, writes the number of passed tests to stdout
########################################################################
basic_tests()
{
	local nb_passed=0
	local nb_tests=0

	printf "########## Basic tests ##########\n\n"

	# No options, operands
	nb_passed=0
	nb_tests=0

	do_test
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Test with no options/operands: %d/%d passed\n" $nb_passed $nb_tests

	# No option, one operand
	nb_passed=0
	nb_tests=0

	do_test "Makefile"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "inc/prototypes.h"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "src"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "inc"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests with no options and one operand: %d/%d passed\n" $nb_passed $nb_tests

	# Test parsing options
	nb_passed=0
	nb_tests=0

	do_test "-a -l -t"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-al -t"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-alt"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests parsing options: %d/%d passed\n" $nb_passed $nb_tests

	# Test several files
	nb_passed=0
	nb_tests=0

	do_test "-1 Makefile inc/prototypes.h Doxyfile"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l Makefile inc/prototypes.h Doxyfile"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-la Makefile inc/prototypes.h Doxyfile"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "Makefile Makefile Makefile"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l Makefile Makefile Makefile"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests several files: %d/%d passed\n" $nb_passed $nb_tests

	# Test several directories
	nb_passed=0
	nb_tests=0

	do_test "-1 src inc src "
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l inc src"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-1 inc inc"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l inc inc"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests several directories: %d/%d passed\n" $nb_passed $nb_tests

	### Test option -a
	nb_passed=0
	nb_tests=0

	do_test "-1a src/"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-1al"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -a: %d/%d passed\n" $nb_passed $nb_tests

	### Test option -l
	nb_passed=0
	nb_tests=0

	do_test "-l src/"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l Makefile"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l Makefile src inc"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -l: %d/%d passed\n" $nb_passed $nb_tests

	### Test option -R
	nb_passed=0
	nb_tests=0

	do_test "-R"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-lR"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -R: %d/%d passed\n" $nb_passed $nb_tests

	### Test option -d
	nb_passed=0
	nb_tests=0

	do_test "-1d src"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-1d src inc"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-1d src inc Makefile / /dev $HOME"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-ld src inc Makefile / /dev $HOME"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-Rd"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -d: %d/%d passed\n" $nb_passed $nb_tests

	### Test option -n
	nb_passed=0
	nb_tests=0

	do_test "-lnd src inc Makefile / /dev $HOME"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-nd src inc Makefile / /dev $HOME"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-ln inc/prototypes.h"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -n: %d/%d passed\n" $nb_passed $nb_tests

	printf "\n"
}

##############################################################################
# Perform some comparison tests between ls and ./ft_ls on the given directory
# (the -l option is not used)
# Globals:
#	None
# Arguments:
#	Directory name, index of the directory in the test_dirs array
# Output:
#	Writes the number of passed tests to stdout
##############################################################################
tests_on_given_dir_long_printing()
{
	options=("-l" "-l@" "-le" "-l@e" "-ln" "-lF" "-la" "-lt" "-ltu" "-ltU" "-ltuU" "-ltUu" "-luU" "-lUu" "-lrtU" "-lrtuU" "-lrtUu" "-lruU" "-lrUu" "-lS" "-lrS" "-lSt" "-lStU" "-ltS" "-ltUS" "-lF" "-lSF" "-lSFtUr")

	local i=1
	local nb_passed=0
	local nb_tests=${#options[*]}

	printf "Tests on %s: " $1

	for opt in ${options[*]}
	do
		do_test $opt" "$1
		if (( $? == 0 )); then
			(( nb_passed++ ))
		fi
		(( i++ ))
	done

	# Print the result
	printf "%d/%d passed\n" $nb_passed $nb_tests
}

### Tests ###

###########################################################################
# Perform comparison tests between ls and ./ft_ls on each directory of the
# test_dirs array (the -l option is not used here)
# Globals:
#	test_dirs
# Arguments:
#	None
###########################################################################
tests_on_dirs()
{
	local i=1

	printf "########## Test on directories ##########\n\n"

	for current_dir in ${test_dirs[*]}
	do
		# printf "%s:\n" $current_dir
		tests_on_given_dir $current_dir $i
		(( i++ ))
	done

	printf "\n\n"
}

###########################################################################
# Perform comparison tests between ls and ./ft_ls on each directory of the
# test_dirs array (the -l option is used in each test)
# Globals:
#	test_dirs
# Arguments:
#	None
###########################################################################
tests_on_dirs_long_printing()
{
	local i=1

	printf "########## Test on directories - long printing ##########\n\n"


	for current_dir in ${test_dirs[*]}
	do
		# printf "%s:\n" $current_dir
		tests_on_given_dir_long_printing $current_dir $i
		(( i++ ))
	done

	printf "\n"
}

##################################################################################
# Perform some basic comparison tests between ls and ./ft_ls on the directory /dev
# Globals:
#	None
# Arguments:
#	None
# Output:
#	Writes the number of passed tests to stdout
##################################################################################
tests_on_dev()
{
	local nb_passed=0
	local nb_tests=0

	printf "########## Tests on /dev ##########\n\n"

	do_test "/dev"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l /dev"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests on /dev: %d/%d passed\n" $nb_passed $nb_tests

	printf "\n"
}

#########################################################################
# Perform some basic comparison tests between ls and ./ft_ls on the root
# directory
# Globals:
#	None
# Arguments:
#	None
# Output:
#	Writes the number of passed tests to stdout
#########################################################################
tests_on_root_directory()
{
	local nb_passed=0
	local nb_tests=0

	printf "########## Tests on / ##########\n\n"

	do_test "/"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	do_test "-l /"
	if (( $? == 0 )); then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests on /: %d/%d passed\n" $nb_passed $nb_tests

	printf "\n"
}

main()
{
	rm -rf ../diffs
	mkdir $DIFF_DIR

	# Check the presence of ./ft_ls (to do)

	basic_tests
	tests_on_dirs
	tests_on_dirs_long_printing
	tests_on_dev
	tests_on_root_directory
}

main
