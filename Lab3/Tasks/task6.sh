#!/usr/bin/bash

echo "Enter a Number"
read num

for ((i=1; i<=10; i++)); do
    echo "$num x $i = $((num * i))"
done

