const int button1 = 5;
const int button2 = 7;
int buttonstate1, buttonstate2, i = 0;
void setup() {
  // put your setup code here, to run once:
for(int led = 9; led < 12; led++){
  pinMode(led, OUTPUT);     //the led using pins 9 to 11
}
pinMode(button1, INPUT);
pinMode(button2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.begin(9600);
delay(500);
Serial.println(i);
delay(200);
buttonstate1 = digitalRead(button1);
buttonstate2 = digitalRead(button2);
if(buttonstate1 == HIGH){
  i++;
  delay(200);
  }

if(buttonstate2 == HIGH){
  i--;
  delay(200);
  }

switch(i){
case 1:
  for(int led = 9; led < 12; led++){
  digitalWrite(led, HIGH);
  delay(200);                 //the led is flashing towards the right
  digitalWrite(led, LOW);
  delay(200);
  }
break;
case 2:
   for(int led = 11; led >= 9; led--){
  digitalWrite(led, HIGH);
  delay(200);                 //the led is flashing towards the left
  digitalWrite(led, LOW);
  delay(200);
  }
break;
default:
  for(int led = 9; led < 12; led++){
  digitalWrite(led, LOW);     //turn off the led
  delay(200);
  }
i=0;
break;
}
}
