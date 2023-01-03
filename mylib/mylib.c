#include <stdio.h>

void states(int s0, int s1, int i1, int i2, int* S0, int* S1){
    *S0 = s0 & (!i2) | s1 & i1;
    *S1 = s0 & i1 | s1 & (!i2) | ((!s0) & (!s1)) & ((!i1) & (!i2));
}