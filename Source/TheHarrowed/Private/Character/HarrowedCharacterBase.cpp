// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/HarrowedCharacterBase.h"

AHarrowedCharacterBase::AHarrowedCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AHarrowedCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

