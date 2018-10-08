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

uint32_t LR = 0;//リンクレジスタ
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
			cerr << "something wrong at PC:" << PC << " OP: " << hex << OP;
			return EXIT_FAILURE;
		}
	}
}
