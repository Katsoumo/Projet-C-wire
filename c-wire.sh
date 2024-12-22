#!/bin/bash

afficher_aide() {
    cat << FIN
Utilisation : $0 <chemin> <station> <consommation>
Description :
Ce script v�rifie la validit� des arguments fournis et effectue des op�rations sp�cifiques.

Arguments requis :
  <chemin>        Chemin absolu valide vers un fichier.
  <station>       Doit �tre l'un des suivants : "hvb", "hva", "lv".
  <consommation>  Doit �tre l'un des suivants : "entreprise", "individuel", "tout".

Combinaisons invalides de <station> et <consommation> :
  - hvb-individuel
  - hvb-tout
  - hva-individuel
  - hva-tout
Si une combinaison invalide est fournie, une erreur sera affich�e.

Options :
  -h, --aide      Affiche cette aide et quitte.
FIN
}

# D�but du chronom�tre
debut_script=$(date +%s)

# G�rer l'option d'aide
if [[ "$1" == "-h" || "$1" == "--aide" ]]; then
    afficher_aide
    exit 0
fi

# V�rifier le nombre d'arguments
if [[ $# -ne 3 ]]; then
    echo "Erreur : Nombre d'arguments incorrect."
    afficher_aide
    exit 1
fi

# Assignation des arguments
chemin_fichier=$1
type_station=$2
type_consommation=$3

# V�rifier la validit� du chemin
if [[ ! -f "$chemin_fichier" ]]; then
    echo "Erreur : Fichier introuvable � l'emplacement $chemin_fichier."
    afficher_aide
    exit 2
fi

# V�rifier le type de station
if [[ "$type_station" != "hvb" && "$type_station" != "hva" && "$type_station" != "lv" ]]; then
    echo "Erreur : Type de station invalide : $type_station."
    afficher_aide
    exit 3
fi

# V�rifier le type de consommation
if [[ "$type_consommation" != "entreprise" && "$type_consommation" != "individuel" && "$type_consommation" != "tout" ]]; then
    echo "Erreur : Type de consommation invalide : $type_consommation."
    afficher_aide
    exit 4
fi

# V�rifier et compiler l'ex�cutable si n�cessaire
executable="codeC/MNH_CWire"
if [[ ! -f "$executable" ]]; then
    echo "Compilation de l'ex�cutable manquant..."
    (cd codeC && make clean && make all)
    if [[ ! -f "$executable" ]]; then
        echo "Erreur : La compilation a �chou� pour $executable."
        exit 5
    fi
fi

# Pr�parer le r�pertoire temporaire
dossier_tmp="tmp"
if [[ ! -d "$dossier_tmp" ]]; then
    echo "Cr�ation du r�pertoire temporaire $dossier_tmp..."
    mkdir "$dossier_tmp"
else
    rm -rf "$dossier_tmp/*"
fi

# G�rer les combinaisons station-consommation
case "${type_station}-${type_consommation}" in
    "hvb-entreprise")
        awk -F";" '($2 != "-" && $5 != "-") || ($2 != "-" && $7 != "-") {print $2 ";" $7 ";" $8}' input/c-wire_v25.dat > "$dossier_tmp/hvb_entreprise.csv"
        sed -i 's/-/0/g' "$dossier_tmp/hvb_entreprise.csv"
        fichier_tmp="$dossier_tmp/hvb_entreprise.csv"
        fichier_final="tests/hvb_entreprise.csv"
        ;;
    "hva-entreprise")
        awk -F";" '($3 != "-" && $5 != "-") || ($3 != "-" && $7 != "-") {print $3 ";" $7 ";" $8}' input/c-wire_v25.dat > "$dossier_tmp/hva_entreprise.csv"
        sed -i 's/-/0/g' "$dossier_tmp/hva_entreprise.csv"
        fichier_tmp="$dossier_tmp/hva_entreprise.csv"
        fichier_final="tests/hva_entreprise.csv"
        ;;
    "lv-entreprise")
        awk -F";" '($4 != "-" && $5 != "-") || ($4 != "-" && $7 != "-") {print $4 ";" $7 ";" $8}' input/c-wire_v25.dat > "$dossier_tmp/lv_entreprise.csv"
        sed -i 's/-/0/g' "$dossier_tmp/lv_entreprise.csv"
        fichier_tmp="$dossier_tmp/lv_entreprise.csv"
        fichier_final="tests/lv_entreprise.csv"
        ;;
    "lv-individuel")
        awk -F";" '($4 != "-" && $6 != "-") || ($4 != "-" && $7 != "-") {print $4 ";" $7 ";" $8}' input/c-wire_v25.dat > "$dossier_tmp/lv_individuel.csv"
        sed -i 's/-/0/g' "$dossier_tmp/lv_individuel.csv"
        fichier_tmp="$dossier_tmp/lv_individuel.csv"
        fichier_final="tests/lv_individuel.csv"
        ;;
    "lv-tout")
        awk -F";" '($4 != "-" && $5 != "-") || ($4 != "-" && $6 != "-") || ($4 != "-" && $7 != "-") {print $4 ";" $7 ";" $8}' "$chemin_fichier" > "$dossier_tmp/lv_tout.csv"
        sed -i 's/-/0/g' "$dossier_tmp/lv_tout.csv"
        fichier_tmp="$dossier_tmp/lv_tout.csv"
        fichier_final="tests/lv_tout_minmax.csv"

        if [[ -s "$fichier_tmp" ]]; then
            echo "Nom;Capacit�;Consommation;Diff�rence" > "$fichier_final"
            awk -F";" 'NR > 1 && $2 ~ /^[0-9]+$/ && $3 ~ /^[0-9]+$/ {
                capacite = $2; consommation = $3; difference = capacite - consommation;
                print $0 ";" difference;
            }' "$fichier_tmp" | sort -t';' -k4,4n | {
                head -n 10 >> "$fichier_final"
                tail -n 10 >> "$fichier_final"
            }
        else
            echo "Erreur : Aucune donn�e valide pour lv-tout."
            exit 7
        fi
        ;;
    *)
        echo "Erreur : Combinaison station-consommation invalide."
        afficher_aide
        exit 6
        ;;
esac

# V�rifier ou cr�er le fichier final
[[ ! -f "$fichier_final" ]] && touch "$fichier_final" && chmod +w "$fichier_final"

# Ex�cuter l'ex�cutable
"$executable" "$fichier_tmp" "$fichier_final" > /dev/null
sort -t ';' -k 2,2 "$fichier_final" > /dev/null

# Fin du chronom�tre et affichage du temps �coul�
fin_script=$(date +%s)
temps_ecoule=$((fin_script - debut_script))
echo "Temps total d'ex�cution : $temps_ecoule secondes"