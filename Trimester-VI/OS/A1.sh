#!/bin/bash

echo "Enter string: "
read c
echo "${c,,}"

echo "Enter string: "
read c
echo "${c^^}"

ops()
{
    #res=`echo $2 $3 $4 | bc -l`
    res="$(($2 $3 $4))"
    echo "$1 $res"
}

while :
do
    echo "Enter first value: "
    read a
    echo "Enter second value: "
    read b
    echo -e "MENU:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit"
    read ch
    case $ch in
    1) ops "Addition -" $a "+" $b;;
    2) ops "Subtraction -" $a "-" $b;;
    3) ops "Multiplication -" $a "*" $b;;
    4) ops "Division -" $a "/" $b;;  
    5) exit;;
    esac
done