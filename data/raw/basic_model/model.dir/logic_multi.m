/*begin pCreate arriving procedure

	set anRoute to 0
	while anRoute < 3 do
	begin
		inc anRoute by 1
		if anRoute = 1 then
			clone 1 load to pIns
	/*	else if anRoute = 2 then
			clone 1 load to pPSo
		else if anRoute = 3 then
			clone 1 load to pMSo	*/
	end

	//OHT3(EVL-C) creation
	set anRoute = 0
	while anRoute < 64 do
	begin
		inc anRoute by 1
		set anLoadType = 3
		set anDeliverType = 1
		set anStart to 1

		if anRoute <= 4  then print "pm:cp_Can_05_1" to vstrTemp else 
		if anRoute <= 8  then print "pm:cp_Can_06_1" to vstrTemp else
		if anRoute <= 12 then print "pm:cp_Cap_05_1" to vstrTemp else
		if anRoute <= 16 then print "pm:cp_Cap_06_1" to vstrTemp else
		if anRoute <= 20 then print "pm:cp_Can_01_1" to vstrTemp else 
		if anRoute <= 24 then print "pm:cp_Can_02_1" to vstrTemp else 
		if anRoute <= 28 then print "pm:cp_Cap_01_1" to vstrTemp else 
		if anRoute <= 32 then print "pm:cp_Cap_02_1" to vstrTemp else
		if anRoute <= 36 then print "pm:cp_Can_03_1" to vstrTemp else 
		if anRoute <= 40 then print "pm:cp_Can_04_1" to vstrTemp else
		if anRoute <= 44 then print "pm:cp_Cap_03_1" to vstrTemp else
		if anRoute <= 48 then print "pm:cp_Cap_04_1" to vstrTemp else
		if anRoute <= 52 then print "pm:cp_Cap_07_1" to vstrTemp else
		if anRoute <= 56 then print "pm:cp_Cap_08_1" to vstrTemp else
		if anRoute <= 60 then print "pm:cp_Can_07_1" to vstrTemp else
		if anRoute <= 64 then print "pm:cp_Can_08_1" to vstrTemp   
		
		set alocTo to vstrTemp	
		
		//Zone Division
		if alocTo = pm.cp_Can_06_1 or alocTo = pm.cp_Can_05_1 or alocTo = pm.cp_Cap_06_1 or alocTo = pm.cp_Cap_05_1 then set aiLine to 1 else 			// Line 1
	    if alocTo = pm.cp_Cap_07_1 or alocTo = pm.cp_Cap_08_1 or alocTo = pm.cp_Can_07_1 or alocTo = pm.cp_Can_08_1 then set aiLine to 2 else			// Line 2
	    if alocTo = pm.cp_Cap_01_1 or alocTo = pm.cp_Cap_02_1 or alocTo = pm.cp_Can_01_1 or alocTo = pm.cp_Can_02_1 then set aiLine to 3 else			// Line 3
	    if alocTo = pm.cp_Cap_03_1 or alocTo = pm.cp_Cap_04_1 or alocTo = pm.cp_Can_03_1 or alocTo = pm.cp_Can_04_1 then set aiLine to 4 				// Line 4
	
		set vk to vstrTemp substring(12,1)
		set vs to vstrTemp substring(9,1)
		
		if vs = "p" then
		begin
			set aQnum = vk*10
			set vD = vk
		end
		else if vs = "n" then
		begin
			set aQnum = vk*10+100
			set vD = vk+10
		end		
		
		clone 1 load to pEQZoneBefore nlt lLarge		
	end
	//Stack UTB pre-filling
	set anRoute = 0
	while anRoute < viLineUTB * 4 do  //Stack 1Line UTBnum
	begin
		inc anRoute by 1
		if anRoute <= viFrontUTB or (anRoute >= 13 and anRoute <= viFrontUTB + 12 * 1) or (anRoute >= 25 and anRoute <= viFrontUTB + 12 * 2) or (anRoute >= 37 and anRoute <= viFrontUTB + 12 * 3)  then
		begin
			inc cUTB(anRoute) by 1
			inc cUTB_Occupied(anRoute) by 1
			clone 1 load to pUTBinit
		end
	end	
end

begin pEQZoneBefore arriving procedure
	if anRoute < 32 and anRoute > 16 then
		wait for 36*1 sec
	else if anRoute < 48 and anRoute > 16 then
		wait for 36*2 sec
	else if anRoute > 48 then
		wait for 36*3 sec
		
	clone 1 load to pEQZone nlt lLarge	
end

begin pUTBinit arriving procedure
	move into Q_UTB(anRoute)
	wait to be ordered on OL_UTB(anRoute)	
	send to die
end

