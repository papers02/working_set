while true; do
	WS=`xl dmesg -c | grep working | cut -d' ' -f9`
	SIZE=`xl list | grep hvm0 | cut -c49-52`
	date +%s
	echo "old: $SIZE proc: $WS new: $(((WS*SIZE/100)+130))"
	xl mem-set hvm0 $(((WS*SIZE/100)+130))
	sleep 60
done
