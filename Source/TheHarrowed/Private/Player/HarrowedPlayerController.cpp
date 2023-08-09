// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HarrowedPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

AHarrowedPlayerController::AHarrowedPlayerController()
{
	bReplicates = true;
}

void AHarrowedPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(DefaultContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(DefaultContext, 0);
}

void AHarrowedPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AHarrowedPlayerController::Look);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AHarrowedPlayerController::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AHarrowedPlayerController::StopJumping);
}

void AHarrowedPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(LookAxisVector.X);
		ControlledPawn->AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AHarrowedPlayerController::Jump()
{
	if (ACharacter* ControlledCharacter = GetControlledCharacter())
	{
		ControlledCharacter->Jump();
	}
}

void AHarrowedPlayerController::StopJumping()
{
	if (ACharacter* ControlledCharacter = GetControlledCharacter())
	{
		ControlledCharacter->StopJumping();
	}
}

ACharacter* AHarrowedPlayerController::GetControlledCharacter() const
{
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		if (ACharacter* ControlledCharacter = Cast<ACharacter>(ControlledPawn))
		{
			return ControlledCharacter;
		}
	}

	return nullptr;
}

