
#define sensorPin 2   // Define o pino 2 para o sensor IR (sensor de linha)

const int PINO_ENA = 6;    // Define o pino 6 para o controle de velocidade do motor A
const int PINO_ENB = 5;    // Define o pino 5 para o controle de velocidade do motor B
const int PINO_IN1 = 4;    // Define o pino 4 para o controle da direção do motor A
const int PINO_IN2 = 3;    // Define o pino 3 para o controle da direção do motor A
const int PINO_IN3 = 8;    // Define o pino 8 para o controle da direção do motor B
const int PINO_IN4 = 7;    // Define o pino 7 para o controle da direção do motor B

const int LED_PIN = 9;     // Define o pino 9 para o LED 1
const int LED_PIN1 = 10;   // Define o pino 10 para o LED 2
const int LED_PIN2 = 11;   // Define o pino 11 para o LED 3

void setup() {
    pinMode(sensorPin, INPUT);  // Configura o pino do sensor como entrada (para ler o estado do sensor)

    // Configura os pinos dos LEDs como saída
    pinMode(LED_PIN, OUTPUT);   
    pinMode(LED_PIN1, OUTPUT);  
    pinMode(LED_PIN2, OUTPUT);  

    // Configura os pinos dos motores como saída
    pinMode(PINO_ENA, OUTPUT); 
    pinMode(PINO_ENB, OUTPUT);
    pinMode(PINO_IN1, OUTPUT);
    pinMode(PINO_IN2, OUTPUT);
    pinMode(PINO_IN3, OUTPUT);
    pinMode(PINO_IN4, OUTPUT);
    
    Serial.begin(9600);  // Inicializa a comunicação serial a 9600 bauds
}

void loop() {
    int estado = digitalRead(sensorPin);  // Lê o estado do sensor (retorna HIGH ou LOW)
    Serial.println(estado);  // Exibe o estado do sensor no monitor serial

    if (estado == 0) {  // Se o sensor detectar a cor preta (estado 0)
        // Controla os motores para mover o robô para frente
        digitalWrite(PINO_IN1, LOW); 
        digitalWrite(PINO_IN2, HIGH);
        digitalWrite(PINO_IN3, LOW);
        digitalWrite(PINO_IN4, HIGH);
        analogWrite(PINO_ENA, 255);  // Define a velocidade máxima do motor A
        analogWrite(PINO_ENB, 255);  // Define a velocidade máxima do motor B
    } else {  // Se o sensor detectar a cor branca (estado 1)
        // Controla os motores para mover o robô para trás
        digitalWrite(PINO_IN1, HIGH); 
        digitalWrite(PINO_IN2, LOW);
        digitalWrite(PINO_IN3, HIGH);
        digitalWrite(PINO_IN4, LOW);
        analogWrite(PINO_ENA, 255);  // Define a velocidade máxima do motor A
        analogWrite(PINO_ENB, 255);  // Define a velocidade máxima do motor B
    }

    delay(100);  // Aguarda 100 milissegundos antes de ler novamente o sensor
}