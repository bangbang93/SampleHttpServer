#pragma once

#include <string>
#include <map>

using namespace std;
map<string, string> mime_map;

void init_mime();
string get_mime(string fix);