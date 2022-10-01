void desafios(){
  if(s1 && !s3 && (s4 || s5 || s6) && !s7){
    readReduzidoAndSprint(50);
    readS();
    if(s1 && !s3 && (s4 || s5 || s6) && !s7){
      Serial.print("Identificar desafio esquerda\n");
      identificarDesafioEsquerda();
    }
  }
  else if(s9 && !s7 && (s6 || s5 || s4) && !s3){
    readReduzidoAndSprint(50);
    readS();
    if(s9 && !s7 && (s6 || s5 || s4) && !s3){
      Serial.print("Identificar desafio direita\n");
      identificarDesafioDireita();
    }
  }
  else if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
    readReduzidoAndSprint(300);
    readS();
    if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
      analogWrite(motorR, 0);
      analogWrite(motorL, 120);
      delay(200);
      readS();
      if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
        analogWrite(motorR, 150);
        analogWrite(motorL, 0);
        delay(500);
        if(!s1 && !s2 && !s3 && !s4 && !s5 && !s6 && !s7 && !s8 && !s9){
          parar(7000);
        }
      } 
    }
  }
  else if((s1 && s2 && s3 && !s5 && s7 && s8 && s9) && (s4 || s6)){
    Serial.print("Faixa\n");
    faixa = true;
    while(faixa){
      faixaPedestre();
    }
  }
}

void identificarDesafioEsquerda(){
  int contador = 1;
  bool lastWhite = true;
  while(true){
    readReduzidoAndSprint();
    Serial.print(contador);
    Serial.print("\n");
    if(s1 && s2 && s3 && s4 && s5)
      break;
    if(!s1 && lastWhite)
      lastWhite = false;
    else if(s1 && !lastWhite){
      contador++;
      lastWhite = true;
    }
  }

  Serial.print(contador);
  Serial.print("Final contador\n");

  if(contador == 1){    
    while(s5 && s6 && s7 && s8 && s9){
      readReduzidoAndSprint();
      readS();
    }
    curva90Esquerda();
  }
  else{
    Serial.print("Rotatoria");
    roundabout(contador, false);
  }
}

void identificarDesafioDireita(){
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
      readS();
    }
    curva90Direita();
  }
  else{
    Serial.print("Rotatoria");
    roundabout(contador, true);
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

