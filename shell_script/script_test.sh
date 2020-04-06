#!/bin/bash

BOLD='\033[1m'
NORMAL='\033[0m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# memo
# if [[ $1="toto" ]] est une assignation !!!
# if [[ $1 = "toto" ]] est une comparaison !!!

if [[ "$#" -ne 1 ]]; then
	echo "please enter one of the following arguments : [valid/invalid]"
else
	total=0;
	ko_test=0;
	ok_test=0
	for filename in ./$1_map/*; do
		let total++
		res=$(./fillit $filename 2>&1)
		if [[ ( -z "$res" && $1 = "valid" ) || ( -n "$res" && $1 = "invalid" ) ]] ; then
			echo -e "${GREEN}[OK]${NC} <$res> | $filename"
			let ok_test++
		elif [[ ( -z "$res" && $1 = "invalid" ) || ( -n "$res" && $1 = "valid" ) ]]; then
			echo -e "${RED}[KO]${NC} <$res> | $filename"
			let ko_test++
		fi
	done
	if [ $ok_test -eq $total ]; then
		echo -e "\n${BOLD}${GREEN}OK ! [$(echo 'scale=2;'"$ok_test/$total*100" | bc -l)%]${NC}${NORMAL}"
	else
		echo -e "\n${RED}KO ! FAILURE RATE [$(echo 'scale=2;'"$ko_test/$total*100" | bc -l)%]${NC}"
	fi
	echo "ok_test[$ok_test] ko_test[$ko_test] total[$total]"
fi
