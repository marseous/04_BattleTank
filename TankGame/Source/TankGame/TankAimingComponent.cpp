// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{

	if (!Barrel) { return; }

	FVector OutTossVelocity;
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutTossVelocity,
		Barrel->GetSocketLocation("Projectile"),
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveAimSolution)
	{
		MoveBarrelTowards(OutTossVelocity);
	}
}

	// ��������� ����� ��������� �� y ������������ �������
void UTankAimingComponent::MoveBarrelTowards(FVector AimingDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimingDirection.Rotation();
	auto DeltaRotation = AimAsRotator - BarrelRotator;

	UE_LOG(LogTemp, Warning, TEXT("DeltaRotation %s"), *DeltaRotation.ToString())

}