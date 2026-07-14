VERSION 12.6.1.12
SYSTYPE Process
UNITS Millimeters Seconds
SYSDEF UtilByAvail off RefCheck on debugger on warningMessages off report standard
FLAGS
	System Inherit
	Text Red
	Resources Inherit
	Resource Names Invisible Red
	Queues Inherit
	Queue Names Red
	Queue Amounts Invisible Red
	Blocks Invisible Inherit
	Block Names Invisible Red
	Labels Red
PROCDEF UserId 1
TYPE name CounterList TYPEtype list CounterPtr
	CTYPE "AM_CounterList*"
	TYPE2STRING "AM_CounterListToStr"
PROC name pDispatch 0 traf Infinite
PROC name pReAssign 0 traf Infinite
PROC name pCreate 0 traf Infinite
PROC name pMakeRoute 0 traf Infinite
PROC name pMove 0 traf Infinite
PROC name pExit 0 traf Infinite
PROC name pSTK_Arrived 0 traf Infinite
PROC name pSTK 0 traf Infinite
PROC name pEQPortZone 0 traf Infinite
PROC name pEQZone 0 traf Infinite
PROC name pSTKtoUTB 0 traf Infinite
PROC name pUTBtoEQ 0 traf Infinite
PROC name pSTKtoEQ 0 traf Infinite
PROC name pPark_Check 0 traf Infinite
PROC name pDistribution 3 traf Infinite nextproc die
PROC name pIns 0 traf Infinite
PROC name pPSo 0 traf Infinite
PROC name pMSo 0 traf Infinite
PROC name pUTB_Util 0 traf Infinite
PROC name pUTBinit 0 traf Infinite
PROC name pUTB_Selection 0 traf Infinite
PROC name pEQZoneBefore 0 traf Infinite
PROC name pUTB_Selection2 0 traf Infinite
PROC name pBlockCount 0 traf Infinite
PROC name pEQBufferCheck 0 traf Infinite
PROC name pInsertToUTB 0 traf Infinite
LDTYPE name lLarge 0
picpos begx -3358 begy 75138 endx -3357 endy 75138 scx 400 scy 400 scz 400
 color 4 template Millimeters
700 17
4 4 0 1 1 none
1
310 0
1 1 1 1 1 0 0
end
LDTYPE name lTRAY 0
picpos endx 1
 template Millimeters
700 17
2 2 0 1 1 none
1
310 0
1 1 1 1 1 0 0
end
LDTYPE name lSmall 0
picpos begx -2639 begy 75130 endx -2638 endy 75130 scx 300 scy 300 scz 300
 color 1 template Millimeters
700 17
1 1 0 1 1 none
1
310 0
1 1 1 1 1 0 0
end
LDTYPE name lCreate 0
picpos begx -346489.984 begy 124059.992 begz 2800 endx -346488.984 endy 124059.992 endz 2800 scx 400 scy 400 scz 400
 color 4 template Millimeters
700 17
4 4 0 1 1 none
1
310 0
1 1 1 1 1 0 0
end
		create con 0 Seconds stream stream_lCreate_1 foa con 0 Seconds stream stream_lCreate_1 First pCreate 0 Limit 1
		create con 0 Seconds stream stream_lCreate_2 foa con 0 Seconds stream stream_lCreate_2 First pDispatch 0 Limit 1
		create con 0.5 Seconds stream stream_lCreate_3 foa con 0 Seconds stream stream_lCreate_3 First pReAssign 0 Limit 1
		create con 0 Seconds stream stream_lCreate_4 First pPark_Check 0 Limit 1
		create con 0 Seconds stream stream_lCreate_5 First pBlockCount 0 Limit 1
LDTYPE name lSSmall 0
picpos begx -1985 begy 75072 endx -1984 endy 75072 scx 400 scy 350 scz 300
 color 1 template Millimeters
700 17
1 1 0 1 1 none
1
310 0
1 1 1 1 1 0 0
end
LDTYPE name lEMT 0
picpos begx -1245 begy 75106 endx -1244 endy 75106 scx 300 scy 300 scz 300
 color 72 template Millimeters
700 17
72 72 0 1 1 none
1
310 0
1 1 1 1 1 0 0
end
LDTYPE name L_UTB 0
picpos endx 1
 template Millimeters
700 17
2 2 0 1 1 none
1
310 0
1 1 1 1 1 0 0
end
		create con 0 Seconds stream stream_L_UTB_1 foa con 0 Seconds stream stream_L_UTB_1 First pUTB_Util 0 Limit 1
RSRC name rOHT 0 cap 2147483647 prtime con 5 Seconds stream stream_rOHT_1

	UserDef
		
QUEUE name qDisable 0 cap 2147483647

	UserDef

QUEUE name qStorage 0 cap 2147483647

	UserDef

QUEUE name qSpace 0 cap 2147483647

	UserDef

QUEUE name Q_STKL 10 cap 2147483647
	color 1 7
	color 2 7
	color 3 7
	color 4 7
	color 5 7
	color 6 7
	color 7 7
	color 8 7
	color 9 7
	color 10 7

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name qSTK_Arrived 10 cap 2147483647

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name qSTK_ToGo 10 cap 2147483647

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name Q_STKS 10 cap 2147483647
	color 1 7
	color 2 7
	color 3 7
	color 4 7
	color 5 7
	color 6 7

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name Qstart 0 cap 2147483647

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name Qstart2 0 cap 2147483647

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name Q_STKEVL 10 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name Q_STKEVS 5 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name interface 200 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name qBayUTB 0 cap 2147483647

	UserDef

QUEUE name Ins 500 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name MS 500 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name PS 500 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name m_CanCap 200 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name Q_UTB 16 cap 5
	color 1 36
	color 2 36
	color 3 36
	color 4 36
	color 5 36
	color 6 1
	color 7 1
	color 8 1
	color 9 36
	color 10 36
	color 11 4
	color 12 4
	color 13 4
	color 14 4
	color 15 36
	color 16 36

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name qComplete 0 cap 2147483647

	UserDef

QUEUE name Q_Port 36 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end

QUEUE name Queue1 0 cap 1

	UserDef

QUEUE name qInfinite 0 cap 2147483647

	UserDef

