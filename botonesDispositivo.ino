//BOTONES
int botonSonidoM = 4;
int botonSonidoV = 5;
int botonLuzM = 6;
int botonLuzV = 7;
int botonFinal = 12;
//ESTADOS BOTONES
int estadoAnteriorUno = 0;
int estadoAnteriorDos = 0;
int estadoAnteriorTres = 0;
int estadoAnteriorCuatro = 0;
int estadoAnteriorCinco = 0;
//LEDS
int LEDSonidoM = 9;
int LEDSonidoV = 10;
int LEDLuzM = 11;
//int LEDLuzV = 13;
int LEDBotonFinal = 3;
//ESTADOS LEDS
int EstadoLED = 0;
//COMPORTAMIENTO GLITCH LUZ LED
// Variable global arriba del setup

const byte LEDLuzV = 13;  // Pin donde va a estar conectado el botón con LED blanco
int paso = 0;             // por donde vamos en el eje de tiempo
const byte delta = 200;    // Demora entre cada ajuste del brillo
int maxpasos;             // Cantidad total de pasos en un ciclo de respiración
int Ritmo;                // Duración de la inspiración cantidad de pasos
int delayT = 100;


void setup() {  // initialize the buttons' inputs:
                //BOTONES
  pinMode(botonSonidoM, INPUT);
  pinMode(botonSonidoV, INPUT);
  pinMode(botonLuzM, INPUT);
  pinMode(botonLuzV, INPUT_PULLUP);
  pinMode(botonFinal, INPUT);
  //LEDS
  pinMode(LEDSonidoM, OUTPUT);
  pinMode(LEDSonidoV, OUTPUT);
  pinMode(LEDLuzM, OUTPUT);
  pinMode(LEDLuzV, OUTPUT);
  pinMode(LEDBotonFinal, OUTPUT);
  //TIRA LED
  digitalWrite(LEDLuzV, HIGH);
  maxpasos = 4000 / delta;          // Para más rápido/lento subir/bajar el 4000
  Ritmo = round(maxpasos * 3 / 8);  // Duración de la inspiración cantidad de pasos

  Serial.begin(9600);
}

void loop() {

  int bLedSMNuevo = digitalRead(botonSonidoM);
  int bLedSV = digitalRead(botonSonidoV);
  int bLedLM = digitalRead(botonLuzM);
  int bLedLV = digitalRead(botonLuzV);
  int bLedBF = digitalRead(botonFinal);

  //BOTON UNO
  if (bLedSMNuevo == 1 && estadoAnteriorUno == 0) {
    if (EstadoLED == 0) {
      digitalWrite(LEDSonidoM, HIGH);
      EstadoLED = 1;
      Serial.write(1);
    } else {
      digitalWrite(LEDSonidoM, LOW);
      EstadoLED = 0;
      Serial.write((byte)0x00);
    }
  }
  estadoAnteriorUno == bLedSMNuevo;
  //BOTON DOS
  if (bLedSV == HIGH && estadoAnteriorDos == LOW) {
    if (EstadoLED == 0) {
      digitalWrite(LEDSonidoV, HIGH);
      EstadoLED = 1;
      Serial.write(2);
    } else {
      digitalWrite(LEDSonidoV, LOW);
      EstadoLED = 0;
      Serial.write((byte)0x00);
    }
  }
  estadoAnteriorDos == bLedSV;

  //BOTON TRES
  if (bLedLM == HIGH) {
    //Serial.println("c");
    digitalWrite(LEDLuzM, HIGH);
    
    Serial.write(1);
    //Serial.println("LEDLuzM is pressed");
  } else {
    digitalWrite(LEDLuzM, LOW);
    Serial.write((byte)0x00);
  }

  //BOTON CUATRO
  if (bLedLV == HIGH) {
    //Serial.println("d");
    digitalWrite(LEDLuzV, LOW);
    Serial.println("LEDLuzV is pressed");
    Serial.write(2);
   // Glitch();
  } else {
    digitalWrite(LEDLuzV, HIGH);
    Serial.write((byte)0x00);
  }

  //BOTON FINAL
  if (bLedSMNuevo == HIGH && bLedSV == HIGH && bLedLM == HIGH && bLedLV == HIGH) {
    //Serial.println("t");
    digitalWrite(LEDBotonFinal, HIGH);
    Serial.println("LEDBotonFinal is pressed");
  } else {
    digitalWrite(LEDBotonFinal, LOW);
  }
  //Serial.println(data);
 // delay(delayT);  //original es 100 !!!! es que a veces parece tener delay
}
void Glitch() {
  static unsigned long tiempoInicio = 0;  // Variable para el tiempo inicial
  unsigned long tiempoActual = millis();  // Obtener el tiempo actual en milisegundos

  if (tiempoActual - tiempoInicio >= 20000) {  // Después de 20 segundos, level se establecerá en 255
    analogWrite(LEDLuzV, 255);
  } else {
    int level = random(255);
    analogWrite(LEDLuzV, level);
  }

  if (tiempoActual - tiempoInicio >= 20000) {
    tiempoInicio = tiempoActual;  // Reiniciar el tiempo inicial
  }

  delay(delayT);
}
