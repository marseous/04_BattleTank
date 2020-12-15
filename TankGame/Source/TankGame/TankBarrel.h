// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankGame.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class TANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	void Elevate(float RelativeSpeed);

	UPROPERTY(EditAnywhere, Category = "Setup")		float MaxDegreesPerSecond = 20.f;
	UPROPERTY(EditAnywhere, Category = "Setup")		float MinDegreesPerSecond = 0.f;
	UPROPERTY(EditAnywhere, Category = "Setup")		float MaxElevetionDegrees = 40.f;
};
