-Description du programme:
Ce programme a été conçu pour faciliter la gestion et l’analyse des données liées à la distribution électrique. Il s’appuie sur un système de traitement en C pour effectuer des calculs complexes et gérer des structures de données avancées, telles que les arbres AVL, garantissant une gestion rapide et équilibrée des informations. Son objectif principal est d’extraire, analyser et présenter des informations essentielles, notamment la consommation et la capacité des différentes stations électriques, tout en permettant une personnalisation selon les préférences de l’utilisateur.

Grâce à une combinaison d'outils Shell et C, le programme offre une interface flexible qui permet à l'utilisateur de filtrer les données selon différents critères et de générer automatiquement des rapports détaillés.


-Instructions pour l'exécution:

Pré-requis
Fichiers nécessaires : Téléchargez le fichier de données c-wire_v25.dat et placez-le dans le dossier input prévu à cet effet.
Dossier de résultats : Assurez-vous qu’un dossier dédié aux résultats est disponible. Si ce n’est pas le cas, le programme le créera automatiquement.
Compilation : Avant l’exécution, compilez le programme avec la commande suivante dans le terminal :
bash
Copier le code
make clean
make

Étapes d’exécution
Ouvrez un terminal et placez-vous dans le répertoire contenant l'exécutable.
Pour lancer le programme, utilisez la commande suivante :
bash

Copier le code
./CY_CWire input/c-wire_v25.dat <choix_station> <choix_consommateur>
<choix_station> : Choisissez parmi les options suivantes : hvb (stations à haute tension), hva (moyenne tension), ou lv (basse tension).
<choix_consommateur> : Sélectionnez le type de consommateur : company (entreprise), individual (particulier), ou all (tous).

Interaction avec le programme
Après le lancement :

Le programme analysera les données contenues dans le fichier spécifié.
Selon vos choix, il identifiera les stations électriques et calculera leur consommation totale ainsi que leur capacité disponible.
Des fichiers de sortie seront générés pour résumer les résultats sous forme de tableaux lisibles.

Vérification des résultats
Les fichiers de sortie contenant les résultats seront automatiquement enregistrés dans le dossier spécifié.
Si ce dossier n'existe pas, il sera créé lors de l’exécution du programme.
Vous pourrez consulter ces fichiers pour vérifier les informations, comme les niveaux de consommation par station et les détails des types de consommateurs.
