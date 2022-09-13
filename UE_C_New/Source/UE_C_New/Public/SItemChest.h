// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGamePlayInterface.h"
#include "GameFramework/Actor.h"
#include "SItemChest.generated.h"

UCLASS()
class UE_C_NEW_API ASItemChest : public AActor,public ISGamePlayInterface
{
	GENERATED_BODY()
	void interact_Implementation(APawn* Instigatorpawn) override;
public:	
	// Sets default values for this actor's properties
	ASItemChest();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *BaseComp;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent*LidComp;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
