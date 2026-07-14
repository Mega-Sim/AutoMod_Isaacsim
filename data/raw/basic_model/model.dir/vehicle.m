begin pm initialization function
	inc viInit by 1

	if theVehicle type = "EVL" then set theVehicle anVehicleType = 1
	else if theVehicle type = "EVL2" then set theVehicle anVehicleType = 2

	if theVehicle type = "EVL" then set theVehicle segments first color = blue violet
	else if theVehicle type = "EVL2" then set theVehicle segments first color = purple
		
	if theVehicle anVehicleType <= 4 then
	begin
		set theVehicle defined forward normal to vrNormalVelocity(theVehicle anVehicleType) m per sec
		set theVehicle defined forward curve to vrCurveVelocity(theVehicle anVehicleType) m per sec
		set theVehicle defined forward spur to vrCurveVelocity(theVehicle anVehicleType) m per sec
		
		set theVehicle defined reverse normal to vrNormalVelocity(theVehicle anVehicleType) m per sec
		set theVehicle defined reverse curve to vrCurveVelocity(theVehicle anVehicleType) m per sec
		set theVehicle defined reverse spur to vrCurveVelocity(theVehicle anVehicleType) m per sec 
		
		set theVehicle defined acceleration to vrAcceleration(theVehicle anVehicleType) m per sec
		set theVehicle defined deceleration to vrDeceleration(theVehicle anVehicleType) m per sec
		
		set theVehicle defined brake = vrBrakeDistance m
		set theVehicle defined stop = vrStopDistance m
	
	inc vcOHT(theVehicle anVehicleType) by 1
	set theVehicle aID = vcOHT(theVehicle anVehicleType)
	set theVehicle aAssign = 0 /* JobAssigned 1, ParkAssigned 2, etc. 3 */

	if theVehicle aID <= vnOHT(theVehicle anVehicleType) then
		insert theVehicle into vlistOHT(theVehicle anVehicleType)
	end
	set theVehicle alocPark to null
	insert theVehicle into vlistOHT_ParkCheck
	
	return true
end

begin pm.steer passing station function

	for each vlocTemp in theVehicle current route do
	begin
		if vlocTemp color = white or (vlocTemp color = cyan or vlocTemp color = aquamarine)  then
			break
	end
	
	if (theVehicle aiSteering = 1 and (vlocTemp color = cyan or vlocTemp color = aquamarine)) or (theVehicle aiSteering = 2 and vlocTemp color = white) then
	begin
		set theVehicle defined forward normal to vrNormalVelocity(theVehicle anVehicleType)*0.67 m per sec
		set theVehicle defined forward curve to vrCurveVelocity(theVehicle anVehicleType)*0.67 m per sec
		set theVehicle aiSteerChange = 1	
	end

	return true
end

begin pm.Avoid passing station function
		
	if theVehicle aiSteering = 0 then
	begin
		if stopLoc color = white then
			set theVehicle aiSteering = 1
		else 
			set theVehicle aiSteering = 2
	end

	return true
end

begin pm.dummy passing station function

	if theVehicle aiSteerChange = 1 then
	begin
		set theVehicle defined forward normal to vrNormalVelocity(theVehicle anVehicleType) m per sec
		set theVehicle defined forward curve to vrCurveVelocity(theVehicle anVehicleType) m per sec	
		set theVehicle aiSteerChange = 0
	end	

	return true
end


begin pm start to move function

	print theVehicle current location to vsTemp
	
	if vsTemp substring(7, 4) = "Park" and theVehicle aiYellow = 1 and theVehicle alocPark = theVehicle current location then
	begin
		set theVehicle aiYellow = 0
		set theVehicle alocPark to null
		set k to vsTemp substring(12, 2)
		dec cPark(k) by 1
			
		if theVehicle type = "EVL" then
			set theVehicle segments first color to blue violet
		else if theVehicle type = "EVL2" then
			set theVehicle segments first color to purple
	end
	
	return true
end


