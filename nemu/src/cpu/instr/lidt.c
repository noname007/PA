#include "cpu/instr.h"

make_instr_func(lidt)
{
	 int len = 1;
    OPERAND MEM;
    MEM.data_size = data_size;
    MEM.type = OPR_MEM;

    len += modrm_rm(eip + 1, &MEM);

    OPERAND limit, base;
    limit.data_size = 16;
    limit.type = OPR_MEM;
    limit.addr = MEM.addr;
    base.data_size = (data_size == 32) ? 32 : 24;
    base.type = OPR_MEM;
    base.addr = MEM.addr + limit.data_size / 8;

    cpu.idtr.base = laddr_read(base.addr, base.data_size / 8);
    cpu.idtr.limit = laddr_read(limit.addr, limit.data_size / 8);
    
    print_asm_0("lgdt", "", len + 5);

    return len;
}