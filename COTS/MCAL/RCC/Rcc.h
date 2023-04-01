/*
 * Rcc.h
 *
 *  Created on: Mar 10, 2022
 *      Author: Ahmed Soliman
 */

#ifndef RCC_H_
#define RCC_H_


#define Rcc_u8HSE_ModeSysClk        0xC00000001
#define Rcc_u8HSE_CrystalMode       0xC00000001
#define Rcc_u8HSE_ByPassMode        0xC00000003
#define Rcc_u8HSIMode               0xC00000000
#define Rcc_u8PllMode               0xC00000002

#define Rcc_u8ClkON_State           (u8)1
#define Rcc_u8ClkOFF_State          (u8)0

#define Rcc_u8ClkRDY                (u8)0
#define Rcc_u8ClkNRDY               (u8)1

#define Rcc_u8Pll_HSISCR            0x000000000
#define Rcc_u8Pll_HSESCR            0x000400000


#define Rcc_u32Pll_Q2CFG           0x102000000
#define Rcc_u32Pll_Q3CFG           0x103000000
#define Rcc_u32Pll_Q4CFG           0x104000000
#define Rcc_u32Pll_Q5CFG           0x105000000
#define Rcc_u32Pll_Q6CFG           0x106000000
#define Rcc_u32Pll_Q7CFG           0x107000000
#define Rcc_u32Pll_Q8CFG           0x108000000
#define Rcc_u32Pll_Q9CFG           0x109000000
#define Rcc_u32Pll_Q10CFG          0x10A000000
#define Rcc_u32Pll_Q11CFG          0x10B000000
#define Rcc_u32Pll_Q12CFG          0x10C000000
#define Rcc_u32Pll_Q13CFG          0x10D000000
#define Rcc_u32Pll_Q14CFG          0x10E000000
#define Rcc_u32Pll_Q15CFG          0x10F000000

#define Rcc_u32Pll_P2CFG            0x200000002
#define Rcc_u32Pll_P4CFG            0x200000004
#define Rcc_u32Pll_P6CFG            0x200000006
#define Rcc_u32Pll_P8CFG            0x200000008



#define Rcc_u32Pll_M2CFG             0x200000002
#define Rcc_u32Pll_M3CFG             0x200000003
#define Rcc_u32Pll_M4CFG             0x200000004
#define Rcc_u32Pll_M5CFG             0x200000005
#define Rcc_u32Pll_M6CFG             0x200000006
#define Rcc_u32Pll_M7CFG             0x200000007
#define Rcc_u32Pll_M8CFG             0x200000008
#define Rcc_u32Pll_M9CFG             0x200000009
#define Rcc_u32Pll_M10CFG            0x20000000A
#define Rcc_u32Pll_M11CFG            0x20000000B
#define Rcc_u32Pll_M12CFG            0x20000000C
#define Rcc_u32Pll_M13CFG            0x20000000D
#define Rcc_u32Pll_M14CFG            0x20000000E
#define Rcc_u32Pll_M15CFG            0x20000000F
#define Rcc_u32Pll_M16CFG            0x200000010
#define Rcc_u32Pll_M17CFG            0x200000011
#define Rcc_u32Pll_M18CFG            0x200000012
#define Rcc_u32Pll_M19CFG            0x200000013
#define Rcc_u32Pll_M20CFG            0x200000014
#define Rcc_u32Pll_M21CFG            0x200000015
#define Rcc_u32Pll_M22CFG            0x200000016
#define Rcc_u32Pll_M23CFG            0x200000017
#define Rcc_u32Pll_M24CFG            0x200000018
#define Rcc_u32Pll_M25CFG            0x200000019
#define Rcc_u32Pll_M26CFG            0x20000001A
#define Rcc_u32Pll_M27CFG            0x20000001B
#define Rcc_u32Pll_M28CFG            0x20000001C
#define Rcc_u32Pll_M29CFG            0x20000001D
#define Rcc_u32Pll_M30CFG            0x20000001E
#define Rcc_u32Pll_M31CFG            0x20000001F
#define Rcc_u32Pll_M32CFG            0x200000020
#define Rcc_u32Pll_M33CFG            0x200000021
#define Rcc_u32Pll_M34CFG            0x200000022
#define Rcc_u32Pll_M35CFG            0x200000023
#define Rcc_u32Pll_M36CFG            0x200000024
#define Rcc_u32Pll_M37CFG            0x200000025
#define Rcc_u32Pll_M38CFG            0x200000026
#define Rcc_u32Pll_M39CFG            0x200000027
#define Rcc_u32Pll_M40CFG            0x200000028
#define Rcc_u32Pll_M41CFG            0x200000029
#define Rcc_u32Pll_M42CFG            0x20000002A
#define Rcc_u32Pll_M43CFG            0x20000002B
#define Rcc_u32Pll_M44CFG            0x20000002C
#define Rcc_u32Pll_M45CFG            0x20000002D
#define Rcc_u32Pll_M46CFG            0x20000002E
#define Rcc_u32Pll_M47CFG            0x20000002F
#define Rcc_u32Pll_M48CFG            0x200000030
#define Rcc_u32Pll_M49CFG            0x200000031
#define Rcc_u32Pll_M50CFG            0x200000032
#define Rcc_u32Pll_M51CFG            0x200000033
#define Rcc_u32Pll_M52CFG            0x200000034
#define Rcc_u32Pll_M53CFG            0x200000035
#define Rcc_u32Pll_M54CFG            0x200000036
#define Rcc_u32Pll_M55CFG            0x200000037
#define Rcc_u32Pll_M56CFG            0x200000038
#define Rcc_u32Pll_M57CFG            0x200000039
#define Rcc_u32Pll_M58CFG            0x20000003A
#define Rcc_u32Pll_M59CFG            0x20000003B
#define Rcc_u32Pll_M60CFG            0x20000003C
#define Rcc_u32Pll_M61CFG            0x20000003D
#define Rcc_u32Pll_M62CFG            0x20000003E
#define Rcc_u32Pll_M63CFG            0x20000003F

