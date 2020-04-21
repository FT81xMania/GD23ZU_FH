static void plotfloat(int x, int y, float numero, int Ndec, int font)
{
 // int font = 30;


if (Ndec == 2){
    GD.cmd_number(x - 2, y, font, OPT_RIGHTX | OPT_SIGNED, int(numero));
    GD.cmd_text(  x,     y, font, 0, ".");
    GD.cmd_number(x + 8, y, font, 2, int(100 * abs(numero)));
  }

if (Ndec == 3){
    GD.cmd_number(x - 2, y, font, OPT_RIGHTX | OPT_SIGNED, int(numero));
    GD.cmd_text(  x,     y, font, 0, ".");
    GD.cmd_number(x + 8, y, font, 3, int(1000 * abs(numero)));
  }
  
if (Ndec == 4){
    GD.cmd_number(x - 2, y, font, OPT_RIGHTX | OPT_SIGNED, int(numero));
    GD.cmd_text(  x,     y, font, 0, ".");
    GD.cmd_number(x + 8, y, font, 4, int(10000 * abs(numero)));
  }  
}
