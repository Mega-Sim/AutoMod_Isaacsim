// vehicle.c
// AutoMod 12.6.1 Generated File
// Build: 12.6.1.12
// Model name:	model
// Model path:	D:\Project\1_SDI\SDIHU Factory 2\2. Model\30. model 231030~\231101 model 9~12_basic\model.dir\
// Generated:	Wed Feb 14 10:16:57 2024
// Applied/AutoMod Licensee Confidential
// NO DISTRIBUTION OR REPRODUCTION RIGHTS GRANTED!
// Copyright (c) 1988-2015 Applied Materials All rights reserved.
//
// All Rights Reserved.  Reproduction or transmission in whole or
// in part, in any form or by any means, electronic, mechanical or
// otherwise, is prohibited without the prior written consent of
// copyright owner.
//
// Licensed Material - Property of Applied Materials, Inc.
//
// Applied Materials, Inc.
// 3050 Bowers Drive
// P.O. Box 58039
// Santa Clara, CA 95054-3299
// U.S.A.
//


#include "cdecls.h"


static int32
pm_vehinit(vehicle* am_theVehicle)
{
	load* localactor = (load*)am_theVehicle;
	AMDebuggerBeginRoutine("vehicle.m", "Vehicle initialization function", "model.pm", localactor);
	{
		char*	names[1];
		void*	ptrs[1];
		char*	(*valstrfuncs[1])(void*);
		
		names[0] = "theVehicle";
		ptrs[0] = &am_theVehicle;
		valstrfuncs[0] = VehiclePtr_valstrfunc;
		AMDebuggerParams("model.pm", pm_vehinit, localactor, 1, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 2);
			am2_viInit += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 4);
			if (StringCompare(VehGetType(ValidPtr(am_theVehicle, 81, vehicle*)), "EVL") == 0) {
				AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 4);
				ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType = 1;
				EntityChanged(0x00000040);
			}
			else {
				AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 5);
				if (StringCompare(VehGetType(ValidPtr(am_theVehicle, 81, vehicle*)), "EVL2") == 0) {
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 5);
					ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType = 2;
					EntityChanged(0x00000040);
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 7);
			if (StringCompare(VehGetType(ValidPtr(am_theVehicle, 81, vehicle*)), "EVL") == 0) {
				AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 7);
				VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(am_theVehicle, 81, vehicle*))), 84, VehSeg*), 21);
				EntityChanged(0x01000040);
			}
			else {
				AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 8);
				if (StringCompare(VehGetType(ValidPtr(am_theVehicle, 81, vehicle*)), "EVL2") == 0) {
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 8);
					VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(am_theVehicle, 81, vehicle*))), 84, VehSeg*), 12);
					EntityChanged(0x01000040);
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 10);
			if (ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType <= 4) {
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 12);
					VehSetDefForNormalVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrNormalVelocity[ValidIndex("am_model.am_vrNormalVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 13);
					VehSetDefForCurveVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrCurveVelocity[ValidIndex("am_model.am_vrCurveVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 14);
					VehSetDefForSpurVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrCurveVelocity[ValidIndex("am_model.am_vrCurveVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 16);
					VehSetDefRevNormalVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrNormalVelocity[ValidIndex("am_model.am_vrNormalVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 17);
					VehSetDefRevCurveVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrCurveVelocity[ValidIndex("am_model.am_vrCurveVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 18);
					VehSetDefRevSpurVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrCurveVelocity[ValidIndex("am_model.am_vrCurveVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 20);
					VehSetDefAccel(ValidPtr(am_theVehicle, 81, vehicle*), FromModelTime(ToModelRate(ToModelDistance(am2_vrAcceleration[ValidIndex("am_model.am_vrAcceleration", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 21);
					VehSetDefDecel(ValidPtr(am_theVehicle, 81, vehicle*), FromModelTime(ToModelRate(ToModelDistance(am2_vrDeceleration[ValidIndex("am_model.am_vrDeceleration", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 23);
					VehSetDefBrakeDist(ValidPtr(am_theVehicle, 81, vehicle*), ToModelDistance(am2_vrBrakeDistance, UNITMETERS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 24);
					VehSetDefStopDist(ValidPtr(am_theVehicle, 81, vehicle*), ToModelDistance(am2_vrStopDistance, UNITMETERS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 26);
					am2_vcOHT[ValidIndex("am_model.am_vcOHT", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)] += 1;
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 27);
					ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aID = am2_vcOHT[ValidIndex("am_model.am_vcOHT", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)];
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 28);
					ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aAssign = 0;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 30);
					if (ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aID <= am2_vnOHT[ValidIndex("am_model.am_vnOHT", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 20)]) {
						AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 31);
						ListAppendItem(VehicleList, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 20)], am_theVehicle);	// append item to end of list
					}
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 33);
			ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_alocPark = NULL;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 34);
			ListAppendItem(VehicleList, am2_vlistOHT_ParkCheck, am_theVehicle);	// append item to end of list
		}
		{
			AMDebugger("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor, 36);
			AMDebuggerEndRoutine("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("vehicle.m", "Vehicle initialization function", "model.pm", pm_vehinit, localactor);
} /* end of pm_vehinit */

static int32
pm_steer_pass(vehicle* am_theVehicle, simloc* am_stopLoc)
{
	AMLocationListItem* am_lv0; // 'for each' loop variable
	AMLocationList* am_ls0 = NULL; // 'for each' list

	load* localactor = (load*)am_theVehicle;
	AMDebuggerBeginRoutine("vehicle.m", "Passing station function", "model.pm.steer", localactor);
	{
		char*	names[2];
		void*	ptrs[2];
		char*	(*valstrfuncs[2])(void*);
		
		names[0] = "theVehicle";
		ptrs[0] = &am_theVehicle;
		valstrfuncs[0] = VehiclePtr_valstrfunc;
		names[1] = "stopLoc";
		ptrs[1] = &am_stopLoc;
		valstrfuncs[1] = Location_valstrfunc;
		AMDebuggerParams("model.pm.steer", pm_steer_pass, localactor, 2, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor, 41);
			am_ls0 = 0;
			ListCopy(LocationList, am_ls0, VehGetRouteList(ValidPtr(am_theVehicle, 81, vehicle*)));
			for (am_lv0 = (am_ls0) ? (am_ls0)->first : NULL; am_lv0; am_lv0 = am_lv0->next) {
				am2_vlocTemp = am_lv0->item;
				{
					{
						AMDebugger("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor, 43);
						if (LocGetColor(ValidPtr(am2_vlocTemp, 40, simloc*)) == 7 || (LocGetColor(ValidPtr(am2_vlocTemp, 40, simloc*)) == 6 || LocGetColor(ValidPtr(am2_vlocTemp, 40, simloc*)) == 17)) {
							AMDebugger("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor, 44);
							break;
						}
					}
				}
			}
			ListRemoveAllAndFree(LocationList, am_ls0); /* End of for each */
		}
		{
			AMDebugger("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor, 47);
			if ((ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiSteering == 1 && (LocGetColor(ValidPtr(am2_vlocTemp, 40, simloc*)) == 6 || LocGetColor(ValidPtr(am2_vlocTemp, 40, simloc*)) == 17)) || (ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiSteering == 2 && LocGetColor(ValidPtr(am2_vlocTemp, 40, simloc*)) == 7)) {
				{
					AMDebugger("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor, 49);
					VehSetDefForNormalVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrNormalVelocity[ValidIndex("am_model.am_vrNormalVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)] * 0.67000000000000004, UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor, 50);
					VehSetDefForCurveVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrCurveVelocity[ValidIndex("am_model.am_vrCurveVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)] * 0.67000000000000004, UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor, 51);
					ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiSteerChange = 1;
					EntityChanged(0x00000040);
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor, 54);
	ListRemoveAllAndFree(LocationList, am_ls0);
			AMDebuggerEndRoutine("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("vehicle.m", "Passing station function", "model.pm.steer", pm_steer_pass, localactor);
} /* end of pm_steer_pass */

static int32
pm_Avoid_pass(vehicle* am_theVehicle, simloc* am_stopLoc)
{
	load* localactor = (load*)am_theVehicle;
	AMDebuggerBeginRoutine("vehicle.m", "Passing station function", "model.pm.Avoid", localactor);
	{
		char*	names[2];
		void*	ptrs[2];
		char*	(*valstrfuncs[2])(void*);
		
		names[0] = "theVehicle";
		ptrs[0] = &am_theVehicle;
		valstrfuncs[0] = VehiclePtr_valstrfunc;
		names[1] = "stopLoc";
		ptrs[1] = &am_stopLoc;
		valstrfuncs[1] = Location_valstrfunc;
		AMDebuggerParams("model.pm.Avoid", pm_Avoid_pass, localactor, 2, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("vehicle.m", "Passing station function", "model.pm.Avoid", pm_Avoid_pass, localactor, 59);
			if (ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiSteering == 0) {
				{
					AMDebugger("vehicle.m", "Passing station function", "model.pm.Avoid", pm_Avoid_pass, localactor, 61);
					if (LocGetColor(ValidPtr(am_stopLoc, 40, simloc*)) == 7) {
						AMDebugger("vehicle.m", "Passing station function", "model.pm.Avoid", pm_Avoid_pass, localactor, 62);
						ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiSteering = 1;
						EntityChanged(0x00000040);
					}
					else {
						AMDebugger("vehicle.m", "Passing station function", "model.pm.Avoid", pm_Avoid_pass, localactor, 64);
						ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiSteering = 2;
						EntityChanged(0x00000040);
					}
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Passing station function", "model.pm.Avoid", pm_Avoid_pass, localactor, 67);
			AMDebuggerEndRoutine("vehicle.m", "Passing station function", "model.pm.Avoid", pm_Avoid_pass, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("vehicle.m", "Passing station function", "model.pm.Avoid", pm_Avoid_pass, localactor);
} /* end of pm_Avoid_pass */

static int32
pm_dummy_pass(vehicle* am_theVehicle, simloc* am_stopLoc)
{
	load* localactor = (load*)am_theVehicle;
	AMDebuggerBeginRoutine("vehicle.m", "Passing station function", "model.pm.dummy", localactor);
	{
		char*	names[2];
		void*	ptrs[2];
		char*	(*valstrfuncs[2])(void*);
		
		names[0] = "theVehicle";
		ptrs[0] = &am_theVehicle;
		valstrfuncs[0] = VehiclePtr_valstrfunc;
		names[1] = "stopLoc";
		ptrs[1] = &am_stopLoc;
		valstrfuncs[1] = Location_valstrfunc;
		AMDebuggerParams("model.pm.dummy", pm_dummy_pass, localactor, 2, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("vehicle.m", "Passing station function", "model.pm.dummy", pm_dummy_pass, localactor, 72);
			if (ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiSteerChange == 1) {
				{
					AMDebugger("vehicle.m", "Passing station function", "model.pm.dummy", pm_dummy_pass, localactor, 74);
					VehSetDefForNormalVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrNormalVelocity[ValidIndex("am_model.am_vrNormalVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Passing station function", "model.pm.dummy", pm_dummy_pass, localactor, 75);
					VehSetDefForCurveVel(ValidPtr(am_theVehicle, 81, vehicle*), ToModelRate(ToModelDistance(am2_vrCurveVelocity[ValidIndex("am_model.am_vrCurveVelocity", ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_anVehicleType, 4)], UNITMETERS), UNITSECONDS));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Passing station function", "model.pm.dummy", pm_dummy_pass, localactor, 76);
					ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiSteerChange = 0;
					EntityChanged(0x00000040);
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Passing station function", "model.pm.dummy", pm_dummy_pass, localactor, 79);
			AMDebuggerEndRoutine("vehicle.m", "Passing station function", "model.pm.dummy", pm_dummy_pass, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("vehicle.m", "Passing station function", "model.pm.dummy", pm_dummy_pass, localactor);
} /* end of pm_dummy_pass */

static int32
pm_start(vehicle* am_theVehicle)
{
	load* localactor = (load*)am_theVehicle;
	AMDebuggerBeginRoutine("vehicle.m", "Start to move function", "model.pm", localactor);
	{
		char*	names[1];
		void*	ptrs[1];
		char*	(*valstrfuncs[1])(void*);
		
		names[0] = "theVehicle";
		ptrs[0] = &am_theVehicle;
		valstrfuncs[0] = VehiclePtr_valstrfunc;
		AMDebuggerParams("model.pm", pm_start, localactor, 1, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 85);
			{
				char* pArg1 = rel_simlocname(VehGetCurLoc(ValidPtr(am_theVehicle, 81, vehicle*)), am_model.$sys);

				char* am_tmp;
				am_tmp = bufsprintf("%s", pArg1);
				SetString(&am2_vsTemp, am_tmp);
				EntityChanged(0x01000000);
			}
		}
		{
			AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 87);
			if (StringCompare(StrGetSubStr(am2_vsTemp, 7, 4), "Park") == 0 && ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiYellow == 1 && LocCompare(ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_alocPark, VehGetCurLoc(ValidPtr(am_theVehicle, 81, vehicle*))) == 0) {
				{
					AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 89);
					ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_aiYellow = 0;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 90);
					ValidPtr(am_theVehicle, 81, vehicle*)->load.attribute->am2_alocPark = NULL;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 91);
					am2_k = str2Integer(StrGetSubStr(am2_vsTemp, 12, 2));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 92);
					CntDecContents(ValidPtr(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 10, counter*), 1, NULL);
					EntityChanged(0x01000010);
				}
				{
					AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 94);
					if (StringCompare(VehGetType(ValidPtr(am_theVehicle, 81, vehicle*)), "EVL") == 0) {
						AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 95);
						VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(am_theVehicle, 81, vehicle*))), 84, VehSeg*), 21);
						EntityChanged(0x01000040);
					}
					else {
						AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 96);
						if (StringCompare(VehGetType(ValidPtr(am_theVehicle, 81, vehicle*)), "EVL2") == 0) {
							AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 97);
							VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(am_theVehicle, 81, vehicle*))), 84, VehSeg*), 12);
							EntityChanged(0x01000040);
						}
					}
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Start to move function", "model.pm", pm_start, localactor, 100);
			AMDebuggerEndRoutine("vehicle.m", "Start to move function", "model.pm", pm_start, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("vehicle.m", "Start to move function", "model.pm", pm_start, localactor);
} /* end of pm_start */

static int32
pPark_Check_arriving(load* this, int32 step, void* args)
{
	struct _localargs {
		AMLocationListItem* lv1; // 'for each' loop variable
		AMLocationList* ls1; // 'for each' list
		AMLocationListItem* lv2; // 'for each' loop variable
		AMLocationList* ls2; // 'for each' list
	} *am_localargs = (struct _localargs*)args;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("vehicle.m", "Arriving procedure", "model.pPark_Check", localactor);
	AMDebuggerParams("model.pPark_Check", pPark_Check_arriving, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	am_localargs = (struct _localargs*)xcalloc(1, sizeof(struct _localargs));
	{
		{
			AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 106);
			while (1 == 1) {
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 108);
					if (waitfor(ToModelTime(1.0000000000000000, UNITSECONDS), this, pPark_Check_arriving, Step 2, am_localargs) == Delayed)
						return Delayed;
Label2: ; // Step 2
				}
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 109);
					am2_i = 0;
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 110);
					while (am2_i < Size(List, VehicleList, am2_vlistOHT_ParkCheck)) {
						{
							AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 112);
							am2_i += 1;
							EntityChanged(0x01000000);
						}
						{
							AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 113);
							if (VehGetVehicleInFront(ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*)) != NULL && StringCompare(VehGetStatus(ValidPtr(VehGetVehicleInFront(ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*)), 81, vehicle*)), "Idle") == 0 && VehGetCurSchedJob(ValidPtr(VehGetVehicleInFront(ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*)), 81, vehicle*)) == NULL) {
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 115);
									am2_vvFront = VehGetVehicleInFront(ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*));
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 116);
									am2_vlocFront = VehGetCurLoc(ValidPtr(am2_vvFront, 81, vehicle*));
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 117);
									ListCopy(LocationList, am2_vloclist_CurrentRoute, VehGetRouteList(ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*)));
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 118);
									ListAppendItem(LocationList, am2_vloclist_CurrentRoute, VehGetDest(ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*)));	// append item to end of list
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 119);
									am2_vrDistanceR = 2147483647;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 121);
									am2_j = 1;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 122);
									am_localargs->ls1 = 0;
									ListCopy(LocationList, am_localargs->ls1, am2_vlocAvoidList);
									for (am_localargs->lv1 = (am_localargs->ls1) ? (am_localargs->ls1)->first : NULL; am_localargs->lv1; am_localargs->lv1 = am_localargs->lv1->next) {
										am2_vlocTemp = am_localargs->lv1->item;
										{
											{
												AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 124);
												am2_k = 0;
												EntityChanged(0x01000000);
											}
											{
												AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 125);
												while (am2_k < 17) {
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 127);
														am2_k += 1;
														EntityChanged(0x01000000);
													}
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 128);
														if (CntGetCurConts(ValidPtr(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 10, counter*)) < am2_viParkCapa[ValidIndex("am_model.am_viParkCapa", am2_k, 30)] && ValidPtr(am2_vvFront, 81, vehicle*)->load.attribute->am2_aiYellow == 0) {
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 130);
																{
																	int result = inccount(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 1, this, pPark_Check_arriving, Step 3, am_localargs);
																	if (result != Continue) return result;
Label3: ;	// Step 3
																}
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 131);
																ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*)->load.attribute->am2_aiCheck = 1;
																EntityChanged(0x00000040);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 132);
																ValidPtr(am2_vvFront, 81, vehicle*)->load.attribute->am2_aiYellow = 1;
																EntityChanged(0x00000040);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 133);
																veh_dispatch(am2_vvFront, ListIndexItem(LocationList, am2_vlocParkList, am2_k), 0, NULL, 0);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 134);
																ValidPtr(am2_vvFront, 81, vehicle*)->load.attribute->am2_alocPark = ListIndexItem(LocationList, am2_vlocParkList, am2_k);
																EntityChanged(0x00000040);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 135);
																VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(am2_vvFront, 81, vehicle*))), 84, VehSeg*), 36);
																EntityChanged(0x01000040);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 136);
																break;
															}
														}
													}
												}
											}
											{
												AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 140);
												am2_vrDistanceR = FromModelDistance(VehGetDistToLoc(ValidPtr(am2_vvFront, 81, vehicle*), ValidPtr(am2_vlocTemp, 40, simloc*)), UNITMILLIMETERS);
												EntityChanged(0x01000000);
											}
											{
												AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 142);
												if (am2_j == 1 && am2_vrDistanceR > FromModelDistance(ToModelDistance(1, UNITMETERS), UNITMILLIMETERS)) {
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 144);
														am2_vrDistanceMin = am2_vrDistanceR;
														EntityChanged(0x01000000);
													}
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 145);
														am2_vlocMin = am2_vlocTemp;
														EntityChanged(0x01000000);
													}
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 146);
														am2_vloc2nd = LocGetQualifier(am_model.am_pm.am_cp_a_301, -9999);
														EntityChanged(0x01000000);
													}
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 147);
														am2_vrDistance2nd = FromModelDistance(VehGetDistToLoc(ValidPtr(am2_vvFront, 81, vehicle*), ValidPtr(LocGetQualifier(am_model.am_pm.am_cp_a_301, -9999), 40, simloc*)), UNITMILLIMETERS);
														EntityChanged(0x01000000);
													}
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 148);
														am2_j += 1;
														EntityChanged(0x01000000);
													}
												}
												else {
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 152);
														if (am2_vrDistanceR > FromModelDistance(ToModelDistance(1, UNITMETERS), UNITMILLIMETERS) && am2_vrDistanceR < am2_vrDistanceMin) {
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 154);
																am2_vrDistance2nd = am2_vrDistanceMin;
																EntityChanged(0x01000000);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 155);
																am2_vloc2nd = am2_vlocMin;
																EntityChanged(0x01000000);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 156);
																am2_vrDistanceMin = am2_vrDistanceR;
																EntityChanged(0x01000000);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 157);
																am2_vlocMin = am2_vlocTemp;
																EntityChanged(0x01000000);
															}
														}
														else {
															AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 159);
															if (am2_vrDistanceR > FromModelDistance(ToModelDistance(1, UNITMETERS), UNITMILLIMETERS) && am2_vrDistanceR < am2_vrDistance2nd && am2_vrDistanceR > am2_vrDistanceMin) {
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 161);
																	am2_vrDistance2nd = am2_vrDistanceR;
																	EntityChanged(0x01000000);
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 162);
																	am2_vloc2nd = am2_vlocTemp;
																	EntityChanged(0x01000000);
																}
															}
														}
													}
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 164);
														am2_j += 1;
														EntityChanged(0x01000000);
													}
												}
											}
										}
									}
									ListRemoveAllAndFree(LocationList, am_localargs->ls1); /* End of for each */
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 168);
									if (ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*)->load.attribute->am2_aiCheck == 0) {
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 170);
											am2_viTemp[1] = 0;
											EntityChanged(0x01000000);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 171);
											am_localargs->ls2 = 0;
											ListCopy(LocationList, am_localargs->ls2, am2_vloclist_CurrentRoute);
											for (am_localargs->lv2 = (am_localargs->ls2) ? (am_localargs->ls2)->first : NULL; am_localargs->lv2; am_localargs->lv2 = am_localargs->lv2->next) {
												am2_vlocTemp = am_localargs->lv2->item;
												{
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 173);
														if (LocCompare(am2_vlocTemp, am2_vlocMin) == 0) {
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 175);
																veh_dispatch(am2_vvFront, am2_vloc2nd, 0, NULL, 0);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 176);
																am2_viTemp[1] = 1;
																EntityChanged(0x01000000);
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 177);
																break;
															}
														}
														else {
															AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 179);
															if (LocCompare(am2_vlocTemp, am2_vloc2nd) == 0) {
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 181);
																	veh_dispatch(am2_vvFront, am2_vlocMin, 0, NULL, 0);
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 182);
																	am2_viTemp[1] = 1;
																	EntityChanged(0x01000000);
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 183);
																	break;
																}
															}
														}
													}
												}
											}
											ListRemoveAllAndFree(LocationList, am_localargs->ls2); /* End of for each */
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 187);
											if (am2_viTemp[1] == 0) {
												AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 188);
												veh_dispatch(am2_vvFront, am2_vlocMin, 0, NULL, 0);
											}
										}
									}
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 191);
									am2_vloc2nd = NULL;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 192);
									am2_vlocMin = NULL;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 193);
									am2_vvFront = NULL;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 194);
									am2_vlocFront = NULL;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 195);
									am2_vrDistance2nd = 2147483647;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 196);
									am2_vrDistanceMin = 2147483647;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor, 197);
									ValidPtr(ListIndexItem(VehicleList, am2_vlistOHT_ParkCheck, am2_i), 81, vehicle*)->load.attribute->am2_aiCheck = 0;
									EntityChanged(0x00000040);
								}
							}
						}
					}
				}
			}
		}
	}
