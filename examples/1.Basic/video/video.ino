#include <GD23ZU.h>

void setup()
{
  GD.begin();
}
void loop()
{
  MoviePlayer mp;

  //mp.begin("MxB_NCS450.avi");
  //mp.begin("MxB_NCS799.avi");
  //mp.begin("oficial.avi");
  //mp.begin("JLo_Booty_IA799.avi");
  
  //mp.begin("Sunny500.avi");   //funciona en H743
  //mp.begin("A_Fme500.avi");  //funciona en H743
  //  mp.begin("AB_LAB500.avi");  //funciona en H743
  //mp.begin("AC_HtH500.avi");  //funciona en H743
  mp.begin("AS_GB500.avi");  //funciona en H743
   //mp.begin("ASI_WW500.avi");  //funciona en H743
  // mp.begin("AvB_JR500.avi");  //funciona en H743
    
  mp.play();
}
