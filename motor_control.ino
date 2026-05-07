// Motor A connections
int enA = 7;
int in1 = 8;
int in2 = 9;


void motor_setup() {
  // Set all motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

}

void motor_rotate(int enable) {
  if(enable)
  {
  
  analogWrite(enA,128);
  
  // Change direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  }
  else
  {
     analogWrite(enA,128);
  
  // Change direction
  digitalWrite(in1,LOW);
  digitalWrite(in2, LOW);
  }
   

}