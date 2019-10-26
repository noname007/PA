#include "cpu/instr.h"

make_instr_func(lea)
{
	OPERAND r, m;
	r.data_size = data_size;
	m.data_size = data_size;
	int len = 1;
	len+=modrm_r_rm(eip+1,&r,&m);
	r.val = m.addr;
	r.val = sign_ext(r.val, r.data_size);
	operand_write(&r);
	return len;
}
