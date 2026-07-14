// logic.c
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



static double
Funcl0(load* this)
{
	return 100 - am2_vrStorage;
}


static double
Funcl1(load* this)
{
	return am2_vrStorage;
}


typedef struct {
	double (*freq)(load*);
	int32 value;
} Oneof0;

static Oneof0 List0[] = {
	{ Funcl0, 1},
	{ Funcl1, 2}
};

static int32
oneofFunc0(load* this)
{
	size_t ind;
	size_t i;
	static Real freq[2];

	tprintf(tfp, "In oneof\n");
	for (i = 0; i < 2; i++)
		freq[i] = List0[i].freq(this);
	ind = oneof_n(am2_stream0, 2, freq);
	return List0[ind].value;
}


static simloc*
Func0(load* this)
{
	return LocGetQualifier(am_model.am_pm.am_cp_Out_1, -9999);
}


static simloc*
Func1(load* this)
{
	return LocGetQualifier(am_model.am_pm.am_cp_Out_2, -9999);
}


typedef struct {
	simloc* (*value)(load*);
} Nextof1;

static Nextof1 List1[] = {
	Func0,
	Func1
};

static simloc*
nextofFunc1(load* this)
{
	static int ind = 1;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 2;
	return List1[ind].value(this);
}


static simloc*
Func2(load* this)
{
	return LocGetQualifier(am_model.am_pm.am_cp_Out_3, -9999);
}


static simloc*
Func3(load* this)
{
	return LocGetQualifier(am_model.am_pm.am_cp_Out_4, -9999);
}


typedef struct {
	simloc* (*value)(load*);
} Nextof2;

static Nextof2 List2[] = {
	Func2,
	Func3
};

static simloc*
nextofFunc2(load* this)
{
	static int ind = 1;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 2;
	return List2[ind].value(this);
}


static simloc*
Func4(load* this)
{
	return LocGetQualifier(am_model.am_pm.am_cp_Out_5, -9999);
}


static simloc*
Func5(load* this)
{
	return LocGetQualifier(am_model.am_pm.am_cp_Out_6, -9999);
}


typedef struct {
	simloc* (*value)(load*);
} Nextof3;

static Nextof3 List3[] = {
	Func4,
	Func5
};

static simloc*
nextofFunc3(load* this)
{
	static int ind = 1;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 2;
	return List3[ind].value(this);
}


static simloc*
Func6(load* this)
{
	return LocGetQualifier(am_model.am_pm.am_cp_Out_7, -9999);
}


static simloc*
Func7(load* this)
{
	return LocGetQualifier(am_model.am_pm.am_cp_Out_8, -9999);
}


typedef struct {
	simloc* (*value)(load*);
} Nextof4;

static Nextof4 List4[] = {
	Func6,
	Func7
};

static simloc*
nextofFunc4(load* this)
{
	static int ind = 1;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 2;
	return List4[ind].value(this);
}

static int32
pEQZone_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pEQZone", localactor);
	AMDebuggerParams("model.pEQZone", pEQZone_arriving, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	case Step 6: goto Label6;
	case Step 7: goto Label7;
	case Step 8: goto Label8;
	case Step 9: goto Label9;
	case Step 10: goto Label10;
	case Step 11: goto Label11;
	case Step 12: goto Label12;
	case Step 13: goto Label13;
	case Step 14: goto Label14;
	case Step 15: goto Label15;
	case Step 16: goto Label16;
	case Step 17: goto Label17;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 2);
			this->attribute->am2_anLoadType = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 4);
			pushppa(this, pEQZone_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocConv[1]);
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 5);
			{
				int result = inccount(&(am2_cEQBuffer[ValidIndex("am_model.am_cEQBuffer", this->attribute->am2_aiPort, 20)]), 1, this, pEQZone_arriving, Step 3, am_localargs);
				if (result != Continue) return result;
Label3: ;	// Step 3
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 6);
			pushppa(this, pEQZone_arriving, Step 4, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocConv[2]);
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label4: ; // Step 4
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 9);
			pushppa(this, pEQZone_arriving, Step 5, am_localargs);
			pushppa(this, inqueue, Step 1, &(am2_Q_Port[ValidIndex("am_model.am_Q_Port", this->attribute->am2_aiPort, 36)]));
			return Continue; // go move into territory
Label5: ; // Step 5
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 10);
			{
				int result = deccount(&(am2_cEQBuffer[ValidIndex("am_model.am_cEQBuffer", this->attribute->am2_aiPort, 20)]), 1, this, pEQZone_arriving, Step 6, am_localargs);
				if (result != Continue) return result;
Label6: ;	// Step 6
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 12);
			if (CntGetCurConts(ValidPtr(&(am2_cEQBuffer[ValidIndex("am_model.am_cEQBuffer", this->attribute->am2_aiPort, 20)]), 10, counter*)) < 1) {
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 14);
					{
						int result = inccount(&(am2_cEQBufferEmpty[ValidIndex("am_model.am_cEQBufferEmpty", this->attribute->am2_aiPort, 20)]), 1, this, pEQZone_arriving, Step 7, am_localargs);
						if (result != Continue) return result;
Label7: ;	// Step 7
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 15);
					clone(this, 1, am2_pEQBufferCheck, NULL);
				}
			}
			else {
				AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 17);
				if (CntGetCurConts(ValidPtr(&(am2_cEQBuffer[ValidIndex("am_model.am_cEQBuffer", this->attribute->am2_aiPort, 20)]), 10, counter*)) == 1) {
					{
						AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 19);
						{
							int result = inccount(&(am2_cEQBufferCapa1[ValidIndex("am_model.am_cEQBufferCapa1", this->attribute->am2_aiPort, 16)]), 1, this, pEQZone_arriving, Step 8, am_localargs);
							if (result != Continue) return result;
Label8: ;	// Step 8
						}
					}
				}
				else {
					AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 21);
					if (CntGetCurConts(ValidPtr(&(am2_cEQBuffer[ValidIndex("am_model.am_cEQBuffer", this->attribute->am2_aiPort, 20)]), 10, counter*)) == 2) {
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 23);
							{
								int result = inccount(&(am2_cEQBufferCapa2[ValidIndex("am_model.am_cEQBufferCapa2", this->attribute->am2_aiPort, 16)]), 1, this, pEQZone_arriving, Step 9, am_localargs);
								if (result != Continue) return result;
Label9: ;	// Step 9
							}
						}
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 25);
						if (CntGetCurConts(ValidPtr(&(am2_cEQBuffer[ValidIndex("am_model.am_cEQBuffer", this->attribute->am2_aiPort, 20)]), 10, counter*)) == 3) {
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 27);
								{
									int result = inccount(&(am2_cEQBufferCapa3[ValidIndex("am_model.am_cEQBufferCapa3", this->attribute->am2_aiPort, 16)]), 1, this, pEQZone_arriving, Step 10, am_localargs);
									if (result != Continue) return result;
Label10: ;	// Step 10
								}
							}
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 30);
			if (waitfor(ToModelTime(125, UNITSECONDS), this, pEQZone_arriving, Step 11, am_localargs) == Delayed)
				return Delayed;
Label11: ; // Step 11
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 34);
			pushppa(this, pEQZone_arriving, Step 12, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocConv[3]);
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label12: ; // Step 12
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 35);
			LdSetColor(this, 72);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 38);
			am2_viRandom = oneofFunc0(this);
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 40);
			if (am2_viRandom == 1) {
				AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 41);
				clone(this, 1, am2_pUTB_Selection, NULL);
			}
			else {
				AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 42);
				if (am2_viRandom == 2) {
					AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 43);
					clone(this, 1, am2_pSTKtoEQ, NULL);
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 47);
			pushppa(this, pEQZone_arriving, Step 13, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocConv[4]);
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label13: ; // Step 13
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 49);
			this->attribute->am2_anDeliverType = 0;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 50);
			this->attribute->am2_anTransfer = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 51);
			am2_vnRequest[ValidIndex("am_model.am_vnRequest", this->attribute->am2_anLoadType, 30)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 52);
			am2_vnRequesti[ValidIndex("am_model.am_vnRequesti", this->attribute->am2_aiLine, 100)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 54);
			ListAppendItem(LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", this->attribute->am2_anLoadType, 20)], this);	// append item to end of list
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 56);
			this->attribute->am2_atTR = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 58);
			{
				char* pArg1 = rel_simlocname(this->attribute->am2_alocTo, am_model.$sys);

				char* am_tmp;
				am_tmp = bufsprintf("%s", pArg1);
				SetString(&am2_vsTempTo, am_tmp);
				EntityChanged(0x01000000);
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 59);
			am2_vi = str2Integer(StrGetSubStr(am2_vsTempTo, 14, 1));
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 60);
			am2_vi = am2_vi + 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 61);
			SetString(&am2_vsTempTo, StrGetSubStr(am2_vsTempTo, 1, 13));
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 62);
			{
				char* pArg1 = am2_vsTempTo;
				int32 pArg2 = am2_vi;

				char* am_tmp;
				am_tmp = bufsprintf("%s%d", pArg1, pArg2);
				SetString(&am2_vsTempTo, am_tmp);
				EntityChanged(0x01000000);
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 63);
			this->attribute->am2_alocFrom = str2Location(am2_vsTempTo);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 64);
			this->attribute->am2_aiDeliverType = 3;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 66);
			this->attribute->am2_anGapType = 2;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 68);
			pushppa(this, pEQZone_arriving, Step 14, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocFrom);
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label14: ; // Step 14
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 70);
			this->attribute->am2_anGapType = 4;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 72);
			this->attribute->am2_aDistance = VehGetTotDistA(ValidPtr(LdGetVehicle(this), 81, vehicle*));
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 73);
			this->attribute->am2_aRetDistance = this->attribute->am2_aDistance - ValidPtr(LdGetVehicle(this), 81, vehicle*)->load.attribute->am2_vhlRetDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 74);
			am2_viOutNumbering += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 76);
			if (this->attribute->am2_aiLine == 1) {
				AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 76);
				this->attribute->am2_alocOut = nextofFunc1(this);
				EntityChanged(0x00000040);
			}
			else {
				AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 77);
				if (this->attribute->am2_aiLine == 2) {
					AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 77);
					this->attribute->am2_alocOut = nextofFunc2(this);
					EntityChanged(0x00000040);
				}
				else {
					AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 78);
					if (this->attribute->am2_aiLine == 3) {
						AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 78);
						this->attribute->am2_alocOut = nextofFunc3(this);
						EntityChanged(0x00000040);
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 79);
						if (this->attribute->am2_aiLine == 4) {
							AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 79);
							this->attribute->am2_alocOut = nextofFunc4(this);
							EntityChanged(0x00000040);
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 81);
			this->attribute->am2_alocTo = this->attribute->am2_alocOut;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 82);
			pushppa(this, pEQZone_arriving, Step 15, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocTo);
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label15: ; // Step 15
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 83);
			this->attribute->am2_atLoad = ToModelTime(FromModelTime(ASIclock, UNITSECONDS) + ValidPtr(LdGetVehicle(this), 81, vehicle*)->load.attribute->am2_arSetDownTime, UNITSECONDS);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 84);
			this->attribute->am2_aDelDistance = VehGetTotDistA(ValidPtr(LdGetVehicle(this), 81, vehicle*)) - this->attribute->am2_aDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 85);
			this->attribute->am2_aTotDistance = this->attribute->am2_aRetDistance + this->attribute->am2_aDelDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 87);
			{
				int result = inccount(&(am2_cOut[3]), 1, this, pEQZone_arriving, Step 16, am_localargs);
				if (result != Continue) return result;
Label16: ;	// Step 16
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 89);
			tabulate(am2_tDT_Out, FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 90);
			pushppa(this, pEQZone_arriving, Step 17, am_localargs);
			pushppa(this, am2_sReport, Step 1, NULL);
			return Continue;
