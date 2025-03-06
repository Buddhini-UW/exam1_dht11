
#include <DHT.h>
#include <DHT_U.h>

#define ledpin 12
#define DHTPIN 4    
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
 
  Serial.begin(9600);
pinMode(ledpin,OUTPUT);
  delay(1500); 

  Serial.println("DHT11 test!");
  dht.begin();
  // Defined in thingProperties.h
  
}
void loop() {
  
  // Your code here 
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(hum) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    
  }

  digitalWrite(ledpin,HIGH);
delay(1000);
digitalWrite(ledpin,LOW);
delay(1000);

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  Temperature: ");
  Serial.print(temp);
  Serial.println("°C");
  delay(2000); // Wait a bit between readings


}


