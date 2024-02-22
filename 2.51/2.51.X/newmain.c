#include <htc.h>

#define led1 RC0
#define led2 RC1
#define on 0
#define off 1

__CONFIG( FOSC_HS & WDTE_OFF &
PWRTE_OFF & CP_OFF & BOREN_ON &
LVP_OFF & CPD_OFF & WRT_OFF &
DEBUG_OFF);

const unsigned char seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void delay(int time) {
    while(time--);
}

void main() {
    TRISB = 0;
    TRISC0 = TRISC1 = 0;
    led1 = led2 = off;
    int i;
    while(1) {
        for (i = 50; i <= 70; i++) {
            led1 = on;
            led2 = off;
            PORTB = seg[i / 10];
            delay(1000);
            led1 = off;
            led2 = on;
            PORTB = seg[i % 10];
            delay(1000);
            led2 = off;
        }
    }
}