Label17: ;
			if (!this->inLeaveProc && this->nextproc) {
				retval = Continue;
				goto LabelRet;
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor, 91);
			this->nextproc = am2_pExit; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pEQZone", pEQZone_arriving, localactor);
	return retval;
} /* end of pEQZone_arriving */


typedef struct {
	char* value;
} Nextof5;

static Nextof5 List5[] = {
	"pm.cp_A01001",
	"pm.cp_A01002",
	"pm.cp_A01003",
	"pm.cp_A01004"
};

static char*
nextofFunc5(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List5[ind].value;
}


typedef struct {
	char* value;
} Nextof6;

static Nextof6 List6[] = {
	"pm.cp_A01005",
	"pm.cp_A01006",
	"pm.cp_A01007",
	"pm.cp_A01008"
};

static char*
nextofFunc6(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List6[ind].value;
}


typedef struct {
	char* value;
} Nextof7;

static Nextof7 List7[] = {
	"pm.cp_A01009",
	"pm.cp_A01010",
	"pm.cp_A01011",
	"pm.cp_A01012"
};

static char*
nextofFunc7(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List7[ind].value;
}


typedef struct {
	char* value;
} Nextof8;

static Nextof8 List8[] = {
	"pm.cp_A01013",
	"pm.cp_A01014",
	"pm.cp_A01015",
	"pm.cp_A01016"
};

static char*
nextofFunc8(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List8[ind].value;
}

static int32
pSTKtoUTB_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pSTKtoUTB", localactor);
	AMDebuggerParams("model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	case Step 6: goto Label6;
	case Step 7: goto Label7;
	case Step 8: goto Label8;
	case Step 9: goto Label9;
	case Step 10: goto Label10;
	case Step 11: goto Label11;
	case Step 12: goto Label12;
	case Step 13: goto Label13;
	case Step 14: goto Label14;
	case Step 15: goto Label15;
	case Step 16: goto Label16;
	case Step 17: goto Label17;
	case Step 18: goto Label18;
	case Step 19: goto Label19;
	case Step 20: goto Label20;
	case Step 21: goto Label21;
	case Step 22: goto Label22;
	case Step 23: goto Label23;
	case Step 24: goto Label24;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 96);
			this->attribute->am2_alocTo = this->attribute->am2_alocFrom;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 97);
			if (this->attribute->am2_aiLine == 1) {
				AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 97);
				SetString(&am2_vstrTemp, nextofFunc5(this));
				EntityChanged(0x01000000);
			}
			else {
				AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 98);
				if (this->attribute->am2_aiLine == 2) {
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 98);
					SetString(&am2_vstrTemp, nextofFunc6(this));
					EntityChanged(0x01000000);
				}
				else {
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 99);
					if (this->attribute->am2_aiLine == 3) {
						AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 99);
						SetString(&am2_vstrTemp, nextofFunc7(this));
						EntityChanged(0x01000000);
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 100);
						if (this->attribute->am2_aiLine == 4) {
							AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 100);
							SetString(&am2_vstrTemp, nextofFunc8(this));
							EntityChanged(0x01000000);
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 102);
			this->attribute->am2_alocFrom = str2Location(am2_vstrTemp);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 104);
			this->attribute->am2_anDeliverType = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 105);
			this->attribute->am2_anTransfer = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 106);
			am2_vnRequest[ValidIndex("am_model.am_vnRequest", this->attribute->am2_anLoadType, 30)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 107);
			am2_vnRequesti[ValidIndex("am_model.am_vnRequesti", this->attribute->am2_aiLine, 100)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 108);
			ListAppendItem(LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", this->attribute->am2_anLoadType, 20)], this);	// append item to end of list
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 110);
			this->attribute->am2_anGapType = 3;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 112);
			this->attribute->am2_atTR = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 113);
			this->attribute->am2_aiDeliverType = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 114);
			pushppa(this, pSTKtoUTB_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocFrom);
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 116);
			this->attribute->am2_anGapType = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 118);
			this->attribute->am2_aDistance = VehGetTotDistA(ValidPtr(LdGetVehicle(this), 81, vehicle*));
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 119);
			this->attribute->am2_aRetDistance = this->attribute->am2_aDistance - ValidPtr(LdGetVehicle(this), 81, vehicle*)->load.attribute->am2_vhlRetDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 121);
			pushppa(this, pSTKtoUTB_arriving, Step 3, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocTo);
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label3: ; // Step 3
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 122);
			clone(this, 1, am2_pInsertToUTB, NULL);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 124);
			if (ValidPtr(LdGetVehicle(this), 81, vehicle*)->load.attribute->am2_aiLocChange == 1) {
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 126);
					ValidPtr(LdGetVehicle(this), 81, vehicle*)->load.attribute->am2_aiLocChange = 0;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 127);
					this->attribute->am2_aiLocChange = 1;
					EntityChanged(0x00000040);
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 130);
			if (this->attribute->am2_aiPreMove == 1) {
				AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 131);
				this->attribute->am2_aiPreMove = 0;
				EntityChanged(0x00000040);
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 133);
			this->attribute->am2_atLoad = ToModelTime(FromModelTime(ASIclock, UNITSECONDS) + ValidPtr(LdGetVehicle(this), 81, vehicle*)->load.attribute->am2_arSetDownTime, UNITSECONDS);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 134);
			this->attribute->am2_aDelDistance = VehGetTotDistA(ValidPtr(LdGetVehicle(this), 81, vehicle*)) - this->attribute->am2_aDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 135);
			this->attribute->am2_aTotDistance = this->attribute->am2_aRetDistance + this->attribute->am2_aDelDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 137);
			{
				if (isFileValid(am2_vSTKtoUTBLog, 0)) {
					char* pArg1 = rel_simlocname(this->attribute->am2_alocFrom, am_model.$sys);
					char* pArg2 = " ";
					char* pArg3 = "\t";
					char* pArg4 = rel_simlocname(this->attribute->am2_alocTo, am_model.$sys);
					char* pArg5 = " ";
					char* pArg6 = "\t";
					double pArg7 = FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atTR, UNITSECONDS);
					char* pArg8 = " ";
					char* pArg9 = "\t";
					double pArg10 = FromModelDistance(this->attribute->am2_aDelDistance, UNITMILLIMETERS);

					fprintf((am2_vSTKtoUTBLog)->fp, "%s%s%s%s%s%s%lf%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10);
					fflush((am2_vSTKtoUTBLog)->fp);
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 139);
			tabulate(am2_tDT_STKtoUTB, FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 140);
			pushppa(this, pSTKtoUTB_arriving, Step 4, am_localargs);
			pushppa(this, am2_sReport, Step 1, NULL);
			return Continue;
Label4: ;
			if (!this->inLeaveProc && this->nextproc) {
				retval = Continue;
				goto LabelRet;
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 142);
			if (this->attribute->am2_aiLocChange == 1) {
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 144);
					this->attribute->am2_aiLocChange = 0;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 145);
					this->nextproc = am2_pEQZone; /* send to ... */
					EntityChanged(W_LOAD);
					retval = Continue;
					goto LabelRet;
				}
			}
			else {
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 149);
					pushppa(this, pSTKtoUTB_arriving, Step 5, am_localargs);
					pushppa(this, inqueue, Step 1, &(am2_Q_UTB[ValidIndex("am_model.am_Q_UTB", this->attribute->am2_aiPort, 16)]));
					return Continue; // go move into territory
Label5: ; // Step 5
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 151);
					if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiPort == 1) {
						AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 151);
						{
							int result = inccount(&(am2_cUTBCan9[1]), 1, this, pSTKtoUTB_arriving, Step 6, am_localargs);
							if (result != Continue) return result;
Label6: ;	// Step 6
						}
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 152);
						if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiPort == 2) {
							AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 152);
							{
								int result = inccount(&(am2_cUTBCan9[2]), 1, this, pSTKtoUTB_arriving, Step 7, am_localargs);
								if (result != Continue) return result;
Label7: ;	// Step 7
							}
						}
						else {
							AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 153);
							if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiPort == 3) {
								AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 153);
								{
									int result = inccount(&(am2_cUTBCap9[1]), 1, this, pSTKtoUTB_arriving, Step 8, am_localargs);
									if (result != Continue) return result;
Label8: ;	// Step 8
								}
							}
							else {
								AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 154);
								if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiPort == 4) {
									AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 154);
									{
										int result = inccount(&(am2_cUTBCap9[2]), 1, this, pSTKtoUTB_arriving, Step 9, am_localargs);
										if (result != Continue) return result;
Label9: ;	// Step 9
									}
								}
								else {
									AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 155);
									if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiPort == 5) {
										AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 155);
										{
											int result = inccount(&(am2_cUTBCan10[1]), 1, this, pSTKtoUTB_arriving, Step 10, am_localargs);
											if (result != Continue) return result;
Label10: ;	// Step 10
										}
									}
									else {
										AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 156);
										if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiPort == 6) {
											AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 156);
											{
												int result = inccount(&(am2_cUTBCan10[2]), 1, this, pSTKtoUTB_arriving, Step 11, am_localargs);
												if (result != Continue) return result;
Label11: ;	// Step 11
											}
										}
										else {
											AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 157);
											if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiPort == 7) {
												AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 157);
												{
													int result = inccount(&(am2_cUTBCap10[1]), 1, this, pSTKtoUTB_arriving, Step 12, am_localargs);
													if (result != Continue) return result;
Label12: ;	// Step 12
												}
											}
											else {
												AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 158);
												if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiPort == 8) {
													AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 158);
													{
														int result = inccount(&(am2_cUTBCap10[2]), 1, this, pSTKtoUTB_arriving, Step 13, am_localargs);
														if (result != Continue) return result;
Label13: ;	// Step 13
													}
												}
												else {
													AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 159);
													if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiPort == 9) {
														AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 159);
														{
															int result = inccount(&(am2_cUTBCan11[1]), 1, this, pSTKtoUTB_arriving, Step 14, am_localargs);
															if (result != Continue) return result;
Label14: ;	// Step 14
														}
													}
													else {
														AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 160);
														if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiPort == 10) {
															AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 160);
															{
																int result = inccount(&(am2_cUTBCan11[2]), 1, this, pSTKtoUTB_arriving, Step 15, am_localargs);
																if (result != Continue) return result;
Label15: ;	// Step 15
															}
														}
														else {
															AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 161);
															if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiPort == 11) {
																AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 161);
																{
																	int result = inccount(&(am2_cUTBCap11[1]), 1, this, pSTKtoUTB_arriving, Step 16, am_localargs);
																	if (result != Continue) return result;
Label16: ;	// Step 16
																}
															}
															else {
																AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 162);
																if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiPort == 12) {
																	AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 162);
																	{
																		int result = inccount(&(am2_cUTBCap11[2]), 1, this, pSTKtoUTB_arriving, Step 17, am_localargs);
																		if (result != Continue) return result;
Label17: ;	// Step 17
																	}
																}
																else {
																	AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 163);
																	if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiPort == 13) {
																		AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 163);
																		{
																			int result = inccount(&(am2_cUTBCan12[1]), 1, this, pSTKtoUTB_arriving, Step 18, am_localargs);
																			if (result != Continue) return result;
Label18: ;	// Step 18
																		}
																	}
																	else {
																		AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 164);
																		if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiPort == 14) {
																			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 164);
																			{
																				int result = inccount(&(am2_cUTBCan12[2]), 1, this, pSTKtoUTB_arriving, Step 19, am_localargs);
																				if (result != Continue) return result;
Label19: ;	// Step 19
																			}
																		}
																		else {
																			AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 165);
																			if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiPort == 15) {
																				AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 165);
																				{
																					int result = inccount(&(am2_cUTBCap12[1]), 1, this, pSTKtoUTB_arriving, Step 20, am_localargs);
																					if (result != Continue) return result;
Label20: ;	// Step 20
																				}
																			}
																			else {
																				AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 166);
																				if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiPort == 16) {
																					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 166);
																					{
																						int result = inccount(&(am2_cUTBCap12[2]), 1, this, pSTKtoUTB_arriving, Step 21, am_localargs);
																						if (result != Continue) return result;
Label21: ;	// Step 21
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
									}
								}
							}
						}
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 168);
					return waitorder(&(am2_OL_UTB[ValidIndex("am_model.am_OL_UTB", this->attribute->am2_aiPort, 200)]), this, pSTKtoUTB_arriving, Step 22, am_localargs);
