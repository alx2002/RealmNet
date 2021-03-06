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

#include <Packets/CreateSuccess.h>
#include <Packets/Notification.h>

class Plugin : public IPlugin
{
public:
	Plugin(IProxy& proxy) : IPlugin(proxy)
	{
		HookPacket(CreateSuccess);
	}

	void onCreateSuccess(CreateSuccess& p)
	{
		proxy.sendPacket(Notification(proxy.playerData.objectId, "Welcome to RealmNet!", 0x00ff80));
	}
};

IPlugin* create(IProxy& proxy)
{
	return new Plugin(proxy);
}

void attach(const char** plugin, const char** author, void(IPlugin::**onDisconnect)(), HookedKey** keyHook)
{
	*plugin = "Welcome";
	*author = "CrazyJani";
}