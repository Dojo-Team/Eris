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
  desafios();
  error();
  sprint();
}