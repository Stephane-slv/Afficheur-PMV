#include <Arduino.h>
#define serialIn = 2
#define horloge = 3
#define validation = 4
#define verrou = 5

//byte car_a [6] = {0B00000000,0B01111110,0B00001001,0B00001001,0B00001001,0B01111110};
//byte barre_hor_1 [6] = {0B00000000,0B01010101,0B01010101,0B01010101,0B01010101,0B01010101};
//byte barre_hor_2 [6] = {0B00000000,0B10101010,0B10101010,0B10101010,0B10101010,0B10101010};

byte caracteres [4][6] = {
    {0B00000000,0B01111110,0B00001001,0B00001001,0B00001001,0B01111110},    // A
    {0B00000000,0B00111110,0B01001001,0B01001001,0B01001001,0B01111111},    // B
    {0B00000000,0B01010101,0B01010101,0B01010101,0B01010101,0B01010101},
    {0B00000000,0B10101010,0B10101010,0B10101010,0B10101010,0B10101010}
};

int data = 0;
int clk = 0;
int latch = 1;
int enable = 0;
byte valeur = 0;
int i  = 0;
void setup() {
Serial.begin(9600);  
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
digitalWrite(4,LOW);
digitalWrite(5,HIGH);
}

void loop(){
for (int k = 0; k <=3; k++)
{
    for ( i = 0; i <=5; i++ )
        {valeur = caracteres[k][i];
            for (int j = 7; j >= 0; --j ) 
            {data = (bitRead(valeur, j));
            digitalWrite (2,data);
            digitalWrite (3,HIGH);
            digitalWrite (3,LOW);
            }
        } 
digitalWrite(4,HIGH);
delay(1);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
delay(500);
}
}