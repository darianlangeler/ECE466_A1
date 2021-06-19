#include "systemc.h"
#include <iomanip>

SC_MODULE(stim)
{
  sc_out<bool> reset;
  sc_out<float> x;
  sc_in_clk Clk;

  void stimgen()
  {
    reset.write(true);
    wait();
    reset.write(false);
    x.write(1);
    wait();
    x.write(0);
    //sc_stop();
  }
  SC_CTOR(stim)
  {
    SC_CTHREAD(stimgen, Clk.pos());
  }
};