// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "TestTCP.h"

// Sets default values
AMyCharacter::AMyCharacter(): Scr(nullptr)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		if (!Scr)
		{
			Scr = NewObject<UTestTCP>(this,UTestTCP::StaticClass());
			if (Scr)
			{
				UE_LOG(LogTemp,Warning,TEXT("새거 만듦"))
			}
			else
			{
				UE_LOG(LogTemp,Warning,TEXT("실패"))
			}
		}
		Scr->CreateTCPConnection();
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

