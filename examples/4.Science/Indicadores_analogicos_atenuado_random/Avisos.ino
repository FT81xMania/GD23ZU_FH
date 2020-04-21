void espera()
{
  GD.ClearColorRGB(0x000025); //fondo de pantalla
  GD.Clear();
    GD.ColorA(255);  
    GD.cmd_text(240, 120, 26,   OPT_CENTERX, "Procesando entorno visual...");    
  GD.swap(); 
}
