#include <esp_now.h>
#include <WiFi.h>
#include <mecmotor.h>
// Structure to receive data
typedef struct struct_message {
    int potvalue;
    int x2;
    int y2;
    int x1;
    int y1;
    int sw;
} struct_message;

//struct_message called valued
struct_message valued;

// Variable to store the last received time
unsigned long lastReceiveTime = 0;
const unsigned long timeoutDuration = 2000;
long speed;

bool dataReceived = false;
mecmotor motor;
// Callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&valued, incomingData, sizeof(valued));
    Serial.print("Bytes received: ");
    Serial.println(len);


    speed = map(valued.potvalue,0,4096,0,255);
    Serial.println(speed);
    if ((valued.y2 == 1202) && (valued.x2 == 2047)){
      Serial.println("Forward");
      motor.forward(speed);

    }
    if (((valued.y2 < 10) && (valued.y2 > 1))  &&  (valued.x2 == 2047)){
      Serial.println("Backward");
      motor.backward(speed);
    }
    if ((valued.x2 == 1202) && (valued.y2 == 2047)) {
      Serial.println("right");
      motor.right(speed);
    }
    if ((valued.x2 < 10) && (valued.x2 > 1)) {
      Serial.println("left");
      motor.left(speed);
    }
    if  ((valued.x1 == 1202) && (valued.y1 == 2047)) {
      motor.strafer(speed);
    }
    if ((valued.x1 < 10 ) && (valued.x1 > 1)){
      motor.strafel(speed);
    }
    if (valued.sw == 0){
      Serial.println("front pivot");
      if ((valued.y1 < 10) && (valued.y1 > 1)){
        motor.pivotfr(speed);
      }
      if (valued.y1 == 1202) {
        motor.pivotfl(speed);
      }

    }
    if (valued.sw == 1){
      Serial.println("backward pivot");
      if ((valued.y1 < 10) && (valued.y1 > 1)){
        motor.pivotbr(speed);
      }
      if (valued.y1 == 1202) {
        motor.pivotbl(speed);
      }      
    }
    if ((valued.x1 == 2047 ) && (valued.x2 == 2047 ) && (valued.y1 == 2047 ) && (valued.y2 == 2047 )){
      motor.stop();
    }



    
    lastReceiveTime = millis();
    dataReceived = true;
}

void setup() {
    
    Serial.begin(115200);
  
    
    WiFi.mode(WIFI_STA);

    // Init ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
  
    // Register the callback function for receiving data
    esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}

void loop() {
    // Check if the current time has exceeded the timeout duration since the last receive
    if (millis() - lastReceiveTime > timeoutDuration) {
        // If the timeout has been reached and data was previously received
        if (dataReceived) {
            
            valued.potvalue = 0;

            
            Serial.println("Timeout! Resetting values to 0.");


            
            dataReceived = false;
        }

    }




    delay(1); 
}
