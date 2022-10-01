#define f 350

void readS()
{
  time = millis();  
  s1 = analogRead(A0) < f;
  s2 = analogRead(A1) < f;
  s3 = analogRead(A2) < f;
  s4 = analogRead(A3) < f;
  s5 = analogRead(A4) < f;
  s6 = analogRead(A5) < f;
  s7 = analogRead(A6) < f;
  s8 = analogRead(A7) < f;
  s9 = analogRead(A8) < f;
}

void error()
{
  if      ( s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9) {erro = -3.42;}  // Sensor 1     na linha branca
  else if ( s1 &&  s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9) {erro = -3.00;}  // Sensor 1 e 2 na linha branca
  else if (!s1 &&  s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9) {erro = -2.59;}  // Sensor 2     na linha branca
  else if (!s1 &&  s2 &&  s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9) {erro = -2.16;}  // Sensor 2 e 3 na linha branca
  else if (!s1 && !s2 &&  s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9) {erro = -1.74;}  // Sensor 3     na linha branca
  else if (!s1 && !s2 &&  s3 &&  s4 && !s5 && !s6 && !s7 && !s8 && !s9) {erro = -1.31;}  // Sensor 3 e 4 na linha branca
  else if (!s1 && !s2 && !s3 &&  s4 && !s5 && !s6 && !s7 && !s8 && !s9) {erro = -0.87;}  // Sensor 4     na linha branca
  else if (!s1 && !s2 && !s3 &&  s4 &&  s5 && !s6 && !s7 && !s8 && !s9) {erro = -0.44;}  // Sensor 4 e 5 na linha branca
  else if (!s1 && !s2 && !s3 && !s4 &&  s5 && !s6 && !s7 && !s8 && !s9) {erro =  0;}  // Sensor 5     na linha branca        POSIÇÃO IDEAL
  else if (!s1 && !s2 && !s3 && !s4 &&  s5 &&  s6 && !s7 && !s8 && !s9) {erro =  0.44;}  // Sensor 5 e 6 na linha branca
  else if (!s1 && !s2 && !s3 && !s4 && !s5 &&  s6 && !s7 && !s8 && !s9) {erro =  0.87;}  // Sensor 6     na linha branca
  else if (!s1 && !s2 && !s3 && !s4 && !s5 &&  s6 &&  s7 && !s8 && !s9) {erro =  1.31;}  // Sensor 6 e 7 na linha branca
  else if (!s1 && !s2 && !s3 && !s4 && !s5 && !s6 &&  s7 && !s8 && !s9) {erro =  1.74;}  // Sensor 7     na linha branca
  else if (!s1 && !s2 && !s3 && !s4 && !s5 && !s6 &&  s7 &&  s8 && !s9) {erro =  2.16;}  // Sensor 7 e 8 na linha branca
  else if (!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 &&  s8 && !s9) {erro =  2.59;}  // Sensor 8     na linha branca
  else if (!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 &&  s8 &&  s9) {erro =  3.00;}  // Sensor 8 e 9 na linha branca
  else if (!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 &&  s9) {erro =  3.42;}  // Sensor 9     na linha branca
}