#define Rcc_u32Pll_N0CFG            0x300000000
#define Rcc_u32Pll_N1CFG            0x300000040
#define Rcc_u32Pll_N2CFG            0x300000080
#define Rcc_u32Pll_N3CFG            0x3000000C0
#define Rcc_u32Pll_N4CFG            0x300000100
#define Rcc_u32Pll_N5CFG            0x300000140
#define Rcc_u32Pll_N6CFG            0x300000180
#define Rcc_u32Pll_N7CFG            0x3000001C0
#define Rcc_u32Pll_N8CFG            0x300000200
#define Rcc_u32Pll_N9CFG            0x300000240
#define Rcc_u32Pll_N10CFG           0x300000280
#define Rcc_u32Pll_N11CFG           0x3000002C0
#define Rcc_u32Pll_N12CFG           0x300000300
#define Rcc_u32Pll_N13CFG           0x300000340
#define Rcc_u32Pll_N14CFG           0x300000380
#define Rcc_u32Pll_N15CFG           0x3000003C0
#define Rcc_u32Pll_N16CFG           0x300000400
#define Rcc_u32Pll_N17CFG           0x300000440
#define Rcc_u32Pll_N18CFG           0x300000480
#define Rcc_u32Pll_N19CFG           0x3000004C0
#define Rcc_u32Pll_N20CFG           0x300000500
#define Rcc_u32Pll_N21CFG           0x300000540
#define Rcc_u32Pll_N22CFG           0x300000580
#define Rcc_u32Pll_N23CFG           0x3000005C0
#define Rcc_u32Pll_N24CFG           0x300000600
#define Rcc_u32Pll_N25CFG           0x300000640
#define Rcc_u32Pll_N26CFG           0x300000680
#define Rcc_u32Pll_N27CFG           0x3000006C0
#define Rcc_u32Pll_N28CFG           0x300000700
#define Rcc_u32Pll_N29CFG           0x300000740
#define Rcc_u32Pll_N30CFG           0x300000780
#define Rcc_u32Pll_N31CFG           0x3000007C0
#define Rcc_u32Pll_N32CFG           0x300000800
#define Rcc_u32Pll_N33CFG           0x300000840
#define Rcc_u32Pll_N34CFG           0x300000880
#define Rcc_u32Pll_N35CFG           0x3000008C0
#define Rcc_u32Pll_N36CFG           0x300000900
#define Rcc_u32Pll_N37CFG           0x300000940
#define Rcc_u32Pll_N38CFG           0x300000980
#define Rcc_u32Pll_N39CFG           0x3000009C0
#define Rcc_u32Pll_N40CFG           0x300000A00
#define Rcc_u32Pll_N41CFG           0x300000A40
#define Rcc_u32Pll_N42CFG           0x300000A80
#define Rcc_u32Pll_N43CFG           0x300000AC0
#define Rcc_u32Pll_N44CFG           0x300000B00
#define Rcc_u32Pll_N45CFG           0x300000B40
#define Rcc_u32Pll_N46CFG           0x300000B80
#define Rcc_u32Pll_N47CFG           0x300000BC0
#define Rcc_u32Pll_N48CFG           0x300000C00
#define Rcc_u32Pll_N49CFG           0x300000C40
#define Rcc_u32Pll_N50CFG           0x300000C80
#define Rcc_u32Pll_N51CFG           0x300000CC0
#define Rcc_u32Pll_N52CFG           0x300000D00
#define Rcc_u32Pll_N53CFG           0x300000D40
#define Rcc_u32Pll_N54CFG           0x300000D80
#define Rcc_u32Pll_N55CFG           0x300000DC0
#define Rcc_u32Pll_N56CFG           0x300000E00
#define Rcc_u32Pll_N57CFG           0x300000E40
#define Rcc_u32Pll_N58CFG           0x300000E80
#define Rcc_u32Pll_N59CFG           0x300000EC0
#define Rcc_u32Pll_N60CFG           0x300000F00
#define Rcc_u32Pll_N61CFG           0x300000F40
#define Rcc_u32Pll_N62CFG           0x300000F80
#define Rcc_u32Pll_N63CFG           0x300000FC0
#define Rcc_u32Pll_N64CFG           0x300001000
#define Rcc_u32Pll_N65CFG           0x300001040
#define Rcc_u32Pll_N66CFG           0x300001080
#define Rcc_u32Pll_N67CFG           0x3000010C0
#define Rcc_u32Pll_N68CFG           0x300001100
#define Rcc_u32Pll_N69CFG           0x300001140
#define Rcc_u32Pll_N70CFG           0x300001180
#define Rcc_u32Pll_N71CFG           0x3000011C0
#define Rcc_u32Pll_N72CFG           0x300001200
#define Rcc_u32Pll_N73CFG           0x300001240
#define Rcc_u32Pll_N74CFG           0x300001280
#define Rcc_u32Pll_N75CFG           0x3000012C0
#define Rcc_u32Pll_N76CFG           0x300001300
#define Rcc_u32Pll_N77CFG           0x300001340
#define Rcc_u32Pll_N78CFG           0x300001380
#define Rcc_u32Pll_N79CFG           0x3000013C0
#define Rcc_u32Pll_N80CFG           0x300001400
#define Rcc_u32Pll_N81CFG           0x300001440
#define Rcc_u32Pll_N82CFG           0x300001480
#define Rcc_u32Pll_N83CFG           0x3000014C0
#define Rcc_u32Pll_N84CFG           0x300001500
#define Rcc_u32Pll_N85CFG           0x300001540
#define Rcc_u32Pll_N86CFG           0x300001580
#define Rcc_u32Pll_N87CFG           0x3000015C0
#define Rcc_u32Pll_N88CFG           0x300001600
#define Rcc_u32Pll_N89CFG           0x300001640
#define Rcc_u32Pll_N90CFG           0x300001680
#define Rcc_u32Pll_N91CFG           0x3000016C0
#define Rcc_u32Pll_N92CFG           0x300001700
#define Rcc_u32Pll_N93CFG           0x300001740
#define Rcc_u32Pll_N94CFG           0x300001780
#define Rcc_u32Pll_N95CFG           0x3000017C0
#define Rcc_u32Pll_N96CFG           0x300001800
#define Rcc_u32Pll_N97CFG           0x300001840
#define Rcc_u32Pll_N98CFG           0x300001880
#define Rcc_u32Pll_N99CFG           0x3000018C0
#define Rcc_u32Pll_N100CFG          0x300001900
#define Rcc_u32Pll_N101CFG          0x300001940
#define Rcc_u32Pll_N102CFG          0x300001980
#define Rcc_u32Pll_N103CFG          0x3000019C0
#define Rcc_u32Pll_N104CFG          0x300001A00
#define Rcc_u32Pll_N105CFG          0x300001A40
#define Rcc_u32Pll_N106CFG          0x300001A80
#define Rcc_u32Pll_N107CFG          0x300001AC0
#define Rcc_u32Pll_N108CFG          0x300001B00
#define Rcc_u32Pll_N109CFG          0x300001B40
#define Rcc_u32Pll_N110CFG          0x300001B80
#define Rcc_u32Pll_N111CFG          0x300001BC0
#define Rcc_u32Pll_N112CFG          0x300001C00
#define Rcc_u32Pll_N113CFG          0x300001C40
#define Rcc_u32Pll_N114CFG          0x300001C80
#define Rcc_u32Pll_N115CFG          0x300001CC0
#define Rcc_u32Pll_N116CFG          0x300001D00
#define Rcc_u32Pll_N117CFG          0x300001D40
#define Rcc_u32Pll_N118CFG          0x300001D80
#define Rcc_u32Pll_N119CFG          0x300001DC0
#define Rcc_u32Pll_N120CFG          0x300001E00
#define Rcc_u32Pll_N121CFG          0x300001E40
#define Rcc_u32Pll_N122CFG          0x300001E80
#define Rcc_u32Pll_N123CFG          0x300001EC0
#define Rcc_u32Pll_N124CFG          0x300001F00
#define Rcc_u32Pll_N125CFG          0x300001F40
#define Rcc_u32Pll_N126CFG          0x300001F80
#define Rcc_u32Pll_N127CFG          0x300001FC0
#define Rcc_u32Pll_N128CFG          0x300002000
#define Rcc_u32Pll_N129CFG          0x300002040
#define Rcc_u32Pll_N130CFG          0x300002080
#define Rcc_u32Pll_N131CFG          0x3000020C0
#define Rcc_u32Pll_N132CFG          0x300002100
#define Rcc_u32Pll_N133CFG          0x300002140
#define Rcc_u32Pll_N134CFG          0x300002180
#define Rcc_u32Pll_N135CFG          0x3000021C0
#define Rcc_u32Pll_N136CFG          0x300002200
#define Rcc_u32Pll_N137CFG          0x300002240
#define Rcc_u32Pll_N138CFG          0x300002280
#define Rcc_u32Pll_N139CFG          0x3000022C0
#define Rcc_u32Pll_N140CFG          0x300002300
#define Rcc_u32Pll_N141CFG          0x300002340
#define Rcc_u32Pll_N142CFG          0x300002380
#define Rcc_u32Pll_N143CFG          0x3000023C0
#define Rcc_u32Pll_N144CFG          0x300002400
#define Rcc_u32Pll_N145CFG          0x300002440
#define Rcc_u32Pll_N146CFG          0x300002480
#define Rcc_u32Pll_N147CFG          0x3000024C0
#define Rcc_u32Pll_N148CFG          0x300002500
#define Rcc_u32Pll_N149CFG          0x300002540
#define Rcc_u32Pll_N150CFG          0x300002580
#define Rcc_u32Pll_N151CFG          0x3000025C0
#define Rcc_u32Pll_N152CFG          0x300002600
#define Rcc_u32Pll_N153CFG          0x300002640
#define Rcc_u32Pll_N154CFG          0x300002680
#define Rcc_u32Pll_N155CFG          0x3000026C0
#define Rcc_u32Pll_N156CFG          0x300002700
#define Rcc_u32Pll_N157CFG          0x300002740
#define Rcc_u32Pll_N158CFG          0x300002780
#define Rcc_u32Pll_N159CFG          0x3000027C0
#define Rcc_u32Pll_N160CFG          0x300002800
#define Rcc_u32Pll_N161CFG          0x300002840
#define Rcc_u32Pll_N162CFG          0x300002880
#define Rcc_u32Pll_N163CFG          0x3000028C0
#define Rcc_u32Pll_N164CFG          0x300002900
#define Rcc_u32Pll_N165CFG          0x300002940
#define Rcc_u32Pll_N166CFG          0x300002980
#define Rcc_u32Pll_N167CFG          0x3000029C0
#define Rcc_u32Pll_N168CFG          0x300002A00
#define Rcc_u32Pll_N169CFG          0x300002A40
#define Rcc_u32Pll_N170CFG          0x300002A80
#define Rcc_u32Pll_N171CFG          0x300002AC0
#define Rcc_u32Pll_N172CFG          0x300002B00
#define Rcc_u32Pll_N173CFG          0x300002B40
#define Rcc_u32Pll_N174CFG          0x300002B80
#define Rcc_u32Pll_N175CFG          0x300002BC0
#define Rcc_u32Pll_N176CFG          0x300002C00
#define Rcc_u32Pll_N177CFG          0x300002C40
#define Rcc_u32Pll_N178CFG          0x300002C80
#define Rcc_u32Pll_N179CFG          0x300002CC0
#define Rcc_u32Pll_N180CFG          0x300002D00
#define Rcc_u32Pll_N181CFG          0x300002D40
#define Rcc_u32Pll_N182CFG          0x300002D80
#define Rcc_u32Pll_N183CFG          0x300002DC0
#define Rcc_u32Pll_N184CFG          0x300002E00
#define Rcc_u32Pll_N185CFG          0x300002E40
#define Rcc_u32Pll_N186CFG          0x300002E80
#define Rcc_u32Pll_N187CFG          0x300002EC0
#define Rcc_u32Pll_N188CFG          0x300002F00
#define Rcc_u32Pll_N189CFG          0x300002F40
#define Rcc_u32Pll_N190CFG          0x300002F80
#define Rcc_u32Pll_N191CFG          0x300002FC0
#define Rcc_u32Pll_N192CFG          0x300003000
#define Rcc_u32Pll_N193CFG          0x300003040
#define Rcc_u32Pll_N194CFG          0x300003080
#define Rcc_u32Pll_N195CFG          0x3000030C0
#define Rcc_u32Pll_N196CFG          0x300003100
#define Rcc_u32Pll_N197CFG          0x300003140
#define Rcc_u32Pll_N198CFG          0x300003180
#define Rcc_u32Pll_N199CFG          0x3000031C0
#define Rcc_u32Pll_N200CFG          0x300003200
#define Rcc_u32Pll_N201CFG          0x300003240
#define Rcc_u32Pll_N202CFG          0x300003280
#define Rcc_u32Pll_N203CFG          0x3000032C0
#define Rcc_u32Pll_N204CFG          0x300003300
#define Rcc_u32Pll_N205CFG          0x300003340
#define Rcc_u32Pll_N206CFG          0x300003380
#define Rcc_u32Pll_N207CFG          0x3000033C0
#define Rcc_u32Pll_N208CFG          0x300003400
#define Rcc_u32Pll_N209CFG          0x300003440
#define Rcc_u32Pll_N210CFG          0x300003480
#define Rcc_u32Pll_N211CFG          0x3000034C0
#define Rcc_u32Pll_N212CFG          0x300003500
#define Rcc_u32Pll_N213CFG          0x300003540
#define Rcc_u32Pll_N214CFG          0x300003580
#define Rcc_u32Pll_N215CFG          0x3000035C0
#define Rcc_u32Pll_N216CFG          0x300003600
#define Rcc_u32Pll_N217CFG          0x300003640
#define Rcc_u32Pll_N218CFG          0x300003680
#define Rcc_u32Pll_N219CFG          0x3000036C0
#define Rcc_u32Pll_N220CFG          0x300003700
#define Rcc_u32Pll_N221CFG          0x300003740
#define Rcc_u32Pll_N222CFG          0x300003780
#define Rcc_u32Pll_N223CFG          0x3000037C0
#define Rcc_u32Pll_N224CFG          0x300003800
#define Rcc_u32Pll_N225CFG          0x300003840
#define Rcc_u32Pll_N226CFG          0x300003880
#define Rcc_u32Pll_N227CFG          0x3000038C0
#define Rcc_u32Pll_N228CFG          0x300003900
#define Rcc_u32Pll_N229CFG          0x300003940
#define Rcc_u32Pll_N230CFG          0x300003980
#define Rcc_u32Pll_N231CFG          0x3000039C0
#define Rcc_u32Pll_N232CFG          0x300003A00
#define Rcc_u32Pll_N233CFG          0x300003A40
#define Rcc_u32Pll_N234CFG          0x300003A80
#define Rcc_u32Pll_N235CFG          0x300003AC0
#define Rcc_u32Pll_N236CFG          0x300003B00
#define Rcc_u32Pll_N237CFG          0x300003B40
#define Rcc_u32Pll_N238CFG          0x300003B80
#define Rcc_u32Pll_N239CFG          0x300003BC0
#define Rcc_u32Pll_N240CFG          0x300003C00
#define Rcc_u32Pll_N241CFG          0x300003C40
#define Rcc_u32Pll_N242CFG          0x300003C80
#define Rcc_u32Pll_N243CFG          0x300003CC0
#define Rcc_u32Pll_N244CFG          0x300003D00
#define Rcc_u32Pll_N245CFG          0x300003D40
#define Rcc_u32Pll_N246CFG          0x300003D80
#define Rcc_u32Pll_N247CFG          0x300003DC0
#define Rcc_u32Pll_N248CFG          0x300003E00
#define Rcc_u32Pll_N249CFG          0x300003E40
#define Rcc_u32Pll_N250CFG          0x300003E80
#define Rcc_u32Pll_N251CFG          0x300003EC0
#define Rcc_u32Pll_N252CFG          0x300003F00
#define Rcc_u32Pll_N253CFG          0x300003F40
#define Rcc_u32Pll_N254CFG          0x300003F80
#define Rcc_u32Pll_N255CFG          0x300003FC0
#define Rcc_u32Pll_N256CFG          0x300004000
#define Rcc_u32Pll_N257CFG          0x300004040
#define Rcc_u32Pll_N258CFG          0x300004080
#define Rcc_u32Pll_N259CFG          0x3000040C0
#define Rcc_u32Pll_N260CFG          0x300004100
#define Rcc_u32Pll_N261CFG          0x300004140
#define Rcc_u32Pll_N262CFG          0x300004180
#define Rcc_u32Pll_N263CFG          0x3000041C0
#define Rcc_u32Pll_N264CFG          0x300004200
#define Rcc_u32Pll_N265CFG          0x300004240
#define Rcc_u32Pll_N266CFG          0x300004280
#define Rcc_u32Pll_N267CFG          0x3000042C0
#define Rcc_u32Pll_N268CFG          0x300004300
#define Rcc_u32Pll_N269CFG          0x300004340
#define Rcc_u32Pll_N270CFG          0x300004380
#define Rcc_u32Pll_N271CFG          0x3000043C0
#define Rcc_u32Pll_N272CFG          0x300004400
#define Rcc_u32Pll_N273CFG          0x300004440
#define Rcc_u32Pll_N274CFG          0x300004480
#define Rcc_u32Pll_N275CFG          0x3000044C0
#define Rcc_u32Pll_N276CFG          0x300004500
#define Rcc_u32Pll_N277CFG          0x300004540
#define Rcc_u32Pll_N278CFG          0x300004580
#define Rcc_u32Pll_N279CFG          0x3000045C0
#define Rcc_u32Pll_N280CFG          0x300004600
#define Rcc_u32Pll_N281CFG          0x300004640
#define Rcc_u32Pll_N282CFG          0x300004680
#define Rcc_u32Pll_N283CFG          0x3000046C0
#define Rcc_u32Pll_N284CFG          0x300004700
#define Rcc_u32Pll_N285CFG          0x300004740
#define Rcc_u32Pll_N286CFG          0x300004780
#define Rcc_u32Pll_N287CFG          0x3000047C0
#define Rcc_u32Pll_N288CFG          0x300004800
#define Rcc_u32Pll_N289CFG          0x300004840
#define Rcc_u32Pll_N290CFG          0x300004880
#define Rcc_u32Pll_N291CFG          0x3000048C0
#define Rcc_u32Pll_N292CFG          0x300004900
#define Rcc_u32Pll_N293CFG          0x300004940
#define Rcc_u32Pll_N294CFG          0x300004980
#define Rcc_u32Pll_N295CFG          0x3000049C0
#define Rcc_u32Pll_N296CFG          0x300004A00
#define Rcc_u32Pll_N297CFG          0x300004A40
#define Rcc_u32Pll_N298CFG          0x300004A80
#define Rcc_u32Pll_N299CFG          0x300004AC0
#define Rcc_u32Pll_N300CFG          0x300004B00
#define Rcc_u32Pll_N301CFG          0x300004B40
#define Rcc_u32Pll_N302CFG          0x300004B80
#define Rcc_u32Pll_N303CFG          0x300004BC0
#define Rcc_u32Pll_N304CFG          0x300004C00
#define Rcc_u32Pll_N305CFG          0x300004C40
#define Rcc_u32Pll_N306CFG          0x300004C80
#define Rcc_u32Pll_N307CFG          0x300004CC0
#define Rcc_u32Pll_N308CFG          0x300004D00
#define Rcc_u32Pll_N309CFG          0x300004D40
#define Rcc_u32Pll_N310CFG          0x300004D80
#define Rcc_u32Pll_N311CFG          0x300004DC0
#define Rcc_u32Pll_N312CFG          0x300004E00
#define Rcc_u32Pll_N313CFG          0x300004E40
#define Rcc_u32Pll_N314CFG          0x300004E80
#define Rcc_u32Pll_N315CFG          0x300004EC0
#define Rcc_u32Pll_N316CFG          0x300004F00
#define Rcc_u32Pll_N317CFG          0x300004F40
#define Rcc_u32Pll_N318CFG          0x300004F80
#define Rcc_u32Pll_N319CFG          0x300004FC0
#define Rcc_u32Pll_N320CFG          0x300005000
#define Rcc_u32Pll_N321CFG          0x300005040
#define Rcc_u32Pll_N322CFG          0x300005080
#define Rcc_u32Pll_N323CFG          0x3000050C0
#define Rcc_u32Pll_N324CFG          0x300005100
#define Rcc_u32Pll_N325CFG          0x300005140
#define Rcc_u32Pll_N326CFG          0x300005180
#define Rcc_u32Pll_N327CFG          0x3000051C0
#define Rcc_u32Pll_N328CFG          0x300005200
#define Rcc_u32Pll_N329CFG          0x300005240
#define Rcc_u32Pll_N330CFG          0x300005280
#define Rcc_u32Pll_N331CFG          0x3000052C0
#define Rcc_u32Pll_N332CFG          0x300005300
#define Rcc_u32Pll_N333CFG          0x300005340
#define Rcc_u32Pll_N334CFG          0x300005380
#define Rcc_u32Pll_N335CFG          0x3000053C0
#define Rcc_u32Pll_N336CFG          0x300005400
#define Rcc_u32Pll_N337CFG          0x300005440
#define Rcc_u32Pll_N338CFG          0x300005480
#define Rcc_u32Pll_N339CFG          0x3000054C0
#define Rcc_u32Pll_N340CFG          0x300005500
#define Rcc_u32Pll_N341CFG          0x300005540
#define Rcc_u32Pll_N342CFG          0x300005580
#define Rcc_u32Pll_N343CFG          0x3000055C0
#define Rcc_u32Pll_N344CFG          0x300005600
#define Rcc_u32Pll_N345CFG          0x300005640
#define Rcc_u32Pll_N346CFG          0x300005680
#define Rcc_u32Pll_N347CFG          0x3000056C0
#define Rcc_u32Pll_N348CFG          0x300005700
#define Rcc_u32Pll_N349CFG          0x300005740
#define Rcc_u32Pll_N350CFG          0x300005780
#define Rcc_u32Pll_N351CFG          0x3000057C0
#define Rcc_u32Pll_N352CFG          0x300005800
#define Rcc_u32Pll_N353CFG          0x300005840
#define Rcc_u32Pll_N354CFG          0x300005880
#define Rcc_u32Pll_N355CFG          0x3000058C0
#define Rcc_u32Pll_N356CFG          0x300005900
#define Rcc_u32Pll_N357CFG          0x300005940
#define Rcc_u32Pll_N358CFG          0x300005980
#define Rcc_u32Pll_N359CFG          0x3000059C0
#define Rcc_u32Pll_N360CFG          0x300005A00
#define Rcc_u32Pll_N361CFG          0x300005A40
#define Rcc_u32Pll_N362CFG          0x300005A80
#define Rcc_u32Pll_N363CFG          0x300005AC0
#define Rcc_u32Pll_N364CFG          0x300005B00
#define Rcc_u32Pll_N365CFG          0x300005B40
#define Rcc_u32Pll_N366CFG          0x300005B80
#define Rcc_u32Pll_N367CFG          0x300005BC0
#define Rcc_u32Pll_N368CFG          0x300005C00
#define Rcc_u32Pll_N369CFG          0x300005C40
#define Rcc_u32Pll_N370CFG          0x300005C80
#define Rcc_u32Pll_N371CFG          0x300005CC0
#define Rcc_u32Pll_N372CFG          0x300005D00
#define Rcc_u32Pll_N373CFG          0x300005D40
#define Rcc_u32Pll_N374CFG          0x300005D80
#define Rcc_u32Pll_N375CFG          0x300005DC0
#define Rcc_u32Pll_N376CFG          0x300005E00
#define Rcc_u32Pll_N377CFG          0x300005E40
#define Rcc_u32Pll_N378CFG          0x300005E80
#define Rcc_u32Pll_N379CFG          0x300005EC0
#define Rcc_u32Pll_N380CFG          0x300005F00
#define Rcc_u32Pll_N381CFG          0x300005F40
#define Rcc_u32Pll_N382CFG          0x300005F80
#define Rcc_u32Pll_N383CFG          0x300005FC0
#define Rcc_u32Pll_N384CFG          0x300006000
#define Rcc_u32Pll_N385CFG          0x300006040
#define Rcc_u32Pll_N386CFG          0x300006080
#define Rcc_u32Pll_N387CFG          0x3000060C0
#define Rcc_u32Pll_N388CFG          0x300006100
#define Rcc_u32Pll_N389CFG          0x300006140
#define Rcc_u32Pll_N390CFG          0x300006180
#define Rcc_u32Pll_N391CFG          0x3000061C0
#define Rcc_u32Pll_N392CFG          0x300006200
#define Rcc_u32Pll_N393CFG          0x300006240
#define Rcc_u32Pll_N394CFG          0x300006280
#define Rcc_u32Pll_N395CFG          0x3000062C0
#define Rcc_u32Pll_N396CFG          0x300006300
#define Rcc_u32Pll_N397CFG          0x300006340
#define Rcc_u32Pll_N398CFG          0x300006380
#define Rcc_u32Pll_N399CFG          0x3000063C0
#define Rcc_u32Pll_N400CFG          0x300006400
#define Rcc_u32Pll_N401CFG          0x300006440
#define Rcc_u32Pll_N402CFG          0x300006480
#define Rcc_u32Pll_N403CFG          0x3000064C0
#define Rcc_u32Pll_N404CFG          0x300006500
#define Rcc_u32Pll_N405CFG          0x300006540
#define Rcc_u32Pll_N406CFG          0x300006580
#define Rcc_u32Pll_N407CFG          0x3000065C0
#define Rcc_u32Pll_N408CFG          0x300006600
#define Rcc_u32Pll_N409CFG          0x300006640
#define Rcc_u32Pll_N410CFG          0x300006680
#define Rcc_u32Pll_N411CFG          0x3000066C0
#define Rcc_u32Pll_N412CFG          0x300006700
#define Rcc_u32Pll_N413CFG          0x300006740
#define Rcc_u32Pll_N414CFG          0x300006780
#define Rcc_u32Pll_N415CFG          0x3000067C0
#define Rcc_u32Pll_N416CFG          0x300006800
#define Rcc_u32Pll_N417CFG          0x300006840
#define Rcc_u32Pll_N418CFG          0x300006880
#define Rcc_u32Pll_N419CFG          0x3000068C0
#define Rcc_u32Pll_N420CFG          0x300006900
#define Rcc_u32Pll_N421CFG          0x300006940
#define Rcc_u32Pll_N422CFG          0x300006980
#define Rcc_u32Pll_N423CFG          0x3000069C0
#define Rcc_u32Pll_N424CFG          0x300006A00
#define Rcc_u32Pll_N425CFG          0x300006A40
#define Rcc_u32Pll_N426CFG          0x300006A80
#define Rcc_u32Pll_N427CFG          0x300006AC0
#define Rcc_u32Pll_N428CFG          0x300006B00
#define Rcc_u32Pll_N429CFG          0x300006B40
#define Rcc_u32Pll_N430CFG          0x300006B80
#define Rcc_u32Pll_N431CFG          0x300006BC0
#define Rcc_u32Pll_N432CFG          0x300006C00

