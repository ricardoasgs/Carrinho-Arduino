#include <LiquidCrystal.h> //Inclui a biblioteca do LCD
LiquidCrystal lcd(14,15,16,17,18,19); //Configura os pinos do Arduino para se comunicar com o LCD
#include <Ultrasonic.h>
//trigger,echo
Ultrasonic ultrasonic(8,9);
//carrinho.
 int Entrada1 = 2; 
int Entrada2 = 3; 
int Entrada12 = 4; 
int Entrada22 = 5;
int buz =6;
int farol = 7;
int lre =10;
//sensor.
long microsec = 0;
float distanciaCM = 0;
// recebe o valor do BT. 
char c;
//LDR.
int sensor = 0; //Pino analógico em que o sensor está conectado.
int valorSensor = 0; //Usada para ler o valor do sensor em tempo real.

void setup() 
{

Serial.begin(9600); 
 pinMode(Entrada1, OUTPUT); 
 pinMode(Entrada2, OUTPUT);
 pinMode(Entrada12, OUTPUT); 
 pinMode(Entrada22, OUTPUT); 
 pinMode(farol, OUTPUT); 
 pinMode(buz, OUTPUT); 
 pinMode(lre, OUTPUT);
 
 
lcd.begin(16, 2); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)
lcd.setCursor(2, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("CCP - Unisal"); //Escreve no LCD 
lcd.setCursor(3, 1); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("#Sucesso !"); //Escreve no LCD 
para();


}

void loop() 
{
 int valorSensor = analogRead(sensor); // Lê o valor da luminosidade. 
 
 float cmMsec, inMsec; 
 
 //Le os dados do sensor, com o tempo de retorno do sinal. 
 long microsec = ultrasonic.timing(); 
 
 //Calcula a distancia em centimetros. 
 cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

 c=Serial.read();
 
 // verifica a luminosidade do ambiente.
 if (valorSensor < 200) {
 digitalWrite(farol, HIGH);
 
 }
 else {
 digitalWrite(farol, LOW);
 
 }
 
 //verifica a distancia e os comandos.
 if ((cmMsec<=40)){
 digitalWrite(buz, HIGH);
 delay(75);
 digitalWrite(buz, LOW);
 delay(75);
 }
 
 if(c=='a'){
 frente(); 
 }
 
 else if(c=='b'){
 para();
 }
 
 else if(c=='c'){
 tras();
 }
 
 else if(c=='e'){
 esquerda();
 }

 else if(c=='d'){
 direita(); 
 }
 
 
 else if(c=='z'){
 digitalWrite(buz, HIGH); 
 }
 
 else if(c=='o'){
 digitalWrite(buz, LOW); 
 }
 
 

} 
void frente() {
digitalWrite(Entrada1, HIGH); 
digitalWrite(Entrada2, LOW); 
digitalWrite(Entrada12, HIGH); 
digitalWrite(Entrada22, LOW); 
} 
void tras() {
digitalWrite(Entrada1, LOW); 
digitalWrite(Entrada2, HIGH); 
digitalWrite(Entrada12, LOW); 
digitalWrite(Entrada22, HIGH); 
digitalWrite(lre, HIGH); 
}
void para() {
digitalWrite(Entrada1, LOW); 
digitalWrite(Entrada2, LOW); 
digitalWrite(Entrada12, LOW); 
digitalWrite(Entrada22, LOW); 
digitalWrite(lre, LOW); 
}
void direita() {
 digitalWrite(Entrada1, HIGH); 
 digitalWrite(Entrada2, LOW); 
 digitalWrite(Entrada12, LOW); 
 digitalWrite(Entrada22, LOW); 
}
void esquerda() {
 digitalWrite(Entrada1, LOW); 
 digitalWrite(Entrada2, LOW); 
 digitalWrite(Entrada12, HIGH); 
 digitalWrite(Entrada22, LOW); 
}
