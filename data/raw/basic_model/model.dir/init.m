begin model initialization function										
										
	open "UTBtoEQ.txt" for writing save result as vUTBtoEQLog
	open "STKtoUTB.txt" for writing save result as vSTKtoUTBLog	
	open "Delay.txt" for writing save result as vDelayLog	
										
	set vrRatio = 1.0							
	set vrUTBRatio = 100.0									
	set vRuntime = 13	
/*	
	set i = 0
	while i < 1 do
	begin								
		inc i by 1
		set viParkCapa(i) to 3							
	end
	*/
	set vrSpec to 0.85						
										
	if viParkCapa(1) = 0 then									
		print "No Park" to lParkCount								
										
	set vnOHT(1) = 80	// EVL								
	set vnOHT(2) = 0	// EVS								
	set vnOHT(3) = 0	// EVL-C								
	set vrConv = 6									
	set vrLift = 6									
										
	set viAbnormalUTB to 3									
	set vnUTB = 64									
	set viFrontUTB = 5									
	set viLineUTB = 8									
	set vrStorage = 0									
										
	set vnCapa to vrRatio * 100									
	print "Capa:" vnCapa "%" to lblvnCapa									
	print "EVL-C: " vnOHT(3) " ea" to lblOHT									
										
	call fsetValuable_FilePtr()   /* Call Text Files */									
//	call freadFromto()									
	call freadOHTSpec()     	  /* Set OHT Specification */								
	call freadControl()     	 /* Set run control and parking points */								
										
   return true										
end										
										
begin fsetValuable_FilePtr										
	open "arc/data/EQ_Loc.txt" for reading save result as vfpInFromto									
	open "arc/data/avoid.txt" for reading save result as vfpInControl(2)
	open "arc/data/utb.txt" for reading save result as vfputbtact
	open "arc/data/eq.txt" for reading save result as vfpeqtact
	open "arc/data/stk.txt" for reading save result as vfpstktact
	open "arc/data/conv.txt" for reading save result as vfpconvtact
	
	set viGap to 1
	while vfputbtact eof = false do
	begin
		read vrUTBGap(viGap) from vfputbtact
		inc viGap by 1
	end
	set viGap to 1
	while vfpeqtact eof = false do
	begin
		read vrEQGap(viGap) from vfpeqtact
		inc viGap by 1
	end
	set viGap to 1
	while vfpstktact eof = false do
	begin
		read vrSTKGap(viGap) from vfpstktact
		inc viGap by 1
	end
	set viGap to 1
	while vfpconvtact eof = false do
	begin
		read vrCONVGap(viGap) from vfpconvtact
		inc viGap by 1
	end
										
	open "arc/result/1.output_EVLC.txt" for writing save result as vfpOutResult(1)	
	open "arc/result/1.output_EVLC2.txt" for writing save result as vfpOutResult(6)									
//	open "arc/result/2.output_noUTBcase.txt" for writing save result as vfpOutResult(2)									
//	open "arc/result/3.output_UTBoccupied.txt" for writing save result as vfpOutResult(3)									
//	open "arc/result/4.output_UTBdelayedTime.txt" for writing save result as vfpOutResult(4)
	open "arc/result/2.output_UTBtoEQ.txt" for writing save result as vfUTBtoEQ(1)	
	open "arc/result/2.output_STKtoUTB.txt" for writing save result as vfUTBtoEQ(2)	
	open "arc/result/3.EQcomplete.txt" for writing save result as vfpOutResult(2)	
	open "arc/result/4.EQcompleteType.txt" for writing save result as vfpOutResult(3)
	open "arc/result/UTBtoEQraw.txt" for writing save result as vfpOutResult(4)
	open "arc/result/6.B_Traffic.txt" for writing save result as vfpOutResult(5)											

	print "A\tB\tC\tD\tE" to vfpOutResult(4)
										
	return true									