#define Rcc_u32APB1_NDIVCFG          0x400000000
#define Rcc_u32APB1_DIV2CFG          0x400000800
#define Rcc_u32APB1_DIV4CFG          0x400001000
#define Rcc_u32APB1_DIV8CFG          0x400002000
#define Rcc_u32APB1_DIV16CFG         0x400004000

#define Rcc_u32APB2_NDIVCFG          0x500000000
#define Rcc_u32APB2_DIV2CFG          0x500004000
#define Rcc_u32APB2_DIV4CFG          0x500008000
#define Rcc_u32APB2_DIV8CFG          0x500010000
#define Rcc_u32APB2_DIV16CFG         0x500020000

#define Rcc_u32AHB_DIV2CFG           0x600000020
#define Rcc_u32AHB_DIV4CFG           0x600000040
#define Rcc_u32AHB_DIV8CFG           0x600000080
#define Rcc_u32AHB_DIV16CFG          0x600000100
#define Rcc_u32AHB_DIV64CFG          0x600000400
#define Rcc_u32AHB_DIV128CFG         0x600000800
#define Rcc_u32AHB_DIV256CFG         0x600001000
#define Rcc_u32AHB_DIV512CFG         0x600002000


#define Rcc_u8AHB1_BUS               0x71
#define Rcc_u8AHB2_BUS               0x72
#define Rcc_u8APB1_BUS               0x73
#define Rcc_u8APB2_BUS               0x74