begin pPark_Check arriving procedure

	while 1=1 do
	begin
		wait for 1.0 sec
		set i = 0
		while i < vlistOHT_ParkCheck size do
		begin
			inc i by 1
			if vlistOHT_ParkCheck(i) vehicle in front != null and vlistOHT_ParkCheck(i) vehicle in front status = "Idle" and vlistOHT_ParkCheck(i) vehicle in front current schedjob = null then
			begin
				set vvFront to vlistOHT_ParkCheck(i) vehicle in front
				set vlocFront to vvFront current location
				set vloclist_CurrentRoute to vlistOHT_ParkCheck(i) current route
				insert vlistOHT_ParkCheck(i) destination into vloclist_CurrentRoute at end
				set vrDistanceR to 9999999999
				
				set j = 1
				for each vlocTemp in vlocAvoidList 
				begin
					set k = 0 
					while k < 17 do
					begin
						inc k by 1
						if cPark(k) current < viParkCapa(k) and vvFront aiYellow = 0 then
						begin
							inc cPark(k) by 1
							set vlistOHT_ParkCheck(i) aiCheck to 1
							set vvFront aiYellow = 1
							dispatch vvFront to vlocParkList(k)
							set vvFront alocPark to vlocParkList(k)
							set vvFront segments first color to green yellow
							break
						end
					end
				
					set vrDistanceR to vvFront path distance to vlocTemp
					
					if j = 1 and vrDistanceR > 1 m then 
					begin	
						set vrDistanceMin to vrDistanceR
						set vlocMin to vlocTemp
						set vloc2nd to pm.cp_a_301
						set vrDistance2nd to vvFront path distance to pm.cp_a_301						
						inc j by 1
					end
					else
					begin
						if vrDistanceR > 1 m and vrDistanceR < vrDistanceMin then
						begin
							set vrDistance2nd to vrDistanceMin
							set vloc2nd to vlocMin
							set vrDistanceMin to vrDistanceR
							set vlocMin to vlocTemp
						end
						else if vrDistanceR > 1 m and vrDistanceR < vrDistance2nd and vrDistanceR > vrDistanceMin then
						begin
							set vrDistance2nd to vrDistanceR
							set vloc2nd to vlocTemp						
						end
						inc j by 1
					end
				end
				
				if vlistOHT_ParkCheck(i) aiCheck = 0 then
				begin
					set viTemp(1) to 0
					for each vlocTemp in vloclist_CurrentRoute 
					begin
						if vlocTemp = vlocMin then
						begin
							dispatch vvFront to vloc2nd
							set viTemp(1) to 1
							break
						end
						else if vlocTemp = vloc2nd then
						begin
							dispatch vvFront to vlocMin
							set viTemp(1) to 1
							break
						end
					end
					
					if viTemp(1) = 0 then
						dispatch vvFront to vlocMin
				end
					
				set vloc2nd to null
				set vlocMin to null	
				set vvFront to null
				set vlocFront to null		
				set vrDistance2nd to 9999999999
				set vrDistanceMin to 9999999999											
				set vlistOHT_ParkCheck(i) aiCheck to 0
			end // end of 1st ife
		end // end of while
	
	end
end

begin pm task search procedure
	if this vehicle aID > vnOHT(anVehicleType) then    
	begin
		move into queue qDisable
		wait to be ordered on ol_Disable    /* If vnOHT > OHT # in Model, rest are disabled */
		return
	end
	
	else if aAssign = 0 and this vehicle anVehicleType <= 4 then
	begin
		if this vehicle aiYellow = 0 then
		begin
			set k = 0 
			while k < 17 do
			begin
				inc k by 1
				if cPark(k) current < viParkCapa(k) then
				begin
					inc cPark(k) by 1
					set this vehicle aiYellow = 1
					dispatch this vehicle to vlocParkList(k)
					set this vehicle alocPark to vlocParkList(k)
					set this vehicle segments first color to green yellow
					break
				end
			end	
		end	
	end
end

begin pm pickup procedure

	if this vehicle anVehicleType <= 4 then
	begin
		remove this vehicle closest schedjob load from vlistLoad(4 + this vehicle closest schedjob load anLoadType)
		
		if anDeliverType = 1 then 				// STK to UTB
			wait for n 14.1, 14.1/5
		else if anDeliverType = 2 then			// UTB to EQ
			wait for n 12.7, 1.3
		else if anDeliverType = 0 then			// EQ to MIC
			wait for n 16.4, 2.4
			
		set this vehicle closest schedjob load atUnload to ac
	end
			
	set this vehicle segments first color to sea
end

