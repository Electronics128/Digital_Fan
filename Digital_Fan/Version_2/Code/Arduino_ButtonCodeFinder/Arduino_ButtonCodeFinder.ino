#include <IRremote.h>
int RECV_PIN = 12; // the pin where you connect the output pin of IR sensor (CHANGE Depending on your Arduino)   
IRrecv irrecv(RECV_PIN);     
decode_results results;     
void setup()     
{     
Serial.begin(9600);     
irrecv.enableIRIn();     
{     
void loop()     
{     
if (irrecv.decode(&results))   
{     
 int results.value = results;   
 Serial.println(" ");     
 Serial.print("Code: ");     
 Serial.println(results.value);    
 Serial.println(" ");     
 irrecv.resume();     
}     