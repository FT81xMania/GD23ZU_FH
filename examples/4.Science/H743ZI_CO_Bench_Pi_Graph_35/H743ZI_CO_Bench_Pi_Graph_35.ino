// BigNumber example: Calculate Pi using the Francois Viete formula
#include <GD23ZU.h>

#include <BigNumber.h>

int MCUID;
char TXPb[50];
int NIter=200;  //2000 Core7XXI@256MHz -- 93s
unsigned long Elapsed=0;

//Marco para graficar
int PX0=25, PY0=-5, PXMAX=300-PX0, PYMAX=PY0+230, PYBase= PY0+225;
int esp=9;

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
} 

void setup()
{
  BigNumber::begin (NIter);    // Length of the BigNumber. 50 is fast, 74 is slow.

  unsigned long start = micros();
    BigNumber pi = PiViete ();
  unsigned long finish = micros();
  Elapsed=((finish - start) / 1000U);
  
  GD.begin();
  //GD.begin(GD_STORAGE);
  IDEMCU();

  GD.Clear();
  GD.cmd_text(GD.w / 2, 50, 20, OPT_CENTER, "Calculate Pi using the Francois Viete formula");

  sprintf(TXPb,"Time elapsed:  %d ms x1000 ", Elapsed);  GD.cmd_text(GD.w / 2, 65, 20, OPT_CENTER, TXPb); 
  sprintf(TXPb,"No. of iterations:  %d ", NIter);  GD.cmd_text(GD.w / 2, 80, 20, OPT_CENTER, TXPb);

  Grafico();
  Parametros();
  GD.swap();
}
void loop(){}  //Nothing to do here!!!
