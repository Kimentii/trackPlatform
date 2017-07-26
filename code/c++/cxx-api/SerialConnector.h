﻿#ifndef _BLUETOOTH_CONNECTOR_H_
#define _BLUETOOTH_CONNECTOR_H_

#include "TrackPlatform_BasicConnector.h"
#include "serial/serial.h"

class SerialConnector : public TrackPlatform_BasicConnector
{
	static const size_t messageMaxSize = 65535;
	static const size_t timeoutInMs = 500;
	
	serial::Serial* readPort;
	serial::Serial* writePort;

public:
	SerialConnector(const std::string& rx, const std::string& tx, uint32_t baudRate);
	~SerialConnector() override;
	std::string read() override;
	std::string readAllAvailable() override;
	void write(const std::string& s) override;
	bool isConnected() override;
};

#endif /* _BLUETOOTH_CONNECTOR_H_ */