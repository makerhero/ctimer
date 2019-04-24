/**
 *  Programa de teste para a classe cTimer
 *  Conecte LEDs aos pinos GPIO 8, 9 e 10.
 *  
 */
#include "ctimer.h"

#define LED0  8
#define LED1  9
#define LED2  10

cTimer  g_Timer0(true);
cTimer  g_Timer1(true);
cTimer  g_Timer2(true);

// Defina aqui os tempos em ms para cada LED piscar:
#define   TEMPO_0   100
#define   TEMPO_1   275
#define   TEMPO_2   717


bool    gLed0 = false;
bool    gLed1 = false;
bool    gLed2 = false;


void setup() {
  pinMode(LED0, OUTPUT);
  digitalWrite(LED0, 0);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, 0);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, 0);

  g_Timer0.SetTimeOut(TEMPO_0);
  g_Timer1.SetTimeOut(TEMPO_1);
  g_Timer2.SetTimeOut(TEMPO_2);
  
}


void loop() {
  if(g_Timer0.IsTimeOut(true))
  {
    digitalWrite(LED0, gLed0);
    gLed0 = !gLed0;  
  }

  if(g_Timer1.IsTimeOut(true))
  {
    digitalWrite(LED1, gLed1);
    gLed1 = !gLed1;  
  }

  if(g_Timer2.IsTimeOut(true))
  {
    digitalWrite(LED2, gLed2);
    gLed2 = !gLed2;  
  }

  /*
   * Faca aqui o que voce quiser... 
   * 
   */

  }
 
