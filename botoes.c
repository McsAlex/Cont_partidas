/*
 * File:   botoes.c
 * Author: 19179453
 *
 * Created on 3 de Março de 2021, 16:18
 */


#include <xc.h>

void botoes_init (void)
{
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD1 = 1;
}
char b1 (void)
{
    return (PORTDbits.RD1);
}
char b0 (void)
{
    return (PORTDbits.RD0);
}
