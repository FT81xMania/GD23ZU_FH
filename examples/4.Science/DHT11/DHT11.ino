#include <Wire.h>
#include <GD23ZU.h>

//leds
//Led RGB ánodo común: (+) a 3.3V, leds a pines de control(-)
int led0 = PD3;  //Verde
int led1 = PC0;  //Rojo
int led2 = PD1;  //Azul
//leds

#include "DHT.h"

#define DHTPIN     PC2      //F429, Core7XXI
#define DHTTYPE    DHT11 

DHT dht(DHTPIN, DHTTYPE);

float h, t, f;
int HM, TC, TF;
long previousMillisDHT = 0, previousMillisSec = 0; 
long intervalDHT = 1000;

int PGX=320, PGY=80;

//Parámetros del plano y gráfica lineal
int separacionM=4;            //distancia en pixeles entre puntos de la gráfica
const int maxlecturasM = 80;  //Número de puntos almacenados para graficar
float NDV = 10;               //número de divisores verticales del plano
float PitchX=32, PitchY=32;   //tamaño de cada celda en el plano

float NDH = maxlecturasM*separacionM/PitchX;  //número de divisores horizontales
float EscalaY=PitchY*NDV/100;

// Diseño de marco para gráfica
int RectWidthM = NDH*PitchX, RectHeightM = NDV*PitchY; //afecta altura del marco, base 70
//Parámetros del plano y gráfica lineal

//Humedad
float LecturaH;        // Humedad
float ValorH;          // ajuste de lectura para que quede dentro del marco de la gráfica
int lecturaHumedad[maxlecturasM];  // base de datos actual
long previousMillisH = 0, intervalH = 5000;  
int jH;
//Humedad

//Temperatura
float LecturaT;        // Temperatura
float ValorT;          // ajuste de lectura para que quede dentro del marco de la gráfica
int lecturaTemperatura[maxlecturasM];  // base de datos actual
long previousMillisT = 0, intervalT = 5000;  
int jT;
//Temperatura

char TxT[40];

int MCUID;
