#include <WiFi.h>
#include <PubSubClient.h>


//conexão WiFi
const char* ssid = ":D";
const char* senha = "12345678";

//definindo o IP que receberá o protocolo
const char* mqtt_server = "10.181.154.230";
const int mqtt_porta = 1883;

//usuário e senha do mosquitto
const char* usuario = "nexus";
const char* mqtt_senha = "nexus123";

//define o esp32 como cliente
WiFiClient espClient;
PubSubClient client(espClient);


//portas
const int IN1 = 32, IN2 = 33, IN3 = 25, IN4 = 26, ENA = 27, ENB = 14;

//variaveis
String mensagem;

bool estadoIN3;
bool estadoIN4;
bool estadoIN1;
bool estadoIN2;



//callback, nele está o que o esp32 mostrará/realizará quando estabelecer a conexão 
void callback (char* topic, byte* payload, unsigned int tamanho) {
  Serial.print("mensagem recebida [");
  Serial.print(topic);
  Serial.print("]: ");

   for (int i = 0; i < tamanho; i++) {

    mensagem += (char)payload[i];
    
    Serial.print("mensagem [");
    Serial.print(mensagem);
    Serial.println("]");
  }


  //pwm dos motores
  analogWrite(ENA, 128);
  analogWrite(ENB, 128);


  //o que o esp32 deve interpretar para cada uma dessas mensagens que serão enviadas para o tópico 
if (mensagem == "w"){ 
    estadoIN3 = HIGH;
    estadoIN4 = LOW;
    estadoIN1 = HIGH;
    estadoIN2 = LOW;
    mensagem = "";

}
if (mensagem == "DESLIGA") {
    estadoIN3 = LOW;
    estadoIN4 = LOW;
    estadoIN1 = LOW;
    estadoIN2 = LOW;

    for(int i = 128; i>=0; i--) {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      delay(15);
    }
   mensagem = "";
  
    }


  if (mensagem == "s") {
    estadoIN3 = LOW;
    estadoIN4 = HIGH;
    estadoIN1 = LOW;
    estadoIN2 = HIGH;
    mensagem = "";
  }
  if(mensagem == "a"){
  analogWrite(ENB, 64);
  analogWrite(ENA, 128);

  mensagem = ""; 
  }
 if(mensagem == "d"){
   analogWrite(ENA, 64);
  analogWrite(ENB, 128);

  mensagem = "";  
  }

  Serial.println();

  digitalWrite(IN3, estadoIN3);
  digitalWrite(IN4, estadoIN4);
  digitalWrite(IN1, estadoIN1);
  digitalWrite(IN2, estadoIN2);


}

//definindo a conexão e inscrevendo o esp32 no tópico do broker
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
  //monitor serial
  Serial.begin(115200);
  delay(2000);

  //conectando o esp32 à rede WiFi
  WiFi.begin(ssid, senha);
  WiFi.mode(WIFI_STA);

  while(WiFi.status() != WL_CONNECTED){
    delay(10000);
    Serial.print(".");
  }

  Serial.println("\n conectado");
  Serial.println("IP do esp:");
  Serial.println(WiFi.localIP());


  //setando o IP e a porta usada para o protocolo assim como definindo o callback
  client.setServer(mqtt_server, mqtt_porta);
  client.setCallback(callback);
 

  //definindo as portas da ponte H como saídas digitais
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //estado inicial das portas da ponte H
  estadoIN3 = LOW;
  estadoIN4 = LOW;
  estadoIN1 = LOW;
  estadoIN2 = LOW;


}

void loop() {
  if(!client.connected()) reconnect();

  client.loop();

}
