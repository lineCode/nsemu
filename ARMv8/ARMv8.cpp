/* nsemu - LGPL - Copyright 2017 rkx1209<rkx1209dev@gmail.com> */
#include "Nsemu.hpp"
static Interpreter *cpu_engine;
namespace ARMv8 {

ARMv8State arm_state;

void Init() {
	Interpreter::create ();
	cpu_engine = Interpreter::get_instance ();
        PC = 0x0;
        SP = 0x30000;
}

void RunLoop() {
	cpu_engine->Run ();
}

void Dump() {
        for (int r = 0; r < GPR_DUMMY; r++) {
                if (!X(r))
                        continue;
                if (r == GPR_LR)
                        debug_print ("LR\t");
                else if (r == GPR_SP)
                        debug_print ("SP\t");
                else
                        debug_print ("X%d\t", r);
                debug_print ("0x%016lx\n", X(r));
        }
        debug_print ("PC\t0x%016lx\n", PC);
        debug_print ("NZCV\t0x%016lx\n", NZCV);
}

}
