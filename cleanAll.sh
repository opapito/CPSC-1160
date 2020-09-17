#!/bin/sh

# cleanAll.sh
# Clean all executable files (-executable - type f) excluding the current directory (mindepth 2) as well as the hidden .git directory
# (which contains executable scritps)
# find . -executable -type f | xargs rm -f (this command can NOT be used as it also excludes the clean.sh file itself as it is present in the current directory . )
# Checking for executable files can be done with -perm (not recommended) or -executable (recommended, as it takes ACL into account).
# find ./Ch* -executable -type f -print # selects only the directories starting with Ch
# https://superuser.com/questions/38981/how-can-i-find-only-the-executable-files-under-a-certain-directory-in-linux

# $? exit status of last foreground process

# 1) Checking if there is at least one executable file to be deleted. If there is a file, its name will be stored in the variable firstFile.
# The option -quit EXITS find command AFTER FIRST occurrence
# https://unix.stackexchange.com/questions/62880/how-to-stop-the-find-command-after-first-match

#firstFile=$(find ./* -executable -type f -print -quit); --> old version
firstFile=$(find . -mindepth 2 -executable -type f ! -path "./.git/*" -printf '%f\n' -quit);

# 2) The option -z checks if the variable is empty returning true, the message about the absence of file is print and the program exits
# If the variable is not empty, the condition returns false, meaning there are files to be deleted, and the program continues
[ -z "$firstFile" ] && echo "There are no executable files to delete" && exit 0;

# 3) Listing all files to be deleted
echo "Executable files to be deleted:";
i=0;
for file in $(find . -mindepth 2 -executable -type f ! -path "./.git/*" -printf '%f\n');
              # find all executable files (-executable - type f) excluding the current directory (mindepth 2) as well as the hidden .git directory
              # (which contains executable scritps)
              # (find . -mindepth 1 -executable -type f ! -iname ".*" -printf '%f\n') --> this option ( ! -iname ".*" ) excludes the hidden files from the search
do
  i=$((i+1));
  #fileD=$(echo $file | cut -c11-); --> using -printf '%f' is the better aproach to obtaining only the file names. The cut option will not work
                                      # in all situations as the name and length of files vary
  fileD=$(echo $file);
  echo "$i=> $fileD";
done

# 4) Asking for user confirmation before deletion
read -p "Delete $i executable files (y|n)?" YN;

if [ "$YN" = "y" ] || [ "$YN" = "Y" ]; then
  # (find ./* -executable -type f | xargs rm -f) && echo "Deleted successfully!!!" && exit 0;
  (find . -mindepth 2 -executable -type f ! -path "./.git/*" | xargs rm -f) && echo "Deleted successfully!!!" && exit 0;
else
  echo "Deletion cancelled." && exit 1;
fi
;