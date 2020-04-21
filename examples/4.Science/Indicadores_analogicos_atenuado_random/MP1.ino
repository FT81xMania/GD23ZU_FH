void MP1(){
  uint32_t m_ptr, m_w, m_h;  
  GD.cmd_getprops(m_ptr, m_w, m_h);
  GD.finish();

  uint16_t w = GD.rd16(m_w);
  uint16_t h = GD.rd16(m_h);  
  GD.BitmapSize(BILINEAR, BORDER, BORDER, w, h);
  float zoom = 0.3;   
  int DeltaXM=18;
while(1)
{

  if(V0==100){incremento=-1;}
    if(V0==0){incremento=1;}  
   V0 = V0+incremento;
  

 GD.Clear();
// GD.SaveContext();     
//  GD.Begin(BITMAPS); GD.Vertex2ii(0, 100); GD.End();
// GD.RestoreContext();    

GD.SaveContext();
  GD.ColorRGB(0x00ffff); GD.cmd_text(GD.w-24, 2, 21, 0, TXPT); GD.cmd_text(GD.w-7, -2, 20, 0, "o"); GD.cmd_text(GD.w-7, 5, 20, 0, "c"); 
  GD.ColorRGB(0x00ffff); GD.cmd_text(185-DeltaXM-10, 2+60, 28, OPT_CENTER, signoD);
GD.RestoreContext();  

GD.SaveContext();
//    GD.ColorRGB(0xffffff);
    int zw = zoom * w / 2;
    int zh = zoom * h / 2;
    GD.Begin(BITMAPS);
    GD.cmd_scale(F16(zoom), F16(zoom));
    GD.cmd_setmatrix();
    GD.Vertex2ii(240 - zw, 198 - zh, 15, 0);
    zoom = min(1.0, zoom * 1.2);
GD.RestoreContext();    

// Gauge vertical de -90 a 90 grados 
  MarcasDialV(40,70-DeltaXM,80,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0xff);
  //Analogico2(50,75,80,20,1,1,V0,100,21,45+25,115-18, 4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote 
  //  Analogico2(50,75,80,20,1,1,T_T4,100,21,45+25,115-18, 4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote 
    Analogico2(40,70-DeltaXM,80,20,1,1,T1g,100,21,45+25-DeltaXM,115-18, 4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote 


//Gauge central 
   MarcasDial(80,175-DeltaXM,90,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
   //Analogico(70,175,90,7,65,1,5,V0,100,21,185,105, 0,0,255,4);
   //Analogico(70,175,90,7,65,1,5,T_T4,100,21,185,105, 0,0,255,4);
   Analogico(80,175-DeltaXM,90,7,65,1,5,T1g,100,31,175-DeltaXM,115,0,0,255,4);
   
     
// Gauge vertical de 90 a 270 grados 
  MarcasDialV2(40,280-DeltaXM+5,80,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0xff);
  //Analogico3(50,275,80,20,1,1,V0,100,21,295,115-18,4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote  
  //  Analogico3(50,275,80,20,1,1,T_T4,100,21,295,115-18,4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote  
    Analogico3(40,280-DeltaXM+5,80,20,1,1,T1g,100,21,295-DeltaXM,115-18,4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote  

Sensor1();

 GD.swap();
// delay(50); 
 }
}
