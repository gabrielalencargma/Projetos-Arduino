// Declaração da variável dos leds, recebendo o número da saída digital.
int ledVermelho = 2;
int ledVerde = 3;
int ledAzul = 4;

// Declaração da variável "intensidade_luz".
int intensidade_luz = 0;

void setup()
{
  Serial.begin(9600); // Inicialização do monitor serial.
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop()
{
  // "intensidade_luz" recebe o valor da entrada analógica A0.
  intensidade_luz = analogRead(A0); // A0 recebe o valor do fotoresistor.
  
  // Impressão do valor de "intensidade_luz" no monitor serial.
  Serial.println(intensidade_luz);
  
  if(intensidade_luz >= 600) {
    // Acendimento do led vermelho e desligamento dos outros leds.
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW); 
    digitalWrite(ledAzul, LOW); 
  } else if(intensidade_luz >= 400) {
    // Acendimento do led verde e desligamento dos outros leds.
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH); 
    digitalWrite(ledAzul, LOW); 
  } else {
  	// Acendimento do led azul e desligamento dos outros leds.
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW); 
    digitalWrite(ledAzul, HIGH); 
  }
}