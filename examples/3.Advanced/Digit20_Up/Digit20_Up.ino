//#include <GD23ZUTX.h>
#include <GD23ZU.h>

int MCUID;

void setup()
{
  GD.begin();
  IDEMCU();
}

void loop()
{
GD.Clear();
  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");

GD.Begin(LINES);
  GD.ColorRGB(255,255,255);
  GD.Vertex2f(0*16, 0*16);    GD.Vertex2f((GD.w)*16, 0*16);  //Superior
  GD.Vertex2f(0*16, (GD.h-1)*16);  GD.Vertex2f((GD.w)*16, (GD.h-1)*16); //inferior
  GD.Vertex2f(0*16, 0*16);  GD.Vertex2f(0*16, (GD.h-1)*16); //izquierda
  GD.Vertex2f((GD.w-1)*16, 0*16);  GD.Vertex2f((GD.w-1)*16, (GD.h-1)*16); //derecha  
  
Parametros();

digitos(GD.w/2-35,GD.h/2-25, 20);
digitos(-35,20, 20);
  
GD.swap();
} 

char Num0[20];
int N0=0, PYN0=0;

char Num0C[20];
int N0C=1, PYN0C=-11;

long previousMillis=0, refresco=50;

void digitos(int PX, int PY, int siseTX)
{
 sprintf(Num0, "%d ", N0);   sprintf(Num0C, "%d ", N0C); 
 
 unsigned long currentMillis = millis(); 
 if(currentMillis - previousMillis >= refresco)
 {
 previousMillis = currentMillis;
 //delay(100);

  PYN0=PYN0+1;   
  if(PYN0>=11){PYN0=-11; N0=N0+2; if(N0>=10){N0=0;}}

  PYN0C=PYN0C+1;
  if(PYN0C>=11){PYN0C=-11; N0C=N0C+2; if(N0C>=10){N0C=1;}}
 }
  GD.cmd_text(PX+45, PY-PYN0, siseTX, OPT_CENTER, Num0); 
  GD.cmd_text(PX+45, PY-PYN0C, siseTX, OPT_CENTER, Num0C);
  
  GD.ColorA(255);
  GD.cmd_fgcolor(0x000000);  GD.cmd_button(PX+38, PY-17, 10, 12, siseTX, OPT_FLAT, "");
  GD.cmd_fgcolor(0x000000);  GD.cmd_button(PX+38, PY+6, 10, 12, siseTX, OPT_FLAT, "");
  GD.ColorA(255);
}
