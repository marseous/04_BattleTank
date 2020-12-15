// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankGame.h"
#include "Components/SceneComponent.h"
#include "TankTurret.generated.h"


UCLASS(  meta=(BlueprintSpawnableComponent) )
class TANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = "Setup")		float MaxDegreesPerSecond = 25.f;
};
