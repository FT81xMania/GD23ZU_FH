char TXP[50];

void Parametros()
{
  GD.SaveContext();
   GD.ColorRGB(0x555555);
    GD.cmd_text(0, (GD.h)-30, 26, 0, Board);
    sprintf(TXP,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(0, (GD.h)-15, 26, 0, TXP);
  GD.RestoreContext();
}
