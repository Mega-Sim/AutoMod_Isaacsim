// init.c
// AutoMod 12.6.1 Generated File
// Build: 12.6.1.12
// Model name:	model
// Model path:	D:\Project\1_SDI\SDIHU Factory 2\2. Model\30. model 231030~\231101 model 9~12_basic\model.dir\
// Generated:	Wed Feb 14 10:18:41 2024
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

#undef fsetValuable_FilePtr
static int32 fsetValuable_FilePtr(void);
#undef freadOHTSpec
static int32 freadOHTSpec(void);
#undef freadControl
static int32 freadControl(void);

static int32
model_initialize()
{
	{
		{
			am2_vUTBtoEQLog = OpenFilePtr(am_model.$sys, "UTBtoEQ.txt", "w");
		}
		{
			am2_vSTKtoUTBLog = OpenFilePtr(am_model.$sys, "STKtoUTB.txt", "w");
		}
		{
			am2_vDelayLog = OpenFilePtr(am_model.$sys, "Delay.txt", "w");
		}
		{
			am2_vrRatio = 1.0000000000000000;
			EntityChanged(0x01000000);
		}
		{
			am2_vrUTBRatio = 100.00000000000000;
			EntityChanged(0x01000000);
		}
		{
			am2_vRuntime = 13;
			EntityChanged(0x01000000);
		}
		{
			am2_vrSpec = 0.84999999999999998;
			EntityChanged(0x01000000);
		}
		{
			if (am2_viParkCapa[1] == 0) {
				{
					char* pArg1 = "No Park";

					updatelabel(am2_lParkCount, "%s", pArg1);
				}
			}
		}
		{
			am2_vnOHT[1] = 80;
			EntityChanged(0x01000000);
		}
		{
			am2_vnOHT[2] = 0;
			EntityChanged(0x01000000);
		}
		{
			am2_vnOHT[3] = 0;
			EntityChanged(0x01000000);
		}
		{
			am2_vrConv = 6;
			EntityChanged(0x01000000);
		}
		{
			am2_vrLift = 6;
			EntityChanged(0x01000000);
		}
		{
			am2_viAbnormalUTB = 3;
			EntityChanged(0x01000000);
		}
		{
			am2_vnUTB = 64;
			EntityChanged(0x01000000);
		}
		{
			am2_viFrontUTB = 5;
			EntityChanged(0x01000000);
		}
		{
			am2_viLineUTB = 8;
			EntityChanged(0x01000000);
		}
		{
			am2_vrStorage = 0;
			EntityChanged(0x01000000);
		}
		{
			am2_vnCapa = am2_vrRatio * 100;
			EntityChanged(0x01000000);
		}
		{
			{
				char* pArg1 = "Capa:";
				int32 pArg2 = am2_vnCapa;
				char* pArg3 = "%";

				updatelabel(am2_lblvnCapa, "%s%d%s", pArg1, pArg2, pArg3);
			}
		}
		{
			{
				char* pArg1 = "EVL-C: ";
				int32 pArg2 = am2_vnOHT[3];
				char* pArg3 = " ea";

				updatelabel(am2_lblOHT, "%s%d%s", pArg1, pArg2, pArg3);
			}
		}
		{
			fsetValuable_FilePtr();
		}
		{
			freadOHTSpec();
		}
		{
			freadControl();
		}
		{
			return 1;
		}
	}
LabelRet: ;
} /* end of model_initialize */

