#usr/bin/env bash
for ((i = 1; i <=$2; i++))
do
	export NUMSDEF=$(shuf -i 1-$1 | xargs)
	./push_swap $(echo $NUMSDEF) | ./checker_linux $(echo $NUMSDEF)
	./push_swap $(echo $NUMSDEF) | ./checker $(echo $NUMSDEF)
done