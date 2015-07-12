for pid in $*
do
  echo "bg $(pidof $pid)"
  pid[]=$(pidof $pid)"
done
for pid in $*
do
  sleep 5
  if[[pidof $pid]]
  echo "bg $(pidof $pid)"
done
