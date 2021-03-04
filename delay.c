/*
 * File:   delay.c
 * Author: 19179453
 *
 * Created on 3 de Março de 2021, 16:30
 */


#include <xc.h>
#include "config.h"

void delay (unsigned int t)

{
    while (t)
    {
        --t;
        __delay_ms(1);
    }
}
