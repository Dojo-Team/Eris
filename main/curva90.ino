void curva90Direita(){
  while(s6 && s7)
    readReduzidoAndSprint();
  darReDireita(350, 80);
  while(!s6 && !s7){
    analogWrite(motorL, 150);
    analogWrite(motorR, 0);
    readS();
  }
}

void curva90Esquerda(){
  while(s3 && s4)
    readReduzidoAndSprint();
  darReEsquerda(350, 80);
  while(!s3 && !s4){
    analogWrite(motorR, 150);
    analogWrite(motorL, 0);
    readS();
  }
}