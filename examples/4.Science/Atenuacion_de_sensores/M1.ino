void M1()
{
  while(1)    
  {
   GD.ClearColorRGB(0x000f00); 
   GD.Clear();
   GD.SaveContext();
    GD.ColorRGB(0xFFFFFF);
    GD.cmd_text(GD.w-15, 20, 26, OPT_CENTER, "M1");
    GD.get_inputs();
   
    GD.ColorA(35); GD.ColorRGB(0xffffff); GD.cmd_fgcolor(0x9025fa);
    GD.Tag(20);  GD.cmd_button(5, 20+70, 60, 60, 28, 0,  "MP");   GD.Tag(255);
   GD.RestoreContext();   

    if (GD.inputs.tag==20)
    {
        MP();    
    }    
   
   GD.swap(); 
  }
}
