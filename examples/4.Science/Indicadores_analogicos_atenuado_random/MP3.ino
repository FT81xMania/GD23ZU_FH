void MP3(){  //Random

while(1)
{

//  if(V0==100){incremento=-1;}
//    if(V0==0){incremento=1;}  
//   V0 = V0+incremento;
  
  V0 = random(0,100);  

 GD.ClearColorRGB(0x151515); //fondo de pantalla
 GD.Clear();
// GD.SaveContext();     
//  GD.Begin(BITMAPS); GD.Vertex2ii(0, 100); GD.End();
// GD.RestoreContext();    



// Gauge vertical de -90 a 90 grados 
  MarcasDialV(70,85,125,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0xff);
  Analogico2(70,85,125,30,1,2,V0,100,21,90,135, 4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote 
//  Analogico2(50,75,80,45,1,1,V0,100,21,45+25,115-18, 4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote
 
//  MarcasDial(70,240,135,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
//   Analogico(70,240,135,7,65,1,5,V0,100,21,250,150, 0,0,255,4);
     
  MarcasDial(140,240,170,5,2); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
   Analogico(140,240,170,20,135,2,4,V0,100,24,250,200, 0,0,255,6);   
//RadioBase, XBase, YBase, LargoSeguidor, largoAguja, EspesorAguja, SeparadorSeguidor, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, R, G, B, radio del pivote.    
     
// Gauge vertical de 90 a 270 grados 
  MarcasDialV2(70,395,125,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0xff);
  Analogico3(70,395,125,30,1,2,V0,100,21,410,135,4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote  
//  Analogico3(50,275,80,45,1,1,V0,100,21,295,115-18,4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote

 GD.swap();
// delay(50); 
 }
}
