void MP(){
int ActivaCortina=0, DespXMP=(GD.w/2)-(480/2);  
 
int SaliraMP, DespX=-350;      
int VelDespX=0;
int movx, velocidadx;

CargaJPG();
  
  while(1)
  {
   GD.ClearColorRGB(0x000055);
   GD.Clear();
   GD.get_inputs();

   GD.SaveContext();
     GD.Begin(BITMAPS);
     GD.Vertex2f(DespXMP*16, ((GD.h/2)-(272/2))*16);
    if(ActivaCortina==1){VelDespX=10; DespXMP=DespXMP-VelDespX; if(DespXMP<=-480){VelDespX=0; DespXMP=-480;}}
    if(ActivaCortina==2){VelDespX=10; DespXMP=DespXMP+VelDespX; if(DespXMP>=(GD.w/2)-(480/2)){VelDespX=0; DespXMP=(GD.w/2)-(480/2);}}
   GD.RestoreContext();

   GD.Tag(1); GD.cmd_fgcolor(0x005000);  
    GD.ColorA(150);   GD.cmd_button((GD.w/2)+30, (GD.h/2)-60, 120, 150, 31, 0,"Test");    GD.ColorA(255);
   GD.Tag(255);

   if (GD.inputs.tag==1)
   {
    delay(125);
     ActivaCortina=ActivaCortina+1;
     if(ActivaCortina>=3){ActivaCortina=1;}
   }

   GD.cmd_number(100, 375, 28, OPT_SIGNED|OPT_RIGHTX, DespXMP);
   GD.cmd_number(100, 375+35, 28, OPT_SIGNED|OPT_RIGHTX, ActivaCortina);
   GD.swap();
  }   
}
