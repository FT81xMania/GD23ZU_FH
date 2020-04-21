void fondopantalla()
{
// Diseño de marco/fondo para gráfica
  GD.ColorA(60); //transperencia
  GD.ColorRGB(0x00ff00);
     GD.LineWidth(1 * 16);
     GD.Begin(LINES);
       marcadoresverticales();
       
       marcadoreshorizontales();
  GD.ColorA(255); //color solido      
// Diseño de marco para gráfica
}  


void fondografica()
{
    GD.Vertex2f(XGT * 16, (YGT) * 16);                          //Esquina superior izquierda
    GD.Vertex2f((XGT+RectWidth) * 16, (YGT+RectHeight) * 16); //esquina inferior derecha
}  

void marcadoresverticales()
{
    for (int k=0; k<=RectWidth/(10*escalaGF); k++)
     {    
  GD.Vertex2f((XGT+(k*sepGF)) * 16, YGT* 16);  //starting coordinates
  GD.Vertex2f((XGT+(k*sepGF)) * 16, (YGT+RectHeight) * 16);  //ending coordinates
     }  
}


void marcadoreshorizontales()
{
    for (int k=0; k<=10; k++)
     {    
  GD.Vertex2f((XGT) * 16, ((YGT)+(k*sepGF))* 16);  //starting coordinates
  GD.Vertex2f((XGT+RectWidth) * 16, ((YGT)+(k*sepGF)) * 16);  //ending coordinates
     }     
}
// Diseño de marco para gráfica
