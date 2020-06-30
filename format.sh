tmpFile="tmp"
git add .
git status --porcelain | sed s/^...// > $tmpFile 
cmt="add "
while read fileName 
do 
	echo "ADD FILE: "$fileName
	if [[ $fileName == *.cc ]] || [[ $fileName == *.cpp ]]; then
	    echo "FORMAT FILE: "$fileName
	    clang-format -i --style=file $fileName 
	fi	
	cmt=${cmt}":"${fileName/\/main.cc/} 
done < $tmpFile 
git status 
git commit -am "$cmt" 
#git push 
rm -f $tmpFile
