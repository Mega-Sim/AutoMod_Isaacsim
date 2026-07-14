begin pEQZone arriving procedure
	set anLoadType = 1
												
	move into alocConv(1)																			
	inc cEQBuffer(aiPort) by 1																			
	travel to alocConv(2)																			
																				
// EQ Service Time ----------------------------------------------------------------------------------------------------------------------------------------------------																				
	move into Q_Port(aiPort)																			
	dec cEQBuffer(aiPort) by 1																			
																				
	if cEQBuffer(aiPort) current < 1 then																			
	begin																			
		inc cEQBufferEmpty(aiPort) by 1																		
		clone 1 load to pEQBufferCheck																		
	end	
	else if cEQBuffer(aiPort) current = 1 then																			
	begin																			
		inc cEQBufferCapa1(aiPort) by 1																		
	end	
	else if cEQBuffer(aiPort) current = 2 then																			
	begin																			
		inc cEQBufferCapa2(aiPort) by 1																		
	end	
	else if cEQBuffer(aiPort) current = 3 then																			
	begin																			
		inc cEQBufferCapa3(aiPort) by 1																		
	end																		
																	
	wait for 125 seconds	 																		
																			
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------																				
																				
	move into alocConv(3)																			
	set this load color to thistle	
	
// New Box Call ------------------------------------------------------------------------------------------------------------------------------------------------------																				
	set viRandom to oneof(100 - vrStorage:1, vrStorage:2)			//vrStorage : indirect																
																				
	if viRandom = 1 then																			
		clone 1 load to pUTB_Selection 																		
	else if viRandom = 2 then		 																	
		clone 1 load to pSTKtoEQ																									
																				
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------																				
																				
	travel to alocConv(4)																			
																				
	set anDeliverType = 0																			
	set anTransfer = 1																			
	inc vnRequest(anLoadType) by 1																			
	inc vnRequesti(aiLine) by 1																			
																							
	insert this load into vlistLoad(anLoadType)																			
																				
	set atTR to ac																			
																				
	print alocTo to vsTempTo																			
	set vi to vsTempTo substring(14,1)																			
	set vi to vi + 1																			
	set vsTempTo to vsTempTo substring(1,13)																			
	print vsTempTo vi to vsTempTo																			
	set alocFrom to vsTempTo																			
	set aiDeliverType to 3		
	
	set anGapType = 2	/* anGapType 1:UTB, 2:EQ, 3:STK, 4:CONV */																		
																				
	move into alocFrom		
	
	set anGapType = 4	/* anGapType 1:UTB, 2:EQ, 3:STK, 4:CONV */																		
																				
	set aDistance to this vehicle total distance traveled       /* distance measured until load placed at from location */																			
	set aRetDistance to aDistance - this vehicle vhlRetDistance  																			
	inc viOutNumbering by 1																			
																				
	if aiLine = 1 then set alocOut to nextof(pm.cp_Out_1, pm.cp_Out_2) else																			
	if aiLine = 2 then set alocOut to nextof(pm.cp_Out_3, pm.cp_Out_4) else																			
	if aiLine = 3 then set alocOut to nextof(pm.cp_Out_5, pm.cp_Out_6) else																			
	if aiLine = 4 then set alocOut to nextof(pm.cp_Out_7, pm.cp_Out_8) 																			
																				
	set alocTo to alocOut																			
	travel to alocTo																			
	set atLoad to ac + this vehicle arSetDownTime																		
	set aDelDistance to this vehicle total distance traveled - aDistance																			
	set aTotDistance to aRetDistance + aDelDistance																			
																				
	inc cOut(3) by 1																			
																				
   	tabulate atLoad - atTR in tDT_Out																			
	call sReport																			
	send to pExit																			
end																				
																				
