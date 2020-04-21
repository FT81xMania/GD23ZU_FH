#include <GD23ZU.h>

const char song[7][15] = {"diff.ima","made.ima","Beautifu.ima","mesmeriz.ima"};
int IDAudio=0;

static void Player()
{
  Streamer stream;
  stream.begin(song[IDAudio]);
  byte playing = 1;

  while(1)
  {
   GD.ClearColorRGB(0x100000);
   GD.Clear();
    GD.get_inputs();

    GD.SaveContext();
    GD.cmd_text(GD.w/2, 20, 29, OPT_CENTER, song[IDAudio]);
    GD.Tag(100); GD.cmd_fgcolor(0x005000);  GD.cmd_button((GD.w/2)-(100/2), (GD.h/2)+(60/2), 100, 60, 28, 0,"Next");  GD.Tag(255);
    GD.Tag(101); GD.cmd_fgcolor(0x000050);  GD.cmd_button(5, (GD.h/2)+(60/2), 100, 60, 28, 0,"MP");  GD.Tag(255);
    GD.RestoreContext();

   uint16_t val, range;
   stream.progress(val, range);
   GD.SaveContext();
    GD.ColorRGB(0x00ff00); GD.cmd_fgcolor(0x000000); GD.cmd_bgcolor(0xff0000); GD.cmd_slider(GD.w/4, 60, GD.w/2, 8, 0, val, range);
   GD.RestoreContext();
   GD.cmd_number(GD.w/2, GD.h/3, 27, OPT_CENTERX|OPT_RIGHTX|OPT_SIGNED, val);
   GD.cmd_number(GD.w/2, GD.h/2, 27, OPT_CENTERX|OPT_RIGHTX|OPT_SIGNED, range);

   if(val>=range)
     {
      IDAudio =IDAudio +1; 
       if(IDAudio>=4){IDAudio=0;}
      Player();
     }
    
    if (GD.inputs.tag == 100)
      {
       delay(170);
       IDAudio =IDAudio +1; 
       if(IDAudio>=4){IDAudio=0;}
       Player();
      }

     if (GD.inputs.tag == 101)
      {
        MP();
      }
    PieTX();
    GD.swap();
        
    if (!stream.feed()) 
    {
      playing = 0;
      GD.sample(0, 0, 0, 0);
    }
  }
}

void setup()
{
  GD.begin();
  //GD.cmd_setrotate(0);
  MP();
  //Player();
}
void loop(){}

void MP()
{
  GD.sample(0, 0, 0, 0);
  while(1)
  {
   GD.ClearColorRGB(0x001050);
   GD.Clear();
    GD.get_inputs();

    GD.SaveContext();
    GD.Tag(102); GD.cmd_fgcolor(0x500000);  GD.cmd_button((GD.w/2), (GD.h/2)-(60/2), 140, 60, 28, 0,"IMA Player");  GD.Tag(255);
    GD.RestoreContext();

    if (GD.inputs.tag == 102)
      {
        Player();
      }
    PieTX();
    GD.swap();
  }
}
