#include <cstdint>
#include <cstring>
#include <cstdio>
#include <ttyd/itemdrv.h>
#include <ttyd/item_data.h>
#include <ttyd/common_types.h>
#include <gc/OSLink.h>
#include <OWR_STATE.h>
#include <ttyd/swdrv.h>
#include <ttyd/mario_party.h>
#include <ttyd/mario_pouch.h>
#include <ttyd/party.h>
#include <ttyd/msgdrv.h>
#include <ttyd/fontmgr.h>
#include <ttyd/seqdrv.h>
#include <ttyd/string.h>
#include <ttyd/event.h>
#include <AP/aaa.h>
#include <AP/aji.h>
#include <AP/bom.h>
#include <AP/dou.h>
#include <AP/eki.h>
#include <AP/end.h>
#include <AP/gor_00.h>
#include <AP/gor_01.h>
#include <AP/gor_02.h>
#include <AP/gor_03.h>
#include <AP/gor_04.h>
#include <AP/gor_misc.h>
#include <AP/hei.h>
#include <AP/hom.h>
#include <AP/gon.h>
#include <AP/gra.h>
#include <AP/jin.h>
#include <AP/kpa.h>
#include <AP/main.h>
#include <AP/nok.h>
#include <AP/pik.h>
#include <AP/win.h>
#include <AP/mri.h>
#include <AP/muj.h>
#include <AP/rsh.h>
#include <AP/tik.h>
#include <AP/tou.h>
#include <AP/tou2.h>
#include <AP/usu.h>

#include "common.h"
#include "OWR.h"
#include "patch.h"

using ::ttyd::common::ItemData;
using gc::OSLink::OSModuleInfo;
using ::ttyd::common::ShopItemData;
using namespace ::ttyd::common;
using ::ttyd::seqdrv::SeqIndex;
using ::ttyd::string::strcmp;

namespace ItemId = ::ttyd::common::ItemId;
namespace ModuleId = ::ttyd::common::ModuleId;

extern "C" {
	void badgeShop_init();
}

const uint32_t kShopOffsets[] = {
	0x36c5c, 0x57b70,  0xdd98,  0x3c14, 0x40fa8,
	0x1aed4, 0x15be8, 0x21c18, 0x23770, 0x11174
};

char* strcpy_String(char* dest, const char* src)
{
	return ttyd::string::strcpy(dest, src);
}

uint16_t GSWF_ARR[] =
{
	//Any of these being enabled will disable them
	//Shop Tutorial
	0,

	//Email Explanations
	37,38,

	//Save block and heart block tutorials
	233,234,

	//Zess T. blocking gate enable
	1187,

	//Contact Lens Ordered and in shop
	1189, 1191,

	//Skip Zess T. Explain Dialogue
	1197,

	//Attempt to enter ch.4 pipe early
	1341
};
uint16_t GSWF_ARR_SIZE = sizeof(GSWF_ARR) / sizeof(GSWF_ARR[0]);

namespace mod::owr
{
	ItemData* item_db = common::kItemDataArr;
	OWR* gSelf = nullptr;
	StateManager* gState = nullptr;

	OWR::OWR() {}

	void* (*g_itemEntry_trampoline)(const char*, uint32_t, uint32_t, int32_t, void*, float, float, float) = nullptr;
	bool (*g_OSLink_trampoline)(OSModuleInfo*, void*) = nullptr;
	void (*g_stg0_00_init_trampoline)() = nullptr;
	const char* (*g_msgSearch_trampoline)(const char*) = nullptr;

