#!/bin/bash
str=$1
K=$2
str2=""
n=0; 

while [ $n -lt ${#str} ]; do 
    case ${str: $n:1} in
        1|3|5|7|9) if [ $((${str: $n:1}+K)) -lt 10 ]; then
            str2="$str2$((${str: $n:1}+K))"
        else
            str2="$str2$((${str: $n:1}+K-10))"
        fi;;
        0|2|4|6|8) if [ ${str: $n:1} -ge $K ]; then
            str2="$str2$((${str: $n:1}-K))"
        else
            str2="$str2$((${str: $n:1}-K+10))"
        fi;;
        *) str2="$str2${str: $n:1}";;
    esac
    n=$((n+1));
done

echo $str $str2