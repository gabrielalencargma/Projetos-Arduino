void setup()
{
  // Configurando o pino 13 (usando a constante "LED_BUILTIN") como saída para o funcionamento do led RGB.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH); // Ativando o pino "LED_BUILTIN".
  delay(1000); // Pausa de 1000 milisegundos.
  digitalWrite(LED_BUILTIN, LOW); // Desativando o pino "LED_BUILTIN".
  delay(1000); // Pausa de 1000 milisegundos.
}