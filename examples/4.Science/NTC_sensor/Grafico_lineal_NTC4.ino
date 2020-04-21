void Arraydatos4()
{
  for (j4=0; j4<13; j4++)  //Puedes usar cualquier intervalo entre 0 y maxlecturas   XD XD, solo muestra del 0-12 
     {  
      GD.ColorRGB(0,255,0);
      sprintf(TX,"%02d", j4);          GD.cmd_text(xTextoT, (yTextoT+15*j4), 16, 0, TX);
      sprintf(TX,"%02d", lectura4[j4]); GD.cmd_text(xTextoT+40, (yTextoT+15*j4), 16, 0, TX);   
     }
}

void insertadatos4()  //En Baseactual()  ---->    convertida en función XD
{
// Esta función debe recorrer los datos hacia atrás y luego insertará el dato actual al final de la lista
//  La base nueva corresponde a la base previa -1 dato
  unsigned long currentMillis4a = millis();        
  if(currentMillis4a - previousMillis4a > interval4a)
  {
    // save the last time 
    previousMillis4a = currentMillis4a;       
  
    for (j4=0; j4<maxlecturas-1; j4++)
      {
        lectura4[j4]=lectura4[j4+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaT4();  //Toma la lectura actual del sensor
    lectura4[maxlecturas-1] = Valor4;       //base de maxlecturas puntos
  } //usa millis en lugar de delay XD XD XD para actualizar la gráficaT
}

void Baseactual4()  // lineas
{
//lee la base de datos actual  

//Gráfica lineal      
     GD.ColorRGB(0xFF,0xFF,0xff);//set the color of the point to white
     GD.Begin(LINE_STRIP);
    for (j4=0; j4<maxlecturas; j4++)
     {    
        GD.Vertex2f(((j4*separacion)+xinicial) * 16, (ybaseT-(lectura4[j4])) * 16);
     }

    lectura4[maxlecturas-1] = Valor4;  GD.ColorRGB(255,255,0); sprintf(TX,"%02d", (lectura4[maxlecturas-1])/escalaGF); GD.cmd_text(783, ybaseT-(lectura4[maxlecturas-1])-5, 20, 0, TX);  //Presenta lectura actual
    //GD.ColorRGB(0,255,0); sprintf(TX,"%04d", Lectura); GD.cmd_text(783, ybaseT-(lectura[maxlecturas-1])-15, 16, 0, TX);      
    j4=0;  //al salir deja j=0 para empezar la matriz en (0,0)
    
     insertadatos4();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}
