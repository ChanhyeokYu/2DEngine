#include "TCPSocket.h"
#include <iostream>

TCPSocket::TCPSocket()
{
}

TCPSocket::~TCPSocket()
{
    Shutdown();
}

bool TCPSocket::Initialize()
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        std::cerr << "WSAStartup failed with error: " << result << std::endl;
        return false;
    }

    return true;
}

void TCPSocket::Shutdown()
{
    if (Socket_ != INVALID_SOCKET) // 소켓이 유효할 경우 소켓을 닫기
    {
        closesocket(Socket_);
        Socket_ = INVALID_SOCKET;
    }
    WSACleanup();
}

bool TCPSocket::BindAndListen(int port)
{
    isServer_ = true;

    // 소켓 생성
    Socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Socket_ == INVALID_SOCKET)
    {
        std::cerr << "Failed to create socket. Error: " << WSAGetLastError() << std::endl;
        return false;
    }

    // IP4용 소켓 정보를 저장
    sockaddr_in service; 
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = INADDR_ANY;
    service.sin_port = htons(port); // PC는 리틀엔디안을 사용 하지만 네트워크는 빅 엔디안을 사용하기 때문에 바이트 순서 변환

    // 범용 소켓 클래스로 캐스팅 후 바인딩
    // 나의 소켓을 쓸 객체를 바인딩
    if (bind(Socket_, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(Socket_);
        Socket_ = INVALID_SOCKET;
        return false;   
    }

    //바인딩 한 소켓 리슨
    if (listen(Socket_, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "Listen failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(Socket_);
        Socket_ = INVALID_SOCKET;
        return false;
    }

    std::cout << "Server listening on port" << port << std::endl;
    return false;
}

std::shared_ptr<TCPSocket> TCPSocket::Accpet()
{
    if (!isServer_ || Socket_ == INVALID_SOCKET)
    {
        return nullptr;
    }

    // 커넥트를 허용한 클라이언트 소켓
    SOCKET clientSocket = accept(Socket_, nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Accept failed. Error: " << WSAGetLastError() << std::endl; 
        return nullptr;

    }

    auto client = std::make_shared<TCPSocket>();
    client->Socket_ = clientSocket;
    return client;
}

bool TCPSocket::Connect(const std::string& address, int port)
{
    isServer_ = false;

    // 클라이언트가 사용할 소켓 생성
    Socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Socket_ == INVALID_SOCKET)
    {
        std::cerr << "Socket creation failed. Error: " << WSAGetLastError() << std::endl;
        return false;
    }

    // IP4 구조체에 정보 입력
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, address.c_str(), &serverAddr.sin_addr); //사람이 읽기 편한 문자열을 컴퓨터가 사용하는 바이너리 문자열로 변환
    serverAddr.sin_port = htons(port);

    int result = connect(Socket_, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == SOCKET_ERROR)
    {
        std::cerr << "Connection failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(Socket_);
        Socket_ = INVALID_SOCKET;
        return false;
    }

    std::cout << "Connection to server: " << address << ":" << port << std::endl;
    return true;

}

int TCPSocket::Send(const char* data, int length)
{
    if (Socket_ == INVALID_SOCKET)
    {
        return -1;
    }
    int bytesSent = send(Socket_, data, length, 0);
    if (bytesSent == SOCKET_ERROR)
    {
        std::cerr << "Send failed. Error: " << WSAGetLastError() << std::endl;
        return -1;
    }
    return bytesSent;

}

int TCPSocket::Receive(char* buffer, int length)
{
    if (Socket_ == INVALID_SOCKET)
    {
        return -1;
    }
    
    int bytesReceived = recv(Socket_, buffer, length, 0);
    if (bytesReceived == SOCKET_ERROR)
    {
        std::cerr << "Receive fail. Error: " << WSAGetLastError() << std::endl;
        return -1;
    }

    return bytesReceived;

}