begin pSTKtoEQ arriving procedure
	if anLoadType = 3 then 
	begin
		set vstrTemp to oneof(1:"pm:cp_StkL_1", 1:"pm:cp_StkL_2", 1:"pm:cp_StkL_3", 1:"pm:cp_StkL_4", 1:"pm:cp_StkL_5", 1:"pm:cp_StkL_6", 1:"pm:cp_StkL_7", 1:"pm:cp_StkL_8",
			  1:"pm:cp_StkL_9", 1:"pm:cp_StkL_10", 1:"pm:cp_StkL_11", 1:"pm:cp_StkL_12", 1:"pm:cp_StkL_13", 1:"pm:cp_StkL_14", 1:"pm:cp_StkL_15", 1:"pm:cp_StkL_16") 
	end 
	else if anLoadType = 1 then 
		set vstrTemp to oneof(1:"pm:cp_StkL_1", 1:"pm:cp_StkL_2", 1:"pm:cp_StkL_3", 1:"pm:cp_StkL_4")  

	set alocFrom to vstrTemp

	set anDeliverType = 1
	set anTransfer = 1
	inc vnRequest(anLoadType) by 1
	insert this load into vlistLoad(anLoadType)
	
	set atTR to ac
	move into alocFrom
	set this load color to red
	set aDistance to this vehicle total distance traveled       /* distance measured until load placed at from location */
	set aRetDistance to aDistance - this vehicle vhlRetDistance 

	travel to alocTo
	set atLoad to ac + vtLoading(1)
	set aDelDistance to this vehicle total distance traveled - aDistance
	set aTotDistance to aRetDistance + aDelDistance
	
	call sReport
	send to pEQZone
end

begin pSTKtoUTB arriving procedure
		
	if anLoadType = 3 then 
	begin
		set vstrTemp to oneof(1:"pm:cp_StkL_1", 1:"pm:cp_StkL_2", 1:"pm:cp_StkL_3", 1:"pm:cp_StkL_4", 1:"pm:cp_StkL_5", 1:"pm:cp_StkL_6", 1:"pm:cp_StkL_7", 1:"pm:cp_StkL_8",
			  1:"pm:cp_StkL_9", 1:"pm:cp_StkL_10", 1:"pm:cp_StkL_11", 1:"pm:cp_StkL_12", 1:"pm:cp_StkL_13", 1:"pm:cp_StkL_14", 1:"pm:cp_StkL_15", 1:"pm:cp_StkL_16") 
	end 
	else if anLoadType = 1 then set vstrTemp to oneof(1:"pm:cp_StkL_1", 1:"pm:cp_StkL_2", 1:"pm:cp_StkL_3", 1:"pm:cp_StkL_4")  
	else if anLoadType = 2 then set vstrTemp to oneof(1:"pm:cp_StkR_1", 1:"pm:cp_StkR_2", 1:"pm:cp_StkR_3", 1:"pm:cp_StkR_4")
	
	set alocFrom to vstrTemp
	
	if anLoadType = 3 and aiPreMove = 0 then 		//EVL-C, 210224 revised
	begin
		print "pm:cp_UTB" aiUTBnum to vstrTemp2
        inc cUTB_Occupied(aiUTBnum) by 1
		set alocTo to vstrTemp2
	end
	else if anLoadType = 3 and aiPreMove = 1 then 	//EVL-C, 210222 revised
	begin
		set aiSearchCount to (1 + viLineUTB * (aiLine - 1))
		while 1=1 do
		begin            									
            if cUTB(aiSearchCount) current = 0 and cUTB_Occupied(aiSearchCount) current = 0 then	
            begin
                set aiUTBnum to aiSearchCount
                inc cUTB_Occupied(aiUTBnum) by 1
                break
            end 
            else if aiSearchCount > (1 + viLineUTB * (aiLine - 1)) + viFrontUTB and aiSearchCount < (1 + viLineUTB * (aiLine - 1)) + viLineUTB then	// EVL-C, 210323 revised
            begin           									
	            if cUTB(aiSearchCount) current = 0 and cUTB_Occupied(aiSearchCount) current = 0 then	
	            begin
	                set aiUTBnum to aiSearchCount
	                inc cUTB_Occupied(aiUTBnum) by 1
	                break
	            end    
            end   
            
            if aiSearchCount = (1 + viLineUTB * (aiLine - 1)) + viLineUTB - 1
            begin
            	wait for 5 sec
            	set aiSearchCount to 0            
            end
       		inc aiSearchCount by 1          	
		end
		print "pm:cp_UTB" aiUTBnum to vstrTemp2
		set alocTo to vstrTemp2
	end	
		
	if (anLoadType = 3) or (anLoadType = 1 and aDefine = "n") then	//for UTB Delivery only (Stack All , Multi Can Only)
	begin
		set anDeliverType = 1
		set anTransfer = 1
		inc vnRequest(anLoadType) by 1
		insert this load into vlistLoad(anLoadType)
		
		set atTR to ac
		move into alocFrom
		set aDistance to this vehicle total distance traveled       /* distance measured until load placed at from location */
		set aRetDistance to aDistance - this vehicle vhlRetDistance     
	end

	travel to alocTo 
	dispatch this vehicle to alocFrom
	inc cUTB(aiUTBnum) by 1
	
	if aiPreMove = 1 then 
		set aiPreMove to 0
		
	inc viUTB_Cur by 1
		
	if (anLoadType = 3) or (anLoadType = 1 and aDefine = "n") then
	begin	
		set atLoad to ac + vtLoading(1)
		set aDelDistance to this vehicle total distance traveled - aDistance
		set aTotDistance to aRetDistance + aDelDistance
		
		call sReport
	end	
	move into Q_UTB(aiUTBnum)
	wait to be ordered on OL_UTB(aiUTBnum)
	send to die
