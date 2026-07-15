// user.h
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


#ifndef __USER_H__
#define __USER_H__

#include "amc2.h"

FILE** Getimpstdin();
extern FILE** imp_stdin;
#undef stdin
#define stdin (*imp_stdin)
FILE** Getimpstdout();
extern FILE** imp_stdout;
#undef stdout
#define stdout (*imp_stdout)
FILE** Getimpstderr();
extern FILE** imp_stderr;
#undef stderr
#define stderr (*imp_stderr)
struct process_system** Getimpheadpt();
extern struct process_system** imp_headpt;
#undef headpt
#define headpt (*imp_headpt)
struct AMLoadList* Getimpactiveloads();
extern struct AMLoadList* imp_activeloads;
#undef activeloads
#define activeloads (*imp_activeloads)
struct model_header** Getimpmodel();
extern struct model_header** imp_model;
#undef model
#define model (*imp_model)
FILE** Getimptfp();
extern FILE** imp_tfp;
#undef tfp
#define tfp (*imp_tfp)
FILE** Getimprfp();
extern FILE** imp_rfp;
#undef rfp
#define rfp (*imp_rfp)
FILE** Getimppfp();
extern FILE** imp_pfp;
#undef pfp
#define pfp (*imp_pfp)
int32* Getimptrace();
extern int32* imp_trace;
#undef trace
#define trace (*imp_trace)
int32* Getimpanimate();
extern int32* imp_animate;
#undef animate
#define animate (*imp_animate)
int32* GetimpAnimating();
extern int32* imp_Animating;
#undef Animating
#define Animating (*imp_Animating)
unsigned long* Getimpchangeflag();
extern unsigned long* imp_changeflag;
#undef changeflag
#define changeflag (*imp_changeflag)
int32* GetimpEnableBeaming();
extern int32* imp_EnableBeaming;
#undef EnableBeaming
#define EnableBeaming (*imp_EnableBeaming)
Time* GetimpASIclock();
extern Time* imp_ASIclock;
#undef ASIclock
#define ASIclock (*imp_ASIclock)
Time* Getimpbeginper();
extern Time* imp_beginper;
#undef beginper
#define beginper (*imp_beginper)
Boolean* GetimpSIMULATOR();
extern Boolean* imp_SIMULATOR;
#undef SIMULATOR
#define SIMULATOR (*imp_SIMULATOR)
struct AMEventNoticeList** Getimpcel();
extern struct AMEventNoticeList** imp_cel;
#undef cel
#define cel (*imp_cel)
struct eventlist* Getimpfel();
extern struct eventlist* imp_fel;
#undef fel
#define fel (*imp_fel)
struct dlogItem** Getimpgrf_sl();
extern struct dlogItem** imp_grf_sl;
#undef grf_sl
#define grf_sl (*imp_grf_sl)
struct s_menu** Getimppopmenu();
extern struct s_menu** imp_popmenu;
#undef popmenu
#define popmenu (*imp_popmenu)
ASIWindow* GetimpWORKMENU();
extern ASIWindow* imp_WORKMENU;
#undef WORKMENU
#define WORKMENU (*imp_WORKMENU)
ASIWindow* GetimpSimLotStatusWin();
extern ASIWindow* imp_SimLotStatusWin;
#undef SimLotStatusWin
#define SimLotStatusWin (*imp_SimLotStatusWin)
ASIWindow* GetimpSimStnStatusWin();
extern ASIWindow* imp_SimStnStatusWin;
#undef SimStnStatusWin
#define SimStnStatusWin (*imp_SimStnStatusWin)
ASIWindow* GetimpSimOperStatusWin();
extern ASIWindow* imp_SimOperStatusWin;
#undef SimOperStatusWin
#define SimOperStatusWin (*imp_SimOperStatusWin)
ASIWindow* GetimpSimInvStatusWin();
extern ASIWindow* imp_SimInvStatusWin;
#undef SimInvStatusWin
#define SimInvStatusWin (*imp_SimInvStatusWin)
ASIWindow* GetimpSimKanbanStatusWin();
extern ASIWindow* imp_SimKanbanStatusWin;
#undef SimKanbanStatusWin
#define SimKanbanStatusWin (*imp_SimKanbanStatusWin)
#ifdef VISUALC
#define MODELDLLEXPORT __declspec(dllexport)
#else
#define MODELDLLEXPORT
#endif // VISUALC
DeclareList(_CounterList, counter*,);
#define AM_CounterListItemCopy(item1, item2) item1 = item2
#define AM_CounterListItemEqual(item1, item2) (item1 == item2)
#define AM_CounterListItemRemove(item) /* empty */
#define AM_CounterListItemToStr(item) actorname(item)

