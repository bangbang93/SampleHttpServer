// NetworkHomework.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <winsock2.h>
#include <iostream>
#include "http.h"

#pragma comment(lib,"Ws2_32.lib")

using namespace std;

#define PORT 8080
#define MAX_EVENT 1000
#define null NULL

SOCKET sock;
WSAEVENT events[WSA_MAXIMUM_WAIT_EVENTS];
SOCKET socks[WSA_MAXIMUM_WAIT_EVENTS];

int event_count = 0;

int setupSocket();
void event_loop();
void write_response(string response, int i);

extern void init_mime();

int _tmain(int argc, _TCHAR* argv[])
{
	init_mime();
	int network_stat = setupSocket();
	if (network_stat != 0)
	{
		return network_stat;
	}
	WSAEVENT event = WSACreateEvent();
	WSAEventSelect(sock, event, FD_ACCEPT | FD_CLOSE);
	socks[event_count] = sock;
	events[event_count] = event;
	event_count++;
	event_loop();
	return 0;
}

int setupSocket()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(1, 1), &wsadata);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		cout << "socket() failed" << endl;
		cout << WSAGetLastError() << endl;
		return -1;
	}
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	if (bind(sock, (sockaddr*)&addr, sizeof(addr)) == INVALID_SOCKET)
	{
		cout << "bind() failed" << endl;
		cout << WSAGetLastError() << endl;
		return -1;
	}
	if (listen(sock, 10) == INVALID_SOCKET)
	{
		cout << "listen() failed" << endl;
		cout << WSAGetLastError() << endl;
	}
	return 0;
}

void event_loop()
{
	cout << "ready for connection on port:" << PORT << endl;
	while (true)
	{
		int index = WSAWaitForMultipleEvents(event_count, events, false, WSA_INFINITE, false);
		index -= WSA_WAIT_EVENT_0;
		for (int i = index; i < event_count; i++)
		{
			int ret = WSAWaitForMultipleEvents(1, &events[i], true, 1000, false);
			if (ret == WSA_WAIT_FAILED || ret == WSA_WAIT_TIMEOUT)
			{
				continue;
			}
			WSANETWORKEVENTS event;
			WSAEnumNetworkEvents(socks[i], events[i], &event);
			if (event.lNetworkEvents & FD_ACCEPT)
			{
				if (event.iErrorCode[FD_ACCEPT_BIT] == 0)
				{
					if (event_count > WSA_MAXIMUM_WAIT_EVENTS)
					{
						cout << "Too many connections, overload" << endl;
						continue;
					}
					SOCKET client = accept(socks[i], null, null);
					WSAEVENT event = WSACreateEvent();
					WSAEventSelect(client, event, FD_READ | FD_CLOSE | FD_WRITE);
					events[event_count] = event;
					socks[event_count] = client;
					event_count++;
				}
			}
			else if (event.lNetworkEvents & FD_READ)
			{
				if (event.iErrorCode[FD_READ_BIT] == 0)
				{
					char buffer[4096];
					memset(buffer, 0, sizeof(buffer));
					int bytes = recv(socks[i], buffer, 1024, 0);
					if (bytes > 0)
					{
						string response = http_request(buffer, bytes);
						write_response(response, i);
					}
				}
			} else if (event.lNetworkEvents & FD_CLOSE)
			{
				if (event.iErrorCode[FD_CLOSE_BIT] == 0)
				{
					closesocket(socks[i]);
					for (int j = i; j < event_count - 1; j++)
					{
						socks[j] = socks[j + 1];
						events[j] = events[j + 1];
					}
					event_count--;
				}
			} else if (event.lNetworkEvents & FD_WRITE)
			{
				// nothing todo
			}
		}
	}
}

void write_response(string response, int i)
{
	send(socks[i], response.c_str(), response.length(), 0);
	closesocket(socks[i]);
	for (int j = i; j < event_count - 1; j++)
	{
		socks[j] = socks[j + 1];
		events[j] = events[j + 1];
	}
	event_count--;
}