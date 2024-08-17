#!/bin/bash

# Iterate over each directory
for dir in */; do
    # Enter the directory
    cd "$dir" || continue

    # Rename files by removing leading zero from frame numbers
    for file in wall_*_frame_0[0-2].xpm; do
        # Extract the base name and frame number
        base_name=$(basename "$file" .xpm)
        frame_number="${base_name##*_frame_0}"

        # Construct the new file name with the frame number without the leading zero
        new_file="${base_name%_frame_0*}_frame_$frame_number.xpm"

        # Rename the file
        mv "$file" "$new_file"
        echo "Renamed $file to $new_file"
    done

    # Return to the parent directory
    cd ..
done
