// model~model.c
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


#include "decls.h"

struct model_struct am_model;

char CommandName[] = "C:/AutoModx64/12_6/bin/amod64.exe";
extern ASIWindow WORKMENU;

FILE** imp_stdin;
FILE** imp_stdout;
FILE** imp_stderr;
struct process_system** imp_headpt;
struct AMLoadList* imp_activeloads;
struct model_header** imp_model;
FILE** imp_tfp;
FILE** imp_rfp;
FILE** imp_pfp;
int32* imp_trace;
int32* imp_animate;
int32* imp_Animating;
unsigned long* imp_changeflag;
int32* imp_EnableBeaming;
Time* imp_ASIclock;
Time* imp_beginper;
Boolean* imp_SIMULATOR;
struct AMEventNoticeList** imp_cel;
struct eventlist* imp_fel;
struct dlogItem** imp_grf_sl;
struct s_menu** imp_popmenu;
ASIWindow* imp_WORKMENU;
ASIWindow* imp_SimLotStatusWin;
ASIWindow* imp_SimStnStatusWin;
ASIWindow* imp_SimOperStatusWin;
ASIWindow* imp_SimInvStatusWin;
ASIWindow* imp_SimKanbanStatusWin;

#ifdef __GNUC__
int __attribute__((stdcall)) 
DllEntryPoint(void* hinstDLL, int fdwReason, void* lpvReserved) 
{
	return 1;
}
#endif //__GNUC__


MODELDLLEXPORT
init_globs()
{
	imp_headpt = Getimpheadpt();
	imp_activeloads = Getimpactiveloads();
	imp_model = Getimpmodel();
	imp_tfp = Getimptfp();
	imp_rfp = Getimprfp();
	imp_pfp = Getimppfp();
	imp_trace = Getimptrace();
	imp_animate = Getimpanimate();
	imp_Animating = GetimpAnimating();
	imp_changeflag = Getimpchangeflag();
	imp_EnableBeaming = GetimpEnableBeaming();
	imp_ASIclock = GetimpASIclock();
	imp_beginper = Getimpbeginper();
	imp_SIMULATOR = GetimpSIMULATOR();
	imp_cel = Getimpcel();
	imp_fel = Getimpfel();
	imp_grf_sl = Getimpgrf_sl();
	imp_popmenu = Getimppopmenu();
	imp_WORKMENU = GetimpWORKMENU();
	imp_SimLotStatusWin = GetimpSimLotStatusWin();
	imp_SimStnStatusWin = GetimpSimStnStatusWin();
	imp_SimOperStatusWin = GetimpSimOperStatusWin();
	imp_SimInvStatusWin = GetimpSimInvStatusWin();
	imp_SimKanbanStatusWin = GetimpSimKanbanStatusWin();
	imp_stdin = Getimpstdin();
	imp_stdout = Getimpstdout();
	imp_stderr = Getimpstderr();

	initglobs0();
}

MODELDLLEXPORT load*
newattrib(load* this, load* that)
{
	int i0;

	if (!this->attribute)
		this->attribute = (loadatt*)xmalloc(sizeof(loadatt));
	else {
		ListRemoveAllAndFree(LocationList, this->attribute->am_model.am_aRoute_FromLoc);
		ListRemoveAllAndFree(LocationList, this->attribute->am_model.am_aRoute_ToLoc);
		if (this->attribute->am_model.am_asTemp_PN)
			xfree(this->attribute->am_model.am_asTemp_PN);
		if (this->attribute->am_model.am_asCanCap)
			xfree(this->attribute->am_model.am_asCanCap);
		if (this->attribute->am_model.am_aDefine)
			xfree(this->attribute->am_model.am_aDefine);
		if (this->attribute->am_model.am_alocToA)
			xfree(this->attribute->am_model.am_alocToA);
	}
	if (that != NULL) {
		*(this->attribute) = *(that->attribute);
		this->attribute->am_model.am_aRoute_FromLoc = NULL;
		ListCopy(LocationList, this->attribute->am_model.am_aRoute_FromLoc, that->attribute->am_model.am_aRoute_FromLoc);
		this->attribute->am_model.am_aRoute_ToLoc = NULL;
		ListCopy(LocationList, this->attribute->am_model.am_aRoute_ToLoc, that->attribute->am_model.am_aRoute_ToLoc);
		if (this->attribute->am_model.am_asTemp_PN) {
			this->attribute->am_model.am_asTemp_PN = strdup(that->attribute->am_model.am_asTemp_PN);
		}
		if (this->attribute->am_model.am_asCanCap) {
			this->attribute->am_model.am_asCanCap = strdup(that->attribute->am_model.am_asCanCap);
		}
		if (this->attribute->am_model.am_aDefine) {
			this->attribute->am_model.am_aDefine = strdup(that->attribute->am_model.am_aDefine);
		}
		if (this->attribute->am_model.am_alocToA) {
			this->attribute->am_model.am_alocToA = strdup(that->attribute->am_model.am_alocToA);
		}
	} else
		memset(this->attribute, 0, sizeof(loadatt));
	return this;
}

