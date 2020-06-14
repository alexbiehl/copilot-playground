#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "heater.h"

void heatoff(float x) {
    printf("heatoff %f\n", x);
}

void heaton(float x) {
    printf("heaton %f\n", x);
}

uint8_t temperature = 0;

int main(int argc, char **argv) {
    while (1) {
        // Generate a random temperature between -50 to 100 ala
        //   temperature = (rand() % (upper – lower + 1)) + lower
        temperature = (uint8_t) (rand() % (100 + 50 + 1)) - 50;
        step();
    }
}
