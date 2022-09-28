void desafios(){
  if(s1 && !s3 && (s4 || s5 || s6)){
    while(s5 && s6 && s7 && s8 && s9){
      readReduzidoAndSprint();
    }
    curva90Esquerda();
    Serial.print("Curva 90 esquerda");
  }
  else if(s9 && !s7 && (s6 || s5 || s4)){
    identificarDesafio();
    Serial.print("Identificar Desafio");
  }
  else if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
      analogWrite(motorR, 0);
      analogWrite(motorL, 0);
      readS();
      if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
        delay(5000);
      }
  }
  else if((s1 && s2 && s3 && !s5 && s7 && s8 && s9) && (!s4 || !s6)){
    faixa = true;
    while(faixa){
      faixaPedestre();
      Serial.print("Faixa");

    }
  }
}

void identificarDesafio(){
  int contador = 1;
  bool lastWhite = true;
  while(true){
    readReduzidoAndSprint();
    if(s5 && s6 && s7 && s8 && s9)
      break;
    if(!s9 && lastWhite)
      lastWhite = false;
    else if(s9 && !lastWhite)
      contador++;
  }
  if(contador == 1){    
    while(s5 && s6 && s7 && s8 && s9){
      readReduzidoAndSprint();
    }
    curva90Direita();
  }
  else{
    Serial.print("Rotatoria");
    roundabout(contador);
  }
}

void readReduzidoAndSprint(){
  readS();
  errorReduzido();
  sprint();
}
