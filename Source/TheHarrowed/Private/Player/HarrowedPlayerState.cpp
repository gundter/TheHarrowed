// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HarrowedPlayerState.h"

#include "AbilitySystem/HarrowedAbilitySystemComponent.h"
#include "AbilitySystem/HarrowedAttributeSet.h"

AHarrowedPlayerState::AHarrowedPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UHarrowedAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UHarrowedAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AHarrowedPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
