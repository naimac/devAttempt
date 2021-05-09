#!/bin/bash

CURRENT_PATH=$(pwd)
CURRENT_DATE=`date '+%Y-%m-%d %H:%M:%S'`
CURRENT_YEAR=`date '+%Y'`
USERNAME=`git config user.name`
FILE=$( find $CURRENT_PATH -type f \( -name "*.txt" -o -name "*.java" \) -exec basename {} \; )
VERSION=0.0

for var in $FILE
do
	EXTENSION="${var##*.}"
	if [ $EXTENSION = "java" ]; then
		first_line="/***********************************************************/"
		end_line=$first_line
		middle_start="/*"
		middle_end="*/"
	elif [ $EXTENSION = "txt" ]; then
		first_line="#################################################"
		end_line=$first_line
		middle_start="#"
		middle_end="#"
	fi

TEMPLATE="$first_line\n
$middle_start bla bla bla $middle_end\n
$middle_start bla bPOUPOUPOUPOPOU $middle_end\n
$middle_start bla blOIYEIYOIAGFOAIUEYROIEAYRa $middle_end\n
$middle_start bla $middle_end\n
$end_line"

echo -e $TEMPLATE > $var

done

:<<END
TEMPLATE="@copyright (c) $YEAR Airbus Defence and Space SAS  - All Rights Reserved\n
Airbus Defence and Space owns the copyright of this document.\n
Redistribution and use in source and binary forms, with or without modification, is strictly forbidden without the prior permission of the owner.\n
\n
SDN PROBES - PHCD\n
Version : $VERSION\n
Date : $CURRENT_DATE\n
Author : $USERNAME
\n
Dev tool and langage\n
- C++/scripting shell\n
- GNU gcc/gpp\n
\n
-----------------------------------------------------------------------------------\n
This version includes:\n
- source code and configuration file for SDN Probes, including PHCD and Visibility\n
\tversion $VERSION ($CURRENT_DATE)\n
\n
- reference documents\n
\t- Applications Design documents :\n
\tPHCD Probe SDD v0.3\n
\t- 	Visibility Sensors v0.1\n"

END

