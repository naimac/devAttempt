#!/bin/bash

FILE_HEADER_ABSENT="./file_headerAbsent.txt"
FILE_HEADER_PRESENT="./file_headerPresent.txt"
TEMPLATE_FILE="./template"
TMP_TEMPLATE_FILE="/tmp/template"

FILE=$( find $CURRENT_PATH -type f \( -name "*.txt" -o -name "*.java" -o -name "*.c" \) )

:<< stop
# DATE USAGE
#CURRENT_DATE=`date '+%Y-%m-%d %H:%M:%S'`

# BASENAME USAGE
#FILE=$( find $CURRENT_PATH -type f \( -name "*.txt" -o -name "*.java" \) -exec basename {} \; )

# TEST IF HEADER EXIST
VAL=`awk 'NR==2{ print; }' $CURRENT_FILE` # EXTRACT 1ERE LIGNE
#	if [[ "${VAL}" =~ ^.*"@copyright (c)".*$ ]]; then # MISE A JOUR DES PARAMETRES : version / date etc
# 		SED
#	else 
#	fi

stop

for CURRENT_FILE in $FILE
do

	cp $TEMPLATE_FILE $TMP_TEMPLATE_FILE

	HEADER_LENGTH=50

	# CARACTERES DE COMMENTAIRE
	HEADER_EDGE="/"
	HEADER_FILLER="\*"

	# FORMATAGE HEADER : ENCADREMENT BLOC HEADER , 1ere et derniere ligne de commentaire
	i=0
	while [[ $i -lt $HEADER_LENGTH ]]; do
		HEADER_EDGE+="$HEADER_FILLER"
		i=$[$i+1]
	done
	HEADER_EDGE+="/"

	# INSERTION EN TETE
	# HEADER_EDGE_SED=$(echo $HEADER_EDGE | sed 's,/,\\/,g') # AUTRE FACON DE FAIRE
	HEADER_EDGE_SED=$(echo $HEADER_EDGE | sed 's/\\//g')
	sed -ie "1s,^,$HEADER_EDGE_SED\n,g" $TMP_TEMPLATE_FILE

	# INSERTION EN FIN
	echo "$HEADER_EDGE_SED" >> $TMP_TEMPLATE_FILE

	# FORMATAGE HEADER : POSITIONNEMENT CARACTERE DE COMMENTAIRE EN TETE DE LIGNE

	LINE_COUNT=`cat $TMP_TEMPLATE_FILE | wc -l`

	echo $LINE_COUNT

	i=2
	while [ $i -lt $LINE_COUNT ]; do
		sed -i "${i}s/^/\/$HEADER_FILLER/" $TMP_TEMPLATE_FILE
		i=$[$i+1]
	done

	:<< STOP
# TIPS : RAPPEL SYNTAXE POUR COMPTER DES CARACTERES
HEADER_CENTER_END="*/\n" # FIORITURE FACTULATIVE (JUST FOR FUN)
COUNT=${#HEADER_CENTER_END}

i=0

while [ $i -lt 10 ]; do
	VAR+=" "
	i=$[$i + 1]
done

cat $FILE_HEADER_ABSENT >> $TMP_TEMPLATE_FILE
cat $TMP_TEMPLATE_FILE > $FILE_HEADER_ABSENT
vi -O $FILE_HEADER_ABSENT
STOP

cat $CURRENT_FILE >> $TMP_TEMPLATE_FILE
cat $TMP_TEMPLATE_FILE > $CURRENT_FILE
done
