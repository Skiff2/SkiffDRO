long ValX = 0;
long ValY = 0;
bool  IsAx = false;
bool  IsBx = false;
bool  IsAy = false;
bool  IsBy = false;

void setup() {
Serial1.begin(9600); //А в идеале, настроить BT модуль на 115200 и тут тоже поставить 115200
  pinMode(PA0, INPUT_PULLDOWN);
  pinMode(PA1, INPUT_PULLDOWN);
  pinMode(PA2, INPUT_PULLDOWN);
  pinMode(PA3, INPUT_PULLDOWN);
  attachInterrupt(PA0, intAx, CHANGE);
  attachInterrupt(PA1, intBx, CHANGE);
  attachInterrupt(PA2, intAy, CHANGE);
  attachInterrupt(PA3, intBy, CHANGE);

  IsAx = digitalRead(PA0);
  IsBx = digitalRead(PA1);
  IsAy = digitalRead(PA2);
  IsBy = digitalRead(PA3);
}

void loop() {
  delay(200);
  Serial1.print(ValX);
  Serial1.print("|");
  Serial1.println(ValY);
}

void intAx() { IsAx = !IsAx;  if ((IsAx && !IsBx) || (!IsAx && IsBx)) ValX++; else ValX--; }
void intBx() { IsBx = !IsBx;  if ((!IsAx && IsBx) || (IsAx && !IsBx)) ValX--; else ValX++;  }

void intAy() { IsAy = !IsAy;  if ((IsAy && !IsBy) || (!IsAy && IsBy)) ValY++; else ValY--; }
void intBy() { IsBy = !IsBy;  if ((!IsAy && IsBy) || (IsAy && !IsBy)) ValY--; else ValY++;  }