void errorI()
{
  if      (!s1 &&  s2 &&  s3 &&  s4 &&  s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro = -3.42;}  // Sensor 1     na linha branca
  else if (!s1 && !s2 &&  s3 &&  s4 &&  s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro = -3.00;}  // Sensor 1 e 2 na linha branca
  else if ( s1 && !s2 &&  s3 &&  s4 &&  s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro = -2.59;}  // Sensor 2     na linha branca
  else if ( s1 && !s2 && !s3 &&  s4 &&  s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro = -2.16;}  // Sensor 2 e 3 na linha branca
  else if ( s1 &&  s2 && !s3 &&  s4 &&  s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro = -1.74;}  // Sensor 3     na linha branca
  else if ( s1 &&  s2 && !s3 && !s4 &&  s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro = -1.31;}  // Sensor 3 e 4 na linha branca
  else if ( s1 &&  s2 &&  s3 && !s4 &&  s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro = -0.87;}  // Sensor 4     na linha branca
  else if ( s1 &&  s2 &&  s3 && !s4 && !s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro = -0.44;}  // Sensor 4 e 5 na linha branca
  else if ( s1 &&  s2 &&  s3 &&  s4 && !s5 &&  s6 &&  s7 &&  s8 &&  s9) {erro =  0;}     // Sensor 5     na linha branca        POSIÇÃO IDEAL
  else if ( s1 &&  s2 &&  s3 &&  s4 && !s5 && !s6 &&  s7 &&  s8 &&  s9) {erro =  0.44;}  // Sensor 5 e 6 na linha brancas
  else if ( s1 &&  s2 &&  s3 &&  s4 &&  s5 && !s6 &&  s7 &&  s8 &&  s9) {erro =  0.87;}  // Sensor 6     na linha branca
  else if ( s1 &&  s2 &&  s3 &&  s4 &&  s5 && !s6 && !s7 &&  s8 &&  s9) {erro =  1.31;}  // Sensor 6 e 7 na linha branca
  else if ( s1 &&  s2 &&  s3 &&  s4 &&  s5 &&  s6 && !s7 &&  s8 &&  s9) {erro =  1.74;}  // Sensor 7     na linha branca
  else if ( s1 &&  s2 &&  s3 &&  s4 &&  s5 &&  s6 && !s7 && !s8 &&  s9) {erro =  2.16;}  // Sensor 7 e 8 na linha branca
  else if ( s1 &&  s2 &&  s3 &&  s4 &&  s5 &&  s6 &&  s7 && !s8 &&  s9) {erro =  2.59;}  // Sensor 8     na linha branca
  else if ( s1 &&  s2 &&  s3 &&  s4 &&  s5 &&  s6 &&  s7 && !s8 && !s9) {erro =  3.00;}  // Sensor 8 e 9 na linha branca
  else if ( s1 &&  s2 &&  s3 &&  s4 &&  s5 &&  s6 &&  s7 &&  s8 && !s9) {erro =  3.42;}  // Sensor 9     na linha branca
  else errorReduzido();
}

void errorReduzido()
{
  if      ( s3 && !s4 && !s5 && !s6 && !s7) {erro = -1.74;}  // Sensor 2 e 3 na linha branca
  else if ( s3 &&  s4 && !s5 && !s6 && !s7) {erro = -1.31;}  // Sensor 3 e 4 na linha branca
  else if (!s3 &&  s4 && !s5 && !s6 && !s7) {erro = -0.87;}  // Sensor 4     na linha branca
  else if (!s3 &&  s4 &&  s5 && !s6 && !s7) {erro = -0.44;}  // Sensor 4 e 5 na linha branca
  else if (!s3 && !s4 &&  s5 && !s6 && !s7) {erro =  0;}  // Sensor 5     na linha branca        POSIÇÃO IDEAL
  else if (!s3 && !s4 &&  s5 &&  s6 && !s7) {erro =  0.44;}  // Sensor 5 e 6 na linha branca
  else if (!s3 && !s4 && !s5 &&  s6 && !s7) {erro =  0.87;}  // Sensor 6     na linha branca
  else if (!s3 && !s4 && !s5 &&  s6 &&  s7) {erro =  1.31;}  // Sensor 6 e 7 na linha branca
  else if (!s3 && !s4 && !s5 && !s6 &&  s7) {erro =  1.74;}  // Sensor 7     na linha branca
}

void imprimeLeituraAnalogica(){
  Serial.print(analogRead(A0));Serial.print(" ");Serial.print(analogRead(A1));Serial.print(" ");Serial.print(analogRead(A2));Serial.print(" ");
  Serial.print(analogRead(A3));Serial.print(" ");Serial.print(analogRead(A4));Serial.print(" ");Serial.print(analogRead(A5));Serial.print(" ");
  Serial.print(analogRead(A6));Serial.print(" ");Serial.print(analogRead(A7));Serial.print(" ");Serial.print(analogRead(A8));Serial.print("\n");
}