LabelRet: ;
	ListRemoveAllAndFree(LocationList, am_localargs->ls1);
	ListRemoveAllAndFree(LocationList, am_localargs->ls2);
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("vehicle.m", "Arriving procedure", "model.pPark_Check", pPark_Check_arriving, localactor);
	return retval;
} /* end of pPark_Check_arriving */

static int32
pm_task(vehicle* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("vehicle.m", "Task search procedure", "model.pm", localactor);
	{
		char*	names[1];
		void*	ptrs[1];
		char*	(*valstrfuncs[1])(void*);
		
		names[0] = "Current";
		ptrs[0] = &this->curlocdata.sloc;
		valstrfuncs[0] = Location_valstrfunc;
		AMDebuggerParams("model.pm", pm_task, localactor, 1, names, ptrs, valstrfuncs);
	}
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 205);
			if (this->load.attribute->am2_aID > am2_vnOHT[ValidIndex("am_model.am_vnOHT", this->load.attribute->am2_anVehicleType, 20)]) {
				{
					AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 207);
					pushppa(this, pm_task, Step 2, am_localargs);
					pushppa(this, inqueue, Step 1, am2_qDisable);
					return Continue; // go move into territory
Label2: ; // Step 2
				}
				{
					AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 208);
					return waitorder(am2_ol_Disable, this, pm_task, Step 3, am_localargs);
