// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetAIControlledTank() const
{
	UE_LOG(LogTemp, Warning, TEXT("AI Controls: %s"), *Cast<ATank>(GetPawn())->GetName());
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI FOUND PLAYER: %s"), *PlayerTank->GetName());
		return PlayerTank;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI: PLAYER NOT FOUND"));
	}
	return nullptr;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetAIControlledTank();
	GetPlayerTank();
	
}