#define Rcc_u32DMA1EN_Perpheral_AHB1      0x800200000
#define Rcc_u32DMA2EN_Perpheral_AHB1      0x800400000
#define Rcc_u32CRCEN_Perpheral_AHB1       0x800001000
#define Rcc_u32GPIOHEN_Perpheral_AHB1     0x800000080
#define Rcc_u32GPIOEEN_Perpheral_AHB1     0x800000010
#define Rcc_u32GPIODEN_Perpheral_AHB1     0x800000008
#define Rcc_u32GPIOCEN_Perpheral_AHB1     0x800000004
#define Rcc_u32GPIOBEN_Perpheral_AHB1     0x800000002
#define Rcc_u32GPIOAEN_Perpheral_AHB1     0x800000001

#define Rcc_u32OTGFSEN_Perpheral_AHB2     0x900000080

#define Rcc_u32PWREN_Perpheral_APB1       0xA10000000
#define Rcc_u32I2C3EN_Perpheral_APB1      0xA00800000
#define Rcc_u32I2C2EN_Perpheral_APB1      0xA00400000
#define Rcc_u32I2C1EN_Perpheral_APB1      0xA00200000
#define Rcc_u32USART2EN_Perpheral_APB1    0xA00020000
#define Rcc_u32SPI3EN_Perpheral_APB1      0xA00008000
#define Rcc_u32SPI2EN_Perpheral_APB1      0xA00004000
#define Rcc_u32WWDGEN_Perpheral_APB1      0xA00000800
#define Rcc_u32TIM5EN_Perpheral_APB1      0xA00000008
#define Rcc_u32TIM4EN_Perpheral_APB1      0xA00000004
#define Rcc_u32TIM3EN_Perpheral_APB1      0xA00000002
#define Rcc_u32TIM2EN_Perpheral_APB1      0xA00000001


