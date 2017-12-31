// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetControlledTank() == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not get AI controlled tank!"))
	}
	else
	{
		FString AIControlledTank = GetControlledTank()->GetName();
		
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled tank: %s"), *AIControlledTank)
	}


}