begin pm setdown procedure

	if this vehicle anVehicleType <= 4 then
	begin
		remove this vehicle closest schedjob load from vlistLoad(4 + this vehicle closest schedjob load anLoadType)
		
		if anDeliverType = 1 then				// STK to UTB
		begin
			set this vehicle closest schedjob load arSetDownTime to n 11.2, 1.3
			wait for this vehicle closest schedjob load arSetDownTime
		end
		else if anDeliverType = 2 then			// UTB to EQ
		begin
			set this vehicle closest schedjob load arSetDownTime to n 16.7, 2.4
			wait for this vehicle closest schedjob load arSetDownTime
		end
		else if anDeliverType = 0 then			// EQ to MIC
		begin
			set this vehicle closest schedjob load arSetDownTime to n 12.5, 2.3
			wait for this vehicle closest schedjob load arSetDownTime
		end
	end
			
	set this vehicle segments first color to blue violet
	insert this vehicle into vlistOHT(anVehicleType)
end

begin pm resume moving procedure
   wait for vtResume
end

/* Dispatching Rule */
begin pDispatch arriving procedure
	while 1=1 do
	begin
		wait for vtSchedule
				
		set i = 1
		while i <= 4 do
		begin
		
			while vlistOHT(i) size > 0 and vlistLoad(i) size > 0 do //check OHT number and load creation
			begin
				set vlSelect = null
				set vvSelect = null
				set vtSelect = 0
				
				for each vohtTemp in vlistOHT(i) do
				begin
					for each vlTemp in vlistLoad(i) do
					begin
						if aiHotLot = 10 then
						begin
							set vlSelect = vlTemp
							set vvSelect = vohtTemp
							break
						end
						else
						begin
							if vlTemp anTransfer = 1 then
								set vrDistance = vohtTemp path distance to vlTemp alocFrom  //setting starting point for distance measure 
							else
								set vrDistance = vohtTemp path distance to vlTemp alocStorage
							
							set vtCost = 3000 - vtPriorityCost - ((ac - vlTemp atTR) * vnTimeWeight) + (vrDistance / 1000 / vrNormalVelocity(i)) //calculating weight value for load that is closest

							if vlSelect = null then
							begin
								set vlSelect = vlTemp
								set vvSelect = vohtTemp
								set vtSelect = vtCost
							end
							
							else if (ac - vlSelect atTR) < vtTimeLimit and (ac - vlTemp atTR) >= vtTimeLimit then
							begin
								set vlSelect = vlTemp
								set vvSelect = vohtTemp
								set vtSelect = vtCost
							end
							
							else if (ac - vlSelect atTR) < vtTimeLimit and (ac - vlTemp atTR) < vtTimeLimit then
							begin
								if vtCost < vtSelect then
								begin
									set vlSelect = vlTemp
									set vvSelect = vohtTemp
									set vtSelect = vtCost
								end
							end
							
							else if (ac - vlSelect atTR) >= vtTimeLimit and (ac - vlTemp atTR) >= vtTimeLimit then
							begin
								if vtCost < vtSelect then
								begin
									set vlSelect = vlTemp
									set vvSelect = vohtTemp
									set vtSelect = vtCost
								end
							end
						end	
					end
				end
					
				if vlSelect <> null then
				begin
					claim vlSelect for vvSelect
				
					for each vJob in vvSelect schedjobs do
					begin
						if vJob type = "retrieve" then 
						set vvSelect current schedjob to vJob     
					end     
					
					for each vJob in vvSelect schedjobs do
					begin
						if vJob type = "move" then 
						begin
							print vJob location to vsTemp
							if vvSelect aiYellow = 1 and vsTemp substring(7, 4) = "Park" then
							begin
								set vvSelect aiYellow = 0
								set k to vsTemp substring(12, 2)
								set vvSelect alocPark to null
								dec cPark(k) by 1
							end				
							
							cancel vJob     
						end
					end 
									
					set vlSelect atAssign to ac
					set vlSelect atAssignInit to ac
	
					set vvSelect aAssign = 1
					set vvSelect segments first color to goldenrod
					set vvSelect vhlRetDistance to vvSelect total distance traveled      
					    
					if vlSelect anTransfer = 1 then 
						set vrDistance = vvSelect path distance to vlSelect alocFrom  //setting starting point for distance measure
					else
						set vrDistance = vvSelect path distance to vlSelect alocStorage
	
					remove vvSelect from vlistOHT(i)
					remove vlSelect from vlistLoad(i)
					
					set vlSelect avDispatch to vvSelect
					
					insert vlSelect into vlistLoad(4+i)  /* Assigned Load */
				end
			end	
						
			inc i by 1
		end
	end
end