end

begin pUTBtoEQ arriving procedure
	if anLoadType = 3 then 											//EVL-C
	begin
		print "pm:cp_UTB" aiUTBnum to vstrTemp
		set alocFrom to vstrTemp
	end
	else if anLoadType = 1 and aDefine = "n" then					//EVL_Can
	begin
		print "pm:cp_UTB_multi" aiUTBnum to vstrTemp
		set alocFrom to vstrTemp
	end
	
	set anDeliverType = 2
	set anTransfer = 1
	inc vnRequest(anLoadType) by 1
	inc vnRequest(anLoadType+6) by 1								//for no utb delivery vnReq(n+6) exists only. no (n) result
		
	insert this load into vlistLoad(anLoadType)
	
	set atTR to ac
	move into alocFrom
	dec cUTB_Occupied(aiUTBnum) by 1
	order 1 load from OL_UTB(aiUTBnum)
	
	if (anLoadType = 3) or (anLoadType = 1 and aDefine = "n") then	//for UTB Delivery only
		set this load color to blue
	else 
		set this load color to cyan									//for no UTB Delivery _from the start
		
	if (anLoadType = 3) then
		dec viUTB_Cur by 1
	else if (anLoadType = 1 and aDefine = "n") then	
		dec viUTBM_Cur by 1
		
	set aDistance to this vehicle total distance traveled       	/* distance measured until load placed at from location */
	set aRetDistance to aDistance - this vehicle vhlRetDistance     

	if (anLoadType = 3 and anRoute % 2 = 1 ) or (anLoadType = 1 and aDefine = "n") then			//for UTB Delivery only, 210222
	begin
		clone 1 load to pSTKtoUTB nlt lLarge
		set aiPreMove to 1
		clone 1 load to pSTKtoUTB nlt lLarge
		set aiPreMove to 0
	end
	
	travel to alocTo
	set atLoad to ac + vtLoading(1)
	set aDelDistance to this vehicle total distance traveled - aDistance
	set aTotDistance to aRetDistance + aDelDistance
	
	call sReport
	send to pEQZone
end

begin pEQZone arriving procedure

	/* Time Loss Statistics */
	set atEnterLoss to 0
	set atOutLoss to 0
	set atServiceEnd to 0

/*	if anStart = 1 then
	begin*/
		if anLoadType = 3 then 		// EVL-C
			inc cPort(aQnum+1) by 1
		else if anLoadType = 1 then	// EVL
		begin
			inc cPort_multi(aQnum+1) by 1
/*			if alocTo = pm.cp_mCan_01_1 then
				set this load aiOL to 13 else
			if alocTo = pm.cp_mCan_02_1 then
				set this load aiOL to 14 else
			if alocTo = pm.cp_mCap_01_1 then
				set this load aiOL to 15 else
			if alocTo = pm.cp_mCap_02_1 then
				set this load aiOL to 16*/
		end
		else if anLoadType = 2 then	// EVS
		begin
			if aDefine = "P" then inc cPort_PS(aQnum+1)  by 1 else 
			if aDefine = "M" then inc cPort_MS(aQnum+1)  by 1 else 
			if aDefine = "I" then inc cPort_Ins(aQnum+1) by 1 else
			print "No EVS PortType error" to message	
		
/*			if aDefine = "P" and alocTo = pm.cp_PSocket_01_1 then  
				set this load aiOL to 1  else
			if aDefine = "P" and alocTo = pm.cp_PSocket_01_2 then 
				set this load aiOL to 2  else
			if aDefine = "P" and alocTo = pm.cp_PSocket_02_1 then
				set this load aiOL to 3  else
			if aDefine = "P" and alocTo = pm.cp_PSocket_02_2 then 
				set this load aiOL to 4  else
			if aDefine = "M" and alocTo = pm.cp_MSocket_01_1 then
				set this load aiOL to 5  else
			if aDefine = "M" and alocTo = pm.cp_MSocket_01_2 then
				set this load aiOL to 6  else
			if aDefine = "M" and alocTo = pm.cp_MSocket_02_1 then
				set this load aiOL to 7  else
			if aDefine = "M" and alocTo = pm.cp_MSocket_02_2 then
				set this load aiOL to 8  else
			if aDefine = "I" and alocTo = pm.cp_Ins_01_1 then
				set this load aiOL to 9  else
			if aDefine = "I" and alocTo = pm.cp_Ins_01_2 then
				set this load aiOL to 10 else
			if aDefine = "I" and alocTo = pm.cp_Ins_02_1 then
				set this load aiOL to 11 else
			if aDefine = "I" and alocTo = pm.cp_Ins_02_2 then
				set this load aiOL to 12*/
		end
