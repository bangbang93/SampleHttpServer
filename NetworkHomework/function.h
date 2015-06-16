#pragma once
#include <string>

using namespace std;

string get_mime_type(string filename);

string make_http_header(int status, string mimetype);

string read_file(string filename, int &length);