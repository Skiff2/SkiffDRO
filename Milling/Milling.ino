long ValX = 500000;
long ValY = 500000;
long ValZ = 500000;
bool  IsAx = false;
bool  IsBx = false;
bool  IsAy = false;
bool  IsBy = false;
bool  IsAz = false;
bool  IsBz = false;

void setup() {
Serial.begin(115200); //это не трогать
Serial1.begin(9600); //А это, в идеале, настроить BT модуль на 115200 и тут тоже поставить 115200
  pinMode(PA0, INPUT_PULLDOWN);
  pinMode(PA1, INPUT_PULLDOWN);
  pinMode(PA2, INPUT_PULLDOWN);
  pinMode(PA3, INPUT_PULLDOWN);
  pinMode(PA4, INPUT_PULLDOWN);
  pinMode(PA5, INPUT_PULLDOWN);
  attachInterrupt(PA0, intAx, CHANGE);
  attachInterrupt(PA1, intBx, CHANGE);
  attachInterrupt(PA2, intAy, CHANGE);
  attachInterrupt(PA3, intBy, CHANGE);
  attachInterrupt(PA4, intAz, CHANGE);
  attachInterrupt(PA5, intBz, CHANGE);

  IsAx = digitalRead(PA0);
  IsBx = digitalRead(PA1);
  IsAy = digitalRead(PA2);
  IsBy = digitalRead(PA3);
  IsAz = digitalRead(PA4);
  IsBz = digitalRead(PA5);
}

void loop() {
  delay(200);
  Serial1.print(ValX-500000);
  Serial1.print("*");
  Serial1.print(ValY-500000);
  Serial1.print("*");
  Serial1.println(ValZ-500000);
  Serial.print(ValX-500000);
  Serial.print("*");
  Serial.print(ValY-500000);
  Serial.print("*");
  Serial.println(ValZ-500000);
}

void intAx() {if (digitalRead(PA0) == IsAx) return; IsAx = !IsAx;  if ((IsAx && !IsBx) || (!IsAx && IsBx)) ValX++; else ValX--; }
void intBx() {if (digitalRead(PA1) == IsBx) return; IsBx = !IsBx;  if ((!IsAx && IsBx) || (IsAx && !IsBx)) ValX--; else ValX++;  }

void intAy() {if (digitalRead(PA2) == IsAy) return; IsAy = !IsAy;  if ((IsAy && !IsBy) || (!IsAy && IsBy)) ValY--; else ValY++; }
void intBy() {if (digitalRead(PA3) == IsBy) return; IsBy = !IsBy;  if ((!IsAy && IsBy) || (IsAy && !IsBy)) ValY++; else ValY--;  }

void intAz() {if (digitalRead(PA4) == IsAz) return; IsAz = !IsAz;  if ((IsAz && !IsBz) || (!IsAz && IsBz)) ValZ++; else ValZ--; }
void intBz() {if (digitalRead(PA5) == IsBz) return; IsBz = !IsBz;  if ((!IsAz && IsBz) || (IsAz && !IsBz)) ValZ--; else ValZ++;  }