Label3: ; // Step 3
				}
				{
					AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 209);
					{
							retval = Continue;
							goto LabelRet;
					}
				}
			}
			else {
				AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 212);
				if (this->load.attribute->am2_aAssign == 0 && this->load.attribute->am2_anVehicleType <= 4) {
					{
						AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 214);
						if (this->load.attribute->am2_aiYellow == 0) {
							{
								AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 216);
								am2_k = 0;
								EntityChanged(0x01000000);
							}
							{
								AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 217);
								while (am2_k < 17) {
									{
										AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 219);
										am2_k += 1;
										EntityChanged(0x01000000);
									}
									{
										AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 220);
										if (CntGetCurConts(ValidPtr(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 10, counter*)) < am2_viParkCapa[ValidIndex("am_model.am_viParkCapa", am2_k, 30)]) {
											{
												AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 222);
												{
													int result = inccount(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 1, this, pm_task, Step 4, am_localargs);
													if (result != Continue) return result;
Label4: ;	// Step 4
												}
											}
											{
												AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 223);
												this->load.attribute->am2_aiYellow = 1;
												EntityChanged(0x00000040);
											}
											{
												AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 224);
												veh_dispatch(this, ListIndexItem(LocationList, am2_vlocParkList, am2_k), 0, NULL, 0);
											}
											{
												AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 225);
												this->load.attribute->am2_alocPark = ListIndexItem(LocationList, am2_vlocParkList, am2_k);
												EntityChanged(0x00000040);
											}
											{
												AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 226);
												VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(this)), 84, VehSeg*), 36);
												EntityChanged(0x00000040);
											}
											{
												AMDebugger("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor, 227);
												break;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("vehicle.m", "Task search procedure", "model.pm", pm_task, localactor);
	return retval;
} /* end of pm_task */

static int32
pm_pickup(vehicle* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("vehicle.m", "Pickup procedure", "model.pm", localactor);
	{
		char*	names[2];
		void*	ptrs[2];
		char*	(*valstrfuncs[2])(void*);
		
		names[0] = "Load";
		ptrs[0] = &Front(List, SchedJobList, &this->jobs)->theload;
		valstrfuncs[0] = LoadPtr_valstrfunc;
		names[1] = "Current";
		ptrs[1] = &this->curlocdata.sloc;
		valstrfuncs[1] = Location_valstrfunc;
		AMDebuggerParams("model.pm", pm_pickup, localactor, 2, names, ptrs, valstrfuncs);
	}
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 236);
			if (this->load.attribute->am2_anVehicleType <= 4) {
				{
					AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 238);
					ListRemoveFirstMatch(LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", 4 + ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_anLoadType, 20)], JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)));	// remove first match from list
				}
				{
					AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 240);
					if (this->load.attribute->am2_anDeliverType == 1) {
						AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 241);
						if (waitfor(ToModelTime(normal1(am2_stream0, 14.100000000000000, 14.100000000000000 / 5), UNITSECONDS), this, pm_pickup, Step 2, am_localargs) == Delayed)
							return Delayed;
Label2: ; // Step 2
					}
					else {
						AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 242);
						if (this->load.attribute->am2_anDeliverType == 2) {
							AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 243);
							if (waitfor(ToModelTime(normal1(am2_stream0, 12.699999999999999, 1.3000000000000000), UNITSECONDS), this, pm_pickup, Step 3, am_localargs) == Delayed)
								return Delayed;
Label3: ; // Step 3
						}
						else {
							AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 244);
							if (this->load.attribute->am2_anDeliverType == 0) {
								AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 245);
								if (waitfor(ToModelTime(normal1(am2_stream0, 16.399999999999999, 2.3999999999999999), UNITSECONDS), this, pm_pickup, Step 4, am_localargs) == Delayed)
									return Delayed;
