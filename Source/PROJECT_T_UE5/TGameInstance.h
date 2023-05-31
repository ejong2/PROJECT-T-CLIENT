// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TCPModule.h"
#include "TGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class PROJECT_T_UE5_API UTGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	virtual ~UTGameInstance() override; // Add destructor

	virtual void Init() override;

	UTCPModule* GetTCPModule();

private:

	UTCPModule* TcpClient;
};