MODELDLLEXPORT void*
get_ldatt_address(load* this, int32 index, int32* d)
{
	void* data = NULL;

	switch(index) {
	case 0:
		data = (void*)&this->attribute->am_model.am_anVehicleType;
		break;
	case 1:
		data = (void*)&this->attribute->am_model.am_aID;
		break;
	case 2:
		data = (void*)&this->attribute->am_model.am_aAssign;
		break;
	case 3:
		data = (void*)&this->attribute->am_model.am_aParkBay;
		break;
	case 4:
		data = (void*)&this->attribute->am_model.am_atRetStart;
		break;
	case 5:
		data = (void*)&this->attribute->am_model.am_anLoadType;
		break;
	case 6:
		data = (void*)&this->attribute->am_model.am_atUnload;
		break;
	case 7:
		data = (void*)&this->attribute->am_model.am_alocToBay;
		break;
	case 8:
		data = (void*)&this->attribute->am_model.am_alocFromBay;
		break;
	case 9:
		data = (void*)&this->attribute->am_model.am_aRoute_FromLoc;
		break;
	case 10:
		data = (void*)&this->attribute->am_model.am_alocFrom;
		break;
	case 11:
		data = (void*)&this->attribute->am_model.am_atLoad;
		break;
	case 12:
		data = (void*)&this->attribute->am_model.am_anTransfer;
		break;
	case 13:
		data = (void*)&this->attribute->am_model.am_alocStorage;
		break;
	case 14:
		data = (void*)&this->attribute->am_model.am_atTR;
		break;
	case 15:
		data = (void*)&this->attribute->am_model.am_atAssign;
		break;
	case 16:
		data = (void*)&this->attribute->am_model.am_atAssignInit;
		break;
	case 17:
		data = (void*)&this->attribute->am_model.am_vhlRetDistance;
		break;
	case 18:
		data = (void*)&this->attribute->am_model.am_avDispatch;
		break;
	case 19:
		data = (void*)&this->attribute->am_model.am_alocPark;
		break;
	case 20:
		data = (void*)&this->attribute->am_model.am_anRoute;
		break;
	case 21:
		data = (void*)&this->attribute->am_model.am_atInitialCreated;
		break;
	case 22:
		data = (void*)&this->attribute->am_model.am_arTimeGap;
		break;
	case 23:
		data = (void*)&this->attribute->am_model.am_atAfterTimeGap;
		break;
	case 24:
		data = (void*)&this->attribute->am_model.am_atCreate;
		break;
	case 25:
		data = (void*)&this->attribute->am_model.am_aDistance;
		break;
	case 26:
		data = (void*)&this->attribute->am_model.am_aRetDistance;
		break;
	case 27:
		data = (void*)&this->attribute->am_model.am_aRoute_ToLoc;
		break;
	case 28:
		data = (void*)&this->attribute->am_model.am_alocTo;
		break;
	case 29:
		data = (void*)&this->attribute->am_model.am_aDelDistance;
		break;
	case 30:
		data = (void*)&this->attribute->am_model.am_aTotDistance;
		break;
	case 31:
		data = (void*)&this->attribute->am_model.am_aiAssignCount;
		break;
	case 32:
		data = (void*)&this->attribute->am_model.am_anTemp1;
		break;
	case 33:
		data = (void*)&this->attribute->am_model.am_atConvIn[d[0]];
		break;
	case 34:
		data = (void*)&this->attribute->am_model.am_atConvOut[d[0]];
		break;
	case 35:
		data = (void*)&this->attribute->am_model.am_atConv[d[0]];
		break;
	case 36:
		data = (void*)&this->attribute->am_model.am_atInLoadCome;
		break;
	case 37:
		data = (void*)&this->attribute->am_model.am_atInLoadGo;
		break;
	case 38:
		data = (void*)&this->attribute->am_model.am_atOutLoadCome;
		break;
	case 39:
		data = (void*)&this->attribute->am_model.am_atOutLoadGo;
		break;
	case 40:
		data = (void*)&this->attribute->am_model.am_atOutLoad;
		break;
	case 41:
		data = (void*)&this->attribute->am_model.am_atInLoad;
		break;
	case 42:
		data = (void*)&this->attribute->am_model.am_alocConvFrom;
		break;
	case 43:
		data = (void*)&this->attribute->am_model.am_alocConvTo;
		break;
	case 44:
		data = (void*)&this->attribute->am_model.am_ai;
		break;
	case 45:
		data = (void*)&this->attribute->am_model.am_anDeliverType;
		break;
	case 46:
		data = (void*)&this->attribute->am_model.am_aQnum;
		break;
	case 47:
		data = (void*)&this->attribute->am_model.am_aj;
		break;
	case 48:
		data = (void*)&this->attribute->am_model.am_asTemp_PN;
		break;
	case 49:
		data = (void*)&this->attribute->am_model.am_aiTemp_EQnum;
		break;
	case 50:
		data = (void*)&this->attribute->am_model.am_alocOut;
		break;
	case 51:
		data = (void*)&this->attribute->am_model.am_anStart;
		break;
	case 52:
		data = (void*)&this->attribute->am_model.am_aiUTBnum;
		break;
	case 53:
		data = (void*)&this->attribute->am_model.am_aiHotLot;
		break;
	case 54:
		data = (void*)&this->attribute->am_model.am_aiHotLotEQ;
		break;
	case 55:
		data = (void*)&this->attribute->am_model.am_asCanCap;
		break;
	case 56:
		data = (void*)&this->attribute->am_model.am_aAlt;
		break;
	case 57:
		data = (void*)&this->attribute->am_model.am_atEnterLoss;
		break;
	case 58:
		data = (void*)&this->attribute->am_model.am_atOutLoss;
		break;
	case 59:
		data = (void*)&this->attribute->am_model.am_atServiceEnd;
		break;
	case 60:
		data = (void*)&this->attribute->am_model.am_atFinalBuffer;
		break;
	case 61:
		data = (void*)&this->attribute->am_model.am_atServiceIn;
		break;
	case 62:
		data = (void*)&this->attribute->am_model.am_aDefine;
		break;
	case 63:
		data = (void*)&this->attribute->am_model.am_aiPortZone;
		break;
	case 64:
		data = (void*)&this->attribute->am_model.am_aiLossNum;
		break;
	case 65:
		data = (void*)&this->attribute->am_model.am_aiDelay;
		break;
	case 66:
		data = (void*)&this->attribute->am_model.am_aiSearchCount;
		break;
	case 67:
		data = (void*)&this->attribute->am_model.am_aiOL;
		break;
	case 68:
		data = (void*)&this->attribute->am_model.am_aiLocAssigned;
		break;
	case 69:
		data = (void*)&this->attribute->am_model.am_aiRandom;
		break;
	case 70:
		data = (void*)&this->attribute->am_model.am_aiBoxOut;
		break;
	case 71:
		data = (void*)&this->attribute->am_model.am_atEnterToOut;
		break;
	case 72:
		data = (void*)&this->attribute->am_model.am_aiCheck;
		break;
	case 73:
		data = (void*)&this->attribute->am_model.am_aiYellow;
		break;
	case 74:
		data = (void*)&this->attribute->am_model.am_aiPreMove;
		break;
	case 75:
		data = (void*)&this->attribute->am_model.am_aiLine;
		break;
	case 76:
		data = (void*)&this->attribute->am_model.am_aiDeliverType;
		break;
	case 77:
		data = (void*)&this->attribute->am_model.am_alocToTwin;
		break;
	case 78:
		data = (void*)&this->attribute->am_model.am_aiLocChange;
		break;
	case 79:
		data = (void*)&this->attribute->am_model.am_alocConv[d[0]];
		break;
	case 80:
		data = (void*)&this->attribute->am_model.am_aiPort;
		break;
	case 81:
		data = (void*)&this->attribute->am_model.am_aiCounterNum;
		break;
	case 82:
		data = (void*)&this->attribute->am_model.am_aiUTBtoEQ;
		break;
	case 83:
		data = (void*)&this->attribute->am_model.am_aiSTKtoEQ;
		break;
	case 84:
		data = (void*)&this->attribute->am_model.am_aiBox;
		break;
	case 85:
		data = (void*)&this->attribute->am_model.am_anDummy;
		break;
	case 86:
		data = (void*)&this->attribute->am_model.am_atDelayed[d[0]];
		break;
	case 87:
		data = (void*)&this->attribute->am_model.am_aUTBName;
		break;
	case 88:
		data = (void*)&this->attribute->am_model.am_A_cgStopDelay;
		break;
	case 89:
		data = (void*)&this->attribute->am_model.am_A_cgStopOccur;
		break;
	case 90:
		data = (void*)&this->attribute->am_model.am_A_cgStopTotalDelay;
		break;
	case 91:
		data = (void*)&this->attribute->am_model.am_A_cgStopVeh;
		break;
	case 92:
		data = (void*)&this->attribute->am_model.am_alocToA;
		break;
	case 93:
		data = (void*)&this->attribute->am_model.am_atEQEmpty;
		break;
	case 94:
		data = (void*)&this->attribute->am_model.am_aRandom;
		break;
	case 95:
		data = (void*)&this->attribute->am_model.am_anGapType;
		break;
	case 96:
		data = (void*)&this->attribute->am_model.am_aiSteering;
		break;
	case 97:
		data = (void*)&this->attribute->am_model.am_aiSteerChange;
		break;
	case 98:
		data = (void*)&this->attribute->am_model.am_aiLineStart[d[0]];
		break;
	case 99:
		data = (void*)&this->attribute->am_model.am_arSetDownTime;
		break;
	}
	return data;
}