begin pSTKtoUTB arriving procedure																				
																
	set alocTo to alocFrom																			
	if aiLine = 1 then set vstrTemp to nextof("pm.cp_A01001", "pm.cp_A01002", "pm.cp_A01003", "pm.cp_A01004") else																			
	if aiLine = 2 then set vstrTemp to nextof("pm.cp_A01005", "pm.cp_A01006", "pm.cp_A01007", "pm.cp_A01008") else																			
	if aiLine = 3 then set vstrTemp to nextof("pm.cp_A01009", "pm.cp_A01010", "pm.cp_A01011", "pm.cp_A01012") else																			
	if aiLine = 4 then set vstrTemp to nextof("pm.cp_A01013", "pm.cp_A01014", "pm.cp_A01015", "pm.cp_A01016") 																			
																				
	set alocFrom to vstrTemp																			
																				
    set anDeliverType = 1																			
	set anTransfer = 1																			
	inc vnRequest(anLoadType) by 1																			
	inc vnRequesti(aiLine) by 1															
	insert this load into vlistLoad(anLoadType)	
	
	set anGapType = 3	/* anGapType 1:UTB, 2:EQ, 3:STK, 4:CONV */																		
																				
	set atTR to ac 																			
	set aiDeliverType to 1																			
	move into alocFrom
	 
	set anGapType = 1	/* anGapType 1:UTB, 2:EQ, 3:STK, 4:CONV */					
					
	set aDistance to this vehicle total distance traveled       /* distance measured until load placed at from location */																			
	set aRetDistance to aDistance - this vehicle vhlRetDistance  																			
																				
	travel to alocTo
	clone 1 load to pInsertToUTB  			
							
	if this vehicle aiLocChange = 1 then																			
	begin																			
		set this vehicle aiLocChange = 0																		
		set this load aiLocChange = 1																		
	end																			
																				
	if aiPreMove = 1 then 																			
		set aiPreMove to 0																		
																				
	set atLoad to ac + this vehicle arSetDownTime																		
	set aDelDistance to this vehicle total distance traveled - aDistance																			
	set aTotDistance to aRetDistance + aDelDistance																			
																				
	print alocFrom, "\t" alocTo, "\t" atLoad - atTR, "\t"  aDelDistance to vSTKtoUTBLog																			
																				
   	tabulate atLoad - atTR in tDT_STKtoUTB																			
	call sReport																			
																				
	if this load aiLocChange = 1 then																			
	begin																			
		set this load aiLocChange = 0																		
		send to pEQZone																		
	end																			
	else																			
	begin																			
		move into Q_UTB(aiPort)																		
																				
		if aiLine = 1 and aiPort = 1 then inc cUTBCan9(1) by 1 else 																		
		if aiLine = 1 and aiPort = 2 then inc cUTBCan9(2) by 1 else																		
		if aiLine = 1 and aiPort = 3 then inc cUTBCap9(1) by 1 else																		
		if aiLine = 1 and aiPort = 4 then inc cUTBCap9(2) by 1 else																		
		if aiLine = 2 and aiPort = 5 then inc cUTBCan10(1) by 1 else																		
		if aiLine = 2 and aiPort = 6 then inc cUTBCan10(2) by 1 else																		
		if aiLine = 2 and aiPort = 7 then inc cUTBCap10(1) by 1 else																		
		if aiLine = 2 and aiPort = 8 then inc cUTBCap10(2) by 1 else																		
		if aiLine = 3 and aiPort = 9 then inc cUTBCan11(1) by 1 else																		
		if aiLine = 3 and aiPort = 10 then inc cUTBCan11(2) by 1 else																		
		if aiLine = 3 and aiPort = 11 then inc cUTBCap11(1) by 1 else																		
		if aiLine = 3 and aiPort = 12 then inc cUTBCap11(2) by 1 else																		
		if aiLine = 4 and aiPort = 13 then inc cUTBCan12(1) by 1 else																		
		if aiLine = 4 and aiPort = 14 then inc cUTBCan12(2) by 1 else																		
		if aiLine = 4 and aiPort = 15 then inc cUTBCap12(1) by 1 else																		
		if aiLine = 4 and aiPort = 16 then inc cUTBCap12(2) by 1 
		
		wait to be ordered on OL_UTB(aiPort)																		
																				
		move into qInfinite
		wait to be ordered on OLInfinite																		
	end																			
																				
