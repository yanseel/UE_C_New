// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
UCLASS()
class START_CPP_API AYCharacter : public ACharacter
{
	GENERATED_BODY() 

public:
	// Sets default values for this character's properties
	AYCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* springarmcomp;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* cameracomp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
