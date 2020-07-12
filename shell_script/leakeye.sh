#!/bin/bash

function leakeye
{
	while [ 1 ]
	do ps -ef | grep "myProg"
		sleep 1
		clear
	done
}
