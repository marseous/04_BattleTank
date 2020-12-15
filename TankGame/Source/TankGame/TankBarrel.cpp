// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationSpeed = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto ElevationAngle = ElevationSpeed + GetComponentRotation().Pitch;
	
	// ограничение подъема ствола
	SetRelativeRotation(FRotator(FMath::Clamp<float>(ElevationAngle, MinElevetionDegrees, MaxElevetionDegrees), 0, 0));
}