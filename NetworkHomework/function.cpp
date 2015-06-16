#include "stdafx.h"
#include <string>
#include <fstream>
#include <map>

using namespace std;

extern map<string, string> mime_map;
extern string get_mime(string);

string get_mime_type(string filename){
	const char *p = strrchr(filename.c_str(), '.');
	if (p == NULL)
	{
		return mime_map["html"];
	}
	string postfix(p);
	postfix = postfix.substr(1);
	return get_mime(postfix);
}

string make_http_header(int status, string mimetype = nullptr){
	return "";
}

string read_file(string filename, int &length)
{
	ifstream file(filename);
	if (file.is_open() == false)
	{
		if (filename.find("index.html") == string::npos)
		{
			return read_file(filename + "/index.html", length);
		} else
		{
			length = -1;
			return "";
		}
	} else
	{
		file.seekg(0, ios::end);
		ios::pos_type ss = file.tellg();
		file.seekg(0, ios::beg);
		char* buffer = (char*)malloc(ss);
		memset(buffer, 0, ss);
		memset(buffer, 0, sizeof(char)*ss);
		file.read(buffer, ss);
		string buf(buffer);
		free(buffer);
		length = buf.length();
		return buf;
	}
}