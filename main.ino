#include <HX711.h>
#include <Servo.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DOUT D6
#define CLK D7
#define DHTPIN D3
#define DHTTYPE DHT11

HX711 scale(DOUT, CLK);
DHT dht(DHTPIN, DHTTYPE);
Servo myservo;

float calibration_factor = 670.10;
int GRAM;

char auth[] = "hI26DN_PGw0-MjX_FThy5MczoX02F_-J"; // Enter the Auth code from Blynk
char ssid[] = "VeendySuseno";  // Enter your WiFi SSID
char pass[] = "Admin12345";    // Enter your WiFi password

void setup() {
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
  
  dht.begin();  // Start DHT sensor
  pinMode(D4, OUTPUT);  // LED/relay for heat
  pinMode(D5, OUTPUT);  // LED/relay for cooling
  
  myservo.attach(D9);  // Attach servo
  myservo.write(0);    // Initial servo position
  
  scale.set_scale();
  scale.tare();  // Reset the scale to 0
  long zero_factor = scale.read_average();
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
  
  delay(1000);
}

void loop() {
  Blynk.run();  // Initiates Blynk
  
  // Read humidity and temperature from DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");
  
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
  
  scale.set_scale(calibration_factor);
  GRAM = scale.get_units();  // Get the weight in grams
  Serial.print("Weight: ");
  Serial.print(GRAM);
  Serial.println(" Gram");

  Serial.print("Calibration factor: ");
  Serial.println(calibration_factor);
  
  // Send sensor data to Blynk
  Blynk.virtualWrite(V0, h);    // V0 for Humidity
  Blynk.virtualWrite(V1, t);    // V1 for Temperature
  Blynk.virtualWrite(V2, GRAM); // V2 for Weight

  // Temperature control logic
  if (t > 30.00) {
    Blynk.notify("SUHU PANAS");
    digitalWrite(D4, LOW);  // Turn off heat
    digitalWrite(D5, HIGH); // Turn on cooling
  } else if (t < 28.00) {
    Blynk.notify("SUHU DINGIN");
    digitalWrite(D4, HIGH); // Turn on heat
    digitalWrite(D5, LOW);  // Turn off cooling
  } else {
    Blynk.notify("SUHU NORMAL");
    digitalWrite(D4, HIGH); // Turn on both heat and cooling
    digitalWrite(D5, HIGH);
  }

  // Servo control based on weight (GRAM)
  if (GRAM <= 300) {
    Blynk.notify("PAKAN KURANG");
    myservo.write(90);  // Open servo
    delay(1000);
  } else if (GRAM >= 500) {
    Blynk.notify("PAKAN CUKUP");
    myservo.write(0);  // Close servo
    delay(1000);
  }
}