/*		else
			print "no LoadType error" to message		
	
	end*/
	
	if anLoadType = 3 then									// Stack
	begin
		move into interface(aQnum+1)
	
		inc cPort(aQnum+2) by 1
		wait for vrConv seconds
		move into interface(aQnum+2)
		dec cPort(aQnum+1) by 1
		set aiLossNum to 1
	
		set aj to 2
		while aj < 4 do
		begin
			inc aj by 1		
			inc cPort(aQnum+aj) by 1	
			wait for vrConv seconds		
			if aj = 4 and vtEnterLoss(1,aQnum) != 0 then					
			begin
				set atEnterLoss to ac - vtEnterLoss(1, aQnum)
				set vtEnterLoss(1, aQnum) to 0
			end				
			move into interface(aQnum+aj)
			dec cPort(aQnum+aj-1) by 1			
		end
	end
	else if anLoadType = 1  and aiPortZone = 2 then			// Multi Can
	begin
		set this load color to orange
		move into m_CanCap(aQnum+1)
		
		inc cPort_multi(aQnum+2) by 1
		wait for vrConv seconds
		move into m_CanCap(aQnum+2)
		dec cPort_multi(aQnum+1) by 1
		set aiLossNum to 2

		set aj to 2
		while aj < 5 do
		begin
			inc aj by 1		
			inc cPort_multi(aQnum+aj) by 1	
			wait for vrConv seconds		
			if aj = 5 and vtEnterLoss(2, aQnum) != 0 then					
			begin
				set atEnterLoss to ac - vtEnterLoss(2, aQnum)
				set vtEnterLoss(2, aQnum) to 0
			end				
			move into m_CanCap(aQnum+aj)
			dec cPort_multi(aQnum+aj-1) by 1			
		end
		set aj to 0
	end
	else if anLoadType = 1  and aiPortZone = 1 then			// Multi Cap
	begin
		set this load color to orange
		move into m_CanCap(aQnum+1)
		
		inc cPort_multi(aQnum+2) by 1
		wait for vrConv seconds
		move into m_CanCap(aQnum+2)
		dec cPort_multi(aQnum+1) by 1
		set aiLossNum to 3
		
		inc cPort_multi(aQnum+3) by 1
		wait for vrConv seconds
		if vtEnterLoss(3, aQnum) != 0 then					
		begin
			set atEnterLoss to ac - vtEnterLoss(3, aQnum)
			set vtEnterLoss(3, aQnum) to 0
		end				
		move into m_CanCap(aQnum+3)
		dec cPort_multi(aQnum+2) by 1
	end
	else									
	begin
		set this load color to cyan
		if aDefine = "P" and aiPortZone = 1 then			// PSocket, Col A
		begin		
			move into PS(aQnum+1)
		 	inc cPort_PS(aQnum+2) by 1
			wait for vrConv seconds
			move into PS(aQnum+2)
			dec cPort_PS(aQnum+1) by 1
			set aiLossNum to 4
			
			set aj to 2
			while aj < 5 do
			begin
				inc aj by 1
				inc cPort_PS(aQnum+aj) by 1	
				wait for vrConv seconds	
				if aj = 5 and vtEnterLoss(4,aQnum) != 0 then					
				begin
					set atEnterLoss to ac - vtEnterLoss(4, aQnum)
					set vtEnterLoss(4, aQnum) to 0
				end					
				move into PS(aQnum+aj)
				dec cPort_PS(aQnum+aj-1) by 1			
			end
			set aj to 0
		end
		else if aDefine = "P" and aiPortZone = 2 then	// PSocket, Col B
		begin		
			move into PS(aQnum+1)
		 	inc cPort_PS(aQnum+2) by 1
			wait for vrConv seconds
			move into PS(aQnum+2)
			dec cPort_PS(aQnum+1) by 1
			set aiLossNum to 5
			
			set aj to 2
			while aj < 4 do
			begin
				inc aj by 1
				inc cPort_PS(aQnum+aj) by 1	
				wait for vrConv seconds	
				if aj = 4 and vtEnterLoss(5, aQnum) != 0 then					
				begin
					set atEnterLoss to ac - vtEnterLoss(5, aQnum)
					set vtEnterLoss(5, aQnum) to 0
				end						
				move into PS(aQnum+aj)
				dec cPort_PS(aQnum+aj-1) by 1			
			end
			set aj to 0
		 end
		 else if aDefine = "M" and aiPortZone = 1 then	// MSocket, Col A
		 begin
			move into MS(aQnum+1)
		 	inc cPort_MS(aQnum+2) by 1
			wait for vrConv seconds
			move into MS(aQnum+2)
			dec cPort_MS(aQnum+1) by 1
			set aiLossNum to 6
			
			set aj to 2
			while aj < 5 do
			begin
				inc aj by 1
				inc cPort_MS(aQnum+aj) by 1	
				wait for vrConv seconds	
				if aj = 5 and vtEnterLoss(6, aQnum) != 0 then					
				begin
					set atEnterLoss to ac - vtEnterLoss(6, aQnum)
					set vtEnterLoss(6, aQnum) to 0
				end						
				move into MS(aQnum+aj)
				dec cPort_MS(aQnum+aj-1) by 1			
			end
			set aj to 0
		 end
		 else if aDefine = "M" and aiPortZone = 2 then	// MSocket, Col B
		 begin
			move into MS(aQnum+1)
		 	inc cPort_MS(aQnum+2) by 1
			wait for vrConv seconds
			move into MS(aQnum+2)
			dec cPort_MS(aQnum+1) by 1
			set aiLossNum to 7
			
			set aj to 2
			while aj < 4 do
			begin
				inc aj by 1
				inc cPort_MS(aQnum+aj) by 1	
				wait for vrConv seconds	
				if aj = 4 and vtEnterLoss(7,aQnum) != 0 then					
				begin
					set atEnterLoss to ac - vtEnterLoss(7, aQnum)
					set vtEnterLoss(7, aQnum) to 0
				end						
				move into MS(aQnum+aj)
				dec cPort_MS(aQnum+aj-1) by 1			
			end
			set aj to 0
		 end
		 else if aDefine = "I" and aiPortZone = 1 then	// Insulator, Col A
		 begin					
			move into Ins(aQnum+1)				
		 	inc cPort_Ins(aQnum+2) by 1				
			wait for vrConv seconds				
			move into Ins(aQnum+2)				
			dec cPort_Ins(aQnum+1) by 1	
			set aiLossNum to 8			
							
			set aj to 2				
			while aj < 5 do				
			begin				
				inc aj by 1			
				inc cPort_Ins(aQnum+aj) by 1			
				wait for vrConv seconds	
				if aj = 5 and vtEnterLoss(8, aQnum) != 0 then					
				begin
					set atEnterLoss to ac - vtEnterLoss(8, aQnum)
					set vtEnterLoss(8, aQnum) to 0
				end							
				move into Ins(aQnum+aj)			
				dec cPort_Ins(aQnum+aj-1) by 1			
			end				
			set aj to 0	
		 end
		 else if aDefine = "I" and aiPortZone = 2 then	// Insulator, Col B
		 begin				
			move into Ins(aQnum+1)				
		 	inc cPort_Ins(aQnum+2) by 1				
			wait for vrConv seconds				
			move into Ins(aQnum+2)				
			dec cPort_Ins(aQnum+1) by 1	
			set aiLossNum to 9			
							
			set aj to 2				
			while aj < 4 do				
			begin				
				inc aj by 1			
				inc cPort_Ins(aQnum+aj) by 1			
				wait for vrConv seconds	
				if aj = 4 and vtEnterLoss(9, aQnum) != 0 then					
				begin
					set atEnterLoss to ac - vtEnterLoss(9, aQnum)
					set vtEnterLoss(9, aQnum) to 0
				end							
				move into Ins(aQnum+aj)			
				dec cPort_Ins(aQnum+aj-1) by 1			
			end				
			set aj to 0	
		 end
		 else print "error 1" to message
	end
		
	/* Time Loss Statistics */		
	set atServiceIn to ac
	if atEnterLoss > 0 then
	begin
		inc vtEnterLossCumul(aiLossNum, aQnum) by atEnterLoss
