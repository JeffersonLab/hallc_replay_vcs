#!/bin/tcsh

echo "warning this executable for quick merging files"
echo "will give empty lines for sme junk runs, be carefull"

set rep=`pwd`
@ run = 8824
@ runmax = 9423
set tri="${rep}/mergedruninfo/trigger_mergedruninfo.txt"
set rui="${rep}/mergedruninfo/run_mergedruninfo.txt"
set efi="${rep}/mergedruninfo/eff_mergedruninfo.txt"
rm $tri $rui $efi
touch $tri $rui $efi

while ($run < $runmax)
  #if ( -z "${rep}/singleruninfo/run_info_${run}.txt" ) then
		echo run=$run
    cat ${rep}/singleruninfo/trigger_info_${run}.txt >> $tri
    echo " " >> $tri
    cat ${rep}/singleruninfo/run_info_${run}.txt >> $rui
    echo " " >> $rui
    cat ${rep}/singleruninfo/eff_info_${run}.txt >> $efi
    echo " " >> $efi
    #else
    #endif
  @ run++
end
