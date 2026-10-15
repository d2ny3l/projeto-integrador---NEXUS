#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h>

const char* ssid = ":D";
const char* senha = "12345678";

const char* mqtt_server = "172.22.57.230";
const int mqtt_porta = 1883;

const char* usuario = "nexus";
const char* mqtt_senha = "nexus123";

WiFiClient espClient;
PubSubClient client(espClient);


const int IN1 = 3, IN2 = 4, IN3 = 5, IN4 = 6;

String mensagem = "";

bool estadoIN3;
bool estadoIN4;
bool estadoIN1;
bool estadoIN2;

Servo myservo;
int servoPin = 13;


void conexao_wifi(void){

  WiFi.begin(ssid, senha);
  WiFi.mode(WIFI_STA);

  while(WiFi.status() != WL_CONNECTED){
    delay(10000);
    Serial.print(".");
  }

  Serial.println("\n conectado");
  Serial.println("IP do esp:");
  Serial.println(WiFi.localIP());


}

void callback (char* topico, byte* payload, unsigned int tamanho) {
  Serial.print("mensagem recebida [");
  Serial.print(topico);
  Serial.print("]: ");

   for (int i = 0; i < tamanho; i++) {

    mensagem=(char)payload[i];
    
  }
if (mensagem == "DESLIGA") {
  bool estadoIN3 = LOW;
bool estadoIN4 = LOW;
bool estadoIN1 = LOW;
bool estadoIN2 = LOW;
   digitalWrite(IN3, estadoIN3);
   digitalWrite(IN4, estadoIN4);
   digitalWrite(IN1, estadoIN1);
   digitalWrite(IN2, estadoIN2);
  
    }
}

  if (mensagem == "s") {
    estadoIN3 = LOW;
    estadoIN4 = HIGH;
    digitalWrite(IN3, estadoIN3);
    digitalWrite(IN4, estadoIN4);
  }
  if(mensagem == "d"){
  digitalWrite(IN3, estadoIN3);
  digitalWrite(IN4, estadoIN4);
  analogWrite(ENB, estadoVelo);
  myservo.write(315);  
  }
 if(mensagem == "a"){
  digitalWrite(IN3, estadoIN3);
  digitalWrite(IN4, estadoIN4);
  analogWrite(ENB, estadoVelo);
  myservo.write(225);  
  }
  Serial.println();

}

void reconnect() {
  while(!client.connected()){
    Serial.print("conectando MQTT");
    if(client.connect("ESP32", usuario, mqtt_senha)){
      Serial.print("conectado");
      client.subscribe("motor/comando");
    }
    else {
      Serial.print("falhou, codigo: ");
      Serial.print(client.state());
      Serial.println("tentando novamente.......");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  conexao_wifi();

  client.setServer(mqtt_server, mqtt_porta);
  client.setCallback(callback);

  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400); 

  bool estadoIN3 = LOW;
bool estadoIN4 = LOW;
bool estadoIN1 = LOW;
bool estadoIN2 = LOW;


}

void loop() {
  if(!client.connected()) reconnect();

  client.loop();

}