//		print this load, "\t", atEnterLoss to message
		inc viEnterLossCount(aiLossNum, aQnum) by 1
	end


// EQ Service Time ----------------------------------------------------------------------------------------------------------------------------------------------------
	if anLoadType = 3 then    
	begin
		wait for 144  		seconds  								// Stack Can/Cap Service Time
	end
	else if anLoadType = 1 then
	begin
		if aDefine = "n" then wait for 192         seconds else 		// Multi Can Service Time
//		if aDefine = "n" and anStart = 1 and aiDelay = 1 then wait for 192+192/2   seconds else 
		if aDefine = "c" then wait for 1056 	   seconds 			// Multi Cap Service Time
//		if aDefine = "c" and anStart = 1 and aiDelay = 1 then wait for 1056+1056/2 seconds  	  
	end
	else if anLoadType = 2 then
	begin
/*		if aDefine = "I" and anStart = 1 and aiPortZone = 1 then wait for 1200 seconds else
		if aDefine = "I" and anStart = 1 and aiPortZone = 2 then wait for 600 seconds else
		if aDefine = "I" then wait for 600*2 seconds	else								
		if (aDefine = "P" or aDefine = "M") and anStart = 1 and aiPortZone = 1 then wait for 1150  seconds else 			
		if (aDefine = "P" or aDefine = "M") and anStart = 1 and aiPortZone = 1 then wait for 2300  seconds else
		if (aDefine = "P" or aDefine = "M") then wait for 2300*2  	  	seconds	
		*/
	end
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	if anStart = 1 then
		set anStart = 0

	inc viEQcomplete(aQnum) by 1
	set atServiceEnd to ac
		
//Empty foup in buffer out

// New Box Call ----------------------------------------------------------------------------------------------------------------------------------------------------

	clone 1 load to pUTB_Selection
// 	call sUTB_Selection
   	
