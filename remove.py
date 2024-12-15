#!/usr/bin/env python3

import os
import shutil

def main():
    obj_directory = "./obj"
    executable_file = "./debug/space-rocket.exe"

    if os.path.isdir(obj_directory):
        for item in os.listdir(obj_directory):
                    item_path = os.path.join(obj_directory, item)
                    try:
                        if os.path.isfile(item_path):
                            os.remove(item_path)
                            print(f"Removed file: {item_path}")
                        elif os.path.isdir(item_path):
                            shutil.rmtree(item_path)
                            print(f"Removed directory: {item_path}")
                    except OSError as e:
                        print(f"Error removing {item_path}: {e}")

    if os.path.isfile(executable_file):
        try:
            os.remove(executable_file)
            print(f"Removed: {executable_file}")
        except OSError as e:
            print(f"Error removing file: {e}")
    else:
        print(f"The file {executable_file} does not exist.")

if __name__ == "__main__":
    main()
