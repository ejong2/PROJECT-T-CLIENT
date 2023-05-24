// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTcpClient.h"
#include "Networking.h"
#include "SocketSubsystem.h"

UMyTcpClient::UMyTcpClient()
	: ClientSocket(nullptr)
{
}

bool UMyTcpClient::ConnectToServer(FString IP, int32 Port)
{
	ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	TSharedRef<FInternetAddr> Addr = SocketSubsystem->CreateInternetAddr();

	bool bIsValid;
	Addr->SetIp(*IP, bIsValid);
	Addr->SetPort(Port);

	if (!bIsValid)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid IP!"));
		return false;
	}

	ClientSocket = SocketSubsystem->CreateSocket(NAME_Stream, TEXT("default"), false);

	if (!ClientSocket->Connect(*Addr))
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not connect to server!"));
		ClientSocket = nullptr;
		return false;
	}

	return true;
}

void UMyTcpClient::Disconnect()
{
	if (ClientSocket)
	{
		ClientSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
		ClientSocket = nullptr;
	}
}