Label4: ; // Step 4
							}
						}
					}
				}
				{
					AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 247);
					ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_atUnload = ASIclock;
					EntityChanged(0x00000040);
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor, 250);
			VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(this)), 84, VehSeg*), 63);
			EntityChanged(0x00000040);
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("vehicle.m", "Pickup procedure", "model.pm", pm_pickup, localactor);
	return retval;
} /* end of pm_pickup */

static int32
pm_setdown(vehicle* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("vehicle.m", "Setdown procedure", "model.pm", localactor);
	{
		char*	names[2];
		void*	ptrs[2];
		char*	(*valstrfuncs[2])(void*);
		
		names[0] = "Load";
		ptrs[0] = &Front(List, SchedJobList, &this->jobs)->theload;
		valstrfuncs[0] = LoadPtr_valstrfunc;
		names[1] = "Current";
		ptrs[1] = &this->curlocdata.sloc;
		valstrfuncs[1] = Location_valstrfunc;
		AMDebuggerParams("model.pm", pm_setdown, localactor, 2, names, ptrs, valstrfuncs);
	}
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 255);
			if (this->load.attribute->am2_anVehicleType <= 4) {
				{
					AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 257);
					ListRemoveFirstMatch(LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", 4 + ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_anLoadType, 20)], JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)));	// remove first match from list
				}
				{
					AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 259);
					if (this->load.attribute->am2_anDeliverType == 1) {
						{
							AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 261);
							ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_arSetDownTime = normal1(am2_stream0, 11.199999999999999, 1.3000000000000000);
							EntityChanged(0x00000040);
						}
						{
							AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 262);
							if (waitfor(ToModelTime(ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_arSetDownTime, UNITSECONDS), this, pm_setdown, Step 2, am_localargs) == Delayed)
								return Delayed;
Label2: ; // Step 2
						}
					}
					else {
						AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 264);
						if (this->load.attribute->am2_anDeliverType == 2) {
							{
								AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 266);
								ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_arSetDownTime = normal1(am2_stream0, 16.699999999999999, 2.3999999999999999);
								EntityChanged(0x00000040);
							}
							{
								AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 267);
								if (waitfor(ToModelTime(ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_arSetDownTime, UNITSECONDS), this, pm_setdown, Step 3, am_localargs) == Delayed)
									return Delayed;