end																				

begin pInsertToUTB arriving procedure
	insert this load into vllUTB(aiPort)
	wait to be ordered on OLInfinite
end
																	
begin pUTBtoEQ arriving procedure			
																											
	print "pm:cp_UTB_" aiLine "_" aiUTBnum to vstrTemp2																			
																				
	set alocFrom to vstrTemp2													
	set anDeliverType = 2																			
	set anTransfer = 1																			
	inc vnRequest(anLoadType) by 1																			
	inc vnRequesti(aiLine) by 1								//for no utb delivery vnReq(n+6) exists only. no (n) result											
																				
	insert this load into vlistLoad(anLoadType)																			
	
	set anGapType = 1	/* anGapType 1:UTB, 2:EQ, 3:STK, 4:CONV */																			
	set atTR to ac																			
	set aiDeliverType to 2																					
	move into alocFrom   
	set anGapType = 2	/* anGapType 1:UTB, 2:EQ, 3:STK, 4:CONV */	
						
	clone 1 load to pSTKtoUTB nlt lLarge																			
																				
	order 1 load from OL_UTB(aiPort)																			
																				
	/* UTB Buffer DEC */																			
	if aiLine = 1 and aiPort = 1 then dec cUTBCan9(1) by 1 else 																			
	if aiLine = 1 and aiPort = 2 then dec cUTBCan9(2) by 1 else																			
	if aiLine = 1 and aiPort = 3 then dec cUTBCap9(1) by 1 else																			
	if aiLine = 1 and aiPort = 4 then dec cUTBCap9(2) by 1 else																			
	if aiLine = 2 and aiPort = 5 then dec cUTBCan10(1) by 1 else																			
	if aiLine = 2 and aiPort = 6 then dec cUTBCan10(2) by 1 else																			
	if aiLine = 2 and aiPort = 7 then dec cUTBCap10(1) by 1 else																			
	if aiLine = 2 and aiPort = 8 then dec cUTBCap10(2) by 1 else																			
	if aiLine = 3 and aiPort = 9 then dec cUTBCan11(1) by 1 else																			
	if aiLine = 3 and aiPort = 10 then dec cUTBCan11(2) by 1 else																			
	if aiLine = 3 and aiPort = 11 then dec cUTBCap11(1) by 1 else																			
	if aiLine = 3 and aiPort = 12 then dec cUTBCap11(2) by 1 else																			
	if aiLine = 4 and aiPort = 13 then dec cUTBCan12(1) by 1 else																			
	if aiLine = 4 and aiPort = 14 then dec cUTBCan12(2) by 1 else																			
	if aiLine = 4 and aiPort = 15 then dec cUTBCap12(1) by 1 else																			
	if aiLine = 4 and aiPort = 16 then dec cUTBCap12(2) by 1																			
	/********************/																			
																										
	dec viUTB_Cur by 1																			
																				
	set aDistance to this vehicle total distance traveled       	/* distance measured until load placed at from location */																		
	set aRetDistance to aDistance - this vehicle vhlRetDistance     																			
																				
	travel to alocTo																			
	set atLoad to ac + this vehicle arSetDownTime																		
	set aDelDistance to this vehicle total distance traveled - aDistance																			
	set aTotDistance to aRetDistance + aDelDistance																			
																				
	inc cOut(2) by 1																			
																				
	print aiLine aiUTBnum to vsUTBName																			
	set aUTBName to vsUTBName																			
																				
   	tabulate atLoad - atTR in tDT_UTBtoEQ  																			
   	tabulate atLoad - atTR in tDT_UTBtoEQL(aiLine) 																			
   	tabulate atLoad - atTR in tDT_UTBtoEQL2(aUTBName)  																			
   																				
   	print alocTo to alocToA																			
   	read alocToA as 12 from alocToA																			
   																				
   	tabulate atUnload - atAssign in tUnloadMove(anLoadType)     /* calculate moving time without load */																			
    tabulate atLoad - atUnload in tLoadMove(anLoadType) 																				
   																				
   	print alocFrom, "\t" alocTo, "\t" atUnload - atAssign, "\t" atLoad - atUnload, "\t" atLoad - atTR, "\t"  aDelDistance to vUTBtoEQLog																			
   																					
	call sReport																			
	send to pEQZone																			
