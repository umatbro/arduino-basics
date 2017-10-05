#define LED_R 10
#define LED_G 11
#define LED_Y 12

#define KONT 2
#define BUZZER A5
#define PIR 3

boolean buzz_on = false;

void alarm(){
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, LOW);
}

void setup() {
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_Y,OUTPUT);
  pinMode(BUZZER,OUTPUT);

  pinMode(KONT, INPUT_PULLUP);

  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_Y, LOW);

  attachInterrupt(
      digitalPinToInterrupt(2),
      alarm,
      RISING
    );
}

void loop() {
  digitalWrite(LED_Y, HIGH);
  delay(2000);
  digitalWrite(LED_Y, LOW);
  delay(2000);  
}