LABEL name lblName 0
LABEL name Wall 0
LABEL name Label1 0
LABEL name lblOHT 0
 dis 0 picpos begx -308784 begy 208860.992 endx -308783 endy 208860.992 scx 3000 scy 3000 scz 100

	UserDef color 14	template Millimeters
140 49
14 14 0 1 1 Label
num OHT : 
end
LABEL name lblvnCapa 0
 dis 0 picpos begx -308525.024 begy 214994.992 endx -308524.024 endy 214994.992 scx 3000 scy 3000 scz 100

	UserDef color 15	template Millimeters
140 49
15 15 0 1 1 Label
Capa :
end
LABEL name Label2 0
LABEL name Label3 0
 dis 0 picpos begx -308209.024 begy 224588 endx -308208.024 endy 224588 scx 4000 scy 4000 scz 100

	UserDef color 74	template Millimeters
140 49
74 74 0 1 1 Label
Stack 1, 2_UTB
end
LABEL name Facil 10
LABEL name lUtil 0
LABEL name lDelDis 0
 dis 0 picpos begx -309263.008 begy 202422.992 endx -309262.008 endy 202422.992 scx 3000 scy 3000 scz 100

	UserDef color 53	template Millimeters
140 49
53 53 0 1 1 Label
Del Distance:
end
LABEL name lRet 0
 dis 0 picpos begx -309116 begy 196970.992 endx -309115 endy 196970.992 scx 3000 scy 3000 scz 100

	UserDef color 0	template Millimeters
140 49
0 0 0 1 1 Label
Ret
end
LABEL name lDel 0
 dis 0 picpos begx -309116 begy 191520 endx -309115 endy 191520 scx 3000 scy 3000 scz 100

	UserDef color 0	template Millimeters
140 49
0 0 0 1 1 Label
Del
end
LABEL name lGPark 0
 dis 0 picpos begx -309116 begy 186214.992 endx -309115 endy 186214.992 scx 3000 scy 3000 scz 100

	UserDef color 0	template Millimeters
140 49
0 0 0 1 1 Label
Going to Park
end
LABEL name lPark 0
 dis 0 picpos begx -308527.008 begy 180910.992 endx -308526.008 endy 180910.992 scx 3000 scy 3000 scz 100

	UserDef color 0	template Millimeters
140 49
0 0 0 1 1 Label
Park
end
LABEL name lParkCount 0
 dis 0 picpos begx -213639.008 begy 193312.992 endx -213638.008 endy 193312.992 scx 3000 scy 3000 scz 10

	UserDef color 7	template Millimeters
140 49
7 7 0 1 1 Label
ParkCapa
end
LABEL name Label4 0
 dis 0 picpos begx -242839.008 begy 218996 endx -242838.008 endy 218996 scx 3000 scy 3000

	UserDef color 2	template Millimeters
140 49
2 2 0 1 1 Label
Storage Ratio ver
end
ORDER name ol_Disable 0
ORDER name OLwaiting 1000
ORDER name OL_Small 20
ORDER name OL_EVS 20
ORDER name OL_OHT 20
ORDER name OL_Ins 0
ORDER name OL_PSocket 0
ORDER name OL_MSocket 0
ORDER name OL_UTB 200
ORDER name OLInfinite 0
BLOCK name STK_EVL 10 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end
BLOCK name N_HWif 300 cap 1

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end
BLOCK name Block1 4 cap 2147483647
 dis 1 picpos begx 270077.984 begy -15617 endx 270078.984 endy -15617 scx 6000 scy 3500
 dis 2 picpos begx 249857.984 begy -15706 endx 249858.984 endy -15706 scx 3900 scy 3500
 dis 3 picpos begx 231713.984 begy -15698 endx 231714.984 endy -15698 scx 5000 scy 3500
 dis 4 picpos begx 209574.992 begy -15698 endx 209575.992 endy -15698 scx 6000 scy 3500

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end
BLOCK name UsageCnt 30 cap 2147483647
 dis 1 picpos begx 294926.016 begy -37365 endx 294927.016 endy -37365 scx 4734.99989440338 scy 11965.9998328598
 dis 2 picpos begx 242532 begy -28450 endx 242533 endy -28450 scx 19435.9995883927 scy 2892
 dis 3 picpos begx 244010 begy -17190 endx 244011 endy -17190 scx 19864 scy 2046

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end
BLOCK name B_STKZone 0 cap 2147483647
 dis 0 picpos begx 279179.008 begy 147143.008 endx 279180.008 endy 147143.008 scx 69999.9981714286 scy 2000 scz 3000

	UserDef	template Millimeters