MODELDLLEXPORT void
set_attdata(load* this)
{
	attribute* att;

	am_model.am_anVehicleType$att->data = (void*)&this->attribute->am_model.am_anVehicleType;
	am_model.am_aID$att->data = (void*)&this->attribute->am_model.am_aID;
	am_model.am_aAssign$att->data = (void*)&this->attribute->am_model.am_aAssign;
	am_model.am_aParkBay$att->data = (void*)&this->attribute->am_model.am_aParkBay;
	am_model.am_atRetStart$att->data = (void*)&this->attribute->am_model.am_atRetStart;
	am_model.am_anLoadType$att->data = (void*)&this->attribute->am_model.am_anLoadType;
	am_model.am_atUnload$att->data = (void*)&this->attribute->am_model.am_atUnload;
	am_model.am_alocToBay$att->data = (void*)&this->attribute->am_model.am_alocToBay;
	am_model.am_alocFromBay$att->data = (void*)&this->attribute->am_model.am_alocFromBay;
	am_model.am_aRoute_FromLoc$att->data = (void*)&this->attribute->am_model.am_aRoute_FromLoc;
	am_model.am_alocFrom$att->data = (void*)&this->attribute->am_model.am_alocFrom;
	am_model.am_atLoad$att->data = (void*)&this->attribute->am_model.am_atLoad;
	am_model.am_anTransfer$att->data = (void*)&this->attribute->am_model.am_anTransfer;
	am_model.am_alocStorage$att->data = (void*)&this->attribute->am_model.am_alocStorage;
	am_model.am_atTR$att->data = (void*)&this->attribute->am_model.am_atTR;
	am_model.am_atAssign$att->data = (void*)&this->attribute->am_model.am_atAssign;
	am_model.am_atAssignInit$att->data = (void*)&this->attribute->am_model.am_atAssignInit;
	am_model.am_vhlRetDistance$att->data = (void*)&this->attribute->am_model.am_vhlRetDistance;
	am_model.am_avDispatch$att->data = (void*)&this->attribute->am_model.am_avDispatch;
	am_model.am_alocPark$att->data = (void*)&this->attribute->am_model.am_alocPark;
	am_model.am_anRoute$att->data = (void*)&this->attribute->am_model.am_anRoute;
	am_model.am_atInitialCreated$att->data = (void*)&this->attribute->am_model.am_atInitialCreated;
	am_model.am_arTimeGap$att->data = (void*)&this->attribute->am_model.am_arTimeGap;
	am_model.am_atAfterTimeGap$att->data = (void*)&this->attribute->am_model.am_atAfterTimeGap;
	am_model.am_atCreate$att->data = (void*)&this->attribute->am_model.am_atCreate;
	am_model.am_aDistance$att->data = (void*)&this->attribute->am_model.am_aDistance;
	am_model.am_aRetDistance$att->data = (void*)&this->attribute->am_model.am_aRetDistance;
	am_model.am_aRoute_ToLoc$att->data = (void*)&this->attribute->am_model.am_aRoute_ToLoc;
	am_model.am_alocTo$att->data = (void*)&this->attribute->am_model.am_alocTo;
	am_model.am_aDelDistance$att->data = (void*)&this->attribute->am_model.am_aDelDistance;
	am_model.am_aTotDistance$att->data = (void*)&this->attribute->am_model.am_aTotDistance;
	am_model.am_aiAssignCount$att->data = (void*)&this->attribute->am_model.am_aiAssignCount;
	am_model.am_anTemp1$att->data = (void*)&this->attribute->am_model.am_anTemp1;
	am_model.am_atConvIn$att->data = (void*)this->attribute->am_model.am_atConvIn;
	am_model.am_atConvOut$att->data = (void*)this->attribute->am_model.am_atConvOut;
	am_model.am_atConv$att->data = (void*)this->attribute->am_model.am_atConv;
	am_model.am_atInLoadCome$att->data = (void*)&this->attribute->am_model.am_atInLoadCome;
	am_model.am_atInLoadGo$att->data = (void*)&this->attribute->am_model.am_atInLoadGo;
	am_model.am_atOutLoadCome$att->data = (void*)&this->attribute->am_model.am_atOutLoadCome;
	am_model.am_atOutLoadGo$att->data = (void*)&this->attribute->am_model.am_atOutLoadGo;
	am_model.am_atOutLoad$att->data = (void*)&this->attribute->am_model.am_atOutLoad;
	am_model.am_atInLoad$att->data = (void*)&this->attribute->am_model.am_atInLoad;
	am_model.am_alocConvFrom$att->data = (void*)&this->attribute->am_model.am_alocConvFrom;
	am_model.am_alocConvTo$att->data = (void*)&this->attribute->am_model.am_alocConvTo;
	am_model.am_ai$att->data = (void*)&this->attribute->am_model.am_ai;
	am_model.am_anDeliverType$att->data = (void*)&this->attribute->am_model.am_anDeliverType;
	am_model.am_aQnum$att->data = (void*)&this->attribute->am_model.am_aQnum;
	am_model.am_aj$att->data = (void*)&this->attribute->am_model.am_aj;
	am_model.am_asTemp_PN$att->data = (void*)&this->attribute->am_model.am_asTemp_PN;
	am_model.am_aiTemp_EQnum$att->data = (void*)&this->attribute->am_model.am_aiTemp_EQnum;
	am_model.am_alocOut$att->data = (void*)&this->attribute->am_model.am_alocOut;
	am_model.am_anStart$att->data = (void*)&this->attribute->am_model.am_anStart;
	am_model.am_aiUTBnum$att->data = (void*)&this->attribute->am_model.am_aiUTBnum;
	am_model.am_aiHotLot$att->data = (void*)&this->attribute->am_model.am_aiHotLot;
	am_model.am_aiHotLotEQ$att->data = (void*)&this->attribute->am_model.am_aiHotLotEQ;
	am_model.am_asCanCap$att->data = (void*)&this->attribute->am_model.am_asCanCap;
	am_model.am_aAlt$att->data = (void*)&this->attribute->am_model.am_aAlt;
	am_model.am_atEnterLoss$att->data = (void*)&this->attribute->am_model.am_atEnterLoss;
	am_model.am_atOutLoss$att->data = (void*)&this->attribute->am_model.am_atOutLoss;
	am_model.am_atServiceEnd$att->data = (void*)&this->attribute->am_model.am_atServiceEnd;
	am_model.am_atFinalBuffer$att->data = (void*)&this->attribute->am_model.am_atFinalBuffer;
	am_model.am_atServiceIn$att->data = (void*)&this->attribute->am_model.am_atServiceIn;
	am_model.am_aDefine$att->data = (void*)&this->attribute->am_model.am_aDefine;
	am_model.am_aiPortZone$att->data = (void*)&this->attribute->am_model.am_aiPortZone;
	am_model.am_aiLossNum$att->data = (void*)&this->attribute->am_model.am_aiLossNum;
	am_model.am_aiDelay$att->data = (void*)&this->attribute->am_model.am_aiDelay;
	am_model.am_aiSearchCount$att->data = (void*)&this->attribute->am_model.am_aiSearchCount;
	am_model.am_aiOL$att->data = (void*)&this->attribute->am_model.am_aiOL;
	am_model.am_aiLocAssigned$att->data = (void*)&this->attribute->am_model.am_aiLocAssigned;
	am_model.am_aiRandom$att->data = (void*)&this->attribute->am_model.am_aiRandom;
	am_model.am_aiBoxOut$att->data = (void*)&this->attribute->am_model.am_aiBoxOut;
	am_model.am_atEnterToOut$att->data = (void*)&this->attribute->am_model.am_atEnterToOut;
	am_model.am_aiCheck$att->data = (void*)&this->attribute->am_model.am_aiCheck;
	am_model.am_aiYellow$att->data = (void*)&this->attribute->am_model.am_aiYellow;
	am_model.am_aiPreMove$att->data = (void*)&this->attribute->am_model.am_aiPreMove;
	am_model.am_aiLine$att->data = (void*)&this->attribute->am_model.am_aiLine;
	am_model.am_aiDeliverType$att->data = (void*)&this->attribute->am_model.am_aiDeliverType;
	am_model.am_alocToTwin$att->data = (void*)&this->attribute->am_model.am_alocToTwin;
	am_model.am_aiLocChange$att->data = (void*)&this->attribute->am_model.am_aiLocChange;
	am_model.am_alocConv$att->data = (void*)this->attribute->am_model.am_alocConv;
	am_model.am_aiPort$att->data = (void*)&this->attribute->am_model.am_aiPort;
	am_model.am_aiCounterNum$att->data = (void*)&this->attribute->am_model.am_aiCounterNum;
	am_model.am_aiUTBtoEQ$att->data = (void*)&this->attribute->am_model.am_aiUTBtoEQ;
	am_model.am_aiSTKtoEQ$att->data = (void*)&this->attribute->am_model.am_aiSTKtoEQ;
	am_model.am_aiBox$att->data = (void*)&this->attribute->am_model.am_aiBox;
	am_model.am_anDummy$att->data = (void*)&this->attribute->am_model.am_anDummy;
	am_model.am_atDelayed$att->data = (void*)this->attribute->am_model.am_atDelayed;
	am_model.am_aUTBName$att->data = (void*)&this->attribute->am_model.am_aUTBName;
	am_model.am_A_cgStopDelay$att->data = (void*)&this->attribute->am_model.am_A_cgStopDelay;
	am_model.am_A_cgStopOccur$att->data = (void*)&this->attribute->am_model.am_A_cgStopOccur;
	am_model.am_A_cgStopTotalDelay$att->data = (void*)&this->attribute->am_model.am_A_cgStopTotalDelay;
	am_model.am_A_cgStopVeh$att->data = (void*)&this->attribute->am_model.am_A_cgStopVeh;
	am_model.am_alocToA$att->data = (void*)&this->attribute->am_model.am_alocToA;
	am_model.am_atEQEmpty$att->data = (void*)&this->attribute->am_model.am_atEQEmpty;
	am_model.am_aRandom$att->data = (void*)&this->attribute->am_model.am_aRandom;
	am_model.am_anGapType$att->data = (void*)&this->attribute->am_model.am_anGapType;
	am_model.am_aiSteering$att->data = (void*)&this->attribute->am_model.am_aiSteering;
	am_model.am_aiSteerChange$att->data = (void*)&this->attribute->am_model.am_aiSteerChange;
	am_model.am_aiLineStart$att->data = (void*)this->attribute->am_model.am_aiLineStart;
	am_model.am_arSetDownTime$att->data = (void*)&this->attribute->am_model.am_arSetDownTime;
}

