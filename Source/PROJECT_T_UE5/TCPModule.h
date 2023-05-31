// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TCPModule.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_T_UE5_API UTCPModule : public UObject
{
	GENERATED_BODY()
public:
	UTCPModule();

	bool ConnectToServer(FString IP, int32 Port);
	void Disconnect();
	void SendLoginPacket(bool bIsLogin,FString Id, FString Password);
private:
	FSocket* ClientSocket;
};
