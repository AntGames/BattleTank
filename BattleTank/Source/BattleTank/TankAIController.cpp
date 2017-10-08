// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* Tank = GetControlledTank();
	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("AITank::ControlledTank:: %s"), *Tank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController:: <Missing tank>"));
	}

	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AITank::Playertank: %s"), *PlayerTank->GetName());
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerController = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerController) {
		auto Tank = Cast<ATank>(PlayerController);
		return Tank;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ATankAIController:: Cant find player tank"));
	}

	return nullptr;
}

