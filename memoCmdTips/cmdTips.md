# reduire la taille d'une image
for i in *.jpeg; do convert "myimage.jpeg" -quality 20% ./reduced/myimage.jpg; done

# sortir la liste pure (pas de ligne vide, fonctions ne commencent pas par _ des fonctions utilises par un programme
nm ./a.out | cut -d " " -f3 | sed 's/^_//' | sed '/^[[:space:]]*$/d'
