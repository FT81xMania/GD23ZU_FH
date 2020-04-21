void LecturaNTC3() //Toma la lectura del sensor
{
     Lectura3=analogRead(analogPin3);  //Original
     
     TempCF3F =Temp3X1-0.3 + ((Lect3Y1 - Lectura3)/p3);  
//     TempCF3 = random(20,25);  //pruebas
}

int deltaX3=107, deltaX23 = 162, deltaY3=10;  //tamaño 22
void readT3(int SepTy, int Fuente, int posX, int posY)
{
 unsigned long currentMillis3 = millis();        
 if(currentMillis3 - previousMillis3 > interval3)
 {  
  previousMillis3 = currentMillis3;
  LecturaNTC3();  T3 = TempCF3F * 1;   
 }
    GD.cmd_romfont(14,31);     
    GD.ColorRGB(0,200,0);   plotfloat(70, 52, T3, 1, 14);
}

void LecturaT3()
{
  Lectura3=TempCF3F;
  //Lectura=0;
  Valor3=Lectura3*escalaGF;  //ajuste para que el gráfico quede dentro de la ventana
}

void lineabaseT3()
{
  for (int k=0; k<maxlecturas; k++)
      {
       //LecturaMSGEQ7();
       Valor3=0;
        lectura3[k] = Valor3;  
      }        
  //k3 = maxlecturas;    // al salir de la linea base XD siempre será i = maxlecturas  
}
