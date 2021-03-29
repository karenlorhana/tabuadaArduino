/* Tabuada Subtração*/

// incluindo as bibliotecas 
#include <Keypad.h> //biblioteca do teclado matricial
#include <LiquidCrystal.h> // biblioteca do display
 
// definições do teclado
const byte numLinhas= 4; //numero de linhas do teclado
const byte numColunas= 4; //numero de colunas do teclado
//criando um array com os valores referentes a cada teclada
char mapaTeclado[numLinhas][numColunas]=
{
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
 };
byte pinosLinhas[numLinhas] = {9,8,7,6}; //definindo os pinos das linhas
byte pinosColunas[numColunas]= {13,12,11,10}; //definindo os pinos das colunas
// enviando as informações dos pinos e dos valores do teclado para a biblioteca dele
Keypad TecladoMatricial= Keypad(makeKeymap(mapaTeclado), pinosLinhas, pinosColunas, numLinhas, numColunas);
 
//definindo os pinos do display LCD
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);


void setup() {
 lcd.begin(16, 2); //Incia o display LCD
 randomSeed(analogRead(7));//Inicia o gerador de números aleatórios
 lcd.setCursor(6, 0);
 lcd.print("For");
 lcd.setCursor(5, 1);
 lcd.print("Girls");
 delay(2000);
}
 
void loop() {
 lcd.clear();//apagando tudo do display
 lcd.setCursor(0, 0);
 //Escolhe dois números e os exibe no LCD
 int num1 = random(2, 11);
 int num2 = random(2, 11);
 int resultado = num1 - num2;
 lcd.print(String(num1) + " - " + String(num2) + " = ");
 // Esperando a resposta do usuário e digitar o resultado
 int resposta = valorLido().toInt(); //recebe um valor no char e converte para o tipo String
 lcd.setCursor(0, 1);
 // Se o valor digitado for igual ao resultado da mutiplicação
 if (resultado == resposta){
 lcd.print("Voce acertou!");

}
 else {
 // se não for igual ao resultado da multiplicação
 lcd.print("Errou... R: " + String(resultado));
 }
 resposta = valorLido().toInt(); //Apenas esperando pressionar qualquer tecla para continuar
}
 
//Entra aqui quando é pressionado o "#"
//Recebe os valores do teclado e os imprime na tela e retorna para a função anterior o valor recebido
String valorLido(){
 String valorDigitado = "";
 char teclaPressionada = TecladoMatricial.getKey();
 while (teclaPressionada != '#'){
 teclaPressionada = TecladoMatricial.getKey();
 if ((teclaPressionada != NO_KEY) && (teclaPressionada != '#')) {
 valorDigitado.concat(teclaPressionada);// concatena os valores que recebe com os já recebidos anteriormente
 lcd.print(teclaPressionada);
 } 
 } 
 return(valorDigitado); // retorna o valor digitado para a função anterior
 }
