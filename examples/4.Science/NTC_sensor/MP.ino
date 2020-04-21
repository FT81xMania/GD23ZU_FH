void MP()
{
do
 {
  GD.ClearColorRGB(0x000000);  //color de fondo
  GD.Clear();  
  fondopantalla();

  readT3(0, 22, 0, 70);          
   //Arraydatos3();  //Presenta los datos de la base de 13 datos en una función XD   
  Baseactual3();     //  Gráfica lineal    
  
  readT4(0, 22, 0, 140);          
   //Arraydatos4();  //Presenta los datos de la base de 13 datos en una función XD   
  Baseactual4();     //  Gráfica lineal


   GD.SaveContext();
   GD.ColorRGB(255,255,0);
    GD.cmd_text(105, 233, 26, 0, "T (   C)");  GD.cmd_text(125, 230, 20, 0, "o");
    GD.cmd_text(420, 450, 26, 0, "Intervalo de lectura (s)");
    
      GD.cmd_text(170, 432, 20, 0, "0"); 
     GD.cmd_text(162, 392, 20, 0, "10"); 
     GD.cmd_text(162, 352, 20, 0, "20"); 
     GD.cmd_text(162, 312, 20, 0, "30"); 
     GD.cmd_text(162, 272, 20, 0, "40"); 
     GD.cmd_text(162, 232, 20, 0, "50"); 
     GD.cmd_text(162, 192, 20, 0, "60"); 
     GD.cmd_text(162, 152, 20, 0, "70"); 
     GD.cmd_text(162, 112, 20, 0, "80"); 
      GD.cmd_text(162, 72, 20, 0, "90"); 
     GD.cmd_text(156, 32, 20, 0, "100"); 
   GD.RestoreContext();
   
 
  GD.swap();
 }
 while(1); 
}  
