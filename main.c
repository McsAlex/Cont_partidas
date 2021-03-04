/*
 * File:   main.c
 * Author: 19179453
 *
 * Created on 3 de Mar�o de 2021, 16:10
 */


#include <xc.h>
#include "config.h"
#include "botoes.h"
#include "contatores.h"
#include "disp7seg.h"
#include "delay.h"

void main(void) 
{
    int cont = 0;
    int estado = 0;
    int t;
    
    while ( 1 )
    {    
        switch ( estado )
        {
            case 0:
                    estado = 1;
                    break;
            case 1:
                    contatores_init();
                    botoes_init();
                    disp7seg_init();
                    estado = 2;
                    break;
            case 2:
                    if ( b1() == 1 && K1status() == 0 )
                        estado = 3;
                    break;
            case 3:
                    K1(1);
                    K2(1);
                    K3(0);
                    estado = 4;
                    break;
            case 4:
                    t = 3000;
                    estado = 6;
                    break;
            case 6:
                    delay (1);
                    --t;
                    if (t <= 0 )
                        estado = 7;
                    if( b0() == 1 )
                        estado = 9;
                    break;
            case 7:
                    ++cont;
                    estado = 8;
                    break;
            case 8:
                    K1(1);
                    K2(0);
                    K3(1);
                    if( b0() == 1 )
                        estado = 9;
                    break;
            case 9:
                    K1(0);
                    K2(0);
                    K3(0);
                    estado = 2;
                    break;
        }      
        display7seg(cont);
        
        if ( cont >= 10)
            cont = 0;

    }    
}