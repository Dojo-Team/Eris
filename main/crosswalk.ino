void faixaPedestre()
{
	readS();
	errorI();
	sprint();
	if ((s5 || s4 || s6) && !s9 && !s1 && !s8 && !s7)
	{
		readS();
		error();
		sprint();
	}
	else if (!s3 && !s4 && !s5 && !s6 && !s7) {
		parar(6000);
		analogWrite(motorR, 135);
		analogWrite(motorL, 165);
		delay(800);
    darRe(200, 70);
    readS();
    bool isDireita = true;
    while(tudoPreto()){
      readS();
      if(isDireita){
        analogWrite(motorR, 0);
		    analogWrite(motorL, 165);
        delay(250);
      }
      else{
        analogWrite(motorR, 165);
		    analogWrite(motorL, 0);
        delay(350);
      }
      isDireita = !isDireita;
    }
		faixa = false;
	}
}