#! /bin/bash


mkdir a b c
touch ./a/aa.txt ./b/bb.txt ./c/cc.txt ./m.txt
a=$(echo `./script.sh -dir .`)
b="2 sh txt"

if [[ $a == "$b" ]]
then
    echo "OK"
else
    echo "FAIL"
fi
rm -rf a b c m.txt