char*
Acceleration_valstrfunc(void* data)
{
	Acceleration* valptr = (Acceleration*)data;

	return acceleration2str(*valptr);
}

Acceleration
Acceleration_strvalfunc(char* data)
{
	return str2Acceleration(data);
}

char*
BlockPtr_valstrfunc(void* data)
{
	block** valptr = (block**)data;

	return actorname(*valptr);
}

block*
BlockPtr_strvalfunc(char* data)
{
	return str2BlockPtr(data);
}

char*
BlockList_valstrfunc(void* data)
{
	AMBlockList** valptr = (AMBlockList**)data;

	return AMBlockListToStr(*valptr);
}

char*
Color_valstrfunc(void* data)
{
	ASI_Color* valptr = (ASI_Color*)data;

	return color2str(*valptr);
}

ASI_Color
Color_strvalfunc(char* data)
{
	return str2Color(data);
}

char*
ContainerPtr_valstrfunc(void* data)
{
	Container** valptr = (Container**)data;

	return actorname(*valptr);
}

Container*
ContainerPtr_strvalfunc(char* data)
{
	return str2ContainerPtr(data);
}

char*
ContainerList_valstrfunc(void* data)
{
	AMContainerList** valptr = (AMContainerList**)data;

	return AMContainerListToStr(*valptr);
}

