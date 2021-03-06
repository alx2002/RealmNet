#include "stdafx.h"

#include "Networking/Acceptor.h"
#include <GameData/TypeManager.h>
#include <GameData/ServerManager.h>
#include <GameData/XmlData.h>
#include "Data/PluginManager.h"

//TODO
//pass an additional Proxy** to the plugins for null checking before calling (e.g. in a separate thread)
//autoloot plugin
//spellaim plugin
//tombhack plugin
//stuntimer plugin
//flash taskbar on tell plugin

//auto UpdateAck for easy fake updates
//how to get the client to ignore a NewTick (i.e. no Move response)
//make PlayerData more complete

inline void initialize();

void main()
{
	printf("RealmNet v3.1 (Build from " __TIMESTAMP__ ")\n");

	initialize();

	boost::asio::io_service ios;
	Acceptor acceptor(ios);

	boost::asio::io_service::work work(ios);
	ios.run();
}

inline void initialize()
{
	TypeManager::mapPackets();
	PluginManager::attachPlugins();
	XmlData::loadData();
	ServerManager::loadServers();
#ifndef _DEBUG
	KeyHook::monitorKeys();
#endif
}