Label3: ; // Step 3
							}
						}
						else {
							AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 269);
							if (this->load.attribute->am2_anDeliverType == 0) {
								{
									AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 271);
									ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_arSetDownTime = normal1(am2_stream0, 12.500000000000000, 2.2999999999999998);
									EntityChanged(0x00000040);
								}
								{
									AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 272);
									if (waitfor(ToModelTime(ValidPtr(JobGetLoad(ValidPtr(VehGetClosestJob(this), 58, SchedJob*)), 32, load*)->attribute->am2_arSetDownTime, UNITSECONDS), this, pm_setdown, Step 4, am_localargs) == Delayed)
										return Delayed;
Label4: ; // Step 4
								}
							}
						}
					}
				}
			}
		}
		{
			AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 276);
			VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(this)), 84, VehSeg*), 21);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor, 277);
			ListAppendItem(VehicleList, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", this->load.attribute->am2_anVehicleType, 20)], this);	// append item to end of list
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("vehicle.m", "Setdown procedure", "model.pm", pm_setdown, localactor);
	return retval;
} /* end of pm_setdown */

static int32
pm_resumemove(vehicle* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("vehicle.m", "Resume moving procedure", "model.pm", localactor);
	AMDebuggerParams("model.pm", pm_resumemove, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("vehicle.m", "Resume moving procedure", "model.pm", pm_resumemove, localactor, 281);
			if (waitfor(am2_vtResume, this, pm_resumemove, Step 2, am_localargs) == Delayed)
				return Delayed;
Label2: ; // Step 2
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("vehicle.m", "Resume moving procedure", "model.pm", pm_resumemove, localactor);
	return retval;
} /* end of pm_resumemove */

static int32
pDispatch_arriving(load* this, int32 step, void* args)
{
	struct _localargs {
		AMVehicleListItem* lv3; // 'for each' loop variable
		AMVehicleList* ls3; // 'for each' list
		AMLoadListItem* lv4; // 'for each' loop variable
		AMLoadList* ls4; // 'for each' list
		AMSchedJobListItem* lv5; // 'for each' loop variable
		AMSchedJobList* ls5; // 'for each' list
		AMSchedJobListItem* lv6; // 'for each' loop variable
		AMSchedJobList* ls6; // 'for each' list
	} *am_localargs = (struct _localargs*)args;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("vehicle.m", "Arriving procedure", "model.pDispatch", localactor);
	AMDebuggerParams("model.pDispatch", pDispatch_arriving, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	am_localargs = (struct _localargs*)xcalloc(1, sizeof(struct _localargs));
	{
		{
			AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 286);
			while (1 == 1) {
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 288);
					if (waitfor(am2_vtSchedule, this, pDispatch_arriving, Step 2, am_localargs) == Delayed)
						return Delayed;
Label2: ; // Step 2
				}
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 290);
					am2_i = 1;
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 291);
					while (am2_i <= 4) {
						{
							AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 294);
							while (Size(List, VehicleList, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", am2_i, 20)]) > 0 && Size(List, LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", am2_i, 20)]) > 0) {
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 296);
									am2_vlSelect = NULL;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 297);
									am2_vvSelect = NULL;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 298);
									am2_vtSelect = ToModelTime(0, UNITSECONDS);
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 300);
									am_localargs->ls3 = 0;
									ListCopy(VehicleList, am_localargs->ls3, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", am2_i, 20)]);
									for (am_localargs->lv3 = (am_localargs->ls3) ? (am_localargs->ls3)->first : NULL; am_localargs->lv3; am_localargs->lv3 = am_localargs->lv3->next) {
										am2_vohtTemp = am_localargs->lv3->item;
										{
											{
												AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 302);
												am_localargs->ls4 = 0;
												ListCopy(LoadList, am_localargs->ls4, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", am2_i, 20)]);
												for (am_localargs->lv4 = (am_localargs->ls4) ? (am_localargs->ls4)->first : NULL; am_localargs->lv4; am_localargs->lv4 = am_localargs->lv4->next) {
													am2_vlTemp = am_localargs->lv4->item;
													{
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 304);
															if (this->attribute->am2_aiHotLot == 10) {
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 306);
																	am2_vlSelect = am2_vlTemp;
																	EntityChanged(0x01000000);
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 307);
																	am2_vvSelect = am2_vohtTemp;
																	EntityChanged(0x01000000);
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 308);
																	break;
																}
															}
															else {
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 312);
																	if (ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_anTransfer == 1) {
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 313);
																		am2_vrDistance = FromModelDistance(VehGetDistToLoc(ValidPtr(am2_vohtTemp, 81, vehicle*), ValidPtr(ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_alocFrom, 40, simloc*)), UNITMILLIMETERS);
																		EntityChanged(0x01000000);
																	}
																	else {
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 315);
																		am2_vrDistance = FromModelDistance(VehGetDistToLoc(ValidPtr(am2_vohtTemp, 81, vehicle*), ValidPtr(ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_alocStorage, 40, simloc*)), UNITMILLIMETERS);
																		EntityChanged(0x01000000);
																	}
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 317);
																	am2_vtCost = ToModelTime(3000 - FromModelTime(am2_vtPriorityCost, UNITSECONDS) - FromModelTime(((ASIclock - ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_atTR) * am2_vnTimeWeight), UNITSECONDS) + (am2_vrDistance / 1000 / am2_vrNormalVelocity[ValidIndex("am_model.am_vrNormalVelocity", am2_i, 4)]), UNITSECONDS);
																	EntityChanged(0x01000000);
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 319);
																	if (am2_vlSelect == NULL) {
																		{
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 321);
																			am2_vlSelect = am2_vlTemp;
																			EntityChanged(0x01000000);
																		}
																		{
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 322);
																			am2_vvSelect = am2_vohtTemp;
																			EntityChanged(0x01000000);
																		}
																		{
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 323);
																			am2_vtSelect = am2_vtCost;
																			EntityChanged(0x01000000);
																		}
																	}
																	else {
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 326);
																		if ((ASIclock - ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_atTR) < am2_vtTimeLimit && (ASIclock - ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_atTR) >= am2_vtTimeLimit) {
																			{
																				AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 328);
																				am2_vlSelect = am2_vlTemp;
																				EntityChanged(0x01000000);
																			}
																			{
																				AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 329);
																				am2_vvSelect = am2_vohtTemp;
																				EntityChanged(0x01000000);
																			}
																			{
																				AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 330);
																				am2_vtSelect = am2_vtCost;
																				EntityChanged(0x01000000);
																			}
																		}
																		else {
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 333);
																			if ((ASIclock - ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_atTR) < am2_vtTimeLimit && (ASIclock - ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_atTR) < am2_vtTimeLimit) {
																				{
																					AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 335);
																					if (am2_vtCost < am2_vtSelect) {
																						{
																							AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 337);
																							am2_vlSelect = am2_vlTemp;
																							EntityChanged(0x01000000);
																						}
																						{
																							AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 338);
																							am2_vvSelect = am2_vohtTemp;
																							EntityChanged(0x01000000);
																						}
																						{
																							AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 339);
																							am2_vtSelect = am2_vtCost;
																							EntityChanged(0x01000000);
																						}
																					}
																				}
																			}
																			else {
																				AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 343);
																				if ((ASIclock - ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_atTR) >= am2_vtTimeLimit && (ASIclock - ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_atTR) >= am2_vtTimeLimit) {
																					{
																						AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 345);
																						if (am2_vtCost < am2_vtSelect) {
																							{
																								AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 347);
																								am2_vlSelect = am2_vlTemp;
																								EntityChanged(0x01000000);
																							}
																							{
																								AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 348);
																								am2_vvSelect = am2_vohtTemp;
																								EntityChanged(0x01000000);
																							}
																							{
																								AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 349);
																								am2_vtSelect = am2_vtCost;
																								EntityChanged(0x01000000);
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
												ListRemoveAllAndFree(LoadList, am_localargs->ls4); /* End of for each */
											}
										}
									}
									ListRemoveAllAndFree(VehicleList, am_localargs->ls3); /* End of for each */
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 356);
									if (am2_vlSelect != NULL) {
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 358);
											ClaimLoad(am2_vvSelect, am2_vlSelect, FALSE);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 360);
											am_localargs->ls5 = 0;
											ListCopy(SchedJobList, am_localargs->ls5, VehGetJobList(ValidPtr(am2_vvSelect, 81, vehicle*)));
											for (am_localargs->lv5 = (am_localargs->ls5) ? (am_localargs->ls5)->first : NULL; am_localargs->lv5; am_localargs->lv5 = am_localargs->lv5->next) {
												am2_vJob = am_localargs->lv5->item;
												{
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 362);
														if (StringCompare(JobGetType(ValidPtr(am2_vJob, 58, SchedJob*)), "retrieve") == 0) {
															AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 363);
															VehSetCurSchedJob(ValidPtr(am2_vvSelect, 81, vehicle*), am2_vJob);
															EntityChanged(0x01000000);
														}
													}
												}
											}
											ListRemoveAllAndFree(SchedJobList, am_localargs->ls5); /* End of for each */
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 366);
											am_localargs->ls6 = 0;
											ListCopy(SchedJobList, am_localargs->ls6, VehGetJobList(ValidPtr(am2_vvSelect, 81, vehicle*)));
											for (am_localargs->lv6 = (am_localargs->ls6) ? (am_localargs->ls6)->first : NULL; am_localargs->lv6; am_localargs->lv6 = am_localargs->lv6->next) {
												am2_vJob = am_localargs->lv6->item;
												{
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 368);
														if (StringCompare(JobGetType(ValidPtr(am2_vJob, 58, SchedJob*)), "move") == 0) {
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 370);
																{
																	char* pArg1 = rel_simlocname(JobGetDest(ValidPtr(am2_vJob, 58, SchedJob*)), am_model.$sys);

																	char* am_tmp;
																	am_tmp = bufsprintf("%s", pArg1);
																	SetString(&am2_vsTemp, am_tmp);
																	EntityChanged(0x01000000);
																}
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 371);
																if (ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_aiYellow == 1 && StringCompare(StrGetSubStr(am2_vsTemp, 7, 4), "Park") == 0) {
																	{
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 373);
																		ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_aiYellow = 0;
																		EntityChanged(0x00000040);
																	}
																	{
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 374);
																		am2_k = str2Integer(StrGetSubStr(am2_vsTemp, 12, 2));
																		EntityChanged(0x01000000);
																	}
																	{
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 375);
																		ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_alocPark = NULL;
																		EntityChanged(0x00000040);
																	}
																	{
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 376);
																		{
																			int result = deccount(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 1, this, pDispatch_arriving, Step 3, am_localargs);
																			if (result != Continue) return result;
Label3: ;	// Step 3
																		}
																	}
																}
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 379);
																veh_cancel(am2_vJob);
															}
														}
													}
												}
											}
											ListRemoveAllAndFree(SchedJobList, am_localargs->ls6); /* End of for each */
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 383);
											ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_atAssign = ASIclock;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 384);
											ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_atAssignInit = ASIclock;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 386);
											ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_aAssign = 1;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 387);
											VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(am2_vvSelect, 81, vehicle*))), 84, VehSeg*), 34);
											EntityChanged(0x01000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 388);
											ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_vhlRetDistance = VehGetTotDistA(ValidPtr(am2_vvSelect, 81, vehicle*));
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 390);
											if (ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_anTransfer == 1) {
												AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 391);
												am2_vrDistance = FromModelDistance(VehGetDistToLoc(ValidPtr(am2_vvSelect, 81, vehicle*), ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_alocFrom, 40, simloc*)), UNITMILLIMETERS);
												EntityChanged(0x01000000);
											}
											else {
												AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 393);
												am2_vrDistance = FromModelDistance(VehGetDistToLoc(ValidPtr(am2_vvSelect, 81, vehicle*), ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_alocStorage, 40, simloc*)), UNITMILLIMETERS);
												EntityChanged(0x01000000);
											}
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 395);
											ListRemoveFirstMatch(VehicleList, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", am2_i, 20)], am2_vvSelect);	// remove first match from list
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 396);
											ListRemoveFirstMatch(LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", am2_i, 20)], am2_vlSelect);	// remove first match from list
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 398);
											ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch = am2_vvSelect;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 400);
											ListAppendItem(LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", 4 + am2_i, 20)], am2_vlSelect);	// append item to end of list
										}
									}
								}
							}
						}
						{
							AMDebugger("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor, 404);
							am2_i += 1;
							EntityChanged(0x01000000);
						}
					}
				}
			}
		}
	}
