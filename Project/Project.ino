#include <dht11.h>

#define DHT11PIN 12
dht11 DHT11;

int buzzer = 7;
int flame_sensor = 2;
int flame_detected;

int MQ2pin =A3;
int mq2pin=10;
float sensorValue;

void setup()

{

  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(flame_sensor, INPUT);
  Serial.println("MQ2 warming up!");
	delay(20000);

}


void loop()
{

// Temperature Detection 

Serial.println();
int chk = DHT11.read(DHT11PIN);
float humidity =(DHT11.humidity);
float temp = (DHT11.temperature);
Serial.print("Humidity (%): ");
Serial.println(humidity);
Serial.print("Temperature  (C): ");
Serial.println(temp);

if(temp >=60){
digitalWrite(buzzer,HIGH);
delay(1000);
exit(1);
// digitalWrite(buzzer,LOW);

}




// Flame detection

  flame_detected = digitalRead(flame_sensor);
  Serial.print("Flame Value: ");
	Serial.println(flame_detected);
  // if (flame_detected == 1)
  // {
  //   Serial.println("Flame detected...! take action immediately.");

  //   digitalWrite(buzzer, HIGH);
  //   digitalWrite(LED, HIGH);
  //   delay(200);
  //   digitalWrite(LED, LOW);
  //   delay(200);
  // }
  // else
  // {

  //   Serial.println("No flame detected. stay cool");

  //   digitalWrite(buzzer, LOW);

  //   digitalWrite(LED, LOW);
  // }

  // // Smoke Detection 

  sensorValue = analogRead(MQ2pin); // read analog input pin 0
	Serial.print("Sensor Value: ");
	Serial.println(sensorValue);
  int sensorV = digitalRead(mq2pin);
  Serial.print("Sensor V (dig): ");
	Serial.println(sensorV);

  delay(2000);

}

