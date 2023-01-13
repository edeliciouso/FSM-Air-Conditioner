<<<<<<< HEAD
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
}

int main(void){
    // Set initial state.
    int s0 = 0, s1 = 0, b1 = 0, b2 = 0, S0 = 0, S1 = 0, o0 = 0, o1 = 0;

    // Loop.
    while(true){
        if ((S0 == 0) && (S1 == 0)){
            off(); // The AC is in an off state
            if ((b1 == 0) && (b2 == 0)){
                off(); // No inputs, so the AC is off.
            } else if ((b1 == 0) && (b2 == 1)){
                on(); // 01 is the ON/OFF button, so the AC turns on.
                S1 = 1;
            } else if ((b1 == 1) && (b2 == 0)){
                off(); // 10 is the SWING button, so the AC stays off.
            }
        }
        else if((S0 == 0) && (S1 == 1)){
            on(); // 01 is an on state, so the AC is on.
            if ((b1 == 0) && (b2 == 0)){
                on(); // No inputs, so nothing changes.
            } else if((b1 == 0) && (b2 == 1)){
                off(); // ON/OFF button is pressed, so the AC turns off.
                S1 = 0;
            } else if((b1 == 1) && (b2 == 0)){
                swing(); // SWING button is pressed, so the AC is in swing mode.
                S1 = 0;
                S0 = 1;
            }
        }
        else if((S0 == 1) && (S1 == 0)){
            swing(); // 10 is swing state, so the AC is in swing mode.
            if ((b1 == 0) && (b2 == 0)){
                swing(); // No inputs.
            } else if((b1 == 0) && (b2 == 1)){
                off(); // ON/OFF button is pressed, so the AC turns off.
            } else if((b1 == 1) && (b2 == 0)){
                on(); // SWING button is pressed, so the AC is back to normal mode.
                S0 = 0;
                S1 = 1;
            }
        }
        
        // Get user input.
        b1 = 0;
        b2 = 0;
        int button;
        printf("Select a button ([1] for SWING | [2] for ON/OFF): ");
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
        } 
    }

    return 0;

=======
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
}

int main(void){
    // Set initial state.
    int s0 = 0, s1 = 0, b1 = 0, b2 = 0, S0 = 0, S1 = 0, o0 = 0, o1 = 0;

    // Loop.
    while(true){
        if ((S0 == 0) && (S1 == 0)){
            off(); // The AC is in an off state
            if ((b1 == 0) && (b2 == 0)){
                off(); // No inputs, so the AC is off.
            } else if ((b1 == 0) && (b2 == 1)){
                on(); // 01 is the ON/OFF button, so the AC turns on.
                S1 = 1;
            } else if ((b1 == 1) && (b2 == 0)){
                off(); // 10 is the SWING button, so the AC stays off.
            }
        }
        else if((S0 == 0) && (S1 == 1)){
            on(); // 01 is an on state, so the AC is on.
            if ((b1 == 0) && (b2 == 0)){
                on(); // No inputs, so nothing changes.
            } else if((b1 == 0) && (b2 == 1)){
                off(); // ON/OFF button is pressed, so the AC turns off.
                S1 = 0;
            } else if((b1 == 1) && (b2 == 0)){
                swing(); // SWING button is pressed, so the AC is in swing mode.
                S1 = 0;
                S0 = 1;
            }
        }
        else if((S0 == 1) && (S1 == 0)){
            swing(); // 10 is swing state, so the AC is in swing mode.
            if ((b1 == 0) && (b2 == 0)){
                swing(); // No inputs.
            } else if((b1 == 0) && (b2 == 1)){
                off(); // ON/OFF button is pressed, so the AC turns off.
            } else if((b1 == 1) && (b2 == 0)){
                on(); // SWING button is pressed, so the AC is back to normal mode.
                S0 = 0;
                S1 = 1;
            }
        }
        
        // Get user input.
        b1 = 0;
        b2 = 0;
        int button;
        printf("Select a button ([1] for SWING | [2] for ON/OFF): ");
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
        } 
    }

    return 0;

>>>>>>> 7881863747079c689b3f675ae5958986e4e8f591
}