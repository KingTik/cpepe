#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void set_bit(int index, int *reg){
    int mask = 1 << index;
    *reg |= mask;

}

void unset_bit(int index, int *reg){
    int mask = 1 << index;
    *reg &= INT_MAX ^ mask;

}

void invert_bit(int index, int *reg){
    int mask = 1 << index;
    *reg ^= mask;

}


int main(){


    
    int a = 15;
    int *r = &a;
    printf("*r: %d\n", *r);
    
    unset_bit(3, r);

    printf("*r: %d\n", *r);
}