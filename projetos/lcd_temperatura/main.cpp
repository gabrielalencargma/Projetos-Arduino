// Importando a biblioteca do LCD I2C.
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(32,16,2); // Configurando o LCD.

float valor = 0; // Declarando a variável "valor".
float temperatura = 0; // Declarando a variável "temperatura".

void setup()
{
  lcd.begin(16,2); // Definindo a quantidade de linhas e colunas do LCD.
  lcd.backlight(); // Habilitando o backlight.
  lcd.init(); // Iniciando o LCD.
  lcd.clear(); // Limpando as mensagens do LCD.
}

void loop()
{
  // "valor" recebe o valor da entrada analógica A0.
  valor = analogRead(A0); 
 
  // "temperatura" recebe o resultado do cálculo que transforma "valor" em graus célsius.
  temperatura = (valor * (5.0 / 1024.0) -.5) * 100;
  
  lcd.setCursor(0,0); // Selecionando coluna 1 e linha 1.
  lcd.print("Temperatura: "); // Print da mensagem no cursor selecionado.
  lcd.setCursor(0,1); // Selecionando coluna 1 e linha 2.
  lcd.print(temperatura); // Print da temperatura no cursor selecionado.
  delay(3000); // Pausa de 2 segundos.
  lcd.clear(); // Limpando as mensagens do LCD.
}