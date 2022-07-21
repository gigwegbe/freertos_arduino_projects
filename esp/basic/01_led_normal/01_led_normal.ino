#define RED     25
#define YELLOW  32
#define BLUE    22

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED, digitalRead(RED)^1); 
  digitalWrite(YELLOW,digitalRead(YELLOW)^1);
  digitalWrite(BLUE,digitalRead(BLUE)^1);
  delay(50);
  
}
