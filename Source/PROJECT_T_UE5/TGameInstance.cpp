// Fill out your copyright notice in the Description page of Project Settings.


#include "TGameInstance.h"
#include "TCPModule.h"

void UTGameInstance::Init()
{
	Super::Init();

	TcpClient = NewObject<UTCPModule>();

	if (TcpClient)
	{
		bool bConnected = TcpClient->ConnectToServer(TEXT("192.168.0.10"), 5001);

		if (bConnected)
		{
			UE_LOG(LogTemp, Log, TEXT("Successfully connected to the server!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to connect to the server!"));
		}
	}
}

UTGameInstance::~UTGameInstance()
{
	// destructor
	if (TcpClient)
	{
		TcpClient->Disconnect();
		UE_LOG(LogTemp, Log, TEXT("Disconnected from the server!"));
	}
}



UTCPModule* UTGameInstance::GetTCPModule()
{
	return TcpClient;
}
