#include "stdafx.h"
#include <string>
#include <iostream>
#include "function.h"

using namespace std;

string build_response(string url);

string build_header(int length, string url);

string build_status(int status);

string http_request(char* request, int length)
{
	char method[10];
	char url[1024];
	char protocol[10];
	memset(method, 0, sizeof(method));
	memset(url, 0, sizeof(url));
	memset(protocol, 0, sizeof(protocol));
	sscanf_s(request, "%s %s %s", method, 10, url, 1024, protocol, 10);
	cout << method << "  " << url << "  ";
	return build_response(url);
}

string build_response(string url)
{
	int length;
	string buffer = read_file("www" + url, length);
	if (length != -1)
	{
		string header = build_header(length, url);
		buffer = build_status(200) + header + "\r\n" + buffer;
		cout << 200 << endl;
		return buffer;
	} else
	{
		string header = build_header(0, url);
		buffer = build_status(404) + header + "\r\n";
		cout << 404 << endl;
		return buffer;
	}
}

string build_header(int length, string url)
{
	char length_str[20];
	sprintf_s(length_str, "%d", length);
	string str = "Content-Type: " + get_mime_type(url) + "\r\n" +
		"Connection: Close\r\n" +
		"Content-Length: ";
	str += string(length_str);
	str += "\r\n";
	return str;
}

string build_status(int status)
{
	char str[20];
	sprintf_s(str, "HTTP/1.0 %d\r\n", status);
	return string(str);
}