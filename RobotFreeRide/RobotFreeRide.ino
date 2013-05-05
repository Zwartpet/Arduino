//Arduino PWM Speed Control：
int E1 = 5;  
int M1 = 4; 
int E2 = 6;                      
int M2 = 7;                        
const int IRPinC = 8;//Connect the signal pin to the digital pin 4
const int IRPinR = 2;//Connect the signal pin to the digital pin 4
const int IRPinL = 3;//Connect the signal pin to the digital pin 4
void setup() 
{ 
  pinMode(M1, OUTPUT);   
  pinMode(M2, OUTPUT); 
  pinMode(IRPinC, INPUT);
  pinMode(IRPinR, INPUT);
  pinMode(IRPinL, INPUT);
  analogWrite(E1, 150);   //PWM Speed Control
  analogWrite(E2, 150);   //PWM Speed Control
} 

void loop() 
{ 
  if(digitalRead(IRPinL) == LOW && digitalRead(IRPinR) == HIGH){
    digitalWrite(M1,LOW);   
    digitalWrite(M2, HIGH);  
    analogWrite(E1, 200);   //PLL Speed Control
    analogWrite(E2, 200);   //PLL Speed Control
  }
  else if(digitalRead(IRPinL) == HIGH && digitalRead(IRPinR) == LOW){
    digitalWrite(M1, HIGH);   
    digitalWrite(M2, LOW);
    analogWrite(E1, 200);   //PLL Speed Control
    analogWrite(E2, 200);   //PLL Speed Control  
  }
  else if (digitalRead(IRPinL) == LOW && digitalRead(IRPinR) == LOW){
    digitalWrite(M1,HIGH);   
    digitalWrite(M2, HIGH);  
    analogWrite(E1, 200);   //PLL Speed Control
    analogWrite(E2, 200);   //PLL Speed Control
    delay(1000);
    digitalWrite(M1,LOW);   
    digitalWrite(M2, HIGH);  
    analogWrite(E1, 200);   //PLL Speed Control
    analogWrite(E2, 200);   //PLL Speed Control
    delay(1000);
  }
  else if(digitalRead(IRPinR) == HIGH && digitalRead(IRPinL) == HIGH){
    digitalWrite(M1,LOW);   
    digitalWrite(M2, LOW);  
    analogWrite(E1, 200);
    analogWrite(E2, 200);
  }
}


