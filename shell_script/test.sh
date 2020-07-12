#!/bin/bash

function test
{
	$VAR=find / -type "term2.sh" -exec basename {}\;
	if [ $VAR ]
}
