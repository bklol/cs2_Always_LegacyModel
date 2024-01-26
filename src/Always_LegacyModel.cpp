#include "Always_LegacyModel.h"

#include "utils/addresses.h"

#include "tier0/memdbgon.h"
#include "utils/cdetour.h"
#include <entity2/entityidentity.h>
#include <baseentity.h>

Weapon_IsLegacy g_Weapon_IsLegacy;
CUtlVector<CDetourBase*> g_vecDetours;

#define DECLARE_BASEPLAYER_DETOUR(name) DECLARE_DETOUR(name, BasePlayer::Detour_##name, &modules::server);
#define DECLARE_BASEPLAYER_EXTERN_DETOUR(name) extern CDetour<decltype(BasePlayer::Detour_##name)> name;

namespace BasePlayer
{
	bool FASTCALL Detour_Weapon_IsLegacyModel(const char* pName);
}

DECLARE_BASEPLAYER_EXTERN_DETOUR(Weapon_IsLegacyModel);
DECLARE_BASEPLAYER_DETOUR(Weapon_IsLegacyModel);

PLUGIN_EXPOSE(Weapon_IsLegacy, g_Weapon_IsLegacy);

bool Weapon_IsLegacy::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();
	modules::server = new CModule(GAMEBIN, "server");
	INIT_DETOUR(Weapon_IsLegacyModel);
	return true;
}

bool FASTCALL BasePlayer::Detour_Weapon_IsLegacyModel(const char* pName)
{
	return true;
}

bool Weapon_IsLegacy::Unload(char *error, size_t maxlen)
{	
	return true;
}

void Weapon_IsLegacy::AllPluginsLoaded()
{
}

bool Weapon_IsLegacy::Pause(char *error, size_t maxlen)
{
	return true;
}

bool Weapon_IsLegacy::Unpause(char *error, size_t maxlen)
{
	return true;
}

const char *Weapon_IsLegacy::GetLicense()
{
	return "";
}

const char *Weapon_IsLegacy::GetVersion()
{
	return "1.0";
}

const char *Weapon_IsLegacy::GetDate()
{
	return __DATE__;
}

const char *Weapon_IsLegacy::GetLogTag()
{
	return "Weapon_IsLegacy";
}

const char *Weapon_IsLegacy::GetAuthor()
{
	return "bklol";
}

const char *Weapon_IsLegacy::GetDescription()
{
	return "Weapon_IsLegacy";
}

const char *Weapon_IsLegacy::GetName()
{
	return "CS2 Weapon_IsLegacy";
}

const char *Weapon_IsLegacy::GetURL()
{
	return "https://github.com/bklol/cs2_Always_LegacyModel";
}
