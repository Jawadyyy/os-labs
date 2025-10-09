#!/bin/bash

echo "Enter a number: "
read num

if [ $num -gt 0 ]
then 
	echo "The number is pos"
elif [ $num -lt 0 ]
then
	echo "the number is neg"
else
	echo "num is zero"
fi
