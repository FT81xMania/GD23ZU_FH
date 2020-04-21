void SetupReloj()
{
//Draw clock
  GD.cmd_clock(250,50,50,OPT_FLAT, Rhora, Rmin, Rseg,0);
  sprintf(HoraTXS, "%02d:%02d:%02d", Rhora, Rmin, Rseg);
  GD.ColorRGB(0xffffff);   GD.cmd_text(252, 100, 20, OPT_CENTER, HoraTXS);

//dayOfWeek, dayOfMonth, month, year;
  sprintf(FechaTXS, "%02d-%02d-20%02d", ND, Mh, Yr);
  GD.ColorRGB(0xffffff);   GD.cmd_text(250, 110, 20, OPT_CENTER, FechaTXS);
  
//Año, base 2017
  sprintf(FechaTXS, "%02d", Yr);
  GD.Tag(209);    GD.cmd_button(215, 125, 50, 20, 28, 0,  FechaTXS);  GD.Tag(255);  
  if (GD.inputs.tag==209){
       delay(145);
       Yr=Yr+1;  
      }

  GD.Tag(210);    GD.cmd_button(270, 125, 50, 20, 28, 0,  "A");       GD.Tag(255);  
  if (GD.inputs.tag==210){
       delay(145);
       Yr=17;  
      }

//Mes, base 04
  sprintf(FechaTXS, "%02d", Mh);
  GD.Tag(211);    GD.cmd_button(215, 155, 50, 20, 28, 0,  FechaTXS);  GD.Tag(255);  
  if (GD.inputs.tag==211){
       delay(145);
       Mh=Mh+1;
       
       if(Mh>=13){Mh=1;}
       if(Mh==1){NDmax=31;}
       if(Mh==2){
          NDmax=28;
           if(Yr==20){NDmax=29;}
           if(Yr==24){NDmax=29;}
           if(Yr==28){NDmax=29;}
           if(Yr==32){NDmax=29;}
           if(Yr==36){NDmax=29;}
           if(Yr==40){NDmax=29;}
         }
       if(Mh==3){NDmax=30;}
       if(Mh==4){NDmax=30;}
       if(Mh==5){NDmax=31;}
       if(Mh==6){NDmax=30;}
       if(Mh==7){NDmax=31;}
       if(Mh==8){NDmax=31;}
       if(Mh==9){NDmax=30;}
       if(Mh==10){NDmax=31;}
       if(Mh==11){NDmax=30;}
       if(Mh==12){NDmax=31;}
      }

  GD.Tag(212);    GD.cmd_button(270, 155, 50, 20, 28, 0,  "M");       GD.Tag(255);  
  if (GD.inputs.tag==212){
       delay(145);
       Mh=4;  
      }


//Día del mes, base 01
  sprintf(FechaTXS, "%02d", ND);
  GD.Tag(213);    GD.cmd_button(215, 185, 50, 20, 28, 0,  FechaTXS);  GD.Tag(255);  
  if (GD.inputs.tag==213){
       delay(145);
       ND=ND+1;
       //if(ND>=32){ND=0;}
       if(ND>=NDmax+1){ND=1;}
      }

  GD.Tag(214);    GD.cmd_button(270, 185, 50, 20, 28, 0,  "ND");       GD.Tag(255);  
  if (GD.inputs.tag==214){
       delay(145);
       ND=1;  
      }

//Día de la semana, base 07
  sprintf(FechaTXS, "%02d", DS);
  
  GD.Tag(215);    GD.cmd_button(215, 215, 50, 20, 28, 0,  FechaTXS);  GD.Tag(255);  
  if (GD.inputs.tag==215){
       delay(145);
       DS=DS+1;
       if(DS>=8){DS=1;}
      }

  GD.Tag(216);    GD.cmd_button(270, 215, 50, 20, 28, 0,  "DS");       GD.Tag(255);  
  if (GD.inputs.tag==216){
       delay(145);
       DS=7; 
      }
  if (DS==1){GD.ColorRGB(0xffffff);   GD.cmd_text(147, 125, 18, OPT_CENTER, "DOMINGO");}  
  if (DS==2){GD.ColorRGB(0xffffff);   GD.cmd_text(147, 125, 18, OPT_CENTER, "LUNES");}
  if (DS==3){GD.ColorRGB(0xffffff);   GD.cmd_text(147, 125, 18, OPT_CENTER, "MARTES");}
  if (DS==4){GD.ColorRGB(0xffffff);   GD.cmd_text(147, 125, 18, OPT_CENTER, "MIERCOLES");}
  if (DS==5){GD.ColorRGB(0xffffff);   GD.cmd_text(147, 125, 18, OPT_CENTER, "JUEVES");}
  if (DS==6){GD.ColorRGB(0xffffff);   GD.cmd_text(147, 125, 18, OPT_CENTER, "VIERNES");}
  if (DS==7){GD.ColorRGB(0xffffff);   GD.cmd_text(147, 125, 18, OPT_CENTER, "SABADO");}
  
  if (Rhora==24){Rhora=0;}

  GD.ColorRGB(0xffffff);   GD.cmd_number(205, 135, 26, OPT_RIGHTX | OPT_SIGNED, Rhora);
//Draw Slider Hora
  GD.Tag(SliderHora);
  GD.cmd_fgcolor(0xFF0000);
  GD.cmd_slider(10,140,170,10,OPT_FLAT,Rhora,24);
  //            x,   y,  largo, espesor, tag a seguir 
  GD.cmd_track( 10,140,170,10,SliderHora);
  switch (GD.inputs.track_tag & 0xff) {
  case SliderHora:
    Rhora = GD.inputs.track_val * 24L / 65535;
    //Serial.println(Rhora);
    break;
   }

  if (Rmin==60){Rmin=0;}

  GD.ColorRGB(0xffffff);   GD.cmd_number(205, 135+28, 26, OPT_RIGHTX | OPT_SIGNED, Rmin);
//Draw Slider Minuto
  GD.Tag(SliderMin);
  GD.cmd_fgcolor(0xFF0000);
  GD.cmd_slider(10,140+25,170,10,OPT_FLAT,Rmin,60);
  //            x,   y,  largo, espesor, tag a seguir 
  GD.cmd_track( 10,140+25,170,10,SliderMin);
  switch (GD.inputs.track_tag & 0xff) {
  case SliderMin:
    Rmin = GD.inputs.track_val * 60L / 65535;
    //Serial.println(Rmin);
    break;
   } 


  if (Rseg==60){Rseg=0;}

  GD.ColorRGB(0xffffff);   GD.cmd_number(205, 135+28*2, 26, OPT_RIGHTX | OPT_SIGNED, Rseg);
//Draw Slider Minuto
  GD.Tag(SliderSeg);
  GD.cmd_fgcolor(0xFF0000);
  GD.cmd_slider(10,140+25*2,170,10,OPT_FLAT,Rseg,60);
  //            x,   y,  largo, espesor, tag a seguir 
  GD.cmd_track( 10,140+25*2,170,10,SliderSeg);
  switch (GD.inputs.track_tag & 0xff) {
  case SliderSeg:
    Rseg = GD.inputs.track_val * 60L / 65535;
    //Serial.println(Rseg);
    break;
   }
   
//Setup del Reloj

GD.Tag(208);    GD.cmd_button(120, 80, 60, 30, 18, 0,  "Setup");        GD.Tag(255);  

if (GD.inputs.tag==208){
        delay(145);
          // DS3231   seconds, minutes, hours, day, date, month, year
          setDS3231time(Rseg,    Rmin,  Rhora,  DS,  ND,    Mh,   Yr);
        AjusteReloj=AjusteReloj+1;
      }
  GD.cmd_fgcolor(0x00FF00);
}
