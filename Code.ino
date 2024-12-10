#include <WiFi.h>
#include <ThingESP.h>

ThingESP32 thing("sakib", "HomeAuto", "homeautoESP32");

int LED_PIN = 23;      
int led_pin = 22;     
int fan_pin = 25;  
int pump_pin = 13; 

bool ledState = false; 
bool ledState1 = false; 
bool fanState = false;
bool pumpState = false;

void setup()
{
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);  
    pinMode(led_pin, OUTPUT);  
    pinMode(fan_pin, OUTPUT);
    pinMode(pump_pin, OUTPUT);
    digitalWrite(fan_pin, LOW); 
    digitalWrite(pump_pin, LOW);
    thing.SetWiFi("Hlw", "12344567889");
    thing.initDevice();
}

String HandleResponse(String query)
{
    if (query == "led1 on") {
        digitalWrite(LED_PIN, HIGH); 
        ledState = true;            
        return "Done: LED1 Turned ON";
    }
    else if (query == "led1 off") {
        digitalWrite(LED_PIN, LOW);  
        ledState = false;            
        return "Done: LED1 Turned OFF";
    }
    else if (query == "led1 status") {
        return ledState ? "LED1 is ON" : "LED1 is OFF";
    }
    else if (query == "led2 on") {
        digitalWrite(led_pin, HIGH); 
        ledState1 = true;            
        return "Done: LED2 Turned ON";
    }
    else if (query == "led2 off") {
        digitalWrite(led_pin, LOW);  
        ledState1 = false;           
        return "Done: LED2 Turned OFF";
    }
    else if (query == "led2 status") {
        return ledState1 ? "LED2 is ON" : "LED2 is OFF";
    }
    else if (query == "fan on") {
        digitalWrite(fan_pin, HIGH); 
        fanState = true;             
        return "Done: Fan Turned ON";
    }
    else if (query == "fan off") {
        digitalWrite(fan_pin, LOW);  
        fanState = false;            
        return "Done: Fan Turned OFF";
    }
    else if (query == "fan status") {
        return fanState ? "Fan is ON" : "Fan is OFF";
    }
    else if (query == "pump on"){
       digitalWrite(pump_pin, HIGH);
       pumpState = true;
       return "Done: Water-pump Turned ON.";
    }
    else if (query == "pump off"){
       digitalWrite(pump_pin, LOW);
       pumpState = false;
       return "Done: Water-pump turned OFF.";
    }
    else if (query == "pump status"){
       return pumpState ? "Pump is ON" : "Pump is OFF";
    }
    else {
        return "Your query was invalid.";
    }
}

void loop()
{
    thing.Handle(); 
}
