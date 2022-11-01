/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
*/

//Libraries
#include <DHT.h>;

//Constants
#define DHTPIN_1 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht_ground(DHTPIN_1, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

#define DHTPIN_2 4     // what pin we're connected to
DHT dht_air(DHTPIN_2, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//for fading led
int led = 3;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

//for led
// #define LED 3  // The pin the LED is connected to

//Variables
int chk;
float hum_ground;  //Stores humidity value
float temp_ground; //Stores temperature value

float hum_air;  //Stores humidity value
float temp_air; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht_ground.begin();
  dht_air.begin();
  // for led
  // pinMode(LED, OUTPUT); // Declare the LED as an output

  //for fading led
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}


void loop_ground_humid_temp_sense()
{
    delay(2000);
    //Read data and store it to variables hum and temp
    hum_ground = dht_ground.readHumidity();
    temp_ground= dht_ground.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("ground sensor Humidity: ");
    Serial.print(hum_ground);
    Serial.print(" %, ground sensor Temp: ");
    Serial.print(temp_ground);
    Serial.println(" Celsius");
    delay(1000); //Delay 2 sec.

}

void loop_air_humid_temp_sense()
{
    delay(2000);
    //Read data and store it to variables hum and temp
    hum_air = dht_air.readHumidity();
    temp_air= dht_air.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("air sensor Humidity: ");
    Serial.print(hum_air);
    Serial.print(" %, air sensor Temp: ");
    Serial.print(temp_air);
    Serial.println(" Celsius");
    delay(1000); //Delay 2 sec.

}

void loop_fade_light()
 {

  //for fading led
    // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(90);
}



void loop()
{
  loop_ground_humid_temp_sense();
  loop_air_humid_temp_sense();
  loop_fade_light();
}

