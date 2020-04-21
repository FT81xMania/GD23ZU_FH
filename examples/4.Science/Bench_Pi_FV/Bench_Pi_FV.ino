// BigNumber example: Calculate Pi using the Francois Viete formula
// Install library from: https://github.com/nickgammon/BigNumber

#include <GD23ZU.h>
#include <BigNumber.h>

int MCUID;
char TXPb[50];
int NIter=200;  //2000 Core7XXI@256MHz -- 93s

//Nucleo F767
//int led0 = PB0;  //PB7(azul), PB0(verde), PB14(rojo)
//int led1 = PB7;
//int led2 = PB14;

//Core7XXI
//int led0 = PD3;  //Verde
//int led1 = PC0;  //Rojo
//int led2 = PD1;  //Azul

BigNumber PiViete ()
{
  // Francois Viete formula
  BigNumber two (2);       // used as a constant value of 2
  BigNumber s (0);         // used in iteration
  BigNumber t (1);         // used in iteration
 
  for (int i = 0; i < 115; i++) // number of iterations: 10 to 115
  {
    BigNumber r = s + two; // temporary value
    s = r.sqrt ();
    t *= s / two;
  }
  return two / t;          // calculate pi
} // end of function pi

void setup()
{
//  pinMode(led0, OUTPUT);   //Verde
//  pinMode(led1, OUTPUT);   //Rojo
//  pinMode(led2, OUTPUT);   //Azul

//  digitalWrite(led0, HIGH);  //HIGH -- apagado, LOW -- encendido
//  digitalWrite(led1, LOW);
//  digitalWrite(led2, HIGH);

  // Arduino Uno
  // -----------
  // The Arduino Uno has only 2k bytes of SRAM.
  // The maximum length of BigNumber is 74 for an Arduino Uno.
  // About 115 iterations in the Francois Viete formula is enough for an Arduino Uno.
  // That will take 34 seconds.
  //
  // Arduino Zero or Arduino MKR
  // ---------------------------
  // For an Arduino Zero, it is possible to set the length of BigNumber to a higher value.
  // For example, the length of BigNumber to 1000, and 1500 iterations.
  // That will take 8 hours.
  
    BigNumber::begin (NIter);    // Length of the BigNumber. 50 is fast, 74 is slow.

//  Serial.println (F("Please wait patiently (34 seconds with Arduino Uno)"));
//  Serial.println (F("pi (as text)       = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706"));

  unsigned long start = micros();
    BigNumber pi = PiViete ();
  unsigned long finish = micros();
  
//  digitalWrite(led0, LOW);  //HIGH -- apagado, LOW -- encendido
//  digitalWrite(led1, HIGH);

  GD.begin();
  IDEMCU();

GD.Clear();
  GD.cmd_text(GD.w / 2, 50, 30, OPT_CENTER, "Calculate Pi using the Francois Viete formula");

  //sprintf(TXPb,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(GD.w / 2, 100, 31, OPT_CENTER, TXPb);
  //if(GD.model==815){
  //sprintf(TXPb,"EVE model:  BT%d ", GD.model);  GD.cmd_text(GD.w / 2, 150, 31, OPT_CENTER, TXPb);}else{
  //sprintf(TXPb,"Model:  FT%d ", GD.model);  GD.cmd_text(GD.w / 2, (GD.h / 5) * 2, 31, OPT_CENTER, TXPb);  
 // }
  sprintf(TXPb,"Time elapsed:  %d microseconds ", ((finish - start) / 1000UL));  GD.cmd_text(GD.w / 2, (GD.h / 2)+50, 31, OPT_CENTER, TXPb);
  
  //sprintf(TXPb,"Pi:  %d", pi);  GD.cmd_text(GD.w / 2, (GD.h / 2)+100, 31, OPT_CENTER, TXPb);
  sprintf(TXPb,"No. of iterations:  %d ", NIter);  GD.cmd_text(GD.w / 2, (GD.h / 2)+95, 31, OPT_CENTER, TXPb);

  Parametros();
GD.swap();
} // end of setup
void loop(){}  //Nothing to do here!!!
