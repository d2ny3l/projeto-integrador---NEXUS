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
mosquitto_pub -h -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "w"
```
#### para trás:
```text
mosquitto_pub -h -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "s"
```
#### para a esquerda:
```text
mosquitto_pub -h -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "a"
```
#### para a direita:
```text
mosquitto_pub -h -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "d"
```
#### para ser parado:
```text
mosquitto_pub -h -p 1883 -t "motor/comando" -u "nexus" -P "nexus123" -m "DESLIGA"
```
