// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not get player's tank!"))
	}
	else
	{
		FString PlayerTankName = PlayerTank->GetName();
		
		UE_LOG(LogTemp, Warning, TEXT("Player's tank: %s"), *PlayerTankName)
	}


}
