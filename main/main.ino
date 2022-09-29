//MOTORES
int IN1 = 3, IN2 = 4, IN3 = 5, IN4 = 6;

//sensores
bool s1, s2, s3, s4, s5, s6, s7, s8, s9;

//Motores
int motorR = 2, motorL = 7;

//Constantes PID
float Kp = 76, Ki = 0, Kd = 38;
//float Kp = 15, Ki = 0.1, Kd = 2;

//Variaveis para calcular o PID
float P = 0, I = 0, D = 0, PID = 0;
int erro = 0, erro_antes = 0;

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
  P = erro;
  I = I + erro;
  D = erro - erro_antes;
  PID = (Kp * P) + (Kd * D) + (Ki * I);
  
  speedL += PID;
  speedR -= PID;
  int maxVelo = 180;
  int minVelo = 20;
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
