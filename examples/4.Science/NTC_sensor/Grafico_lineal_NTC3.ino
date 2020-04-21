void Arraydatos3()
{
  for (j3=0; j3<13; j3++)  //Puedes usar cualquier intervalo entre 0 y maxlecturas   XD XD, solo muestra del 0-12 
     {  
      GD.ColorRGB(0,255,0);
      sprintf(TX,"%02d", j3);          GD.cmd_text(xTextoT, (yTextoT+15*j3), 16, 0, TX);
      sprintf(TX,"%02d", lectura3[j3]); GD.cmd_text(xTextoT+40, (yTextoT+15*j3), 16, 0, TX);   
     }
}

void insertadatos3()  //En Baseactual()  ---->    convertida en función XD
{
// Esta función debe recorrer los datos hacia atrás y luego insertará el dato actual al final de la lista
//  La base nueva corresponde a la base previa -1 dato
  unsigned long currentMillis3a = millis();        
  if(currentMillis3a - previousMillis3a > interval3a)
  {
    // save the last time 
    previousMillis3a = currentMillis3a;       
  
    for (j3=0; j3<maxlecturas-1; j3++)
      {
        lectura3[j3]=lectura3[j3+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaT3();  //Toma la lectura actual del sensor
    lectura3[maxlecturas-1] = Valor3;       //base de maxlecturas puntos
  } //usa millis en lugar de delay XD XD XD para actualizar la gráficaT
}

void Baseactual3()  // lineas
{
//lee la base de datos actual  

//Gráfica lineal      
     GD.ColorRGB(0,200,0);//set the color of the point to green
     GD.Begin(LINE_STRIP);
    for (j3=0; j3<maxlecturas; j3++)
     {    
        GD.Vertex2f(((j3*separacion)+xinicial) * 16, (ybaseT-(lectura3[j3])) * 16);
     }

    lectura3[maxlecturas-1] = Valor3;  GD.ColorRGB(255,255,0); sprintf(TX,"%02d", (lectura3[maxlecturas-1])/escalaGF); GD.cmd_text(783, ybaseT-(lectura3[maxlecturas-1])-5, 20, 0, TX);  //Presenta lectura actual
    //GD.ColorRGB(0,255,0); sprintf(TX,"%04d", Lectura3); GD.cmd_text(783, ybaseT-(lectura3[maxlecturas-1])-15, 16, 0, TX);      
    j3=0;  //al salir deja j=0 para empezar la matriz en (0,0)
    
     insertadatos3();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}