#define Rcc_u32TIM11EN_Perpheral_APB2     0xB00040000
#define Rcc_u32TIM10EN_Perpheral_APB2     0xB00020000
#define Rcc_u32TIM9EN_Perpheral_APB2      0xB00010000
#define Rcc_u32SYSCFGEN_Perpheral_APB2    0xB00004000
#define Rcc_u32SPI4EN_Perpheral_APB2      0xB00002000
#define Rcc_u32SPI1EN_Perpheral_APB2      0xB00001000
#define Rcc_u32SDIOEN_Perpheral_APB2      0xB00000800
#define Rcc_u32ADC1EN_Perpheral_APB2      0xB00000100
#define Rcc_u32USART6EN_Perpheral_APB2    0xB00000020
#define Rcc_u32USART1EN_Perpheral_APB2    0xB00000010
#define Rcc_u32TIM1EN_Perpheral_APB2      0xB00000001


typedef enum
{
	Rcc_enuOk,
	Rcc_enuSysClk_Select_Error,
	Rcc_enuClk_Control_Error,
	Rcc_enuPllSCR_Cfg_Error,
	Rcc_enuPllM_Cfg_Error,
	Rcc_enuPllN_Cfg_Error,
	Rcc_enuPllP_Cfg_Error,
	Rcc_enuPllQ_Cfg_Error,
	Rcc_enuAHB_Cfg_Error,
	Rcc_enuAPB1_Cfg_Error,
	Rcc_enuAPB2_Cfg_Error,
	Rcc_enuBUSSLK_Perph_Error,
	Rcc_enuAHBPerph_Arg_Error,
	Rcc_enuAPB1Perph_Arg_Error,
	Rcc_enuApB2Perph_Arg_Error,

}Rcc_tenuErrorStatus;


