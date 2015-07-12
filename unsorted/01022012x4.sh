#!/bin/bash
a=$(find $1 -type f -perm \-u=x)
while read -r row; do
    result=$($row 1>$row_stderr.txt)
    echo "$row $result" >> outputt.txt
    succ=$(($succ+1))
done <<< "$a"
echo "succ:$succ"
