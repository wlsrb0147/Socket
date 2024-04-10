// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTCP.h"

#include "Sockets.h" // Socket->Connect
#include "SocketSubsystem.h" // ISocketSubSystem
#include "Interfaces/IPv4/IPv4Address.h" // IPv4

bool UTestTCP::CreateTCPConnection()
{
	//소켓 생성
	FSocket* Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream,TEXT("TCPClient"),false);

	// 서버 주소 설정
	FIPv4Address IP;
	FIPv4Address::Parse(TEXT("127.0.0.1"),IP);

	const TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	Addr->SetIp(IP.Value);
	Addr->SetPort(6000);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Trying to connect.")));
	
	const bool Connected = Socket->Connect(*Addr);

	if (Connected)
	{
		const TCHAR* SendData = TEXT("Hello, Server!");
		int32 BytesSent = 0;
		Socket->Send((uint8*)TCHAR_TO_UTF8(SendData),FCString::Strlen(SendData)*sizeof(TCHAR),BytesSent);
		UE_LOG(LogTemp,Warning,TEXT("Success"))
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Failed"))
	}
	
	Socket->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	
	return Connected;
}
