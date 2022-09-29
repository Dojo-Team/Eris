void curva90Direita(){
  analogWrite(motorL, 165);
  analogWrite(motorR, 0);
  delay(500);
}

void curva90Esquerda(){
  analogWrite(motorL, 0);
  analogWrite(motorR, 165);
  delay(500);
}