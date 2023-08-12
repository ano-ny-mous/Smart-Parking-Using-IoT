#define BLYNK_PRINT DebugSerial
#include <SoftwareSerial.h>
#include <BlynkSimpleStream.h>
#include <ESP8266WiFi.h>
SoftwareSerial DebugSerial(0,1);

const char* ssid = "yourNetworkName";
const char* password = "yourNetworkPassword";
int trig = 2;
int echo = 3;
long lecture_echo;
long cm;

// You should get Auth Token in the Blynk
char auth[] = "xxxxxxxxxxxxx";
WidgetLCD lcd(V1);
WidgetLED led1(V5);
WidgetLED led2(V6);
WidgetLED led3(V7);
WidgetLCD lcd1(V8);

void setup() 
{
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
   }
  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial,auth);
  pinMode(trig,OUTPUT);
  digitalWrite(trig,LOW);
  pinMode(echo,INPUT);
  lcd.clear();
}

void loop() 
{
  lcd.clear();
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  lecture_echo = pulseIn(echo,HIGH);
  cm = lecture_echo/58;
  delay(50);
  lcd.print(1,1,cm);
  Blynk.virtualWrite(1,cm);
    if (cm <= 50 and cm>=10) {
    Blynk.virtualWrite(2, 255);
    led2.on();
    lcd1.clear();
    lcd1.print(0,0,"Slot Not");
    lcd1.print(1,1,"Available");
  }
  else {
    Blynk.virtualWrite(2, 0);
    led2.off();
  }
  if (cm>50) {
    Blynk.virtualWrite(3, 255);
    led1.on();
    lcd1.clear();
    lcd1.print(0,0,"Slot Available");
  }
  else {
    Blynk.virtualWrite(3, 0);
    led1.off();
  }
  if (cm<10) {
    Blynk.virtualWrite(2, 255);
    Blynk.virtualWrite(3, 165);
    Blynk.virtualWrite(4, 0);
    led3.on();
    lcd1.clear();
    lcd1.print(0,0,"Obstacle in");
    lcd1.print(1,1,"Between");
  }
  else {
    Blynk.virtualWrite(4, 0);
    led3.off();
  }
  Blynk.run();  
  delay(1000);
}