typedef struct loadatt {
	struct {
		int32 am_anVehicleType;	/* anVehicleType */
		int32 am_aID;	/* aID */
		int32 am_aAssign;	/* aAssign */
		int32 am_aParkBay;	/* aParkBay */
		ASITime am_atRetStart;	/* atRetStart */
		int32 am_anLoadType;	/* anLoadType */
		ASITime am_atUnload;	/* atUnload */
		int32 am_alocToBay;	/* alocToBay */
		int32 am_alocFromBay;	/* alocFromBay */
		AMLocationList* am_aRoute_FromLoc;	/* aRoute_FromLoc */
		simloc* am_alocFrom;	/* alocFrom */
		ASITime am_atLoad;	/* atLoad */
		int32 am_anTransfer;	/* anTransfer */
		simloc* am_alocStorage;	/* alocStorage */
		ASITime am_atTR;	/* atTR */
		ASITime am_atAssign;	/* atAssign */
		ASITime am_atAssignInit;	/* atAssignInit */
		Distance am_vhlRetDistance;	/* vhlRetDistance */
		vehicle* am_avDispatch;	/* avDispatch */
		simloc* am_alocPark;	/* alocPark */
		int32 am_anRoute;	/* anRoute */
		ASITime am_atInitialCreated;	/* atInitialCreated */
		double am_arTimeGap;	/* arTimeGap */
		ASITime am_atAfterTimeGap;	/* atAfterTimeGap */
		ASITime am_atCreate;	/* atCreate */
		Distance am_aDistance;	/* aDistance */
		Distance am_aRetDistance;	/* aRetDistance */
		AMLocationList* am_aRoute_ToLoc;	/* aRoute_ToLoc */
		simloc* am_alocTo;	/* alocTo */
		Distance am_aDelDistance;	/* aDelDistance */
		Distance am_aTotDistance;	/* aTotDistance */
		int32 am_aiAssignCount;	/* aiAssignCount */
		int32 am_anTemp1;	/* anTemp1 */
		ASITime am_atConvIn[3];	/* atConvIn */
		ASITime am_atConvOut[3];	/* atConvOut */
		ASITime am_atConv[3];	/* atConv */
		ASITime am_atInLoadCome;	/* atInLoadCome */
		ASITime am_atInLoadGo;	/* atInLoadGo */
		ASITime am_atOutLoadCome;	/* atOutLoadCome */
		ASITime am_atOutLoadGo;	/* atOutLoadGo */
		ASITime am_atOutLoad;	/* atOutLoad */
		ASITime am_atInLoad;	/* atInLoad */
		simloc* am_alocConvFrom;	/* alocConvFrom */
		simloc* am_alocConvTo;	/* alocConvTo */
		int32 am_ai;	/* ai */
		int32 am_anDeliverType;	/* anDeliverType */
		int32 am_aQnum;	/* aQnum */
		int32 am_aj;	/* aj */
		char* am_asTemp_PN;	/* asTemp_PN */
		int32 am_aiTemp_EQnum;	/* aiTemp_EQnum */
		simloc* am_alocOut;	/* alocOut */
		int32 am_anStart;	/* anStart */
		int32 am_aiUTBnum;	/* aiUTBnum */
		int32 am_aiHotLot;	/* aiHotLot */
		int32 am_aiHotLotEQ;	/* aiHotLotEQ */
		char* am_asCanCap;	/* asCanCap */
		int32 am_aAlt;	/* aAlt */
		ASITime am_atEnterLoss;	/* atEnterLoss */
		ASITime am_atOutLoss;	/* atOutLoss */
		ASITime am_atServiceEnd;	/* atServiceEnd */
		ASITime am_atFinalBuffer;	/* atFinalBuffer */
		ASITime am_atServiceIn;	/* atServiceIn */
		char* am_aDefine;	/* aDefine */
		int32 am_aiPortZone;	/* aiPortZone */
		int32 am_aiLossNum;	/* aiLossNum */
		int32 am_aiDelay;	/* aiDelay */
		int32 am_aiSearchCount;	/* aiSearchCount */
		int32 am_aiOL;	/* aiOL */
		int32 am_aiLocAssigned;	/* aiLocAssigned */
		int32 am_aiRandom;	/* aiRandom */
		int32 am_aiBoxOut;	/* aiBoxOut */
		ASITime am_atEnterToOut;	/* atEnterToOut */
		int32 am_aiCheck;	/* aiCheck */
		int32 am_aiYellow;	/* aiYellow */
		int32 am_aiPreMove;	/* aiPreMove */
		int32 am_aiLine;	/* aiLine */
		int32 am_aiDeliverType;	/* aiDeliverType */
		simloc* am_alocToTwin;	/* alocToTwin */
		int32 am_aiLocChange;	/* aiLocChange */
		simloc* am_alocConv[11];	/* alocConv */
		int32 am_aiPort;	/* aiPort */
		int32 am_aiCounterNum;	/* aiCounterNum */
		int32 am_aiUTBtoEQ;	/* aiUTBtoEQ */
		int32 am_aiSTKtoEQ;	/* aiSTKtoEQ */
		int32 am_aiBox;	/* aiBox */
		int32 am_anDummy;	/* anDummy */
		ASITime am_atDelayed[17];	/* atDelayed */
		int32 am_aUTBName;	/* aUTBName */
		double am_A_cgStopDelay;	/* A_cgStopDelay */
		double am_A_cgStopOccur;	/* A_cgStopOccur */
		double am_A_cgStopTotalDelay;	/* A_cgStopTotalDelay */
		vehicle* am_A_cgStopVeh;	/* A_cgStopVeh */
		char* am_alocToA;	/* alocToA */
		ASITime am_atEQEmpty;	/* atEQEmpty */
		int32 am_aRandom;	/* aRandom */
		int32 am_anGapType;	/* anGapType */
		int32 am_aiSteering;	/* aiSteering */
		int32 am_aiSteerChange;	/* aiSteerChange */
		int32 am_aiLineStart[11];	/* aiLineStart */
		double am_arSetDownTime;	/* arSetDownTime */
	} am_model;
} loadatt;

#define ValidIndex(NAME, INDEX, MAXINDEX) validindex(NAME, INDEX, MAXINDEX)
#define ValidPtr(VALUE, KIND, CAST) ((CAST)validptr(VALUE, KIND))

#endif // __USER_H__
