#!/bin/bash
#
# Script used to test the validity of the ft_ls program
# Usage: bash script_test.sh

##### GLOBAL VARIABLES #####

DIFF_DIR=../diffs
TEST_DIRS=("." "test" "test2" "$HOME/Desktop" ".git" "$HOME")
TEST_INDEX=0

##### TEST FUNCTIONS #####

##############################################################################
# Perform some comparison tests between ls and ./ft_ls on the given directory
# (the -l option is not used)
# Globals:
#	None
# Arguments:
#	Directory name, index of the directory in the TEST_DIRS array
# Output:
#	Writes the number of passed tests to stdout
##############################################################################
tests_on_given_dir()
{
	options=("-1" "-1a" "-1t" "-1tu" "-1tU" "-1tuU" "-1tUu" "-1uU" "-1Uu" "-1rtU" "-1rtuU" "-1rtUu" "-1ruU" "-1rUu" "-1S" "-1rS" "-1St" "-1StU" "-1tS" "-1tUS" "-1F" "-1SF" "-1SFtUr" "-R")

	local i=1
	local nb_passed=0
	local nb_tests=${#options[*]}
	local old_test_index=$(( TEST_INDEX + 1 ))

	printf "Tests on %s: " "$1"

	for opt in "${options[@]}"
	do
		if do_test "$opt"" ""$1"; then
			(( nb_passed++ ))
		fi
		(( i++ ))
	done

	# Print the result
	printf "%d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"
}

#############################################################################
# Execute ls and ./ft_ls with the provided arguments and compare the results
# Global:
#	TEST_INDEX
# Arguments:
# 	A string containing the options and arguments passed to ls and ./ft_ls
# Returns:
#	0 if the results are identical, 1 otherwise
#############################################################################
do_test()
{
	(( TEST_INDEX++ ))

	local res=0

	local result_a=$DIFF_DIR/test"$TEST_INDEX"_a.txt
	local result_b=$DIFF_DIR/test"$TEST_INDEX"_b.txt
	local stderr=$DIFF_DIR/test"$TEST_INDEX"_stderr.txt
	local diff_file=$DIFF_DIR/test"$TEST_INDEX"_diff.txt
	local diff_file_KO=$DIFF_DIR/test"$TEST_INDEX"_diff_KO.txt

	printf "ls %s\n\n" "$1" > $result_a
	printf "ls %s\n\n" "$1" > $result_b

	printf "##### ls stderr #####\n\n" > $stderr

	ls $1 2>> $stderr | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> $result_a

	printf "\n\n##### ./ft_ls stderr #####\n\n" >> $stderr

	./ft_ls $1 2>> $stderr | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11}' >> $result_b

	# Diff
	if diff $result_a $result_b > $diff_file; then
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
#	TEST_INDEX
# Arguments:
#	None
# Output:
#	For each test category, writes the number of passed tests to stdout
########################################################################
basic_tests()
{
	local nb_passed=0
	local nb_tests=0
	local old_test_index=1

	printf "########## Basic tests ##########\n\n"

	# No options, operands
	nb_passed=0
	nb_tests=0

	if do_test; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Test with no options/operands: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# No option, one operand
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "Makefile"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "inc/prototypes.h"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "src"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "inc"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "non_existing_file"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests with no options and one operand: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# Test parsing options
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-a -l -t"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-al -t"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-alt"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests parsing options: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# Test several files
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-1 Makefile inc/prototypes.h Doxyfile"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l Makefile inc/prototypes.h Doxyfile"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-la Makefile inc/prototypes.h Doxyfile"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "Makefile Makefile Makefile"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l Makefile Makefile Makefile"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l . non_existing_file"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests several files: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# Test several directories
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-1 src inc src "; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l inc src"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-1 inc inc"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l inc inc"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l inc non_existing_directory"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests several directories: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	### Test option -a
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-1a src/"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-1al"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -a: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# Test option -l
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-l src/"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l Makefile"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l Makefile src inc"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -l: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# Test option -R
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-R"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-lR"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -R: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# Test option -d
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-1d src"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-1d src inc"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-1d src inc Makefile / /dev $HOME"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-ld src inc Makefile / /dev $HOME"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-Rd"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -d: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# Test option -n
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-lnd src inc Makefile / /dev $HOME"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-nd src inc Makefile / /dev $HOME"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-ln inc/prototypes.h"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests option -n: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	# Tests with a symlink to a directory
	nb_passed=0
	nb_tests=0
	old_test_index=$(( TEST_INDEX +1 ))

	if do_test "-1 test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-1 test2/link_to_test2_itself test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-1R test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-1R test2/link_to_test2_itself test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l test2/link_to_test2_itself test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-lR test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-ltR test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-ltSr test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-lR test2/link_to_test2_itself test2/link_to_test2_itself"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests with a symlink to a directory: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	printf "\n"
}

##############################################################################
# Perform some comparison tests between ls and ./ft_ls on the given directory
# (the -l option is not used)
# Globals:
#	TEST_INDEX
# Arguments:
#	Directory name, index of the directory in the TEST_DIRS array
# Output:
#	Writes the number of passed tests to stdout
##############################################################################
tests_on_given_dir_long_printing()
{
	options=("-l" "-l@" "-le" "-l@e" "-ln" "-lF" "-la" "-lt" "-ltu" "-ltU" "-ltuU" "-ltUu" "-luU" "-lUu" "-lrtU" "-lrtuU" "-lrtUu" "-lruU" "-lrUu" "-lS" "-lrS" "-lSt" "-lStU" "-ltS" "-ltUS" "-lF" "-lSF" "-lSFtUr" "-lR")

	local i=1
	local nb_passed=0
	local nb_tests=${#options[*]}
	local old_test_index=$(( TEST_INDEX + 1 ))

	printf "Tests on %s: " "$1"

	for opt in "${options[@]}"
	do
		if do_test "$opt"" ""$1"; then
			(( nb_passed++ ))
		fi
		(( i++ ))
	done

	# Print the result
	printf "%d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"
}

###########################################################################
# Perform comparison tests between ls and ./ft_ls on each directory of the
# TEST_DIRS array (the -l option is not used here)
# Globals:
#	TEST_DIRS
# Arguments:
#	None
###########################################################################
tests_on_dirs()
{
	local i=1

	printf "########## Test on directories ##########\n\n"

	for current_dir in "${TEST_DIRS[@]}"
	do
		# printf "%s:\n" $current_dir
		tests_on_given_dir "$current_dir" $i
		(( i++ ))
	done

	printf "\n\n"
}

###########################################################################
# Perform comparison tests between ls and ./ft_ls on each directory of the
# TEST_DIRS array (the -l option is used in each test)
# Globals:
#	TEST_DIRS
# Arguments:
#	None
###########################################################################
tests_on_dirs_long_printing()
{
	local i=1

	printf "########## Test on directories - long printing ##########\n\n"

	for current_dir in "${TEST_DIRS[@]}"
	do
		# printf "%s:\n" $current_dir
		tests_on_given_dir_long_printing "$current_dir" $i
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
	local old_test_index=$(( TEST_INDEX + 1 ))

	printf "########## Tests on /dev ##########\n\n"

	if do_test "/dev"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l /dev"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests on /dev: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

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
	local old_test_index=$(( TEST_INDEX + 1 ))

	printf "########## Tests on / ##########\n\n"

	if do_test "/"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	if do_test "-l /"; then
		(( nb_passed++ ))
	fi
	(( nb_tests++ ))

	printf "Tests on /: %d/%d passed" "$nb_passed" "$nb_tests"
	printf " [%d - %d]\n" "$old_test_index" "$TEST_INDEX"

	printf "\n"
}

##### MAIN FUNCTION #####

main()
{
	rm -rf ../diffs
	mkdir $DIFF_DIR

	# Check the presence of ./ft_ls
	if [[ ! -f ./ft_ls ]]; then
		printf "The file ft_ls doesn't exist\n"
		exit 1
	fi

	basic_tests
	tests_on_dirs
	tests_on_dirs_long_printing
	tests_on_dev
	tests_on_root_directory
}

main
