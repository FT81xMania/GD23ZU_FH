#include <Wire.h>
#include <AT24Cxx.h>

#include <GD23ZU.h>

#define i2c_address 0x50
AT24Cxx eep(i2c_address, 63);

int address = 0;
byte value=0;  //first component of the touch vector to zero

char TXP[50];

void setup() {
    Wire.begin();
    eep.update(address, value);

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
    
    GD.ColorRGB(0xffffff);  GD.cmd_text((GD.w/2)-60, 0, 28, OPT_CENTERX, "AT24Cxx write/read");
    GD.ColorRGB(0xffffff);  GD.cmd_text((GD.w/2)+80, 8, 20, OPT_CENTERX, "Touch vector");

    sprintf(TXP,"Size of EEPROM: %d Kb", eep.length());  GD.cmd_text(0, 40, 26, 0, TXP);
    sprintf(TXP,"  registro %d = %d", 0, eep.read(0));   GD.cmd_text(0, 60+11*0, 20, 0, TXP);    

    GD.swap();
  }
}
