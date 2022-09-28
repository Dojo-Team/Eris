void roundabout(int marcacoes)
{
  curva90Direita();
  int contador = 1;
  bool lastWhite = false;
  while(contador != marcacoes){
    readReduzidoAndSprint();
    if(!s9 && lastWhite)
      lastWhite = false;
    else if(s9 && !lastWhite)
      contador++;
  }
  while(s5 && s6 && s7 && s8 && s9){
    readReduzidoAndSprint();
  }
  curva90Direita();
}