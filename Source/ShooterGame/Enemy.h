// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class SHOOTERGAME_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	int32 HP;
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void IsDead();
};