char*
CounterPtr_valstrfunc(void* data)
{
	counter** valptr = (counter**)data;

	return actorname(*valptr);
}

counter*
CounterPtr_strvalfunc(char* data)
{
	return str2CounterPtr(data);
}

char*
Distance_valstrfunc(void* data)
{
	Distance* valptr = (Distance*)data;

	return distance2str(*valptr);
}

Distance
Distance_strvalfunc(char* data)
{
	return str2Distance(data);
}

char*
FilePtr_valstrfunc(void* data)
{
	iofile** valptr = (iofile**)data;

	return iofile2str(*valptr);
}

iofile*
FilePtr_strvalfunc(char* data)
{
	return str2FilePtr(data);
}

char*
GraphPtr_valstrfunc(void* data)
{
	bgraph** valptr = (bgraph**)data;

	return actorname(*valptr);
}

bgraph*
GraphPtr_strvalfunc(char* data)
{
	return str2GraphPtr(data);
}

char*
Integer_valstrfunc(void* data)
{
	int32* valptr = (int32*)data;

	return int2str(*valptr);
}

int32
Integer_strvalfunc(char* data)
{
	return str2Integer(data);
}

char*
LabelPtr_valstrfunc(void* data)
{
	label** valptr = (label**)data;

	return actorname(*valptr);
}

