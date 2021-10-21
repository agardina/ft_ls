#!/bin/bash

mkdir diffs

ls -1 > diff1
./ft_ls > diff2

diff diff1 diff2

rm -rf diffs
