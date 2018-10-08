#include <iostream>
#include <vector>
#include <stdint.h>
#include "instruction.h"
#include "op.h"

using namespace std;

extern uint32_t* INST_MEM;
extern uint32_t PC;
extern uint32_t OP;

uint32_t get_opname(uint32_t ui) {
	ui = ui>>26;
}

int do_op() {
	OP = INST_MEM[PC];
	uint32_t opname = get_opname(OP);

	
	switch((int)opname) {
		case 0: 
			load_imm();PC++;break;
		case 1:
			move_reg();PC++;break;
		case 2:
			add_imm();PC++;break;
		case 3:
			add_reg();PC++;break;
		case 4:
			sub_reg();PC++;break;
		case 5:
			l_shift_lg_imm();PC++;break;
		case 6:
			r_shift_lg_imm();PC++;break;
		case 7:
			fadd();PC++;break;
		case 8:
			fsub();PC++;break;
		case 9:
			fdiv();PC++;break;
		case 10:
			fmul();PC++;break;
		case 11:
			fsqrt();PC++;break;
		case 12:
			fabs();PC++;break;
		case 13:
			fmove_reg();PC++;break;
		case 14:
			branch();break;
		case 15:
			branch_eq();break;
		case 16:
			branch_neq();break;
		case 17:
			branch_lt();break;
		case 18:
			branch_and_link();break;
		case 19:
			branch_link_reg();break;
		case 20:
			move_from_link();break;
		case 21:
			move_to_link();break;
		case 22:
			cmp_imm();break;
		case 23:
			cmp_reg();break;
		case 24:
			fcmp_reg();break;
		case 25:
			load();break;
		case 26:
			store();break;
		case 27:
			fload();break;
		case 28:
			fstore();break;
		default:
			cerr << "undefined instruction" << endl;
			return 1;
	}

	return 0;
}





