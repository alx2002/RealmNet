#include "stdafx.h"

#include "Https/Downloader.h"
#include "Parser/ServerParser.h"
#include "Parser/DataParser.h"

//parses GroundTypes.xml and Objects.xml from static.drips.pw
//parses char/list from realmofthemadgod.com/char/list?guid=[random] (the guid is there to avoid banned accounts; not implemented)

void main()
{
	//download files
	Downloader::download("www.realmofthemadgod.com", "/char/list", "CharList.xml");
	Downloader::download("static.drips.pw", "/rotmg/production/current/xmlc/Objects.xml", "Objects.xml");
	Downloader::download("static.drips.pw", "/rotmg/production/current/xmlc/GroundTypes.xml", "GroundTypes.xml");

	//parse files
	ServerParser::parse();
	DataParser::parse();
	getchar();
}