#include <Wire.h>
#include <AT24Cxx.h>

#include <GD23ZU.h>

#define i2c_address 0x50
AT24Cxx eep(i2c_address, 63);

int address = 0;
byte value;

char TXP[50];

void setup() {
  Wire.begin();

  GD.begin(GD_STORAGE);
  MP();
}
void loop(){}

void MP()
{
  while(1)
  {
    GD.ClearColorRGB(0x000040);
    GD.Clear();
    
    GD.ColorRGB(0xffffff);  GD.cmd_text((GD.w/2)-60, 0, 28, OPT_CENTERX, "AT24Cxx read");
    GD.ColorRGB(0xffffff);  GD.cmd_text((GD.w/2)+60, 8, 20, OPT_CENTERX, "Touch vector");

    sprintf(TXP,"Size of EEPROM: %d Kb", eep.length());  GD.cmd_text(0, 40, 26, 0, TXP);
    
    sprintf(TXP,"  registro %d = %d", 0, eep.read(0));   GD.cmd_text(0, 60+11*0, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 1, eep.read(1));   GD.cmd_text(0, 60+11*1, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 2, eep.read(2));   GD.cmd_text(0, 60+11*2, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 3, eep.read(3));   GD.cmd_text(0, 60+11*3, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 4, eep.read(4));   GD.cmd_text(0, 60+11*4, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 5, eep.read(5));   GD.cmd_text(0, 60+11*5, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 6, eep.read(6));   GD.cmd_text(0, 60+11*6, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 7, eep.read(7));   GD.cmd_text(0, 60+11*7, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 8, eep.read(8));   GD.cmd_text(0, 60+11*8, 20, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 9, eep.read(9));   GD.cmd_text(0, 60+11*9, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 10, eep.read(10));   GD.cmd_text(0, 60+11*10, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 11, eep.read(11));   GD.cmd_text(0, 60+11*11, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 12, eep.read(12));   GD.cmd_text(0, 60+11*12, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 13, eep.read(13));   GD.cmd_text(0, 60+11*13, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 14, eep.read(14));   GD.cmd_text(0, 60+11*14, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 15, eep.read(15));   GD.cmd_text(0, 60+11*15, 20, 0, TXP);
    
    sprintf(TXP,"registro %d = %d", 16, eep.read(16));   GD.cmd_text(0+100, 60+11*0, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 17, eep.read(17));   GD.cmd_text(0+100, 60+11*1, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 18, eep.read(18));   GD.cmd_text(0+100, 60+11*2, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 19, eep.read(19));   GD.cmd_text(0+100, 60+11*3, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 20, eep.read(20));   GD.cmd_text(0+100, 60+11*4, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 21, eep.read(21));   GD.cmd_text(0+100, 60+11*5, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 22, eep.read(22));   GD.cmd_text(0+100, 60+11*6, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 23, eep.read(23));   GD.cmd_text(0+100, 60+11*7, 20, 0, TXP);
    sprintf(TXP,"registro %d = %d", 24, eep.read(24));   GD.cmd_text(0+100, 60+11*8, 20, 0, TXP);
    //sprintf(TXP,"registro %d = %d", 25, eep.read(25));   GD.cmd_text(0+100, 60+11*9, 20, 0, TXP);    

    GD.swap();
  }
}