end																				
																				
begin pUTB_Selection arriving procedure																				
																				
	set aiCheck to 0
	set atDelayed(aiPort) to 0
	set aiUTBnum to 0
	set vlSelected to null
	
	if aiUTBnum = 0 then
	begin
		set aiCheck to 0
		while 1=1 do
		begin
			if vllUTB(aiPort) size < 1 then
			begin
		    	inc aiCheck by 1
		    	if aiCheck = 1 then
		    	begin
		    		set atDelayed(aiPort) to ac
		    		inc vinoUTBcase by 1
		    	end
				wait for 5 sec
			end
			else 
				break
		end
				
		set aiUTBnum to vllUTB(aiPort) first aiUTBnum
		remove vllUTB(aiPort) first from vllUTB(aiPort)	
		
        clone 1 load to pUTBtoEQ nlt lLarge  
    	
        if aiCheck > 0 and atDelayed(aiPort) > 0 then
    	begin
    		tabulate (ac - atDelayed(aiPort)) in tUTBdelayTime
    	end	   
    	
	end	    	    	
				
	send to die      																			
																				
end																				
																				
begin pCreate arriving procedure																				
																				
	set anStart to 1																			
																				
	//OHT3(EVL-C) creation																			
	set anRoute = 0																			
	/*while anRoute < 40 do*/																			
	while anRoute < 64 do																			
	begin																			
		inc anRoute by 1																		
		set anDeliverType = 1																		
																				
		if anRoute <= 4 then 																		
		begin																		
			print "pm:cp_Can_01_1" to vstrTemp 																	
			set aiLine to 1																	
			set aiPort to 1													
		end																		
		else if anRoute <= 8 then 																		
		begin																		
			print "pm:cp_Can_01_3" to vstrTemp 																	
			set aiLine to 1																	
			set aiPort to 2																	
		end																		
		else if anRoute <= 12 then 																		
		begin																		
			print "pm:cp_Cap_01_1" to vstrTemp 																	
			set aiLine to 1																	
			set aiPort to 3																	
		end																		
		else if anRoute <= 16 then 																		
		begin																		
			print "pm:cp_Cap_01_3" to vstrTemp																	
			set aiLine to 1																	
			set aiPort to 4																	
		end																		
		else if anRoute <= 20 then 																		
		begin																		
			print "pm:cp_Can_02_1" to vstrTemp 																	
			set aiLine to 2																	
			set aiPort to 5																	
		end																		
		else if anRoute <= 24 then 																		
		begin																		
			print "pm:cp_Can_02_3" to vstrTemp 																	
			set aiLine to 2																	
			set aiPort to 6																	
		end																		
		else if anRoute <= 28 then 																		
		begin																		
			print "pm:cp_Cap_02_1" to vstrTemp 																	
			set aiLine to 2																	
			set aiPort to 7																	
		end																		
		else if anRoute <= 32 then 																		
		begin																		
			print "pm:cp_Cap_02_3" to vstrTemp																	
			set aiLine to 2																	
			set aiPort to 8																	
		end																		
																				
		else if anRoute <= 36 then 																		
		begin																		
			print "pm:cp_Can_03_1" to vstrTemp 																	
			set aiLine to 3																	
			set aiPort to 9																	
		end																		
		else if anRoute <= 40 then 																		
		begin																		
			print "pm:cp_Can_03_3" to vstrTemp 																	
			set aiLine to 3																	
			set aiPort to 10																	
		end																		
		else if anRoute <= 44 then 																		
		begin																		
			print "pm:cp_Cap_03_1" to vstrTemp 																	
			set aiLine to 3																	
			set aiPort to 11																	
		end																		
		else if anRoute <= 48 then 																		
		begin																		
			print "pm:cp_Cap_03_3" to vstrTemp																	
			set aiLine to 3																	
			set aiPort to 12																	
		end																		
		else if anRoute <= 52 then 																		
		begin																		
			print "pm:cp_Can_04_1" to vstrTemp 																	
			set aiLine to 4																	
			set aiPort to 13																	
		end																		
		else if anRoute <= 56 then 																		
		begin																		
			print "pm:cp_Can_04_3" to vstrTemp 																	
			set aiLine to 4																	
			set aiPort to 14																	
		end																		
		else if anRoute <= 60 then 																		
		begin																		
			print "pm:cp_Cap_04_1" to vstrTemp 																	
			set aiLine to 4																	
			set aiPort to 15																	
		end																		
		else if anRoute <= 64 then 																		
		begin																		
			print "pm:cp_Cap_04_3" to vstrTemp																	
			set aiLine to 4																	
			set aiPort to 16																	
		end																		
																				
		set alocTo to vstrTemp																		
		set alocToTwin to vstrTemp																		
																				
		set vk to vstrTemp substring(14,1)																		
		set vs to vstrTemp substring(9,1)																		
		set aQnum to 1																		
																				
		if vs = "n" then																		
		begin																		
			print "conv.sta_Can_0" aiLine "_" vk "_1" to vstrTemp																	
			set alocConv(1) to vstrTemp																	
			print "conv.sta_Can_0" aiLine "_" vk "_2" to vstrTemp																	
			set alocConv(2) to vstrTemp																	
			print "conv.sta_Can_0" aiLine "_" vk "_3" to vstrTemp																	
			set alocConv(3) to vstrTemp																	
			print "conv.sta_Can_0" aiLine "_" vk "_4" to vstrTemp																	
			set alocConv(4) to vstrTemp																	
			set aiBox to 1																	
		end																		
		else if vs = "p" then																		
		begin																		
			print "conv.sta_Cap_0" aiLine "_" vk "_1" to vstrTemp																	
			set alocConv(1) to vstrTemp																	
			print "conv.sta_Cap_0" aiLine "_" vk "_2" to vstrTemp																	
			set alocConv(2) to vstrTemp																	
			print "conv.sta_Cap_0" aiLine "_" vk "_3" to vstrTemp																	
			set alocConv(3) to vstrTemp																	
			print "conv.sta_Cap_0" aiLine "_" vk "_4" to vstrTemp																	
			set alocConv(4) to vstrTemp																	
			set aiBox to 2																	
		end		
																					
		clone 1 load to pEQZoneBefore nlt lLarge																		
	end																			
	
	set vi to 0																						
	clone 1 load to pUTBinit nlt lLarge													
