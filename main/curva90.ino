void curva90Direita(){
  analogWrite(motorL, 150);
  analogWrite(motorR, 0);
  delay(800);
}

void curva90Esquerda(){
  analogWrite(motorL, 0);
  analogWrite(motorR, 150);
  delay(800);
}