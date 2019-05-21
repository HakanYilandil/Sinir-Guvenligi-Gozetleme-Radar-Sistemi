#include <Servo.h>. //servo kütüphanesi çağırma

// Ultrasonik Sinyal pinleri
const int trigPin = 10;
const int echoPin = 11;

long duration; //32 bitlik değişken tanımlama
int distance; //tam sayı değişkeni tanımlama

Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT); //Fonksiyon pini çıkış
  pinMode(echoPin, INPUT);  //Fonksiyon pini giriş
  Serial.begin(9600);  //Seri haberleşmede fonksiyonun iletişim hızı ayarı
  myServo.attach(12); // Servo motor sinyal pini
}
void loop() {
  // 15 derece ile 165 derece arasında dön
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30); // Bekleme süresi belirleme
  distance = calculateDistance();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  }
  
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
int calculateDistance(){ 
   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