Label22: ; // Step 22
					if (!this->inLeaveProc && this->nextproc) {
						retval = Continue;
						goto LabelRet;
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 170);
					pushppa(this, pSTKtoUTB_arriving, Step 23, am_localargs);
					pushppa(this, inqueue, Step 1, am2_qInfinite);
					return Continue; // go move into territory
Label23: ; // Step 23
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor, 171);
					return waitorder(am2_OLInfinite, this, pSTKtoUTB_arriving, Step 24, am_localargs);
Label24: ; // Step 24
					if (!this->inLeaveProc && this->nextproc) {
						retval = Continue;
						goto LabelRet;
					}
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pSTKtoUTB", pSTKtoUTB_arriving, localactor);
	return retval;
} /* end of pSTKtoUTB_arriving */

static int32
pInsertToUTB_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pInsertToUTB", localactor);
	AMDebuggerParams("model.pInsertToUTB", pInsertToUTB_arriving, localactor, 0, NULL, NULL, NULL);
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
			AMDebugger("logic.m", "Arriving procedure", "model.pInsertToUTB", pInsertToUTB_arriving, localactor, 177);
			ListAppendItem(LoadList, am2_vllUTB[ValidIndex("am_model.am_vllUTB", this->attribute->am2_aiPort, 16)], this);	// append item to end of list
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pInsertToUTB", pInsertToUTB_arriving, localactor, 178);
			return waitorder(am2_OLInfinite, this, pInsertToUTB_arriving, Step 2, am_localargs);
Label2: ; // Step 2
			if (!this->inLeaveProc && this->nextproc) {
				retval = Continue;
				goto LabelRet;
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pInsertToUTB", pInsertToUTB_arriving, localactor);
	return retval;
} /* end of pInsertToUTB_arriving */

static int32
pUTBtoEQ_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pUTBtoEQ", localactor);
	AMDebuggerParams("model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	case Step 6: goto Label6;
	case Step 7: goto Label7;
	case Step 8: goto Label8;
	case Step 9: goto Label9;
	case Step 10: goto Label10;
	case Step 11: goto Label11;
	case Step 12: goto Label12;
	case Step 13: goto Label13;
	case Step 14: goto Label14;
	case Step 15: goto Label15;
	case Step 16: goto Label16;
	case Step 17: goto Label17;
	case Step 18: goto Label18;
	case Step 19: goto Label19;
	case Step 20: goto Label20;
	case Step 21: goto Label21;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 183);
			{
				char* pArg1 = "pm:cp_UTB_";
				int32 pArg2 = this->attribute->am2_aiLine;
				char* pArg3 = "_";
				int32 pArg4 = this->attribute->am2_aiUTBnum;

				char* am_tmp;
				am_tmp = bufsprintf("%s%d%s%d", pArg1, pArg2, pArg3, pArg4);
				SetString(&am2_vstrTemp2, am_tmp);
				EntityChanged(0x01000000);
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 185);
			this->attribute->am2_alocFrom = str2Location(am2_vstrTemp2);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 186);
			this->attribute->am2_anDeliverType = 2;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 187);
			this->attribute->am2_anTransfer = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 188);
			am2_vnRequest[ValidIndex("am_model.am_vnRequest", this->attribute->am2_anLoadType, 30)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 189);
			am2_vnRequesti[ValidIndex("am_model.am_vnRequesti", this->attribute->am2_aiLine, 100)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 191);
			ListAppendItem(LoadList, am2_vlistLoad[ValidIndex("am_model.am_vlistLoad", this->attribute->am2_anLoadType, 20)], this);	// append item to end of list
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 193);
			this->attribute->am2_anGapType = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 194);
			this->attribute->am2_atTR = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 195);
			this->attribute->am2_aiDeliverType = 2;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 196);
			pushppa(this, pUTBtoEQ_arriving, Step 2, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocFrom);
			pushppa(this, move_in_loc, Step 1, NULL);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 197);
			this->attribute->am2_anGapType = 2;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 199);
			clone(this, 1, am2_pSTKtoUTB, am2_lLarge);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 201);
			order(1, &(am2_OL_UTB[ValidIndex("am_model.am_OL_UTB", this->attribute->am2_aiPort, 200)]), NULL, NULL);		// Place an order
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 204);
			if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiPort == 1) {
				AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 204);
				{
					int result = deccount(&(am2_cUTBCan9[1]), 1, this, pUTBtoEQ_arriving, Step 3, am_localargs);
					if (result != Continue) return result;
Label3: ;	// Step 3
				}
			}
			else {
				AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 205);
				if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiPort == 2) {
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 205);
					{
						int result = deccount(&(am2_cUTBCan9[2]), 1, this, pUTBtoEQ_arriving, Step 4, am_localargs);
						if (result != Continue) return result;
Label4: ;	// Step 4
					}
				}
				else {
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 206);
					if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiPort == 3) {
						AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 206);
						{
							int result = deccount(&(am2_cUTBCap9[1]), 1, this, pUTBtoEQ_arriving, Step 5, am_localargs);
							if (result != Continue) return result;
Label5: ;	// Step 5
						}
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 207);
						if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiPort == 4) {
							AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 207);
							{
								int result = deccount(&(am2_cUTBCap9[2]), 1, this, pUTBtoEQ_arriving, Step 6, am_localargs);
								if (result != Continue) return result;
Label6: ;	// Step 6
							}
						}
						else {
							AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 208);
							if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiPort == 5) {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 208);
								{
									int result = deccount(&(am2_cUTBCan10[1]), 1, this, pUTBtoEQ_arriving, Step 7, am_localargs);
									if (result != Continue) return result;
Label7: ;	// Step 7
								}
							}
							else {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 209);
								if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiPort == 6) {
									AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 209);
									{
										int result = deccount(&(am2_cUTBCan10[2]), 1, this, pUTBtoEQ_arriving, Step 8, am_localargs);
										if (result != Continue) return result;
Label8: ;	// Step 8
									}
								}
								else {
									AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 210);
									if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiPort == 7) {
										AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 210);
										{
											int result = deccount(&(am2_cUTBCap10[1]), 1, this, pUTBtoEQ_arriving, Step 9, am_localargs);
											if (result != Continue) return result;
Label9: ;	// Step 9
										}
									}
									else {
										AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 211);
										if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiPort == 8) {
											AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 211);
											{
												int result = deccount(&(am2_cUTBCap10[2]), 1, this, pUTBtoEQ_arriving, Step 10, am_localargs);
												if (result != Continue) return result;
Label10: ;	// Step 10
											}
										}
										else {
											AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 212);
											if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiPort == 9) {
												AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 212);
												{
													int result = deccount(&(am2_cUTBCan11[1]), 1, this, pUTBtoEQ_arriving, Step 11, am_localargs);
													if (result != Continue) return result;
Label11: ;	// Step 11
												}
											}
											else {
												AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 213);
												if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiPort == 10) {
													AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 213);
													{
														int result = deccount(&(am2_cUTBCan11[2]), 1, this, pUTBtoEQ_arriving, Step 12, am_localargs);
														if (result != Continue) return result;
Label12: ;	// Step 12
													}
												}
												else {
													AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 214);
													if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiPort == 11) {
														AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 214);
														{
															int result = deccount(&(am2_cUTBCap11[1]), 1, this, pUTBtoEQ_arriving, Step 13, am_localargs);
															if (result != Continue) return result;
Label13: ;	// Step 13
														}
													}
													else {
														AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 215);
														if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiPort == 12) {
															AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 215);
															{
																int result = deccount(&(am2_cUTBCap11[2]), 1, this, pUTBtoEQ_arriving, Step 14, am_localargs);
																if (result != Continue) return result;
Label14: ;	// Step 14
															}
														}
														else {
															AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 216);
															if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiPort == 13) {
																AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 216);
																{
																	int result = deccount(&(am2_cUTBCan12[1]), 1, this, pUTBtoEQ_arriving, Step 15, am_localargs);
																	if (result != Continue) return result;
Label15: ;	// Step 15
																}
															}
															else {
																AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 217);
																if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiPort == 14) {
																	AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 217);
																	{
																		int result = deccount(&(am2_cUTBCan12[2]), 1, this, pUTBtoEQ_arriving, Step 16, am_localargs);
																		if (result != Continue) return result;
Label16: ;	// Step 16
																	}
																}
																else {
																	AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 218);
																	if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiPort == 15) {
																		AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 218);
																		{
																			int result = deccount(&(am2_cUTBCap12[1]), 1, this, pUTBtoEQ_arriving, Step 17, am_localargs);
																			if (result != Continue) return result;
Label17: ;	// Step 17
																		}
																	}
																	else {
																		AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 219);
																		if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiPort == 16) {
																			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 219);
																			{
																				int result = deccount(&(am2_cUTBCap12[2]), 1, this, pUTBtoEQ_arriving, Step 18, am_localargs);
																				if (result != Continue) return result;
Label18: ;	// Step 18
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
							}
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 222);
			am2_viUTB_Cur -= 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 224);
			this->attribute->am2_aDistance = VehGetTotDistA(ValidPtr(LdGetVehicle(this), 81, vehicle*));
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 225);
			this->attribute->am2_aRetDistance = this->attribute->am2_aDistance - ValidPtr(LdGetVehicle(this), 81, vehicle*)->load.attribute->am2_vhlRetDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 227);
			pushppa(this, pUTBtoEQ_arriving, Step 19, am_localargs);
			load_SetDestLoc(this, this->attribute->am2_alocTo);
			pushppa(this, travel_to_loc, Step 1, NULL);
			return Continue; // go move to location