700 17
2 2 0 1 1 none
1
310 17
2 2 0 1 0 none
4 4 4 4 4 0 0
end
BLOCK name B_OHT_Restriction 100 cap 1
 dis 1 picpos begx -89710 begy -31994 endx -89709 endy -31994 scx 200 scy 700 scz 100
 dis 2 picpos begx -94239 begy -31837 endx -94238 endy -31837 scx 200 scy 700 scz 100
 dis 3 picpos begx -60675 begy -33096 endx -60674 endy -33096 scx 200 scy 300 scz 100
 dis 4 picpos begx -48507 begy -33115 endx -48506 endy -33115 scx 200 scy 300 scz 100
 dis 5 picpos begx -38307 begy -33104 endx -38306 endy -33104 scx 200 scy 300 scz 100
 dis 6 picpos begx -36181 begy -33133 endx -36180 endy -33133 scx 200 scy 300 scz 100
 dis 7 picpos begx -56609 begy -89106 endx -56608 endy -89106 scx 200 scy 350 scz 100
 dis 8 picpos begx -52525 begy -89171 endx -52524 endy -89171 scx 200 scy 350 scz 100
 dis 9 picpos begx -12369 begy -89158 endx -12368 endy -89158 scx 200 scy 350 scz 100
 dis 10 picpos begx -94414 begy -87508 endx -94413 endy -87508 scx 200 scy 300
 dis 11 picpos begx -95745 begy -89175 endx -95744 endy -89175 scx 150 scy 600
 dis 12 picpos begx -96861 begy -89632 endx -96860 endy -89632 scx 150 scy 850 scz 100
 dis 13 picpos begx -62184 begy -34603 endx -62183 endy -34603 scx 200 scy 300 scz 100
 dis 14 picpos begx -31917 begy -34819 endx -31916 endy -34819 scx 300 scy 200 scz 100
 dis 15 picpos begx -66415 begy -36799 endx -66414 endy -36799 scx 200 scy 600 scz 100
 dis 17 picpos begx -79765 begy -34907 endx -79764 endy -34907 scx 250 scy 200 scz 100
 dis 18 picpos begx -99697 begy -18660 endx -99696 endy -18660 scx 200 scy 250 scz 100
 dis 19 picpos begx -96886 begy -19799 endx -96885 endy -19799 scx 200 scy 250 scz 100
 dis 20 picpos begx -113418 begy -22317 endx -113417 endy -22317 scx 250 scy 200 scz 100
 dis 21 picpos begx -44769 begy -15231 endx -44768 endy -15231 scx 200 scy 250 scz 100
 dis 22 picpos begx -39304 begy -19076 endx -39303 endy -19076 scx 200 scy 250 scz 100
 dis 23 picpos begx -31834 begy -19818 endx -31833 endy -19818 scx 200 scy 250 scz 100
 dis 24 picpos begx -17295 begy -18763 endx -17294 endy -18763 scx 200 scy 250 scz 100
 dis 25 picpos begx -21827 begy -19224 endx -21826 endy -19224 scx 200 scy 250 scz 100
 dis 26 picpos begx -23148 begy -17975 endx -23147 endy -17975 scx 200 scy 250 scz 1000
 dis 27 picpos begx -66713 begy -79316 endx -66712 endy -79316 scx 250 scy 200 scz 100
 dis 29 picpos begx -69288 begy -88308 endx -69287 endy -88308 scx 200 scy 250 scz 100
 dis 30 picpos begx -21527 begy -31981 endx -21526 endy -31981 scx 250 scy 200 scz 100
 dis 31 picpos begx -20901 begy -26163 endx -20900 endy -26163 scx 200 scy 100 scz 100
 dis 32 picpos begx -77119 begy -90334 endx -77118 endy -90334 scx 200 scy 250 scz 100
 dis 33 picpos begx -68172 begy -91193 endx -68171 endy -91193 scx 200 scy 250 scz 100
 dis 34 picpos begx -50229 begy -90403 endx -50228 endy -90403 scx 200 scy 250 scz 100
 dis 35 picpos begx -43491 begy -90436 endx -43490 endy -90436 scx 200 scy 250 scz 100
 dis 36 picpos begx -34871 begy -89239 endx -34870 endy -89239 scx 250 scy 200 scz 100
 dis 37 picpos begx -99485 begy -87152 endx -99484 endy -87152 scx 200 scy 250 scz 100
 dis 38 picpos begx -25413 begy -88330 endx -25412 endy -88330 scx 200 scy 250 scz 100
 dis 39 picpos begx -23004 begy -91140 endx -23003 endy -91140 scx 200 scy 250 scz 100
 dis 40 picpos begx -21794 begy -79157 endx -21793 endy -79157 scx 250 scy 200 scz 100

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end
BLOCK name B_TrafficCheck 10 cap 2147483647
 dis 1 picpos begx -139163.008 begy -44076 endx -139162.008 endy -44076 scx 871 scy 741 scz 100

	UserDef	template Millimeters
700 17
-1 -1 0 1 1 none
1
310 17
-1 -1 0 1 0 none
4 4 4 4 4 0 0
end
BLOCK name Block190 0 cap 1
	color 0 11

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block141 0 cap 1
	color 0 11
 dis 0 picpos begx -87452.584 begy -34105.52 endx -87452.5840001192 endy -34104.52 scx 170.000017233455 scy 228.000034265348 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block169 0 cap 1
	color 0 11
 dis 0 picpos begx -56517.352 begy -34237.416 endx -56516.352 endy -34237.416 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block194 0 cap 1
	color 0 12
 dis 0 picpos begx -112406.896 begy -19850.164 endx -112407.896 endy -19850.1640002384 scx 169.999971277571 scy 455.999965734648 scz 0.100000003539026

	UserDef	template Millimeters
700 17
12 12 0 1 1 none
1
310 17
12 12 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block377 0 cap 1
	color 0 6
 dis 0 picpos begx -85541.968 begy -29983.418 endx -85540.968 endy -29983.418 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
6 6 0 1 1 none
1
310 17
6 6 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block199 0 cap 1
	color 0 14
 dis 0 picpos begx -104324.968 begy -34793.956 endx -104323.968 endy -34793.956 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
14 14 0 1 1 none
1
310 17
14 14 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block325 0 cap 1
	color 0 11
 dis 0 picpos begx -46220.384 begy -34192.416 endx -46219.384 endy -34192.416 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block96 0 cap 1
	color 0 14
 dis 0 picpos begx -113410.968 begy -36576.616 endx -113409.968 endy -36576.616 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
14 14 0 1 1 none
1
310 17
14 14 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block51 0 cap 1
	color 0 3
 dis 0 picpos begx -75937.968 begy -18115.396 endx -75936.968 endy -18115.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
3 3 0 1 1 none
1
310 17
3 3 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block256 0 cap 1
	color 0 5
 dis 0 picpos begx -21499.96 begy -44752.416 endx -21498.96 endy -44752.416 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
5 5 0 1 1 none
1
310 17
5 5 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block165 0 cap 1
	color 0 13
 dis 0 picpos begx -119442 begy -33932 endx -119441.99999994 endy -33931 scx 499.999937499996 scy 169.999954044111 scz 0.100000003539026

	UserDef	template Millimeters
700 17
13 13 0 1 1 none
1
310 17
13 13 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block121 0 cap 1
	color 0 13
 dis 0 picpos begx -66552.968 begy -19178.036 endx -66551.968 endy -19178.036 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
13 13 0 1 1 none
1
310 17
13 13 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block94 0 cap 1
	color 0 13
 dis 0 picpos begx -65388.964 begy -57519.62 endx -65387.964 endy -57519.62 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
13 13 0 1 1 none
1
310 17
13 13 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block214 0 cap 1
	color 0 5
 dis 0 picpos begx -66207.968 begy -56273.52 endx -66206.968 endy -56273.52 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
5 5 0 1 1 none
1
310 17
5 5 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block43 0 cap 1
	color 0 5
 dis 0 picpos begx -89927.968 begy -33691.928 endx -89926.968 endy -33691.928 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
5 5 0 1 1 none
1
310 17
5 5 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block78 0 cap 1
	color 0 4
 dis 0 picpos begx -65066.968 begy -87550.824 endx -65065.968 endy -87550.824 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
