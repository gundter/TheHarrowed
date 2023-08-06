// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HarrowedCharacterBase.generated.h"

UCLASS(Abstract)
class THEHARROWED_API AHarrowedCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AHarrowedCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
