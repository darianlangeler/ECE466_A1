#include "filter.h"
#include "systemc.h"
#include <iostream>

 void filter::seq_proc() {
 while (1) {
 if (reset.read() == true) {
 delayB1.write(0);
 delayB2.write(0);
 delayB3.write(0);
 delayA0.write(0);
 delayA1.write(0);
}
 else {
 delayB1.write( x.read() );
 delayB2.write( delayB1.read() );
 delayB3.write( delayB2.read() );
 
 delayA0.write( y.read() );
 delayA1.write( delayA0.read() );
}
wait();
 }
 }
 
 void filter::comb_proc() {
 float xs = x.read();
 float delayB1s = delayB1.read();
 float delayB2s = delayB2.read();
 float delayB3s = delayB3.read();
 
 float delayA0s = delayA0.read();
 float delayA1s = delayA1.read();
 
 //Compute B(z) and put output as middle
 float middle = xs*b0 + delayB1s*b1 + delayB2s*b2 + delayB3s*b3;
 
 // Sum B(z) and A(z) and put directly into y
 y.write( middle + delayA1s*a0);
 }
 