4 4 0 1 1 none
1
310 17
4 4 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block84 0 cap 1
	color 0 12
 dis 0 picpos begx -59469.384 begy -91098.808 endx -59468.384 endy -91098.808 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
12 12 0 1 1 none
1
310 17
12 12 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block26 0 cap 1
	color 0 3
 dis 0 picpos begx -86834.472 begy -17587.396 endx -86833.472 endy -17587.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
3 3 0 1 1 none
1
310 17
3 3 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block378 0 cap 1
	color 0 14
 dis 0 picpos begx -36157.96 begy -17544.66 endx -36156.96 endy -17544.66 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
14 14 0 1 1 none
1
310 17
14 14 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block371 0 cap 1
	color 0 11
 dis 0 picpos begx -59024.24 begy -18213.456 endx -59023.24 endy -18213.456 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block247 0 cap 1
	color 0 3
 dis 0 picpos begx -55967.96 begy -19081.396 endx -55966.96 endy -19081.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
3 3 0 1 1 none
1
310 17
3 3 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block401 0 cap 1
	color 0 3
 dis 0 picpos begx -97570.792 begy -34908.928 endx -97569.792 endy -34908.928 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
3 3 0 1 1 none
1
310 17
3 3 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block418 0 cap 1
	color 0 3
 dis 0 picpos begx -80168.224 begy -19786.396 endx -80167.224 endy -19786.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
3 3 0 1 1 none
1
310 17
3 3 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block138 0 cap 1
	color 0 14
 dis 0 picpos begx -21396.96 begy -38079.236 endx -21395.96 endy -38079.236 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
14 14 0 1 1 none
1
310 17
14 14 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block290 0 cap 1
	color 0 4
 dis 0 picpos begx -20340.968 begy -87703.824 endx -20339.968 endy -87703.824 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
4 4 0 1 1 none
1
310 17
4 4 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block339 0 cap 1
	color 0 3
 dis 0 picpos begx -60516.384 begy -18520.396 endx -60515.384 endy -18520.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
3 3 0 1 1 none
1
310 17
3 3 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block15 0 cap 1
	color 0 11
 dis 0 picpos begx -106964.896 begy -42985.928 endx -106963.896 endy -42985.928 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block91 0 cap 1
	color 0 12
 dis 0 picpos begx -62209.216 begy -17556.972 endx -62208.216 endy -17556.972 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
12 12 0 1 1 none
1
310 17
12 12 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block115 0 cap 1
	color 0 4
 dis 0 picpos begx -75898.4 begy -87012.824 endx -75897.4 endy -87012.824 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
4 4 0 1 1 none
1
310 17
4 4 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block133 0 cap 1
	color 0 4
 dis 0 picpos begx -31029.576 begy -87082.824 endx -31028.576 endy -87082.824 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
4 4 0 1 1 none
1
310 17
4 4 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block158 0 cap 1
	color 0 11
 dis 0 picpos begx -49021.152 begy -19844.456 endx -49020.152 endy -19844.456 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block375 0 cap 1
	color 0 12
 dis 0 picpos begx -62433.42 begy -37500.988 endx -62432.42 endy -37500.988 scx 170 scy 570 scz 0.100000003539026

	UserDef	template Millimeters
700 17
12 12 0 1 1 none
1
310 17
12 12 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block405 0 cap 1
	color 0 3
 dis 0 picpos begx -94923.824 begy -29966.926 endx -94922.824 endy -29966.926 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
3 3 0 1 1 none
1
310 17
3 3 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block287 0 cap 1
	color 0 12
 dis 0 picpos begx -15811.288 begy -91153.808 endx -15810.288 endy -91153.808 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
12 12 0 1 1 none
1
310 17
12 12 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block283 0 cap 1
	color 0 11
 dis 0 picpos begx 11687.617 begy -35171.808 endx 11688.617 endy -35171.808 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block12 0 cap 1
	color 0 12
 dis 0 picpos begx -109522.8 begy -30050.926 endx -109521.8 endy -30050.926 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
12 12 0 1 1 none
1
310 17
12 12 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block383 0 cap 1
	color 0 4
 dis 0 picpos begx -87520.976 begy -18998.396 endx -87519.976 endy -18998.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
4 4 0 1 1 none
1
310 17
4 4 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block162 0 cap 1
	color 0 12
 dis 0 picpos begx -65361.328 begy -21124.396 endx -65360.328 endy -21124.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
12 12 0 1 1 none
1
310 17
12 12 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block314 0 cap 1
	color 0 4
 dis 0 picpos begx -62480.736 begy -19221.396 endx -62479.736 endy -19221.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
4 4 0 1 1 none
1
310 17
4 4 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block106 0 cap 1
	color 0 11
 dis 0 picpos begx -42431.872 begy -34852.808 endx -42430.872 endy -34852.808 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block390 0 cap 1
	color 0 4
 dis 0 picpos begx -104082.112 begy -18915.396 endx -104081.112 endy -18915.396 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
4 4 0 1 1 none
1
310 17
4 4 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block313 0 cap 1
	color 0 11
 dis 0 picpos begx -32120.008 begy -90415.808 endx -32119.008 endy -90415.808 scx 170 scy 228 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block87 0 cap 1
	color 0 13
 dis 0 picpos begx -112515.592 begy -51826.6 endx -112514.592 endy -51826.6 scx 228 scy 170 scz 0.100000003539026

	UserDef	template Millimeters
700 17
13 13 0 1 1 none
1
310 17
13 13 0 1 1 none
4 4 4 4 4 0 0
end
BLOCK name Block218 0 cap 1
	color 0 11
 dis 0 picpos begx -68594.112 begy -19122.9 endx -68594.1120001192 endy -19121.9 scx 170 scy 342.000034265349 scz 0.100000003539026

	UserDef	template Millimeters
