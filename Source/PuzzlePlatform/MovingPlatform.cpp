// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	// TargetLocation�� Gloabl�� ����
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// HasAuthority : �ڽ��� �������� ��ȯ�Ѵ�. ����(ture) 
	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		float MoveLength = (GlobalStartLocation - GlobalTargetLocation).Size();
		float MovedLength = (GlobalStartLocation - Location).Size();
		if (MovedLength >= MoveLength)
		{
			Swap(GlobalStartLocation, GlobalTargetLocation);
		}
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

		Location += Speed * DeltaTime * Direction;
		SetActorLocation(Location);
	}
}
