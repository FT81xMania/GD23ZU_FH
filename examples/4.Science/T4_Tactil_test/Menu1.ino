void M1()
{
  while(1)
  {
   GD.ClearColorRGB(0x003500);
   GD.Clear();
   GD.get_inputs();

   GD.Tag(3); GD.cmd_fgcolor(0x500000);  
    GD.cmd_button((GD.w/2), (GD.h/2)-80, 60, 40, 28, 0,"M2");  
   GD.Tag(255);

   if (GD.inputs.tag==3)
   {
     M2();
   }

   GD.Tag(4); GD.cmd_fgcolor(0x000050);  
    GD.cmd_button((GD.w/2), (GD.h/2)+50, 60, 40, 28, 0,"MP");  
   GD.Tag(255);

   if (GD.inputs.tag==4)
   {
     MP();
   }

   GD.swap();
  } 
}
