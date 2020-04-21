// Aguja analógica + seguidor o gauge, de -20 a 200 grados
void Analogico(uint16_t RadioBase, uint16_t XBase, uint16_t YBase, uint16_t LargoAguja, uint16_t Addaguja, uint16_t EspesorAguja, uint16_t Separador, uint16_t Variable, uint16_t RangoEscala, uint16_t SizeTxt, uint16_t XTxt, uint16_t YTxt, uint16_t  R, uint16_t  G, uint16_t  B, uint16_t  pivote)
{
  RadioBase = RadioBase - 10;  //Da la separación respecto a las marcas secundarias
  
	float X1, Y1, X2, Y2, Tetha;
        float pi=3.1415926535897932384626433832795;
        //int XText=180, YText=185;
          //  Tetha = (200 * Variable/RangoEscala);
            
          Tetha = map(Variable, 0, RangoEscala, -30, 210);       //elimina el limite horizontal de los 180 grados XD  

//Gauge o arco XD
  GD.ColorA(200);
	//FTImpl.ColorRGB(0x00,0xFF,0x00); // verde

    //R=0;G=0,B=210;
    GD.ColorRGB(R,G,B);


  
   //for (int Angulo = 0; Angulo<=(Tetha-5); Angulo++ ) // Gauge Continuo desde la horizontal, 5 grados antes de la aguja
   //for (int Angulo = 0; Angulo<=(Tetha-3); Angulo= Angulo + 1)  // Gauge Continuo desde la horizontal, 3 grados antes de la aguja
   for (int Angulo = -30; Angulo<=(Tetha-3); Angulo= Angulo + Separador){  // Gauge Continuo desde la horizontal, 3 grados antes de la aguja
   // for (int Angulo = -10; Angulo<=(Tetha-5); Angulo++ )  // Gauge Continuo desde 10 grados por debajo de la horizontal, solo visual, 5 grados antes de la aguja
   // for (int Angulo = 0; Angulo<=(Tetha-1); Angulo= Angulo + 5)  // Gauge Discontinuo
    GD.LineWidth(1 * 16); //Espesor de las lineas que forman el gauge solido que acompaña a la aguja
    GD.Begin(LINES);
          X1 = (RadioBase-LargoAguja)* cos(Angulo*pi/180);
          Y1 = (RadioBase-LargoAguja)* sin(Angulo*pi/180);

          X2 = (RadioBase)* cos(Angulo*pi/180);
          Y2 = (RadioBase)* sin(Angulo*pi/180);
	      GD.Vertex2f((XBase - X1) * 16, (YBase - Y1) * 16);   //starting coordinates
	      GD.Vertex2f((XBase - X2) * 16, (YBase - Y2) * 16);  //ending coordinates	
       }
//Gauge o arco XD


//Pivote
  GD.ColorA(205);
  GD.ColorRGB(0xff,0x00,0x00);
  GD.PointSize(pivote * 16);
  GD.Begin(POINTS);   
  GD.Vertex2f(XBase * 16, YBase * 16);
//Pivote

//Aguja del Dial
        X1 = (RadioBase-LargoAguja-Addaguja)* cos(Tetha*pi/180);
        Y1 = (RadioBase-LargoAguja-Addaguja)* sin(Tetha*pi/180);

        X2 = (RadioBase)* cos(Tetha*pi/180);
        Y2 = (RadioBase)* sin(Tetha*pi/180);
  GD.ColorA(255);
	GD.ColorRGB(0xFF,0x00,0x00);
	GD.LineWidth(EspesorAguja * 16);
    GD.Begin(LINES);
	GD.Vertex2f((XBase - X1) * 16, (YBase - Y1) * 16);   //starting coordinates
	GD.Vertex2f((XBase - X2) * 16, (YBase - Y2) * 16);  //ending coordinates
    GD.ColorRGB(50,55,255);  GD.cmd_number(XTxt, YTxt, SizeTxt, OPT_SIGNED|OPT_CENTER, Variable);
    GD.End();

GD.SaveContext();
  GD.ColorA(205);
  GD.ColorRGB(0xff,0x00,0x00);
  GD.PointSize(2 * 16);
  GD.Begin(POINTS);   
  GD.Vertex2f((XBase - ((RadioBase+17)* cos(Tetha*pi/180))) * 16, (YBase - ((RadioBase+18)* sin(Tetha*pi/180))) * 16);
GD.RestoreContext();    
}
// Aguja analógica + seguidor o gauge