700 17
11 11 0 1 1 none
1
310 17
11 11 0 1 1 none
4 4 4 4 4 0 0
end
COUNT name cCnt 21 cap Infinite
COUNT name cUTB 100 cap 1
COUNT name Cout_in 0 cap Infinite
COUNT name Cout_out 0 cap Infinite
COUNT name cPark 30 cap 10
COUNT name cUTB_Occupied 100 cap 1
COUNT name cStop 0 cap Infinite
COUNT name cCheck 0 cap Infinite
COUNT name cCap 12 cap Infinite
COUNT name cCan 12 cap Infinite
COUNT name cOut 4 cap Infinite
COUNT name cUTBEmpty 120 cap Infinite
COUNT name cEQBuffer 20 cap Infinite
COUNT name cEQBufferEmpty 20 cap Infinite
COUNT name cUTBCan 12 cap Infinite
COUNT name cUTBCap 12 cap Infinite
COUNT name cEQBufferCapa1 16 cap Infinite
COUNT name cEQBufferCapa2 16 cap Infinite
COUNT name cEQBufferCapa3 16 cap Infinite
COUNT name cEQDelay 20 cap Infinite
COUNT name cUTBCan9 2 cap Infinite
COUNT name cUTBCap9 2 cap Infinite
COUNT name cUTBCan10 2 cap Infinite
COUNT name cUTBCap10 2 cap Infinite
COUNT name cUTBCan11 2 cap Infinite
COUNT name cUTBCap11 2 cap Infinite
COUNT name cUTBCan12 2 cap Infinite
COUNT name cUTBCap12 2 cap Infinite
COUNT name cUTBZero 64 cap Infinite
TABLE name tDelDistance 9 bins 1 0 1
TABLE name tRetDistance 9 bins 1 0 1
TABLE name tTotDistance 9 bins 1 0 1
TABLE name tAssignInit 9 bins 1 0 1
TABLE name tAssign 9 bins 1 0 1
TABLE name tUnloadMove 9 bins 1 0 1
TABLE name tLoadMove 9 bins 1 0 1
TABLE name tAssignCount 0 bins 1 0 1
TABLE name tAssignUpper1time 0 bins 1 0 1
TABLE name tConvMove 9 bins 1 0 1
TABLE name tOutLoad 9 bins 1 0 1
TABLE name tInLoad 9 bins 1 0 1
TABLE name tConvMove1 9 bins 1 0 1
TABLE name tConvMove2 9 bins 1 0 1
TABLE name tUTB_Cur 0 bins 1 0 1
TABLE name tUTBM_Cur 0 bins 1 0 1
TABLE name tOHT_Util 0 bins 1 0 1
TABLE name tOHT_Ret 0 bins 1 0 1
TABLE name tOHT_Del 0 bins 1 0 1
TABLE name tOHT_GPark 0 bins 1 0 1
TABLE name tOHT_Park 0 bins 1 0 1
TABLE name tDel_STKtoUTB 0 bins 1 0 1
TABLE name tDel_UTBtoEQ 0 bins 1 0 1
TABLE name tDel_EQtoOut 0 bins 1 0 1
TABLE name tDelDistancei 10 bins 1 0 1
TABLE name tRetDistancei 10 bins 1 0 1
TABLE name tTotDistancei 10 bins 1 0 1
TABLE name tAssignIniti 10 bins 1 0 1
TABLE name tAssigni 10 bins 1 0 1
TABLE name tUnloadMovei 10 bins 1 0 1
TABLE name tLoadMovei 10 bins 1 0 1
TABLE name tSTKZone 0 bins 1 0 1
TABLE name tDelDistance_UTBtoEQ 10 bins 1 0 1
TABLE name tLoadMove_UTBtoEQ 10 bins 1 0 1
TABLE name tDelDistance_Direct 10 bins 1 0 1
TABLE name tLoadMove_Direct 10 bins 1 0 1
TABLE name tDT_UTBtoEQ 0 bins 1 0 1
TABLE name tDT_Direct 0 bins 1 0 1
TABLE name tDT_Out 0 bins 1 0 1
TABLE name tDT_STKtoUTB 0 bins 1 0 1
TABLE name tDT_UTBtoEQL 9 bins 1 0 1
TABLE name tUTBdelayTime 0 bins 1 0 1
TABLE name tDT_UTBtoEQL2 499 bins 1 0 1
TABLE name tCap 12 bins 1 0 1
TABLE name tCan 12 bins 1 0 1
TABLE name tEQEmpty 20 bins 1 0 1
ATT name anVehicleType 0 type Integer
ATT name aID 0 type Integer
ATT name aAssign 0 type Integer
ATT name aParkBay 0 type Integer
ATT name atRetStart 0 type Time
ATT name anLoadType 0 type Integer
ATT name atUnload 0 type Time
ATT name alocToBay 0 type Integer
ATT name alocFromBay 0 type Integer
ATT name aRoute_FromLoc 0 type LocationList
ATT name alocFrom 0 type Location
ATT name atLoad 0 type Time
ATT name anTransfer 0 type Integer
ATT name alocStorage 0 type Location
ATT name atTR 0 type Time
ATT name atAssign 0 type Time
ATT name atAssignInit 0 type Time
ATT name vhlRetDistance 0 type Distance
ATT name avDispatch 0 type VehiclePtr
ATT name alocPark 0 type Location
ATT name anRoute 0 type Integer
ATT name atInitialCreated 0 type Time
ATT name arTimeGap 0 type Real
ATT name atAfterTimeGap 0 type Time
ATT name atCreate 0 type Time
ATT name aDistance 0 type Distance
ATT name aRetDistance 0 type Distance
ATT name aRoute_ToLoc 0 type LocationList
ATT name alocTo 0 type Location
ATT name aDelDistance 0 type Distance
ATT name aTotDistance 0 type Distance
ATT name aiAssignCount 0 type Integer
ATT name anTemp1 0 type Integer
ATT name atConvIn 1 2 type Time
ATT name atConvOut 1 2 type Time
ATT name atConv 1 2 type Time
ATT name atInLoadCome 0 type Time
ATT name atInLoadGo 0 type Time
ATT name atOutLoadCome 0 type Time
ATT name atOutLoadGo 0 type Time
ATT name atOutLoad 0 type Time
ATT name atInLoad 0 type Time
ATT name alocConvFrom 0 type Location
ATT name alocConvTo 0 type Location
ATT name ai 0 type Integer
ATT name anDeliverType 0 type Integer
ATT name aQnum 0 type Integer
ATT name aj 0 type Integer
ATT name asTemp_PN 0 type String
ATT name aiTemp_EQnum 0 type Integer
ATT name alocOut 0 type Location
ATT name anStart 0 type Integer
ATT name aiUTBnum 0 type Integer
ATT name aiHotLot 0 type Integer
ATT name aiHotLotEQ 0 type Integer
ATT name asCanCap 0 type String
ATT name aAlt 0 type Integer
ATT name atEnterLoss 0 type Time
ATT name atOutLoss 0 type Time
ATT name atServiceEnd 0 type Time
ATT name atFinalBuffer 0 type Time
ATT name atServiceIn 0 type Time
ATT name aDefine 0 type String
ATT name aiPortZone 0 type Integer
ATT name aiLossNum 0 type Integer
ATT name aiDelay 0 type Integer
ATT name aiSearchCount 0 type Integer
ATT name aiOL 0 type Integer
ATT name aiLocAssigned 0 type Integer
ATT name aiRandom 0 type Integer
ATT name aiBoxOut 0 type Integer
ATT name atEnterToOut 0 type Time
ATT name aiCheck 0 type Integer
ATT name aiYellow 0 type Integer
ATT name aiPreMove 0 type Integer
ATT name aiLine 0 type Integer
ATT name aiDeliverType 0 type Integer
ATT name alocToTwin 0 type Location
ATT name aiLocChange 0 type Integer
ATT name alocConv 1 10 type Location
ATT name aiPort 0 type Integer
ATT name aiCounterNum 0 type Integer
ATT name aiUTBtoEQ 0 type Integer
ATT name aiSTKtoEQ 0 type Integer
ATT name aiBox 0 type Integer
ATT name anDummy 0 type Integer
ATT name atDelayed 1 16 type Time
ATT name aUTBName 0 type Integer
ATT name A_cgStopDelay 0 type Real
ATT name A_cgStopOccur 0 type Real
ATT name A_cgStopTotalDelay 0 type Real
ATT name A_cgStopVeh 0 type VehiclePtr
ATT name alocToA 0 type String
ATT name atEQEmpty 0 type Time
ATT name aRandom 0 type Integer
ATT name anGapType 0 type Integer
ATT name aiSteering 0 type Integer
ATT name aiSteerChange 0 type Integer
ATT name aiLineStart 1 10 type Integer
ATT name arSetDownTime 0 type Real
VAR name vnRoute 0 type Integer
VAR name vrRatio 0 type Real
VAR name vnOHT 1 20 type Integer
VAR name vrOHTspec 1 4 type Real
VAR name vnCapa 0 type Integer
VAR name i 0 type Integer
VAR name vclOHTNum 0 type CounterList
VAR name vfpInFromto 0 type FilePtr
VAR name vfpInControl 1 4 type FilePtr
VAR name vfpOutResult 1 30 type FilePtr
VAR name vsStream 1 10 type String
VAR name vsaStream 1 10 type String
VAR name viaStream 1 4 type Integer
VAR name vroute_VehicleType 0 type String
VAR name vroute_Interval 1 5200 type Integer
VAR name vroute_FromLoc 1 5200 type String
VAR name vroute_FromBay 1 5200 type Integer
VAR name vroute_ToLoc 1 5200 type String
VAR name vroute_ToBay 1 5200 type Integer
VAR name vrNormalVelocity 1 4 type Real
VAR name vrCurveVelocity 1 4 type Real
VAR name vrAcceleration 1 4 type Real
VAR name vrDeceleration 1 4 type Real
VAR name vtLoading 1 20 type Time
VAR name vrBrakeDistance 0 type Real
VAR name vrStopDistance 0 type Real
VAR name vtResume 0 type Time
VAR name vtRun 0 type Time
VAR name vtSchedule 0 type Time
VAR name vtPriorityCost 0 type Time
VAR name vnTimeWeight 0 type Integer
VAR name vtTimeLimit 0 type Time
VAR name vnPark 0 type Integer
VAR name vsStream2 0 type String
VAR name vlocTemp 0 type Location
VAR name vlocParkList 0 type LocationList
VAR name vLocListpm 1 2 type LocationList
VAR name vnRequest 1 30 type Integer
VAR name vnComplete 1 30 type Integer
VAR name vnDelay 1 20 type Integer
VAR name vcOHT 1 4 type Integer
VAR name vlistOHT 1 20 type VehicleList
VAR name vlocPark 0 type Location
VAR name vsParkPoint 0 type String
VAR name vsParkBayNum 0 type String
VAR name viParkBayNum 0 type Integer
VAR name vlistLoad 1 20 type LoadList
VAR name vlTemp2 0 type LoadPtr
VAR name viWIP 0 type Integer
VAR name vlSelect 0 type LoadPtr
VAR name vvSelect 0 type VehiclePtr
VAR name vtSelect 0 type Time
VAR name vohtTemp 0 type VehiclePtr
VAR name vlTemp 0 type LoadPtr
VAR name vrDistance 0 type Real
VAR name vtCost 0 type Time
VAR name vJob 0 type SchedJobPtr
VAR name viCheck 0 type Integer
VAR name vrDistance2 0 type Real
VAR name vrDistanceTemp 0 type Real
VAR name k2 0 type Integer
VAR name vsTemp 0 type String
VAR name viParkTemp 0 type Integer
VAR name vsTemp2 0 type String
VAR name vlocTemp2 0 type Location
VAR name vcOHTNum 0 type CounterPtr
VAR name vstrTemp 0 type String
VAR name vo 0 type Integer
VAR name vtAddTemp 0 type Time
VAR name vstrTemp2 0 type String
VAR name viAssignOnce 0 type Integer
VAR name j 0 type Integer
VAR name vroute_Storage 1 5200 type Integer
VAR name viCase 0 type Integer
VAR name viTemp 1 100 type Integer
VAR name k 0 type Integer
VAR name vnUTB 0 type Integer
VAR name vnInOut 1 20 type Integer
VAR name vnTemp1 0 type Integer
VAR name vstrTemp1 0 type String
VAR name vlocTemp1 0 type Location
VAR name vnTemp3 0 type Integer
VAR name vnCreated 1 7 type Integer
VAR name vnConvIn 1 20 type Integer
VAR name vnConvOut 1 20 type Integer
VAR name vnConvIn1 1 20 type Integer
VAR name vSubstring 0 type String
VAR name vnSub 0 type Integer
VAR name viIndex 0 type Integer
VAR name vCnt 1 21 type Integer
VAR name vtPH 1 20 type Integer
VAR name vsParkTemp 0 type String
VAR name vroute_DeliverType 1 5200 type Integer
VAR name vnInDT 1 20 type Integer
VAR name vnInTT 1 20 type Integer
VAR name vnOutDT 1 20 type Integer
VAR name vnOutTT 1 20 type Integer
VAR name vsTemp_PN 0 type String
VAR name viTemp_EQnum 0 type Integer
VAR name vsEQTemp 0 type String
VAR name vk 0 type Integer
VAR name vstringTemp 0 type String
VAR name vstringTemp2 0 type String
VAR name vicheckTemp 0 type Integer
VAR name vsPort1Temp 0 type String
VAR name viPort2Temp 0 type Integer
VAR name viPort 0 type Integer
VAR name vsRouteTemp 0 type Location
VAR name vlocRoute 0 type Location
VAR name vicheck 0 type Integer
VAR name vs 0 type String
VAR name vD 0 type Integer
VAR name vDummy 0 type Location
VAR name vroute_headtoUTBratio 0 type Integer
VAR name vroute_StorageType 0 type String
VAR name viTemp2 0 type Integer
VAR name vsTempTo 0 type String
VAR name vRuntime 0 type Integer
VAR name vCntModelSnap 0 type Integer
VAR name v 1 20 type Integer
VAR name vTime 1 20 type Time
VAR name vCnt_Route 1 20 type Integer
VAR name vTotal_Route 1 20 type Integer
VAR name vnUTBCNT 1 8 type Integer
VAR name viTotAlt 0 type Integer
VAR name viMax 0 type Integer
VAR name viEQcomplete 1 1000 type Integer
VAR name vtOutLossCumul 2 1000 1000 type Time
VAR name viEnterLossCount 2 1000 1000 type Integer
VAR name viOutLossCount 2 1000 1000 type Integer
VAR name vtEnterLossCumul 2 1000 1000 type Time
VAR name vtEnterLoss 2 100 1000 type Time
VAR name vrConv 0 type Real
VAR name vrLift 0 type Real
VAR name vUTBFull_Total 0 type Integer
VAR name vUTBFull_Zone1 0 type Integer
VAR name vUTBFull_Zone2 0 type Integer
VAR name vUTBFull_Zone3 0 type Integer
VAR name vUTBFull_Zone4 0 type Integer
VAR name vUTBFull_Zone15 0 type Integer
VAR name vUTBFull_Zone5 0 type Integer
VAR name vUTBFull_Zone7 0 type Integer
VAR name vUTBFull_Zone17 0 type Integer
VAR name vUTBFull_Zone11 0 type Integer
VAR name vUTBFull_Zone13 0 type Integer
VAR name vsDefine 0 type String
VAR name vk2 0 type Integer
VAR name vnUTB_Multi 0 type Integer
VAR name vUTBFull_Multi_Total 0 type Integer
VAR name viPort1Temp 0 type Integer
VAR name viRandom 0 type Integer
VAR name viNcount 1 100 type Integer
VAR name viUTB_Cur 0 type Integer
VAR name viUTBM_Cur 0 type Integer
VAR name vi 0 type Integer
VAR name vrUTBRatio 0 type Real
VAR name viInit 0 type Integer
VAR name vlocAvoidList 0 type LocationList
VAR name vlistOHT_ParkCheck 0 type VehicleList
VAR name vvFront 0 type VehiclePtr
VAR name vlocFront 0 type Location
VAR name vloclist_CurrentRoute 0 type LocationList
VAR name vrDistanceR 0 type Real
VAR name vrDistanceMin 0 type Real
VAR name vlocMin 0 type Location
VAR name vloc2nd 0 type Location
VAR name vrDistance2nd 0 type Real
VAR name viParkCapa 1 30 type Integer
VAR name viOutNumbering 0 type Integer
VAR name viUTBLine 1 100 type Integer
VAR name viFrontUTB 0 type Integer
VAR name viLineUTB 0 type Integer
VAR name vnRequesti 1 100 type Integer
VAR name vnCompletei 1 100 type Integer
VAR name vvlDeliver 0 type VehicleList
VAR name vvTemp 0 type VehiclePtr
VAR name viConfirm 0 type Integer
VAR name viDestChange 0 type Integer
VAR name viRamdom 0 type Integer
VAR name vrStorage 0 type Real
VAR name viSearch 0 type Integer
VAR name viRoute 3 10 10 10 type Integer
VAR name vinoUTBcase 0 type Integer
VAR name viAbnormalUTB 0 type Integer
VAR name viComplete2 1 8 type Integer
VAR name vrSpec 0 type Real
VAR name viBoxOut 0 type Integer
VAR name viNewBox 0 type Integer
VAR name viUTBBox 0 type Integer
VAR name vsUTBName 0 type String
VAR name vUTBtoEQLog 0 type FilePtr
VAR name vSTKtoUTBLog 0 type FilePtr
VAR name vfUTBtoEQ 1 2 type FilePtr
VAR name vDelayLog 0 type FilePtr
VAR name vnEQBuffer 1 20 type Integer
VAR name vnEQBufferEmpty 1 20 type Integer
VAR name vTact 0 type Integer
VAR name vllUTB 1 16 type LoadList
VAR name vfpLoading 0 type FilePtr
VAR name vfpUnloading 0 type FilePtr
VAR name viGap 0 type Integer
VAR name vrLoadingGap 1 99999 type Real
VAR name vrUnloadingGap 1 99999 type Real
VAR name vfputbtact 0 type FilePtr
VAR name vfpeqtact 0 type FilePtr
VAR name vfpstktact 0 type FilePtr
VAR name vfpconvtact 0 type FilePtr
VAR name vrUTBGap 1 343 type Real
VAR name vrEQGap 1 336 type Real
VAR name vrSTKGap 1 176 type Real
VAR name vrCONVGap 1 168 type Real
VAR name vnCompleteType 1 10 type Integer
VAR name viLineStart 1 10 type Integer
VAR name vlSelected 0 type LoadPtr
RNSTREAM stream0 0 type CMRG flags 1
	cmrgseed 1 12345 12345 12345 12345 12345 12345
