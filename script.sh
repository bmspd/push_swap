#!/bin/bash
echo RESULT OF SORTING
echo ------------
ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
echo ------------
echo NUMBER OF ACTIONS
echo ------------
./push_swap $ARG | wc -l
echo ------------
#./push_swap $ARG
