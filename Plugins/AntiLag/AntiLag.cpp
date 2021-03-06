#pragma region Header
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;

#define PLUGIN
#include <Interface/IPlugin.h>
#include <GameData/Constants.h>
#pragma endregion

#include <Packets/ShowEffect.h>
#include <Packets/Notification.h>
#include <Packets/AllyShoot.h>
#include <Packets/Damage.h>

class Plugin : public IPlugin
{
public:
	Plugin(IProxy& proxy) : IPlugin(proxy)
	{
		HookPacket(ShowEffect);
		HookPacket(Notification);
		HookPacket(AllyShoot);
		HookPacket(Damage);
	}

	void onShowEffect(ShowEffect& p)
	{
		switch (p.effectType)
		{
			case EffectType::Nova:
			case EffectType::Heal:
			case EffectType::Teleport:
			case EffectType::Poison:
			case EffectType::Line:
			case EffectType::Burst:
			case EffectType::Flow:
			case EffectType::Ring:
			case EffectType::Collapse:
			case EffectType::Shocker:
			case EffectType::Shockee:
			case EffectType::RisingFury:
				proxy.discardPacket(p);
		}
	}

	void onNotification(Notification& p)
	{
		if (proxy.playerData.objectId != p.objectId)
			proxy.discardPacket(p);
	}

	void onAllyShoot(AllyShoot& p)
	{
		proxy.discardPacket(p);
	}

	void onDamage(Damage& p)
	{
		if (proxy.playerData.objectId != p.objectId)
			proxy.discardPacket(p);
	}
};

IPlugin* create(IProxy& proxy)
{
	return new Plugin(proxy);
}

void attach(const char** plugin, const char** author, void(IPlugin::**onDisconnect)(), HookedKey** keyHook)
{
	*plugin = "AntiLag";
	*author = "CrazyJani";
}