label*
LabelPtr_strvalfunc(char* data)
{
	return str2LabelPtr(data);
}

char*
LoadPtr_valstrfunc(void* data)
{
	load** valptr = (load**)data;

	return actorname(*valptr);
}

load*
LoadPtr_strvalfunc(char* data)
{
	return str2LoadPtr(data);
}

char*
LoadList_valstrfunc(void* data)
{
	AMLoadList** valptr = (AMLoadList**)data;

	return AMLoadListToStr(*valptr);
}

char*
LoadTypePtr_valstrfunc(void* data)
{
	loadtype** valptr = (loadtype**)data;

	return actorname(*valptr);
}

loadtype*
LoadTypePtr_strvalfunc(char* data)
{
	return str2LoadTypePtr(data);
}

char*
Location_valstrfunc(void* data)
{
	simloc** valptr = (simloc**)data;

	return simlocname(*valptr);
}

simloc*
Location_strvalfunc(char* data)
{
	return str2Location(data);
}

char*
LocationList_valstrfunc(void* data)
{
	AMLocationList** valptr = (AMLocationList**)data;

	return AMLocationListToStr(*valptr);
}

char*
LocationTypePtr_valstrfunc(void* data)
{
	LocationType** valptr = (LocationType**)data;

	return actorname(*valptr);
}

LocationType*
LocationTypePtr_strvalfunc(char* data)
{
	return str2LocationTypePtr(data);
}

char*
LocationTypeList_valstrfunc(void* data)
{
	AMLocationTypeList** valptr = (AMLocationTypeList**)data;

	return AMLocationTypeListToStr(*valptr);
}

