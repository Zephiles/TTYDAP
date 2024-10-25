#include <AP/tou.h>
#include <ttyd/evt_cam.h>
#include <ttyd/evt_npc.h>
#include <ttyd/evt_nannpc.h>
#include <ttyd/evt_msg.h>
#include <ttyd/evt_map.h>
#include <ttyd/evt_hit.h>
#include <ttyd/evt_mario.h>
#include <ttyd/evt_party.h>
#include <ttyd/evt_bero.h>
#include <ttyd/evt_snd.h>
#include <ttyd/evt_urouro.h>
#include "evt_cmd.h"
#include "common_types.h"
#include "patch.h"

using namespace mod;
using namespace ttyd;

extern int32_t evt_open[];
extern int32_t talk_gardman[];
extern int32_t evt_tou_match_make_default_sub[];
extern int32_t evt_tou_match_make_default[];
extern int32_t evt_tou_match_after_default[];
extern int32_t tou_00_init_evt[];
extern int32_t talk_sakaba[];
extern int32_t talk_hot[];
extern int32_t init_papa[];
extern int32_t talk_papa[];
extern int32_t init_mama[];
extern int32_t talk_mama[];
extern int32_t init_konari[];
extern int32_t talk_konari[];
extern int32_t talk_musume[];
extern int32_t init_musume_1[];
extern int32_t init_musume_2[];
extern int32_t init_musume_3[];
extern int32_t talk_kino_1[];
extern int32_t talk_kino_2[];
extern int32_t talk_roten_1[];
extern int32_t talk_roten_2[];
extern int32_t talk_jugem_1[];
extern int32_t talk_jugem_2[];
extern int32_t talk_bijyo[];
extern int32_t init_kiza[];
extern int32_t talk_kiza[];
extern int32_t init_sarary[];
extern int32_t evt_uron[];
extern int32_t evt_tamago_sleep[];
extern int32_t evt_tamago_move[];
extern int32_t evt_tamago[];
extern int32_t talk_tamago[];
extern int32_t evt_gondora[];
extern int32_t evt_gondora2[];
extern int32_t evt_peach_after[];
extern int32_t tou_evt_key_01[];
extern int32_t tou_01_init_evt[];
extern int32_t evt_move_g[];
extern int32_t init_gard1[];
extern int32_t talk_gard1[];
extern int32_t init_gard2[];
extern int32_t talk_gard2[];
extern int32_t init_madam[];
extern int32_t talk_madam[];
extern int32_t talk_repo[];
extern int32_t talk_cam1[];
extern int32_t init_cam2[];
extern int32_t talk_cam2[];
extern int32_t talk_kino4[];
extern int32_t talk_kino5[];
extern int32_t talk_kinopiko[];
extern int32_t talk_kinopio_f[];
extern int32_t init_chu[];
extern int32_t talk_chu[];
extern int32_t init_champ[];
extern int32_t talk_champ[];
extern int32_t init_shikowa[];
extern int32_t talk_shikowa[];
extern int32_t init_uranoko[];
extern int32_t tou_talk_uranoko_02[];
extern int32_t init_ironA[];
extern int32_t talk_ironA[];
extern int32_t init_ironB[];
extern int32_t talk_ironB[];
extern int32_t init_borodo[];
extern int32_t talk_borodo[];
extern int32_t evt_tougi2[];
extern int32_t evt_momikucha[];
extern int32_t tou_evt_key_02[];
extern int32_t evt_poster_8[];
extern int32_t tou_02_init_evt[];
extern int32_t init_g_1[];
extern int32_t talk_g_1[];
extern int32_t move_g_1[];
extern int32_t init_g_2[];
extern int32_t talk_g_2[];
extern int32_t move_g_2[];
extern int32_t init_g_4[];
extern int32_t talk_g_4[];
extern int32_t move_g_4[];
extern int32_t talk_g_7[];
extern int32_t talk_g_8[];
extern int32_t talk_g_9[];
extern int32_t init_g_10[];
extern int32_t talk_g_10[];
extern int32_t init_g_11[];
extern int32_t talk_g_11[];
extern int32_t tou_init_brots_05[];
extern int32_t evt_gardman[];
extern int32_t tou_evt_lock_04[];
extern int32_t tou_04_init_evt[];
extern int32_t evt_takurami[];
extern int32_t evt_hiki_open[];
extern int32_t init_gans[];
extern int32_t talk_gans[];
extern int32_t init_kinoshikowa[];
extern int32_t talk_kinoshikowa[];
extern int32_t evt_sensyu2[];
extern int32_t evt_nozoki[];
extern int32_t tou_05_init_evt[];
extern int32_t evt_kontena[];
extern int32_t evt_kaidan[];
extern int32_t tou_evt_block_broken_06[];
extern int32_t tou_evt_lock_06[];
extern int32_t evt_chuchu[];
extern int32_t tou_06_init_evt[];
extern int32_t evt_champion[];
extern int32_t tou_evt_dakuto_07[];
extern int32_t tou_07_init_evt[];
extern int32_t evt_toile[];
extern int32_t talk_togenoko[];
extern int32_t talk_togemet[];
extern int32_t talk_hammerbros[];
extern int32_t tou_talk_uranoko_08[];
extern int32_t evt_1st_leagu[];
extern int32_t evt_toile_door[];
extern int32_t tou_08_init_evt[];
extern int32_t tou_09_init_evt[];
extern int32_t init_kino[];
extern int32_t talk_kino[];
extern int32_t tou_init_michel_10[];
extern int32_t talk_michel[];
extern int32_t talk_octo[];
extern int32_t tou_init_brots_10[];
extern int32_t talk_brots[];
extern int32_t talk_gangan[];
extern int32_t init_poku[];
extern int32_t talk_poku[];
extern int32_t init_iron[];
extern int32_t talk_iron[];
extern int32_t init_iron2[];
extern int32_t talk_iron2[];
extern int32_t evt_saisyo_after[];
extern int32_t evt_okorareru[];
extern int32_t tou_evt_block_10[];
extern int32_t tou_10_init_evt[];
extern int32_t tou_11_init_evt[];
extern int32_t tou_evt_block_broken_12[];
extern int32_t tou_init_michel_12[];
extern int32_t init_michel_dummy[];
extern int32_t tou_init_brots_12[];
extern int32_t init_brots_dummy[];
extern int32_t tou_12_init_evt[];
extern int32_t tou_evt_dakuto_13[];
extern int32_t evt_nusumi[];
extern int32_t evt_first[];
extern int32_t tou_13_init_evt[];

