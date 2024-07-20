void setup()
{
  // Configurando o pino 10 como saída para o funcionamento do led.
  pinMode(10, OUTPUT);
  Serial.begin(9600); // Iniciando do monitor serial.
  
  // Estrutura for para contar "i" até 1200.
  for(int i=100; i<=1200; i++) {
    Serial.println(i); // Print do valor de "i" no monitor serial.
    tone(7, i); // Ativando o alarme no pino 7 com a frenquência igual ao valor de "i".
  }
}

void loop()
{
  digitalWrite(10, 1); // Ativando o pino 10.
}