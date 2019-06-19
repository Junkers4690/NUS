/* Mateusz Janusz, Wojciech Domański, Jan Wyrwicz 2019 */

#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
  #define X_CS_PIN         53
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
  #define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
  #define Z_CS_PIN         40
#endif



int i=0;
bool kier=0;
void setup() {
  Serial.begin(115200);
  
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, kier);

  pinMode(X_STEP_PIN, OUTPUT);

  pinMode(X_MAX_PIN, INPUT_PULLUP);
  
  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, kier);

  pinMode(Y_STEP_PIN, OUTPUT);

  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  
  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
   
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, kier);

  pinMode(Z_STEP_PIN, OUTPUT);

  pinMode(Z_MAX_PIN, INPUT_PULLUP);
}

void loop() {
Serial.println(digitalRead(X_MAX_PIN));
Serial.println(digitalRead(Y_MAX_PIN));
Serial.println(digitalRead(Z_MAX_PIN));

if(digitalRead(X_MAX_PIN)==LOW){
digitalWrite(X_STEP_PIN,HIGH);
}
if(digitalRead(Y_MAX_PIN)==LOW){
digitalWrite(Y_STEP_PIN,HIGH);
}
if(digitalRead(Z_MAX_PIN)==LOW){
digitalWrite(Z_STEP_PIN,HIGH);
}
delay(5);
digitalWrite(X_STEP_PIN,LOW);
digitalWrite(Y_STEP_PIN,LOW);
digitalWrite(Z_STEP_PIN,LOW);
delay(5);




i++;
if(i==199)
{
  kier=!kier;
digitalWrite(X_DIR_PIN, kier);
digitalWrite(Y_DIR_PIN, kier);
digitalWrite(Z_DIR_PIN, kier);
i=0;
}
}
