// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "SExplosive.generated.h"

UCLASS()
class UE_C_NEW_API ASExplosive : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosive();

protected:
	// Called when the game starts or when spawned
	UFUNCTION()
	void ActorOnHit(UPrimitiveComponent* HitComponent,AActor* OtherActor, UPrimitiveComponent *OtherComp,FVector NormalImpuse,const FHitResult &Hit );
	USceneComponent *SceneComp;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *StaticMeshComp;
	
	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* RadialForceComp;
	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
