fib(){
  first=1
  second=0
  for i in `seq $1`
  do
    tmp=$first
    first=$(($first+$second))
    second=$tmp
    echo $first
  done
}

filename=$1
extension=$2

#1. Read the file(filename) line by line;
for row in $(cat $filename)
do
  outfile="$(basename $filename | sed 's/\.txt//g')$row.$extension"
  fib $row > $outfile
done
