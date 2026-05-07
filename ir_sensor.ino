#define IRpin 4 
#define ledPin 13 
void ir_setup() { 
	// put your setup code here, to run once: 
pinMode(IRpin,INPUT); 
pinMode(ledPin,OUTPUT); 
} 

int ir_check() { 
	// put your main code here, to run repeatedly: 
	int IRread = digitalRead(IRpin); 
digitalWrite(ledPin,LOW); 
if(IRread == 0){ 
	return 1;
} 
else
{
  return 0;
}
} 
