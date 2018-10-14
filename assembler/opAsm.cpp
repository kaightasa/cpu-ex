#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>
#include <sstream>
#include "opAsm.h"

using namespace std;


vector<string> StringSplit(const string str, char sep) {
	vector<string> v;
	stringstream ss(str);
	string buffer;
	while(getline(ss, buffer, sep)) {
		v.push_back(buffer);
	}
	return v;
}

uint32_t getrD(string str) {
	vector<string> vtmp = StringSplit(str, 'r');
	int r = stoi(vtmp[1]);
	return r << 21;
}	

