
#include "grbl.h"
#include "output.h"


void output_init(){
    OUTPUT_DDR  |= ((1<<OUTPUT1_BIT)|(1<<OUTPUT2_BIT)); // Initialize out1 and out2 
    OUTPUT_PORT ^= ((OUTPUT_PORT&(1<<OUTPUT1_BIT))<<OUTPUT1_BIT) | ((OUTPUT_PORT&(1<<OUTPUT2_BIT))<<OUTPUT2_BIT); // set out1 and out2 to 0
}

void output_write(uint8_t output_bit, uint8_t value){
    OUTPUT_PORT ^= (OUTPUT_PORT&(1<<output_bit))^(value<<output_bit);
}