Label19: ; // Step 19
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 228);
			this->attribute->am2_atLoad = ToModelTime(FromModelTime(ASIclock, UNITSECONDS) + ValidPtr(LdGetVehicle(this), 81, vehicle*)->load.attribute->am2_arSetDownTime, UNITSECONDS);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 229);
			this->attribute->am2_aDelDistance = VehGetTotDistA(ValidPtr(LdGetVehicle(this), 81, vehicle*)) - this->attribute->am2_aDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 230);
			this->attribute->am2_aTotDistance = this->attribute->am2_aRetDistance + this->attribute->am2_aDelDistance;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 232);
			{
				int result = inccount(&(am2_cOut[2]), 1, this, pUTBtoEQ_arriving, Step 20, am_localargs);
				if (result != Continue) return result;
Label20: ;	// Step 20
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 234);
			{
				int32 pArg1 = this->attribute->am2_aiLine;
				int32 pArg2 = this->attribute->am2_aiUTBnum;

				char* am_tmp;
				am_tmp = bufsprintf("%d%d", pArg1, pArg2);
				SetString(&am2_vsUTBName, am_tmp);
				EntityChanged(0x01000000);
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 235);
			this->attribute->am2_aUTBName = str2Integer(am2_vsUTBName);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 237);
			tabulate(am2_tDT_UTBtoEQ, FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 238);
			tabulate(&(am2_tDT_UTBtoEQL[ValidIndex("am_model.am_tDT_UTBtoEQL", this->attribute->am2_aiLine, 9)]), FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 239);
			tabulate(&(am2_tDT_UTBtoEQL2[ValidIndex("am_model.am_tDT_UTBtoEQL2", this->attribute->am2_aUTBName, 499)]), FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 241);
			{
				char* pArg1 = rel_simlocname(this->attribute->am2_alocTo, am_model.$sys);

				char* am_tmp;
				am_tmp = bufsprintf("%s", pArg1);
				SetString(&this->attribute->am2_alocToA, am_tmp);
				EntityChanged(0x00000040);
			}
		}
				{
			int rflag;
			static ReadRef st1;

			setupReadRef(&st1, 1, am_model.am_alocToA$att, &this->attribute->am2_alocToA, NULL, 12, FALSE);
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 242);
			rflag = readString(this->attribute->am2_alocToA, NULL, &st1, NULL);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 244);
			tabulate(&(am2_tUnloadMove[ValidIndex("am_model.am_tUnloadMove", this->attribute->am2_anLoadType, 9)]), FromModelTime(this->attribute->am2_atUnload - this->attribute->am2_atAssign, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 245);
			tabulate(&(am2_tLoadMove[ValidIndex("am_model.am_tLoadMove", this->attribute->am2_anLoadType, 9)]), FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atUnload, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 247);
			{
				if (isFileValid(am2_vUTBtoEQLog, 0)) {
					char* pArg1 = rel_simlocname(this->attribute->am2_alocFrom, am_model.$sys);
					char* pArg2 = " ";
					char* pArg3 = "\t";
					char* pArg4 = rel_simlocname(this->attribute->am2_alocTo, am_model.$sys);
					char* pArg5 = " ";
					char* pArg6 = "\t";
					double pArg7 = FromModelTime(this->attribute->am2_atUnload - this->attribute->am2_atAssign, UNITSECONDS);
					char* pArg8 = " ";
					char* pArg9 = "\t";
					double pArg10 = FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atUnload, UNITSECONDS);
					char* pArg11 = " ";
					char* pArg12 = "\t";
					double pArg13 = FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atTR, UNITSECONDS);
					char* pArg14 = " ";
					char* pArg15 = "\t";
					double pArg16 = FromModelDistance(this->attribute->am2_aDelDistance, UNITMILLIMETERS);

					fprintf((am2_vUTBtoEQLog)->fp, "%s%s%s%s%s%s%lf%s%s%lf%s%s%lf%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13, pArg14, pArg15, pArg16);
					fflush((am2_vUTBtoEQLog)->fp);
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 249);
			pushppa(this, pUTBtoEQ_arriving, Step 21, am_localargs);
			pushppa(this, am2_sReport, Step 1, NULL);
			return Continue;
Label21: ;
			if (!this->inLeaveProc && this->nextproc) {
				retval = Continue;
				goto LabelRet;
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor, 250);
			this->nextproc = am2_pEQZone; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pUTBtoEQ", pUTBtoEQ_arriving, localactor);
	return retval;
} /* end of pUTBtoEQ_arriving */

static int32
pUTB_Selection_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pUTB_Selection", localactor);
	AMDebuggerParams("model.pUTB_Selection", pUTB_Selection_arriving, localactor, 0, NULL, NULL, NULL);
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
			AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 255);
			this->attribute->am2_aiCheck = 0;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 256);
			this->attribute->am2_atDelayed[ValidIndex("am_model.am_atDelayed", this->attribute->am2_aiPort, 16)] = ToModelTime(0, UNITSECONDS);
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 257);
			this->attribute->am2_aiUTBnum = 0;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 258);
			am2_vlSelected = NULL;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 260);
			if (this->attribute->am2_aiUTBnum == 0) {
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 262);
					this->attribute->am2_aiCheck = 0;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 263);
					while (1 == 1) {
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 265);
							if (Size(List, LoadList, am2_vllUTB[ValidIndex("am_model.am_vllUTB", this->attribute->am2_aiPort, 16)]) < 1) {
								{
									AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 267);
									this->attribute->am2_aiCheck += 1;
									EntityChanged(0x00000040);
								}
								{
									AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 268);
									if (this->attribute->am2_aiCheck == 1) {
										{
											AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 270);
											this->attribute->am2_atDelayed[ValidIndex("am_model.am_atDelayed", this->attribute->am2_aiPort, 16)] = ASIclock;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 271);
											am2_vinoUTBcase += 1;
											EntityChanged(0x01000000);
										}
									}
								}
								{
									AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 273);
									if (waitfor(ToModelTime(5, UNITSECONDS), this, pUTB_Selection_arriving, Step 2, am_localargs) == Delayed)
										return Delayed;
Label2: ; // Step 2
								}
							}
							else {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 276);
								break;
							}
						}
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 279);
					this->attribute->am2_aiUTBnum = ValidPtr(ListFirstItem(LoadList, am2_vllUTB[ValidIndex("am_model.am_vllUTB", this->attribute->am2_aiPort, 16)]), 32, load*)->attribute->am2_aiUTBnum;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 280);
					ListRemoveFirstMatch(LoadList, am2_vllUTB[ValidIndex("am_model.am_vllUTB", this->attribute->am2_aiPort, 16)], ListFirstItem(LoadList, am2_vllUTB[ValidIndex("am_model.am_vllUTB", this->attribute->am2_aiPort, 16)]));	// remove first match from list
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 282);
					clone(this, 1, am2_pUTBtoEQ, am2_lLarge);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 284);
					if (this->attribute->am2_aiCheck > 0 && this->attribute->am2_atDelayed[ValidIndex("am_model.am_atDelayed", this->attribute->am2_aiPort, 16)] > ToModelTime(0, UNITSECONDS)) {
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 286);
							tabulate(am2_tUTBdelayTime, FromModelTime((ASIclock - this->attribute->am2_atDelayed[ValidIndex("am_model.am_atDelayed", this->attribute->am2_aiPort, 16)]), UNITSECONDS));	// Tabulate the value
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor, 291);
			this->nextproc = am2_die; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pUTB_Selection", pUTB_Selection_arriving, localactor);
	return retval;
} /* end of pUTB_Selection_arriving */