	void OWR::SequenceInit()
	{
		uint32_t SequencePosition = ttyd::swdrv::swByteGet(1700);
		if (ttyd::mario_pouch::pouchCheckItem(26) == 0)
			ttyd::mario_pouch::pouchGetItem(ItemId::ELEVATOR_KEY_001A);
		if (SequencePosition != 0)
			return;
		ttyd::swdrv::swByteSet(1700, 15);
		ttyd::swdrv::swByteSet(1705, 11);
		ttyd::swdrv::swByteSet(1719, 8);
		ttyd::swdrv::swByteSet(1717, 13);

		ttyd::mario_pouch::pouchSetMaxHP(99);
		ttyd::mario_pouch::pouchSetMaxFP(99);
		ttyd::mario_pouch::pouchSetHP(99);
		ttyd::mario_pouch::pouchSetFP(99);

		uint8_t goombella = static_cast<uint8_t>(ttyd::party::PartyMembers::Goombella);
		uint8_t yoshi = static_cast<uint8_t>(ttyd::party::PartyMembers::Yoshi);
		uint8_t bobbery = static_cast<uint8_t>(ttyd::party::PartyMembers::Bobbery);
		uint8_t koops = static_cast<uint8_t>(ttyd::party::PartyMembers::Koops);
		uint8_t flurrie = static_cast<uint8_t>(ttyd::party::PartyMembers::Flurrie);

		ttyd::mario_party::partyJoin(goombella);
		ttyd::mario_party::partyJoin(yoshi);
		ttyd::mario_party::partyJoin(bobbery);
		ttyd::mario_party::partyJoin(koops);
		ttyd::mario_party::partyJoin(flurrie);

		ttyd::mario_party::marioPartyHello(goombella);

		uint16_t size = GSWF_ARR_SIZE;
		for (int i = 0; i < size; i++)
		{
			ttyd::swdrv::swSet(GSWF_ARR[i]);
		}
		ttyd::swdrv::swSet(1215);
		ttyd::swdrv::swSet(1216);


		ttyd::mario_pouch::pouchGetItem(ItemId::ULTRA_BOOTS);
		ttyd::mario_pouch::pouchAddStarPiece(50);
		ttyd::mario_pouch::pouchGetItem(ItemId::ULTRA_HAMMER);
		ttyd::mario_pouch::pouchGetItem(ItemId::INVALID_ITEM_PAPER_MODE_ICON);
		ttyd::mario_pouch::pouchGetItem(ItemId::INVALID_ITEM_TUBE_MODE_ICON);
		for (int i = 0; i <= 10; i++)
			ttyd::mario_pouch::pouchGetItem(ItemId::POWER_PLUS);
		ttyd::mario_pouch::pouchGetItem(ItemId::SPIKE_SHIELD);
		ttyd::mario_pouch::pouchGetItem(ItemId::MULTIBOUNCE);
		ttyd::mario_pouch::pouchGetItem(ItemId::POWER_BOUNCE);
		ttyd::mario_pouch::pouchGetItem(ItemId::CONTACT_LENS);
		ttyd::mario_pouch::pouchGetItem(ItemId::BLIMP_TICKET);
	}

	void OWR::LZTest()
	{
		uint32_t aaa_00_Address = 0x802EDE78;
		SeqIndex NextSeq = ttyd::seqdrv::seqGetNextSeq();
		SeqIndex Load = ttyd::seqdrv::SeqIndex::kLoad;

		if (NextSeq == Load)
		{
			strcpy_String(reinterpret_cast<char*>(aaa_00_Address), "gor_01");
		}
	}

	void OWR::Init()
	{
		gSelf = this;

		ApplyMainAssemblyPatches();
		ApplyMainScriptPatches();

		/*g_itemEntry_trampoline = patch::hookFunction(
			ttyd::itemdrv::itemEntry, [](const char* name, uint32_t id, uint32_t mode, int32_t collection_expr, void* script, float x, float y, float z)
			{
				return g_itemEntry_trampoline(name, gSelf->state_.itemEntries[id], mode, collection_expr, script, x, y, z);
			});*/

		g_OSLink_trampoline = patch::hookFunction(
			gc::OSLink::OSLink, [](OSModuleInfo* new_module, void* bss) {
				bool result = g_OSLink_trampoline(new_module, bss);
				if (new_module != nullptr && result) {
					gSelf->OnModuleLoaded(new_module);
				}
				return result;
			});

		g_msgSearch_trampoline = patch::hookFunction(
			ttyd::msgdrv::msgSearch, [](const char* msgKey) {
				if (!strcmp(msgKey, "jolene_fukidashi"))
				{
					return "Oh my!<wait 100> Excuse me.\n<k>";
				}
				if (!strcmp(msgKey, "jolene_fukidashi_end"))
				{
					return "Well then.<wait 100> Shall we\nget going?\n<k>";
				}
				return g_msgSearch_trampoline(msgKey);
			});

		g_stg0_00_init_trampoline = patch::hookFunction(
			ttyd::event::stg0_00_init, []() {
				gSelf->NewFileInit();
				g_stg0_00_init_trampoline();
			});

		uint32_t* kSkipUHCutsceneOpcode = reinterpret_cast<uint32_t*>(0x800abcd8);
		const uint32_t skip_cutscene_opcode = 0x48000030;     // b 0x0030
		mod::patch::writePatch(
			kSkipUHCutsceneOpcode, &skip_cutscene_opcode, sizeof(uint32_t));
	}

	void OWR::Update()
	{
		SequenceInit();
		LZTest();
	}

	void OWR::Draw()
	{
		//char* buffer = new char[256];
		//sprintf(buffer, "seq: %lu", ttyd::swdrv::swByteGet(0));
		//DrawString(buffer, -232, -120,-1U);
	}

