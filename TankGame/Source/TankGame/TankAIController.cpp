// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetAIControlledTank() const
{
	UE_LOG(LogTemp, Warning, TEXT("AI Controls: %s"), *Cast<ATank>(GetPawn())->GetName());
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetAIControlledTank();
}
