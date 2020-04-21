//const short  y_data[] = {
//30701, 10641, 9404, 2843, 5957, 4552, 3715, 2320, 1632, 2833, 
//2644, 2203, 2644, 2379, 2203, 1859, 1474, 1241, 1467, 1235};

const short  y_data[] = {
32015, 30701, 10858, 9404, 5957, 4552, 3715, 2843, 2833, 2644,  
2379, 2320, 2175, 1934, 1859, 1740, 1632, 1471, 1467, 1326, 1321, 1244, 1239};

void GArray(){
  GD.ColorRGB(0x00ff00); 
  for ( long  j = 0 ; j<=22 ; j++)
    {  
       GD.Vertex2f((j+PX0+esp*j)*16, (PYBase-(y_data[j]/100))*16);
       if(y_data[j]==Elapsed){GD.ColorRGB(0x00ff00);}
       if(y_data[j]<Elapsed){GD.ColorRGB(0x00ff00);}       
     }
}

void GArrayLinea(){
  GD.ColorRGB(0xffff00); ;
  for ( long  j = 0 ; j<=22 ; j++)
    {  
       if(y_data[j]==Elapsed){GD.ColorRGB(0xff0000);}
       if(y_data[j]<Elapsed){GD.ColorRGB(0x00ff00);}
 
       GD.Vertex2f((j+PX0+esp*j)*16, (PYBase)*16);
       GD.Vertex2f((j+PX0+esp*j)*16, (PYBase-(y_data[j]/100))*16);
     }
}

void MarcoG()
{
  GD.Begin(LINES); GD.LineWidth(16 * 0.5);
  GD.Vertex2f((PX0-esp)*16, (PY0-110)*16);    GD.Vertex2f((PX0-esp)*16, (PYMAX+50)*16);
  GD.Vertex2f((PX0-esp)*16, (PYMAX-4)*16);  GD.Vertex2f((PXMAX+PX0-esp)*16, (PYMAX-4)*16);
  
  GD.cmd_text(PXMAX+55-10, PYMAX-10, 20, 0, "X+");
  GD.cmd_text(PX0-5-esp, PY0-15-110, 20, 0, "Y+");
  GD.cmd_text(PX0-5-esp, PYMAX+52, 20, 0, "Y-");
}

void Grafico()
{
  GD.SaveContext();
    MarcoG();
  GD.RestoreContext();
 
  GD.SaveContext();
    GD.Begin(POINTS);  GD.PointSize(2*16);  GArray();
  GD.RestoreContext();

  GD.SaveContext();
    GD.Begin(LINES); GD.LineWidth(16 * 1); GD.PointSize(1*16);  GArrayLinea();
  GD.RestoreContext();
}
