#define BLYNK_PRINT Serial



/* Fill-in your Template ID (only if using Blynk.Cloud) */

#define BLYNK_TEMPLATE_ID "TMPLs7CI82Pj"
#define BLYNK_DEVICE_NAME "Motor"
#define BLYNK_AUTH_TOKEN "2tblvADA2mgc91YP64PYTkj_7HtPCH7s"

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266_SSL.h>



// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

char auth[] = "2tblvADA2mgc91YP64PYTkj_7HtPCH7s";



// Your WiFi credentials.

// Set password to "" for open networks.

char ssid[] = "Sadat";

char pass[] = "#s@d@t##";



int M1PWM = 14; //GPIO14

int M2PWM = 12; //GPIO12

int M1P = 5;  //GPIO5

int M1N = 4;  //GPIO4

int M2P = 0;  //GPIO0

int M2N = 2;  //GPIO2



int pinValue1;

int pinValue2;



BLYNK_WRITE(V1)



{



  int pinValue1 = param.asInt(); // assigning incoming value from pin V1 to a variable



  analogWrite(M1PWM,pinValue1);



  Blynk.virtualWrite(V1, pinValue1);



  Serial.print("V1 Slider value is: ");



  Serial.println(pinValue1);



}



BLYNK_WRITE(V2)



{



  int pinValue2 = param.asInt(); // assigning incoming value from pin V2 to a variable



  analogWrite(M2PWM,pinValue2);



  Blynk.virtualWrite(V2, pinValue2);



  Serial.print("V2 Slider value is: ");



  Serial.println(pinValue2);



}

void setup()

{

  pinMode (M1PWM,OUTPUT);

  pinMode (M2PWM,OUTPUT);

  pinMode (M1P,OUTPUT);

  pinMode (M1N,OUTPUT);

  pinMode (M2P,OUTPUT);

  pinMode (M2N,OUTPUT);

  // Debug console

  Serial.begin(9600);



  Blynk.begin(auth, ssid, pass);

}



void loop()

{

  Blynk.run();

}
