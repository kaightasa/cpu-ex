#include <iostream>
#include <stdint.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "encode.h"


using namespace std;

uint32_t encode(string);
extern uint32_t encode_to_op(vector<string>);

uint32_t encode(string str) {
	stringstream ss(str);
	vector<string> vitem;
	while(getline(ss, string item, ' ')) {
		vitem.push_back(item);
	}
	uint32_t op = encode_to_op(vitem);
	return op;
}

int main(int argc, char** argv) {

	if (argc < 3) {
		cerr << "too few arguments put as follows: ./asm [inputfile] [outputfile]" << endl;
		return 1;
	}
	
	ifstream filein(argv[1]);
	ofstream fileout(argv[2]);

	uint32_t op;
	int linenum = 0;
	for (string line; getline(filein, line);) {
		//line の処理
		linenum++;
		op = encode(line);
		if (op == 0xffffffff) {
			cerr << "not defined in line" << linenum << endl;
			continue;
		}
		//simulator用にバイナリ出力に直す
		fileout << hex << op << endl;
	}

	filein.close();

	fileout.close();

	return 0;
}


