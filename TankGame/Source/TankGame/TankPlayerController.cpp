// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() // Получаем координаты локации куда указывает прицел
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if(GetHitLocation(HitLocation))
	{ 
		UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString())
	}
}

bool ATankPlayerController::GetHitLocation(FVector& HitLocation)
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	// Точка прицела на экране
	FVector2D ScreenLocation(CrosshairXLocation * ViewportSizeX, CrosshairYLocation * ViewportSizeY);

	// Координаты направления прицела
	FVector LookDirection; 
	if (AimCoordinatesToWorld(ScreenLocation, LookDirection))
	{
		GetHitCoordinates(LookDirection, HitLocation);
	}

	return true;
}

// Проицирование прицела в мир и получени координат направления
bool ATankPlayerController::AimCoordinatesToWorld(FVector2D ScreenLocation, FVector& LookDirection)
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection
	);
}

bool ATankPlayerController::GetHitCoordinates(FVector AimDirection, FVector &HitLocation)
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (AimDirection * LineTraceLength);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;

		return true;
	}

	return false;
}
