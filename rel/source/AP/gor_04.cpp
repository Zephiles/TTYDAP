#include <AP/gor_04.h>
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

extern int32_t hom_10_evt_resha_start_gor_04[];
extern int32_t gor_evt_train[];
extern int32_t evt_train2[];
extern int32_t peach_mail_04[];
extern int32_t jugemu_a_init[];
extern int32_t jugemu_a_talk[];
extern int32_t kinopiko_b_talk_04[];
extern int32_t luigi_init_04[];
extern int32_t luigi_npcEnt_04[];
extern int32_t gor_04_init_evt[];

void ApplyGor04Patches(OSModuleInfo* module_info)
{
	hom_10_evt_resha_start_gor_04[49] = GSW(1706);
	hom_10_evt_resha_start_gor_04[50] = 43;

	gor_evt_train[240] = GSW(1706);
	gor_evt_train[241] = 49;
	gor_evt_train[270] = GSW(1706);
	gor_evt_train[271] = 2;

	evt_train2[223] = GSW(1706);
	evt_train2[224] = 49;
	evt_train2[226] = GSW(1706);
	evt_train2[227] = 49;
	evt_train2[280] = GSW(1706);
	evt_train2[281] = 50;

	peach_mail_04[225] = GSW(1706);
	peach_mail_04[226] = 50;

	jugemu_a_init[1] = GSW(1715);
	jugemu_a_init[2] = 10;

	jugemu_a_talk[1] = GSW(1710); //HOOK
	jugemu_a_talk[3] = 2;
	jugemu_a_talk[11] = 3;
	jugemu_a_talk[19] = 4;
	jugemu_a_talk[27] = 5;
	jugemu_a_talk[35] = 6;
	jugemu_a_talk[43] = 7;
	jugemu_a_talk[51] = 8;

	kinopiko_b_talk_04[1] = GSW(1706); //HOOK
	kinopiko_b_talk_04[3] = 2;
	kinopiko_b_talk_04[11] = 3;
	kinopiko_b_talk_04[19] = 4;
	kinopiko_b_talk_04[27] = 5; 
	kinopiko_b_talk_04[35] = 6;
	kinopiko_b_talk_04[43] = 7;
	kinopiko_b_talk_04[51] = 8;

	luigi_init_04[1] = GSW(1710); //HOOK
	luigi_init_04[3] = 6;
	luigi_init_04[4] = 7;

	luigi_npcEnt_04[1] = GSW(1710);//HOOK
	luigi_npcEnt_04[3] = 6;
	luigi_npcEnt_04[4] = 7;

	gor_04_init_evt[1] = GSW(1715);
	gor_04_init_evt[2] = 10;
	gor_04_init_evt[49] = GSW(1715);
	gor_04_init_evt[50] = 10;
	gor_04_init_evt[185] = GSW(1706);
	gor_04_init_evt[186] = 49;
	gor_04_init_evt[191] = GSW(1715);
	gor_04_init_evt[192] = 10;
	gor_04_init_evt[222] = GSW(1706);
	gor_04_init_evt[223] = 48;
}