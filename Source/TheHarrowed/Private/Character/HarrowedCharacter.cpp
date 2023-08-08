// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/HarrowedCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/HarrowedPlayerController.h"
#include "Player/HarrowedPlayerState.h"

AHarrowedCharacter::AHarrowedCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.);
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	GetCharacterMovement()->MaxWalkSpeed = 350.f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->SocketOffset = FVector(0.f, 75.f, 50.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void AHarrowedCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init Ability Actor Info for the Server
	InitAbilityActorInfo();
}

void AHarrowedCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init Ability Actor Info for the client
	InitAbilityActorInfo();
}

void AHarrowedCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AHarrowedCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AHarrowedCharacter::InitAbilityActorInfo()
{
	AHarrowedPlayerState* HarrowedPlayerState = GetPlayerState<AHarrowedPlayerState>();
	check(HarrowedPlayerState);
	HarrowedPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(HarrowedPlayerState, this);
	AbilitySystemComponent = HarrowedPlayerState->GetAbilitySystemComponent();
	AttributeSet = HarrowedPlayerState->GetAttributeSet();
}
