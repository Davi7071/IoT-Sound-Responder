#define Microphone 15
#include <ESP32Servo.h>

const int servoPin = 18;
const int ledPin = 2;
const int buzzerPin = 4;

Servo servo;
int lastState = HIGH;
int lastState2 = LOW;
int value;
int contvalue = 0;
int pos = 0;

// Notas do Buzzer
#define NOTE_C4  262
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_G3  196

void setup() {
  servo.attach(servoPin, 500, 2400);  
  Serial.begin(115200);
  delay(1000);
  pinMode(Microphone, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
  servo.write(pos);

  Serial.println("Digite a palavra-chave (ex: ligar):");
}

void loop() {
  // Simula BLE.
  //Como o WOKIWI não suporta envio de arquivos ou recebimento, tivemos que apenas simular a comunicação
  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "ligar") {
      Serial.println("Comando 'ligar' recebido.");
      motorvibration();
      pos = 0;
      servo.write(pos);
      contvalue = 0;
    } else {
      Serial.println("Comando não reconhecido.");
    }
  }

  microphone();
} 

void motorvibration() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  playMarioTheme();

  for (pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(1);
  }

  delay(300);
}

void playMarioTheme() {

  tone(buzzerPin, NOTE_E4, 150);
  delay(150);
  tone(buzzerPin, NOTE_E4, 150);
  delay(150);
  tone(buzzerPin, 0, 100);  // pausa
  delay(100);

  tone(buzzerPin, NOTE_E4, 150);
  delay(150);
  tone(buzzerPin, 0, 100);
  delay(100);

  tone(buzzerPin, NOTE_C4, 150);
  delay(150);
  tone(buzzerPin, NOTE_E4, 150);
  delay(150);
  tone(buzzerPin, NOTE_G4, 300);
  delay(300);

  tone(buzzerPin, 0, 100);
  delay(100);

  tone(buzzerPin, NOTE_G3, 300);
  delay(300);

  noTone(buzzerPin);
}

void microphone() {
  int sample = analogRead(Microphone);
  if (sample < 2052) {
    value = 0;
  } else {
    value = (sample - 2047) * 10;
  }

  Serial.print("Value: ");
  Serial.println(value);
  
  if (value > 500) {
    contvalue++;
  }

  if (contvalue >= 5) {
    Serial.println("Som detectado! Executando ação.");
    motorvibration();
    pos = 0;
    servo.write(pos);
    contvalue = 0;
  } else {
    delay(180);
  }
}