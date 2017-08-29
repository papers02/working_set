while true; do
        EXTRA=`dmesg -c | grep "tot" | sed 's/^......//' | cut -d' ' -f11`
	WS=`xl dmesg -c | grep working | cut -d' ' -f9`
        
	if [ $EXTRA -gt 4 ]
	then
		NOW=`xl list | grep hvm0 | cut  -c49-52`
        	MEM=$((NOW+EXTRA))
        	DATE=`date +%s`
        	echo "geiger $DATE $MEM $EXTRA"
        	xl mem-set hvm0 $MEM
	else
        	SIZE=`xl list | grep hvm0 | cut -c49-52`
        	DATE=`date +%s`
        	echo "vmware $DATE $(((WS*SIZE/100)+190))"
        	xl mem-set hvm0 $(((WS*SIZE/100)+190))
	fi
        sleep 60
done
