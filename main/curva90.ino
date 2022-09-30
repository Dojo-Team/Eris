void curva90Direita(){
  while(s6){
    readReduzidoAndSprint();
  }
  while(!s6){
    analogWrite(motorL, 130);
    analogWrite(motorR, 0);
    readS();
  }
}

void curva90Esquerda(){
  while(s3){
    readReduzidoAndSprint();
  }
  analogWrite(motorR, 0);
  analogWrite(motorL, 0);
  delay(50);
  while(!s3){
    analogWrite(motorR, 130);
    analogWrite(motorL, 0);
    readS();
  }
}