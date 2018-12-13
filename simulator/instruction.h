#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_


inline int get_rD(const uint32_t ui) {
	uint32_t tmp = ui << 6;
	tmp = tmp >> 27;
	return int(tmp);
}
inline int get_rA(const uint32_t ui) {
	uint32_t tmp = ui << 11;
	tmp = tmp >> 27;
	return int(tmp);
}
inline int get_rB(const uint32_t ui) {
	uint32_t tmp = ui << 16;
	tmp = tmp >> 27;
	return int(tmp);
}
inline int32_t get_simm16(const uint32_t ui) {
	if (ui & (1 << 15)) {
		return (ui | 0xFFFF0000);
	} else {
		return (ui & 0x0000FFFF);
	}
}
inline int get_imm5(const uint32_t ui){
	uint32_t tmp = ui << 16;
	tmp = tmp >> 27;
	return int (tmp);
}
inline int32_t get_simm26(const uint32_t ui) {
	if (ui & (1 << 25)) {
		return (ui | 0xFC000000);
	} else {
		return (ui & 0x03FFFFFF);
	}
}

void cr0_set0(const uint32_t);
void cr0_set1(const uint32_t);
void cr0_set2(const uint32_t);

bool load_imm();
bool move_reg();
void add_imm();
void add_reg();
void sub_reg();
void l_shift_lg_imm();
void r_shift_lg_imm();
void fadd();
void fsub();
void fdiv();
void fmul();
void fsqrt();
void fabs();
void fmove_reg();
void branch();//無条件分岐
void branch_eq();
void branch_neq();
void branch_lt();
void branch_and_link();
void branch_link_reg();
void move_from_link();
void move_to_link();
void cmp_imm();
void cmp_reg();
void fcmp_reg();
bool load();//word
bool store();
bool fload();
bool fstore();

//added
void l_shift_lg();
void r_shift_lg();
void branch_cond();
void int_to_float();
void float_to_int();
void out();
void outstep();

//added 2
void branch_abs();
void branch_abs_and_link();

//added 3
void in();

#endif //INSTRUCTION_H_
