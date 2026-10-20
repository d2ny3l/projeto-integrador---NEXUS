# Programação do carrinho no geral
o controle do carrinho é pensado para percorrer as 4 direções, no projeto final ele será dirigido a partir de um volante cuja conexão se da por WiFi utilizando um protocolo MQTT.

## cerebro_nexus
esse código foi produzido inicialmente por boa parte da etapa 1 com o grupo tendo apenas em mente que o controle seria por WiFi, mas não detíamos de mais nenhuma outra ideia como se daria o desenrolar do processo, dito isso usamos o **mosquitto** como broker para iniciar o protocolo **MQTT**, o seu papel é servir como um mensageiro que enviará as mensagens que o usuário mandar para o **esp32** por meio de um tópico que está atrlado ao endereço de IP da rede.

## A rede
O endereço de IP usado provém do roteamento de internet do celular de um dos membros, porém quando for usado o volante oficial, o controle será substituído para ocorrer utilizando os parâmetros de funcionamento dele.

## ligação do protocolo mqtt
para comandar as direções do carrinho é necessario por em funcionamento um protocolo MQTT para que consiga-se publicar os comandos para o esp32 e ele interprete elas para que o carrinho realize uma ação desejada

### para ligar
digite no terminal:
```text
mosquitto -c "mosquitto.conf" -v
```

### publicação
para que o carrinho vá para alguma direção deve-se publicar uma mensagem no tópico do protocolo
#### caso for para frente:
```text
mosquitto_pub -h 10.181.154.230 -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "w"
```
ou
```text
mosquitto_pub -t "motor/comando" -u "nexus" -P "nexus123" -m "w"
```
#### para trás:
```text
mosquitto_pub -h 10.181.154.230 -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "s"
```
ou
```text
mosquitto_pub -t "motor/comando" -u "nexus" -P "nexus123" -m "s"
```
#### para a esquerda:
```text
mosquitto_pub -h 10.181.154.230 -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "a"
```
ou
```text
mosquitto_pub -t "motor/comando" -u "nexus" -P "nexus123" -m "a"
```
#### para a direita:
```text
mosquitto_pub -h 10.181.154.230 -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "d"
```
ou
```text
mosquitto_pub -t "motor/comando" -u "nexus" -P "nexus123" -m "d"
```
#### para ser parado:
```text
mosquitto_pub -h 10.181.154.230 -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "DESLIGA"
```
ou
```text
mosquitto_pub -t "motor/comando" -u "nexus" -P "nexus123" -m "DESLIGA"
```

No caso na avaliação da etapa 1 de nosso grupo estaremos publicando essas mensagens no tópico "motor/comando" pelo celular a partir de um aplicativo chamado "Iot MQTT panel" para dispositivos android  
