// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"  // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void BeginPlay() override;

private:
	ATank* GetControlledTank() const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333f;

	// Start the tank moving the barrel so that a shot would it
	// where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// Return an OUT parameter
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f;

	// Returns true if ray line trace hits something in the specified channel (ECC_Visibility)
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
