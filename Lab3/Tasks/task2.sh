#!/usr/bin/bash

echo "Enter your First Number"
read num1

echo "Enter your Second Number"
read num2

echo "Choose Operation"
echo "1- +"
echo "2- -"
echo "3- x"
echo "4- /"
read opt

if [[ $opt -eq 1 ]]; then
	res=$((num1+num2))
	echo "$res"
		
elif [[ $opt -eq 2 ]]; then
	res=$((num1-num2))
	echo "$res"
		
elif [[ $opt -eq 3 ]]; then
	res=$((num1*num2))
	echo "$res"
		
elif [[ $opt -eq 4 ]]; then
	res=$((num1/num2))
	echo "$res"
	
else 
 	echo "Wrong Input"
 	
fi
