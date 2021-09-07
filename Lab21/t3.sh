#! /bin/bash
a=$(echo `./script.sh`)
b="dir is undefined"
if [[ $a == "$b" ]]
then
    echo "OK"
else
    echo "FAIL"
fi