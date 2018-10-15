#ifndef OPASM_H_
#define OPASM_H_

#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

vector<string> StringSplit(const string, char);

uint32_t get_rD(string);
uint32_t get_rA(string);
uint32_t get_rB(string);
uint32_t get_simm16(string);
uint32_t get_imm5(string);
uint32_t get_simm26(string);

uint32_t op_li(vector<string>);
uint32_t op_mr(vector<string>);
uint32_t op_addi(vector<string>);
uint32_t op_add(vector<string>);
uint32_t op_sub(vector<string>);
uint32_t op_slwi(vector<string>);
uint32_t op_srwi(vector<string>);
uint32_t op_fadd(vector<string>);
uint32_t op_fsub(vector<string>);
uint32_t op_fdiv(vector<string>);
uint32_t op_fmul(vector<string>);
uint32_t op_fsqrt(vector<string>);
uint32_t op_fabs(vector<string>);
uint32_t op_fmr(vector<string>);
uint32_t op_b(vector<string>);
uint32_t op_beq(vector<string>);
uint32_t op_bne(vector<string>);
uint32_t op_blt(vector<string>);
uint32_t op_bl(vector<string>);
uint32_t op_blr(vector<string>);
uint32_t op_mflr(vector<string>);
uint32_t op_mtlr(vector<string>);
uint32_t op_cmpwi(vector<string>);
uint32_t op_cmpw(vector<string>);
uint32_t op_fcmp(vector<string>);
uint32_t op_ld(vector<string>);
uint32_t op_st(vector<string>);
uint32_t op_fld(vector<string>);
uint32_t op_fst(vector<string>);

uint32_t set_txt(vector<string>);
uint32_t set_align(vector<string>);
uint32_t set_globl(vector<string>);
uint32_t set_label(vector<string>);

#endif //OPASM_H_
