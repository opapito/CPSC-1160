#!/bin/sh

# Clean all executable files in the current directoy recursively
# find . -executable -type f | xargs rm -f (this command also excludes the clean.sh file itself as it is present in the current directory . )
# find ./Ch* -executable -type f -print # selects only the directories starting with Ch

# $? exit status of last foreground process

#find ./Ch* -executable -type f | xargs rm -f


echo "Executable files to be deleted:";
i=0;
for file in $(find ./Ch* -executable -type f);
do
  i=$((i+1));
  fileD=$(echo $file | cut -c11-);
  
  echo "$i=> $fileD";
done

read -p "Delete $i executable files (y|n)?" YN;

if [ "$YN" = "y" ] || [ "$YN" = "Y" ]; then
  (find ./Ch* -executable -type f | xargs rm -f) && echo "Deleted successfully!!!" && exit 0;
else
  echo "Deletion cancelled." && exit 1;
fi
;