end																				
																				
begin pEQZoneBefore arriving procedure

	if anRoute <= 12 then
		wait for 10*1 sec
	else if anRoute <= 24 then
		wait for 10*2 sec
	else if anRoute <= 36 then
		wait for 10*3 sec
	else if anRoute <= 48 then
		wait for 10*4 sec
															
	clone 1 load to pEQZone																			
end																				
																					
begin pUTBinit arriving procedure	
	set anLoadType = 1
									
	inc vi by 1																			
																				
	if vi <= 64 then
	begin
		if vi <= 4  then set aiUTBnum to nextof(1,3,5,7) else				//Line 9
		if vi <= 8  then set aiUTBnum to nextof(2,4,6,8) else					
		if vi <= 12  then set aiUTBnum to nextof(9,11,13,15) else			
		if vi <= 16 then set aiUTBnum to nextof(10,12,14,16) else		// 10-2 Cap change to 4 ea	
		
		if vi <= 20 then set aiUTBnum to nextof(1,3,5,7) else					//Line 10
		if vi <= 24 then set aiUTBnum to nextof(2,4,6,8) else
		if vi <= 28 then set aiUTBnum to nextof(9,11,13,15) else
		if vi <= 32 then set aiUTBnum to nextof(10,12,14,16) else
		
		if vi <= 36 then set aiUTBnum to nextof(1,3,5,7) else				//Line 11
		if vi <= 40 then set aiUTBnum to nextof(2,4,6,8) else
		if vi <= 44 then set aiUTBnum to nextof(9,11,13,15) else
		if vi <= 48 then set aiUTBnum to nextof(10,12,14,16) else
		
		if vi <= 52 then set aiUTBnum to nextof(1,3,5,7) else				//Line 12
		if vi <= 56 then set aiUTBnum to nextof(2,4,6,8) else
		if vi <= 60 then set aiUTBnum to nextof(9,11,13,15) else
		if vi <= 64 then set aiUTBnum to nextof(10,12,14,16) 			// 12-2 Cap change to 4 ea
		
		if vi <= 4  then inc cUTBCan9(1) by 1 else 																		
		if vi <= 8  then inc cUTBCan9(2) by 1 else																		
		if vi <= 12  then inc cUTBCap9(1) by 1 else																		
		if vi <= 16  then inc cUTBCap9(2) by 1 else																		
		if vi <= 20  then inc cUTBCan10(1) by 1 else																		
		if vi <= 24  then inc cUTBCan10(2) by 1 else																		
		if vi <= 28  then inc cUTBCap10(1) by 1 else																		
		if vi <= 32  then inc cUTBCap10(2) by 1 else																		
		if vi <= 36  then inc cUTBCan11(1) by 1 else																		
		if vi <= 40  then inc cUTBCan11(2) by 1 else																		
		if vi <= 44  then inc cUTBCap11(1) by 1 else																		
		if vi <= 48  then inc cUTBCap11(2) by 1 else																		
		if vi <= 52  then inc cUTBCan12(1) by 1 else																		
		if vi <= 56  then inc cUTBCan12(2) by 1 else																		
		if vi <= 60  then inc cUTBCap12(1) by 1 else																		
		if vi <= 64  then inc cUTBCap12(2) by 1 
	
		if vi <= 4   then set aiPort to 1 else																	
		if vi <= 8   then set aiPort to 2 else
		if vi <= 12  then set aiPort to 3 else
		if vi <= 16  then set aiPort to 4 else
		if vi <= 20  then set aiPort to 5 else																	
		if vi <= 24  then set aiPort to 6 else																
		if vi <= 28  then set aiPort to 7 else													
		if vi <= 32  then set aiPort to 8 else													
		if vi <= 36  then set aiPort to 9 else													
		if vi <= 40  then set aiPort to 10 else													
		if vi <= 44  then set aiPort to 11 else														
		if vi <= 48  then set aiPort to 12 else																
		if vi <= 52  then set aiPort to 13 else															
		if vi <= 56  then set aiPort to 14 else																	
		if vi <= 60  then set aiPort to 15 else																
		if vi <= 64  then set aiPort to 16 
	
		insert this load into vllUTB(aiPort)
		clone 1 load to pUTBinit
		move into Q_UTB(aiPort)	
		wait to be ordered on OL_UTB(aiPort)
	end
	send to die
	
