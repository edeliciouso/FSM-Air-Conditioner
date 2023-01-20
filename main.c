#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib/mylib.h"

void green(){
    printf("\033[0;32m");
}

void reset(){
    printf("\033[0m");
}

void on(){
    printf("======================\n");
    printf("|                    |\n");
    printf("|   Air Conditioner  |\n");
    printf("|         Is         |\n");
    green();
    printf("|         ON         |\n");
    reset();
    printf("|                    |\n");
    printf("|                    |\n");
    printf("______________________\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|  swing     on/off  |\n");
    printf("|   xxx        xxx   |\n");
    printf("|  xxxxx      xxxxx  |\n");
    printf("|   xxx        xxx   |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("======================\n");
    reset();
}

void off(){
    printf("======================\n");
    printf("|                    |\n");
    printf("|   Air Conditioner  |\n");
    printf("|         Is         |\n");
    printf("|         OFF        |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("______________________\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|  swing     on/off  |\n");
    printf("|   xxx        xxx   |\n");
    printf("|  xxxxx      xxxxx  |\n");
    printf("|   xxx        xxx   |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("======================\n");
    reset();
}

void swing(){
    printf("======================\n");
    printf("|                    |\n");
    printf("|   Air Conditioner  |\n");
    printf("|         Is         |\n");
    green();
    printf("|    In SWING Mode   |\n");
    reset();
    printf("|                    |\n");
    printf("|                    |\n");
    printf("______________________\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|  swing     on/off  |\n");
    printf("|   xxx        xxx   |\n");
    printf("|  xxxxx      xxxxx  |\n");
    printf("|   xxx        xxx   |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("======================\n");
    reset();
}

int main(void){
    // Set initial state.
    int s0 = 0, s1 = 0, b1 = 0, b2 = 0, S0 = 0, S1 = 0, o0 = 0, o1 = 0;

    // Loop.
    while(true){
        printf("\033[2J\033[1;1H");
        if (S0 == 0 && S1 == 0){
            off();
            printf("Current state: %d %d",s0,s1);
            printf("\nInputs: %d %d", b1, b2);
            printf("\nOutput: %d %d\n", o0, o1);
        }
        else if(S0 == 0 && S1 == 1){
            on();
            printf("Current state: %d %d",s0,s1);
            printf("\nInputs: %d %d", b1, b2);
            printf("\nOutput: %d %d\n", o0, o1);
        }
        else if(S0 == 1 && S1 == 0){
            swing();
            printf("Current state: %d %d",s0,s1);
            printf("\nInputs: %d %d", b1, b2);
            printf("\nOutput: %d %d\n", o0, o1);
        }
        
        // Get user input.
        b1 = 0;
        b2 = 0;
        int button;
        printf("\nSelect a button ([1] for SWING | [2] for ON/OFF): ");
        scanf("%d", &button);

        if (button == 0){
            b1 = 0;
            b2 = 0;
        } else if (button == 2){
            b1 = 0;
            b2 = 1;
        } else if (button == 1){
            b1 = 1;
            b2 = 0;
        } else {
            b1 = 0;
            b2 = 0;
        }
    
        // Calculate the next state and output
        states(s0, s1, b1, b2, &S0, &S1);
        s0 = S0;
        s1 = S1;
        outputs(s0, s1, &o0, &o1);

    }

    return 0;

}
