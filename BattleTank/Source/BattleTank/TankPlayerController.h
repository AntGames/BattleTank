// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

private:
	//Moving barel towars crosshair
	void AimTowardsCrosshair();

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
