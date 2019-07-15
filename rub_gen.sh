ARG=`ruby -e "puts (1..45).to_a.shuffle.join(' ')"`
#./push_swap $ARG
#./push_swap $ARG | ./checker $ARG
./push_swap $ARG | ./checker -v $ARG
#./push_swap $ARG
#valgrind --leak-check=full ./push_swap $ARG
#valgrind --leak-check=full ./push_swap $ARG | ./checker $ARG
#./push_swap $ARG
#./push_swap $ARG | ./checker $ARG
