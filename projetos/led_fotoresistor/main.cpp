// Declarando a variável dos leds com o número dos pinos digitais.
int ledVermelho = 2;
int ledVerde = 3;
int ledAzul = 4;

// Declarando a variável "intensidade_luz".
int intensidade_luz = 0;

void setup()
{
  Serial.begin(9600); // Iniciando do monitor serial.
  // Configurando os pinos 2, 3 e 4 como saída para o funcionamento dos leds.
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop()
{
  // "intensidade_luz" recebe o valor da entrada analógica A0.
  intensidade_luz = analogRead(A0);
  
  // Print do valor de "intensidade_luz" no monitor serial.
  Serial.println(intensidade_luz);
  
  if(intensidade_luz >= 600) {
    // Acendendo o led vermelho e desligando os outros leds.
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW); 
    digitalWrite(ledAzul, LOW); 
  } else if(intensidade_luz >= 400) {
    // Acendendo o led verde e desligando os outros leds.
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH); 
    digitalWrite(ledAzul, LOW); 
  } else {
  	// Acendendo o led azul e desligando os outros leds.
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW); 
    digitalWrite(ledAzul, HIGH); 
  }
}