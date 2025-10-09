echo "Enter filename"
read fname

echo "-------Displaying Current Permissions-------"
ls -l "$fname"

echo "------------Now Making it Executable-------"
chmod +x "$fname"

echo "----------New Permissions of File---------"
ls -l "$fname"

