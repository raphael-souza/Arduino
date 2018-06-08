// Pinos conectados ao Step
int pino_passo = 5;
int pino_direcao = 6;
int onOff = 7;
int direcao = 1;

// Quantidade de passos para uma volta completa
// Ajuste de acordo com o seu motor
int passos_motor = 360;

void setup() 
{
  // Define os pinos como saida
  pinMode(pino_passo, OUTPUT);
  pinMode(pino_direcao, OUTPUT);
  pinMode(onOff, OUTPUT);
}

void loop()
{
  // Define a direcao de rotacao
  direcao = 1;
  digitalWrite(onOff,LOW);
  digitalWrite(pino_direcao, direcao);
 
    digitalWrite(pino_passo, 1);
    delayMicroseconds(3);
    digitalWrite(pino_passo, 0);
    
    // delayMricroseconds funciona apenas acima de 380 com facilidade
    //valores menores apresentam perda de torque
    delay(1); // valor de 65 micro segundos 
  
}
