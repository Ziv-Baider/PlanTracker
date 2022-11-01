/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
*/

//Libraries
#include <DHT.h>;

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//for fading led
int led = 3;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

//for led
// #define LED 3  // The pin the LED is connected to

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht.begin();
  // for led
  // pinMode(LED, OUTPUT); // Declare the LED as an output

  //for fading led
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

void loop()
{
    delay(2000);
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(1000); //Delay 2 sec.

  // for led
  // digitalWrite(LED, HIGH); // Turn the LED on

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
  delay(30);
}



   
/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

// int led = 9;         // the PWM pin the LED is attached to
// int brightness = 0;  // how bright the LED is
// int fadeAmount = 5;  // how many points to fade the LED by

// // the setup routine runs once when you press reset:
// void setup() {
//   // declare pin 9 to be an output:
//   pinMode(led, OUTPUT);
// }

// // the loop routine runs over and over again forever:
// void loop() {
//   // set the brightness of pin 9:
//   analogWrite(led, brightness);

//   // change the brightness for next time through the loop:
//   brightness = brightness + fadeAmount;

//   // reverse the direction of the fading at the ends of the fade:
//   if (brightness <= 0 || brightness >= 255) {
//     fadeAmount = -fadeAmount;
//   }
//   // wait for 30 milliseconds to see the dimming effect
//   delay(30);
// }

