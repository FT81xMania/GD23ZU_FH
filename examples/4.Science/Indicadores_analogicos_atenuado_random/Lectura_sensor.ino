

void LecturaSensor1()
{
  //T1=GD.random(0,100);
  //T1=random(0,100);

GD.SaveContext();
  unsigned long currentMillis = millis(); 
  if(currentMillis - previousMillis > refresco)
  {
    previousMillis = currentMillis; 
    //T_T4=(uint32_t)tempmonGetTemp();   //Sensor de temepratura del T4
    T_T4=random(0,100);    //test 
    //float TTX=random(10,30);
    float TTX=0;
    T1=T_T4 + TTX;
    sprintf(TXPT,"%u" , T_T4);  
  }

GD.RestoreContext();
  
  //T1=100;
  var1P=T1;
}

void Sensor1()
{
  unsigned long currentMillisS1 = millis();        
  if(currentMillisS1 - previousMillisS1 > intervalS1)
  {
    previousMillisS1 = currentMillisS1;

    LecturaSensor1();
    T1b = T1;
    DT1 = T1b - T1a;
    if (DT1>=0){DT1g=1;  sprintf(signoD,"+");}else{if (DT1<=0){DT1g=-1;}else{DT1g=0;}  sprintf(signoD,"-");}  //determina el intervalo de suavizado
  }
  ProcesamientoSensor1();
}

void ProcesamientoSensor1()
{
  if(T1g==T1b){T1g=T1b;}else{T1g = T1g + DT1g;}  //modifica Tg hasta alcanzar valor estable nuevo igual a Tb

   GD.Begin(RECTS);      
   GD.LineWidth(3*16); GD.Vertex2f((PBX)*16,(PBY+15+50)*16); GD.Vertex2f((PBX+(258*T1g/100))*16,(PBY+30+50)*16);
   //GD.LineWidth(3*16); GD.Vertex2f((PBX)*16,(PBY+15+50)*16); GD.Vertex2f((PBX+(258*100/100))*16,(PBY+30+50)*16);

   GD.cmd_gauge(50, 180, 40, 0, 4, 7, T1g, 100);
   GD.cmd_gauge(GD.w-50, 180, 40, 0, 4, 7, T1, 100);
  T1a = T1g;
}
