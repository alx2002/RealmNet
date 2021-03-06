#pragma once

#include <Packets/Packet.h>

#ifdef LIB
#define PACKET_API __declspec(dllexport)
#else
#define PACKET_API __declspec(dllimport)
#endif

class PACKET_API Notification : public ServerPacket
{
public:
	int objectId;
	String message;
	int color;

	Notification(int objectId, const String& message, int color);
	Notification(byte* data);

	void emplace(byte* buffer) const override;
	int size() const override;
	String toString() const override;
};