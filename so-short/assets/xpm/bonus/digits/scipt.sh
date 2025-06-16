#!/bin/bash

# Check if ImageMagick is installed
if ! command -v convert &> /dev/null
then
    echo "ImageMagick is not installed. Please install it first."
    exit 1
fi

# Function to process each directory
process_directory() {
    local dir=$1

    # Iterate over each XPM file in the directory
    for file in "$dir"/*.xpm; do
        if [[ -f "$file" ]]; then
            # Resize the image to 32x32 using ImageMagick's convert command
            convert "$file" -resize 32x32 "$file"
        fi
    done
}

# Iterate over each subdirectory in the current directory
for dir in */; do
    if [[ -d "$dir" ]]; then
        process_directory "$dir"
    fi
done

echo "All images have been resized to 32x32 pixels."
