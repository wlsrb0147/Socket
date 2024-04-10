// Fill out your copyright notice in the Description page of Project Settings.


#include "ForFolder.h"

// Sets default values
AForFolder::AForFolder()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AForFolder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AForFolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AForFolder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

