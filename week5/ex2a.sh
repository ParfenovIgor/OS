#Appending a number into file 1000 times
#Two processes are running simultaniously.
#The output looks like "1 \n 1 \n 2 \n 2 ... 51 \n 51 \n 52 \n 53 \n 53 ..."
#By results of expirement, collide didn't happened 22 times out of 1000
for i in {1..1000}
do
	var1=$(grep -Eo '^[0-9]+$' file.txt | tail -1)
	expr $var1 + 1 >> file.txt
done
