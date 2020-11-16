/*******************************************************
This program was created by the
CodeWizardAVR V2.60 Evaluation
Automatic Program Generator
© Copyright 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 04/11/2019
Author  : 
Company : 
Comments: 


Chip type               : ATmega8535
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 128
*******************************************************/

#include <mega8535.h>
#include <delay.h>
#define boton_Adelante PINB.0
#define boton_Atras PINB.1
#define boton_Derecha PINB.2
#define boton_Izquierda PINB.3
#define boton_Start PINB.4
#define boton_Pause PINB.5
#define boton_Clear PINB.6
unsigned char cuenta = 0;
unsigned char Inicio = 0, Clear=0, Pausa=0, i=0, j=0;
unsigned char secuencia [10]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
bit botona_Adelante, botona_Atras, botona_Derecha, botona_Izquierda, botona_Start, botona_Pause, botona_Clear;
bit botonp_Adelante, botonp_Atras, botonp_Derecha, botonp_Izquierda, botonp_Start, botonp_Pause, botonp_Clear;

void main(void){
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=P Bit2=P Bit1=P Bit0=P 
PORTB=(1<<PORTB7) | (1<<PORTB6) | (1<<PORTB5) | (1<<PORTB4) | (1<<PORTB3) | (1<<PORTB2) | (1<<PORTB1) | (1<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<WGM20) | (0<<COM21) | (0<<COM20) | (0<<WGM21) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

while (1){
    if(Inicio == 0 ){
    
      //****************** Presionar el boton Adelante --> 0x01
        if (boton_Adelante==0)
            botona_Adelante=0;
        else
            botona_Adelante=1;
        if ((botona_Adelante==0)&&(botonp_Adelante==1)){
            secuencia[cuenta]= 0x01;  
            cuenta++;
            delay_ms(40);
        }
        if ((botona_Adelante==1)&&(botonp_Adelante==0))
            delay_ms(40);
        botonp_Adelante = botona_Adelante;

        //****************** Presionar el boton Atras --> 0x02
        if (boton_Atras==0)
            botona_Atras=0;
        else
            botona_Atras=1;
        if ((botona_Atras==0)&&(botonp_Atras==1)){
            secuencia[cuenta]= 0x02;  
            cuenta++;
            delay_ms(40);
        }
        if ((botona_Atras==1)&&(botonp_Atras==0))
            delay_ms(40);
        botonp_Atras = botona_Atras;

        //****************** Presionar el boton Derecha --> 0x03
        if (boton_Derecha==0)
            botona_Derecha=0;
        else
            botona_Derecha=1;
        if ((botona_Derecha==0)&&(botonp_Derecha==1)){
            secuencia[cuenta]= 0x03;   
            cuenta++;
            delay_ms(40);
        } 
        if ((botona_Derecha==1)&&(botonp_Derecha==0))
            delay_ms(40);
        botonp_Derecha = botona_Derecha;

      //********************* Presionar el boton Izquierda --> 0x04
        if (boton_Izquierda==0)
            botona_Izquierda=0;
        else
            botona_Izquierda=1;
        if ((botona_Izquierda==0)&&(botonp_Izquierda==1)){
            secuencia[cuenta]= 0x04;   
            cuenta++;
            delay_ms(40);
        }
        if ((botona_Izquierda==1)&&(botonp_Izquierda==0))
            delay_ms(40);
        botonp_Izquierda = botona_Izquierda;
              
        //****************** Control del contador *********
        if (cuenta == 10){
            cuenta = 0;
        }

        //***************** Presionar el boton Start 
        if (boton_Start == 0)
            botona_Start=0;
        else
            botona_Start=1;
        if ( (botonp_Start==1) && (botona_Start==0) ){
            Inicio = 1;
            delay_ms(40);
        }
        if ( (botonp_Start==0) && (botona_Start==1) )
            delay_ms(40);
        botonp_Start = botona_Start;
    }
    else {       
        //Activar motor Adelante
        if(secuencia[i] == 0x01){
            PORTD.0 = 1; 
            PORTD.1 = 1;
            PORTD.2 = 0; 
            PORTD.3 = 0; 
            i++;    
            delay_ms(500);
        }

        //Activar motor Atras
        else if(secuencia[i] == 0x02){
            PORTD.0 = 0; 
            PORTD.1 = 0;
            PORTD.2 = 1; 
            PORTD.3 = 1;
            i++;     
            delay_ms(1000);
        }

        //Activar motor Derecha
        else if(secuencia[i] == 0x03){
            PORTD.0 = 1; 
            PORTD.1 = 0;
            PORTD.2 = 0; 
            PORTD.3 = 1;
            i++;     
            delay_ms(1000);
        }

        //Activar motor Izquierda
        else if(secuencia[i] == 0x04){
            PORTD.0 = 0; 
            PORTD.1 = 1;
            PORTD.2 = 1; 
            PORTD.3 = 0;
            i++;     
            delay_ms(1000);
        }

        else {
            PORTD.0 = 0; 
            PORTD.1 = 0;
            PORTD.2 = 0; 
            PORTD.3 = 0;
            i++;     
            delay_ms(1000);
        }
        
        //Control del contador        
        if( i == 10 ){
            i = 0;
            Inicio = 0;
        }

        // Presionar el boton Pausa 
        if (boton_Pause==0)
            botona_Pause=0;
        else
            botona_Pause=1;

        if ((botona_Pause==0)&&(botonp_Pause==1)){
            Pausa = 1;
            delay_ms(40);
        }
        if ((botona_Pause==1)&&(botonp_Pause==0))
            delay_ms(40);
            
        botonp_Pause = botona_Pause;

        if(Pausa == 1){
            Inicio = 0;
            Pausa = 0;
        }
    }

    // Presionar el boton Clear 
    if (boton_Clear==0)
        botona_Clear=0;
    else
        botona_Clear=1;

    if ((botona_Clear==0)&&(botonp_Clear==1)){
        Clear= 1;
        delay_ms(40);
    }
    if ((botona_Clear==1)&&(botonp_Clear==0))
        delay_ms(40);
    botonp_Clear = botona_Clear;
    
    if(Clear == 1){
        for( j = 0; j<10; j++){
            secuencia [j]=0x00;
        }
        cuenta=0;
        i = 0;
        Clear = 0;  
        Inicio = 0;
    }
}
}
