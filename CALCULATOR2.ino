// Calculator 2
// By: Diego J. Graham
// Uses a membrane switch to take input from the user, an lcd to display the input, 
// and allows the user to add, subtract, multiply, and divide any 2 intigers.
// Displays the result as a float.
////////////////////////////////////////////////////////////////////////////////////

// Initialize the Keypad
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','+'},  // A = addition
  {'4','5','6','-'},  // B = subtraction
  {'7','8','9','C'},  // C = clear
  {'*','0','=','/'}   // D = equals
};

byte rowPins[ROWS] = {25, 26, 29, 30}; 
byte colPins[COLS] = {33, 34, 37, 38}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
////////////////////////////////////////////////////////////////////////////////////////////////

// Initialize the lcd
# include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
////////////////////////////////////////////////////////////////////////////////////////////////

// set the variables for the calculator and initialize the buzzer
String input = "";
float num1 = 0, num2 = 0;
char op = '\0';
bool isNum1 = false;
bool isNum2 = false; 
float result;
const int buzzer = 5;
///////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Calculator Ready");
  delay(1000);
  lcd.clear();
}
////////////////////////////////////////////////////////////////////////////////////////////////


// Main Function
void loop() {
  char key = customKeypad.getKey();
    if (key == 'C') {
      clear();
    } 
    if (!isNum1) {
      getNum1();
    } 
    if (!isNum2) {
      getNum2();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////


// Function to get the first number and the opperation
void getNum1(){
  char key = customKeypad.getKey();
  if (isDigit(key)){
    button_beep();
    input += key;
    lcd.print(key);
    Serial.print(key);
  }
  if (key == '+' || key == '-' || key == '*' || key == '/'){
    button_beep();
    op = key;
    num1 = input.toFloat();
    lcd.print(op);
    isNum1 = true;
    input = "";
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////


// A function to get the second
void getNum2(){
  char key = customKeypad.getKey();
  if (isDigit(key)){
    button_beep();
    input += key;
    lcd.print(key);
    Serial.println(key);
  }
  if (key == '='){
    button_beep();
    lcd.print(key);
    isNum2 = true;
    num2 = input.toFloat();
    input = "";
    evaluate();
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////


// A function to clear the memory on the calculator
void clear(){
  char key = customKeypad.getKey();
  button_beep();
  num2 = 0;
  num1 = 0;
  op = '\0';
  input = "";
  lcd.clear();
  lcd.setCursor(0,0);
  isNum1 = false;
  isNum2 = false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////


// A function to evaluate num1 and num2 with the chosen opperator
void evaluate(){
  lcd.setCursor(0,1);
  switch (op) {
    case '+':
      result = num1+num2;
      break;
    case '-':
      result = num1-num2;
      break;
    case '*':
      result = num1*num2;
      break;
    case '/':
      if (num2 == 0){
        lcd.print("ERROR");
        break;
      }
      else{
        result = num1/num2;
        break;
      }
  }
  lcd.print(result);
}
////////////////////////////////////////////////////////////////////////////////////////////////////


// A function to make a beeping noise when a key is pressed
void button_beep(){
  tone(buzzer, 700);
  delay(250);
  noTone(buzzer);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////