end										
/*										
begin freadFromto										
	set i = 1									
	while vfpInFromto eof = 0 do									
	begin									
		read vsStream(1) from vfpInFromto with delimiter "\n"								
		read vsaStream(1) from vsStream(1) with delimiter "\t"								
										
		set vroute_FromLoc(i) to vsaStream(1)     			/* From Location */					
		inc i by 1								
	end 									
	return true									
end										
*/										
begin freadOHTSpec										
   set vrNormalVelocity(1) = 2.0 * vrSpec										
   set vrCurveVelocity(1) = 0.5 * vrSpec										
   set vrAcceleration(1) = 1.0 * vrSpec										
   set vrDeceleration(1) = 1.5 * vrSpec										
   set vtLoading(1) = 20										
   										
   set vrNormalVelocity(2) = 2.0 * vrSpec										
   set vrCurveVelocity(2) = 0.5 * vrSpec										
   set vrAcceleration(2) = 1.0 * vrSpec										
   set vrDeceleration(2) = 1.5 * vrSpec										
   set vtLoading(2) = 20										
										
   set vrNormalVelocity(3) = 2.0 * vrSpec										
   set vrCurveVelocity(3) = 0.5 * vrSpec										
   set vrAcceleration(3) = 1 * vrSpec										
   set vrDeceleration(3) = 1.5 * vrSpec										
   set vtLoading(3) = 20										
										
   set vrBrakeDistance = 4.5										
   set vrStopDistance = 0.895										
   set vtResume = 0.5										
										
   return true										
end										
										
begin freadControl										
	set vtRun = 1     		/* Time Unit for Printing Run Result */							
	set vtSchedule = 1   	/* Time Interval between assigning out loads */								
	set vtPriorityCost = 100  									
	set vnTimeWeight = 1.0									
	set vtTimeLimit = 300   									
	set vnPark = 36    		/* Number of parking points */							
										
	set i = 2									
	read vsStream2 from vfpInControl(i) with delimiter "\n"									
	while vfpInControl(i) eof = 0 do									
	begin									
		read vsStream2 from vfpInControl(i) with delimiter "\n"								
		read vlocTemp from vsStream2 with delimiter "\n"	
		if vlocTemp != null then							
			insert vlocTemp into vlocAvoidList								
	end	
	
	set i = 0
	while i < 17 do
	begin
		inc i by 1
		print "pm.cp_Park_"	i to vsTemp
		set vlocTemp to vsTemp
		insert vlocTemp into vlocParkList
	end
										
	return true									
end										
										
begin model snap function 										

	print B_TrafficCheck(1) relative average time, "\t", B_TrafficCheck(1) relative average, "\t", B_TrafficCheck(1) relative maximum to vfpOutResult(5)

	print "Complete(Type): ", vnCompleteType(1), "\t", vnCompleteType(2), "\t", vnCompleteType(3) to message								
	print viEQcomplete(1), "\t", viEQcomplete(2), "\t", viEQcomplete(3), "\t", viEQcomplete(4) to vfpOutResult(3)	
	set vnCompleteType(1) to 0				
	set vnCompleteType(2) to 0								
	set vnCompleteType(3) to 0												
									
	print viEQcomplete(1), "\t", viEQcomplete(2), "\t", viEQcomplete(3), "\t", viEQcomplete(4) to message										
	print viEQcomplete(1), "\t", viEQcomplete(2), "\t", viEQcomplete(3), "\t", viEQcomplete(4) to vfpOutResult(2)									
	set viEQcomplete(1) to 0							
	set viEQcomplete(2) to 0							
	set viEQcomplete(3) to 0							
	set viEQcomplete(4) to 0
					
//	print viComplete2(1), "\t", viComplete2(2), "\t", viComplete2(3), "\t", viComplete2(4), "\t", viComplete2(5), "\t", viComplete2(6), "\t", viComplete2(7), "\t", viComplete2(8) to message									
	set viComplete2(1) to 0									
	set viComplete2(2) to 0 									
	set viComplete2(3) to 0									
	set viComplete2(4) to 0									
	set viComplete2(5) to 0									
	set viComplete2(6) to 0									
	set viComplete2(7) to 0									
	set viComplete2(8) to 0		