static int32
pCreate_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pCreate", localactor);
	AMDebuggerParams("model.pCreate", pCreate_arriving, localactor, 0, NULL, NULL, NULL);
	{
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 297);
			this->attribute->am2_anStart = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 300);
			this->attribute->am2_anRoute = 0;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 302);
			while (this->attribute->am2_anRoute < 64) {
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 304);
					this->attribute->am2_anRoute += 1;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 305);
					this->attribute->am2_anDeliverType = 1;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 307);
					if (this->attribute->am2_anRoute <= 4) {
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 309);
							{
								char* pArg1 = "pm:cp_Can_01_1";

								char* am_tmp;
								am_tmp = bufsprintf("%s", pArg1);
								SetString(&am2_vstrTemp, am_tmp);
								EntityChanged(0x01000000);
							}
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 310);
							this->attribute->am2_aiLine = 1;
							EntityChanged(0x00000040);
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 311);
							this->attribute->am2_aiPort = 1;
							EntityChanged(0x00000040);
						}
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 313);
						if (this->attribute->am2_anRoute <= 8) {
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 315);
								{
									char* pArg1 = "pm:cp_Can_01_3";

									char* am_tmp;
									am_tmp = bufsprintf("%s", pArg1);
									SetString(&am2_vstrTemp, am_tmp);
									EntityChanged(0x01000000);
								}
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 316);
								this->attribute->am2_aiLine = 1;
								EntityChanged(0x00000040);
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 317);
								this->attribute->am2_aiPort = 2;
								EntityChanged(0x00000040);
							}
						}
						else {
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 319);
							if (this->attribute->am2_anRoute <= 12) {
								{
									AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 321);
									{
										char* pArg1 = "pm:cp_Cap_01_1";

										char* am_tmp;
										am_tmp = bufsprintf("%s", pArg1);
										SetString(&am2_vstrTemp, am_tmp);
										EntityChanged(0x01000000);
									}
								}
								{
									AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 322);
									this->attribute->am2_aiLine = 1;
									EntityChanged(0x00000040);
								}
								{
									AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 323);
									this->attribute->am2_aiPort = 3;
									EntityChanged(0x00000040);
								}
							}
							else {
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 325);
								if (this->attribute->am2_anRoute <= 16) {
									{
										AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 327);
										{
											char* pArg1 = "pm:cp_Cap_01_3";

											char* am_tmp;
											am_tmp = bufsprintf("%s", pArg1);
											SetString(&am2_vstrTemp, am_tmp);
											EntityChanged(0x01000000);
										}
									}
									{
										AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 328);
										this->attribute->am2_aiLine = 1;
										EntityChanged(0x00000040);
									}
									{
										AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 329);
										this->attribute->am2_aiPort = 4;
										EntityChanged(0x00000040);
									}
								}
								else {
									AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 331);
									if (this->attribute->am2_anRoute <= 20) {
										{
											AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 333);
											{
												char* pArg1 = "pm:cp_Can_02_1";

												char* am_tmp;
												am_tmp = bufsprintf("%s", pArg1);
												SetString(&am2_vstrTemp, am_tmp);
												EntityChanged(0x01000000);
											}
										}
										{
											AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 334);
											this->attribute->am2_aiLine = 2;
											EntityChanged(0x00000040);
										}
										{
											AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 335);
											this->attribute->am2_aiPort = 5;
											EntityChanged(0x00000040);
										}
									}
									else {
										AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 337);
										if (this->attribute->am2_anRoute <= 24) {
											{
												AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 339);
												{
													char* pArg1 = "pm:cp_Can_02_3";

													char* am_tmp;
													am_tmp = bufsprintf("%s", pArg1);
													SetString(&am2_vstrTemp, am_tmp);
													EntityChanged(0x01000000);
												}
											}
											{
												AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 340);
												this->attribute->am2_aiLine = 2;
												EntityChanged(0x00000040);
											}
											{
												AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 341);
												this->attribute->am2_aiPort = 6;
												EntityChanged(0x00000040);
											}
										}
										else {
											AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 343);
											if (this->attribute->am2_anRoute <= 28) {
												{
													AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 345);
													{
														char* pArg1 = "pm:cp_Cap_02_1";

														char* am_tmp;
														am_tmp = bufsprintf("%s", pArg1);
														SetString(&am2_vstrTemp, am_tmp);
														EntityChanged(0x01000000);
													}
												}
												{
													AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 346);
													this->attribute->am2_aiLine = 2;
													EntityChanged(0x00000040);
												}
												{
													AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 347);
													this->attribute->am2_aiPort = 7;
													EntityChanged(0x00000040);
												}
											}
											else {
												AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 349);
												if (this->attribute->am2_anRoute <= 32) {
													{
														AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 351);
														{
															char* pArg1 = "pm:cp_Cap_02_3";

															char* am_tmp;
															am_tmp = bufsprintf("%s", pArg1);
															SetString(&am2_vstrTemp, am_tmp);
															EntityChanged(0x01000000);
														}
													}
													{
														AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 352);
														this->attribute->am2_aiLine = 2;
														EntityChanged(0x00000040);
													}
													{
														AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 353);
														this->attribute->am2_aiPort = 8;
														EntityChanged(0x00000040);
													}
												}
												else {
													AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 356);
													if (this->attribute->am2_anRoute <= 36) {
														{
															AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 358);
															{
																char* pArg1 = "pm:cp_Can_03_1";

																char* am_tmp;
																am_tmp = bufsprintf("%s", pArg1);
																SetString(&am2_vstrTemp, am_tmp);
																EntityChanged(0x01000000);
															}
														}
														{
															AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 359);
															this->attribute->am2_aiLine = 3;
															EntityChanged(0x00000040);
														}
														{
															AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 360);
															this->attribute->am2_aiPort = 9;
															EntityChanged(0x00000040);
														}
													}
													else {
														AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 362);
														if (this->attribute->am2_anRoute <= 40) {
															{
																AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 364);
																{
																	char* pArg1 = "pm:cp_Can_03_3";

																	char* am_tmp;
																	am_tmp = bufsprintf("%s", pArg1);
																	SetString(&am2_vstrTemp, am_tmp);
																	EntityChanged(0x01000000);
																}
															}
															{
																AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 365);
																this->attribute->am2_aiLine = 3;
																EntityChanged(0x00000040);
															}
															{
																AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 366);
																this->attribute->am2_aiPort = 10;
																EntityChanged(0x00000040);
															}
														}
														else {
															AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 368);
															if (this->attribute->am2_anRoute <= 44) {
																{
																	AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 370);
																	{
																		char* pArg1 = "pm:cp_Cap_03_1";

																		char* am_tmp;
																		am_tmp = bufsprintf("%s", pArg1);
																		SetString(&am2_vstrTemp, am_tmp);
																		EntityChanged(0x01000000);
																	}
																}
																{
																	AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 371);
																	this->attribute->am2_aiLine = 3;
																	EntityChanged(0x00000040);
																}
																{
																	AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 372);
																	this->attribute->am2_aiPort = 11;
																	EntityChanged(0x00000040);
																}
															}
															else {
																AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 374);
																if (this->attribute->am2_anRoute <= 48) {
																	{
																		AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 376);
																		{
																			char* pArg1 = "pm:cp_Cap_03_3";

																			char* am_tmp;
																			am_tmp = bufsprintf("%s", pArg1);
																			SetString(&am2_vstrTemp, am_tmp);
																			EntityChanged(0x01000000);
																		}
																	}
																	{
																		AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 377);
																		this->attribute->am2_aiLine = 3;
																		EntityChanged(0x00000040);
																	}
																	{
																		AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 378);
																		this->attribute->am2_aiPort = 12;
																		EntityChanged(0x00000040);
																	}
																}
																else {
																	AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 380);
																	if (this->attribute->am2_anRoute <= 52) {
																		{
																			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 382);
																			{
																				char* pArg1 = "pm:cp_Can_04_1";

																				char* am_tmp;
																				am_tmp = bufsprintf("%s", pArg1);
																				SetString(&am2_vstrTemp, am_tmp);
																				EntityChanged(0x01000000);
																			}
																		}
																		{
																			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 383);
																			this->attribute->am2_aiLine = 4;
																			EntityChanged(0x00000040);
																		}
																		{
																			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 384);
																			this->attribute->am2_aiPort = 13;
																			EntityChanged(0x00000040);
																		}
																	}
																	else {
																		AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 386);
																		if (this->attribute->am2_anRoute <= 56) {
																			{
																				AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 388);
																				{
																					char* pArg1 = "pm:cp_Can_04_3";

																					char* am_tmp;
																					am_tmp = bufsprintf("%s", pArg1);
																					SetString(&am2_vstrTemp, am_tmp);
																					EntityChanged(0x01000000);
																				}
																			}
																			{
																				AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 389);
																				this->attribute->am2_aiLine = 4;
																				EntityChanged(0x00000040);
																			}
																			{
																				AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 390);
																				this->attribute->am2_aiPort = 14;
																				EntityChanged(0x00000040);
																			}
																		}
																		else {
																			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 392);
																			if (this->attribute->am2_anRoute <= 60) {
																				{
																					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 394);
																					{
																						char* pArg1 = "pm:cp_Cap_04_1";

																						char* am_tmp;
																						am_tmp = bufsprintf("%s", pArg1);
																						SetString(&am2_vstrTemp, am_tmp);
																						EntityChanged(0x01000000);
																					}
																				}
																				{
																					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 395);
																					this->attribute->am2_aiLine = 4;
																					EntityChanged(0x00000040);
																				}
																				{
																					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 396);
																					this->attribute->am2_aiPort = 15;
																					EntityChanged(0x00000040);
																				}
																			}
																			else {
																				AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 398);
																				if (this->attribute->am2_anRoute <= 64) {
																					{
																						AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 400);
																						{
																							char* pArg1 = "pm:cp_Cap_04_3";

																							char* am_tmp;
																							am_tmp = bufsprintf("%s", pArg1);
																							SetString(&am2_vstrTemp, am_tmp);
																							EntityChanged(0x01000000);
																						}
																					}
																					{
																						AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 401);
																						this->attribute->am2_aiLine = 4;
																						EntityChanged(0x00000040);
																					}
																					{
																						AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 402);
																						this->attribute->am2_aiPort = 16;
																						EntityChanged(0x00000040);
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
									}
								}
							}
						}
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 405);
					this->attribute->am2_alocTo = str2Location(am2_vstrTemp);
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 406);
					this->attribute->am2_alocToTwin = str2Location(am2_vstrTemp);
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 408);
					am2_vk = str2Integer(StrGetSubStr(am2_vstrTemp, 14, 1));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 409);
					SetString(&am2_vs, StrGetSubStr(am2_vstrTemp, 9, 1));
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 410);
					this->attribute->am2_aQnum = 1;
					EntityChanged(0x00000040);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 412);
					if (StringCompare(am2_vs, "n") == 0) {
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 414);
							{
								char* pArg1 = "conv.sta_Can_0";
								int32 pArg2 = this->attribute->am2_aiLine;
								char* pArg3 = "_";
								int32 pArg4 = am2_vk;
								char* pArg5 = "_1";

								char* am_tmp;
								am_tmp = bufsprintf("%s%d%s%d%s", pArg1, pArg2, pArg3, pArg4, pArg5);
								SetString(&am2_vstrTemp, am_tmp);
								EntityChanged(0x01000000);
							}
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 415);
							this->attribute->am2_alocConv[1] = str2Location(am2_vstrTemp);
							EntityChanged(0x00000040);
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 416);
							{
								char* pArg1 = "conv.sta_Can_0";
								int32 pArg2 = this->attribute->am2_aiLine;
								char* pArg3 = "_";
								int32 pArg4 = am2_vk;
								char* pArg5 = "_2";

								char* am_tmp;
								am_tmp = bufsprintf("%s%d%s%d%s", pArg1, pArg2, pArg3, pArg4, pArg5);
								SetString(&am2_vstrTemp, am_tmp);
								EntityChanged(0x01000000);
							}
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 417);
							this->attribute->am2_alocConv[2] = str2Location(am2_vstrTemp);
							EntityChanged(0x00000040);
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 418);
							{
								char* pArg1 = "conv.sta_Can_0";
								int32 pArg2 = this->attribute->am2_aiLine;
								char* pArg3 = "_";
								int32 pArg4 = am2_vk;
								char* pArg5 = "_3";

								char* am_tmp;
								am_tmp = bufsprintf("%s%d%s%d%s", pArg1, pArg2, pArg3, pArg4, pArg5);
								SetString(&am2_vstrTemp, am_tmp);
								EntityChanged(0x01000000);
							}
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 419);
							this->attribute->am2_alocConv[3] = str2Location(am2_vstrTemp);
							EntityChanged(0x00000040);
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 420);
							{
								char* pArg1 = "conv.sta_Can_0";
								int32 pArg2 = this->attribute->am2_aiLine;
								char* pArg3 = "_";
								int32 pArg4 = am2_vk;
								char* pArg5 = "_4";

								char* am_tmp;
								am_tmp = bufsprintf("%s%d%s%d%s", pArg1, pArg2, pArg3, pArg4, pArg5);
								SetString(&am2_vstrTemp, am_tmp);
								EntityChanged(0x01000000);
							}
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 421);
							this->attribute->am2_alocConv[4] = str2Location(am2_vstrTemp);
							EntityChanged(0x00000040);
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 422);
							this->attribute->am2_aiBox = 1;
							EntityChanged(0x00000040);
						}
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 424);
						if (StringCompare(am2_vs, "p") == 0) {
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 426);
								{
									char* pArg1 = "conv.sta_Cap_0";
									int32 pArg2 = this->attribute->am2_aiLine;
									char* pArg3 = "_";
									int32 pArg4 = am2_vk;
									char* pArg5 = "_1";

									char* am_tmp;
									am_tmp = bufsprintf("%s%d%s%d%s", pArg1, pArg2, pArg3, pArg4, pArg5);
									SetString(&am2_vstrTemp, am_tmp);
									EntityChanged(0x01000000);
								}
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 427);
								this->attribute->am2_alocConv[1] = str2Location(am2_vstrTemp);
								EntityChanged(0x00000040);
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 428);
								{
									char* pArg1 = "conv.sta_Cap_0";
									int32 pArg2 = this->attribute->am2_aiLine;
									char* pArg3 = "_";
									int32 pArg4 = am2_vk;
									char* pArg5 = "_2";

									char* am_tmp;
									am_tmp = bufsprintf("%s%d%s%d%s", pArg1, pArg2, pArg3, pArg4, pArg5);
									SetString(&am2_vstrTemp, am_tmp);
									EntityChanged(0x01000000);
								}
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 429);
								this->attribute->am2_alocConv[2] = str2Location(am2_vstrTemp);
								EntityChanged(0x00000040);
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 430);
								{
									char* pArg1 = "conv.sta_Cap_0";
									int32 pArg2 = this->attribute->am2_aiLine;
									char* pArg3 = "_";
									int32 pArg4 = am2_vk;
									char* pArg5 = "_3";

									char* am_tmp;
									am_tmp = bufsprintf("%s%d%s%d%s", pArg1, pArg2, pArg3, pArg4, pArg5);
									SetString(&am2_vstrTemp, am_tmp);
									EntityChanged(0x01000000);
								}
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 431);
								this->attribute->am2_alocConv[3] = str2Location(am2_vstrTemp);
								EntityChanged(0x00000040);
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 432);
								{
									char* pArg1 = "conv.sta_Cap_0";
									int32 pArg2 = this->attribute->am2_aiLine;
									char* pArg3 = "_";
									int32 pArg4 = am2_vk;
									char* pArg5 = "_4";

									char* am_tmp;
									am_tmp = bufsprintf("%s%d%s%d%s", pArg1, pArg2, pArg3, pArg4, pArg5);
									SetString(&am2_vstrTemp, am_tmp);
									EntityChanged(0x01000000);
								}
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 433);
								this->attribute->am2_alocConv[4] = str2Location(am2_vstrTemp);
								EntityChanged(0x00000040);
							}
							{
								AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 434);
								this->attribute->am2_aiBox = 2;
								EntityChanged(0x00000040);
							}
						}
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 437);
					clone(this, 1, am2_pEQZoneBefore, am2_lLarge);
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 440);
			am2_vi = 0;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor, 441);
			clone(this, 1, am2_pUTBinit, am2_lLarge);
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pCreate", pCreate_arriving, localactor);
	return retval;
} /* end of pCreate_arriving */

