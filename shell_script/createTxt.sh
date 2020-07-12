#!/bin/bash

# FAIRE UNE SEULE FONCTION GENERIQUE POUR UPDATE TXT
# SUIVANT L ENTREE UTILISATEUR SOIT J APPELLE DELETE SOIT CREATE SOIT LES DEUX

echo "Enter charaters or press 'q':"
INPUT=""
FILENAME=""
read -e INPUT
if  [[ $INPUT = "q" ]]
then
	exit
fi

# on met tous les txt (filename des create.txt) dans une liste
if [[ -z $INPUT ]] # empty
then
	CMD=( $(find $CONF -type f -name \*_create.txt -exec basename {} \; | sed -e 's/_create.txt//g' | sort | uniq) )
	COUNT=${#CMD[@]}
else
	# on met les txt contenant l'input dans une liste
	CMD=( $(find $CONF -type f -name \*"$INPUT"*_create.txt -exec basename {} \; | sed -e 's/_create.txt//g' | sort | uniq) )
	COUNT=${#CMD[@]}
fi

if [[ $COUNT -gt 1 ]] || [[ $COUNT -eq 0 ]]
then
	echo -e "Choose filename among following list, or enter 'q' : \n"
	printf ' %s\n' "${CMD[@]}"
	echo -e "\n"
	read -e FILENAME
elif [[ $COUNT -eq 1 ]]
then
	FILENAME=${CMD[0]}
	echo -e "$FILENAME\n"
else
	echo " Abort !"
fi

if  [[ $FILENAME = "q" ]] || [ -z $FILENAME ]
then
	echo " Abort !"
	exit
else
	echo -e "filename = "$FILENAME
	cd $ROOT/runtime/ \
	&& provadmin exec cart nodename=$NODE_NAME filename=${FILENAME}_create.txt \
	&& cd - 
fi
exit
