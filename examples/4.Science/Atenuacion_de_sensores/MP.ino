float Lect, Lect1, Lect2, DeltaL, VelL, LectA;
char LectTXT[40];

void MP()
{
  while(1)    
  {
   GD.ClearColorRGB(0x00000f); 
   GD.Clear();
   GD.get_inputs();
       
   GD.SaveContext();
    GD.ColorRGB(0xFFFFFF);
    GD.cmd_text(GD.w-35, 20, 26, OPT_CENTER, "MP");
    GD.ColorA(35); GD.ColorRGB(0xffffff); GD.cmd_fgcolor(0x9025fa);
    GD.Tag(19);  GD.cmd_button(5, 20, 60, 60, 28, 0,  "M1");   GD.Tag(255);
   GD.RestoreContext();       

    Sensor1();

   GD.SaveContext();
    sprintf(LectTXT,"Sensor1= %g",Lect);  GD.cmd_text(GD.w/2, (GD.h/2), 28, OPT_CENTER, LectTXT);  GD.printNfloat((GD.w/2)+80, (GD.h/2)-15, Lect, 2, 28);
   GD.RestoreContext();

    if (GD.inputs.tag==19)
    {
        M1();    
    }    
   
   GD.swap(); 
  }
}

long previousMillis=0, updateMillis=1000;
void Sensor1()
{
  unsigned long currentMillis = millis(); 
  if(currentMillis - previousMillis > updateMillis)
  {
    previousMillis = currentMillis; 
    Lect=random(0,100);

    Lect2= Lect;
    DeltaL=Lect2-Lect1;
    if(DeltaL>0){VelL=1;}else{if(DeltaL<0){VelL=-1;}else{VelL=0;}}
  }

   if(LectA==Lect2){LectA=Lect2;}else{LectA = LectA + VelL;}

   GD.cmd_gauge(50, 180, 40, 0, 4, 7, LectA, 100);
   GD.cmd_gauge(GD.w-50, 180, 40, 0, 4, 7, Lect, 100);
   Lect1= LectA;
}
