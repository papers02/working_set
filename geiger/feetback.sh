while true; do
	#dmesg
	EXTRA=`dmesg -c | grep "tot"  | cut -d' ' -f11`
	NOW=`xl list | grep hvm0 | cut  -c49-52`
	MEM=$((NOW+EXTRA))
	DATE=`date +%s`
	echo "$DATE $MEM $EXTRA"
	xl mem-set hvm0 $MEM
	sleep 60
done
