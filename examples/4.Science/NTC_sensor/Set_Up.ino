void setup()
{
  GD.begin();
  
  lineabaseT3();  //Solo genera la linea base  
  lineabaseT4();  //Solo genera la linea base  

  GD.ClearColorRGB(0x000000);
  GD.Clear();
  GD.cmd_text(240, 136, 22, OPT_CENTER, "Cargando linea base...");
  GD.swap(); 

  MP();
}
void loop(){}
