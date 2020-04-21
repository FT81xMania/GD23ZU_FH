void MP(){
  uint32_t m_ptr, m_w, m_h;  
  GD.cmd_getprops(m_ptr, m_w, m_h);
  GD.finish();

  uint16_t w = GD.rd16(m_w);
  uint16_t h = GD.rd16(m_h);  
  GD.BitmapSize(BILINEAR, BORDER, BORDER, w, h);
  float zoom = 0.3;   
while(1)
{
  V0 = GD.random(1024); 
  V0 = 0;
 GD.Clear();
// GD.SaveContext();     
//  GD.Begin(BITMAPS); GD.Vertex2ii(0, 100); GD.End();
// GD.RestoreContext();    

GD.SaveContext();
//    GD.ColorRGB(0xffffff);
    int zw = zoom * w / 2;
    int zh = zoom * h / 2;
    GD.Begin(BITMAPS);
    GD.cmd_scale(F16(zoom), F16(zoom));
    GD.cmd_setmatrix();
    GD.Vertex2ii(240 - zw, 173 - zh, 15, 0);
    zoom = min(1.0, zoom * 1.2);
GD.RestoreContext();    

GD.SaveContext();
   icon3Zoom(3, 350, 75, 0.5);   // escala 0.5 XD de cualquier icono XD del set de iconos desplegado

   GD.Vertex2ii(0, 45, 0);
   GD.Vertex2ii(55, 45, 1);  
   GD.Vertex2ii(105, 45, 2);
   GD.Vertex2ii(155, 45, 3);  
   GD.Vertex2ii(205, 45, 4);  
   GD.Vertex2ii(255, 45, 5);    
   GD.Vertex2ii(0, 115, 6);
   GD.Vertex2ii(55, 115, 7);    
   GD.Vertex2ii(120, 115, 8);
   GD.Vertex2ii(155, 115, 9);  
   GD.Vertex2ii(205, 115, 10);  
   GD.Vertex2ii(255, 115, 11);   
   GD.Vertex2ii(0, 185, 12);        
   GD.Vertex2ii(55, 185, 13);
GD.RestoreContext();    


  MarcasDial(150,230,185,6,2); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
   Analogico(150,230,185,15,145,3,1,V0,1024,24,230+90,200-18, 255,255,0, 7); //RadioBase, XBase, YBase, LargoSeguidor, largoAguja, EspesorAguja, SeparadorSeguidor, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, R, G, B, radio del pivote. 


// Gauge horizontal de -20 a 200 grados 
//  MarcasDial(50,75,100,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
//  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0x00);
//  Analogico(50,75,100,9,1,1,V0,1024,21,75+25,100-18);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto 

// Gauge vertical de -90 a 90 grados 
  MarcasDialV(50,75,100,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0x00);
//  Analogico2(50,75,100,9,1,1,V0,1024,21,10+25,100-18);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto 
  Analogico2(50,75,100,45,1,1,V0,1024,21,10+25,100-18,3);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto
 
// Gauge vertical de 90 a 270 grados 
  MarcasDialV2(50,115,100,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0x00);
//  Analogico3(50,115,100,9,1,1,V0,1024,21,115+25,100-18);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto  
  Analogico3(50,115,100,45,1,1,V0,1024,21,115+25,100-18, 3);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, ángulo inicial, ángulo final  
 
 
 //Usar solo un indicador con espesor del seguidor = 1, ya que dos causan error de procesador
 // MarcasDial(50,75,100,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
 //  Analogico(50,75,100,7,45,1,1,V0,1024,21,75+25,100-18, 0,0,255,2);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Separador, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto. Solo aguja analogica. Con divisiones en la banda seguidora o gauge 

  MarcasDial(50,220,100,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
   Analogico(50,220,100,7,45,1,5,V0,1024,21,220+25,100-18, 0,255,0,2);
     
  MarcasDial(50,365,100,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
   Analogico(50,365,100,7,45,1,5,V0,1024,21,365+25,100-18, 0,255,255,2);     
     


 GD.swap();
 delay(50); 
 }
}
