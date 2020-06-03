tmpFile="tmp"
git add .
git diff --name-only > $tmpFile 
cmt="add :"
while read fileName 
do 
	#clang-format -i --style=file $fileName 
	echo "ADD FILE: "$fileName
	cmt=${cmt}":"${fileName/\/main.cc/} 
done < $tmpFile 
git status 
git commit -am "$cmt" 
#git push 
rm -f $tmpFile
