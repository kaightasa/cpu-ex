#include <iostream>
#include <stdint.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "encode.h"
#include "opAsm.h"


using namespace std;

uint32_t encode(string);
uint32_t PC = 0;
extern vector<string> StringSplit(const string, char);
extern uint32_t encode_to_op(vector<string>);

uint32_t encode(string str) {
	vector<string> vitem = StringSplit(str, ' ');
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
			cerr << "undefined instruction" << linenum << endl;
			return 1;
		}
		if (op == 0x00000000) {
			continue;
		}
		//simulator用にバイナリ出力に直す
		fileout << hex << op << endl;
		PC += 4;
	}

	filein.close();

	fileout.close();

	return 0;
}

