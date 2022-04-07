/* Legal-Disclaimer
This project is meant for informational purposes only! To better your knowledge on the concepts of electricity, electrical circuitry, entertainment component circuitry and all other wiring methods. DO NOT ATTEMPT ANY WIRING OF ANY KIND if you lack the knowledge and understanding required. Otherwise personal injury and/or death as well as property damage or loss could occur.

WARNING

Electricity is dangerous and can cause personal injury or DEATH as well as other property loss or damage if not used or constructed properly. If you have any doubts what so ever about performing do-it-yourself electrical work, PLEASE do the smart thing and hire a QUALIFIED SPECIALIST to perform the work for you.

NEVER WORK WITH LIVE VOLTAGE. Always disconnect the power source before working with electrical circuits.

When performing electrical work, ALWAYS READ AND FOLLOW THE MANUFACTURERS INSTRUCTIONS AND SAFETY GUIDELINES. Always follow your local electrical code and requirements which are specific to local areas.

By utilizing this project and the information given, YOU are expressly holding "Orange (Youtube Account)" HARMLESS FOR ANY PROPERTY DAMAGE, PERSONAL INJURY AND/OR DEATH, OR ANY OTHER LOSS OR DAMAGE THAT MAY RESULT FROM YOUR ACTIONS.

This information is provided for the use of individuals as they see fit! Orange and Youtube and all parties associated with it are not responsible for the use and results of this information by any party, especially those lacking sufficient skill or knowledge to perform these steps safely and ANY HAZARD CREATED IS THE SOLE RESPONSIBILITY OF THE USER.*/

// PROCEED AT YOUR OWN RISK


#include <IRremote.h>

int RECV_PIN = 6;                 // Pin no. on Arduino (Change depending on your Arduino)
int Speed1 = 2;                    // Pin no. on Arduino (Change depending on your Arduino)
int Speed2 = 3;                    // Pin no. on Arduino (Change depending on your Arduino)
int Speed3 = 4;                    // Pin no. on Arduino (Change depending on your Arduino)
int OSC = 5;                       // Pin no. on Arduino (Change depending on your Arduino)
int relay[] = {0,0,0,0,0};         // no. of relays present / the state of the relay


#define speed1 16724175             // button code for speed no.1  (CHANGE Depending on your Button Code)
#define speed2 16718055             // button code for speed no.2  (CHANGE Depending on your Button Code)
#define speed3 16743045             // button code for speed no.3  (CHANGE Depending on your Button Code)
#define power  16753245             // button code for ON/OFF      (CHANGE Depending on your Button Code)
#define Osc    16712445             // button code for Oscilation  (CHANGE Depending on your Button Code)
  
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {

Serial.begin(9600);                  // this line can be omitted as it tells the "SM" what button is pressed
irrecv.enableIRIn();                 // enables the IR reciver
pinMode(Speed1, OUTPUT);             // declares speed1 as an output
pinMode(Speed2, OUTPUT);             // declares speed2 as an output
pinMode(Speed3, OUTPUT);             // declares speed3 as an output
pinMode(OSC, OUTPUT);                // declares Oscilation as an output
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
      switch(value) {
  
        case speed1:
          
            if(relay[1] == 0) {
               digitalWrite(Speed1, HIGH);    // Sets the speed to 1
               digitalWrite(Speed2, LOW);     // makes sure that all other speeds are turned off to prevent multiple voltages going to the fan
               digitalWrite(Speed3, LOW);     // makes sure that all other speeds are turned off to prevent multiple voltages going to the fan
               relay[1] == 1;                 // just an indicator for the program that speed 1 is currently ON
}

  break;
  
        case speed2:
          
            if(relay[2] == 0) {
              digitalWrite(Speed1, LOW);    // makes sure that all other speeds are turned off to prevent multiple voltages going to the fan
              digitalWrite(Speed2, HIGH);   // sets the speed to 2
              digitalWrite(Speed3, LOW);    // makes sure that all other speeds are turned off to prevent multiple voltages going to the fan
              relay[2] == 1;                // just an indicator for the program that speed 2 is currently ON
} 

  break;

        case speed3:
            
            if(relay[3] == 0) {
              digitalWrite(Speed1, LOW);    // makes sure that all other speeds are turned off to prevent multiple voltages going to the fan
              digitalWrite(Speed2, LOW);    // makes sure that all other speeds are turned off to prevent multiple voltages going to the fan
              digitalWrite(Speed3, HIGH);   // sets the speed to 3
              relay[3] == 1;                // just an indicator for the program that speed 3 is currently ON
}

  break;

        case power:                         // when this button is pressed it will tell the fan to shut off all speeds and OSC
   
          digitalWrite(Speed1, LOW);
          digitalWrite(Speed2, LOW); 
          digitalWrite(Speed3, LOW);
          digitalWrite(OSC, LOW);
          
  break;

        case Osc:

          if(relay[4] == 0) {
             digitalWrite(OSC, HIGH);     // sets the OSC motor to on
             relay[4] = 1;                // just an indicator for the program that OSC is currently activated
          } 
          
          else {                          // turns OFF the OSC mode
            digitalWrite(OSC, LOW);       // turns OFF the OSC motor
            relay[4] = 0;                 // just an indicator that OSC is currently OFF
          }
          
  break;
  
    }
      Serial.println(value); // you can ommit this line
      irrecv.resume(); // Receive the next value
  }
}
