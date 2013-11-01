#include <StopWatch.h>

int timer = 0;
StopWatch MySW;

void setup(){
  // Open serial connection and setup ports.
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  //Serial.write('1');
  StopWatch(SECONDS);
}

void loop(){
 //Check if data has been sent, then see what color it is
 //Output that color 
  if(Serial.available() > 0){
    MySW.stop();
    MySW.reset();
    char data = Serial.read();
    if (data == 'r'){
      
      //Red has been sent
      digitalWrite(2, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      Serial.write('R');
      
    } else if (data == 'b'){
      //Blue has been sent
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(2, LOW);
      Serial.write('B');
    
    } else if (data == 'g'){
      //Green has been sent
      digitalWrite(7, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(8, LOW);
      Serial.write('G');
    } else { 
     //Something else has been sent - Output it 
     Serial.write(data);
  }
} else {
   MySW.start();
}

if (MySW.elapsed() >= 180000){
  Serial.write('L');
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2, LOW);
  digitalWrite(7, HIGH);
  delay(200);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(200);
  digitalWrite(8, LOW);
}
}

