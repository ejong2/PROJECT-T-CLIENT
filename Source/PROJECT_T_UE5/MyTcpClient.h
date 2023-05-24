// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyTcpClient.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_T_UE5_API UMyTcpClient : public UObject
{
	GENERATED_BODY()

public:
	UMyTcpClient();

	bool ConnectToServer(FString IP, int32 Port);
	void Disconnect();

private:
	FSocket* ClientSocket;
};