void desafios(){
  if(s1 && !s3 && (s4 || s5 || s6)){
    // Serial.print("Curva 90 esquerda\n");
    // while(true){
    //   if(s5 && s6 && s7 && s8 && s9)
    //     break;
    //   readReduzidoAndSprint();
    // }
    // curva90Esquerda();
  }
  else if(s9 && s8 && !s7 && (s6 || s5 || s4)){
    Serial.print("Identificar Desafio\n");
    identificarDesafio();
  }
  else if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
    readReduzidoAndSprint(300);
    readS();
    if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
      analogWrite(motorR, 120);
      analogWrite(motorL, 0);
      delay(200);
      readS();
      if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
        analogWrite(motorR, 0);
        analogWrite(motorL, 120);
        delay(500);
        if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
          parar();
          delay(7000);
        }
      } 
    }
  }
  else if((s1 && s2 && s3 && !s5 && s7 && s8 && s9) && (!s4 || !s6)){
    Serial.print("Faixa\n");
    faixa = true;
    while(faixa){
      faixaPedestre();
    }
  }
}

void identificarDesafio(){
  int contador = 1;
  bool lastWhite = true;
  while(true){
    readReduzidoAndSprint();
    Serial.print(contador);
    Serial.print("\n");
    if(s5 && s6 && s7 && s8 && s9)
      break;
    if(!s9 && lastWhite)
      lastWhite = false;
    else if(s9 && !lastWhite){
      contador++;
      lastWhite = true;
    }
  }

  Serial.print(contador);
  Serial.print("Final contador\n");

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

void readReduzidoAndSprint(int ms){
  int inicio = millis();
  while(millis() < inicio + ms){
    readS();
    errorReduzido();
    sprint();
  }
}

