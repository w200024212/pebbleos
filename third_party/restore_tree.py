#!/usr/bin/env python3
import json
import os
import shutil
import sys

third_party_dir = os.path.dirname(os.path.abspath(__file__))
top_dir = os.path.abspath(os.path.join(third_party_dir, ".."))

def load_file(file_name):
    global data
    with open(file_name, 'r') as file:
        data = json.load(file)

    return data

def move_files(source, destination):
    print("Moving ", source, " to ", destination)

    # Make sure the destination folder exists
    os.makedirs(os.path.join(top_dir, destination), exist_ok=True)

    if os.path.isfile(os.path.join(third_party_dir, source)):
        # Special case where the initial source is only a file
        shutil.copy(os.path.join(third_party_dir, source),
                    os.path.join(top_dir, destination))
    else:
        # If folder, move all the files there or recurse
        dir_contents = os.scandir(os.path.join(third_party_dir, source))
        for dir_item in dir_contents:
            if dir_item.is_file():
                shutil.copy(os.path.join(third_party_dir, source, dir_item.name),
                    os.path.join(top_dir, destination))
            else:
                move_files(os.path.join(source, dir_item.name),
                           os.path.join(destination, dir_item.name))

    # Then recurse in each of the folders


if __name__ == '__main__':
    # Load data from the JSON file
    json_data = load_file(third_party_dir + '/directory_locations.json')

    # Make sure something got loaded
    if json_data is None or len(json_data)==0:
        print("Could not load file with folders list")
        sys.exit(-1)
    
    # If destination is a list, iterate through them separately
    for folder in json_data:
        if isinstance(folder['destination'], list):
            for target in folder['destination']:
                move_files(folder['source'], target)
        else:
            move_files(folder['source'], folder['destination'])

