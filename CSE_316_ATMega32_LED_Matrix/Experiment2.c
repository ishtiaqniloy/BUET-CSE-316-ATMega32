//Experiment 2
#include <avr/io.h>      //IO header
#define F_CPU 1000000UL //defining crystal frequency
#include <util/delay.h>  //delay header

int main(void)
{

  MCUCSR |= (1<<JTD);
  MCUCSR |= (1<<JTD);

    //DDRD = 0xFF; //PORTD as output
    DDRA = 0xFF; //PORTA as output
    DDRC = 0xFF; //PORTC as output

char CHAR_ARR [26][8] = {
  {0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111}, //A
{0,0b00111100,0b01111110,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111}, //B
{0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100}, //C
{0,0b01111110,0b10111101,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111}, //D
{0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111}, //E
{0,0b11011000,0b11011000,0b11011000,0b11011000,0b11011000,0b11111111,0b11111111}, //F
{0b00011111,0b11011111,0b11011000,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111}, //G
{0,0b11111111,0b11111111,0b00011000,0b00011000,0b00011000,0b11111111,0b11111111}, //H
{0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011}, //I
{0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000011,0b11001111,0b11001111}, //J
{0,0b11000011,0b11100111,0b01111110,0b00111100,0b00011000,0b11111111,0b11111111}, //K
{0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111111}, //L
{0b11111111,0b11111111,0b01100000,0b01110000,0b01110000,0b01100000,0b11111111,0b11111111}, //M
{0b11111111,0b11111111,0b00011100,0b00111000,0b01110000,0b11100000,0b11111111,0b11111111}, //N
{0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110}, //O
{0,0b01110000,0b11111000,0b11001100,0b11001100,0b11001100,0b11111111,0b11111111}, //P
{0b01111110,0b11111111,0b11001111,0b11011111,0b11011011,0b11000011,0b11111111,0b01111110}, //Q
{0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111}, //R
{0b11001110,0b11011111,0b11011011,0b11011011,0b11011011,0b11011011,0b11111011,0b01110011}, //S
{0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000}, //T
{0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110}, //U
{0b11100000,0b11111100,0b00011110,0b00000011,0b00000011,0b00011110,0b11111100,0b11100000}, //V
{0b11111110,0b11111111,0b00000011,0b11111111,0b11111111,0b00000011,0b11111111,0b11111110}, //W
{0b01000010,0b11100111,0b01111110,0b00111100,0b00111100,0b01111110,0b11100111,0b01000010}, //X
{0b01000000,0b11100000,0b01110000,0b00111111,0b00111111,0b01110000,0b11100000,0b01000000}, //Y
{0b11000011,0b11100011,0b11110011,0b11111011,0b11011111,0b11001111,0b11000111,0b11000011}  //Z
};
    char PORT[16] = {1,2,4,8,16,32,64,128, 0, 0, 0, 0, 0, 0, 0, 0}; //pin values of a port 2^0,2^1,2^2……2^7
        uint8_t l =0;


        //PORTC=0x00;
        //PORTA=0xFF;
        //uint8_t bangla8[8] = { 0b00000011, 0b00000011, 0b11111111, 0b11111111, 0b00110011, 0b00110011, 0b00111111, 0b00111111};
        //uint8_t bangla8[8] = {0b00000011, 0b00000011, 0b11111111, 0b11111111, 0b00110011, 0b00110011, 0b00111111, 0b00111111};
        //uint8_t bangla8[8] = {0b00110000, 0b00110000, 0b00111111, 0b00111111, 0b00110011, 0b00110011, 0b11111111, 0b11111111};
        uint8_t bangla8[8] = {0b00010000, 0b00010000, 0b00010000, 0b00011111, 0b00010001, 0b00010001, 0b00010001, 0b11111111 };
        uint8_t bangla82[8] = {0b00010000, 0b00010000, 0b00010000, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b11111111 };

        uint8_t saved_vals[16];
        uint8_t saved_vals2[16];
        uint8_t upShift[8] = {0,0,0,0,0,0,0,0};

        int letter = 'L';
        for(int i=0; i<8; i++){  //bring data to saved_vals
          //saved_vals[i] = CHAR_ARR[letter-'A'][i];
          saved_vals[i] = bangla8[i];
          saved_vals2[i] = bangla82[i];

        }
        // for(int i=8; i<16; i++){ //extra values for clearing columns
        //   saved_vals[i] = 0;
        // }

    while(1)
    {
         // for(int i=0; i<8; i++){
         //   //_delay_ms(1);
         //   PORTC = PORT[i];     //clear pin
         // }
         for (int a = 0; a<100; a++){  //speed control
           for (int i=0;i<8;i++)
           {
               PORTC = ~PORT[i];    //ground the PORTC pin
                //_delay_ms(500);
                uint8_t val = saved_vals[i];
               PORTA = val; //power the PORTA
               _delay_ms(1);
               PORTC = PORT[i];     //clear pin after 1msec

              //  PORTC = PORT[i];     //clear pin after 1msec
           }
           //_delay_ms(1000);


       }


       for (int a = 0; a<100; a++){  //speed control
         for (int i=0;i<8;i++)
         {
             PORTC = ~PORT[i];    //ground the PORTC pin
              //_delay_ms(500);
              uint8_t val = saved_vals2[i];
             PORTA = val; //power the PORTA
             _delay_ms(1);
             PORTC = PORT[i];     //clear pin after 1msec

            //  PORTC = PORT[i];     //clear pin after 1msec
         }
         //_delay_ms(1000);


       }

       //right rotate
       // for(int i=0; i<16; i++){ //extra values for clearing columns
       //   saved_vals[(i+15)%16] = saved_vals[i%16];  //left to right rotate
       // }



       //down rotate
       for(int i=0; i<8; i++){ //extra values for clearing rows
        //int rightBit1 = upShift[i] & 1;
         //upShift[i] = upShift[i]>>1;

         int rightBit2 = saved_vals[i] & 1;
         saved_vals[i] = saved_vals[i]>>1 ;  //up down rotate

         //upShift[i] = upShift[i]|rightBit2<<7;
         saved_vals[i] = saved_vals[i]|rightBit2<<7;

         rightBit2 = saved_vals2[i] & 1;
         saved_vals2[i] = saved_vals2[i]>>1 ;  //up down rotate

         //upShift[i] = upShift[i]|rightBit2<<7;
         saved_vals2[i] = saved_vals2[i]|rightBit2<<7;


       }

       //flash
      /* for (int a = 0; a<100; a++){  //speed control
         for (int i=0;i<8;i++)
         {
             PORTC = ~PORT[i];    //ground the PORTC pin
              //_delay_ms(500);
              uint8_t val = 0;
             PORTA = val; //power the PORTA
             _delay_ms(1);
             PORTC = PORT[i];     //clear pin after 1msec
         }
         //_delay_ms(1000);
       }*/





      }
}
