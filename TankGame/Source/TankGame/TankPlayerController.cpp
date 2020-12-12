// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	FString tankName = GetWorld()->GetFirstPlayerController()->GetPawn()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("GETCONTROLLEDTANK : %s"), *tankName);

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();


}
