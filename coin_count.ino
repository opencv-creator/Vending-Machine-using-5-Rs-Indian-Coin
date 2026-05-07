#include <LiquidCrystal_I2C.h> // Driver Library for the LCD Module

// Wiring: Connect SDA pin to A4 and SCL pin to A5
// Connects to LCD via I2C, at address 0x27 (A0-A2 not jumpered)

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2); // Adjust to (0x27,20,4) for 20x4 LCD

// Basic CH-926 Coin Acceptor Code for Arduino Nano
const int coinPin = 2; // Signal pin on CH-926 connected to D2
volatile int pulseCount = 0;
volatile unsigned long lastPulseTime = 0;
float totalAmount = 0.0;
int signal =0;
int status =0;
char buffer[14]; // Must be large enough for all digits + null terminator '\0'

// Set your coin values based on pulses (e.g., 1 pulse = 1, 2 pulses = 5)
float coinValues[] = {0.0, 1.0, 5.0, 10.0, 20.0, 5.0, 100.0}; 

void setup() {
  Serial.begin(9600);
  pinMode(coinPin, INPUT_PULLUP);
  // Attach interrupt to pin 2, triggering on RISING edge
  attachInterrupt(digitalPinToInterrupt(coinPin), coinISR, RISING);
  Serial.println("Ready to accept coins.");
  motor_setup();
  ir_setup();
  lcd_setup();
  status =0;
  lcd_print("Vending Machine" ,"Insert 5Rs Coin");
}

void loop() {
  // If pulses were detected
  if (pulseCount > 0 && (millis() - lastPulseTime > 200)) {
    if (pulseCount < 7) { // Assuming max 6 types
      totalAmount += coinValues[pulseCount];
      Serial.print("Coins: ");
      Serial.print(pulseCount);
      Serial.print(" | Total: ");
      Serial.println(totalAmount);
 
     
      status =1;
      //sprintf (buffer,"Rs= %d",totalAmount);
      sprintf(buffer, "%d Rs", int(totalAmount)); // Result: "Value: 05" [30, 36]

      lcd_print("Total Amount" ,buffer);
      Serial.println(buffer);
      motor_rotate(status);
      
           
    }
    pulseCount = 0; // Reset for next coin
  }

  
  signal = ir_check();
  //Serial.print("status check :");
 // Serial.println(signal);
  if(signal)
  {
   status =0;
   motor_rotate(status);
   lcd.clear();lcd_print("Vending Machine" ,"Insert 5Rs Coin");
  
  
  }
  

}

void coinISR() {
  pulseCount++;
  lastPulseTime = millis();
}
