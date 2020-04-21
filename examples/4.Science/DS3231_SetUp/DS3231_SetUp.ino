//#include "Wire.h"
#include <GD23ZU.h>

//DS3231
//#define DS3231Pin        24  //VCC del breakout DS3231
#define DS3231_I2C_ADDRESS 0x68
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year; 
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val){return( (val/10*16) + (val%10) );}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val){return( (val/16*10) + (val%16) );}

#define SliderHora  204
#define SliderMin  205
#define SliderSeg  206

int AjusteReloj;
int Rseg, Rmin, Rhora, DS, ND, NDmax=30, Mh, Yr;  
char HoraTX[20], HoraTXS[20], FechaTXS[20];
//DS3231

void setup() {
  Wire.begin();
  //pinMode(DS3231Pin, OUTPUT); 
  //digitalWrite(DS3231Pin,HIGH);
  
  //Serial.begin(115200);
  GD.begin();
  RelojDS3231();
}

void loop(){}

void RelojDS3231(){
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year);
  Rseg=second; Rmin=minute; Rhora=hour; 
  DS=dayOfWeek; ND=dayOfMonth; Mh=month; Yr=year;  
  
while(1)
 {
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year);
  GD.ClearColorRGB(0x103000);
  GD.Clear();
  GD.get_inputs();  

  //Draw clock
  GD.cmd_clock(50,50,50,OPT_FLAT,hour,minute,second,0);
  sprintf(HoraTX, "%02d:%02d:%02d", hour, minute, second);
  GD.ColorRGB(0xffffff);   GD.cmd_text(50, 115, 18, OPT_CENTER, HoraTX);

GD.cmd_fgcolor(0x0000FF);
//Toma captura de los datos del DS3231
  GD.Tag(217);    GD.cmd_button(120, 40, 60, 30, 18, 0,  "Datos");        GD.Tag(255);  
   if (GD.inputs.tag==217){
        delay(145);
        Rseg=second; Rmin=minute; Rhora=hour; 
        DS=dayOfWeek; ND=dayOfMonth; Mh=month; Yr=year; 
      }

  if(AjusteReloj==1){SetupReloj();}


  GD.Tag(207);    GD.cmd_button(120, 5, 60, 30, 18, 0,  "Config");        GD.Tag(255);  
   if (GD.inputs.tag==207){
        delay(145);
        AjusteReloj=AjusteReloj+1;
        if(AjusteReloj>=2){AjusteReloj=0;}
      }
      
  GD.swap();
 }
}
