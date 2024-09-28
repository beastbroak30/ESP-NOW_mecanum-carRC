#include <WiFi.h>
#include <esp_now.h>
#include <Adafruit_ADS1X15.h>
//Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
Adafruit_ADS1015 ads; 

#define pot 34
const int btpin = 18;  
int buttonState = 0;       
int lastButtonState = 0;   
bool toggle = false; 
int swt = 0;
uint8_t broadcastAddress[] = {0xcc, 0x7b, 0x5c, 0xf1, 0xb6, 0x04};


typedef struct struct_message {
  int potvalue;
  int x2;
  int y2;
  int x1;
  int y1;
  int sw;
} struct_message;

// Create a struct_message called myData
struct_message valued;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db);

  WiFi.mode(WIFI_STA);
  pinMode(btpin, INPUT_PULLUP);
                                                              
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  if (!ads.begin())
  {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

 

  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {
  // Set values to send
  int16_t jx1, jy1 , jx2, jy2;
  jx1 = ads.readADC_SingleEnded(1);
  jy1 = ads.readADC_SingleEnded(0);
  jx2 = ads.readADC_SingleEnded(2);
  jy2 = ads.readADC_SingleEnded(3);

  buttonState = digitalRead(btpin);
  if (buttonState != lastButtonState) {
    
    if (buttonState == LOW) {
      toggle = !toggle;  
      if (toggle) {
        swt = 1;
      } else {
        swt = 0;
      }
    }
    delay(30);  
  }

  lastButtonState = buttonState; 

  valued.potvalue = (analogRead(pot));
  valued.x1 = jx1;
  valued.y1 = jy1;
  valued.x2 = jx2;
  valued.y2 = jy2;
  valued.sw = swt;
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &valued, sizeof(valued));
   

  delay(1);
}