/*  	
	// Multi EQ _UTB Zone Division	
   else if alocTo = pm.cp_mCan_01_1 or alocTo = pm.cp_mCan_02_1 or alocTo = pm.cp_mCan_03_1 or alocTo = pm.cp_mCan_04_1 then	// Can Only
   begin
   		set aiSearchCount to 1
        while 1=1 do
        begin
        	inc aiSearchCount by 1
            set i to 1 + vnUTB_Multi * u 0.5, 0.5									// 1~28
            if cUTB_multi(i) current = 1 then
            begin
                //inc vUTBFull_Multi by 1
                set aiUTBnum to i
                clone 1 load to pUTBtoEQ nlt lLarge
                dec cUTB_multi(i) by 1
                break
            end 
            if aiSearchCount > 10 then
            begin
            	wait for 5 sec
            	set aiSearchCount to 0
            end        
        end
    end	
    else 		//other LoadTypes of multi
    begin
    	clone 1 load to pSTKtoUTB nlt lLarge
    end
*/
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------


	if anLoadType = 3 then										// Stack Can, Cap bins
	begin
		inc cPort(aQnum+7) by 1
		move into interface(aQnum+7)
		dec cPort(aQnum+4) by 1
		
		if interface(aQnum+3) current = 0 then
			set vtEnterLoss(1, aQnum) to ac
	end
	else if anLoadType = 1 and aiPortZone = 2 then				// Multi Can bins
	begin
		set aj to 5
		while aj < 9 do
		begin
			inc aj by 1
			if aj = 6 and m_CanCap(aQnum+4) current = 0 then
				set vtEnterLoss(2, aQnum) to ac
			inc cPort_multi(aQnum+aj) by 1
			if aj > 5 then
				wait for 6 sec
			move into m_CanCap(aQnum+aj)
			dec cPort_multi(aQnum+aj-1) by 1			
		end
	end
	else if anLoadType = 1 and aiPortZone = 1 then				// Multi Cap bins
	begin
		inc cPort_multi(aQnum+4) by 1
		if aj > 5 then
			wait for 6 sec
		move into m_CanCap(aQnum+4)
		dec cPort_multi(aQnum+3) by 1
		
		if m_CanCap(aQnum+2) current = 0 then
			set vtEnterLoss(3, aQnum) to ac
	end
	else if anLoadType = 2 then
	begin
		if aDefine = "P" and aiPortZone = 1 then	        	// PSocket, Col A bins
		begin	
			wait to be ordered on OL_PSocket		
			set aj to 5
			while aj < 7 do
			begin
				inc aj by 1
				if aj = 6 and PS(aQnum+4) current = 0 then
					set vtEnterLoss(4, aQnum) to ac
				inc cPort_PS(aQnum+aj) by 1
				if aj > 5 then
					wait for 6 sec
				move into PS(aQnum+aj)
				dec cPort_PS(aQnum+aj-1) by 1			
			end
		end
		else if aDefine = "P" and aiPortZone = 2 then			// PSocket, Col B bins
		begin	
			wait to be ordered on OL_PSocket
			set aj to 4
			while aj < 6 do
			begin
				inc aj by 1
				if aj = 5 and PS(aQnum+3) current = 0 then
					set vtEnterLoss(5, aQnum) to ac
				inc cPort_PS(aQnum+aj) by 1
				if aj > 5 then
					wait for 6 sec
				move into PS(aQnum+aj)
				dec cPort_PS(aQnum+aj-1) by 1			
			end
			
			if PS(aQnum+2) current = 0 then
				set vtEnterLoss(5, aQnum) to ac
		end
		else if aDefine = "M" and aiPortZone = 1 then			// MSocket, Col A bins
		begin
			wait to be ordered on OL_MSocket
			set aj to 5
			while aj < 7 do
			begin
				inc aj by 1
				if aj = 6 and MS(aQnum+4) current = 0 then
					set vtEnterLoss(6, aQnum) to ac
				inc cPort_MS(aQnum+aj) by 1
				if aj > 5 then
					wait for 6 sec
				move into MS(aQnum+aj)
				dec cPort_MS(aQnum+aj-1) by 1			
			end
		end
		else if aDefine = "M" and aiPortZone = 2 then	// MSocket, Col B
		begin
			wait to be ordered on OL_MSocket
			set aj to 4
			while aj < 6 do
			begin
				inc aj by 1
				if aj = 5 and MS(aQnum+3) current = 0 then
					set vtEnterLoss(7, aQnum) to ac
				inc cPort_MS(aQnum+aj) by 1
				if aj > 5 then
					wait for 6 sec
				move into MS(aQnum+aj)
				dec cPort_MS(aQnum+aj-1) by 1			
			end
		end
		else if aDefine = "I" and aiPortZone = 1 then	// Insulator, Col A
		begin
			wait to be ordered on OL_Ins
			set aj to 5
			while aj < 8 do
			begin
				inc aj by 1
				if aj = 6 and Ins(aQnum+4) current = 0 then
					set vtEnterLoss(8, aQnum) to ac
				inc cPort_Ins(aQnum+aj) by 1
				if aj > 5 then
					wait for 6 sec
				move into Ins(aQnum+aj)
				dec cPort_Ins(aQnum+aj-1) by 1			
			end
		end
		else if aDefine = "I" and aiPortZone = 2 then	// Insulator, Col B
		begin
			wait to be ordered on OL_Ins
			set aj to 4
			while aj < 6 do
			begin
				inc aj by 1
				if aj = 5 and Ins(aQnum+3) current = 0 then
					set vtEnterLoss(9, aQnum) to ac
				inc cPort_Ins(aQnum+aj) by 1
				if aj > 5 then
					wait for 6 sec
				move into Ins(aQnum+aj)
				dec cPort_Ins(aQnum+aj-1) by 1			
			end
		end
	end
	else 
		print "error 2" to message

	set this load color to thistle
		
	if atOutLoss > 0 then
	begin
		inc vtOutLossCumul(aiLossNum, aQnum) by atOutLoss
		inc viOutLossCount(aiLossNum, aQnum) by 1
	end

	wait for vrLift seconds	

	//check UTB current before UTB searching_ Zone Total
	set i to 0
	set vUTBFull_Total to 0
	while i < vnUTB do
	begin
		inc i by 1
		if cUTB(i) current = 1 then	inc vUTBFull_Total by 1		
	end
	
	//check UTB current before UTB searching_ Zone Total
	set i to 0
	set vUTBFull_Multi_Total to 0
	while i < vnUTB_Multi do
	begin
		inc i by 1
		if cUTB_multi(i) current = 1 then inc vUTBFull_Multi_Total by 1		
	end

	if anLoadType = 3 then
	begin
		inc cPort(aQnum+8) by 1
		wait for vrLift seconds   
		move into interface(aQnum+8)
		dec cPort(aQnum+7) by 1
		wait for vrConv seconds	  
	end
	else if anLoadType = 1 and aiPortZone = 2 then
	begin
		if aDefine = "p" then
			wait for 200 sec
		else if aDefine = "n" then
			wait for 100 sec
		inc cPort_multi(aQnum+1) by 1
		wait for vrLift seconds
		move into m_CanCap(aQnum+1)
		dec cPort_multi(aQnum+9) by 1
	end
	else if anLoadType = 1 and aiPortZone = 1 then
	begin
		if aDefine = "p" then
			wait for 200 sec
		else if aDefine = "n" then
			wait for 150 sec
		inc cPort_multi(aQnum+1) by 1
		wait for vrLift seconds
		move into m_CanCap(aQnum+1)
		dec cPort_multi(aQnum+4) by 1
	end
	else if anLoadType = 2 then
	begin		
		if aDefine = "P" and aiPortZone = 1  then
		begin
			wait for 2100 sec
			inc cPort_PS(aQnum+1) by 1
			wait for vrLift seconds
			move into PS(aQnum+1)
			dec cPort_PS(aQnum+7) by 1
		end
		else if aDefine = "P" and aiPortZone = 2  then
		begin
			wait for 2100 sec
			inc cPort_PS(aQnum+1) by 1
			wait for vrLift seconds
			move into PS(aQnum+1)
			dec cPort_PS(aQnum+6) by 1
		end
		else if aDefine = "M" and aiPortZone = 1  then
		begin
			wait for 2100 sec
			inc cPort_MS(aQnum+1) by 1
			wait for vrLift seconds
			move into MS(aQnum+1)
			dec cPort_MS(aQnum+7) by 1
		end
		else if aDefine = "M" and aiPortZone = 2  then
		begin
			wait for 500 sec
			inc cPort_MS(aQnum+1) by 1
			wait for vrLift seconds
			move into MS(aQnum+1)
			dec cPort_MS(aQnum+6) by 1
		end
		else if aDefine = "I" and aiPortZone = 1  then
		begin
			wait for 500 sec
			inc cPort_Ins(aQnum+1) by 1
			wait for vrLift seconds
			move into Ins(aQnum+1)
			dec cPort_Ins(aQnum+8) by 1
		end
		else if aDefine = "I" and aiPortZone = 2  then
		begin
			wait for 500 sec
			inc cPort_Ins(aQnum+1) by 1
			wait for vrLift seconds
			move into Ins(aQnum+1)
			dec cPort_Ins(aQnum+6) by 1
		end
		else 
			print "error 5" to message
	end
	else 
		print "error 3" to message
	
	set anDeliverType = 0
	set anTransfer = 1
	inc vnRequest(anLoadType) by 1
	inc vnRequest(anLoadType+3) by 1
	
	set aiHotLot to 1
	
	insert this load into vlistLoad(anLoadType)
	
	set atTR to ac
	
	if anLoadType = 3 then
	begin
		print alocTo to vsTempTo
		set vsTempTo to vsTempTo substring(1,13)
		print vsTempTo "2" to vsTempTo
		set alocTo to vsTempTo
		set alocFrom to alocTo
		move into alocTo
 
		dec cPort(aQnum+8) by 1
		
		inc viOutNumbering by 1
		
		if viOutNumbering % 8 = 1 then print "pm.cp_ConvL_2" to vstringTemp else
		if viOutNumbering % 8 = 2 then print "pm.cp_ConvL_3" to vstringTemp else
		if viOutNumbering % 8 = 3 then print "pm.cp_ConvL_4" to vstringTemp else
		if viOutNumbering % 8 = 4 then print "pm.cp_ConvL_5" to vstringTemp else
		if viOutNumbering % 8 = 5 then print "pm.cp_ConvL_6" to vstringTemp else
		if viOutNumbering % 8 = 6 then print "pm.cp_ConvL_7" to vstringTemp else
		if viOutNumbering % 8 = 7 then print "pm.cp_ConvL_8" to vstringTemp else
		if viOutNumbering % 8 = 0 then print "pm.cp_ConvL_9" to vstringTemp 
		
		set alocOut to vstringTemp
	end
	else if anLoadType = 1 then
	begin
		set alocFrom to alocTo
		move into alocTo
 		dec cPort_multi(aQnum+1) by 1
  		print oneof(0.11: "pm.cp_ConvL_2", 0.11: "pm.cp_ConvL_3", 0.11: "pm.cp_ConvL_4", 0.11: "pm.cp_ConvL_5", 0.11: "pm.cp_ConvL_6", 0.11: "pm.cp_ConvL_7", 0.11: "pm.cp_ConvL_8", 
				0.11: "pm.cp_ConvL_9" ) to vstringTemp
		set alocOut to vstringTemp							
	end
	else if anLoadType = 2 then
	begin
		set alocFrom to alocTo
		print oneof(0.11: "pm.cp_ConvL_2", 0.11: "pm.cp_ConvL_3", 0.11: "pm.cp_ConvL_4", 0.11: "pm.cp_ConvL_5", 0.11: "pm.cp_ConvL_6", 0.11: "pm.cp_ConvL_7", 0.11: "pm.cp_ConvL_8", 
				0.11: "pm.cp_ConvL_9" ) to vstringTemp 
		set alocOut to vstringTemp
		
		if aDefine = "P" then
		begin
			move into alocTo
 			dec cPort_PS(aQnum+1) by 1
 		end
 		else if aDefine = "M" then
 		begin
 			move into alocTo
 			dec cPort_MS(aQnum+1) by 1
 		end
 		else if aDefine = "I" then
 		begin
 			move into alocTo
 			dec cPort_Ins(aQnum+1) by 1
 		end
 		else print "error 6" to message
 	end
	
	set aDistance to this vehicle total distance traveled       /* distance measured until load placed at from location */
	set aRetDistance to aDistance - this vehicle vhlRetDistance   
	
	set alocTo to alocOut
	travel to alocTo
	set atLoad to ac + vtLoading(1)
	set aDelDistance to this vehicle total distance traveled - aDistance
	set aTotDistance to aRetDistance + aDelDistance
	
	call sReport
	send to pExit
