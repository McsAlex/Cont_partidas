/*
 * File:   disp7seg.c
 * Author: 19179453
 *
 * Created on 3 de Março de 2021, 16:27
 */


#include <xc.h>
#include "config.h"

char vetor[16] = {    0x3F, 0x06, 0x5B, 0x4F, 
                            0x66, 0x6D, 0x7D, 0x07, 
                            0x7F, 0x6F, 0x77, 0x7C, 
                            0x39, 0x5E, 0x79, 0x71  };

void disp7seg_init( void )
{
    ANSELH = 0;
    TRISB = 0x00;
    PORTB = 0x00;
}
void display7seg(int c)
{
    PORTB = vetor[c];
}
