#include <htc.h>

#define B1 RD0
#define B2 RD1
#define C1 RC0
#define C2 RC1

const unsigned char led7[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x92, 0xf8, 0x80, 0x90};

void delay(int t) {
    int i;
    for (i=0; i<t; i++);
}

void display (int i) {
    int c, dv;
    int j;
    c = (i/10)%10;
    dv = i%10;
    for (j=0; j<10; j++) {
        PORTB = led7[c];
        C1 = 1;
        delay(100);
        C1 = 0;
        PORTB = led7[dv];
        C2 = 1;
        delay(100);
        C2 = 0;
    }
}

void main (void) {
    TRISB = TRISC = 0;
    TRISD0 = 1;
    TRISD1 = 1;
    int i = 0;
    while(1) {
        if(B1 == 0) {
            if(i == 99)
                i=0;
            i++;
            display(i);
        }
        else {
            display(i);
        }
        if(B2 == 0) {
            if(i == 0)
                i = 99;
            i--;
            display(i);
        }
        else {
            display(i);
        }
    }
}