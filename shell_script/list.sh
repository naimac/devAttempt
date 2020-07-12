#!/bin/ksh
OLD_IFS=$IFS
IFS='|'

var="trololo|lol|youpla|abcde|non|because"
var2="trololo|ouiiii|non"

echo "INITIAL: ${var[@]}"
echo "MASK: ${var2[@]}"
echo ""

result=(`comm -3 -2 <(printf '%s\n' ${var[@]} | sort -u) <(printf '%s\n' ${var2[@]} | sort -u)`)

IFS=$OLD_IFS
echo "RESULT:"
for res in $result
do
	val="$res""_pouet"
	echo $val
done
echo ""

##echo ${OK[0]}
