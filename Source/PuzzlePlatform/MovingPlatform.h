// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float Speed = 200.0f;

	// MakeEditWidget : 트랜스폼 또는 로테이터, 아니면 그 배열에 사용됩니다. 프로퍼티를 뷰포트에 이동가능 위젯으로 노출시켜야 함을 나타냅니다.
	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;
};