static int32
fsetValuable_FilePtr()
{
	load* localactor = NULL;
	AMDebuggerBeginRoutine("init.m", "Function", "model.fsetValuable_FilePtr", localactor);
	{
		char*	names[1];
		void*	ptrs[1];
		char*	(*valstrfuncs[1])(void*);
		
		AMDebuggerParams("model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 0, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 48);
			am2_vfpInFromto = OpenFilePtr(am_model.$sys, "arc/data/EQ_Loc.txt", "r");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 49);
			am2_vfpInControl[2] = OpenFilePtr(am_model.$sys, "arc/data/avoid.txt", "r");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 50);
			am2_vfputbtact = OpenFilePtr(am_model.$sys, "arc/data/utb.txt", "r");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 51);
			am2_vfpeqtact = OpenFilePtr(am_model.$sys, "arc/data/eq.txt", "r");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 52);
			am2_vfpstktact = OpenFilePtr(am_model.$sys, "arc/data/stk.txt", "r");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 53);
			am2_vfpconvtact = OpenFilePtr(am_model.$sys, "arc/data/conv.txt", "r");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 55);
			am2_viGap = 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 56);
			while (FileGetEof(ValidPtr(am2_vfputbtact, 24, iofile*)) == 0) {
								{
					if (isFileValid(am2_vfputbtact, 1)) {
						char* delimiter = FileGetDelimiter(am2_vfputbtact);

						if (delimiter && delimiter[0] != '\0') {
							int rflag;
							static ReadRef st1;

							setupReadRef(&st1, 0, am_model.am_vrUTBGap$var, &am2_vrUTBGap[ValidIndex("am_model.am_vrUTBGap", am2_viGap, 343)], NULL, -1, FALSE);
							AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 58);
							rflag = readFile(am2_vfputbtact->fp, delimiter, &st1, NULL);
							SetFileAtEof(am2_vfputbtact, EOF, rflag);
						} else {
							int rflag;
							double am_tmpr1;

							AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 58);
							rflag = fscanf(am2_vfputbtact->fp, "%lf ", &am_tmpr1);
							if (rflag >= 1) {
								am2_vrUTBGap[ValidIndex("am_model.am_vrUTBGap", am2_viGap, 343)] = am_tmpr1;
								EntityChanged(0x01000000);
							}
							SetFileAtEof(am2_vfputbtact, 1, rflag);
							CheckReadError(am2_vfputbtact, 1, rflag);
						}
					}
				}
				{
					AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 59);
					am2_viGap += 1;
					EntityChanged(0x01000000);
				}
			}
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 61);
			am2_viGap = 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 62);
			while (FileGetEof(ValidPtr(am2_vfpeqtact, 24, iofile*)) == 0) {
								{
					if (isFileValid(am2_vfpeqtact, 1)) {
						char* delimiter = FileGetDelimiter(am2_vfpeqtact);

						if (delimiter && delimiter[0] != '\0') {
							int rflag;
							static ReadRef st1;

							setupReadRef(&st1, 0, am_model.am_vrEQGap$var, &am2_vrEQGap[ValidIndex("am_model.am_vrEQGap", am2_viGap, 336)], NULL, -1, FALSE);
							AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 64);
							rflag = readFile(am2_vfpeqtact->fp, delimiter, &st1, NULL);
							SetFileAtEof(am2_vfpeqtact, EOF, rflag);
						} else {
							int rflag;
							double am_tmpr1;

							AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 64);
							rflag = fscanf(am2_vfpeqtact->fp, "%lf ", &am_tmpr1);
							if (rflag >= 1) {
								am2_vrEQGap[ValidIndex("am_model.am_vrEQGap", am2_viGap, 336)] = am_tmpr1;
								EntityChanged(0x01000000);
							}
							SetFileAtEof(am2_vfpeqtact, 1, rflag);
							CheckReadError(am2_vfpeqtact, 1, rflag);
						}
					}
				}
				{
					AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 65);
					am2_viGap += 1;
					EntityChanged(0x01000000);
				}
			}
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 67);
			am2_viGap = 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 68);
			while (FileGetEof(ValidPtr(am2_vfpstktact, 24, iofile*)) == 0) {
								{
					if (isFileValid(am2_vfpstktact, 1)) {
						char* delimiter = FileGetDelimiter(am2_vfpstktact);

						if (delimiter && delimiter[0] != '\0') {
							int rflag;
							static ReadRef st1;

							setupReadRef(&st1, 0, am_model.am_vrSTKGap$var, &am2_vrSTKGap[ValidIndex("am_model.am_vrSTKGap", am2_viGap, 176)], NULL, -1, FALSE);
							AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 70);
							rflag = readFile(am2_vfpstktact->fp, delimiter, &st1, NULL);
							SetFileAtEof(am2_vfpstktact, EOF, rflag);
						} else {
							int rflag;
							double am_tmpr1;

							AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 70);
							rflag = fscanf(am2_vfpstktact->fp, "%lf ", &am_tmpr1);
							if (rflag >= 1) {
								am2_vrSTKGap[ValidIndex("am_model.am_vrSTKGap", am2_viGap, 176)] = am_tmpr1;
								EntityChanged(0x01000000);
							}
							SetFileAtEof(am2_vfpstktact, 1, rflag);
							CheckReadError(am2_vfpstktact, 1, rflag);
						}
					}
				}
				{
					AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 71);
					am2_viGap += 1;
					EntityChanged(0x01000000);
				}
			}
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 73);
			am2_viGap = 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 74);
			while (FileGetEof(ValidPtr(am2_vfpconvtact, 24, iofile*)) == 0) {
								{
					if (isFileValid(am2_vfpconvtact, 1)) {
						char* delimiter = FileGetDelimiter(am2_vfpconvtact);

						if (delimiter && delimiter[0] != '\0') {
							int rflag;
							static ReadRef st1;

							setupReadRef(&st1, 0, am_model.am_vrCONVGap$var, &am2_vrCONVGap[ValidIndex("am_model.am_vrCONVGap", am2_viGap, 168)], NULL, -1, FALSE);
							AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 76);
							rflag = readFile(am2_vfpconvtact->fp, delimiter, &st1, NULL);
							SetFileAtEof(am2_vfpconvtact, EOF, rflag);
						} else {
							int rflag;
							double am_tmpr1;

							AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 76);
							rflag = fscanf(am2_vfpconvtact->fp, "%lf ", &am_tmpr1);
							if (rflag >= 1) {
								am2_vrCONVGap[ValidIndex("am_model.am_vrCONVGap", am2_viGap, 168)] = am_tmpr1;
								EntityChanged(0x01000000);
							}
							SetFileAtEof(am2_vfpconvtact, 1, rflag);
							CheckReadError(am2_vfpconvtact, 1, rflag);
						}
					}
				}
				{
					AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 77);
					am2_viGap += 1;
					EntityChanged(0x01000000);
				}
			}
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 80);
			am2_vfpOutResult[1] = OpenFilePtr(am_model.$sys, "arc/result/1.output_EVLC.txt", "w");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 81);
			am2_vfpOutResult[6] = OpenFilePtr(am_model.$sys, "arc/result/1.output_EVLC2.txt", "w");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 85);
			am2_vfUTBtoEQ[1] = OpenFilePtr(am_model.$sys, "arc/result/2.output_UTBtoEQ.txt", "w");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 86);
			am2_vfUTBtoEQ[2] = OpenFilePtr(am_model.$sys, "arc/result/2.output_STKtoUTB.txt", "w");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 87);
			am2_vfpOutResult[2] = OpenFilePtr(am_model.$sys, "arc/result/3.EQcomplete.txt", "w");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 88);
			am2_vfpOutResult[3] = OpenFilePtr(am_model.$sys, "arc/result/4.EQcompleteType.txt", "w");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 89);
			am2_vfpOutResult[4] = OpenFilePtr(am_model.$sys, "arc/result/UTBtoEQraw.txt", "w");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 90);
			am2_vfpOutResult[5] = OpenFilePtr(am_model.$sys, "arc/result/6.B_Traffic.txt", "w");
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 92);
			{
				if (isFileValid(am2_vfpOutResult[4], 0)) {
					char* pArg1 = "A\tB\tC\tD\tE";

					fprintf((am2_vfpOutResult[4])->fp, "%s\n", pArg1);
					fflush((am2_vfpOutResult[4])->fp);
				}
			}
		}
		{
			AMDebugger("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor, 94);
			AMDebuggerEndRoutine("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("init.m", "Function", "model.fsetValuable_FilePtr", fsetValuable_FilePtr, localactor);
} /* end of fsetValuable_FilePtr */

static int
dispatch_fsetValuable_FilePtr(int nParams, int* argTypes, void** argVals, void** retVal)
{
	static char buf[512];
	int retType;
	static int32 ret;

	if (nParams != 0) {
		message("The function fsetValuable_FilePtr was called from the ActiveX interface with %d parameters, while 0 are required.", nParams);
		return 0;
	}
	ret = fsetValuable_FilePtr();
	*retVal = &ret;
	return 1;
}

static int32
freadOHTSpec()
{
	load* localactor = NULL;
	AMDebuggerBeginRoutine("init.m", "Function", "model.freadOHTSpec", localactor);
	{
		char*	names[1];
		void*	ptrs[1];
		char*	(*valstrfuncs[1])(void*);
		
		AMDebuggerParams("model.freadOHTSpec", freadOHTSpec, localactor, 0, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 111);
			am2_vrNormalVelocity[1] = 2.0000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 112);
			am2_vrCurveVelocity[1] = 0.50000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 113);
			am2_vrAcceleration[1] = 1.0000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 114);
			am2_vrDeceleration[1] = 1.5000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 115);
			am2_vtLoading[1] = ToModelTime(20, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 117);
			am2_vrNormalVelocity[2] = 2.0000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 118);
			am2_vrCurveVelocity[2] = 0.50000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 119);
			am2_vrAcceleration[2] = 1.0000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 120);
			am2_vrDeceleration[2] = 1.5000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 121);
			am2_vtLoading[2] = ToModelTime(20, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 123);
			am2_vrNormalVelocity[3] = 2.0000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 124);
			am2_vrCurveVelocity[3] = 0.50000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 125);
			am2_vrAcceleration[3] = 1 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 126);
			am2_vrDeceleration[3] = 1.5000000000000000 * am2_vrSpec;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 127);
			am2_vtLoading[3] = ToModelTime(20, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 129);
			am2_vrBrakeDistance = 4.5000000000000000;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 130);
			am2_vrStopDistance = 0.89500000000000002;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 131);
			am2_vtResume = ToModelTime(0.50000000000000000, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor, 133);
			AMDebuggerEndRoutine("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("init.m", "Function", "model.freadOHTSpec", freadOHTSpec, localactor);
} /* end of freadOHTSpec */

