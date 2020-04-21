#include <GD23ZU.h>

const short  y_data[] = {
939, 940, 941, 942, 944, 945, 946, 947, 951, 956, 
962, 967, 973, 978, 983, 989, 994, 1000, 1005, 1015, 
1024, 1034, 1043, 1053, 1062, 1075, 1087, 1100, 1112, 1121, 
1126, 1131, 1136, 1141, 1146, 1151, 1156, 1164, 1172, 1179, 
1187, 1194, 1202, 1209, 1216, 1222, 1229, 1235, 1241, 1248, 
1254, 1260, 1264, 1268, 1271, 1275, 1279, 1283, 1287, 1286, 
1284, 1281, 1279, 1276, 1274, 1271, 1268, 1266, 1263, 1261, 
1258, 1256, 1253, 1251, 1246, 1242, 1237, 1232, 1227, 1222, 
1218, 1215, 1211, 1207, 1203, 1199, 1195, 1191, 1184, 1178, 
1171, 1165, 1159, 1152, 1146, 1141, 1136, 1130, 1125, 1120, 
1115, 1110, 1103, 1096, 1088, 1080, 1073, 1065, 1057, 1049, 
1040, 1030, 1021, 1012, 1004, 995, 987, 982, 978, 974};

//Bitmap Background, title, xaxis, yaxis, Gtipo1E, Gtipo1, Gtipo2E, Gtipo2, Gtipo3E, Gtipo3, Gtipo4E, Gtipo4, Gtipo5E, Gtipo5, Gtipo6E, Gtipo6, Gtipo7E, Gtipo7;

int MCUID;

char TX[50];

int graph=1;
int A=50, AC=50, AT=50;
int B=2, BC=2, BT=2;

//Marco para graficar
int PX0=50, PY0=50, PXMAX=450-PX0, PYMAX=PY0+230, PYBase= PY0+225;

int esp=2;

void setup()
{
  GD.begin();
  IDEMCU();
  //GD.cmd_setrotate(1);  //Usar en TFT-Riverdi para conservar vector de calibración tactil en cualquier orientación
  //GD.self_calibrate();  //Con TFT-Riverdi permite reinciar el vector táctil

  GD.cmd_loadimage(0, 0);
  GD.load("Ooj9y5J.png");
}

