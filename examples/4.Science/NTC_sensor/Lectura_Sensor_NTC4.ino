void LecturaNTC4() //Toma la lectura del sensor
{
     Lectura4=analogRead(analogPin4);  //Original
     
     TempCF4F =Temp4X1 + ((Lect4Y1 - Lectura4)/p4);  
//     TempCF4 = random(20,25);  //pruebas
}

int deltaX=107, deltaX2 = 162, deltaY=10;  //tamaño 22
void readT4(int SepTy, int Fuente, int posX, int posY)
{
 unsigned long currentMillis4 = millis();        
 if(currentMillis4 - previousMillis4 > interval4)
 {  
  previousMillis4 = currentMillis4;             
  LecturaNTC4();  T4 = TempCF4F * 1;   
 }
    GD.cmd_romfont(14,31);   //Usa las fuentes adicionales del FT81X: 31, 32, 33, 34  
    GD.ColorRGB(255,255,255);   plotfloat(70, 120, T4, 1, 14);
}

void LecturaT4()
{
  Lectura4=TempCF4F;
  //Lectura=0;
  Valor4=Lectura4*escalaGF;  //ajuste para que el gráfico quede dentro de la ventana
}

void lineabaseT4()
{
  for (int m=0; m<maxlecturas; m++)
      {
       //LecturaMSGEQ7();
       Valor4=0;
        lectura4[m] = Valor4;  
      }        
  //k4 = maxlecturas;    // al salir de la linea base XD siempre será i = maxlecturas  
}
