#pragma once

#include <Packets/Packet.h>
#include <DataObjects/Location.h>

#ifdef LIB
#define PACKET_API __declspec(dllexport)
#else
#define PACKET_API __declspec(dllimport)
#endif

class PACKET_API GroundDamage : public ClientPacket
{
public:
	int time;
	Location position;

	GroundDamage(int time, float x, float y);
	GroundDamage(int time, const Location& position);
	GroundDamage(byte* data);

	void emplace(byte* buffer) const override;
	int size() const override;
	String toString() const override;
};