// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestTCP.generated.h"

/**
 * 
 */
UCLASS()
class ONLINE_CHAT_API UTestTCP : public UObject
{
	GENERATED_BODY()
	
	public:
	
	bool CreateTCPConnection();
	
};
