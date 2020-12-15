// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankGame.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")	
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UPROPERTY(EditAnywhere, Category = "Fire")		float LaunchSpeed = 40000.f;
protected:
	UTankAimingComponent* AimingComponent = nullptr;

	virtual void BeginPlay() override;

private:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