void loop()
{
  GD.ClearColorRGB(0x000010);
  GD.Clear();  GD.get_inputs();

  GD.ColorA(144);
  GD.Begin(BITMAPS);
  GD.Vertex2f(100*16,100*16);
  GD.ColorA(255);

  GD.ColorRGB(0xffffff);
   GD.cmd_text(GD.w / 2, 15, 31, OPT_CENTER, "Graph test");

    GD.Tag(1);  GD.cmd_text(65, PYMAX+15, 28, 0, "y = 0.001x"); GD.cmd_text(65+100, PYMAX+17, 20, 0, "2");  GD.Tag(255);
    GD.Tag(2);  GD.cmd_text(65, PYMAX+15+30, 28, 0, "y = 0.5x");  GD.Tag(255);
    GD.Tag(3);  GD.cmd_text(65, PYMAX+15+30*2, 28, 0, "y = 0.5x-0.0008x");  GD.cmd_text(65+163, PYMAX+17+30*2, 20, 0, "2");  GD.Tag(255);
    GD.Tag(4);  GD.cmd_text(65, PYMAX+15+30*3, 28, 0, "y = AsinBx"); GD.cmd_text(65+100, PYMAX+17+30*3, 20, 0, "2"); GD.Tag(255);
    GD.Tag(5);  GD.cmd_text(65, PYMAX+15+30*4, 28, 0, "y = AcosBx"); GD.cmd_text(65+106, PYMAX+17+30*4, 20, 0, "2");  GD.Tag(255);
    GD.Tag(6);  GD.cmd_text(275, PYMAX+15+30*0, 28, 0, "y = AtanBx"); GD.cmd_text(275+104, PYMAX+17+30*0, 20, 0, "2");  GD.Tag(255);
    GD.Tag(7);  GD.cmd_text(275, PYMAX+15+30*1, 28, 0, "y = f(array[x])"); GD.cmd_text(275+128, PYMAX+17+30*1, 20, 0, "2"); GD.Tag(255);

  MarcoG();
  GD.cmd_text(PXMAX+55, PYMAX-10, 20, 0, "X+");
  GD.cmd_text(PX0-5, PY0-15, 20, 0, "Y+");
  GD.cmd_text(PX0-5, PYMAX+172, 20, 0, "Y-");
  

  if(graph==1){
  GD.ColorRGB(0x50ff00); GD.Begin(LINE_STRIP);    GD.LineWidth(24);  Trace1();
  GD.ColorRGB(0xffffff); GD.Begin(POINTS);      GD.PointSize(4*16);  Trace1Random();}

  if(graph==2){
  GD.ColorRGB(0x50ff00); GD.Begin(LINE_STRIP);    GD.LineWidth(24);  Trace2();
  GD.ColorRGB(0xffffff); GD.Begin(POINTS);      GD.PointSize(4*16);  Trace2();}

  if(graph==3){
  GD.ColorRGB(0x50ff00); GD.Begin(LINE_STRIP);    GD.LineWidth(24);  Trace3();
  GD.ColorRGB(0xffffff); GD.Begin(POINTS);      GD.PointSize(4*16);  Trace3();}

  if(graph==4){
    GD.ColorRGB(0x50ff00); GD.Begin(LINE_STRIP);    GD.LineWidth(24);  SIN();
    GD.ColorRGB(0xffffff); GD.Begin(POINTS);      GD.PointSize(1*16);  SIN();

    GD.cmd_fgcolor(0x000050);
    GD.Tag(11);  GD.cmd_button(500, 250, 120, 60, 29, 0,  "B-");  GD.Tag(255);
    GD.Tag(12);  GD.cmd_button(660, 250, 120, 60, 29, 0,  "B+");  GD.Tag(255);
    GD.Tag(13);  GD.cmd_button(580, 170, 120, 60, 29, 0,  "A+");  GD.Tag(255);
    GD.Tag(14);  GD.cmd_button(580, 330, 120, 60, 29, 0,  "A-");  GD.Tag(255);

    if (GD.inputs.tag==11)
    {
      B=B-1;
      if(B<=1){B=1;}      
    }

    if (GD.inputs.tag==12)
    {
      B=B+1;
      if(B>=18){B=18;}
    }

    if (GD.inputs.tag==13)
    {
      A=A+10;
      if(A>=150){A=150;}
    }

    if (GD.inputs.tag==14)
    {
      A=A-10;
      if(A<=50){A=50;}
    }    
   }

  if(graph==5){
    GD.get_inputs();
    GD.ColorRGB(0x50ff00); GD.Begin(LINE_STRIP);    GD.LineWidth(24);  COS();
    GD.ColorRGB(0xffffff); GD.Begin(POINTS);      GD.PointSize(1*16);  COS();
    
    GD.cmd_fgcolor(0x005000);
    GD.Tag(15);  GD.cmd_button(500, 250, 120, 60, 29, 0,  "B-");  GD.Tag(255);
    GD.Tag(16);  GD.cmd_button(660, 250, 120, 60, 29, 0,  "B+");  GD.Tag(255);
    GD.Tag(17);  GD.cmd_button(580, 170, 120, 60, 29, 0,  "A+");  GD.Tag(255);
    GD.Tag(18);  GD.cmd_button(580, 330, 120, 60, 29, 0,  "A-");  GD.Tag(255);

    if (GD.inputs.tag==15)
    {
      BC=BC-1;
      if(BC<=1){BC=1;}      
    }

    if (GD.inputs.tag==16)
    {
      BC=BC+1;
      if(BC>=18){BC=18;}
    }

    if (GD.inputs.tag==17)
    {
      AC=AC+10;
      if(AC>=150){AC=150;}
    }

    if (GD.inputs.tag==18)
    {
      AC=AC-10;
      if(AC<=50){AC=50;}
    }    
    
   }

  if(graph==6){
    
    //GD.ColorRGB(0x50ff00); GD.Begin(LINE_STRIP);    GD.LineWidth(24);  TAN();
    GD.ColorRGB(0x50ffff); GD.Begin(POINTS);      GD.PointSize(1*16);  TAN();
    
    GD.cmd_fgcolor(0x500000);
    GD.Tag(19);  GD.cmd_button(500, 250, 120, 60, 29, 0,  "B-");  GD.Tag(255);
    GD.Tag(20);  GD.cmd_button(660, 250, 120, 60, 29, 0,  "B+");  GD.Tag(255);
    GD.Tag(21);  GD.cmd_button(580, 170, 120, 60, 29, 0,  "A+");  GD.Tag(255);
    GD.Tag(22);  GD.cmd_button(580, 330, 120, 60, 29, 0,  "A-");  GD.Tag(255);

    if (GD.inputs.tag==19)
    {
      BT=BT-1;
      if(BT<=1){BT=1;}      
    }

    if (GD.inputs.tag==20)
    {
      BT=BT+1;
      if(BT>=18){BT=18;}
    }

    if (GD.inputs.tag==21)
    {
      AT=AT+10;
      if(AT>=150){AT=150;}
    }

    if (GD.inputs.tag==22)
    {
      AT=AT-10;
      if(AT<=50){AT=50;}
    }    
   }
   
  if(graph==7){
    
    //GD.ColorRGB(0x50ff00); GD.Begin(LINE_STRIP);    GD.LineWidth(24);  GArray();
    GD.ColorRGB(0x00ff00); GD.Begin(POINTS);  GD.PointSize(1*16);  GArray();
    sprintf(TX,"esp = %d", esp);
    GD.Tag(23); GD.ColorRGB(0xffffff);  GD.cmd_button(500, 250, 120, 60, 29, 0,  TX);  GD.Tag(255);
    
  if (GD.inputs.tag==23)
    {
      delay(95);
      esp=esp+1;
      if(esp>=3){esp=0;}
    }
   }

  if (GD.inputs.tag==1)
    {
      graph=1;
    }

  if (GD.inputs.tag==2)
    {
      graph=2;
    }

  if (GD.inputs.tag==3)
    {
      graph=3;
    }

  if (GD.inputs.tag==4)
    {
      graph=4;
    }        

   if (GD.inputs.tag==5)
   {
      graph=5;
    }

   if (GD.inputs.tag==6)
   {
      graph=6;
    }

   if (GD.inputs.tag==7)
   {
      graph=7;
    }            
  Parametros();
  GD.swap();
}

