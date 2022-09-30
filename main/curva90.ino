void curva90Direita(){
  analogWrite(motorL, 130);
  analogWrite(motorR, 0);
  int contador = 0;
  bool lastWhite = false;
  while(contador < 3){
    readS();
    if(lastWhite && !s2)
      lastWhite = false;
    else if(!lastWhite && s2){
      lastWhite = true;
      contador++;
    }
  }
}

void curva90Esquerda(){
  analogWrite(motorL, 0);
  analogWrite(motorR, 130);
  int contador = 0;
  bool lastWhite = false;
  while(contador < 3){
    readS();
    if(lastWhite && !s8 && !s8)
      lastWhite = false;
    else if(!lastWhite && s8 && s8){
      lastWhite = true;
      contador++;
    }
  }
}