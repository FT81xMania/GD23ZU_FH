char Board[50];
int ClaveBoard;

void IDEMCU()
{
     ClaveBoard=0;
     sprintf(Board, "MCU: None               (%d)", ClaveBoard);

  #if defined(ARDUINO_ARCH_STM32)
     ClaveBoard=1;
     //sprintf(Board, "MCU(%d): STM32 Nucleo-F767ZI", ClaveBoard);
     //if (STM32_CPU==407){sprintf(Board, "MCU: STM32 F407 M4DEMO"); MCUID=407;}
     if (STM32_CPU==4070){sprintf(Board, "MCU: STM32 F407 M4DEMO_SD"); MCUID=4070;}
     if (STM32_CPU==4071){sprintf(Board, "MCU: STM32 F407 M4DEMO_SDIO"); MCUID=4071;}
     if (STM32_CPU==429){sprintf(Board, "MCU: STM32 F49I-DISCO"); MCUID=429;}
     if (STM32_CPU==746){sprintf(Board, "MCU: STM32 Core7XXI"); MCUID=746;}
     if (STM32_CPU==767){sprintf(Board, "MCU: STM32 Nucleo-F767ZI (Core Danieleff)"); MCUID=767;}
     if (STM32_CPU==7670){sprintf(Board, "MCU: STM32 Nucleo-F767ZI (Core Oficial)"); MCUID=7670;}
  #endif

  #ifdef TEENSYDUINO
     ClaveBoard=2;
     sprintf(Board, "MCU: Teensy 3.6");
  #endif

  #ifdef __DUE__
     ClaveBoard=3;
     sprintf(Board, "MCU: Arduino Due");
  #endif

  #ifdef ESP8266
     ClaveBoard=4;
     sprintf(Board, "MCU: ESP8266");
  #endif

  #if defined(ESP32)
     ClaveBoard=5;
     sprintf(Board, "MCU: ESP32");
  #endif

  #if !defined(TEENSYDUINO)&& !defined(ESP32)&& !defined(__DUE__)&& !defined(ESP8266)&& !defined(ARDUINO_ARCH_STM32)&& defined(ARDUINO)
     ClaveBoard=6;
     sprintf(Board, "MCU: Arduino MEGA/UNO");
  #endif
}