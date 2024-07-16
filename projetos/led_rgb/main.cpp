void setup()
{
  // Configurando o pino 13 como saída para o funcionamento do led RGB.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH); // Ativando "LED_BUILTIN".
  delay(1000); // Pausa de 1000 milisegundos.
  digitalWrite(LED_BUILTIN, LOW); // Desativando "LED_BUILTIN".
  delay(1000); // Pausa de 1000 milisegundos.
}