// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/HarrowedEnemyCharacter.h"

#include "AbilitySystem/HarrowedAbilitySystemComponent.h"
#include "AbilitySystem/HarrowedAttributeSet.h"

AHarrowedEnemyCharacter::AHarrowedEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UHarrowedAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UHarrowedAttributeSet>("AttributeSet");
}