char*
MonitorPtr_valstrfunc(void* data)
{
	State_machine** valptr = (State_machine**)data;

	return actorname(*valptr);
}

State_machine*
MonitorPtr_strvalfunc(char* data)
{
	return str2MonitorPtr(data);
}

char*
MotorPtr_valstrfunc(void* data)
{
	ConvMotor** valptr = (ConvMotor**)data;

	return actorname(*valptr);
}

ConvMotor*
MotorPtr_strvalfunc(char* data)
{
	return str2MotorPtr(data);
}

char*
MotorList_valstrfunc(void* data)
{
	AMConvMotorList** valptr = (AMConvMotorList**)data;

	return AMConvMotorListToStr(*valptr);
}

char*
MotorTypePtr_valstrfunc(void* data)
{
	MotorType** valptr = (MotorType**)data;

	return actorname(*valptr);
}

MotorType*
MotorTypePtr_strvalfunc(char* data)
{
	return str2MotorTypePtr(data);
}

char*
MotorTypeList_valstrfunc(void* data)
{
	AMMotorTypeList** valptr = (AMMotorTypeList**)data;

	return AMMotorTypeListToStr(*valptr);
}

char*
OrderListPtr_valstrfunc(void* data)
{
	ordlist** valptr = (ordlist**)data;

	return actorname(*valptr);
}

ordlist*
OrderListPtr_strvalfunc(char* data)
{
	return str2OrderListPtr(data);
}

char*
PathPtr_valstrfunc(void* data)
{
	Path** valptr = (Path**)data;

	return actorname(*valptr);
}

Path*
PathPtr_strvalfunc(char* data)
{
	return str2PathPtr(data);
}

char*
PathList_valstrfunc(void* data)
{
	AMPathList** valptr = (AMPathList**)data;

	return AMPathListToStr(*valptr);
}

char*
PathTypePtr_valstrfunc(void* data)
{
	AgvPathType** valptr = (AgvPathType**)data;

	return actorname(*valptr);
}

AgvPathType*
PathTypePtr_strvalfunc(char* data)
{
	return str2PathTypePtr(data);
}

char*
PathTypeList_valstrfunc(void* data)
{
	AMAgvPathTypeList** valptr = (AMAgvPathTypeList**)data;

	return AMAgvPathTypeListToStr(*valptr);
}

char*
PhotoeyePtr_valstrfunc(void* data)
{
	Photoeye** valptr = (Photoeye**)data;

	return actorname(*valptr);
}

Photoeye*
PhotoeyePtr_strvalfunc(char* data)
{
	return str2PhotoeyePtr(data);
}

char*
PhotoeyeList_valstrfunc(void* data)
{
	AMPhotoList** valptr = (AMPhotoList**)data;

	return AMPhotoListToStr(*valptr);
}

char*
PhotoeyeTypePtr_valstrfunc(void* data)
{
	PhotoeyeType** valptr = (PhotoeyeType**)data;

	return actorname(*valptr);
}

PhotoeyeType*
PhotoeyeTypePtr_strvalfunc(char* data)
{
	return str2PhotoeyeTypePtr(data);
}

char*
PhotoeyeTypeList_valstrfunc(void* data)
{
	AMPhotoeyeTypeList** valptr = (AMPhotoeyeTypeList**)data;

	return AMPhotoeyeTypeListToStr(*valptr);
}

char*
ProcessPtr_valstrfunc(void* data)
{
	process** valptr = (process**)data;

	return actorname(*valptr);
}

process*
ProcessPtr_strvalfunc(char* data)
{
	return str2ProcessPtr(data);
}

char*
QueuePtr_valstrfunc(void* data)
{
	queue** valptr = (queue**)data;

	return actorname(*valptr);
}

queue*
QueuePtr_strvalfunc(char* data)
{
	return str2QueuePtr(data);
}

char*
QueueList_valstrfunc(void* data)
{
	AMQueueList** valptr = (AMQueueList**)data;

	return AMQueueListToStr(*valptr);
}

char*
Rate_valstrfunc(void* data)
{
	Rate* valptr = (Rate*)data;

	return rate2str(*valptr);
}

Rate
Rate_strvalfunc(char* data)
{
	return str2Rate(data);
}

char*
Real_valstrfunc(void* data)
{
	double* valptr = (double*)data;

	return double2str(*valptr);
}

double
Real_strvalfunc(char* data)
{
	return str2Real(data);
}

char*
ResourcePtr_valstrfunc(void* data)
{
	resource** valptr = (resource**)data;

	return actorname(*valptr);
}

resource*
ResourcePtr_strvalfunc(char* data)
{
	return str2ResourcePtr(data);
}

char*
ResourceList_valstrfunc(void* data)
{
	AMResourceList** valptr = (AMResourceList**)data;

	return AMResourceListToStr(*valptr);
}

char*
SchedJobPtr_valstrfunc(void* data)
{
	SchedJob** valptr = (SchedJob**)data;

	return actorname(*valptr);
}

