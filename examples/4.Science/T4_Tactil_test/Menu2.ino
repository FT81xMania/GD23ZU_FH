void M2()
{
  while(1)
  {
   GD.ClearColorRGB(0x500000);
   GD.Clear();
   GD.get_inputs();

   GD.Tag(6); GD.cmd_fgcolor(0x005000);  
    GD.cmd_button((GD.w/2)-80, (GD.h/2)-80, 60, 40, 28, 0,"M1");  
   GD.Tag(255);

   if (GD.inputs.tag==6)
   {
     M1();
   }

   GD.Tag(5); GD.cmd_fgcolor(0x000050);  
    GD.cmd_button((GD.w/2), (GD.h/2)+50, 60, 40, 28, 0,"MP");  
   GD.Tag(255);

   if (GD.inputs.tag==5)
   {
     MP();
   }

   GD.swap();
  } 
}
