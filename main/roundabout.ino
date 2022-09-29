void roundabout(int marcacoes, bool isDireita)
{
  Serial.print("Saída: ");
  Serial.print(marcacoes - 1);
  Serial.print("\n");
  curva90Direita();
  int contador = 1;
  bool lastWhite = false;
  while(contador != marcacoes){
    readReduzidoAndSprint();
    if((!s9 || !s1) && lastWhite)
      lastWhite = false;
    else if((!s9 || !s1) && !lastWhite){
      lastWhite = true;
      contador++;
    }
    Serial.print("Ainda no while\n");
  }
  Serial.print("Saiu do while\n");
  while(s5 && s6 && s7 && s8 && s9){
    readReduzidoAndSprint();
  }
  Serial.print("Fazer curva 90 direita");
  if(isDireita)
    curva90Direita();
  else
    curva90Esquerda();
}