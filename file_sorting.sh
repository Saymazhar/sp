#!/bin/bash
#prompt the name of directory

echo "Please enter the name of directory : "
read direct_name

echo "you entered $direct_name"

if [ ! -d "$direct_name"]
  then
    echo "Error: Directory '$direct_name' doesn't exists"
    exit 1
fi

echo -e "\n $direct_name directory exists"

#List all the names in the given directory

echo "List all the files in $direct_name directory are : "
ls "$direct_name"

#Sort all the files alphabetically

echo -e "Files in sorted order are : "
ls $direct_name

neu_direct-$direct_name/sorted
mkdir -p "$new_direct"

count=0
for file in "$direct_name"/*
  do
    if [ -f "$file" ]
    then
      mv "$file" "$new_direct"
      ((count++))
    fi
  done
echo -e "\n Success: $count files moved from Bhanu to Sorted directory."
