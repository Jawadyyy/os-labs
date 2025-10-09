#!/usr/bin/bash

echo "Enter your Marks"
read marks

if [[ $marks -ge 80 && $marks -le 100 ]]; then
    echo "Your grade is A"

elif [[ $marks -ge 60 && $marks -lt 80 ]]; then
    echo "Your grade is B"

elif [[ $marks -ge 40 && $marks -lt 60 ]]; then
    echo "Your grade is C"

elif [[ $marks -ge 0 && $marks -lt 40 ]]; then
    echo "You Failed"

else 
    echo "Invalid Input"
fi

