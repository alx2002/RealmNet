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

#include <Packets/Hello.h>
#include <Packets/Failure.h>

String buildVersion;

class Plugin : public IPlugin
{
public:
	Plugin(IProxy& proxy) : IPlugin(proxy)
	{
		HookPacket(Failure);
		HookPacket(Hello);
	}

	void onFailure(Failure& p)
	{
		if (p.errorId == 4)
			buildVersion = p.message;
	}

	void onHello(Hello& p)
	{
		if (buildVersion.length != 0)
		{
			printf("Changing build version %s -> %s\n", p.buildVersion.c_str, buildVersion.c_str);
			p.buildVersion = buildVersion;
			proxy.updatePacket(p);
		}
	}
};

IPlugin* create(IProxy& proxy)
{
	return new Plugin(proxy);
}

void attach(const char** plugin, const char** author, void(IPlugin::**onDisconnect)(), HookedKey** keyHook)
{
	*plugin = "ClientUpdate";
	*author = "CrazyJani";
}