/* ReAssign Process */
begin pReAssign arriving procedure
	while 1=1 do
	begin
		wait for vtSchedule
		
		set j = 1
		while j <= 4 do
		begin
		
			while vlistOHT(j) size > 0 and vlistLoad(4 + j) size > 0 do //check OHT number and load creation
			begin
				set vlSelect = null
				set vvSelect = null
				set vtSelect = 0
				
				for each vlTemp in vlistLoad(4 + j) do 
				begin
					set viCheck = 1
					for each vohtTemp in vlistOHT(j) do
					begin
						if vlTemp anTransfer = 1 then 
						begin
							set vrDistance = vohtTemp path distance to vlTemp alocFrom  //setting starting point for distance measure
							set vrDistance2 = vlTemp avDispatch path distance to vlTemp alocFrom
						end
						else
						begin
							set vrDistance = vohtTemp path distance to vlTemp alocStorage
							set vrDistance2 = vlTemp avDispatch path distance to vlTemp alocStorage
						end
					
						if vrDistance < vrDistance2 then
						begin
							if viCheck = 1 then
							begin
								set vlSelect = vlTemp
								set vvSelect = vohtTemp
								set vrDistanceTemp to vrDistance
								inc viCheck by 1       
							end
							else 
							begin
								if vrDistance < vrDistanceTemp then
								begin
									set vlSelect = vlTemp
									set vvSelect = vohtTemp 
									set vrDistanceTemp to vrDistance             
								end
							end
						end
					end
				end
	
				if vlSelect <> null and vlSelect avDispatch <> vvSelect then
				begin
			
					/*-------Revised Code-------*/					
					set k = 0 
					while k < 17 do
					begin
						inc k by 1
						if cPark(k) current < viParkCapa(k) then
						begin
							inc cPark(k) by 1
							set vlSelect avDispatch aiYellow = 1
							dispatch vlSelect avDispatch to vlocParkList(k)
							set vlSelect avDispatch alocPark to vlocParkList(k)
							set vlSelect avDispatch segments first color to green yellow
							break
						end
					end	
								
					// Swap current "Retrieve" job for "Move" job
					for each vJob in vlSelect avDispatch schedjobs do
					begin
						if vJob type = "move" then 
							set vlSelect avDispatch current schedjob to vJob      
					end
					
					// Cancel Remaining "Retrieve" job
					for each vJob in vlSelect avDispatch schedjobs do
					begin
						if vJob type = "retrieve" then 
							cancel vJob      
					end
					/*-------------------------*/
					
					insert vlSelect avDispatch into vlistOHT(j)
					
					if vlSelect avDispatch anVehicleType = 1 and vlSelect avDispatch aiYellow = 0 then
						set vlSelect avDispatch segments first color to blue violet
					else if vlSelect avDispatch anVehicleType = 2 and vlSelect avDispatch aiYellow = 0 then
						set vlSelect avDispatch segments first color to purple
					
					set vlSelect avDispatch aAssign = 0					
					
					claim vlSelect for vvSelect
					
					for each vJob in vvSelect schedjobs do
					begin
						if vJob type = "retrieve" then 
							set vvSelect current schedjob to vJob     
					end     
			
					for each vJob in vvSelect schedjobs do
					begin
						if vJob type = "move" then 	
						begin
							print vJob location to vsTemp 
							if vvSelect aiYellow = 1 and vsTemp substring(7, 4) = "Park" then
							begin
								set vvSelect aiYellow to 0
								set k to vsTemp substring(12, 2)
								set vvSelect alocPark to null
								dec cPark(k) by 1
							end
							
							cancel vJob     
						end
					end 
			
					set vlSelect atAssign to ac
		
					set vvSelect aAssign = 1
					set vvSelect segments first color to goldenrod
					set vvSelect vhlRetDistance to vvSelect total distance traveled
					
										
					remove vvSelect from vlistOHT(j)
					set vlSelect avDispatch to vvSelect 
					set vrDistanceTemp to 0 
				end
			else
				break
			end
			
			inc j by 1
		end
	end
end

begin pm work ok function
	return false
end

begin pm park ok function
	return false
end

