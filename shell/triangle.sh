#program to find 3 biggest of three using script methode
if [ $# -ne 3 ]
then
	echo "syntax is $0<no> <no2><no3>"
	exit 1
fi
n1=$1
n2=$2
n3=$3
if [ $n1 -gt $n2 -a $n1 -gt $n3 ]
then
	max=$n1
elif [ $n2 -gt $n1 -a $n2 -gt $n3 ]
then
	max=$n2
else
	max=$n3
fi
if [ `expr $n1 + $n2` -gt $max ]
then
	echo "it is a triangle"
else
	echo "it is not a triangle"
fi
exit 0

