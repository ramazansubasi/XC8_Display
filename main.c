/*
 * File:   main.c
 * Author: subram
 * Created on December 29, 2013, 12:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONFIG2
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#define _XTAL_FREQ 4000000
const unsigned char segment[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
char i; // i adinda bir degisken ataniyor



void main(void){

    TRISB=0x00; // PORTB cikis yapiliyor
    PORTB=0x00; // PORTB sifirlaniyor

    for(;;){    // Program sonsuz donguye giriyor
        PORTB=segment[i]; // Display degerleri ayarlaniyor
        i=i+1; // i degiskeni "1" artiriliyor
        __delay_ms(500); // 500ms bekleniyor
        if(i>9) // Eger "i" degeri 9'dan buyukk ise 0'a dön
            i=0; // "i" degiskeni sifirlaniyor
        }
}