/*	
	print tCan(9) relative average, "\t" tCan(10) relative average, "\t" tCan(11) relative average, "\t" tCan(12) relative average, "\t"
		tCap(9) relative average, "\t" tCap(10) relative average, "\t" tCap(11) relative average, "\t" tCap(12) relative average to vfUTBtoEQ(1)
*/										
										
	print tDelDistance(1) relative average, "\t", tRetDistance(1) relative average, "\t", 									
    	  tTotDistance(1) relative average, "\t", tAssignInit(1) relative average, "\t", tAssign(1) relative average, "\t", 									
      	  tUnloadMove(1) relative average, "\t", tLoadMove(1) relative average, "\t", 									
      	  vnRequest(1) / vtRun, "\t", vnComplete(1) / vtRun, "\t", vnDelay(1) / vtRun to vfpOutResult(1)									
      										
	print tDelDistance(1) relative average, "\t", tRetDistance(1) relative average, "\t", 									
    	  tTotDistance(1) relative average, "\t", tAssignInit(1) relative average, "\t", tAssign(1) relative average, "\t", 									
      	  tUnloadMove(1) relative average, "\t", tLoadMove(1) relative average, "\t", 									
      	  vnRequest(1) / vtRun, "\t", vnComplete(1) / vtRun, "\t", vnDelay(1) / vtRun to message									
										
	print tDelDistance(2) relative average, "\t", tRetDistance(2) relative average, "\t", 									
    	  tTotDistance(2) relative average, "\t", tAssignInit(2) relative average, "\t", tAssign(2) relative average, "\t", 									
      	  tUnloadMove(2) relative average, "\t", tLoadMove(2) relative average, "\t", 									
      	  vnRequest(2) / vtRun, "\t", vnComplete(2) / vtRun, "\t", vnDelay(2) / vtRun to vfpOutResult(6)
//	print vinoUTBcase to vfpOutResult(2)									
										
    set vinoUTBcase = 0										
	set vnRequest(1) = 0									
	set vnComplete(1) = 0									
	set vnDelay(1) = 0 										
	set vnRequest(2) = 0									
	set vnComplete(2) = 0									
	set vnDelay(2) = 0 									
										
//	print tUTBdelayTime relative average to vfpOutResult(4)									
										
	return true									
end										
										
/*										
begin pUTB_Util arriving procedure										
	while 1=1 do 									
	begin									
		wait for 5 min								
		set vi to 1								
										
		while vi <= 28 do								// UTB Real Time Count - Total, 210224
		begin								
			if vi <= 4  then inc viUTBLine(1) by cUTB(vi) current else							
			if vi <= 7  then inc viUTBLine(2) by cUTB(vi) current else							
			if vi <= 11 then inc viUTBLine(3) by cUTB(vi) current else							
			if vi <= 14 then inc viUTBLine(4) by cUTB(vi) current else							
			if vi <= 18 then inc viUTBLine(5) by cUTB(vi) current else							
			if vi <= 21 then inc viUTBLine(6) by cUTB(vi) current else							
			if vi <= 25 then inc viUTBLine(7) by cUTB(vi) current else							
			if vi <= 28 then inc viUTBLine(8) by cUTB(vi) current 							
										
			inc vi by 1							
		end								
										
		print viUTBLine(1), "\t", viUTBLine(2), "\t",  viUTBLine(3 ), "\t", viUTBLine(4 ), "\t", viUTBLine(5), "\t", viUTBLine(6), "\t", viUTBLine(7), "\t", viUTBLine(8) , "\t" to vfpOutResult(3)								
										
		set vi to 1								
		while vi <= 8 do								
		begin								
			set viUTBLine(vi) to 0							
			inc vi by 1							
		end								
	end									
end										
*/										
										
										

