## Funcionamento

O circuito funciona da seguinte maneira:

- O sistema de alarme estará ativo apenas à noite;
  - Quando for de manhã, o LCD mostrará a mensagem: **"Alerta inativo, manha"**;
  - Quando for de noite, o LCD mostrará a mensagem: **"Alerta ativo, noite"**.
- Ao abrir uma porta/janela, será alertado continuamente até que ela seja fechada;
  - Para a porta, o alarme terá uma frenquência de **1450Hz** e será exibida a seguinte mensagem no LCD: **"Porta aberta!"**;
  - Para a janela, o alarme terá uma frenquência de **1200Hz** e será exibida a seguinte mensagem no LCD: **"Janela aberta!"**.
- Quando uma porta/janela for aberta, o sensor de movimento será ativado e alertará por 4 segundos a cada vez que detectar algo.
  - Para o sensor de movimento, o alarme terá uma frequência de **1600Hz** e será exibida a seguinte mensagem no LCD: **"Movimento detectado!"**.

## Componentes

Foram utilizados os seguintes componentes na montagem do circuito:

- 1 Arduino Uno R3;
- 1 LCD 16x2 I2C;
- 1 Piezo;
- 1 Led Vermelho;
- 2 Botões;
- 1 Sensor PIR;
- 1 Fotoresistor;
- 5 Resistores.
  - Led: **100Ω**;
  - Piezo, Botões, Sensor PIR e Fotoresistor: **1kΩ**.
  
