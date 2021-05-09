#!/bin/bash

FILE="./test.txt"

VAR=$(stat -c %y ${FILE} | cut -d " " -f1)
sed -i "s/[0-9]\{2\}\/[0-9]\{2\}\/[0-9]\{2\}/$VAR/g" $FILE

cat ${FILE}
