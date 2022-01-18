// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameHUD.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Hero.generated.h"

#define ECC_LookAt ECC_GameTraceChannel1

UCLASS()
class SHOOTERGAME_API AHero : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY()
	AGameHUD* GameHUD;

public:
	UPROPERTY(EditAnywhere)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(BlueprintReadOnly)
	int32 Coins;

	UPROPERTY(BlueprintReadOnly)
	int32 Caps;

	UPROPERTY(BlueprintReadWrite)
	float HP;


	// Hook vars
	FVector HookStart;
	FVector HookEnd;
	bool RightClickment;

	// Sets default values for this character's properties
	AHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION()
	void OnCollide(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnStopCollision(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void MoveForward(float Scale);
	void MoveSideways(float Scale);
	
	void LeftClick();
	void RightClick();
	void StopRightClick();
	void Interact();
	
	void IsDead();
};