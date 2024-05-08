#!/bin/bash

# Check if an argument is provided
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <source_file_path>"
  exit 1
fi

# Capture the source file from the first argument
SOURCE_FILE="$1"

# Check if the source file exists
if [ ! -f "$SOURCE_FILE" ]; then
  echo "Error: File '$SOURCE_FILE' not found"
  exit 1
fi

# Output file name
OUT_FILE_NAME=Solution

# Compile main.cpp with the additional source file
g++ -g main.cpp "$SOURCE_FILE" -o "$OUT_FILE_NAME"

# Check if compilation was successful
# if [ $? -eq 0 ]; then
#   echo "Compilation successful\n"
# else
#   echo "Compilation failed.\n"
#   exit 1
# fi

./"$OUT_FILE_NAME"