#! /bin/bash


mkdir a b c
touch ./a/aa.txt ./b/bb.txt ./c/cc.txt ./a/aa.docx
a=$(echo `./script.sh -dir .`)
b="3 docx sh txt"
if [[ "$a" == "$b" ]]
then
    echo "OK"
else
    echo "FAIL"
fi
rm -rf a b c