LabelRet: ;
	ListRemoveAllAndFree(VehicleList, am_localargs->ls3);
	ListRemoveAllAndFree(LoadList, am_localargs->ls4);
	ListRemoveAllAndFree(SchedJobList, am_localargs->ls5);
	ListRemoveAllAndFree(SchedJobList, am_localargs->ls6);
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("vehicle.m", "Arriving procedure", "model.pDispatch", pDispatch_arriving, localactor);
	return retval;
} /* end of pDispatch_arriving */

static int32
pReAssign_arriving(load* this, int32 step, void* args)
{
	struct _localargs {
		AMLoadListItem* lv7; // 'for each' loop variable
		AMLoadList* ls7; // 'for each' list
		AMVehicleListItem* lv8; // 'for each' loop variable
		AMVehicleList* ls8; // 'for each' list
		AMSchedJobListItem* lv9; // 'for each' loop variable
		AMSchedJobList* ls9; // 'for each' list
		AMSchedJobListItem* lv10; // 'for each' loop variable
		AMSchedJobList* ls10; // 'for each' list
		AMSchedJobListItem* lv11; // 'for each' loop variable
		AMSchedJobList* ls11; // 'for each' list
		AMSchedJobListItem* lv12; // 'for each' loop variable
		AMSchedJobList* ls12; // 'for each' list
	} *am_localargs = (struct _localargs*)args;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("vehicle.m", "Arriving procedure", "model.pReAssign", localactor);
	AMDebuggerParams("model.pReAssign", pReAssign_arriving, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	am_localargs = (struct _localargs*)xcalloc(1, sizeof(struct _localargs));
	{
		{
			AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 411);
			while (1 == 1) {
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 413);
					if (waitfor(am2_vtSchedule, this, pReAssign_arriving, Step 2, am_localargs) == Delayed)
						return Delayed;
Label2: ; // Step 2
				}
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 415);
					am2_j = 1;
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 416);
					while (am2_j <= 4) {
						{
							AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 419);
							while (Size(List, VehicleList, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", am2_j, 20)]) > 0 && Size(List, LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", 4 + am2_j, 20)]) > 0) {
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 421);
									am2_vlSelect = NULL;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 422);
									am2_vvSelect = NULL;
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 423);
									am2_vtSelect = ToModelTime(0, UNITSECONDS);
									EntityChanged(0x01000000);
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 425);
									am_localargs->ls7 = 0;
									ListCopy(LoadList, am_localargs->ls7, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", 4 + am2_j, 20)]);
									for (am_localargs->lv7 = (am_localargs->ls7) ? (am_localargs->ls7)->first : NULL; am_localargs->lv7; am_localargs->lv7 = am_localargs->lv7->next) {
										am2_vlTemp = am_localargs->lv7->item;
										{
											{
												AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 427);
												am2_viCheck = 1;
												EntityChanged(0x01000000);
											}
											{
												AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 428);
												am_localargs->ls8 = 0;
												ListCopy(VehicleList, am_localargs->ls8, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", am2_j, 20)]);
												for (am_localargs->lv8 = (am_localargs->ls8) ? (am_localargs->ls8)->first : NULL; am_localargs->lv8; am_localargs->lv8 = am_localargs->lv8->next) {
													am2_vohtTemp = am_localargs->lv8->item;
													{
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 430);
															if (ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_anTransfer == 1) {
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 432);
																	am2_vrDistance = FromModelDistance(VehGetDistToLoc(ValidPtr(am2_vohtTemp, 81, vehicle*), ValidPtr(ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_alocFrom, 40, simloc*)), UNITMILLIMETERS);
																	EntityChanged(0x01000000);
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 433);
																	am2_vrDistance2 = FromModelDistance(VehGetDistToLoc(ValidPtr(ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_avDispatch, 81, vehicle*), ValidPtr(ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_alocFrom, 40, simloc*)), UNITMILLIMETERS);
																	EntityChanged(0x01000000);
																}
															}
															else {
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 437);
																	am2_vrDistance = FromModelDistance(VehGetDistToLoc(ValidPtr(am2_vohtTemp, 81, vehicle*), ValidPtr(ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_alocStorage, 40, simloc*)), UNITMILLIMETERS);
																	EntityChanged(0x01000000);
																}
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 438);
																	am2_vrDistance2 = FromModelDistance(VehGetDistToLoc(ValidPtr(ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_avDispatch, 81, vehicle*), ValidPtr(ValidPtr(am2_vlTemp, 32, load*)->attribute->am2_alocStorage, 40, simloc*)), UNITMILLIMETERS);
																	EntityChanged(0x01000000);
																}
															}
														}
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 441);
															if (am2_vrDistance < am2_vrDistance2) {
																{
																	AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 443);
																	if (am2_viCheck == 1) {
																		{
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 445);
																			am2_vlSelect = am2_vlTemp;
																			EntityChanged(0x01000000);
																		}
																		{
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 446);
																			am2_vvSelect = am2_vohtTemp;
																			EntityChanged(0x01000000);
																		}
																		{
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 447);
																			am2_vrDistanceTemp = am2_vrDistance;
																			EntityChanged(0x01000000);
																		}
																		{
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 448);
																			am2_viCheck += 1;
																			EntityChanged(0x01000000);
																		}
																	}
																	else {
																		{
																			AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 452);
																			if (am2_vrDistance < am2_vrDistanceTemp) {
																				{
																					AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 454);
																					am2_vlSelect = am2_vlTemp;
																					EntityChanged(0x01000000);
																				}
																				{
																					AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 455);
																					am2_vvSelect = am2_vohtTemp;
																					EntityChanged(0x01000000);
																				}
																				{
																					AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 456);
																					am2_vrDistanceTemp = am2_vrDistance;
																					EntityChanged(0x01000000);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
												ListRemoveAllAndFree(VehicleList, am_localargs->ls8); /* End of for each */
											}
										}
									}
									ListRemoveAllAndFree(LoadList, am_localargs->ls7); /* End of for each */
								}
								{
									AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 463);
									if (am2_vlSelect != NULL && ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch != am2_vvSelect) {
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 467);
											am2_k = 0;
											EntityChanged(0x01000000);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 468);
											while (am2_k < 17) {
												{
													AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 470);
													am2_k += 1;
													EntityChanged(0x01000000);
												}
												{
													AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 471);
													if (CntGetCurConts(ValidPtr(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 10, counter*)) < am2_viParkCapa[ValidIndex("am_model.am_viParkCapa", am2_k, 30)]) {
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 473);
															{
																int result = inccount(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 1, this, pReAssign_arriving, Step 3, am_localargs);
																if (result != Continue) return result;
Label3: ;	// Step 3
															}
														}
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 474);
															ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)->load.attribute->am2_aiYellow = 1;
															EntityChanged(0x00000040);
														}
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 475);
															veh_dispatch(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, ListIndexItem(LocationList, am2_vlocParkList, am2_k), 0, NULL, 0);
														}
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 476);
															ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)->load.attribute->am2_alocPark = ListIndexItem(LocationList, am2_vlocParkList, am2_k);
															EntityChanged(0x00000040);
														}
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 477);
															VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*))), 84, VehSeg*), 36);
															EntityChanged(0x01000040);
														}
														{
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 478);
															break;
														}
													}
												}
											}
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 483);
											am_localargs->ls9 = 0;
											ListCopy(SchedJobList, am_localargs->ls9, VehGetJobList(ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)));
											for (am_localargs->lv9 = (am_localargs->ls9) ? (am_localargs->ls9)->first : NULL; am_localargs->lv9; am_localargs->lv9 = am_localargs->lv9->next) {
												am2_vJob = am_localargs->lv9->item;
												{
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 485);
														if (StringCompare(JobGetType(ValidPtr(am2_vJob, 58, SchedJob*)), "move") == 0) {
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 486);
															VehSetCurSchedJob(ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*), am2_vJob);
															EntityChanged(0x01000000);
														}
													}
												}
											}
											ListRemoveAllAndFree(SchedJobList, am_localargs->ls9); /* End of for each */
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 490);
											am_localargs->ls10 = 0;
											ListCopy(SchedJobList, am_localargs->ls10, VehGetJobList(ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)));
											for (am_localargs->lv10 = (am_localargs->ls10) ? (am_localargs->ls10)->first : NULL; am_localargs->lv10; am_localargs->lv10 = am_localargs->lv10->next) {
												am2_vJob = am_localargs->lv10->item;
												{
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 492);
														if (StringCompare(JobGetType(ValidPtr(am2_vJob, 58, SchedJob*)), "retrieve") == 0) {
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 493);
															veh_cancel(am2_vJob);
														}
													}
												}
											}
											ListRemoveAllAndFree(SchedJobList, am_localargs->ls10); /* End of for each */
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 497);
											ListAppendItem(VehicleList, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", am2_j, 20)], ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch);	// append item to end of list
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 499);
											if (ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)->load.attribute->am2_anVehicleType == 1 && ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)->load.attribute->am2_aiYellow == 0) {
												AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 500);
												VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*))), 84, VehSeg*), 21);
												EntityChanged(0x01000040);
											}
											else {
												AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 501);
												if (ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)->load.attribute->am2_anVehicleType == 2 && ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)->load.attribute->am2_aiYellow == 0) {
													AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 502);
													VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*))), 84, VehSeg*), 12);
													EntityChanged(0x01000040);
												}
											}
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 504);
											ValidPtr(ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch, 81, vehicle*)->load.attribute->am2_aAssign = 0;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 506);
											ClaimLoad(am2_vvSelect, am2_vlSelect, FALSE);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 508);
											am_localargs->ls11 = 0;
											ListCopy(SchedJobList, am_localargs->ls11, VehGetJobList(ValidPtr(am2_vvSelect, 81, vehicle*)));
											for (am_localargs->lv11 = (am_localargs->ls11) ? (am_localargs->ls11)->first : NULL; am_localargs->lv11; am_localargs->lv11 = am_localargs->lv11->next) {
												am2_vJob = am_localargs->lv11->item;
												{
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 510);
														if (StringCompare(JobGetType(ValidPtr(am2_vJob, 58, SchedJob*)), "retrieve") == 0) {
															AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 511);
															VehSetCurSchedJob(ValidPtr(am2_vvSelect, 81, vehicle*), am2_vJob);
															EntityChanged(0x01000000);
														}
													}
												}
											}
											ListRemoveAllAndFree(SchedJobList, am_localargs->ls11); /* End of for each */
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 514);
											am_localargs->ls12 = 0;
											ListCopy(SchedJobList, am_localargs->ls12, VehGetJobList(ValidPtr(am2_vvSelect, 81, vehicle*)));
											for (am_localargs->lv12 = (am_localargs->ls12) ? (am_localargs->ls12)->first : NULL; am_localargs->lv12; am_localargs->lv12 = am_localargs->lv12->next) {
												am2_vJob = am_localargs->lv12->item;
												{
													{
														AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 516);
														if (StringCompare(JobGetType(ValidPtr(am2_vJob, 58, SchedJob*)), "move") == 0) {
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 518);
																{
																	char* pArg1 = rel_simlocname(JobGetDest(ValidPtr(am2_vJob, 58, SchedJob*)), am_model.$sys);

																	char* am_tmp;
																	am_tmp = bufsprintf("%s", pArg1);
																	SetString(&am2_vsTemp, am_tmp);
																	EntityChanged(0x01000000);
																}
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 519);
																if (ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_aiYellow == 1 && StringCompare(StrGetSubStr(am2_vsTemp, 7, 4), "Park") == 0) {
																	{
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 521);
																		ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_aiYellow = 0;
																		EntityChanged(0x00000040);
																	}
																	{
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 522);
																		am2_k = str2Integer(StrGetSubStr(am2_vsTemp, 12, 2));
																		EntityChanged(0x01000000);
																	}
																	{
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 523);
																		ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_alocPark = NULL;
																		EntityChanged(0x00000040);
																	}
																	{
																		AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 524);
																		{
																			int result = deccount(&(am2_cPark[ValidIndex("am_model.am_cPark", am2_k, 30)]), 1, this, pReAssign_arriving, Step 4, am_localargs);
																			if (result != Continue) return result;
Label4: ;	// Step 4
																		}
																	}
																}
															}
															{
																AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 527);
																veh_cancel(am2_vJob);
															}
														}
													}
												}
											}
											ListRemoveAllAndFree(SchedJobList, am_localargs->ls12); /* End of for each */
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 531);
											ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_atAssign = ASIclock;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 533);
											ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_aAssign = 1;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 534);
											VsegSetColor(ValidPtr(ListFirstItem(VehSegList, VehGetVsegList(ValidPtr(am2_vvSelect, 81, vehicle*))), 84, VehSeg*), 34);
											EntityChanged(0x01000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 535);
											ValidPtr(am2_vvSelect, 81, vehicle*)->load.attribute->am2_vhlRetDistance = VehGetTotDistA(ValidPtr(am2_vvSelect, 81, vehicle*));
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 538);
											ListRemoveFirstMatch(VehicleList, am2_vlistOHT[ValidIndex("am_model.am_vlistOHT", am2_j, 20)], am2_vvSelect);	// remove first match from list
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 539);
											ValidPtr(am2_vlSelect, 32, load*)->attribute->am2_avDispatch = am2_vvSelect;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 540);
											am2_vrDistanceTemp = 0;
											EntityChanged(0x01000000);
										}
									}
									else {
										AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 543);
										break;
									}
								}
							}
						}
						{
							AMDebugger("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor, 546);
							am2_j += 1;
							EntityChanged(0x01000000);
						}
					}
				}
			}
		}
	}
