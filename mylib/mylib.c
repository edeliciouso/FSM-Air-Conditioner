#include <stdio.h>

// void states(int s0, int s1, int i1, int i2, int* S0, int* S1){
//     *S0 = s0 & (!i2) | s1 & i1;
//     *S1 = s0 & i1 | s1 & (!i2) | ((!s0) & (!s1)) & ((!i1) & (!i2));
// }

void states(int s0, int s1, int b1, int b2, int* S0, int* S1, int* o0, int* o1){
    *S0 = (!b1) & (!b2) & s0 | b1 & s0 & s1;
    *S1 = b2 & (!s0) & (!s1) | b1 & s0 & (!s1) | (!b1) & (!b2) & s1;
    *o0 = s0 & (!s1);
    *o1 = (!s0) & s1;
}