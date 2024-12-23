-Description du programme:
Ce programme a été conçu pour faciliter la gestion et l’analyse des données liées à la distribution électrique. Il s’appuie sur un système de traitement en C pour effectuer des calculs complexes et gérer des structures de données avancées, telles que les arbres AVL, garantissant une gestion rapide et équilibrée des informations. Son objectif principal est d’extraire, analyser et présenter des informations essentielles, notamment la consommation et la capacité des différentes stations électriques, tout en permettant une personnalisation selon les préférences de l’utilisateur.
Grâce à une combinaison d'outils Shell et C, le programme offre une interface flexible qui permet à l'utilisateur de filtrer les données selon différents critères et de générer automatiquement des rapports détaillés.


-Instructions pour l'exécution:

-Pré-requis
1. Fichiers nécessaires :
Placez le fichier de données c-wire_v25.dat dans le dossier input du projet.
2. Dossiers requis :
Créez les dossiers tmp et tests à la racine du projet si ceux-ci n'existent pas.
3. Compilation:
Accédez au dossier codeC et compilez le projet avec le Makefile:
cd codeC
make clean
make
cd ..

-Étapes d'exécution:
1. Lancez le script Shell en fournissant les arguments requis: ./c-wire.sh input/c-wire_v25.dat <choix_station> <choix_consommateur>
2. Exemple d’exécution: ./c-wire.sh input/c-wire_v25.dat hvb entreprise

-Vérification des résultats:
Verifiez que les fichiers les fichiers générés sont enregistrés automatiquement dans tmp et tests.

Auteurs: Benyoucef Loqman, Haidar Boustati Ilyas, Zerargui Abderrahmane 
