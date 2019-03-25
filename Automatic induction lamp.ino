int pin1 = 5;
int pin2 = 6;
int pin3 = 7;
int count = 0;
int key = 0;
int state = 0;

void setup() {
  pinMode(pin1, INPUT);//热敏
  pinMode(pin2, INPUT);//红外热释
  pinMode(pin3, OUTPUT);//继电器
  Serial.begin(9600);
}

void loop() {
  delay(100);
  int val1 = digitalRead(pin1);
  int val2 = digitalRead(pin2);
  count = count >=20 ? 0 : count + 1;
  Serial.println(val2 + 1000000);
  Serial.println(count + 1000);
  Serial.println(key);
  if (val2 == 1) {
    key = count >= 20 ? 1 : key + val2;
    if (val1 == 1) {
      if (state == 0) {
        digitalWrite(pin3, 1);
        state = 1;
      }
    }
  } else {
    if (count >=20 && key == 0 && state == 1) {
      digitalWrite(pin3, 0);
      state = 0;
      count = 0;
    }
    key = count >= 20 ? 0 : key + val2;
  }
}
