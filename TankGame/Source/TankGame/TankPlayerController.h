// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankGame.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;


UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();
	bool GetHitLocation(FVector &HitLocation);
	bool AimCoordinatesToWorld(FVector2D ScreenLocation, FVector& LookDirection);
	bool GetHitCoordinates(FVector LookDirection, FVector& HitLocation);

	UPROPERTY(EditAnywhere)		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)		float CrosshairYLocation = 0.3333f;
								float LineTraceLength = 10000.f;

};