Rcc_tenuErrorStatus Rcc_enuSelect_SysClk(u64 Copy_u64SClk);
Rcc_tenuErrorStatus Rcc_enuControlClk(u64 Copy_u64Clk,u8 Copy_u8ClkState);
u8 Rcc_u8IsClkReady(u64 Copy_u64SClk);


/*
 *
 * Copy_u8PllM : The software has to set these bits correctly to ensure that the VCO input frequency
 *               ranges from 1 to 2 MHz. It is recommended to select a frequency of 2 MHz to limit PLL jitter.
 *               VCO input frequency = PLL input clock frequency / PLLM with 2 <= Copy_u8PllM <= 63
 *
 * Copy_u8PllP : The software has to set these bits correctly not to exceed 84 MHz on this domain.
 *               PLL output clock frequency = VCO frequency / Copy_u8PllP with Copy_u8PllP = 2, 4, 6, or 8
 *
 * Copy_u8PllQ :  The USB OTG FS requires a 48 MHz clock to work correctly.
 *               The SDIO and the random number generator need a frequency lower than or equal to 48 MHz to work correctly.
 *               USB OTG FS clock frequency = VCO frequency / Copy_u8PllQ with 2 <= Copy_u8PllQ <= 15
 *
 * Copy_u8PllN : The software has to set these bits correctly to ensure that the VCO output frequency is between 192 and 432 MHz
 *
 */
