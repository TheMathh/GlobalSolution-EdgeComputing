// -----------------------------------------------
// FIAP — Edge Computing & Computer Systems
// Projeto: OrbitalWatch - Monitoramento de Satélite
//
// Integrantes:
//   Mateus Alves Borges        RM 571424
//   Arthur de Sá               RM 569526
//   Anthony Leal Monteiro      RM 569616
//   Gustavo Bidin              RM 570272
// -----------------------------------------------

#include <LiquidCrystal_I2C.h>

// ── Pinos 
#define PIN_NTC     A1
#define PIN_LDR     A0
#define PIN_BUTTON  6

#define PIN_LED_G   8
#define PIN_LED_Y   9
#define PIN_LED_R   10
#define PIN_BUZZER  7

LiquidCrystal_I2C lcd(0x27, 16, 2);


// ── Limites temperatura satélite 
#define TEMP_OK_MIN   -20.0
#define TEMP_OK_MAX    50.0

#define TEMP_ALT_MIN  -40.0
#define TEMP_ALT_MAX    70.0


// ── Limites luminosidade 
#define LUZ_OK_MAX    30.0
#define LUZ_ALT_MAX   70.0


// ── Buzzer 
bool buzzerLigado = false;
unsigned long buzzerInicio = 0;
const unsigned long BUZZER_MS = 3000;


// ── Amostras LDR 
const int N_AMOSTRAS = 3;


// ================================================

float lerTemperaturaNTC();
int avaliaStatus(float val, float okMin, float okMax, float altMin, float altMax);
void atualizaLEDs(int status);
void exibeBloco(const char* linha0, float valor, const char* unidade, const char* rotulo);


// ================================================

void setup() {

  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_Y, OUTPUT);
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  pinMode(PIN_BUTTON, INPUT_PULLUP);

  Serial.begin(9600);


  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("OrbitalWatch");
  lcd.setCursor(0,1);
  lcd.print("Iniciando...");

  delay(2000);
  lcd.clear();
}



// ================================================

void loop() {


  // Leitura luminosidade 

  long soma = 0;

  for(int i=0;i<N_AMOSTRAS;i++){
    soma += analogRead(PIN_LDR);
    delay(50);
  }

  float ldrMedio = soma / (float)N_AMOSTRAS;

  float luz = map((long)ldrMedio, 1023, 0, 0, 100);



  // Leitura temperatura NTC 

  float temp = lerTemperaturaNTC();



  // Simulação sinal satélite 

  bool sinal = digitalRead(PIN_BUTTON) == LOW;



  int stTemp = avaliaStatus(
    temp,
    TEMP_OK_MIN,
    TEMP_OK_MAX,
    TEMP_ALT_MIN,
    TEMP_ALT_MAX
  );


  int stLuz =
    (luz <= LUZ_OK_MAX) ? 0 :
    (luz <= LUZ_ALT_MAX) ? 1 : 2;



  int stSinal = sinal ? 0 : 2;



  int stGeral = max(stTemp, max(stLuz, stSinal));



  // LEDs

  atualizaLEDs(stGeral);



  // Buzzer se perder sinal 

  if(stGeral == 2 && !buzzerLigado){

    buzzerLigado = true;
    buzzerInicio = millis();

    digitalWrite(PIN_BUZZER,HIGH);
  }


  if(buzzerLigado && millis()-buzzerInicio >= BUZZER_MS){

    buzzerLigado=false;
    digitalWrite(PIN_BUZZER,LOW);
  }



  //LCD Temperatura 

  const char* msgTemp =
    (stTemp==0) ? "Temp: OK" :
    (temp>TEMP_OK_MAX) ? "Temp ALTA" :
                         "Temp BAIXA";


  exibeBloco(msgTemp,temp,"C","Temp");
  delay(1500);



  // LCD Sinal 

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print(sinal ? "Sinal OK" : "Sem Sinal");

  lcd.setCursor(0,1);
  lcd.print("Satelite");

  delay(1500);



  // LCD Luz

  const char* msgLuz =
    (stLuz==0) ? "Luz OK" :
    (stLuz==1) ? "Meia Luz" :
                 "Luz Alta";


  exibeBloco(msgLuz,luz,"%","Luz");

  delay(1500);



  Serial.print("Temp=");
  Serial.print(temp);

  Serial.print("C Luz=");
  Serial.print(luz);

  Serial.print("% Sinal=");
  Serial.println(sinal ? "OK" : "PERDIDO");

}


float lerTemperaturaNTC(){

  int leitura = analogRead(PIN_NTC);


  float temperatura = map(
    leitura,
    0,
    1023,
    100,
    -40
  );


  return temperatura;
}


int avaliaStatus(
float val,
float okMin,
float okMax,
float altMin,
float altMax
){

  if(val >= okMin && val <= okMax)
    return 0;

  if(val >= altMin && val <= altMax)
    return 1;

  return 2;
}


void atualizaLEDs(int status){

  digitalWrite(PIN_LED_G,status==0 ? HIGH:LOW);

  digitalWrite(PIN_LED_Y,status==1 ? HIGH:LOW);

  digitalWrite(PIN_LED_R,status==2 ? HIGH:LOW);

}



void exibeBloco(
const char* linha0,
float valor,
const char* unidade,
const char* rotulo
){

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print(linha0);

  lcd.setCursor(0,1);

  lcd.print(rotulo);
  lcd.print(": ");

  lcd.print(valor,1);

  lcd.print(unidade);
}