end

begin pUTB_Selection arriving procedure
	set aiUTBnum to 0
	set aiSearchCount to (1 + viLineUTB * (aiLine - 1))	+ viFrontUTB
	while aiSearchCount < (1 + viLineUTB * (aiLine - 1)) + viLineUTB do
	begin   								
	    if cUTB(aiSearchCount) current = 1 then
	    begin
	        set aiUTBnum to aiSearchCount
	        clone 1 load to pUTBtoEQ nlt lLarge
	        dec cUTB(aiSearchCount) by 1                
	        break
	    end		
		inc aiSearchCount by 1		
	end	
	
	if aiUTBnum = 0 then
	begin
		set aiSearchCount to (1 + viLineUTB * (aiLine - 1))	
		while 1=1 do
		begin    								
		    if cUTB(aiSearchCount) current = 1 then
		    begin
		        set aiUTBnum to aiSearchCount
		        clone 1 load to pUTBtoEQ nlt lLarge
		        dec cUTB(aiSearchCount) by 1                
		        break
		    end
		    
		    if aiSearchCount > (1 + viLineUTB * (aiLine - 1)) + viFrontUTB then
		    begin
		    	wait for 5 sec
		    	set aiSearchCount to 0
		    end
			inc aiSearchCount by 1	  
		end
	end
	send to die	
