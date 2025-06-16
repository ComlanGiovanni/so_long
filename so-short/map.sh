#!/bin/bash

# Dimensions de la carte
width=30
height=11

# Crée un fichier vide map.ber
map_file="map.ber"
> $map_file

# Génération des bords de la carte
border_row=$(printf '1%.0s' $(seq 1 $width))

# Initialiser la carte avec des 0 à l'intérieur et des 1 à l'extérieur
for ((i=1; i<=$height; i++)); do
    if [[ $i -eq 1 || $i -eq $height ]]; then
        echo $border_row >> $map_file
    else
        echo "1$(printf '0%.0s' $(seq 2 $((width-1))))1" >> $map_file
    fi
done

# Fonction pour placer un caractère à une position aléatoire
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

# Placement du personnage P
place_char "P"

# Placement du personnage E
place_char "E"

# Placement aléatoire des objets C (augmentation de la densité)
num_C=20  # Ajustez ce nombre pour plus ou moins de C
for ((i=0; i<$num_C; i++)); do
    place_char "C"
done

# Fonction pour ajouter des murs internes (augmentation de la densité)
place_walls() {
    wall_count=$1
    for ((i=0; i<$wall_count; i++)); do
        place_char "1"
    done
}

# Ajout de murs internes (par exemple, 40 murs internes pour plus de densité)
place_walls 40

# Vérification qu'il y a un chemin entre P et E
while true; do
    # Convertir la carte en format compréhensible pour le BFS
    temp_map=$(sed 's/./& /g' $map_file)
    echo "$temp_map" > temp_map.txt

    # Appel d'un script Python pour vérifier la connectivité (BFS ou DFS)
    python3 << EOF
import numpy as np
from collections import deque

# Charger la carte
with open('temp_map.txt') as f:
    grid = [list(line.strip().split()) for line in f]

height, width = len(grid), len(grid[0])

# Trouver les positions de P et E
def find_positions(grid, char):
    for y in range(height):
        for x in range(width):
            if grid[y][x] == char:
                return (y, x)

start = find_positions(grid, 'P')
end = find_positions(grid, 'E')

# Vérification par BFS
def bfs(grid, start, end):
    queue = deque([start])
    visited = set()
    visited.add(start)

    while queue:
        current = queue.popleft()
        if current == end:
            print("Connected")
            return True

        y, x = current
        for dy, dx in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ny, nx = y + dy, x + dx
            if 0 <= ny < height and 0 <= nx < width and (ny, nx) not in visited:
                if grid[ny][nx] != '1':
                    queue.append((ny, nx))
                    visited.add((ny, nx))

    print("Not Connected")
    return False

if bfs(grid, start, end):
    exit(0)
else:
    exit(1)
EOF

    # Si le chemin est valide, sortir de la boucle
    if [ $? -eq 0 ]; then
        rm temp_map.txt
        break
    else
        # Réinitialiser la carte et recommencer le placement
        > $map_file
        for ((i=1; i<=$height; i++)); do
            if [[ $i -eq 1 || $i -eq $height ]]; then
                echo $border_row >> $map_file
            else
                echo "1$(printf '0%.0s' $(seq 2 $((width-1))))1" >> $map_file
            fi
        done

        place_char "P"
        place_char "E"
        for ((i=0; i<$num_C; i++)); do
            place_char "C"
        done
        place_walls 40
    fi
done