static int
dispatch_freadOHTSpec(int nParams, int* argTypes, void** argVals, void** retVal)
{
	static char buf[512];
	int retType;
	static int32 ret;

	if (nParams != 0) {
		message("The function freadOHTSpec was called from the ActiveX interface with %d parameters, while 0 are required.", nParams);
		return 0;
	}
	ret = freadOHTSpec();
	*retVal = &ret;
	return 1;
}

static int32
freadControl()
{
	load* localactor = NULL;
	AMDebuggerBeginRoutine("init.m", "Function", "model.freadControl", localactor);
	{
		char*	names[1];
		void*	ptrs[1];
		char*	(*valstrfuncs[1])(void*);
		
		AMDebuggerParams("model.freadControl", freadControl, localactor, 0, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 137);
			am2_vtRun = ToModelTime(1, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 138);
			am2_vtSchedule = ToModelTime(1, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 139);
			am2_vtPriorityCost = ToModelTime(100, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 140);
			am2_vnTimeWeight = 1.0000000000000000;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 141);
			am2_vtTimeLimit = ToModelTime(300, UNITSECONDS);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 142);
			am2_vnPark = 36;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 144);
			am2_i = 2;
			EntityChanged(0x01000000);
		}
				{
			if (isFileValid(am2_vfpInControl[ValidIndex("am_model.am_vfpInControl", am2_i, 4)], 1)) {
				int rflag;
				static ReadRef st1;

				setupReadRef(&st1, 0, am_model.am_vsStream2$var, &am2_vsStream2, NULL, -1, FALSE);
				AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 145);
				rflag = readFile(am2_vfpInControl[ValidIndex("am_model.am_vfpInControl", am2_i, 4)]->fp, "\n", &st1, NULL);
				SetFileAtEof(am2_vfpInControl[ValidIndex("am_model.am_vfpInControl", am2_i, 4)], EOF, rflag);
			}
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 146);
			while (FileGetEof(ValidPtr(am2_vfpInControl[ValidIndex("am_model.am_vfpInControl", am2_i, 4)], 24, iofile*)) == 0) {
								{
					if (isFileValid(am2_vfpInControl[ValidIndex("am_model.am_vfpInControl", am2_i, 4)], 1)) {
						int rflag;
						static ReadRef st1;

						setupReadRef(&st1, 0, am_model.am_vsStream2$var, &am2_vsStream2, NULL, -1, FALSE);
						AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 148);
						rflag = readFile(am2_vfpInControl[ValidIndex("am_model.am_vfpInControl", am2_i, 4)]->fp, "\n", &st1, NULL);
						SetFileAtEof(am2_vfpInControl[ValidIndex("am_model.am_vfpInControl", am2_i, 4)], EOF, rflag);
					}
				}
								{
					int rflag;
					static ReadRef st1;

					setupReadRef(&st1, 0, am_model.am_vlocTemp$var, &am2_vlocTemp, str2Location, -1, FALSE);
					AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 149);
					rflag = readString(am2_vsStream2, "\n", &st1, NULL);
				}
				{
					AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 150);
					if (LocCompare(am2_vlocTemp, NULL) != 0) {
						AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 151);
						ListAppendItem(LocationList, am2_vlocAvoidList, am2_vlocTemp);	// append item to end of list
					}
				}
			}
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 154);
			am2_i = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 155);
			while (am2_i < 17) {
				{
					AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 157);
					am2_i += 1;
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 158);
					{
						char* pArg1 = "pm.cp_Park_";
						int32 pArg2 = am2_i;

						char* am_tmp;
						am_tmp = bufsprintf("%s%d", pArg1, pArg2);
						SetString(&am2_vsTemp, am_tmp);
						EntityChanged(0x01000000);
					}
				}
				{
					AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 159);
					am2_vlocTemp = str2Location(am2_vsTemp);
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 160);
					ListAppendItem(LocationList, am2_vlocParkList, am2_vlocTemp);	// append item to end of list
				}
			}
		}
		{
			AMDebugger("init.m", "Function", "model.freadControl", freadControl, localactor, 163);
			AMDebuggerEndRoutine("init.m", "Function", "model.freadControl", freadControl, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("init.m", "Function", "model.freadControl", freadControl, localactor);
} /* end of freadControl */

static int
dispatch_freadControl(int nParams, int* argTypes, void** argVals, void** retVal)
{
	static char buf[512];
	int retType;
	static int32 ret;

	if (nParams != 0) {
		message("The function freadControl was called from the ActiveX interface with %d parameters, while 0 are required.", nParams);
		return 0;
	}
	ret = freadControl();
	*retVal = &ret;
	return 1;
}

static int32
model_snap()
{
	load* localactor = NULL;
	AMDebuggerBeginRoutine("init.m", "Model snap function", "model", localactor);
	{
		char*	names[1];
		void*	ptrs[1];
		char*	(*valstrfuncs[1])(void*);
		
		AMDebuggerParams("model", model_snap, localactor, 0, names, ptrs, valstrfuncs);
	}
	{
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 168);
			{
				if (isFileValid(am2_vfpOutResult[5], 0)) {
					double pArg1 = FromModelTime(BlkGetAvTimeR(ValidPtr(&(am2_B_TrafficCheck[1]), 7, block*)), UNITSECONDS);
					char* pArg2 = " ";
					char* pArg3 = "\t";
					char* pArg4 = " ";
					double pArg5 = BlkGetAvContsR(ValidPtr(&(am2_B_TrafficCheck[1]), 7, block*));
					char* pArg6 = " ";
					char* pArg7 = "\t";
					char* pArg8 = " ";
					int32 pArg9 = BlkGetMaxContsR(ValidPtr(&(am2_B_TrafficCheck[1]), 7, block*));

					fprintf((am2_vfpOutResult[5])->fp, "%lf%s%s%s%lf%s%s%s%d\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9);
					fflush((am2_vfpOutResult[5])->fp);
				}
			}
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 170);
			{
				char* pArg1 = "Complete(Type): ";
				char* pArg2 = " ";
				int32 pArg3 = am2_vnCompleteType[1];
				char* pArg4 = " ";
				char* pArg5 = "\t";
				char* pArg6 = " ";
				int32 pArg7 = am2_vnCompleteType[2];
				char* pArg8 = " ";
				char* pArg9 = "\t";
				char* pArg10 = " ";
				int32 pArg11 = am2_vnCompleteType[3];

				message("%s%s%d%s%s%s%d%s%s%s%d", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11);
			}
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 171);
			{
				if (isFileValid(am2_vfpOutResult[3], 0)) {
					int32 pArg1 = am2_viEQcomplete[1];
					char* pArg2 = " ";
					char* pArg3 = "\t";
					char* pArg4 = " ";
					int32 pArg5 = am2_viEQcomplete[2];
					char* pArg6 = " ";
					char* pArg7 = "\t";
					char* pArg8 = " ";
					int32 pArg9 = am2_viEQcomplete[3];
					char* pArg10 = " ";
					char* pArg11 = "\t";
					char* pArg12 = " ";
					int32 pArg13 = am2_viEQcomplete[4];

					fprintf((am2_vfpOutResult[3])->fp, "%d%s%s%s%d%s%s%s%d%s%s%s%d\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13);
					fflush((am2_vfpOutResult[3])->fp);
				}
			}
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 172);
			am2_vnCompleteType[1] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 173);
			am2_vnCompleteType[2] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 174);
			am2_vnCompleteType[3] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 176);
			{
				int32 pArg1 = am2_viEQcomplete[1];
				char* pArg2 = " ";
				char* pArg3 = "\t";
				char* pArg4 = " ";
				int32 pArg5 = am2_viEQcomplete[2];
				char* pArg6 = " ";
				char* pArg7 = "\t";
				char* pArg8 = " ";
				int32 pArg9 = am2_viEQcomplete[3];
				char* pArg10 = " ";
				char* pArg11 = "\t";
				char* pArg12 = " ";
				int32 pArg13 = am2_viEQcomplete[4];

				message("%d%s%s%s%d%s%s%s%d%s%s%s%d", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13);
			}
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 177);
			{
				if (isFileValid(am2_vfpOutResult[2], 0)) {
					int32 pArg1 = am2_viEQcomplete[1];
					char* pArg2 = " ";
					char* pArg3 = "\t";
					char* pArg4 = " ";
					int32 pArg5 = am2_viEQcomplete[2];
					char* pArg6 = " ";
					char* pArg7 = "\t";
					char* pArg8 = " ";
					int32 pArg9 = am2_viEQcomplete[3];
					char* pArg10 = " ";
					char* pArg11 = "\t";
					char* pArg12 = " ";
					int32 pArg13 = am2_viEQcomplete[4];

					fprintf((am2_vfpOutResult[2])->fp, "%d%s%s%s%d%s%s%s%d%s%s%s%d\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13);
					fflush((am2_vfpOutResult[2])->fp);
				}
			}
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 178);
			am2_viEQcomplete[1] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 179);
			am2_viEQcomplete[2] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 180);
			am2_viEQcomplete[3] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 181);
			am2_viEQcomplete[4] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 184);
			am2_viComplete2[1] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 185);
			am2_viComplete2[2] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 186);
			am2_viComplete2[3] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 187);
			am2_viComplete2[4] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 188);
			am2_viComplete2[5] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 189);
			am2_viComplete2[6] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 190);
			am2_viComplete2[7] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 191);
			am2_viComplete2[8] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 197);
			{
				if (isFileValid(am2_vfpOutResult[1], 0)) {
					double pArg1 = TblGetAvContsR(ValidPtr(&(am2_tDelDistance[1]), 71, table*));
					char* pArg2 = " ";
					char* pArg3 = "\t";
					char* pArg4 = " ";
					double pArg5 = TblGetAvContsR(ValidPtr(&(am2_tRetDistance[1]), 71, table*));
					char* pArg6 = " ";
					char* pArg7 = "\t";
					char* pArg8 = " ";
					double pArg9 = TblGetAvContsR(ValidPtr(&(am2_tTotDistance[1]), 71, table*));
					char* pArg10 = " ";
					char* pArg11 = "\t";
					char* pArg12 = " ";
					double pArg13 = TblGetAvContsR(ValidPtr(&(am2_tAssignInit[1]), 71, table*));
					char* pArg14 = " ";
					char* pArg15 = "\t";
					char* pArg16 = " ";
					double pArg17 = TblGetAvContsR(ValidPtr(&(am2_tAssign[1]), 71, table*));
					char* pArg18 = " ";
					char* pArg19 = "\t";
					char* pArg20 = " ";
					double pArg21 = TblGetAvContsR(ValidPtr(&(am2_tUnloadMove[1]), 71, table*));
					char* pArg22 = " ";
					char* pArg23 = "\t";
					char* pArg24 = " ";
					double pArg25 = TblGetAvContsR(ValidPtr(&(am2_tLoadMove[1]), 71, table*));
					char* pArg26 = " ";
					char* pArg27 = "\t";
					char* pArg28 = " ";
					double pArg29 = ToModelTime(am2_vnRequest[1] / am2_vtRun, UNITSECONDS);
					char* pArg30 = " ";
					char* pArg31 = "\t";
					char* pArg32 = " ";
					double pArg33 = ToModelTime(am2_vnComplete[1] / am2_vtRun, UNITSECONDS);
					char* pArg34 = " ";
					char* pArg35 = "\t";
					char* pArg36 = " ";
					double pArg37 = ToModelTime(am2_vnDelay[1] / am2_vtRun, UNITSECONDS);

					fprintf((am2_vfpOutResult[1])->fp, "%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13, pArg14, pArg15, pArg16, pArg17, pArg18, pArg19, pArg20, pArg21, pArg22, pArg23, pArg24, pArg25, pArg26, pArg27, pArg28, pArg29, pArg30, pArg31, pArg32, pArg33, pArg34, pArg35, pArg36, pArg37);
					fflush((am2_vfpOutResult[1])->fp);
				}
			}
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 202);
			{
				double pArg1 = TblGetAvContsR(ValidPtr(&(am2_tDelDistance[1]), 71, table*));
				char* pArg2 = " ";
				char* pArg3 = "\t";
				char* pArg4 = " ";
				double pArg5 = TblGetAvContsR(ValidPtr(&(am2_tRetDistance[1]), 71, table*));
				char* pArg6 = " ";
				char* pArg7 = "\t";
				char* pArg8 = " ";
				double pArg9 = TblGetAvContsR(ValidPtr(&(am2_tTotDistance[1]), 71, table*));
				char* pArg10 = " ";
				char* pArg11 = "\t";
				char* pArg12 = " ";
				double pArg13 = TblGetAvContsR(ValidPtr(&(am2_tAssignInit[1]), 71, table*));
				char* pArg14 = " ";
				char* pArg15 = "\t";
				char* pArg16 = " ";
				double pArg17 = TblGetAvContsR(ValidPtr(&(am2_tAssign[1]), 71, table*));
				char* pArg18 = " ";
				char* pArg19 = "\t";
				char* pArg20 = " ";
				double pArg21 = TblGetAvContsR(ValidPtr(&(am2_tUnloadMove[1]), 71, table*));
				char* pArg22 = " ";
				char* pArg23 = "\t";
				char* pArg24 = " ";
				double pArg25 = TblGetAvContsR(ValidPtr(&(am2_tLoadMove[1]), 71, table*));
				char* pArg26 = " ";
				char* pArg27 = "\t";
				char* pArg28 = " ";
				double pArg29 = ToModelTime(am2_vnRequest[1] / am2_vtRun, UNITSECONDS);
				char* pArg30 = " ";
				char* pArg31 = "\t";
				char* pArg32 = " ";
				double pArg33 = ToModelTime(am2_vnComplete[1] / am2_vtRun, UNITSECONDS);
				char* pArg34 = " ";
				char* pArg35 = "\t";
				char* pArg36 = " ";
				double pArg37 = ToModelTime(am2_vnDelay[1] / am2_vtRun, UNITSECONDS);

				message("%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13, pArg14, pArg15, pArg16, pArg17, pArg18, pArg19, pArg20, pArg21, pArg22, pArg23, pArg24, pArg25, pArg26, pArg27, pArg28, pArg29, pArg30, pArg31, pArg32, pArg33, pArg34, pArg35, pArg36, pArg37);
			}
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 207);
			{
				if (isFileValid(am2_vfpOutResult[6], 0)) {
					double pArg1 = TblGetAvContsR(ValidPtr(&(am2_tDelDistance[2]), 71, table*));
					char* pArg2 = " ";
					char* pArg3 = "\t";
					char* pArg4 = " ";
					double pArg5 = TblGetAvContsR(ValidPtr(&(am2_tRetDistance[2]), 71, table*));
					char* pArg6 = " ";
					char* pArg7 = "\t";
					char* pArg8 = " ";
					double pArg9 = TblGetAvContsR(ValidPtr(&(am2_tTotDistance[2]), 71, table*));
					char* pArg10 = " ";
					char* pArg11 = "\t";
					char* pArg12 = " ";
					double pArg13 = TblGetAvContsR(ValidPtr(&(am2_tAssignInit[2]), 71, table*));
					char* pArg14 = " ";
					char* pArg15 = "\t";
					char* pArg16 = " ";
					double pArg17 = TblGetAvContsR(ValidPtr(&(am2_tAssign[2]), 71, table*));
					char* pArg18 = " ";
					char* pArg19 = "\t";
					char* pArg20 = " ";
					double pArg21 = TblGetAvContsR(ValidPtr(&(am2_tUnloadMove[2]), 71, table*));
					char* pArg22 = " ";
					char* pArg23 = "\t";
					char* pArg24 = " ";
					double pArg25 = TblGetAvContsR(ValidPtr(&(am2_tLoadMove[2]), 71, table*));
					char* pArg26 = " ";
					char* pArg27 = "\t";
					char* pArg28 = " ";
					double pArg29 = ToModelTime(am2_vnRequest[2] / am2_vtRun, UNITSECONDS);
					char* pArg30 = " ";
					char* pArg31 = "\t";
					char* pArg32 = " ";
					double pArg33 = ToModelTime(am2_vnComplete[2] / am2_vtRun, UNITSECONDS);
					char* pArg34 = " ";
					char* pArg35 = "\t";
					char* pArg36 = " ";
					double pArg37 = ToModelTime(am2_vnDelay[2] / am2_vtRun, UNITSECONDS);

					fprintf((am2_vfpOutResult[6])->fp, "%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13, pArg14, pArg15, pArg16, pArg17, pArg18, pArg19, pArg20, pArg21, pArg22, pArg23, pArg24, pArg25, pArg26, pArg27, pArg28, pArg29, pArg30, pArg31, pArg32, pArg33, pArg34, pArg35, pArg36, pArg37);
					fflush((am2_vfpOutResult[6])->fp);
				}
			}
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 213);
			am2_vinoUTBcase = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 214);
			am2_vnRequest[1] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 215);
			am2_vnComplete[1] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 216);
			am2_vnDelay[1] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 217);
			am2_vnRequest[2] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 218);
			am2_vnComplete[2] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 219);
			am2_vnDelay[2] = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("init.m", "Model snap function", "model", model_snap, localactor, 223);
			AMDebuggerEndRoutine("init.m", "Model snap function", "model", model_snap, localactor);
			return 1;
		}
	}
LabelRet: ;
	AMDebuggerEndRoutine("init.m", "Model snap function", "model", model_snap, localactor);
} /* end of model_snap */



/* init function for init.m */
void
model_init_init(struct model_struct* data)
{
	((ProcSystem*)data->$sys)->modelInitPtr = model_initialize;
	data->am_fsetValuable_FilePtr = fsetValuable_FilePtr;
	data->am_freadOHTSpec = freadOHTSpec;
	data->am_freadControl = freadControl;
	((ProcSystem*)data->$sys)->snapFunctionPtr = model_snap;
	data->am_fsetValuable_FilePtr$func->dispatch = dispatch_fsetValuable_FilePtr;
	data->am_fsetValuable_FilePtr$func->func = fsetValuable_FilePtr;
	data->am_freadOHTSpec$func->dispatch = dispatch_freadOHTSpec;
	data->am_freadOHTSpec$func->func = freadOHTSpec;
	data->am_freadControl$func->dispatch = dispatch_freadControl;
	data->am_freadControl$func->func = freadControl;
}

