char TXP[50];
void PieTX()
{
  GD.SaveContext();
  GD.ColorRGB(0x00ff00); sprintf(TXP,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(GD.w - 105, 0, 26, 0, TXP);
  GD.cmd_text(GD.w/2, 0, 26, 0, Board);

  
  if(GD.model==815){
  sprintf(TXP,"EVE chip: BT%d ", GD.model);  GD.cmd_text(GD.w/2, (GD.h)-18, 28, OPT_CENTER, TXP);}else{
  sprintf(TXP,"EVE chip: FT%d ", GD.model);  GD.cmd_text(GD.w/2, (GD.h)-18, 28, OPT_CENTER, TXP);  
  }

  if(SizeFT813==35){GD.cmd_text(GD.w/2, (GD.h)-40, 28, OPT_CENTER, "EVE chip: FT813@NHD-3.5-320240FT-CSXN-CTP");}
  if(SizeFT813==43){GD.cmd_text(GD.w/2, (GD.h)-40, 28, OPT_CENTER, "EVE chip: FT813@NHD-4.3-480272FT-CSXN-CTP");}
  if(SizeFT813==5){GD.cmd_text(GD.w/2, (GD.h)-40, 28, OPT_CENTER, "EVE chip: FT813@NHD-5.0-800480FT-CTXL-CTP");}
  if(SizeFT813==7){GD.cmd_text(GD.w/2, (GD.h)-40, 28, OPT_CENTER, "EVE chip: FT813@NHD-7.0-800480FT-CSXN-CTP");}
  if(SizeFT813==51){GD.cmd_text(GD.w/2, (GD.h)-40, 28, OPT_CENTER, "EVE chip: FT813@Riverdi RVT50UQFNWC000");}
  if(SizeFT813==71){GD.cmd_text(GD.w/2, (GD.h)-40, 28, OPT_CENTER, "EVE chip: FT813@Riverdi RVT70UQFNWC000");}
  if(SizeFT813==52){GD.cmd_text(GD.w/2, (GD.h)-40, 28, OPT_CENTER, "EVE chip: BT815@Matrix Orbital EVE3-50G");}  
  
  GD.ColorRGB(0x444444); GD.cmd_text((GD.w-40), (GD.h)-10, 20, OPT_CENTER, "FT81xmania Team");
  GD.RestoreContext();
}
