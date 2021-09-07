#! /bin/bash
echo "START TESTING..."
r1=`./t1.sh`
echo "TEST №1: $r1"
if [[ $r1 = "OK" ]]
then
    r1=1
fi
r2=`./t2.sh`
echo "TEST №2: $r2"
if [[ $r2 = "OK" ]]
then
    r2=1
fi
r3=`./t3.sh`
echo "TEST №3: $r3"
if [[ $r3 = "OK" ]]
then
    r3=1
fi
t=$(( $r3 + $r2 + $r1 ))
echo "$t OUT OF 3 TESTS PASSED"
if [[ $t -eq 3 ]]
then
    echo "ALL TESTS PASS!"
fi