void Trace1()
{
  for (float x = 0; x < (PXMAX-10); x += 20) {
    float y = PYBase - ((0.001*x*(x)));
    GD.Vertex2f((x+PX0)*16, y*16);
  }  
}

void Trace1Random()
{
  for (float x = 0; x < (PXMAX-10); x += 20) {
    float y = PYBase - ((0.001*x*(x+random(-30,30))));
    GD.Vertex2f((x+PX0)*16, y*16);
  }  
}

void Trace2()
{
  for (float x = 0; x < (PXMAX-10); x += 20) {
    float y = PYBase - ((0.5*x));
    GD.Vertex2f((x+PX0)*16, y*16);
  }  
}

void Trace3()
{
  for (float x = 0; x < (PXMAX-10); x += 20) {
    float y = PYBase - ((0.5*x)-0.0008*x*x);
    GD.Vertex2f((x+PX0)*16, y*16);
  }  
}

void SIN(){
  for ( long  i = 0 ; i<=359 ; i++)
    {  
       GD.Vertex2f((i+PX0)*16, (PYBase-(A*sin((B*i*PI)/180)))*16);
     }
}

void COS(){
  for ( long  j = 0 ; j<=359 ; j++)
    {  
       GD.Vertex2f((j+PX0)*16, (PYBase-(AC*cos((BC*j*PI)/180)))*16);
     }
}

void TAN(){
  for ( long  j = 0 ; j<=359 ; j++)
    {  
       GD.Vertex2f((j+PX0)*16, (PYBase-(AT*tan((BT*j*PI)/180)))*16);
     }
}

void MarcoG()
{
  GD.Begin(LINES);
  GD.Vertex2f(PX0*16, PY0*16);    GD.Vertex2f(PX0*16, (PYMAX+170)*16);
  GD.Vertex2f(PX0*16, (PYMAX-4)*16);  GD.Vertex2f((PXMAX+PX0)*16, (PYMAX-4)*16);
}

void GArray(){
  for ( long  j = 0 ; j<=119 ; j++)
    {  
       GD.Vertex2f((j+PX0+esp*j)*16, (PYBase-(y_data[j]/10))*16);
     }
}
