// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyTcpClient.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_T_UE5_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

    virtual void Init() override;

    ~UMyGameInstance(); // Add destructor

    UMyTcpClient* GetTcpClient();

private:

    UPROPERTY()
    UMyTcpClient* TcpClient;
};
