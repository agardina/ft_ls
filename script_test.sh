#!/bin/bash

### Variables ###

DIFF_DIR=diffs
user_name=`whoami`
file_name_prefix="test"
file_name_suffix_a="_a"
file_name_suffix_b="_b"
diff_name_suffix="_diff"
home_dir="/Users/$user_name"
test_dirs=("." "/dev/" $home_dir)

### Preparation ###

rm -rf diffs

mkdir $DIFF_DIR

### Utils ###

function get_test_file_name_a
{
	echo $file_name_prefix$1$file_name_suffix_a
}

function get_test_file_name_b
{
	echo $file_name_prefix$1$file_name_suffix_b
}

function get_diff_file_name
{
	echo $file_name_prefix$1$diff_name_suffix
}

### Test functions ###

function tests_on_dir
{
	options=("" "-a" "-t" "-tu" "-tU" "-tuU" "-tUu" "-uU" "-Uu" "-rtU" "-rtuU" "-rtUu" "-ruU" "-rUu" "-S" "-rS" "-St" "-StU" "-tS" "-tUS" "-R" "-Rt" "-RS" "-F")
}

function tests_on_dir_long_format
{
	options=("-l" "-l@" "-le" "-l@e" "-ln" "-Rl" "-lF")
}

### Tests ###

function tests_on_dirs
{
	i=0

	for current_dir in ${test_dirs[*]}
	do
		i=`expr $i + 1`
		printf "%s:\n" $current_dir
		testa=`get_test_file_name_a $i`
		testb=`get_test_file_name_b $i`
		diffname=`get_diff_file_name $i`
		ls -r1tU $current_dir > $DIFF_DIR/$testa
		./ft_ls -tU $current_dir > $DIFF_DIR/$testb
		diff $DIFF_DIR/$testa $DIFF_DIR/$testb > $DIFF_DIR/$diffname
	done
}

tests_on_dirs
