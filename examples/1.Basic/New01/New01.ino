#include <GD23ZU.h>

void setup(){
  GD.begin();
  MP();
}
void loop(){}

void MP()
{
  while(1)
  {
   GD.ClearColorRGB(0x000055);
   GD.Clear();
   GD.get_inputs();
   GD.swap();
  }
}
