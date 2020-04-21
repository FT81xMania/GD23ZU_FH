char TXP[50];

void Parametros()
{
  GD.SaveContext();
  
  GD.ColorRGB(0x00ff00);

  GD.cmd_text(GD.w/2, (GD.h/2)-95, 31, OPT_CENTER, Board);
  sprintf(TXP,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(GD.w/2, (GD.h/2)-55, 31, OPT_CENTER, TXP);
  
  if(GD.model==815){
  sprintf(TXP,"EVE chip: BT%d ", GD.model);  GD.cmd_text(GD.w-85, (GD.h)-15, 20, 0, TXP);}else{
  sprintf(TXP,"EVE chip: FT%d ", GD.model);  GD.cmd_text(GD.w-85, (GD.h)-15, 20, 0, TXP);  
  }
      
  GD.RestoreContext();
}