	void OWR::NewFileInit()
	{

	}

	void OWR::OnModuleLoaded(OSModuleInfo* module_info)
	{
		if (module_info == nullptr) return;
		//uintptr_t module_ptr = reinterpret_cast<uintptr_t>(module_info);
		switch (module_info->id) {
		case ModuleId::GOR:
			ApplyGor00Patches(module_info);
			ApplyGor01Patches(module_info);
			ApplyGor02Patches(module_info);
			ApplyGor03Patches(module_info);
			ApplyGor04Patches(module_info);
			ApplyGorMiscPatches(module_info);
			break;
		case ModuleId::HEI:
			ApplyHeiPatches(module_info);
			break;
		case ModuleId::GON:
			ApplyGonPatches(module_info);
			break;
		case ModuleId::NOK:
			ApplyNokPatches(module_info);
			break;
		case ModuleId::WIN:
			ApplyWinPatches(module_info);
			break;
		case ModuleId::MRI:
			ApplyMriPatches(module_info);
			break;
		case ModuleId::TOU:
			ApplyTouPatches(module_info);
			break;
		case ModuleId::TOU2:
			ApplyTou2Patches(module_info);
			break;
		case ModuleId::USU:
			ApplyUsuPatches(module_info);
			break;
		case ModuleId::GRA:
			ApplyGraPatches(module_info);
			break;
		case ModuleId::JIN:
			ApplyJinPatches(module_info);
			break;
		case ModuleId::MUJ:
			ApplyMujPatches(module_info);
			break;
		case ModuleId::DOU:
			ApplyDouPatches(module_info);
			break;
		case ModuleId::RSH:
			ApplyRshPatches(module_info);
			break;
		case ModuleId::EKI:
			ApplyEkiPatches(module_info);
			break;
		case ModuleId::END:
			ApplyEndPatches(module_info);
			break;
		case ModuleId::HOM:
			ApplyHomPatches(module_info);
			break;
		case ModuleId::PIK:
			ApplyPikPatches(module_info);
			break;
		case ModuleId::BOM:
			ApplyBomPatches(module_info);
			break;
		case ModuleId::AJI:
			ApplyAjiPatches(module_info);
			break;
		case ModuleId::AAA:
			ApplyAaaPatches(module_info);
			break;
		case ModuleId::KPA:
			ApplyKpaPatches(module_info);
			break;
		case ModuleId::TIK:
			ApplyTikPatches(module_info);
			break;
		default:
			return;
		}

		/*ShopItemData* item_data = reinterpret_cast<ShopItemData*>(module_ptr + kShopOffsets[0]);
		for (int32_t copy = 0; copy < 7; ++copy) {
			// Skip first item slot on additional copies.
			if (copy > 0) ++item_data;
			for (int32_t i = copy > 0 ? 1 : 0; i < 6; ++i) {
				ItemPrice item_price = ItemPrice();
				if (i == 2)
					item_price.item = ItemId::CARD_KEY_001D;
				else
					item_price.item = ItemId::ULTRA_BOOTS;
				item_price.price = 1;
				item_data->item_id = item_price.item;
				item_data->buy_price = item_price.price;
				++item_data;
			}
		} */
	}

	void OWR::DrawString(const char* data, float x, float y, uint32_t color, float scale) {
		if (!data) return;

		// Init text drawing
		ttyd::fontmgr::FontDrawStart();
		ttyd::fontmgr::FontDrawColor(reinterpret_cast<uint8_t*>(&color));
		ttyd::fontmgr::FontDrawEdge();
		ttyd::fontmgr::FontDrawScale(scale);

		// Draw each line
		char buf[128];
		const float lineDecrement = 32.f * scale;
		constexpr int32_t maxLength = sizeof(buf) - 1;

		while (1)
		{
			// Find the end of the current line
			const char* newline = strchr(data, '\n');

			// If a newline is not found, then currently at the last line
			if (!newline)
			{
				break;
			}

			// Copy this line to the temporary buffer and append a null byte
			int32_t lineLength = newline - data;

			// Make sure the current line won't be an empty string
			if (lineLength > 0)
			{
				// Prevent a buffer overflow
				if (lineLength > maxLength)
				{
					lineLength = maxLength;
				}

				char* tempBuf = strncpy(buf, data, lineLength);
				tempBuf[lineLength] = '\0';

				ttyd::fontmgr::FontDrawString(x, y, tempBuf);
			}

			// Advance to the next line
			data = newline + 1;
			y -= lineDecrement;
		}

		// Draw the rest of the text
		ttyd::fontmgr::FontDrawString(x, y, data);
	}

}