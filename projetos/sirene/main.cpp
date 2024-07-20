void setup()
{
  // Configurando os pinos 6 e 7 como saída para o funcionamento dos leds.
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  azul(); // Chamando a função "azul()".
  vermelho(); // Chamando a função "vermelho()".
}

// Função para ligar o led azul e sua frenquência de alarme.
void azul(){
  digitalWrite(6, 1); // Ativando o pino 6.
  tone(4, 800); // Ativando o alarme no pino 4 com a frenquência 800Hz.
  delay(500); // Pausa de 500 milisegundos.
  digitalWrite(6, 0); // Desativando o pino 6.
}

// Função para ligar o led vermelho e sua frenquência de alarme.
void vermelho(){
  digitalWrite(7, 1); // Ativando o pino 7.
  tone(4, 400); // Ativando o alarme no pino 4 com a frenquência 400Hz.
  delay(500); // Pausa de 500 milisegundos.
  digitalWrite(7, 0); // Desativando o pino 7.
}