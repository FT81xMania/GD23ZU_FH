void MP()
{
  while(1)
  {
   GD.ClearColorRGB(0x000055);
   GD.Clear();
   GD.get_inputs();

   GD.Tag(1); GD.cmd_fgcolor(0x005000);  
    GD.cmd_button((GD.w/2)-80, (GD.h/2)-20, 60, 40, 28, 0,"M1");  
   GD.Tag(255);

   if (GD.inputs.tag==1)
   {
     M1();
   }

   GD.Tag(2); GD.cmd_fgcolor(0x500000);  
    GD.cmd_button((GD.w/2), (GD.h/2)-20, 60, 40, 28, 0,"M2");  
   GD.Tag(255);

   if (GD.inputs.tag==2)
   {
     M2();
   }   

   GD.swap();
  } 
}
