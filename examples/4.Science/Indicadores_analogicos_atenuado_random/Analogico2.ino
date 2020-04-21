// Solo aguja analogica vertical -90 a 90 grados
void Analogico2(uint16_t RadioBase, uint16_t XBase, uint16_t YBase, uint16_t LargoAguja, uint16_t Addaguja, uint16_t EspesorAguja, uint16_t Variable, uint16_t RangoEscala, uint16_t SizeTxt, uint16_t XTxt, uint16_t YTxt, uint16_t pivote)
{
    RadioBase = RadioBase - 10;  //Da la separación respecto a las marcas secundarias
 
    float X1, Y1, X2, Y2, Tetha;
    float pi=3.1415926535897932384626433832795;
    //int XText=180, YText=185;
//         Tetha = (200 * Variable/RangoEscala);
         
          Tetha = map(Variable, 0, RangoEscala, -100, 120);       //elimina el limite horizontal de los 180 grados XD  

//Aguja del Dial
        X1 = (RadioBase-LargoAguja-Addaguja)* cos(Tetha*pi/180);
        Y1 = (RadioBase-LargoAguja-Addaguja)* sin(Tetha*pi/180);

        X2 = (RadioBase)* cos(Tetha*pi/180);
        Y2 = (RadioBase)* sin(Tetha*pi/180);
        
//    GD.ColorA(255); GD.ColorRGB(0xFF,0x00,0x00);
    GD.LineWidth(EspesorAguja * 16);
    GD.Begin(LINES);
    GD.Vertex2f((XBase - X1) * 16, (YBase - Y1) * 16);   //starting coordinates
    GD.Vertex2f((XBase - X2) * 16, (YBase - Y2) * 16);  //ending coordinates  
    
//Pivote
  GD.ColorA(205);
  GD.ColorRGB(0xff,0x00,0x00);
   GD.PointSize(pivote * 16);
   GD.Begin(POINTS);   
   GD.Vertex2f(XBase * 16, YBase * 16);
//Pivote
    
     GD.ColorRGB(255,255,255);   GD.cmd_number(XTxt, YTxt, SizeTxt, OPT_SIGNED|OPT_RIGHTX, Variable);           
}  
// Solo aguja analogica
