//MOTORES
int IN1 = 3, IN2 = 4, IN3 = 5, IN4 = 6;

//sensores
bool s1, s2, s3, s4, s5, s6, s7, s8, s9;

//Motores
int motorR = 2, motorL = 7;

//Constantes PID
float Kp = 95, Ki = 0.2, Kd = 80;
//float Kp = 76, Ki = 0.1, Kd = 73;
int const maxVelo = 240;
int const minVelo = 35;
int const maxI = 80; 
int const minI = -80;

//Variaveis para calcular o PID
float P = 0, I = 0, D = 0, PID = 0;
float erro = 0, erro_antes = 0, erro_d = 0;
unsigned long time = 0, tempo_d = 0;

//Identificador de faixa de pedestres
bool faixa = false;

//Velocidades iniciais dos motores
int speedR = 200, speedL = 200;

void setup() {
    //MOTORES
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    Serial.begin(9600);

    //MOTORES SEMPRE ANDAM PARA FRENTE
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void loop() {
    readS();
    error();
    desafios();
    sprint();
    // Serial.print(s1);Serial.print(" ");Serial.print(s2);Serial.print(" ");Serial.print(s3);Serial.print(" ");
    // Serial.print(s4);Serial.print(" ");Serial.print(s5);Serial.print(" ");Serial.print(s6);Serial.print(" ");
    // Serial.print(s7);Serial.print(" ");Serial.print(s8);Serial.print(" ");Serial.print(s9);Serial.print("\n");
}

void sprint ()
{
  if(erro != erro_antes){
    tempo_d = time + 50;
    erro_d = erro_d + erro - erro_antes;                   
  }
  if(tempo_d < time){
    erro_d = 0;
  }
  P = erro;
  D = erro_d;
  I = I > maxI ? maxI : I;
  I = I < minI ? minI : I;
  PID = (Kp * P) + (Kd * D) + (Ki * I);
  erro_antes = erro;
  //Serial.print(P);Serial.print(" - ");Serial.print(I);Serial.print(" - ");Serial.print(D);Serial.print(" - ");Serial.print(PID);Serial.print("\n");
  
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
  andarFrente();
}

void andarFrente(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void darReDireita(int ms, int velocidade){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(motorR, velocidade);
  analogWrite(motorL, 0);
  delay(ms);
  andarFrente();
}

void darRe(int ms, int velocidade){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  analogWrite(motorR, velocidade);
  analogWrite(motorL, velocidade);
  delay(ms);
  andarFrente();
}