// marcas de -90 a 90 grados
void MarcasDialV(uint16_t RadioBase, uint16_t XBase, uint16_t YBase, uint16_t LargoMarcas, uint16_t EspesorMarcas)
{
//Carátula del gauge personalizado   
//Base del Dial o Gauge
  GD.ColorA(255);
//  GD.ColorRGB(0x00,0xff,0x00);
//  GD.PointSize(RadioBase * 16);
//  GD.Begin(POINTS);   
//  GD.Vertex2f(XBase * 16, YBase * 16);
//  GD.End();
//Base del Dial o Gauge

//Submarcas
  float X1, Y1, X2, Y2;
  float pi=3.1415926535897932384626433832795;
//Gauge o arco XD
  GD.ColorA(175);
  GD.ColorRGB(0xFF,0xFF,0xFF);
//   for (int Angulo = 0; Angulo<=180; Angulo++ )  // Gauge Continuo desde la horizontal
   
  // for (int Angulo = 0; Angulo<=180; Angulo= Angulo + 18){  // Gauge Discontinuo  horizonte de 180 grados con 
  for (int Angulo = -100; Angulo<=120; Angulo= Angulo + ((210)/10)){  // Gauge Discontinuo, bajo horizonte de -20 a 200 grados XD
  GD.LineWidth(EspesorMarcas * 16);
    GD.Begin(LINES);
        X1 = (RadioBase-LargoMarcas)* cos(Angulo*pi/180);
        Y1 = (RadioBase-LargoMarcas)* sin(Angulo*pi/180);

        X2 = (RadioBase)* cos(Angulo*pi/180);
        Y2 = (RadioBase)* sin(Angulo*pi/180);

  GD.Vertex2f((XBase - X1) * 16, (YBase - Y1) * 16);   //starting coordinates
  GD.Vertex2f((XBase - X2) * 16, (YBase - Y2) * 16);  //ending coordinates  
  GD.End();//end lines primitive
       }
//Submarcas

//Marcas principales
//  GD.ColorA(255);
  /* display list for drawing line */
//  GD.ColorRGB(0xFF,0xFF,0xFF);
//  GD.LineWidth(EspesorMarcas * 16);
//    GD.Begin(LINES);

//Dial a 0 grados
//  GD.Vertex2f((XBase-RadioBase+LargoMarcas) * 16, (YBase) * 16);   //starting coordinates
//  GD.Vertex2f((XBase-RadioBase) * 16, (YBase) * 16);  //ending coordinates  

//Dial a 90 grados
//  GD.Vertex2f((XBase) * 16, (YBase-RadioBase+LargoMarcas) * 16);   //starting coordinates
//  GD.Vertex2f((XBase) * 16, (YBase-RadioBase) * 16);  //ending coordinates  

//Dial a 180 grados
 // GD.Vertex2f((XBase+RadioBase-LargoMarcas) * 16, (YBase) * 16);   //starting coordinates
 // GD.Vertex2f((XBase+RadioBase) * 16, (YBase) * 16);  //ending coordinates  
 // GD.End();//end lines primitive
//Marcas principales
}