RNSTREAM stream_LoadType1_1 0 type CMRG flags 1
	title "Generated automatically for LoadType1"
	cmrgseed 1 3692455944 1366884236 2968912127 335948734 4161675175 475798818
RNSTREAM stream_rOHT_1 0 type CMRG flags 1
	title "Generated automatically for rOHT"
	cmrgseed 1 1015873554 1310354410 2249465273 994084013 2912484720 3876682925
RNSTREAM stream_lCreate_1 0 type CMRG flags 1
	title "Generated automatically for lCreate"
	cmrgseed 1 2338701263 1119171942 2570676563 317077452 3194180850 618832124
RNSTREAM stream_lCreate_2 0 type CMRG flags 1
	title "Generated automatically for lCreate"
	cmrgseed 1 1597262096 3906379055 3312112953 1016013135 4099474108 275305423
RNSTREAM stream_lCreate_3 0 type CMRG flags 1
	title "Generated automatically for lCreate"
	cmrgseed 1 97147054 3131372450 829345164 3691032523 3006063034 4259826321
RNSTREAM stream_lCreate_4 0 type CMRG flags 1
	title "Generated automatically for lCreate"
	cmrgseed 1 796079799 2105258207 955365076 2923159030 4116632677 3067683584
RNSTREAM stream_L_UTB_1 0 type CMRG flags 1
	title "Generated automatically for L_UTB"
	cmrgseed 1 3281794178 2616230133 1457051261 2762791137 2480527362 2282316169
