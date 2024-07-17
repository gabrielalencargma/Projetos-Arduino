// Importando a biblioteca do LCD I2C.
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32,16,2); // Configurando o LCD;

// Declarando a variável dos componentes que recebem o número dos pinos digitais.
int led = 10;
int alarme = 9;
int botaoPorta = 0;
int botaoJanela = 1;


int sensorLuz = 0; // Declarando a variável "sensorLuz".
int sensorMovimento = 0; // Declarando a variável "sensorMovimento".

// Declarando a váriável "estaDentro" inicialmente como falsa.
bool estaDentro = false;

void setup()
{
  // Configurando os pinos digitais para o funcionamento dos componentes.
  pinMode(led, OUTPUT);
  pinMode(alarme, OUTPUT);
  pinMode(botaoPorta, INPUT);
  pinMode(botaoJanela, INPUT);
  lcd.begin(16,2); // Definindo a quantidade de linhas e colunas do LCD.
  lcd.backlight(); // Habilitando o backlight.
  lcd.init(); // Iniciando o LCD.
  lcd.clear(); // Limpando as mensagens do LCD.
}

// Função para ligar alarme e led.
void alarmeLigado()
{
  digitalWrite(led, HIGH);
  /* Definindo a frequência do alarme para cada
  sensorização (movimento, porta e janela). */
  if(sensorMovimento > 100) {
    tone(alarme, 1600); // Se um movimento for detectado, o alarme produzirá um tom de 1600Hz.
  } else if(digitalRead(botaoPorta) == 0) {
    tone(alarme, 1450); // Se a porta for aberta, o alarme produzirá um tom de 1450Hz.
  } else {
  	tone(alarme, 1200); // Se a janela for aberta, o alarme produzirá um tom de 1200Hz.
  }
}

// Função para desligar alarme e led.
void alarmeDesligado()
{
  digitalWrite(led, LOW);
  noTone(alarme);
}

// Função para printar uma mensagem no LCD.
void mensagemLCD(int msg){
 // Verificando o valor de "msg" para escolher a mensagem.
  switch(msg){
    case 0:
    	lcd.setCursor (0, 0); // Selecionando coluna 1 e linha 1.
      	lcd.print("Alerta inativo, "); // Print da mensagem no cursor selecionado.
    	lcd.setCursor (0, 1); // Selecionando coluna 1 e linha 2.
    	lcd.print("manha           "); // Print da mensagem no cursor selecionado.
    	break;
    case 1:
    	lcd.setCursor (0, 0);
      	lcd.print("Alerta ativo,   ");
    	lcd.setCursor (0, 1);
    	lcd.print("noite           ");
    	break;
    case 2:
    	lcd.setCursor (0, 0);
      	lcd.print("Porta aberta!   ");
    	lcd.setCursor (0, 1);
    	lcd.print("                ");
    	break;
    case 3: 
    	lcd.setCursor (0, 0);
      	lcd.print("Janela aberta!  ");
    	lcd.setCursor (0, 1);
    	lcd.print("                ");
    	break;
    case 4:
    	lcd.setCursor (0, 0);
      	lcd.print("Movimento       ");
    	lcd.setCursor (0, 1);
    	lcd.print("detectado!      ");
    	break;
  }
}

void loop()
{
  // "sensorLuz" recebe o valor da entrada analógica A0.
  sensorLuz = analogRead(A0);
  // "sensorMovimento" recebe o valor da entrada analógica A1.
  sensorMovimento = analogRead(A1);
  
  /* Se o valor de "sensorLuz" estiver acima de 508 (noite),
  o sistema de segurança ficará ativo */
  if(sensorLuz > 508) {
    mensagemLCD(1); // Chamando a função para printar a mensagem 1 no lcd.
    
    // Enquanto a porta estiver aberta...
    while(digitalRead(botaoPorta) == 0) {
      estaDentro = true; // A variável "estaDentro" será verdadeira, pois há um intruso dentro.
      alarmeLigado(); // Chamando a função para ligar alarme e led.
      mensagemLCD(2); // Chamando a função para printar a mensagem 2 no lcd.
    }
    
    // Enquanto a janela estiver aberta...
    while(digitalRead(botaoJanela) == 0) {
      estaDentro = true; // A variável "estaDentro" será verdadeira, pois há um intruso dentro.
      alarmeLigado(); // Chamando a função para ligar alarme e led.
      mensagemLCD(3); // Chamando a função para printar a mensagem 3 no lcd.
    }
    
    // Se a variável "estaDentro" for verdadeira e um movimento for detectado, então...
    if(estaDentro == true && sensorMovimento > 100) {
      alarmeLigado(); // Chamando a função para ligar alarme e led.
      mensagemLCD(4); // Chamando a função para printar a mensagem 4 no lcd.
      delay(4000); // Pausa de 4000 milisegundos.
  	}
    
    alarmeDesligado(); // Chamando a função para desligar alarme e led.
  } else {
    estaDentro = false; // A variável "estaDentro" voltará a ser falsa.
    alarmeDesligado(); // Chamando a função para desligar alarme e led.
    mensagemLCD(0); // Chamando a função para printar a mensagem 0 no lcd.
  }
}