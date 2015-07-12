files=`find sub -type d | sort -r`
for file in $files
do
  bn=`basename $file`
  cd $file/..
  chmod 755 $bn
  mv $bn $(echo $bn | tr a-z A-Z)
  cd 
done
