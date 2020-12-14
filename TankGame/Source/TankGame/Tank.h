// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankGame.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

protected:
	UTankAimingComponent* AimingComponent = nullptr;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
