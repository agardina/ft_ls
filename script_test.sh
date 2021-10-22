#!/bin/bash

### Variables ###

DIFF_DIR=../diffs
file_name_prefix="test"
file_name_suffix_a="_a"
file_name_suffix_b="_b"
diff_name_suffix="_diff"
home_dir=$HOME
# test_dirs=("." "/dev/" $home_dir)
test_dirs=("." "test" "test2" $home_dir)

### Utils ###

get_test_file_name_a()
{
	echo $file_name_prefix$1_$2$file_name_suffix_a
}

get_test_file_name_b()
{
	echo $file_name_prefix$1_$2$file_name_suffix_b
}

get_diff_file_name()
{
	echo $file_name_prefix$1_$2$diff_name_suffix
}

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
		testa=`get_test_file_name_a $2 $i`
		testb=`get_test_file_name_b $2 $i`
		diffname=`get_diff_file_name $2 $i`
		printf "ls %s %s\n\n" $opt $1 > $DIFF_DIR/$testa
		printf "ls %s %s\n\n" $opt $1 > $DIFF_DIR/$testb
		ls $opt $1 >> $DIFF_DIR/$testa 2> /dev/null
		./ft_ls $opt $1 >> $DIFF_DIR/$testb 2> /dev/null
		diff $DIFF_DIR/$testa $DIFF_DIR/$testb > $DIFF_DIR/$diffname
		if (( $? == 0 )) ; then
			(( nb_passed++ ))
			mv $DIFF_DIR/$diffname $DIFF_DIR/$diffname"_OK"
		fi
		echo -n "./ft_" | cat - $DIFF_DIR/$testb > $DIFF_DIR/temp && mv $DIFF_DIR/temp $DIFF_DIR/$testb
		(( i++ ))
	done

	# Print the result
	printf "%d/%d passed\n" $nb_passed $nb_tests
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
		testa=`get_test_file_name_a $2 $i`
		testb=`get_test_file_name_b $2 $i`
		diffname=`get_diff_file_name $2 $i`
		printf "ls %s %s\n\n" $opt $1 > $DIFF_DIR/$testa
		printf "ls %s %s\n\n" $opt $1 > $DIFF_DIR/$testb
		ls $opt $1 2> /dev/null | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9}' >> $DIFF_DIR/$testa
		./ft_ls $opt $1 2> /dev/null | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9}' >> $DIFF_DIR/$testb
		diff $DIFF_DIR/$testa $DIFF_DIR/$testb > $DIFF_DIR/$diffname
		if (( $? == 0 )) ; then
			(( nb_passed++ ))
			mv $DIFF_DIR/$diffname $DIFF_DIR/$diffname"_OK"
		fi
		echo -n "./ft_" | cat - $DIFF_DIR/$testb > $DIFF_DIR/temp && mv $DIFF_DIR/temp $DIFF_DIR/$testb
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

rm -rf ../diffs

mkdir $DIFF_DIR

# tests_on_dirs
tests_on_dirs_long_printing