EVT_BEGIN(talk_sakaba_evt)
	IF_EQUAL(GSW(1707), 99) //Unknown
		IF_EQUAL(GSWF(3877), 1)
			SET(GSWF(3879), 1)
			USER_FUNC(evt_msg::evt_msg_print, 0, PTR("stg7_tou_01"), 0, 0)
		ELSE()
			USER_FUNC(evt_msg::evt_msg_print, 0, PTR("stg3_tou_06"), 0, 0)
		END_IF()
		RETURN()
	END_IF()
	USER_FUNC(evt_msg::evt_msg_print, 0, PTR("stg3_tou_297_09"), 0, 0)
	RETURN()
EVT_END()

EVT_BEGIN(talk_sakaba_hook)
	RUN_CHILD_EVT(talk_sakaba_evt)
	GOTO(&talk_sakaba[367])
EVT_END()

void ApplyTouPatches(OSModuleInfo* module_info)
{
	evt_open[1] = GSW(1703);
	evt_open[2] = 6;

	talk_gardman[15] = GSW(1703);
	talk_gardman[16] = 11;
	talk_gardman[18] = GSW(1703);
	talk_gardman[19] = 12;
	talk_gardman[173] = GSW(1703);
	talk_gardman[174] = 172;

	evt_tou_match_make_default_sub[147] = GSW(1703);
	evt_tou_match_make_default_sub[148] = 99; //Unknown
	evt_tou_match_make_default_sub[225] = GSW(1703);
	evt_tou_match_make_default_sub[226] = 99; //Unknown
	evt_tou_match_make_default_sub[312] = GSW(1703);
	evt_tou_match_make_default_sub[313] = 99; //Unknown
	evt_tou_match_make_default_sub[388] = GSW(1703);
	evt_tou_match_make_default_sub[389] = 99; //Unknown

	evt_tou_match_make_default[117] = GSW(1703);
	evt_tou_match_make_default[119] = 99; //Unknown
	evt_tou_match_make_default[120] = 99; //Unknown
	evt_tou_match_make_default[142] = 99; //Unknown
	evt_tou_match_make_default[158] = 99; //Unknown
	evt_tou_match_make_default[159] = 99; //Unknown
	evt_tou_match_make_default[164] = 99; //Unknown
	evt_tou_match_make_default[165] = 99; //Unknown
	evt_tou_match_make_default[170] = 99; //Unknown
	evt_tou_match_make_default[171] = 99; //Unknown
	evt_tou_match_make_default[176] = 99; //Unknown

	evt_tou_match_after_default[31] = GSW(1703);
	evt_tou_match_after_default[32] = 11;
	evt_tou_match_after_default[34] = GSW(1703);
	evt_tou_match_after_default[35] = 12;
	evt_tou_match_after_default[1316] = GSW(1703);
	evt_tou_match_after_default[1317] = 172;
	evt_tou_match_after_default[1380] = GSW(1703);
	evt_tou_match_after_default[1381] = 12;
	evt_tou_match_after_default[1394] = GSW(1703);
	evt_tou_match_after_default[1395] = 12;

	tou_00_init_evt[7] = GSW(1704);
	tou_00_init_evt[8] = 99; //Unknown
	tou_00_init_evt[68] = GSW(1703);
	tou_00_init_evt[69] = 2;

	talk_sakaba[23] = GSWF(6026);
	talk_sakaba[24] = EVT_HELPER_OP(0, 0);
	talk_sakaba[25] = EVT_HELPER_OP(0, 0);
	talk_sakaba[26] = EVT_HELPER_OP(0, 0);
	talk_sakaba[27] = EVT_HELPER_OP(0, 0);
	talk_sakaba[28] = EVT_HELPER_OP(0, 0);
	talk_sakaba[29] = EVT_HELPER_OP(0, 0);
	talk_sakaba[30] = EVT_HELPER_OP(0, 0);
	talk_sakaba[31] = EVT_HELPER_OP(0, 0);
	talk_sakaba[276] = EVT_HELPER_OP(0, 49);
	patch::writePatch(&talk_sakaba[277], talk_sakaba_hook, sizeof(talk_sakaba_hook));

	init_papa[1] = GSW(1706);
	init_papa[3] = 1;

	talk_papa[1] = GSW(1703);
	talk_papa[3] = 5;
	talk_papa[11] = 99; //Unknown

	init_mama[1] = GSW(1706);
	init_mama[3] = 1;

	talk_mama[1] = GSW(1703);
	talk_mama[3] = 5;
	talk_mama[11] = 99; //Unknown

	init_konari[1] = GSW(1706);
	init_konari[3] = 1;

	talk_konari[1] = GSW(1703);
	talk_konari[3] = 5;
	talk_konari[11] = 99; //Unknown

	talk_musume[1] = GSW(1703);
	talk_musume[3] = 5;
	talk_musume[23] = 99; //Unknown

	init_musume_1[1] = GSW(1703);
	init_musume_1[3] = 2;
	init_musume_1[4] = 99; //Unknown

	init_musume_2[1] = GSW(1703);
	init_musume_2[3] = 2;
	init_musume_2[4] = 99; //Unknown

	init_musume_3[1] = GSW(1703);
	init_musume_3[3] = 2;
	init_musume_3[4] = 99; //Unknown

	talk_kino_1[1] = GSW(1703);
	talk_kino_1[3] = 5;
	talk_kino_1[11] = 99; //Unknown

	talk_kino_2[1] = GSW(1703);
	talk_kino_2[3] = 5;
	talk_kino_2[11] = 99; //Unknown

	talk_roten_1[1] = GSW(1703);
	talk_roten_1[3] = 5;
	talk_roten_1[11] = 99; //Unknown

	talk_roten_2[1] = GSW(1703);
	talk_roten_2[3] = 5;
	talk_roten_2[11] = 99; //Unknown

	talk_jugem_1[1] = GSW(1703);
	talk_jugem_1[3] = 5;
	talk_jugem_1[11] = 99; //Unknown

	talk_jugem_2[1] = GSW(1703);
	talk_jugem_2[3] = 5;
	talk_jugem_2[11] = 99; //Unknown

	talk_bijyo[1] = GSW(1703);
	talk_bijyo[3] = 5;
	talk_bijyo[11] = 99; //Unknown

	init_kiza[1] = GSW(1706);
	init_kiza[3] = 2;
	init_kiza[4] = 99; //Unknown

	talk_kiza[1] = GSW(1703);
	talk_kiza[3] = 5;
	talk_kiza[11] = 99; //Unknown

	init_sarary[1] = GSW(1706);
	init_sarary[2] = 99; //Unknown

	evt_uron[191] = GSW(1703);
	evt_uron[192] = 3;

	evt_tamago_sleep[3] = GSW(1703);
	evt_tamago_sleep[4] = 10;

	evt_tamago_move[240] = GSW(1703);
	evt_tamago_move[241] = 10;

	evt_tamago[93] = GSW(1703);
	evt_tamago[94] = 9;

	talk_tamago[24] = GSW(1703);
	talk_tamago[25] = 11;

	evt_gondora[159] = GSW(1703);
	evt_gondora[160] = 2;

	evt_gondora2[161] = GSW(1703);
	evt_gondora2[162] = 99; //Unknown

	evt_peach_after[82] = GSW(1703);
	evt_peach_after[83] = 99; //Unknown

	tou_evt_key_01[1] = GSWF(6027);
	tou_evt_key_01[2] = 1;

	tou_evt_key_02[10] = GSWF(6028);
	tou_evt_key_02[11] = 1;

	tou_01_init_evt[107] = GSW(1708);
	tou_01_init_evt[108] = 99; //Unknown
	tou_01_init_evt[211] = GSWF(6027);
	tou_01_init_evt[212] = 0;
	tou_01_init_evt[313] = GSW(1703);
	tou_01_init_evt[314] = 10;
	tou_01_init_evt[333] = GSW(1703);
	tou_01_init_evt[334] = 11;
	tou_01_init_evt[1422] = GSW(1708);
	tou_01_init_evt[1423] = 99; //Unknown
	tou_01_init_evt[1466] = GSW(1703);
	tou_01_init_evt[1468] = 9;
	tou_01_init_evt[1485] = 10;
	tou_01_init_evt[1516] = 11;
	tou_01_init_evt[1589] = GSW(1703);
	tou_01_init_evt[1590] = 99; //Unknown
	tou_01_init_evt[1615] = GSW(1708);
	tou_01_init_evt[1616] = 99; //Unknown

	evt_move_g[51] = GSW(1703);
	evt_move_g[52] = 3;
	evt_move_g[54] = GSW(1703);
	evt_move_g[55] = 3;

	init_gard1[1] = GSW(1703);
	init_gard1[3] = 3;
	init_gard1[11] = 99; //Unknown

	talk_gard1[1] = GSW(1703);
	talk_gard1[3] = 2;
	talk_gard1[11] = 3;
	talk_gard1[21] = 5;
	talk_gard1[29] = 99; //Unknown

	init_gard2[1] = GSW(1703);
	init_gard2[3] = 3;
	init_gard2[11] = 99; //Unknown

	talk_gard2[1] = GSW(1703);
	talk_gard2[3] = 2;
	talk_gard2[11] = 3;
	talk_gard2[21] = 5;
	talk_gard2[29] = 99; //Unknown

	init_madam[1] = GSW(1703);
	init_madam[3] = 99; //Unknown
	init_madam[11] = 99; //Unknown

	talk_madam[1] = GSW(1703);
	talk_madam[3] = 5;
	talk_madam[11] = 99; //Unknown

	talk_repo[1] = GSW(1703);
	talk_repo[3] = 5;
	talk_repo[11] = 99; //Unknown

	talk_cam1[1] = GSW(1703);
	talk_cam1[3] = 5;
	talk_cam1[11] = 99; //Unknown

	init_cam2[1] = GSW(1703);
	init_cam2[2] = 2;

	talk_cam2[1] = GSW(1703);
	talk_cam2[3] = 5;
	talk_cam2[11] = 99; //Unknown

	talk_kino4[1] = GSW(1703);
	talk_kino4[3] = 5;
	talk_kino4[11] = 99; //Unknown

	talk_kino5[4] = GSW(1703);
	talk_kino5[6] = 5;
	talk_kino5[14] = 99; //Unknown

	talk_kinopiko[1] = GSW(1703);
	talk_kinopiko[3] = 5;
	talk_kinopiko[11] = 99; //Unknown

	talk_kinopio_f[1] = GSW(1703);
	talk_kinopio_f[3] = 5;
	talk_kinopio_f[11] = 99; //Unknown

	init_chu[1] = GSWF(6028);
	init_chu[3] = 1;

	talk_chu[1] = GSW(1703);
	talk_chu[3] = 5;
	talk_chu[11] = 99; //Unknown

	init_champ[1] = GSW(1703);
	init_champ[3] = 99; //Unknown

	talk_champ[1] = GSW(1703);
	talk_champ[3] = 99;

	init_shikowa[1] = GSW(1703);
	init_shikowa[3] = 99; //Unknown

	talk_shikowa[1] = GSW(1703);
	talk_shikowa[3] = 99;

	init_uranoko[1] = GSW(1703);
	init_uranoko[3] = 99; //Unknown

	tou_talk_uranoko_02[1] = GSW(1703);
	tou_talk_uranoko_02[3] = 99; //Unknown

	init_ironA[1] = GSW(1703);
	init_ironA[3] = 99; //Unknown

	talk_ironA[1] = GSW(1703);
	talk_ironA[3] = 99; //Unknown

	init_ironB[1] = GSW(1703);
	init_ironB[3] = 99; //Unknown

	talk_ironB[1] = GSW(1703);
	talk_ironB[3] = 99; //Unknown
	
	init_borodo[1] = GSW(1703);
	init_borodo[3] = 99; //Unknown

	talk_borodo[1] = GSW(1703);
	talk_borodo[3] = 99; //Unknown

	evt_tougi2[273] = GSW(1703);
	evt_tougi2[274] = 3;

	evt_momikucha[7] = GSW(1703);
	evt_momikucha[8] = 7;

	evt_poster_8[4] = GSWF(6028);
	evt_poster_8[5] = 0;

	tou_02_init_evt[1] = GSW(1703);
	tou_02_init_evt[3] = 2;
	tou_02_init_evt[4] = 11;
	tou_02_init_evt[17] = 99; //Unknown
	tou_02_init_evt[79] = 3;
	tou_02_init_evt[80] = 99; //Unknown
	tou_02_init_evt[93] = GSW(1703);
	tou_02_init_evt[94] = 99; //Unknown
	tou_02_init_evt[111] = GSW(1703);
	tou_02_init_evt[112] = 99; //Unknown
	tou_02_init_evt[131] = GSW(1703);
	tou_02_init_evt[132] = 99; //Unknown
	tou_02_init_evt[897] = GSWF(6028);
	tou_02_init_evt[898] = 0;

	init_g_1[17] = EVT_HELPER_CMD(0, 2);

	talk_g_1[1] = GSW(1703);
	talk_g_1[3] = 7;
	talk_g_1[10] = 0;
	talk_g_1[11] = 0;
	talk_g_1[12] = 0;
	talk_g_1[13] = 0;
	talk_g_1[14] = 0;
	talk_g_1[15] = 0;
	talk_g_1[16] = 0;
	talk_g_1[17] = 0;
	talk_g_1[18] = 0;
	talk_g_1[19] = 0;
	talk_g_1[20] = 0;
	talk_g_1[21] = 0;
	talk_g_1[22] = 0;
	talk_g_1[23] = 0;
	talk_g_1[24] = 0;
	talk_g_1[26] = 99; //Unknown
	talk_g_1[34] = 99; //Unknown
	talk_g_1[40] = 0; //Unused
	talk_g_1[71] = 0; //Unused

	move_g_1[6] = GSW(1703);
	move_g_1[8] = 5;
	move_g_1[19] = 99; //Unknown
	move_g_1[25] = 0;
	move_g_1[41] = 0;

	init_g_2[1] = GSW(1703);
	init_g_2[2] = 99; //Unknown

	talk_g_2[1] = GSW(1703);
	talk_g_2[3] = 7;
	talk_g_2[11] = 99; //Unknown
	talk_g_2[19] = 99; //Unknown

	move_g_2[31] = GSW(1703);
	move_g_2[32] = 99; //Unknown
	move_g_2[45] = GSW(1703);
	move_g_2[46] = 99; //Unknown

	init_g_4[1] = GSW(1703);
	init_g_4[2] = 99; //Unknown

	talk_g_4[1] = GSW(1703);
	talk_g_4[3] = 4;
	talk_g_4[91] = 5;
	talk_g_4[99] = 99; //Unknown
	talk_g_4[107] = 99; //Unknown

	move_g_4[28] = GSW(1703);
	move_g_4[30] = 4;
	move_g_4[32] = 7;
	move_g_4[39] = 99; //Unknown
	move_g_4[71] = 99; //Unknown
	move_g_4[72] = 99; //Unknown

	talk_g_7[1] = GSW(1703);
	talk_g_7[3] = 7;
	talk_g_7[11] = 99; //Unknown

	talk_g_8[1] = GSW(1703);
	talk_g_8[3] = 7;
	talk_g_8[11] = 99; //Unknown

	talk_g_9[1] = GSW(1703);
	talk_g_9[3] = 7;
	talk_g_9[11] = 99; //Unknown
	talk_g_9[19] = 99; //Unknown

	init_g_10[1] = GSW(1703);
	init_g_10[3] = 99; //Unknown
	init_g_10[15] = 99; //Unknown

	talk_g_10[1] = GSW(1703);
	talk_g_10[3] = 99; //Unknown
	talk_g_10[15] = 99; //Unknown

	init_g_11[1] = GSW(1703);
	init_g_11[3] = 99; //Unknown
	init_g_11[15] = 99; //Unknown

	talk_g_11[1] = GSW(1703);
	talk_g_11[3] = 99; //Unknown
	talk_g_11[15] = 99; //Unknown

	tou_init_brots_05[1] = GSW(1703);
	tou_init_brots_05[2] = 99; //Unknown

	evt_gardman[159] = GSW(1703);
	evt_gardman[161] = 6;
	evt_gardman[163] = GSW(1703);
	evt_gardman[164] = 6;

	tou_evt_lock_04[1] = GSWF(6029);
	tou_evt_lock_04[2] = 1;

	tou_04_init_evt[123] = GSW(1703);
	tou_04_init_evt[124] = 99; //Unknown
	tou_04_init_evt[136] = GSW(1703);
	tou_04_init_evt[138] = 2;
	tou_04_init_evt[139] = 11;
	tou_04_init_evt[152] = 99; //Unknown
	tou_04_init_evt[388] = GSW(1703);
	tou_04_init_evt[390] = 4;
	tou_04_init_evt[392] = 5;
	tou_04_init_evt[437] = GSW(1703);
	tou_04_init_evt[438] = 0; //Unused
	tou_04_init_evt[446] = GSW(1703);
	tou_04_init_evt[447] = 0; //Unused
	tou_04_init_evt[455] = GSW(1703);
	tou_04_init_evt[456] = 99; //Unknown
	tou_04_init_evt[494] = GSW(1703);
	tou_04_init_evt[495] = 99; //Unknown
	tou_04_init_evt[513] = GSW(1703);
	tou_04_init_evt[514] = 99; //Unknown
	tou_04_init_evt[578] = GSWF(6029);
	tou_04_init_evt[579] = 1;
	tou_04_init_evt[616] = GSWF(6029);
	tou_04_init_evt[617] = 1;
	tou_04_init_evt[625] = GSW(1703);
	tou_04_init_evt[626] = 0; //Unused
	tou_04_init_evt[631] = GSW(1703);
	tou_04_init_evt[632] = 99; //Unknown

	evt_takurami[337] = GSW(1703);
	evt_takurami[338] = 99; //Unknown

	evt_hiki_open[13] = GSW(1703);
	evt_hiki_open[14] = 99; //Unknown
	evt_hiki_open[135] = GSW(1703);
	evt_hiki_open[136] = 99; //Unknown

	init_gans[1] = GSW(1703);
	init_gans[3] = 4;
	init_gans[15] = 5;

	talk_gans[172] = GSW(1703);
	talk_gans[173] = 4;

	init_kinoshikowa[1] = GSW(1703);
	init_kinoshikowa[3] = 99; //Unknown

	talk_kinoshikowa[373] = GSW(1703);
	talk_kinoshikowa[375] = 99; //Unknown

	evt_sensyu2[194] = GSW(1703);
	evt_sensyu2[195] = 5;

	evt_nozoki[7] = GSWF(6030);
	evt_nozoki[8] = 1;
	evt_nozoki[161] = GSWF(6030);
	evt_nozoki[162] = 1;
	evt_nozoki[691] = GSWF(6030);
	evt_nozoki[692] = 1;

	tou_05_init_evt[132] = GSW(1703);
	tou_05_init_evt[133] = 99; //Unknown
	tou_05_init_evt[175] = GSW(1703);
	tou_05_init_evt[176] = 4;
	tou_05_init_evt[194] = GSWF(6030);
	tou_05_init_evt[195] = 1;
	tou_05_init_evt[256] = GSW(1703);
	tou_05_init_evt[257] = 4;
	tou_05_init_evt[298] = GSW(1703);
	tou_05_init_evt[299] = 99; //Unknown
	tou_05_init_evt[311] = GSW(1703);
	tou_05_init_evt[313] = 2;
	tou_05_init_evt[314] = 11;
	tou_05_init_evt[327] = 99; //Unknown
	tou_05_init_evt[352] = GSW(1703);
	tou_05_init_evt[354] = 99; //Unknown
	tou_05_init_evt[359] = 99; //Unknown
	tou_05_init_evt[411] = GSW(1703);
	tou_05_init_evt[412] = 99; //Unknown

	evt_kontena[17] = GSWF(6031);
	evt_kontena[18] = 1;

	evt_kaidan[80] = GSWF(6032);
	evt_kaidan[81] = 1;

	tou_evt_block_broken_06[1] = GSWF(6033);
	tou_evt_block_broken_06[2] = 1;

	tou_evt_lock_06[1] = GSWF(6034);
	tou_evt_lock_06[2] = 1;

	evt_chuchu[616] = GSWF(6035);
	evt_chuchu[617] = 1;

	tou_06_init_evt[19] = GSWF(6031);
	tou_06_init_evt[20] = 1;
	tou_06_init_evt[46] = GSWF(6031);
	tou_06_init_evt[47] = 1;
	tou_06_init_evt[269] = GSWF(6032);
	tou_06_init_evt[270] = 1;
	tou_06_init_evt[312] = GSWF(6032);
	tou_06_init_evt[313] = 1;
	tou_06_init_evt[330] = GSWF(6032);
	tou_06_init_evt[331] = 1;
	tou_06_init_evt[486] = GSWF(6035);
	tou_06_init_evt[487] = 1;
	tou_06_init_evt[492] = GSW(1703);
	tou_06_init_evt[493] = 99; //Unknown
	tou_06_init_evt[502] = GSW(1703);
	tou_06_init_evt[503] = 2;
	tou_06_init_evt[504] = 11;
	tou_06_init_evt[518] = 99; //Unknown

	evt_champion[568] = GSW(1703);
	evt_champion[569] = 99; //Unknown

	tou_evt_dakuto_07[25] = GSW(1703);
	tou_evt_dakuto_07[26] = 159;
	tou_evt_dakuto_07[28] = GSW(1703);
	tou_evt_dakuto_07[29] = 159;

	tou_07_init_evt[27] = GSW(1703);
	tou_07_init_evt[28] = 158;
	tou_07_init_evt[30] = GSW(1703);
	tou_07_init_evt[31] = 158;
	tou_07_init_evt[68] = GSW(1703);
	tou_07_init_evt[70] = 159;
	tou_07_init_evt[75] = 172;
	tou_07_init_evt[149] = GSW(1703);
	tou_07_init_evt[151] = 2;
	tou_07_init_evt[152] = 11;
	tou_07_init_evt[165] = 165;
	tou_07_init_evt[188] = GSW(1703);
	tou_07_init_evt[189] = 158;
	tou_07_init_evt[195] = GSW(1703);
	tou_07_init_evt[196] = 158;
	tou_07_init_evt[227] = GSW(1703);
	tou_07_init_evt[228] = 163;
	tou_07_init_evt[237] = GSW(1703);
	tou_07_init_evt[239] = 2;
	tou_07_init_evt[240] = 12;

	evt_toile[1] = GSW(1703);
	evt_toile[2] = 157;
	evt_toile[31] = GSW(1703);
	evt_toile[32] = 157;

	talk_togenoko[1] = GSW(1703);
	talk_togenoko[2] = 172;
	talk_togenoko[4] = GSW(1703);
	talk_togenoko[5] = 157;

	talk_togemet[1] = GSW(1703);
	talk_togemet[2] = 172;
	talk_togemet[4] = GSW(1703);
	talk_togemet[5] = 157;

	talk_hammerbros[1] = GSW(1703);
	talk_hammerbros[2] = 172;
	talk_hammerbros[4] = GSW(1703);
	talk_hammerbros[5] = 157;

	tou_talk_uranoko_08[1] = GSW(1703);
	tou_talk_uranoko_08[2] = 172;
	tou_talk_uranoko_08[4] = GSW(1703);
	tou_talk_uranoko_08[5] = 157;

	evt_1st_leagu[743] = GSW(1703);
	evt_1st_leagu[744] = 12;
	
	evt_toile_door[22] = GSW(1703);
	evt_toile_door[23] = 157;
	evt_toile_door[39] = GSW(1703);
	evt_toile_door[40] = 172;

	tou_08_init_evt[6] = 0;
	tou_08_init_evt[15] = 0;
	tou_08_init_evt[24] = 0;
	tou_08_init_evt[49] = GSWF(6036);
	tou_08_init_evt[58] = 0;
	tou_08_init_evt[59] = 0;
	tou_08_init_evt[60] = 0;
	tou_08_init_evt[68] = 0;
	tou_08_init_evt[69] = 0;
	tou_08_init_evt[70] = 0;
	tou_08_init_evt[188] = GSW(1703);
	tou_08_init_evt[190] = 4;
	tou_08_init_evt[202] = GSW(1703);
	tou_08_init_evt[204] = 2;
	tou_08_init_evt[205] = 11;
	tou_08_init_evt[220] = GSW(1708);
	tou_08_init_evt[220] = 402;
	tou_08_init_evt[277] = GSW(1708);
	tou_08_init_evt[278] = 402;

	tou_09_init_evt[1] = GSW(1703);
	tou_09_init_evt[3] = 2;
	tou_09_init_evt[4] = 11;
	tou_09_init_evt[17] = 165;

	init_kino[1] = GSW(1703);
	init_kino[3] = 6;

	talk_kino[1] = GSW(1703);
	talk_kino[3] = 6;

	tou_init_michel_10[1] = GSW(1703);
	tou_init_michel_10[3] = 172;

	talk_michel[1] = GSW(1703);
	talk_michel[2] = 172;

	talk_octo[1] = GSW(1703);
	talk_octo[2] = 172;
	talk_octo[90] = GSW(1703);
	talk_octo[92] = 0;
	talk_octo[93] = 0;

	tou_init_brots_10[1] = GSW(1703);
	tou_init_brots_10[2] = 172;

	talk_brots[1] = GSW(1703);
	talk_brots[2] = 172;

	talk_gangan[1] = GSW(1703);
	talk_gangan[2] = 172;
	talk_gangan[90] = GSW(1703);
	talk_gangan[92] = 0;
	talk_gangan[93] = 0;

	init_poku[6] = GSW(1703);
	init_poku[8] = 172;
	init_poku[20] = 172;

	talk_poku[23] = GSW(1703);
	talk_poku[25] = 0;
	talk_poku[26] = 0;

	init_iron[1] = GSW(1703);
	init_iron[2] = 172;

	talk_iron[1] = GSW(1703);
	talk_iron[2] = 172;

	init_iron2[1] = GSW(1703);
	init_iron2[2] = 172;

	talk_iron2[1] = GSW(1703);
	talk_iron2[2] = 172;

	evt_saisyo_after[723] = GSW(1703);
	evt_saisyo_after[724] = 8;

	evt_okorareru[283] = GSWF(6036);
	evt_okorareru[284] = 1;

	tou_evt_block_10[1] = GSWF(6037);
	tou_evt_block_10[2] = 1;

	tou_10_init_evt[1] = GSW(1703);
	tou_10_init_evt[3] = 2;
	tou_10_init_evt[4] = 11;
	tou_10_init_evt[17] = 165;
	tou_10_init_evt[43] = GSW(1703);
	tou_10_init_evt[44] = 11;
	tou_10_init_evt[46] = GSW(1703);
	tou_10_init_evt[47] = 11;
	tou_10_init_evt[82] = GSW(1703);
	tou_10_init_evt[83] = 7;
	tou_10_init_evt[105] = GSWF(6037);
	tou_10_init_evt[106] = 1;
	tou_10_init_evt[123] = GSW(1703);
	tou_10_init_evt[125] = 6;
	tou_10_init_evt[176] = GSW(1703);
	tou_10_init_evt[177] = 172;
	tou_10_init_evt[197] = GSW(1703);
	tou_10_init_evt[198] = 172;
	tou_10_init_evt[222] = GSWF(6036);
	tou_10_init_evt[223] = 1;
	tou_10_init_evt[236] = GSW(1703);
	tou_10_init_evt[237] = 11;

	tou_11_init_evt[138] = GSW(1703);
	tou_11_init_evt[140] = 2;
	tou_11_init_evt[141] = 11;

	tou_evt_block_broken_12[52] = GSWF(6038);
	tou_evt_block_broken_12[53] = 1;

	tou_init_michel_12[1] = GSW(1703);
	tou_init_michel_12[2] = 20;

	init_michel_dummy[1] = GSW(1703);
	init_michel_dummy[2] = 20;

	tou_init_brots_12[1] = GSW(1703);
	tou_init_brots_12[2] = 20;

	init_brots_dummy[1] = GSW(1703);
	init_brots_dummy[2] = 20;

	tou_12_init_evt[1] = GSW(1703);
	tou_12_init_evt[2] = 19;
	tou_12_init_evt[11] = GSW(1703);
	tou_12_init_evt[13] = 2;
	tou_12_init_evt[14] = 11;
	tou_12_init_evt[27] = 21;
	tou_12_init_evt[71] = GSWF(6038);
	tou_12_init_evt[72] = 1;
	tou_12_init_evt[89] = GSW(1703);
	tou_12_init_evt[90] = 20;

	tou_evt_dakuto_13[30] = GSW(1703);
	tou_evt_dakuto_13[31] = 18;
	tou_evt_dakuto_13[33] = GSW(1703);
	tou_evt_dakuto_13[34] = 18;

	evt_nusumi[178] = GSW(1703);
	evt_nusumi[179] = 17;

	evt_first[38] = GSW(1703);
	evt_first[39] = 16;

	tou_13_init_evt[1] = GSW(1703);
	tou_13_init_evt[3] = 2;
	tou_13_init_evt[4] = 11;
	tou_13_init_evt[17] = 21;
	tou_13_init_evt[50] = GSW(1703);
	tou_13_init_evt[52] = 18;
	tou_13_init_evt[57] = 172;
	tou_13_init_evt[104] = GSW(1703);
	tou_13_init_evt[105] = 17;
	tou_13_init_evt[110] = GSW(1703);
	tou_13_init_evt[111] = 16;

}