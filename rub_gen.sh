ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
