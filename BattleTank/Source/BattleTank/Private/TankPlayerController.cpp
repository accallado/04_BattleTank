// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

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

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("AimTowardsCrosshair()"));

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (GetControlledTank() == nullptr)
	{
		return;
	}

	FVector HitLocation;  // OUT parameter

	if (GetSightRayHitLocation(HitLocation))  // Has "side-effect": is going to linetrace
	{

		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point

	}


}


// Get worls location of linetrace through crosshair; true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D((float)ViewportSizeX*CrossHairXLocation, (float)ViewportSizeY*CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Aim screen location: %s"), *ScreenLocation.ToString());

	// "De-project" the screen position of the crosshair to a world direction
	// Linetrace along that look direction, and see what we hit (up to max range)
	return true;
}
