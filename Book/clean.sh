#!/bin/sh
# Clean all executable files in the current directoy recursively
# find . -executable -type f | xargs rm -f (this command also excludes the clean.sh file itself as it is present in the current directory . )
# find ./Ch* -executable -type f -print # selects only the directories starting with Ch
find ./Ch* -executable -type f | xargs rm -f