//LADO VIVO
int boton1 = 4;
int boton2 = 5;
int boton3 = 6;


//LADO MUERTO
int boton4 = 8;
int boton5 = 9;
int boton6 = 10;


int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;

int LEDLuzV = 11;
int LEDLuzM = 13; 
 int delayT = 100;

String data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //LADO VIVO
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  //LADO MUERTO
  pinMode(boton4, INPUT);
  pinMode(boton5, INPUT);
  pinMode(boton6, INPUT);
  //TIRA LED
  digitalWrite(LEDLuzV, HIGH);
  digitalWrite(LEDLuzM, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(boton1);
  buttonState2 = digitalRead(boton2);
  buttonState3 = digitalRead(boton3);
  buttonState4 = digitalRead(boton4);
  buttonState5 = digitalRead(boton5);
  buttonState6 = digitalRead(boton6);

  data = normalizeData(buttonState1, buttonState2, buttonState3, buttonState4, buttonState5, buttonState6);

  Serial.println(data);


  if (digitalRead(boton1) == 1) {
    digitalWrite(LEDLuzV, LOW);
  } else {
    digitalWrite(LEDLuzV, HIGH);
  }

  if (digitalRead(boton2) == 1) {
    // Serial.println("B2");
  }

  if (digitalRead(boton3) == 1) {
    // Serial.println("B3");
  }

  if (digitalRead(boton4) == 1) {
    // Serial.println("B4");
    digitalWrite(LEDLuzM, LOW);
  } else {
    digitalWrite(LEDLuzM, HIGH);
  }

  if (digitalRead(boton5) == 1) {
    // Serial.println("B5");
  }

  if (digitalRead(boton6) == 1) {
    // Serial.println("B6");
  }
  delay(20);
}
String normalizeData(int b1, int b2, int b3, int b4, int b5, int b6) {

  String B1string = String(b1);
  String B2string = String(b2);
  String B3string = String(b3);
  String B4string = String(b4);
  String B5string = String(b5);
  String B6string = String(b6);
  /* S000000E*/
  String ret = String("S") + B1string + B2string + B3string + B4string + B5string + B6string + String("E");
  return ret;
}

//delay(100);