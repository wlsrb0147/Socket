// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

struct FIPv4Endpoint;
/**
 * 
 */
class ONLINE_CHAT_API FTestScript
{
public:
	
	FTestScript();
	~FTestScript();

	bool StartServer(uint16 Port);

	void Tick(float DeltaTime) const;

	void StopServer();

private:
	FSocket* ListenerSocket;
	FIPv4Endpoint* EndPoint;
};
