#!/bin/bash

# Dimensions de la carte
width=30
height=11

# Crée un fichier vide map.ber
map_file="map.ber"
> $map_file

# Initialiser la carte avec des 1 (tout est mur au départ)
for ((i=1; i<=$height; i++)); do
    echo $(printf '1%.0s' $(seq 1 $width)) >> $map_file
done

# Fonction pour creuser un passage dans le labyrinthe
carve_passage() {
    local x=$1
    local y=$2
    local directions=(N S E W)

    # Mélange les directions pour un labyrinthe aléatoire
    for ((i=0; i<4; i++)); do
        j=$((RANDOM % (i+1)))
        tmp=${directions[$i]}
        directions[$i]=${directions[$j]}
        directions[$j]=$tmp
    done

    for dir in "${directions[@]}"; do
        case $dir in
            N)
                nx=$x
                ny=$((y - 2))
                wallx=$x
                wally=$((y - 1))
                ;;
            S)
                nx=$x
                ny=$((y + 2))
                wallx=$x
                wally=$((y + 1))
                ;;
            E)
                nx=$((x + 2))
                ny=$y
                wallx=$((x + 1))
                wally=$y
                ;;
            W)
                nx=$((x - 2))
                ny=$y
                wallx=$((x - 1))
                wally=$y
                ;;
        esac

        if [[ $ny -gt 1 && $ny -lt $height && $nx -gt 1 && $nx -lt $width ]]; then
            line=$(sed "${ny}q;d" $map_file)
            if [ "${line:nx-1:1}" = "1" ]; then
                sed -i "${y}s/./0/${x}" $map_file
                sed -i "${wally}s/./0/${wallx}" $map_file
                sed -i "${ny}s/./0/${nx}" $map_file
                carve_passage $nx $ny
            fi
        fi
    done
}

# Démarrer le labyrinthe à une position aléatoire
startx=$((RANDOM % (width / 2) * 2 + 2))
starty=$((RANDOM % (height / 2) * 2 + 2))

carve_passage $startx $starty

# Fonction pour placer un caractère sur une case libre (0)
place_char() {
    char=$1
    while true; do
        x=$((RANDOM % (width - 2) + 2))
        y=$((RANDOM % (height - 2) + 2))
        line=$(sed "${y}q;d" $map_file)
        if [ "${line:x-1:1}" = "0" ]; then
            sed -i "${y}s/./${char}/${x}" $map_file
            break
        fi
    done
}

# Placer les caractères P et E
place_char "P"
place_char "E"

# Placer un nombre aléatoire de C
num_C=20  # Ajustez ce nombre pour plus ou moins de C
for ((i=0; i<$num_C; i++)); do
    place_char "C"
done

# Afficher le labyrinthe généré
cat $map_file
