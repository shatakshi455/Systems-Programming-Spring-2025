#!/bin/bash
k=""
n=0; 
for file in `ls`; do
    if [ -x $file ] && [ -f $file ]; then
        F[(($n))]="$file";
        n=$((n+1))
    fi
done

n=${#F[@]}
s=1
while [ $s -eq 1 ]; do 
    s=0
    i=0
    until [ $((i+1)) -ge "$n" ]; do
        if [ "${F[i]}" -nt "${F[i+1]}" ]; then
            temp=${F[i]}
            F[i]=${F[i+1]}
            F[i+1]=$temp
            s=1
        fi
        i=$((i+1))
    done
done

for file in `echo ${F[@]}`; do
    echo $file
done

