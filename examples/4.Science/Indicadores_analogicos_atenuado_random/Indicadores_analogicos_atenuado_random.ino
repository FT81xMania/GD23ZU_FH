//#include <SPI.h>
//#include <GD2.h>

#include <GD23ZU.h>

#include "Icons2.h"        //ASSETS7b   //+switchs, +boton enc, -icono de advertencia, -iconos de audio
  float V0, incremento;


char TXPT[20];
//long previousMillis=0, refresco=500;
long previousMillis=0, refresco=1000;
uint32_t T_T4=0;

//SensorT 1
int var, var1, varP, var1P;
int PBX=30, PBY=75;

char signoD[20];
float T1, T1a, T1b, T1g, DT1, DT1g;
long previousMillisS1 = 0;
long intervalS1 = 0;