LabelRet: ;
	ListRemoveAllAndFree(LoadList, am_localargs->ls7);
	ListRemoveAllAndFree(VehicleList, am_localargs->ls8);
	ListRemoveAllAndFree(SchedJobList, am_localargs->ls9);
	ListRemoveAllAndFree(SchedJobList, am_localargs->ls10);
	ListRemoveAllAndFree(SchedJobList, am_localargs->ls11);
	ListRemoveAllAndFree(SchedJobList, am_localargs->ls12);
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("vehicle.m", "Arriving procedure", "model.pReAssign", pReAssign_arriving, localactor);
	return retval;
} /* end of pReAssign_arriving */

static int32
pm_work(vehicle* am_theVehicle, simloc* am_loadLoc, load* am_theLoad)
{
	load* localactor = (load*)am_theVehicle;
	AMDebuggerBeginRoutine("vehicle.m", "Work OK function", "model.pm", localactor);
	{
		char*	names[3];
		void*	ptrs[3];
		char*	(*valstrfuncs[3])(void*);
		
		names[0] = "theVehicle";
		ptrs[0] = &am_theVehicle;
		valstrfuncs[0] = VehiclePtr_valstrfunc;
		names[1] = "loadLoc";
		ptrs[1] = &am_loadLoc;
		valstrfuncs[1] = Location_valstrfunc;
		names[2] = "theLoad";
		ptrs[2] = &am_theLoad;
		valstrfuncs[2] = LoadPtr_valstrfunc;
		AMDebuggerParams("model.pm", pm_work, localactor, 3, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("vehicle.m", "Work OK function", "model.pm", pm_work, localactor, 552);
			AMDebuggerEndRoutine("vehicle.m", "Work OK function", "model.pm", pm_work, localactor);
			return 0;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("vehicle.m", "Work OK function", "model.pm", pm_work, localactor);
} /* end of pm_work */

static int32
pm_park(vehicle* am_theVehicle, simloc* am_parkLoc)
{
	load* localactor = (load*)am_theVehicle;
	AMDebuggerBeginRoutine("vehicle.m", "Park OK function", "model.pm", localactor);
	{
		char*	names[2];
		void*	ptrs[2];
		char*	(*valstrfuncs[2])(void*);
		
		names[0] = "theVehicle";
		ptrs[0] = &am_theVehicle;
		valstrfuncs[0] = VehiclePtr_valstrfunc;
		names[1] = "parkLoc";
		ptrs[1] = &am_parkLoc;
		valstrfuncs[1] = Location_valstrfunc;
		AMDebuggerParams("model.pm", pm_park, localactor, 2, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("vehicle.m", "Park OK function", "model.pm", pm_park, localactor, 556);
			AMDebuggerEndRoutine("vehicle.m", "Park OK function", "model.pm", pm_park, localactor);
			return 0;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("vehicle.m", "Park OK function", "model.pm", pm_park, localactor);
} /* end of pm_park */



/* init function for vehicle.m */
void
model_vehicle_init(struct model_struct* data)
{
	((MovementSystem*)data->am_pm.$sys)->srcblock.initprc = pm_vehinit;
	data->am_pm.am_steer->src.passprc = pm_steer_pass;
	data->am_pm.am_Avoid->src.passprc = pm_Avoid_pass;
	data->am_pm.am_dummy->src.passprc = pm_dummy_pass;
	((MovementSystem*)data->am_pm.$sys)->srcblock.startprc = pm_start;
	data->am_pPark_Check->aprc = pPark_Check_arriving;
	((MovementSystem*)data->am_pm.$sys)->srcblock.taskprc = pm_task;
	((MovementSystem*)data->am_pm.$sys)->srcblock.pickupprc = pm_pickup;
	((MovementSystem*)data->am_pm.$sys)->srcblock.setdownprc = pm_setdown;
	((MovementSystem*)data->am_pm.$sys)->srcblock.resumemoveprc = pm_resumemove;
	data->am_pDispatch->aprc = pDispatch_arriving;
	data->am_pReAssign->aprc = pReAssign_arriving;
	((MovementSystem*)data->am_pm.$sys)->srcblock.workprc = pm_work;
	((MovementSystem*)data->am_pm.$sys)->srcblock.parkprc = pm_park;
}

