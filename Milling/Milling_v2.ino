volatile int lastEncodedX = 0;
volatile long ValX = 0;

volatile int lastEncodedY = 0;
volatile long ValY = 0;

volatile int lastEncodedZ = 0;
volatile long ValZ = 0;

void setup() {
Serial.begin(115200); //это не трогать
Serial1.begin(115200); //А это, в идеале, настроить BT модуль на 115200 и тут тоже поставить 115200
  pinMode(PA0, INPUT_PULLDOWN);
  pinMode(PA1, INPUT_PULLDOWN);
  pinMode(PA2, INPUT_PULLDOWN);
  pinMode(PA3, INPUT_PULLDOWN);
  pinMode(PA4, INPUT_PULLDOWN);
  pinMode(PA5, INPUT_PULLDOWN);
  attachInterrupt(PA0, updateEncoderX, CHANGE);
  attachInterrupt(PA1, updateEncoderX, CHANGE);
  attachInterrupt(PA2, updateEncoderY, CHANGE);
  attachInterrupt(PA3, updateEncoderY, CHANGE);
  attachInterrupt(PA4, updateEncoderZ, CHANGE);
  attachInterrupt(PA5, updateEncoderZ, CHANGE);
}

void loop() {
  delay(200);
  Serial1.print(ValX);
  Serial1.print("*");
  Serial1.print(ValY);
  Serial1.print("*");
  Serial1.println(ValZ);
  Serial.print(ValX);
  Serial.print("*");
  Serial.print(ValY);
  Serial.print("*");
  Serial.println(ValZ);
}

void updateEncoderX(){
  int MSB = digitalRead(PA0); //MSB = most significant bit
  int LSB = digitalRead(PA1); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncodedX << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) ValX ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) ValX --;

  lastEncodedX = encoded; //store this value for next time
}

void updateEncoderY(){
  int MSB = digitalRead(PA2); //MSB = most significant bit
  int LSB = digitalRead(PA3); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncodedY << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) ValY ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) ValY --;

  lastEncodedY = encoded; //store this value for next time
}

void updateEncoderZ(){
  int MSB = digitalRead(PA4); //MSB = most significant bit
  int LSB = digitalRead(PA5); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncodedZ << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) ValZ ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) ValZ --;

  lastEncodedZ = encoded; //store this value for next time
}
