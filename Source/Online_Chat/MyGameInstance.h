// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

struct FIPv4Endpoint;
/**
 * 
 */
UCLASS()
class ONLINE_CHAT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	bool StartServer(uint16 Port);

	void Tick(float DeltaTime) const;

	void StopServer();
	virtual void Shutdown() override;

private:
	FSocket* ListenerSocket;
	FIPv4Endpoint* EndPoint;
};
