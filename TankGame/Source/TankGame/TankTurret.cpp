// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	auto RotateSpeed = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RotateAngle = GetRelativeRotation().Yaw + RotateSpeed;

	SetRelativeRotation(FRotator(0, RotateAngle, 0));

	UE_LOG(LogTemp, Warning, TEXT("Rotate()"))

}