// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Math/UnrealMathUtility.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// HasAuthority : �ڽ��� �������� ��ȯ�Ѵ�. ����(ture) 
	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		Location += FVector(Speed * DeltaTime, 0.0f, 0.0f);
		SetActorLocation(Location);
	}
}