static int32
pEQZoneBefore_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pEQZoneBefore", localactor);
	AMDebuggerParams("model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 446);
			if (this->attribute->am2_anRoute <= 12) {
				AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 447);
				if (waitfor(ToModelTime(10 * 1, UNITSECONDS), this, pEQZoneBefore_arriving, Step 2, am_localargs) == Delayed)
					return Delayed;
Label2: ; // Step 2
			}
			else {
				AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 448);
				if (this->attribute->am2_anRoute <= 24) {
					AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 449);
					if (waitfor(ToModelTime(10 * 2, UNITSECONDS), this, pEQZoneBefore_arriving, Step 3, am_localargs) == Delayed)
						return Delayed;
Label3: ; // Step 3
				}
				else {
					AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 450);
					if (this->attribute->am2_anRoute <= 36) {
						AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 451);
						if (waitfor(ToModelTime(10 * 3, UNITSECONDS), this, pEQZoneBefore_arriving, Step 4, am_localargs) == Delayed)
							return Delayed;
Label4: ; // Step 4
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 452);
						if (this->attribute->am2_anRoute <= 48) {
							AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 453);
							if (waitfor(ToModelTime(10 * 4, UNITSECONDS), this, pEQZoneBefore_arriving, Step 5, am_localargs) == Delayed)
								return Delayed;
Label5: ; // Step 5
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor, 455);
			clone(this, 1, am2_pEQZone, NULL);
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pEQZoneBefore", pEQZoneBefore_arriving, localactor);
	return retval;
} /* end of pEQZoneBefore_arriving */


typedef struct {
	int32 value;
} Nextof9;

static Nextof9 List9[] = {
	1,
	3,
	5,
	7
};

static int32
nextofFunc9(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List9[ind].value;
}


typedef struct {
	int32 value;
} Nextof10;

static Nextof10 List10[] = {
	2,
	4,
	6,
	8
};

static int32
nextofFunc10(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List10[ind].value;
}


typedef struct {
	int32 value;
} Nextof11;

static Nextof11 List11[] = {
	9,
	11,
	13,
	15
};

static int32
nextofFunc11(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List11[ind].value;
}


typedef struct {
	int32 value;
} Nextof12;

static Nextof12 List12[] = {
	10,
	12,
	14,
	16
};

static int32
nextofFunc12(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List12[ind].value;
}


typedef struct {
	int32 value;
} Nextof13;

static Nextof13 List13[] = {
	1,
	3,
	5,
	7
};

static int32
nextofFunc13(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List13[ind].value;
}


typedef struct {
	int32 value;
} Nextof14;

static Nextof14 List14[] = {
	2,
	4,
	6,
	8
};

static int32
nextofFunc14(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List14[ind].value;
}


typedef struct {
	int32 value;
} Nextof15;

static Nextof15 List15[] = {
	9,
	11,
	13,
	15
};

static int32
nextofFunc15(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List15[ind].value;
}


typedef struct {
	int32 value;
} Nextof16;

static Nextof16 List16[] = {
	10,
	12,
	14,
	16
};

static int32
nextofFunc16(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List16[ind].value;
}


typedef struct {
	int32 value;
} Nextof17;

static Nextof17 List17[] = {
	1,
	3,
	5,
	7
};

static int32
nextofFunc17(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List17[ind].value;
}


typedef struct {
	int32 value;
} Nextof18;

static Nextof18 List18[] = {
	2,
	4,
	6,
	8
};

static int32
nextofFunc18(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List18[ind].value;
}


typedef struct {
	int32 value;
} Nextof19;

static Nextof19 List19[] = {
	9,
	11,
	13,
	15
};

static int32
nextofFunc19(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List19[ind].value;
}


typedef struct {
	int32 value;
} Nextof20;

static Nextof20 List20[] = {
	10,
	12,
	14,
	16
};

static int32
nextofFunc20(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List20[ind].value;
}


typedef struct {
	int32 value;
} Nextof21;

static Nextof21 List21[] = {
	1,
	3,
	5,
	7
};

static int32
nextofFunc21(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List21[ind].value;
}


typedef struct {
	int32 value;
} Nextof22;

static Nextof22 List22[] = {
	2,
	4,
	6,
	8
};

static int32
nextofFunc22(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List22[ind].value;
}


typedef struct {
	int32 value;
} Nextof23;

static Nextof23 List23[] = {
	9,
	11,
	13,
	15
};

static int32
nextofFunc23(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List23[ind].value;
}


typedef struct {
	int32 value;
} Nextof24;

static Nextof24 List24[] = {
	10,
	12,
	14,
	16
};

static int32
nextofFunc24(load* this)
{
	static int ind = 3;

	tprintf(tfp, "In nextof\n");
	ind = (ind+1) % 4;
	return List24[ind].value;
}

static int32
pUTBinit_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pUTBinit", localactor);
	AMDebuggerParams("model.pUTBinit", pUTBinit_arriving, localactor, 0, NULL, NULL, NULL);
	switch (step) { /* Make the step switcher */
	case Step 1: goto Label1;
	case Step 2: goto Label2;
	case Step 3: goto Label3;
	case Step 4: goto Label4;
	case Step 5: goto Label5;
	case Step 6: goto Label6;
	case Step 7: goto Label7;
	case Step 8: goto Label8;
	case Step 9: goto Label9;
	case Step 10: goto Label10;
	case Step 11: goto Label11;
	case Step 12: goto Label12;
	case Step 13: goto Label13;
	case Step 14: goto Label14;
	case Step 15: goto Label15;
	case Step 16: goto Label16;
	case Step 17: goto Label17;
	case Step 18: goto Label18;
	case Step 19: goto Label19;
	default: message("Bad step number %ld.", step);
	}
	retval = Error;
	goto LabelRet;