SchedJob*
SchedJobPtr_strvalfunc(char* data)
{
	return str2SchedJobPtr(data);
}

char*
SchedJobList_valstrfunc(void* data)
{
	AMSchedJobList** valptr = (AMSchedJobList**)data;

	return AMSchedJobListToStr(*valptr);
}

char*
SectionPtr_valstrfunc(void* data)
{
	ConvSection** valptr = (ConvSection**)data;

	return actorname(*valptr);
}

ConvSection*
SectionPtr_strvalfunc(char* data)
{
	return str2SectionPtr(data);
}

char*
SectionList_valstrfunc(void* data)
{
	AMConvSectionList** valptr = (AMConvSectionList**)data;

	return AMConvSectionListToStr(*valptr);
}

char*
SectionTypePtr_valstrfunc(void* data)
{
	ConvSectionType** valptr = (ConvSectionType**)data;

	return actorname(*valptr);
}

ConvSectionType*
SectionTypePtr_strvalfunc(char* data)
{
	return str2SectionTypePtr(data);
}

char*
SectionTypeList_valstrfunc(void* data)
{
	AMConvSectionTypeList** valptr = (AMConvSectionTypeList**)data;

	return AMConvSectionTypeListToStr(*valptr);
}

char*
SocketPtr_valstrfunc(void* data)
{
	amSocket** valptr = (amSocket**)data;

	return amsocketname(*valptr);
}

amSocket*
SocketPtr_strvalfunc(char* data)
{
	return str2SocketPtr(data);
}

char*
StatePtr_valstrfunc(void* data)
{
	States** valptr = (States**)data;

	return actorname(*valptr);
}

States*
StatePtr_strvalfunc(char* data)
{
	return str2StatePtr(data);
}

char*
StreamPtr_valstrfunc(void* data)
{
	rnstream** valptr = (rnstream**)data;

	return actorname(*valptr);
}

rnstream*
StreamPtr_strvalfunc(char* data)
{
	return str2StreamPtr(data);
}

char*
String_valstrfunc(void* data)
{
	char** valptr = (char**)data;

	return VALIDSTRING(*valptr);
}

char*
String_strvalfunc(char* data)
{
	return str2String(data);
}

char*
StringList_valstrfunc(void* data)
{
	AMStringList** valptr = (AMStringList**)data;

	return AMStringListToStr(*valptr);
}

char*
SystemPtr_valstrfunc(void* data)
{
	System** valptr = (System**)data;

	return systemname(*valptr);
}

System*
SystemPtr_strvalfunc(char* data)
{
	return str2SystemPtr(data);
}

char*
TablePtr_valstrfunc(void* data)
{
	table** valptr = (table**)data;

	return actorname(*valptr);
}

table*
TablePtr_strvalfunc(char* data)
{
	return str2TablePtr(data);
}

char*
Time_valstrfunc(void* data)
{
	ASITime* valptr = (ASITime*)data;

	return time2str(*valptr);
}

ASITime
Time_strvalfunc(char* data)
{
	return str2Time(data);
}

char*
TransferPtr_valstrfunc(void* data)
{
	ConvTransfer** valptr = (ConvTransfer**)data;

	return actorname(*valptr);
}

ConvTransfer*
TransferPtr_strvalfunc(char* data)
{
	return str2TransferPtr(data);
}

char*
TransferTypePtr_valstrfunc(void* data)
{
	TransferType** valptr = (TransferType**)data;

	return actorname(*valptr);
}

TransferType*
TransferTypePtr_strvalfunc(char* data)
{
	return str2TransferTypePtr(data);
}

char*
VehiclePtr_valstrfunc(void* data)
{
	vehicle** valptr = (vehicle**)data;

	return actorname(*valptr);
}

vehicle*
VehiclePtr_strvalfunc(char* data)
{
	return str2VehiclePtr(data);
}

char*
VehicleList_valstrfunc(void* data)
{
	AMVehicleList** valptr = (AMVehicleList**)data;

	return AMVehicleListToStr(*valptr);
}

char*
VehSegPtr_valstrfunc(void* data)
{
	VehSeg** valptr = (VehSeg**)data;

	return actorname(*valptr);
}

VehSeg*
VehSegPtr_strvalfunc(char* data)
{
	return str2VehSegPtr(data);
}

char*
VehSegList_valstrfunc(void* data)
{
	AMVehSegList** valptr = (AMVehSegList**)data;

	return AMVehSegListToStr(*valptr);
}

char*
Velocity_valstrfunc(void* data)
{
	Velocity* valptr = (Velocity*)data;

	return velocity2str(*valptr);
}

Velocity
Velocity_strvalfunc(char* data)
{
	return str2Velocity(data);
}

ImplementList(_CounterList, counter*, NULL);

char*
CounterList_valstrfunc(void* data)
{
	AM_CounterList** valptr = (AM_CounterList**)data;

	return AM_CounterListToStr(*valptr);
}
