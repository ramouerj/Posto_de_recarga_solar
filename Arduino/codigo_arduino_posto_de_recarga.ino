#include <math.h>					// Biblioteca de funções matemáticas para utilizar a função seno
#include <stdio.h>					// Biblioteca padrão do C
#include <stdlib.h>					// **

float Ts = 10e-4; 					// Definição de variáveis
float Fs = 1 / Ts;
int T_sim = 1;
int L = ceil(T_sim / Ts);
int pino_arduino = 8;      

void setup() {

  pinMode(pino_arduino, OUTPUT);			// Definição da função do pino escolhido (output ou input)
  Serial.begin(9600);					// Inicialização do monitor serial
}

void loop() {
							// Declaração de matrizes unidimensionais para fazer os cálculos  
  float trig1[L];
  float trig2[L];
  float trig[L];
  float trig_n[L];
  float vref[L];
  float cmd[L];
  float v[L];
  							// Definição do valor da primeira posição das matrizes em questão
  trig1[0] = 0;
  trig2[0] = 0;
  							// É preciso fazer o cálculo de cada ponto das matrizes, então foi utilizado o FOR para repetir o código, porém com os indices alterados
  for (int k=1;k<L;k++){
    
    v[k] = 0.4 * sin(2 * M_PI * Ts * k);
    
    trig1[k] = trig1[k-1] + 1; //OK
    
    if (trig1[k] > 100){
      trig1[k] = 1;
    }

    trig2[k] = 100 - trig1[k];

    if (trig1[k] < 50){
      trig[k] = trig1[k];
    }
    else{
      trig[k] = trig2[k];
    }
    
    trig_n[k] = trig[k] / 50;
    
    vref[k] = 0.5 + v[k];
    
    if(vref[k] > trig_n[k]){
      cmd[k] = 1;
    }
    else{
      cmd[k] = 0;
    }
  						 // Condição para ligar ou desligar a porta pwm do arduino, se o valor da posição da matriz CMD foi 1, liga. Senão, desliga.
    if(cmd[k] == 0){
      digitalWrite(pino_arduino, LOW);
      }
    else if (cmd[k] == 1){
      digitalWrite(pino_arduino, HIGH);
      }
			
  Serial.println(cmd[k]);			// Mostrar o valor da posição da matriz CMD no monitor serial
  delay(20);					// Delay de 20 ms para visualizar melhor o efeito no LED
  }
  
  
}