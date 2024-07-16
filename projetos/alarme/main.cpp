// Declarando a variável "i" com o valor 100.
int i = 100;

void setup()
{
  // Configurando o pino 10 como saída para o funcionamento do led.
  pinMode(10, OUTPUT);
  Serial.begin(9600); // Iniciando do monitor serial.
  
  // Estrutura while para contar "i" até 1200.
  while(i < 1200){
    i = i + 1; // Acrescentanto 1 ao valor de "i".
    Serial.println(i); // Print do valor de "i" no monitor serial.
    // Ativando o alarme no pino 7 com a frenquência igual ao valor de "i".
    tone(7, i); 
  }
}

void loop()
{
  digitalWrite(10, 1); // Ativando o pino 10;
}