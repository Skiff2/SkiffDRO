long ValX = 500000;
long ValY = 500000;
bool  IsAx = false;
bool  IsBx = false;
bool  IsAy = false;
bool  IsBy = false;
byte nn = 0;

void setup() {
Serial.begin(115200); //Это не трогать! 
Serial1.begin(9600); //А это, в идеале, настроить BT модуль на 115200 и тут тоже поставить 115200
  pinMode(PA0, INPUT_PULLDOWN);
  pinMode(PA1, INPUT_PULLDOWN);
  pinMode(PA2, INPUT_PULLDOWN);
  pinMode(PA3, INPUT_PULLDOWN);
  pinMode(PC13, OUTPUT);
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
  nn ++;
  if (nn == 10)
    digitalWrite(PC13, HIGH);
  if (nn == 20)
  {
    digitalWrite(PC13, LOW);
    nn = 0;
  }
  
  delay(200);
  Serial1.print(ValX-500000);
  Serial1.print("|");
  Serial1.println(ValY-500000);
  Serial.print(ValX-500000);
  Serial.print("|");
  Serial.println(ValY-500000);
}

void intAx() { if (digitalRead(PA0) == IsAx) return; IsAx = !IsAx;  if ((IsAx && !IsBx) || (!IsAx && IsBx)) ValX++; else ValX--; }
void intBx() { if (digitalRead(PA1) == IsBx) return;  IsBx = !IsBx;  if ((!IsAx && IsBx) || (IsAx && !IsBx)) ValX--; else ValX++;  }

void intAy() { if (digitalRead(PA2) == IsAy) return;  IsAy = !IsAy;  if ((IsAy && !IsBy) || (!IsAy && IsBy)) ValY++; else ValY--; }
void intBy() { if (digitalRead(PA3) == IsBy) return;  IsBy = !IsBy;  if ((!IsAy && IsBy) || (IsAy && !IsBy)) ValY--; else ValY++;  }