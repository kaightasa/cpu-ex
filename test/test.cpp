#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <sstream>
#include <string>
#include <fstream>
#include <regex>
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
string trim(const string& str, const char* trimCharacterList = "\t\v\r\n") {
	string result;
	string::size_type left = str.find_first_not_of(trimCharacterList);

	if (left != string::npos) {
		string::size_type right = str.find_last_not_of(trimCharacterList);
		result = str.substr(left, right-left+1);
	}
	return result;
}

uint32_t bits(uint32_t inst, unsigned int i, unsigned int j) {
	return (inst & ((1 << (i + 1)) - (1 << j))) >> j;
}
uint32_t getBit(uint32_t x, int max, int min) {
	uint32_t tmp = x << (31 - max);
	tmp = tmp >> (31-max+min);
	return tmp;
}
uint64_t getBit(uint64_t x, int max, int min) {
	uint64_t tmp = x << (63 - max);
	tmp = tmp >> (63-max+min);
	return tmp;
}

int main(int argc, char** argv) {
	/*uint32_t a = 0x0000000F;
	cout << (int)a << endl;
	uint32_t b = 0x0000000F;
	uint32_t c = a + b;
	cout << c << endl;
	printf("%x\n", c);*/

	/*uint32_t c = 0x0000000E;
	int32_t d = 0xFFFFFFFF;
	uint32_t e = c + d;
	cout << e << endl;
	printf("%x\n", e);*/
	//printf("%x\n", (uint32_t)e);

	/*float e = 2.7;
	//float f = 3.4;
	printf("%f\n", e);
	//printf("%f\n", f);
	float g = sqrt(e);
	cout << g << endl;
	printf("%f\n", g);*/

	/*vector<string> vkey = StringSplit("li rD, value", ' ');
	cout << vkey[0] << endl;
	cout << vkey[1] << endl;
	cout << vkey[2] << endl*/;
	/*string str = "	addi rD, rA,5		";
	str = trim(str);
	vector<string> vitem;
	vector<string> vitem1 = StringSplit(str, ' ');
	//,カンマを削除
	vector<string>::iterator itr; 
	for (itr = vitem1.begin(); itr != vitem1.end(); itr++) {
		vector<string> vitem2 = StringSplit(*itr, ',');
		vector<string>::iterator itr2;
		for (itr2 = vitem2.begin(); itr2 != vitem2.end(); itr2++) {
			vitem.push_back(*itr2);
		}
	}
	vector<string>::iterator itrout;
	for (itrout = vitem.begin(); itrout != vitem.end(); itrout++) {
		cout << *itrout << endl;
	}*/

	/*if (argc < 2) {
		cerr << "too few arguments!" << endl;
		return 1;
	}
	cout << "open inputfile..." << endl;
	ifstream filein(argv[1]);
	string line;
	while (getline(filein,line)) {
		cout << line << endl;
		if (line == "") {
			cout << "null line" << endl;
		}
	}*/

	/*uint32_t result = (0x10000000) | (0xFFFFFFFF) | (0x00000000);
	cout << hex << result << dec << endl;*/
	/*string str = "lo(label)";
	regex re(R"(ha\(.*\))");
	bool result = regex_match(str, re);
	cout << result << endl;*/

/*	string str = "	.globl _min_caml_start";
	string trimmedStr = trim(str);
	cout << "trimmedStr: " << trimmedStr << endl;
	vector<string> vitem;
	vector<string> vitemtmp;
	vector<string> vitem1 = StringSplit(trimmedStr, '\t');
	vector<string>::iterator itr;
	cout << "split by tab:";
	for (itr = vitem1.begin(); itr != vitem1.end(); itr++) {
		cout << " [" << *itr << "]";
		vector<string> vitem2 = StringSplit(*itr, ' ');
		vector<string>::iterator itr2;
		for (itr2 = vitem2.begin(); itr2 != vitem2.end(); itr2++) {
				vitemtmp.push_back(*itr2);
		}
	}
	cout << endl << "split by space:";
	vector<string>::iterator itrtmp;
	for (itrtmp = vitemtmp.begin(); itrtmp != vitemtmp.end(); itrtmp++) {
		cout << " [" << *itrtmp << "]";
		vector<string> vitem3 = StringSplit(*itrtmp, ',');
		vector<string>::iterator itr3;
		for (itr3 = vitem3.begin(); itr3 != vitem3.end(); itr3++) {
				vitem.push_back(*itr3);
		}
	}
	cout << endl << "split by ,:";
	vector<string>::iterator itrz;
	for (itrz = vitem.begin(); itrz != vitem.end(); itrz++) {
		cout << " [" << *itrz << "]";
	}
	cout << endl;*/

/*	uint32_t x = 0xAFCFBEFF;
	uint32_t tmp = getBit(x, 19,4);
	cout << "x " << hex << x << endl;
	cout << "x 19~4 " << tmp << endl;

	uint64_t y = 0xDF489AFCFBEFF000;
	uint64_t tmp2 = getBit(y, 55,0);
	cout << "y " << hex << y << endl;
	cout << "y 55~0 " << tmp2 << endl;*/

	/*uint32_t r0 = 0xffffffff;
	int32_t r1 = int32_t(r0);
	int32_t r2 = 0;

	if (r1 < r2) {
		cout << r0 << endl;
		cout << "r1 is less than r2" << endl;
		cout  << hex << "r1: " << r1 << "  r2: " << r2 << endl;
	} else if (r1 == r2) {
		cout << r0 << endl;
		cout << "r1 equals to r2" << endl;
		cout << hex << "r1: " << r1 << "  r2: " << r2 << endl;
	} else {
		cout << r0 << endl;
		cout << "r1 is bigger than r2" << endl;
		cout << hex << "r1: " << r1 << "  r2: " << r2 << endl;
	}*/

	float tmp = 3.14159;
	float tmp2 = -3.14159;
	uint32_t utmp = *(uint32_t*)&tmp;
	uint32_t utmp2 = *(uint32_t*)&tmp2;
	cout << hex << utmp << endl;
	cout << *(float*)&utmp << endl;
	cout << hex << utmp2 << endl;
	cout << *(float*)&utmp2 << endl;
}