/*
begin pm.high_in passing station function

	set theVehicle defined forward normal to 2.0 m per sec
	set theVehicle defined forward curve to 0.5 m per sec	
	set theVehicle defined acceleration to 1.0 m per sec
	set theVehicle defined deceleration to 1.5 m per sec	

	return true
end

begin pm.high_out passing station function

	set theVehicle defined forward normal to vrNormalVelocity(theVehicle anVehicleType) m per sec
	set theVehicle defined forward curve to vrCurveVelocity(theVehicle anVehicleType) m per sec	
	set theVehicle defined acceleration to vrAcceleration(theVehicle anVehicleType) m per sec
	set theVehicle defined deceleration to vrDeceleration(theVehicle anVehicleType) m per sec	
	
	return true
end

begin pm speed changed function

	if theVehicle vehicle in front <> null then 
	begin  
		/* Vehicle speed is limited by the vehicle pointed to by the "vehicle in front" attribute */  
		if theVehicle current velocity <= 0.0 and theVehicle status = "Deliver" then
		begin 
			if theVehicle load list first alocFrom = pm:cp_UTB_1_9  then 
				print "stop" to message			
			/* Vehicle has stopped due to congestion */  
			/*set theVehicle A_cgStopDelay = ac /* mark the start of a delay */ 
			set theVehicle A_cgStopVeh = theVehicle vehicle in front  
			set theVehicle color = red */
		end  
	end  
	
	return true 

end
*/

/*
begin pm.Dest_Change passing station function // Destination Change

	if theVehicle aiBoxOut = 1 then
	begin
		set vi to 10
		while vi > 1  do
		begin
			if cConvL(vi) current = 0 and theVehicle current schedjob type = "deliver" and theVehicle aiLocAssigned != 1 then
			begin
				inc cConvL(vi) by 1
				print "pm.cp_ConvL_" vi to vsTemp  
				set theVehicle current schedjob location to vsTemp
				set theVehicle aiLocAssigned to 1
				break
			end		
			dec vi by 1
		end
	end
	else if	theVehicle aiBoxOut = 2 then
	begin
		set vi to 2
		while vi < 11  do
		begin
			if cConvL(vi) current = 0 and theVehicle current schedjob type = "deliver" and theVehicle aiLocAssigned != 1 then
			begin
				inc cConvL(vi) by 1
				print "pm.cp_ConvL_" vi to vsTemp  
				set theVehicle current schedjob location to vsTemp
				set theVehicle aiLocAssigned to 1
				break
			end		
			inc vi by 1
		end
	end
	
	return true
end*/
/*
begin pm.cp_BoxOut_1 passing station function
	if theVehicle number of loads on board > 0 then
		set theVehicle atEnterToOut to ac
		
	return true
end
begin pm.cp_BoxOut_2 passing station function	
	if theVehicle atEnterToOut != 0 then
	begin
	//	print theVehicle, "\t", ac, "\t", ac - theVehicle atEnterToOut to message
		print ac - theVehicle atEnterToOut to vfpOutResult(9)
		set theVehicle atEnterToOut to 0
	end
	
	return true
end

begin pm.cp_BoxOut_3 passing station function
	if theVehicle atEnterToOut != 0 then
	begin
		print ac - theVehicle atEnterToOut to vfpOutResult(9)
	//	print ac, "\t", ac - theVehicle atEnterToOut , "\t", theVehicle to message
		set theVehicle atEnterToOut to 0
	end
	
	return true	
end
*/
/*
begin pm.PassingCount passing station function

	if stopLoc = pm.cp_Lcount_1 or stopLoc = pm.cp_Lcount_2 or stopLoc = pm.cp_Lcount_3 or stopLoc = pm.cp_Lcount_4 then
	begin
		print stopLoc to vsTemp
		set viTemp to vsTemp substring(14,1)
		inc viNcount(viTemp) by 1
		set vsTemp to null
		set viTemp to 0
	end

	return true
end
*/
/*
begin pm decelerate to destination function

	if theVehicle current schedjob type = "deliver" then
	begin
		if destLoc = pm.cp_ConvL_2  then inc cConvL(2 ) by 1 else
		if destLoc = pm.cp_ConvL_3  then inc cConvL(3 ) by 1 else
		if destLoc = pm.cp_ConvL_4  then inc cConvL(4 ) by 1 else
		if destLoc = pm.cp_ConvL_5  then inc cConvL(5 ) by 1 else
		if destLoc = pm.cp_ConvL_6  then inc cConvL(6 ) by 1 else
		if destLoc = pm.cp_ConvL_7  then inc cConvL(7 ) by 1 else
		if destLoc = pm.cp_ConvL_8  then inc cConvL(8 ) by 1 else
		if destLoc = pm.cp_ConvL_9  then inc cConvL(9 ) by 1 else
		if destLoc = pm.cp_ConvL_10 then inc cConvL(10) by 1 
	end

	return true
end
*/

