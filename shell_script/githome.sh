#!/bin/bash

# sauvegarde des fichiers dans l historique GIT
# GIT est un gestionnaire de version comme SVN et CSV
# pour consulter l historique : git log ou l alias 'gl'
# pour voir si il y a des fichiers qui n ont pas ete sauvegardes : 'gs' (pour 'git status')
# gs | gl | githome peuvent etre lances de n'importe quel dossier

#DATE=`date +%Y-%m-%d\ \| %H:%M:%S`

#gitsave est un repo git local (git --bare)

# OBJECTIF DU SCRIPT : ajouter dans les message de log la date de mise a jour du commit (just for fun)

cd ~/gitsave && git add -A && git commit -m "MAJ_HOME_[ $DATE ] : $*" && cd -
