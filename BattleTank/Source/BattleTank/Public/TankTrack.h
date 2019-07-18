// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Max force per track, in Newtons
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TrackMaxDrivingForce = 45000000; // Assume 40 tonne tank and 1G acceleration

private:
	UTankTrack();

	virtual void BeginPlay() override;

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION()
	void  OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
