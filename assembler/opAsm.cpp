#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>
#include <sstream>
#include <unordered_map>
#include "opAsm.h"

using namespace std;

uint32_t op;
extern uint32_t PC;

unordered_map<string, uint32_t> labelMap;

vector<string> StringSplit(const string str, char sep) {
	vector<string> v;
	stringstream ss(str);
	string buffer;
	while(getline(ss, buffer, sep)) {
		v.push_back(buffer);
	}
	return v;
}

uint32_t get_rD(string str) {
	vector<string> vtmp = StringSplit(str, 'r');
	int r = stoi(vtmp[1]);
	return r << 21;
}	
uint32_t get_rA(string str) {
	vector<string> vtmp = StringSplit(str, 'r');
	int r = stoi(vtmp[1]);
	return r << 16;
}
uint32_t get_rB(string str) {
	vector<string> vtmp = StringSplit(str, 'r');
	int r = stoi(vtmp[1]);
	return r << 11;
}
uint32_t get_simm16(string str) {
	int r = stoi(str);
	return r;
}
uint32_t get_imm5(string str) {
	int r = stoi(str);
	return r << 11;
}
uint32_t get_simm26(string str) {
	//labalでアドレスが指定されているならmapからlabelを探す
	uint32_t addr;
	try{
		addr = stoi(str, nullptr, 0);
	} catch (const std::invalid_argument& e) {
		addr = labelMap.at(str);
	}
	uint32_t simm26 =  PC - addr;
	return (simm26 & 0x03FFFFFF);
}


//integer
uint32_t op_li(vector<string> vitem) {
	op = 0;
	return (op & get_rD(vitem[1]) & get_simm16(vitem[2]));
}
uint32_t op_mr(vector<string> vitem) {
	op = (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]));
}
uint32_t op_addi(vector<string> vitem){
	op = (1 << 27);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_simm16(vitem[3]));
}
uint32_t op_add(vector<string> vitem){
	op = (1 << 27) | (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_rB(vitem[3]));
}
uint32_t op_sub(vector<string> vitem){
	op = (1 << 28);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_rB(vitem[3]));
}

uint32_t op_slwi(vector<string> vitem){
	op = (1 << 28) | (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_imm5(vitem[3]));
}
uint32_t op_srwi(vector<string> vitem){
	op = (1 << 28) | (1 << 27);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_imm5(vitem[3]));
}


//float
uint32_t op_fadd(vector<string> vitem){
	op = (1 << 28) | (1 << 27) | (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_rB(vitem[3]));
}
uint32_t op_fsub(vector<string> vitem){
	op = (1 << 29);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_rB(vitem[3]));
}
uint32_t op_fdiv(vector<string> vitem){
	op = (1 << 29) | (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_rB(vitem[3]));
}
uint32_t op_fmul(vector<string> vitem){
	op = (1 << 29) | (1 << 27);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_rB(vitem[3]));
}
uint32_t op_fsqrt(vector<string> vitem){
	op = (1 << 29) | (1 << 27) | (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]));
}
uint32_t op_fabs(vector<string> vitem){
	op = (1 << 29) | (1 << 28);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]));
}
uint32_t op_fmr(vector<string> vitem){
	op = (1 << 29) | (1 << 28) | (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]));
}


//条件分岐
uint32_t op_b(vector<string> vitem) {
	op = (1 << 29)| (1 << 28) | (1 << 27);
	return (op & get_simm26(vitem[1]));
}
uint32_t op_beq(vector<string> vitem){
	op = (1 << 29)| (1 << 28) | (1 << 27) | (1 << 26);
	return (op & get_simm26(vitem[1]));
}
uint32_t op_bne(vector<string> vitem){
	op = (1 << 30);
	return (op & get_simm26(vitem[1]));
}
uint32_t op_blt(vector<string> vitem){
	op = (1 << 30)| (1 << 26);
	return (op & get_simm26(vitem[1]));
}
uint32_t op_bl(vector<string> vitem){
	op = (1 << 30)| (1 << 27);
	return (op & get_simm26(vitem[1]));
}
uint32_t op_blr(vector<string> vitem){
	op = (1 << 30) | (1 << 27) | (1 << 26);
	return op;
}
uint32_t op_mflr(vector<string> vitem){
	op = (1 << 30) | (1 << 28);
	return (op & get_rD(vitem[1]));
}
uint32_t op_mtlr(vector<string> vitem){
	op = (1 << 30) | (1 << 28) | (1 << 26);
	return (op & get_rD(vitem[1]));
}


//compare
uint32_t op_cmpwi(vector<string> vitem){
	op = (1 << 30) | (1 << 28) | (1 << 27);
	return (op & get_rA(vitem[1]) & get_simm16(vitem[2]));
}
uint32_t op_cmpw(vector<string> vitem){
	op = (1 << 30) | (1 << 28) | (1 << 27) | (1 << 26);
	return (op & get_rA(vitem[1]) & get_rB(vitem[2]));
}
uint32_t op_fcmp(vector<string> vitem){
	op = (1 << 30) | (1 << 29);
	return (op & get_rA(vitem[1]) & get_rB(vitem[2]));
}


//load and store
uint32_t op_ld(vector<string> vitem){
	op = (1 << 30) | (1 << 29) | (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_simm16(vitem[3]));
}
uint32_t op_st(vector<string> vitem){
	op = (1 << 30) | (1 << 29) | (1 << 27);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_simm16(vitem[3]));
}
uint32_t op_fld(vector<string> vitem){
	op = (1 << 30) | (1 << 29) | (1 << 27) | (1 << 26);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_simm16(vitem[3]));
}
uint32_t op_fst(vector<string> vitem){
	op = (1 << 30) | (1 << 29) | (1 << 28);
	return (op & get_rD(vitem[1]) & get_rA(vitem[2]) & get_simm16(vitem[3]));
}



uint32_t set_txt(vector<string> vitem) {
	return 0;
}
uint32_t set_align(vector<string> vitem) {
	return 0;
}
uint32_t set_globl(vector<string> vitem) {
	return 0;
}
uint32_t set_label(vector<string> vitem) {
	vector<string> vtmp = StringSplit(vitem[0], ':');
	labelMap[vtmp[0]] = PC;
	return 0;
}
	
