// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("player controller begin play"));

	auto ControlledTank = GetControlledTank();
	if (ControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("No possessed Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed Tank: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
