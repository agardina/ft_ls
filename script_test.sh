#!/bin/bash

### Variables ###

DIFF_DIR=../diffs
home_dir=$HOME
# test_dirs=("." "/dev/" $home_dir)
test_dirs=("." "test" "test2" $home_dir)

test_index=0

### Test functions ###

# First arg = directory name, second arg = index of the directory in the director array
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
		if (( $? == 0 ))
		then
			(( nb_passed++ ))
		fi
		(( i++ ))
	done

	# Print the result
	printf "%d/%d passed\n" $nb_passed $nb_tests
}

# First arg = options and arguments passed to ls and ./ft_ls
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

	ls $1 2> /dev/null | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9}' >> $result_a
	./ft_ls $1 2> /dev/null | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9}' >> $result_b

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

basic_tests()
{
	local nb_passed=0
	local nb_tests=0

	printf "########## Basic tests ##########\n\n"

	# No options, operands
	nb_passed=0
	nb_tests=1

	do_test
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	printf "Test with no options/operands: %d/%d passed\n" $nb_passed $nb_tests

	# No option, one operand
	nb_passed=0
	nb_tests=4

	do_test "Makefile"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "inc/prototypes.h"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "src"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "inc"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	printf "Tests with no options and one operand: %d/%d passed\n" $nb_passed $nb_tests

	# Test parsing options
	nb_passed=0
	nb_tests=3

	do_test "-a -l -t"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-al -t"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-alt"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	printf "Tests parsing options: %d/%d passed\n" $nb_passed $nb_tests

	# Test several files
	nb_passed=0
	nb_tests=5

	do_test "-1 Makefile inc/prototypes.h Doxyfile"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-l Makefile inc/prototypes.h Doxyfile"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-la Makefile inc/prototypes.h Doxyfile"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "Makefile Makefile Makefile"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-l Makefile Makefile Makefile"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	printf "Tests several files: %d/%d passed\n" $nb_passed $nb_tests

	# Test several directories
	nb_passed=0
	nb_tests=4

	do_test "-1 src inc src "
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-l inc src"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-1 inc inc"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-l inc inc"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	printf "Tests several directories: %d/%d passed\n" $nb_passed $nb_tests

	### Test option -a
	nb_passed=0
	nb_tests=1

	do_test "-a src/"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	printf "Tests option -a: %d/%d passed\n" $nb_passed $nb_tests

	### Test option -l
	nb_passed=0
	nb_tests=3

	do_test "-l src/"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-l"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	do_test "-l Makefile"
	if (( $? == 0 ))
	then
		(( nb_passed++ ))
	fi

	printf "Tests option -l: %d/%d passed\n" $nb_passed $nb_tests

	printf "\n"
}

# First arg = directory name, second arg = index of the directory in the director array
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
		if (( $? == 0 ))
		then
			(( nb_passed++ ))
		fi
		(( i++ ))
	done

	# Print the result
	printf "%d/%d passed\n" $nb_passed $nb_tests
}

### Tests ###

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

###### Instructions #####

rm -rf ../diffs

# Check the presence of ./ft_ls

mkdir $DIFF_DIR

basic_tests
tests_on_dirs
tests_on_dirs_long_printing