RNSTREAM stream_lCreate_5 0 type CMRG flags 1
	title "Generated automatically for lCreate"
	cmrgseed 1 3777646647 1837464056 4204654757 664239048 4190510072 2959195122
RNSTATE 4215590817 3862461878 1087200967 1544910132 936383720 1611370123
FUNC name fsetValuable_FilePtr type Integer
FUNC name freadFromto type Integer
FUNC name freadOHTSpec type Integer
FUNC name freadControl type Integer
FUNC name fDispatchToNextPark type Integer PARAM name theVehicle type VehiclePtr PARAM name theCurrentBay type Integer PARAM name theZone type Integer
SUBRTN name sSetFromLocation
SUBRTN name sSetToLocation
SUBRTN name sReport
SUBRTN name sSetStorageLocation
SUBRTN name sConToSTK
SUBRTN name sEQPortZone
SUBRTN name sDestChange
SUBRTN name sUTB_Selection
SUBRTN name sSearchCountInit
SUBRTN name sCheck
SFileBegin	name vehicle.m
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

#@!
SFileBegin	name init.m
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
										
										

#@!
SFileBegin	name logic.m
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

#@!
SFileBegin	name PhotoEye.m
/*begin conv.p_1_1 blocked procedure
	set vtPH(1) to ac
end

begin conv.p_1 blocked procedure
	if Turntable(1) current = 1 then 
	begin
		wait until Turntable(1) current = 0
		wait for 6 sec
	end
	if ac - vtPH(1) < 3 sec then wait for 3 sec
end

begin conv.p_1_2 blocked procedure
	set vtPH(2) to ac
end

begin conv.p_2 blocked procedure
	if Turntable(2) current = 1 then 
	begin
		wait until Turntable(2) current = 0
		wait for 6 sec
	end
	if ac - vtPH(2) < 3 sec then wait for 3 sec
end

begin conv.p_1_3 blocked procedure
	set vtPH(3) to ac
end

begin conv.p_3 blocked procedure
	if Turntable(3) current = 1 then
	begin
		wait until Turntable(3) current = 0
		wait for 6 sec
	end
	if ac - vtPH(3) < 3 sec then wait for 3 sec
end

begin conv.p_1_4 blocked procedure
	set vtPH(4) to ac
end

begin conv.p_4 blocked procedure
	if Turntable(4) current = 1 then 
	begin
		wait until Turntable(4) current = 0
		wait for 6 sec
	end
	if ac - vtPH(4) < 3 sec then wait for 3 sec
end

begin conv.p_1_5 blocked procedure
	set vtPH(5) to ac
end

begin conv.p_5 blocked procedure
	if Turntable(5) current = 1 then 
	begin
		wait until Turntable(5) current = 0
		wait for 6 sec
	end
	if ac - vtPH(5) < 3 sec then wait for 3 sec
end

begin conv.p_1_6 blocked procedure
	set vtPH(6) to ac
end

begin conv.p_6 blocked procedure
	if Turntable(6) current = 1 then 
	begin
		wait until Turntable(6) current = 0
		wait for 6 sec
	end
	if ac - vtPH(6) < 3 sec then wait for 3 sec
end

begin conv.p_1_7 blocked procedure
	set vtPH(7) to ac
end

begin conv.p_7 blocked procedure
	if Turntable(7) current = 1 then 
	begin
		wait until Turntable(7) current = 0
		wait for 6 sec
	end
	if ac - vtPH(7) < 3 sec then wait for 3 sec
end

begin conv.p_1_8 blocked procedure
	set vtPH(8) to ac
end

begin conv.p_8 blocked procedure
	if Turntable(8) current = 1 then 
	begin
		wait until Turntable(8) current = 0
		wait for 6 sec
	end
	if ac - vtPH(8) < 3 sec then wait for 3 sec
end

begin conv.p_1_9 blocked procedure
	set vtPH(9) to ac
end

begin conv.p_9 blocked procedure
	if Turntable(9) current = 1 then 
	begin
		wait until Turntable(9) current = 0
		wait for 6 sec
	end
	if ac - vtPH(9) < 3 sec then wait for 3 sec
end

begin conv.p_1_10 blocked procedure
	set vtPH(10) to ac
end

begin conv.p_10 blocked procedure
	if Turntable(10) current = 1 then 
	begin
		wait until Turntable(10) current = 0
		wait for 6 sec
	end
	if ac - vtPH(10) < 3 sec then wait for 3 sec
end

begin conv.p_1_11 blocked procedure
	set vtPH(11) to ac
end

begin conv.p_11 blocked procedure
	if Turntable(11) current = 1 then 
	begin
		wait until Turntable(11) current = 0
		wait for 6 sec
	end
	if ac - vtPH(11) < 3 sec then wait for 3 sec
end

begin conv.p_1_12 blocked procedure
	set vtPH(12) to ac
end

begin conv.p_12 blocked procedure
	if Turntable(12) current = 1 then 
	begin
		wait until Turntable(12) current = 0
		wait for 6 sec
	end
	if ac - vtPH(12) < 3 sec then wait for 3 sec
end


*/

#@!
SFileBegin	name reroute.m
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

#@!
SFileBegin	name logic_multi.m
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

#@!
