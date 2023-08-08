// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/HarrowedCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "HarrowedEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class THEHARROWED_API AHarrowedEnemyCharacter : public AHarrowedCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
};
