
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 20000000

#define RS RC0
#define RW RC1
#define EN RC2
#define LCD PORTB

void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_init();

void lcd_cmd(unsigned char cmd)
{
    LCD = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(2);
    EN = 0;
}

void lcd_data(unsigned char data)
{
    LCD = data;
    RS = 1;
    RW = 0;
    EN = 1;
    __delay_ms(2);
    EN = 0;
}

void lcd_init()
{
    __delay_ms(20);
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
}

void main()
{
    TRISB = 0x00;
    TRISC0 = 0;
    TRISC1 = 0;
    TRISC2 = 0;
    
    lcd_init();
    lcd_data('A');

    SSPCON = 0x28;
    SSPADD = 0x19;

    SEN = 1;
    while(SSPIF == 0);
    SSPIF = 0;

    SSPBUF = 0xA0;
    while(SSPIF == 0);
    SSPIF = 0;

    SSPBUF = 0x00;
    while(SSPIF == 0);
    SSPIF = 0;

    SSPBUF = 0x00;
    while(SSPIF == 0);
    SSPIF = 0;

    SSPBUF = 'A';
    while(SSPIF == 0);
    SSPIF = 0;

    PEN = 1;
    while(SSPIF == 0);
    SSPIF = 0;

    while(1);
}

