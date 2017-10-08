// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControlledTank();
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank::ControlledTank:: %s"), *Tank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("GetControlledTank:: <Missing tank>"));
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void ATankPlayerController::AimTowardsCrosshair()
{

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

