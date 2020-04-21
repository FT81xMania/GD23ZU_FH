#include <GD23ZU.h>

static uint16_t value1, value2, value3, value4=65535 ;
static uint16_t options = OPT_FLAT;

int XPixeles = 100, DY= 100;

int LED1, LED2, LED3, LED4;

int apertura1,apertura2,apertura3,apertura4=128;

void setup()
{
  GD.begin();
}

#define TAG_TOGGLE1    202
#define TAG_TOGGLE2    203
#define TAG_TOGGLE3    204
#define TAG_TOGGLE4    205

void loop()
{
  GD.ClearColorRGB(0x150015);
  GD.Clear();
  GD.get_inputs();

//Control led 1  
  switch (GD.inputs.track_tag & 0xff) {
  case TAG_TOGGLE1:
    value1 = GD.inputs.track_val;
  }

  GD.Tag(TAG_TOGGLE1);
//  GD.cmd_toggle(280, 64, XPixeles, 29, options, value1,
//                "OFF" "\xff" "ON");
  GD.cmd_toggle(280, 64+DY*0, XPixeles, 29, options, value1,
                "  " "\xff" "  ");
  GD.cmd_track(280, 64+DY*0, XPixeles, 20, TAG_TOGGLE1);
  GD.Tag(255);
  
  //GD.cmd_number(200, 50+DY*0, 31, OPT_SIGNED|OPT_RIGHTX, value1);

  GD.cmd_text(450, 50+DY*0, 31, 0, "LED 1 = ");
  GD.cmd_number(650, 50+DY*0, 31, OPT_SIGNED|OPT_RIGHTX, LED1);

  if (value1>=65000){LED1 = 1;}
  if (value1<=0){LED1 = 0;}

  apertura1 =  100*value1/65535; 
  GD.cmd_number(200, 50+DY*0, 31, OPT_SIGNED|OPT_RIGHTX, apertura1);
//Control led 1    

//Control led 2
  switch (GD.inputs.track_tag & 0xff) {
  case TAG_TOGGLE2:
    value2 = GD.inputs.track_val;    
  }

  GD.Tag(TAG_TOGGLE2);
  GD.cmd_toggle(280, DY*1+64, XPixeles, 29, options, value2,
                //"OFF" "\xff" "ON");
                " " "\xff" " ");
  GD.cmd_track(280, DY*1+64, XPixeles, 20, TAG_TOGGLE2);
  GD.Tag(255);

  //GD.cmd_number(200, 50+DY*1, 31, OPT_SIGNED|OPT_RIGHTX, value2);

  GD.cmd_text(450, 50+DY*1, 31, 0, "LED 2 = ");
  GD.cmd_number(650, 50+DY*1, 31, OPT_SIGNED|OPT_RIGHTX, LED2);

  if (value2>=65000){LED2 = 1;}
  if (value2<=0){LED2 = 0;}

  apertura2 =  100*value2/65535; 
  GD.cmd_number(200, 50+DY*1, 31, OPT_SIGNED|OPT_RIGHTX, apertura2);  
//Control led 2

//Control led 3
  switch (GD.inputs.track_tag & 0xff) {
  case TAG_TOGGLE3:
    value3 = GD.inputs.track_val;    
  }

  GD.Tag(TAG_TOGGLE3);
  GD.cmd_toggle(280, DY*2+64, XPixeles, 29, options, value3,
                //"OFF" "\xff" "ON");
                " " "\xff" " ");
  GD.cmd_track(280, DY*2+64, XPixeles, 20, TAG_TOGGLE3);
  GD.Tag(255);

  //GD.cmd_number(200, 50+DY*2, 31, OPT_SIGNED|OPT_RIGHTX, value3);

  GD.cmd_text(450, 50+DY*2, 31, 0, "LED 3 = ");
  GD.cmd_number(650, 50+DY*2, 31, OPT_SIGNED|OPT_RIGHTX, LED3);

  if (value3>=65000){LED3 = 1;}
  if (value3<=0){LED3 = 0;}

  apertura3 =  100*value3/65535; 
  GD.cmd_number(200, 50+DY*2, 31, OPT_SIGNED|OPT_RIGHTX, apertura3);
//Control led 3

//Control led 4
  switch (GD.inputs.track_tag & 0xff) {
  case TAG_TOGGLE4:
    value4 = GD.inputs.track_val;    
  }

  GD.Tag(TAG_TOGGLE4);
  GD.cmd_toggle(280, DY*3+64, XPixeles, 29, options, value4,
                //"OFF" "\xff" "ON");
                " " "\xff" " ");
  GD.cmd_track(280, DY*3+64, XPixeles, 20, TAG_TOGGLE4);
  GD.Tag(255);

  //GD.cmd_number(200, 50+DY*3, 31, OPT_SIGNED|OPT_RIGHTX, value4);

  GD.cmd_text(450, 50+DY*3, 31, 0, "LED 4 = ");
  GD.cmd_number(650, 50+DY*3, 31, OPT_SIGNED|OPT_RIGHTX, LED4);

  if (value4>=65000){LED4 = 1;}
  if (value4<=0){LED4 = 0;}

  apertura4 =  128*value4/65535; 
  GD.cmd_number(200, 50+DY*3, 31, OPT_SIGNED|OPT_RIGHTX, apertura4);
  //GD.cmd_number(50, 55+DY*3, 28, OPT_SIGNED|OPT_RIGHTX, apertura4);
  
//Control led 4
  GD.wr(REG_PWM_DUTY,(apertura4));  

  GD.swap();
}
