#include <iostream>
#include "encode.h"

using namespace std;

#define scmp(str) vitem[0].compare(str)==0

uint32_t encode_to_op(vector<string> vitem) {
	if (scmp("add")) {return op_li(vitem);}
	if (scmp("mr")) {return op_addi(vitem);}
	if (scmp("addi")) {return op_addi(vitem);}
	if (scmp("add")) {return op_add(vitem);}
	if (scmp("sub")) {return op_sub(vitem);}
	if (scmp("slwi")) {return op_slwi(vitem);}
	if (scmp("srwi")) {return op_srwi(vitem);}
	if (scmp("fadd")) {return op_fadd(vitem);}
	if (scmp("fsub")) {return op_fsub(vitem);}
	if (scmp("fdiv")) {return op_fdiv(vitem);}
	if (scmp("fmul")) {return op_(vitem);}
	if (scmp("fsqrt")) {return op_fsqrt(vitem);}
	if (scmp("fabs")) {return op_fabs(vitem);}
	if (scmp("b")) {return op_b(vitem);}
	if (scmp("beq")) {return op_beq(vitem);}
	if (scmp("bne")) {return op_bne(vitem);}
	if (scmp("blt")) {return op_blt(vitem);}
	if (scmp("bl")) {return op_bl(vitem);}
	if (scmp("blr")) {return op_blr(vitem);}
	if (scmp("mflr")) {return op_mflr(vitem);}
	if (scmp("mtlr")) {return op_mtlr(vitem);}
	if (scmp("cmpwi")) {return op_cmpwi(vitem);}
	if (scmp("cmpw")) {return op_cpmw(vitem);}
	if (scmp("fcmp")) {return op_fcmp(vitem);}
	if (scmp("ld")) {return op_ld(vitem);}
	if (scmp("st")) {return op_st(vitem);}
	if (scmp("fld")) {return op_fld(vitem);}
	if (scmp("fst")) {return op_fst(vitem);}

	uint32_t other = 0xffffffff;
	return other;
}


