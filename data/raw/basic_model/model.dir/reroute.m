/*begin pm.check passing station function

	for each vlocTemp in theVehicle current route do
	begin
		if stopLoc = pm.cp_check_1 and vlocTemp = pm.cp_d7 then
		begin
			dispatch theVehicle to pm.cp_reroute_1
			for each vJob in theVehicle schedjobs do
			begin
				if vJob location = pm.cp_reroute_1 then 
					set theVehicle current schedjob to vJob 
			end
			break
		end
		else if stopLoc = pm.cp_check_2 and vlocTemp = pm.cp_d11 then
		begin
			dispatch theVehicle to pm.cp_reroute_2
			for each vJob in theVehicle schedjobs do
			begin
				if vJob location = pm.cp_reroute_2 then 
					set theVehicle current schedjob to vJob 
			end
			break
		end
/*		else if stopLoc = pm.cp_check_3 and vlocTemp = pm.cp_d47 then
		begin
			set viRandom to oneof(1:1, 1:0)
			if viRandom = 1 then
				begin
				dispatch theVehicle to pm.cp_reroute_3
				for each vJob in theVehicle schedjobs do
				begin
					if vJob location = pm.cp_reroute_3 then 
						set theVehicle current schedjob to vJob 
				end
				break
			end
			else
				break
		end
		else if stopLoc = pm.cp_check_4 and vlocTemp = pm.cp_d11 then
		begin
			dispatch theVehicle to pm.cp_reroute_4
			for each vJob in theVehicle schedjobs do
			begin
				if vJob location = pm.cp_reroute_4 then 
					set theVehicle current schedjob to vJob 
			end
			break
		end*/
	end
	set viRandom to 0
	return true
end

begin pm.reroute decelerate to destination function
	return false
end

begin pm.reroute decelerate ok function
	return false
end

*/

