void roundabout(int marcacoes)
{
  int contador = 1;
  bool lastWhite = false;
  while(contador != marcacoes){
    readAndSprint();
    if(!s9 && lastWhite)
      lastWhite = false;
    else if(s9 && !lastWhite)
      contador++;
  }
  readAndSprint();
  delay(100);
  analogWrite(motorR, 20);
  analogWrite(motorL, 150);
  delay(100);
  readAndSprint();
}