Rcc_tenuErrorStatus Rcc_enuPll_Cfg(u64 Copy_u32PllSCR,u64 Copy_u32PllM, u64 Copy_u32PllP, u64 Copy_u32PllQ, u64 Copy_u16PllN);



/*
 * Copy_u8APB1_PRESC : The software has to set these bits correctly not to exceed 42 MHz on this domain.
 *                     The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after PPRE1 write.
 *                     0xx: AHB clock not divided
 *                     100: AHB clock divided by 2 Rcc_u32APB1_DIV2CFG
 *                     101: AHB clock divided by 4 Rcc_u32APB1_DIV4CFG
 *                     110: AHB clock divided by 8 Rcc_u32APB1_DIV8CFG
 *                     111: AHB clock divided by 16 Rcc_u32PBP1_DIV16CFG
 *
 *
 * Copy_u8APB2_PRESC : The software has to set these bits correctly not to exceed 84 MHz on this domain
 *                     The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after PPRE1 write.
 *                     0xx: AHB clock not divided
 *                     100: AHB clock divided by 2 Rcc_u32APB2_DIV2CFG
 *                     101: AHB clock divided by 4 Rcc_u32APB2_DIV4CFG
 *                     110: AHB clock divided by 8 Rcc_u32APB2_DIV8CFG
 *                     111: AHB clock divided by 16 Rcc_u32APB2_DIV16CFG
 *
 */
Rcc_tenuErrorStatus Rcc_enuCtrlBus_Prescaler(u64 Copy_u16AHB_PRESC,u64 Copy_u8APB1_PRESC, u64 Copy_u8APB2_PRESC);


Rcc_tenuErrorStatus Rcc_enuPerpheralClk_Control(u8 Copy_u8Bus,u64 Copy_u64Perpheral,u8 Copy_u8PerphClkState);



#endif /* RCC_H_ */
