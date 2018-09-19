for p in {1..10}
do
	while ! ln ex2.txt ex2.txt.lock
	do
		sleep 1
	done


	i=$( tail -n1 ex2.txt)
	i=$((i+1))
	echo ' ' >> ex2.txt
	echo $i >> ex2.txt

	rm -f ex2.txt.lock
done