Label1: ;  /* Step1 */
	{
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 459);
			this->attribute->am2_anLoadType = 1;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 461);
			am2_vi += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 463);
			if (am2_vi <= 64) {
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 465);
					if (am2_vi <= 4) {
						AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 465);
						this->attribute->am2_aiUTBnum = nextofFunc9(this);
						EntityChanged(0x00000040);
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 466);
						if (am2_vi <= 8) {
							AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 466);
							this->attribute->am2_aiUTBnum = nextofFunc10(this);
							EntityChanged(0x00000040);
						}
						else {
							AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 467);
							if (am2_vi <= 12) {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 467);
								this->attribute->am2_aiUTBnum = nextofFunc11(this);
								EntityChanged(0x00000040);
							}
							else {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 468);
								if (am2_vi <= 16) {
									AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 468);
									this->attribute->am2_aiUTBnum = nextofFunc12(this);
									EntityChanged(0x00000040);
								}
								else {
									AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 470);
									if (am2_vi <= 20) {
										AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 470);
										this->attribute->am2_aiUTBnum = nextofFunc13(this);
										EntityChanged(0x00000040);
									}
									else {
										AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 471);
										if (am2_vi <= 24) {
											AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 471);
											this->attribute->am2_aiUTBnum = nextofFunc14(this);
											EntityChanged(0x00000040);
										}
										else {
											AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 472);
											if (am2_vi <= 28) {
												AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 472);
												this->attribute->am2_aiUTBnum = nextofFunc15(this);
												EntityChanged(0x00000040);
											}
											else {
												AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 473);
												if (am2_vi <= 32) {
													AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 473);
													this->attribute->am2_aiUTBnum = nextofFunc16(this);
													EntityChanged(0x00000040);
												}
												else {
													AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 475);
													if (am2_vi <= 36) {
														AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 475);
														this->attribute->am2_aiUTBnum = nextofFunc17(this);
														EntityChanged(0x00000040);
													}
													else {
														AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 476);
														if (am2_vi <= 40) {
															AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 476);
															this->attribute->am2_aiUTBnum = nextofFunc18(this);
															EntityChanged(0x00000040);
														}
														else {
															AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 477);
															if (am2_vi <= 44) {
																AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 477);
																this->attribute->am2_aiUTBnum = nextofFunc19(this);
																EntityChanged(0x00000040);
															}
															else {
																AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 478);
																if (am2_vi <= 48) {
																	AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 478);
																	this->attribute->am2_aiUTBnum = nextofFunc20(this);
																	EntityChanged(0x00000040);
																}
																else {
																	AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 480);
																	if (am2_vi <= 52) {
																		AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 480);
																		this->attribute->am2_aiUTBnum = nextofFunc21(this);
																		EntityChanged(0x00000040);
																	}
																	else {
																		AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 481);
																		if (am2_vi <= 56) {
																			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 481);
																			this->attribute->am2_aiUTBnum = nextofFunc22(this);
																			EntityChanged(0x00000040);
																		}
																		else {
																			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 482);
																			if (am2_vi <= 60) {
																				AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 482);
																				this->attribute->am2_aiUTBnum = nextofFunc23(this);
																				EntityChanged(0x00000040);
																			}
																			else {
																				AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 483);
																				if (am2_vi <= 64) {
																					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 483);
																					this->attribute->am2_aiUTBnum = nextofFunc24(this);
																					EntityChanged(0x00000040);
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
								}
							}
						}
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 485);
					if (am2_vi <= 4) {
						AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 485);
						{
							int result = inccount(&(am2_cUTBCan9[1]), 1, this, pUTBinit_arriving, Step 2, am_localargs);
							if (result != Continue) return result;
Label2: ;	// Step 2
						}
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 486);
						if (am2_vi <= 8) {
							AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 486);
							{
								int result = inccount(&(am2_cUTBCan9[2]), 1, this, pUTBinit_arriving, Step 3, am_localargs);
								if (result != Continue) return result;
Label3: ;	// Step 3
							}
						}
						else {
							AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 487);
							if (am2_vi <= 12) {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 487);
								{
									int result = inccount(&(am2_cUTBCap9[1]), 1, this, pUTBinit_arriving, Step 4, am_localargs);
									if (result != Continue) return result;
Label4: ;	// Step 4
								}
							}
							else {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 488);
								if (am2_vi <= 16) {
									AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 488);
									{
										int result = inccount(&(am2_cUTBCap9[2]), 1, this, pUTBinit_arriving, Step 5, am_localargs);
										if (result != Continue) return result;
Label5: ;	// Step 5
									}
								}
								else {
									AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 489);
									if (am2_vi <= 20) {
										AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 489);
										{
											int result = inccount(&(am2_cUTBCan10[1]), 1, this, pUTBinit_arriving, Step 6, am_localargs);
											if (result != Continue) return result;
Label6: ;	// Step 6
										}
									}
									else {
										AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 490);
										if (am2_vi <= 24) {
											AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 490);
											{
												int result = inccount(&(am2_cUTBCan10[2]), 1, this, pUTBinit_arriving, Step 7, am_localargs);
												if (result != Continue) return result;
Label7: ;	// Step 7
											}
										}
										else {
											AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 491);
											if (am2_vi <= 28) {
												AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 491);
												{
													int result = inccount(&(am2_cUTBCap10[1]), 1, this, pUTBinit_arriving, Step 8, am_localargs);
													if (result != Continue) return result;
Label8: ;	// Step 8
												}
											}
											else {
												AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 492);
												if (am2_vi <= 32) {
													AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 492);
													{
														int result = inccount(&(am2_cUTBCap10[2]), 1, this, pUTBinit_arriving, Step 9, am_localargs);
														if (result != Continue) return result;
Label9: ;	// Step 9
													}
												}
												else {
													AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 493);
													if (am2_vi <= 36) {
														AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 493);
														{
															int result = inccount(&(am2_cUTBCan11[1]), 1, this, pUTBinit_arriving, Step 10, am_localargs);
															if (result != Continue) return result;
Label10: ;	// Step 10
														}
													}
													else {
														AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 494);
														if (am2_vi <= 40) {
															AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 494);
															{
																int result = inccount(&(am2_cUTBCan11[2]), 1, this, pUTBinit_arriving, Step 11, am_localargs);
																if (result != Continue) return result;
Label11: ;	// Step 11
															}
														}
														else {
															AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 495);
															if (am2_vi <= 44) {
																AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 495);
																{
																	int result = inccount(&(am2_cUTBCap11[1]), 1, this, pUTBinit_arriving, Step 12, am_localargs);
																	if (result != Continue) return result;
Label12: ;	// Step 12
																}
															}
															else {
																AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 496);
																if (am2_vi <= 48) {
																	AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 496);
																	{
																		int result = inccount(&(am2_cUTBCap11[2]), 1, this, pUTBinit_arriving, Step 13, am_localargs);
																		if (result != Continue) return result;
Label13: ;	// Step 13
																	}
																}
																else {
																	AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 497);
																	if (am2_vi <= 52) {
																		AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 497);
																		{
																			int result = inccount(&(am2_cUTBCan12[1]), 1, this, pUTBinit_arriving, Step 14, am_localargs);
																			if (result != Continue) return result;
Label14: ;	// Step 14
																		}
																	}
																	else {
																		AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 498);
																		if (am2_vi <= 56) {
																			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 498);
																			{
																				int result = inccount(&(am2_cUTBCan12[2]), 1, this, pUTBinit_arriving, Step 15, am_localargs);
																				if (result != Continue) return result;
Label15: ;	// Step 15
																			}
																		}
																		else {
																			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 499);
																			if (am2_vi <= 60) {
																				AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 499);
																				{
																					int result = inccount(&(am2_cUTBCap12[1]), 1, this, pUTBinit_arriving, Step 16, am_localargs);
																					if (result != Continue) return result;
Label16: ;	// Step 16
																				}
																			}
																			else {
																				AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 500);
																				if (am2_vi <= 64) {
																					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 500);
																					{
																						int result = inccount(&(am2_cUTBCap12[2]), 1, this, pUTBinit_arriving, Step 17, am_localargs);
																						if (result != Continue) return result;
Label17: ;	// Step 17
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
									}
								}
							}
						}
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 502);
					if (am2_vi <= 4) {
						AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 502);
						this->attribute->am2_aiPort = 1;
						EntityChanged(0x00000040);
					}
					else {
						AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 503);
						if (am2_vi <= 8) {
							AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 503);
							this->attribute->am2_aiPort = 2;
							EntityChanged(0x00000040);
						}
						else {
							AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 504);
							if (am2_vi <= 12) {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 504);
								this->attribute->am2_aiPort = 3;
								EntityChanged(0x00000040);
							}
							else {
								AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 505);
								if (am2_vi <= 16) {
									AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 505);
									this->attribute->am2_aiPort = 4;
									EntityChanged(0x00000040);
								}
								else {
									AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 506);
									if (am2_vi <= 20) {
										AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 506);
										this->attribute->am2_aiPort = 5;
										EntityChanged(0x00000040);
									}
									else {
										AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 507);
										if (am2_vi <= 24) {
											AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 507);
											this->attribute->am2_aiPort = 6;
											EntityChanged(0x00000040);
										}
										else {
											AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 508);
											if (am2_vi <= 28) {
												AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 508);
												this->attribute->am2_aiPort = 7;
												EntityChanged(0x00000040);
											}
											else {
												AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 509);
												if (am2_vi <= 32) {
													AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 509);
													this->attribute->am2_aiPort = 8;
													EntityChanged(0x00000040);
												}
												else {
													AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 510);
													if (am2_vi <= 36) {
														AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 510);
														this->attribute->am2_aiPort = 9;
														EntityChanged(0x00000040);
													}
													else {
														AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 511);
														if (am2_vi <= 40) {
															AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 511);
															this->attribute->am2_aiPort = 10;
															EntityChanged(0x00000040);
														}
														else {
															AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 512);
															if (am2_vi <= 44) {
																AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 512);
																this->attribute->am2_aiPort = 11;
																EntityChanged(0x00000040);
															}
															else {
																AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 513);
																if (am2_vi <= 48) {
																	AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 513);
																	this->attribute->am2_aiPort = 12;
																	EntityChanged(0x00000040);
																}
																else {
																	AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 514);
																	if (am2_vi <= 52) {
																		AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 514);
																		this->attribute->am2_aiPort = 13;
																		EntityChanged(0x00000040);
																	}
																	else {
																		AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 515);
																		if (am2_vi <= 56) {
																			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 515);
																			this->attribute->am2_aiPort = 14;
																			EntityChanged(0x00000040);
																		}
																		else {
																			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 516);
																			if (am2_vi <= 60) {
																				AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 516);
																				this->attribute->am2_aiPort = 15;
																				EntityChanged(0x00000040);
																			}
																			else {
																				AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 517);
																				if (am2_vi <= 64) {
																					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 517);
																					this->attribute->am2_aiPort = 16;
																					EntityChanged(0x00000040);
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
								}
							}
						}
					}
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 519);
					ListAppendItem(LoadList, am2_vllUTB[ValidIndex("am_model.am_vllUTB", this->attribute->am2_aiPort, 16)], this);	// append item to end of list
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 520);
					clone(this, 1, am2_pUTBinit, NULL);
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 521);
					pushppa(this, pUTBinit_arriving, Step 18, am_localargs);
					pushppa(this, inqueue, Step 1, &(am2_Q_UTB[ValidIndex("am_model.am_Q_UTB", this->attribute->am2_aiPort, 16)]));
					return Continue; // go move into territory
Label18: ; // Step 18
				}
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 522);
					return waitorder(&(am2_OL_UTB[ValidIndex("am_model.am_OL_UTB", this->attribute->am2_aiPort, 200)]), this, pUTBinit_arriving, Step 19, am_localargs);
Label19: ; // Step 19
					if (!this->inLeaveProc && this->nextproc) {
						retval = Continue;
						goto LabelRet;
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor, 524);
			this->nextproc = am2_die; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pUTBinit", pUTBinit_arriving, localactor);
	return retval;
} /* end of pUTBinit_arriving */

static int32
pExit_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pExit", localactor);
	AMDebuggerParams("model.pExit", pExit_arriving, localactor, 0, NULL, NULL, NULL);
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
			AMDebugger("logic.m", "Arriving procedure", "model.pExit", pExit_arriving, localactor, 529);
			pushppa(this, pExit_arriving, Step 2, am_localargs);
			pushppa(this, inqueue, Step 1, am2_qSpace);
			return Continue; // go move into territory
Label2: ; // Step 2
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pExit", pExit_arriving, localactor, 530);
			this->nextproc = am2_die; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pExit", pExit_arriving, localactor);
	return retval;
} /* end of pExit_arriving */

