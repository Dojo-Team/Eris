void curva90Direita(){
  while(s6){
    readReduzidoAndSprint();
  }
  darReDireita(350, 80);
  while(!s6){
    analogWrite(motorL, 150);
    analogWrite(motorR, 0);
    readS();
  }
}

void curva90Esquerda(){
  while(s3){
    readReduzidoAndSprint();
  }
  darRe(350, 80);
  while(!s3){
    analogWrite(motorR, 130);
    analogWrite(motorL, 0);
    readS();
  }
}