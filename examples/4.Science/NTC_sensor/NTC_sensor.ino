#include <GD23ZU.h>

char TX[50];  //datos a texto

  const int maxlecturas = 150;  //ya puedes seleccionar los que quieras XD  
  int lectura3[maxlecturas];  // base de datos NTC3
  int k3,j3;

  int lectura4[maxlecturas];  // base de datos NTC4
  int k4,j4;
  
//Posición base de la gráfica  
  int xinicial=180;
  int ybaseT=440;
//Posición base de la gráfica  

  int escalaGF=4;
  int separacion=4;  //separación entre puntos
  int sepGF=escalaGF*10;      //separación entre celdas del fondo para graficar  
  
//Posición del listado de la base de datos
  int xTextoT = 65;
  int yTextoT = 145;  
//Posición del listado de la base de datos

//Millis en lugar de delay para gráfica lineal
long previousMillis3a = 0;        // will store last time was updated
long interval3a = 4000;           // 

long previousMillis4a = 0;        // will store last time was updated
long interval4a = 4000;           // 

// Diseño de marco para gráfica
int RectWidth = separacion*maxlecturas, RectHeight = sepGF*10;
int XGT=xinicial, YGT=ybaseT-RectHeight;

float TAmb = 23;

//***********************Sensor NTC3
    float analogPin3=PC3;   //Core7XXI pines analógicos: PB0 PB1 PA3 PA2 PA0 PA1 PC3 PC2 PC1 PC0
    
    int Lectura3;        // activar variable para las lecturas
    int Valor3;          // ajuste de lectura para que quede dentro del marco de la gráfica
    int TempCF3;          // variable de temperatura calculada
    float TempCF3F;

//    Calibración del NTC3 hecha con 3.3 V
    // Ambiente       (temperatura menor)
    float Temp3X1=TAmb;          // temperatura ambiente
    float Lect3Y1=480;          // lectura ambiente
   
   // Referencia base (temperatura mayor)
    float Temp3X2=36.6;          // temperatura dedos
    float Lect3Y2=608;          // 

    
// Calculos intermedios
    float p3= -1 * ((Lect3Y2 - Lect3Y1)/(Temp3X2 - Temp3X1));    // pendiente de la recta

//Millis en lugar de delay para gráfica de temperatura
long previousMillis3 = 0;        // will store last time was updated
long interval3 = 4000;           // 

float T3;
//***********************Sensor NTC3

//***********************Sensor NTC4
    //float analogPin4=PC3;   //Core7XXI pines analógicos: PB0 PB1 PA3 PA2 PA0 PA1 PC3 PC2 PC1 PC0
    float analogPin4=PC1;   //Core7XXI pines analógicos: PB0 PB1 PA3 PA2 PA0 PA1 PC3 PC2 PC1 PC0
    int Lectura4;        // activar variable para las lecturas
    int Valor4;          // ajuste de lectura para que quede dentro del marco de la gráfica
    int TempCF4;          // variable de temperatura calculada
    float TempCF4F;

//    Calibración del NTC-A4 hecha con 3.3 V
    // Ambiente       (temperatura menor)
    float Temp4X1=TAmb;          // temperatura ambiente
    float Lect4Y1=480;          // lectura ambiente

   
   // Referencia base (temperatura mayor)
    float Temp4X2=36.6;          // temperatura dedos
    float Lect4Y2=608;          // lectura dedos  previo 769

    
// Calculos intermedios
    float p4= -1 * ((Lect4Y2 - Lect4Y1)/(Temp4X2 - Temp4X1));    // pendiente de la recta

//Millis en lugar de delay para gráfica de temperatura
long previousMillis4 = 0;        // will store last time was updated
long interval4 = 4000;           // 

float T4;
//***********************Sensor NTC4
