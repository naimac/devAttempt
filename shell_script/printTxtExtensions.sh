#!/bin/bash

function printTst
{
	RES=( $(find $CONF -type f -name \*_create.txt -exec basename {} \; | sed -e 's/_create.txt//g' | sort | uniq) )
	printf '%s\n' "${RES[@]}"
}
