// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller Begin Play"));

	if (GetControlledTank() == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not get a controlled tank!"));
	}
	else
	{
		FString TankID = GetControlledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank : %s"), *TankID);
	}
}
