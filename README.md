-Description

Ce projet permet une gestion efficace et une analyse des données de distribution d'électricité en utilisant Shell pour le filtrage et C pour le traitement et les calculs. Il offre une interface simple pour suivre la consommation et la capacité des stations électriques.

-Instructions d'utilisation

Téléchargez au préalable le fichier c-wire_v25.dat et placez-le dans le dossier input.

Assurez-vous que le dossier de remplacement pour les résultats existe, sinon il sera créé automatiquement.

Exécution du script Shell :
Ouvrez un terminal et naviguez jusqu’au répertoire contenant le script c-wire.sh.

Lancez ensuite le programme avec la commande suivante :
./codeC/MNH_CWire input/c-wire_v25.dat <choix station> <choix consommateur>

Interaction avec le programme :
Le programme vous demandera de sélectionner des stations (hvb, hva, lv) ainsi que des types de consommateurs (entreprise, particulier, tout).

Le programme traitera les données selon vos choix et vous fournira les résultats, incluant la consommation et la capacité des stations.

Vérification des résultats :
Les résultats du traitement seront enregistrés dans le dossier spécifié. Si ce dossier n'existait pas, il sera automatiquement créé par le script.




Auteurs
Réalisé avec passion par :

Ilyas Haidar Boustati
Abderahmane Zerargui
Benyoucef Loqman