end
/*
begin sUTB_Selection 
	set aiUTBnum to 0
	set aiSearchCount to (1 + viLineUTB * (aiLine - 1))	+ viFrontUTB
	while aiSearchCount < (1 + viLineUTB * (aiLine - 1)) + viLineUTB do
	begin   								
	    if cUTB(aiSearchCount) current = 1 then
	    begin
	        set aiUTBnum to aiSearchCount
	        clone 1 load to pUTBtoEQ nlt lLarge
	        dec cUTB(aiSearchCount) by 1                
	        break
	    end		
		inc aiSearchCount by 1		
	end	
	
	if aiUTBnum = 0 then
	begin
		set aiSearchCount to (1 + viLineUTB * (aiLine - 1))	
		while 1=1 do
		begin    								
		    if cUTB(aiSearchCount) current = 1 then
		    begin
		        set aiUTBnum to aiSearchCount
		        clone 1 load to pUTBtoEQ nlt lLarge
		        dec cUTB(aiSearchCount) by 1                
		        break
		    end
		    
		    if aiSearchCount > (1 + viLineUTB * (aiLine - 1)) + viFrontUTB then
		    begin
		    	wait for 5 sec
		    	set aiSearchCount to 0
		    end
			inc aiSearchCount by 1	  
		end
	end
end
*/
begin pExit arriving procedure
    move into qSpace
    send to die
end

begin sReport

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
     	inc vnDelay(anLoadType) by 1            				/* calculate number of load delayed for more than 5 minutes */
	     		
	if alocFrom capacity = 150 and alocTo capacity = 151 then
		tabulate aDelDistance in tDel_STKtoUTB
	else if alocFrom capacity = 151 and alocTo capacity = 152 then
		tabulate aDelDistance in tDel_UTBtoEQ
	else if alocFrom capacity = 152 and alocTo capacity = 153 then
		tabulate aDelDistance in tDel_EQtoOut
	
end

/*begin pIns arriving procedure
	while 1=1 do
	begin
		wait for 600/2 sec
		order a load from OL_Ins
	end
end

begin pPSo arriving procedure
	while 1=1 do
	begin
		wait for 2300/2 sec
		order a load from OL_PSocket
	end
end

begin pMSo arriving procedure
	while 1=1 do
	begin
		wait for 2300/2 sec
		order a load from OL_MSocket
	end
end
*/

*/

