void roundabout(int marcacoes)
{
  int contador = 1;
  bool lastWhite = false;
  while(contador != marcacoes){
    readReduzidoAndSprint();
    if(!s9 && lastWhite)
      lastWhite = false;
    else if(s9 && !lastWhite)
      contador++;
  }
  readReduzidoAndSprint();
  delay(100);
  analogWrite(motorR, 20);
  analogWrite(motorL, 150);
  delay(100);
  readReduzidoAndSprint();
}