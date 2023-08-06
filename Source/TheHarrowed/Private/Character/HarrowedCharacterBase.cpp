// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/HarrowedCharacterBase.h"

// Sets default values
AHarrowedCharacterBase::AHarrowedCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHarrowedCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHarrowedCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHarrowedCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

