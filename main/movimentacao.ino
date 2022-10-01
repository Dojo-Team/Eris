void sprint ()
{
  if(erro != erro_antes){
    tempo_d = time + 50;
    erro_d = erro_d + erro - erro_antes;                   
  }
  if(tempo_d < time)
    erro_d = 0;
  
  P = erro;
  D = erro_d;
  I = I > maxI ? maxI : I;
  I = I < minI ? minI : I;
  PID = (Kp * P) + (Kd * D) + (Ki * I);
  erro_antes = erro;
  
  speedL += PID;
  speedR -= PID;

  if(speedR < minVelo)
    speedR = minVelo;  
  else if(speedR > maxVelo)
    speedR = maxVelo;
  if(speedL < minVelo)
    speedL = minVelo;
  else if(speedL > maxVelo)
    speedL = maxVelo;
    
  analogWrite(motorR, speedR);
  analogWrite(motorL, speedL);
}

void parar(int ms) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(ms);
  definirMotoresFrente();
}

void definirMotoresFrente(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void definirMotoresTras(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void darReDireita(int ms, int velocidade){
  definirMotoresTras();  
  analogWrite(motorR, velocidade);
  analogWrite(motorL, 0);
  delay(ms);
  definirMotoresFrente();
}

void darReEsquerda(int ms, int velocidade){
  definirMotoresTras();  
  analogWrite(motorR, 0);
  analogWrite(motorL, velocidade);
  delay(ms);
  definirMotoresFrente();
}

void darRe(int ms, int velocidade){
  definirMotoresTras();
  analogWrite(motorR, velocidade);
  analogWrite(motorL, velocidade);
  delay(ms);
  definirMotoresFrente();
}

void readReduzidoAndSprint(){
  readS();
  errorReduzido5Sensores();
  sprint();
}

void readReduzidoAndSprint(int ms){
  int inicio = millis();
  while(millis() < inicio + ms){
    readS();
    errorReduzido5Sensores();
    sprint();
  }
}