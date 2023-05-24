// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
    Super::Init();

    TcpClient = NewObject<UMyTcpClient>();

    if (TcpClient)
    {
        bool bConnected = TcpClient->ConnectToServer(TEXT("127.0.0.1"), 5001);

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

UMyGameInstance::~UMyGameInstance()
{
    // destructor
    if (TcpClient)
    {
        TcpClient->Disconnect();
        UE_LOG(LogTemp, Log, TEXT("Disconnected from the server!"));
    }
}



UMyTcpClient* UMyGameInstance::GetTcpClient()
{
    return TcpClient;
}