static int32
am_sReport(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Subroutine", "model.sReport", localactor);
	AMDebuggerParams("model.sReport", am_sReport, localactor, 0, NULL, NULL, NULL);
	{
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 535);
			am2_vnCompleteType[ValidIndex("am_model.am_vnCompleteType", this->attribute->am2_aiDeliverType, 10)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 537);
			if (ASIclock > ToModelTime(7200, UNITSECONDS)) {
				{
					AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 539);
					if (this->attribute->am2_aiDeliverType == 2) {
						AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 540);
						{
							if (isFileValid(am2_vfpOutResult[4], 0)) {
								int32 pArg1 = this->attribute->am2_aiLine;
								char* pArg2 = " ";
								char* pArg3 = "\t";
								char* pArg4 = " ";
								char* pArg5 = rel_simlocname(this->attribute->am2_alocFrom, am_model.$sys);
								char* pArg6 = " ";
								char* pArg7 = "\t";
								char* pArg8 = " ";
								char* pArg9 = rel_simlocname(this->attribute->am2_alocTo, am_model.$sys);
								char* pArg10 = " ";
								char* pArg11 = "\t";
								char* pArg12 = " ";
								double pArg13 = FromModelTime(this->attribute->am2_atAssignInit - this->attribute->am2_atTR + (this->attribute->am2_atUnload - this->attribute->am2_atAssign + (this->attribute->am2_atAssign - this->attribute->am2_atAssignInit)) + (this->attribute->am2_atLoad - this->attribute->am2_atUnload), UNITSECONDS);
								char* pArg14 = " ";
								char* pArg15 = "\t";
								char* pArg16 = " ";
								double pArg17 = FromModelDistance(this->attribute->am2_aDelDistance / 1000, UNITMILLIMETERS);

								fprintf((am2_vfpOutResult[4])->fp, "%d%s%s%s%s%s%s%s%s%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13, pArg14, pArg15, pArg16, pArg17);
								fflush((am2_vfpOutResult[4])->fp);
							}
						}
					}
					else {
						AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 541);
						if (this->attribute->am2_aiDeliverType == 1) {
							AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 542);
							{
								if (isFileValid(am2_vfpOutResult[7], 0)) {
									int32 pArg1 = this->attribute->am2_aiLine;
									char* pArg2 = " ";
									char* pArg3 = "\t";
									char* pArg4 = " ";
									char* pArg5 = rel_simlocname(this->attribute->am2_alocFrom, am_model.$sys);
									char* pArg6 = " ";
									char* pArg7 = "\t";
									char* pArg8 = " ";
									char* pArg9 = rel_simlocname(this->attribute->am2_alocTo, am_model.$sys);
									char* pArg10 = " ";
									char* pArg11 = "\t";
									char* pArg12 = " ";
									double pArg13 = FromModelTime(this->attribute->am2_atAssignInit - this->attribute->am2_atTR + (this->attribute->am2_atUnload - this->attribute->am2_atAssign + (this->attribute->am2_atAssign - this->attribute->am2_atAssignInit)) + (this->attribute->am2_atLoad - this->attribute->am2_atUnload), UNITSECONDS);
									char* pArg14 = " ";
									char* pArg15 = "\t";
									char* pArg16 = " ";
									double pArg17 = FromModelDistance(this->attribute->am2_aDelDistance / 1000, UNITMILLIMETERS);

									fprintf((am2_vfpOutResult[7])->fp, "%d%s%s%s%s%s%s%s%s%s%s%s%lf%s%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13, pArg14, pArg15, pArg16, pArg17);
									fflush((am2_vfpOutResult[7])->fp);
								}
							}
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 545);
			if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiBox == 1) {
				AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 545);
				am2_viComplete2[1] += 1;
				EntityChanged(0x01000000);
			}
			else {
				AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 546);
				if (this->attribute->am2_aiLine == 1 && this->attribute->am2_aiBox == 2) {
					AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 546);
					am2_viComplete2[2] += 1;
					EntityChanged(0x01000000);
				}
				else {
					AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 547);
					if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiBox == 1) {
						AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 547);
						am2_viComplete2[3] += 1;
						EntityChanged(0x01000000);
					}
					else {
						AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 548);
						if (this->attribute->am2_aiLine == 2 && this->attribute->am2_aiBox == 2) {
							AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 548);
							am2_viComplete2[4] += 1;
							EntityChanged(0x01000000);
						}
						else {
							AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 549);
							if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiBox == 1) {
								AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 549);
								am2_viComplete2[5] += 1;
								EntityChanged(0x01000000);
							}
							else {
								AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 550);
								if (this->attribute->am2_aiLine == 3 && this->attribute->am2_aiBox == 2) {
									AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 550);
									am2_viComplete2[6] += 1;
									EntityChanged(0x01000000);
								}
								else {
									AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 551);
									if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiBox == 1) {
										AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 551);
										am2_viComplete2[7] += 1;
										EntityChanged(0x01000000);
									}
									else {
										AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 552);
										if (this->attribute->am2_aiLine == 4 && this->attribute->am2_aiBox == 2) {
											AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 552);
											am2_viComplete2[8] += 1;
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
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 554);
			tabulate(&(am2_tDelDistancei[ValidIndex("am_model.am_tDelDistancei", this->attribute->am2_aiLine, 10)]), FromModelDistance(this->attribute->am2_aDelDistance, UNITMILLIMETERS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 555);
			tabulate(&(am2_tRetDistancei[ValidIndex("am_model.am_tRetDistancei", this->attribute->am2_aiLine, 10)]), FromModelDistance(this->attribute->am2_aRetDistance, UNITMILLIMETERS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 556);
			tabulate(&(am2_tTotDistancei[ValidIndex("am_model.am_tTotDistancei", this->attribute->am2_aiLine, 10)]), FromModelDistance(this->attribute->am2_aTotDistance, UNITMILLIMETERS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 557);
			tabulate(&(am2_tAssignIniti[ValidIndex("am_model.am_tAssignIniti", this->attribute->am2_aiLine, 10)]), FromModelTime(this->attribute->am2_atAssignInit - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 558);
			tabulate(&(am2_tAssigni[ValidIndex("am_model.am_tAssigni", this->attribute->am2_aiLine, 10)]), FromModelTime(this->attribute->am2_atAssign - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 559);
			tabulate(&(am2_tUnloadMovei[ValidIndex("am_model.am_tUnloadMovei", this->attribute->am2_aiLine, 10)]), FromModelTime(this->attribute->am2_atUnload - this->attribute->am2_atAssign, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 560);
			tabulate(&(am2_tLoadMovei[ValidIndex("am_model.am_tLoadMovei", this->attribute->am2_aiLine, 10)]), FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atUnload, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 562);
			am2_vnCompletei[ValidIndex("am_model.am_vnCompletei", this->attribute->am2_aiLine, 100)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 564);
			tabulate(&(am2_tDelDistance[ValidIndex("am_model.am_tDelDistance", this->attribute->am2_anLoadType, 9)]), FromModelDistance(this->attribute->am2_aDelDistance, UNITMILLIMETERS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 565);
			tabulate(&(am2_tRetDistance[ValidIndex("am_model.am_tRetDistance", this->attribute->am2_anLoadType, 9)]), FromModelDistance(this->attribute->am2_aRetDistance, UNITMILLIMETERS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 566);
			tabulate(&(am2_tTotDistance[ValidIndex("am_model.am_tTotDistance", this->attribute->am2_anLoadType, 9)]), FromModelDistance(this->attribute->am2_aTotDistance, UNITMILLIMETERS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 567);
			tabulate(&(am2_tAssignInit[ValidIndex("am_model.am_tAssignInit", this->attribute->am2_anLoadType, 9)]), FromModelTime(this->attribute->am2_atAssignInit - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 568);
			tabulate(&(am2_tAssign[ValidIndex("am_model.am_tAssign", this->attribute->am2_anLoadType, 9)]), FromModelTime(this->attribute->am2_atAssign - this->attribute->am2_atTR, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 569);
			tabulate(&(am2_tUnloadMove[ValidIndex("am_model.am_tUnloadMove", this->attribute->am2_anLoadType, 9)]), FromModelTime(this->attribute->am2_atUnload - this->attribute->am2_atAssign, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 570);
			tabulate(&(am2_tLoadMove[ValidIndex("am_model.am_tLoadMove", this->attribute->am2_anLoadType, 9)]), FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atUnload, UNITSECONDS));	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 571);
			tabulate(am2_tAssignCount, this->attribute->am2_aiAssignCount);	// Tabulate the value
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 573);
			am2_vnComplete[ValidIndex("am_model.am_vnComplete", this->attribute->am2_anLoadType, 30)] += 1;
			EntityChanged(0x01000000);
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 575);
			if (this->attribute->am2_atLoad - this->attribute->am2_atTR > ToModelTime(5, UNITMINUTES)) {
				{
					AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 577);
					am2_vnDelay[ValidIndex("am_model.am_vnDelay", this->attribute->am2_anLoadType, 20)] += 1;
					EntityChanged(0x01000000);
				}
				{
					AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 578);
					{
						if (isFileValid(am2_vDelayLog, 0)) {
							char* pArg1 = rel_simlocname(this->attribute->am2_alocFrom, am_model.$sys);
							char* pArg2 = " ";
							char* pArg3 = "\t";
							char* pArg4 = rel_simlocname(this->attribute->am2_alocTo, am_model.$sys);
							char* pArg5 = " ";
							char* pArg6 = "\t";
							double pArg7 = FromModelTime(this->attribute->am2_atUnload - this->attribute->am2_atAssign, UNITSECONDS);
							char* pArg8 = " ";
							char* pArg9 = "\t";
							double pArg10 = FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atUnload, UNITSECONDS);
							char* pArg11 = " ";
							char* pArg12 = "\t";
							double pArg13 = FromModelTime(this->attribute->am2_atLoad - this->attribute->am2_atTR, UNITSECONDS);

							fprintf((am2_vDelayLog)->fp, "%s%s%s%s%s%s%lf%s%s%lf%s%s%lf\n", pArg1, pArg2, pArg3, pArg4, pArg5, pArg6, pArg7, pArg8, pArg9, pArg10, pArg11, pArg12, pArg13);
							fflush((am2_vDelayLog)->fp);
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 581);
			if (LocGetCapacity(ValidPtr(this->attribute->am2_alocFrom, 40, simloc*)) == 150 && LocGetCapacity(ValidPtr(this->attribute->am2_alocTo, 40, simloc*)) == 151) {
				AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 582);
				tabulate(am2_tDel_STKtoUTB, FromModelDistance(this->attribute->am2_aDelDistance, UNITMILLIMETERS));	// Tabulate the value
			}
			else {
				AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 583);
				if (LocGetCapacity(ValidPtr(this->attribute->am2_alocFrom, 40, simloc*)) == 151 && LocGetCapacity(ValidPtr(this->attribute->am2_alocTo, 40, simloc*)) == 152) {
					AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 584);
					tabulate(am2_tDel_UTBtoEQ, FromModelDistance(this->attribute->am2_aDelDistance, UNITMILLIMETERS));	// Tabulate the value
				}
				else {
					AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 585);
					if (LocGetCapacity(ValidPtr(this->attribute->am2_alocFrom, 40, simloc*)) == 152 && LocGetCapacity(ValidPtr(this->attribute->am2_alocTo, 40, simloc*)) == 153) {
						AMDebugger("logic.m", "Subroutine", "model.sReport", am_sReport, localactor, 586);
						tabulate(am2_tDel_EQtoOut, FromModelDistance(this->attribute->am2_aDelDistance, UNITMILLIMETERS));	// Tabulate the value
					}
				}
			}
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Subroutine", "model.sReport", am_sReport, localactor);
	return retval;
} /* end of am_sReport */

static int32
pEQBufferCheck_arriving(load* this, int32 step, void* args)
{
	void* am_localargs = NULL;
	load* localactor = this;
	int32 retval = Continue;
	AMDebuggerBeginRoutine("logic.m", "Arriving procedure", "model.pEQBufferCheck", localactor);
	AMDebuggerParams("model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 0, NULL, NULL, NULL);
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
			AMDebugger("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 592);
			this->attribute->am2_atEQEmpty = ASIclock;
			EntityChanged(0x00000040);
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 594);
			while (1 == 1) {
				{
					AMDebugger("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 596);
					if (CntGetCurConts(ValidPtr(&(am2_cEQBuffer[ValidIndex("am_model.am_cEQBuffer", this->attribute->am2_aiPort, 20)]), 10, counter*)) > 0) {
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 598);
							this->attribute->am2_atEQEmpty = ASIclock - this->attribute->am2_atEQEmpty;
							EntityChanged(0x00000040);
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 599);
							tabulate(&(am2_tEQEmpty[ValidIndex("am_model.am_tEQEmpty", this->attribute->am2_aiPort, 20)]), FromModelTime(this->attribute->am2_atEQEmpty, UNITSECONDS));	// Tabulate the value
						}
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 600);
							break;
						}
					}
					else {
						{
							AMDebugger("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 604);
							if (waitfor(ToModelTime(0.10000000000000001, UNITSECONDS), this, pEQBufferCheck_arriving, Step 2, am_localargs) == Delayed)
								return Delayed;
Label2: ; // Step 2
						}
					}
				}
			}
		}
		{
			AMDebugger("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor, 608);
			this->nextproc = am2_die; /* send to ... */
			EntityChanged(W_LOAD);
			retval = Continue;
			goto LabelRet;
		}
	}
LabelRet: ;
	if (am_localargs)
		xfree(am_localargs);
	AMDebuggerEndRoutine("logic.m", "Arriving procedure", "model.pEQBufferCheck", pEQBufferCheck_arriving, localactor);
	return retval;
} /* end of pEQBufferCheck_arriving */



/* init function for logic.m */
void
model_logic_init(struct model_struct* data)
{
	data->am_pEQZone->aprc = pEQZone_arriving;
	data->am_pSTKtoUTB->aprc = pSTKtoUTB_arriving;
	data->am_pInsertToUTB->aprc = pInsertToUTB_arriving;
	data->am_pUTBtoEQ->aprc = pUTBtoEQ_arriving;
	data->am_pUTB_Selection->aprc = pUTB_Selection_arriving;
	data->am_pCreate->aprc = pCreate_arriving;
	data->am_pEQZoneBefore->aprc = pEQZoneBefore_arriving;
	data->am_pUTBinit->aprc = pUTBinit_arriving;
	data->am_pExit->aprc = pExit_arriving;
	data->am_sReport = am_sReport;
	data->am_pEQBufferCheck->aprc = pEQBufferCheck_arriving;
}

