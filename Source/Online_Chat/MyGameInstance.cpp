// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"

bool UMyGameInstance::StartServer(uint16 Port)
{
	ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	EndPoint = new FIPv4Endpoint(FIPv4Address::Any,Port);

	ListenerSocket = SocketSubsystem->CreateSocket(NAME_Stream,TEXT("TCPListener"));

	if (!ListenerSocket)
	{
		return false;
	}

	const bool bBind = ListenerSocket->Bind(EndPoint->ToInternetAddr().Get());

	if (!bBind)
	{
		return false;
	}

	const bool bListen = ListenerSocket->Listen(8);
	return bListen;
}

void UMyGameInstance::Tick(float DeltaTime) const
{
	if (ListenerSocket)
	{
		bool Pending;
		while (ListenerSocket->HasPendingConnection(Pending) && Pending)
		{
			TSharedRef<FInternetAddr> ClientAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
			FSocket* ConnectionSocket = ListenerSocket->Accept(*ClientAddr, TEXT("TCPReceivedSocket"));

			if (ConnectionSocket)
			{
				UE_LOG(LogTemp,Warning,TEXT("소켓받음"))
			}
		}
	}
}

void UMyGameInstance::StopServer()
{
	if (ListenerSocket)
	{
		ListenerSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ListenerSocket);
		ListenerSocket = nullptr;
	}
	delete EndPoint;
	EndPoint = nullptr;
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();
	StopServer();
}

