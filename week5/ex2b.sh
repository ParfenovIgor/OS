#Appending a number into file 1000 times.
#Two processes are running simultaniously.
#But now, when process starting to update file, it locks it.

i=0
while [ $i -le 999 ]
do
	if ln file.txt file.txt.lock
	then
		var1=$(grep -Eo '^[0-9]+$' file.txt.lock | tail -1)
		expr $var1 + 1 >> file.txt.lock
		rm file.txt.lock
	else
		i=$(($i-1))
	fi
	i=$(($i+1))
done
