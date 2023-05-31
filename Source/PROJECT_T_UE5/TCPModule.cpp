// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPModule.h"
#include "Networking.h"
#include "SocketSubsystem.h"
#include "TCPPacketStructs.h"

UTCPModule::UTCPModule()
	: ClientSocket(nullptr)
{
}

bool UTCPModule::ConnectToServer(FString IP, int32 Port)
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

void UTCPModule::Disconnect()
{
	if (ClientSocket)
	{
		ClientSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
		ClientSocket = nullptr;
	}
}

void UTCPModule::SendLoginPacket(bool bIsLogin,FString Id, FString Password)
{
	MessageReqLogin Message;

	FMemory::Memset(&Message, 0, sizeof(Message));

	if (bIsLogin)
	{
		Message.MessageID = (int)EMessageID::C2S_REQ_LOGIN;
	}
	else
	{
		Message.MessageID = (int)EMessageID::C2S_REQ_SIGNUP;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("%d"), Message.MessageID);
	
	Message.MessageSize = sizeof(MessageReqLogin);
	
	FMemory::Memcpy(Message.USER_ID, TCHAR_TO_ANSI(*Id), Id.Len());
	FMemory::Memcpy(Message.USER_PASSWORD, TCHAR_TO_ANSI(*Password), Password.Len());
	
	int Flags = 0;

	ClientSocket->Send((const uint8*)&Message, Message.MessageSize, Flags);
}
