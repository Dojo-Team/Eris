void curva90Direita(){
  analogWrite(motorL, 130);
  analogWrite(motorR, 0);
  delay(600);
}

void curva90Esquerda(){
  analogWrite(motorL, 0);
  analogWrite(motorR, 140);
  delay(600);
}