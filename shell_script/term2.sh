
# extrait l'adresse remote d'un git, by ju 
gcp() {
	#	if [ -z $1 ]; then
	#		1="./"
	#	fi
	URL=$(git -C "${1}" config -l | grep "remote.origin.url" | sed -E 's/.*=(.*)/\1/' | tr -d '\n')
	if [ -n "$URL" ]; then
		/bin/echo -n "$URL" | pbcopy
		/bin/echo "$URL"
	else
		echo "Not a valid git repository."
	fi
}

PROMPT="\e[1;33m\u@\h[bash]>\A> \e[0m\e[0;32m\w\e[0m " 
PROMPT_COMMAND=git_prompt

function git_prompt {
#	ISGIT=$(git status --ignore-submodules 2> /dev/null)
	ISGIT=$(git status 2> /dev/null)
	NOCOLOR='\033[0m'
	if [ -n "$ISGIT" ]
	then
		BRANCH=" $(git branch | cut -d ' ' -f 2 | tr -d '\n') "
		STATUS=$(echo "$ISGIT" | grep "modified")
		if [ -n "$STATUS" ]
		then
			# red
			COLOR='\033[1;31m'
		else
			REMOTE_EXIST=$(git branch -a | grep remotes/origin/"$BRANCH")
			if [ -n "$REMOTE_EXIST" ]
			then
				# REMOTE=$(git diff --ignore-submodules origin/"$BRANCH")
				REMOTE=$(git diff origin/$BRANCH $BRANCH)
				if [ -n "$REMOTE" ]
				then
					# yellow
					COLOR='\033[1;33m'
				else
					# green
					COLOR='\033[1;32m'
				fi
			else
				# green
				COLOR='\033[1;33m'
			fi
		fi
		# echo -e "${COLOR}$BRANCH${NOCOLOR}"
		PS1="$PROMPT$COLOR$BRANCH$NOCOLOR"
#PS1=`PWD`
	else
		PS1="$PROMPT"
	fi
}
