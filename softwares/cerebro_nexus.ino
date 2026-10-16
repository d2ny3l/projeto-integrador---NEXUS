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


const int IN1 = 3, IN2 = 4, IN3 = 5, IN4 = 6, ENA, ENB;

String mensagem = "";

bool estadoIN3;
bool estadoIN4;
bool estadoIN1;
bool estadoIN2;

Servo myservo;
int servoPin = 13;


void callback (char* topico, byte* payload, unsigned int tamanho) {
  Serial.print("mensagem recebida [");
  Serial.print(topico);
  Serial.print("]: ");

   for (int i = 0; i < tamanho; i++) {

    mensagem=(char)payload[i];
    
  }

  
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN3, estadoIN3);
  digitalWrite(IN4, estadoIN4);
  digitalWrite(IN1, estadoIN1);
  digitalWrite(IN2, estadoIN2);

if (mensagem == "w"){
  estadoIN3 = HIGH;
  estadoIN4 = LOW;
  estadoIN1 = HIGH;
  estadoIN2 = LOW;

}
if (mensagem == "DESLIGA") {
  estadoIN3 = LOW;
  estadoIN4 = LOW;
  estadoIN1 = LOW;
  estadoIN2 = LOW;

   for(int i = 255; i>=0; i--) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(15);
   }
  
    }
}

  if (mensagem == "s") {
    estadoIN3 = LOW;
    estadoIN4 = HIGH;
    estadoIN1 = LOW;
    estadoIN2 = HIGH;
  }
  if(mensagem == "d"){
  analogWrite(ENB, 128);
  analogWrite(ENA, 255);

  myservo.write(315);  
  }
 if(mensagem == "a"){
  analogWrite(ENA, 128);
  analogWrite(ENB, 255);

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

  WiFi.begin(ssid, senha);
  WiFi.mode(WIFI_STA);

  while(WiFi.status() != WL_CONNECTED){
    delay(10000);
    Serial.print(".");
  }

  Serial.println("\n conectado");
  Serial.println("IP do esp:");
  Serial.println(WiFi.localIP());


  client.setServer(mqtt_server, mqtt_porta);
  client.setCallback(callback);

  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400); 

  estadoIN3 = LOW;
  estadoIN4 = LOW;
  estadoIN1 = LOW;
  estadoIN2 = LOW;


}

void loop() {
  if(!client.connected()) reconnect();

  client.loop();

}