end
													
begin pExit arriving procedure																				
    move into qSpace																				
    send to die																				
end																				
																				
begin sReport																				

	inc vnCompleteType(aiDeliverType) by 1
	
	if ac > 7200 then
	begin
		if aiDeliverType = 2 then
			print aiLine, "\t", alocFrom, "\t", alocTo, "\t", atAssignInit - atTR + (atUnload - atAssign + (atAssign-atAssignInit)) + (atLoad - atUnload), "\t", aDelDistance/1000 to vfpOutResult(4)
			else if aiDeliverType = 1 then
			print aiLine, "\t", alocFrom, "\t", alocTo, "\t", atAssignInit - atTR + (atUnload - atAssign + (atAssign-atAssignInit)) + (atLoad - atUnload), "\t", aDelDistance/1000 to vfpOutResult(7)
	end
																		
	if aiLine = 1 and aiBox = 1 then inc viComplete2(1) by 1 else 																			
	if aiLine = 1 and aiBox = 2 then inc viComplete2(2) by 1 else 																			
	if aiLine = 2 and aiBox = 1 then inc viComplete2(3) by 1 else 																			
	if aiLine = 2 and aiBox = 2 then inc viComplete2(4) by 1 else																			
	if aiLine = 3 and aiBox = 1 then inc viComplete2(5) by 1 else																			
	if aiLine = 3 and aiBox = 2 then inc viComplete2(6) by 1 else																			
	if aiLine = 4 and aiBox = 1 then inc viComplete2(7) by 1 else																			
	if aiLine = 4 and aiBox = 2 then inc viComplete2(8) by 1 																			
																				
    tabulate aDelDistance in tDelDistancei(aiLine)           /* calculate Delivery Distance */																				
    tabulate aRetDistance in tRetDistancei(aiLine)           /* calculate Retrieve Distance */																				
    tabulate aTotDistance in tTotDistancei(aiLine)           /* calculate Total Distance */																				
    tabulate atAssignInit - atTR in tAssignIniti(aiLine)     /* calculate initial assigned time */																				
  	tabulate atAssign - atTR in tAssigni(aiLine)             /* calculate Total Assign Time */																			
   	tabulate atUnload - atAssign in tUnloadMovei(aiLine)     /* calculate moving time without load */																			
    tabulate atLoad - atUnload in tLoadMovei(aiLine)         /* calculate moving time with load */																				
    																				
	inc vnCompletei(aiLine) by 1																			
																				
    tabulate aDelDistance in tDelDistance(anLoadType)           /* calculate Delivery Distance */																				
    tabulate aRetDistance in tRetDistance(anLoadType)           /* calculate Retrieve Distance */																				
    tabulate aTotDistance in tTotDistance(anLoadType)           /* calculate Total Distance */																				
    tabulate atAssignInit - atTR in tAssignInit(anLoadType)     /* calculate initial assigned time */																				
  	tabulate atAssign - atTR in tAssign(anLoadType)             /* calculate Total Assign Time */																			
   	tabulate atUnload - atAssign in tUnloadMove(anLoadType)     /* calculate moving time without load */																			
    tabulate atLoad - atUnload in tLoadMove(anLoadType)         /* calculate moving time with load */																				
    tabulate aiAssignCount in tAssignCount																				
    																				
	inc vnComplete(anLoadType) by 1																			
	 																			
    if atLoad - atTR > 5 min then																				
    begin																				
     	inc vnDelay(anLoadType) by 1            				/* calculate number of load delayed for more than 5 minutes */															
     	print alocFrom, "\t" alocTo, "\t" atUnload - atAssign, "\t" atLoad - atUnload, "\t" atLoad - atTR to vDelayLog																			
    end		
   						
	if alocFrom capacity = 150 and alocTo capacity = 151 then																			
		tabulate aDelDistance in tDel_STKtoUTB																		
	else if alocFrom capacity = 151 and alocTo capacity = 152 then																			
		tabulate aDelDistance in tDel_UTBtoEQ																		
	else if alocFrom capacity = 152 and alocTo capacity = 153 then																			
		tabulate aDelDistance in tDel_EQtoOut																		
																				
end																				
																				
begin pEQBufferCheck arriving																				
																				
	set atEQEmpty to ac																			
																				
	while 1=1 do 																			
	begin																			
		if cEQBuffer(aiPort) current > 0 then																		
		begin																		
			set atEQEmpty to ac - atEQEmpty																	
			tabulate atEQEmpty in tEQEmpty(aiPort)																	
			break 																	
		end																		
		else																		
		begin																		
			wait for 0.1 sec																	
		end																		
	end																			
																				
	send to die																			
																				
end																				

