#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <stdint.h>
#include "op.h"

#define INST_ADDR 0x10000
#define DATA_ADDR 0x10000

using namespace std;

vector<uint32_t> GPR(32, 0);//汎用レジスタ
vector<float> FPR(32, 0.0);//浮動小数点レジスタ

uint32_t CR = 0;//コンディションレジスタ
//CR0~CR7の8個の4bitフィールド

uint32_t LR = 0;//リンクレジス\タ
uint32_t CTR = 0;//カウントレジスタ
uint32_t INST_MEM[INST_ADDR] = {};//命令のバイナリを読み込む

uint32_t DATA_MEM[DATA_ADDR] = {};//データを保存するメモリ

uint32_t PC = 0;
uint32_t OP = 0;

//bitを取り出す
/*static inline uint32_t bits(uint32_t inst, unsigned int i, unsigned int j) {
	return (inst & ((1 << (i+1)) - (1 << j))) >> j;
}*/
	
//debug用に各レジスタを出力する関数をつくる

void debug();

#define SHOWGPR()\
	do { \
		vector<uint32_t>::iterator itr;\
		for (itr = GPR.begin(); itr != GPR.end(); itr++) {cout << hex << *itr << " ";} \
		cout << endl;}\
	while (0)

#define SHOWFPR()\
	do { \
		vector<float>::iterator itr;\
		for (itr = FPR.begin(); itr != FPR.end(); itr++) {cout << hex << *itr << " ";} \
		cout << endl;}\
	while (0)

#define SHOWCR() cout << hex << CR << endl
#define SHOWLR() cout << hex << LR << endl
#define SHOWCTR() cout << hex << CTR << endl
#define SHOWPC() cout << hex << PC << endl
#define SHOWOP() cout << hex << OP << endl

void debug() {
	while (1) {
		cout << "which register to show? put a number...GPR--0, FPR--1, CR--2, LR--3, CTR--4; PC--5, OP--6, end--7" << endl;
		int x;
		cin >> x;
		switch(x) {
		case 0:
			SHOWGPR();break;
		case 1:
			SHOWFPR();break;
		case 2:
			SHOWCR();break;
		case 3:
			SHOWLR();break;
		case 4:
			SHOWCTR();break;
		case 5:
			SHOWPC();break;
		case 6:
			SHOWOP();break;
		case 7:
			return;;
		default:
			cout << "pls put 0~7" << endl;break;
		}
	}
}

int main(int argc, char**argv) {
	if (argc != 2) {
		cerr << "invailed argument: did you specified input file?" << endl;
		return EXIT_FAILURE;
	}
	FILE* binary;

	binary = fopen(argv[1], "rb");
	if (!binary) {
		cerr << "cannot open file" << endl;
		return EXIT_FAILURE;
	} 

	size_t cnt;
	size_t pos = 0;
	while (cnt = fread(&INST_MEM[pos], 4, 2048, binary)) {
		pos += cnt;
	} 
	int lastPc = pos;
	fclose(binary);

	while(PC <= lastPc) {
		int result = do_op();
		if (!result) {
			cerr << "error at PC:" << hex << PC << endl;
			cerr << "move to debug mode" << endl;
			debug();
			return EXIT_FAILURE;
		}
	}
} 
