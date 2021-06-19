#include "systemc.h"
#include <iostream>

SC_MODULE(filter) {
 sc_in <float> x;
 sc_out <float> y;
 sc_in_clk Clk;
 sc_in <bool> reset;
 float b0, b1, b2, b3, b4, a0; // filter coefficients
 sc_signal <float> delayB1, delayB2, delayB3, delayA0, delayA1; // internal signals
 
 void seq_proc();
 void comb_proc();
 
 SC_CTOR(filter) {
 SC_CTHREAD(seq_proc, Clk.pos());
 SC_METHOD(comb_proc); sensitive << x << delayB1 << delayB2 << delayB3 << delayA0 << delayA1;
 b0 = 0.1667; b1 = -0.5; b2 = 0.5; b3 = -0.1667; a0 = -0.3333;
 }
};