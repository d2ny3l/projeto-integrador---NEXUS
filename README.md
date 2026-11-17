# projeto integrador - corrida de carrinhos
## Equipe
**Nome:** NEXUS 
**Turma:** Meca3M
**Professor técnico:** Breno Meira Moura de Amorim
### Integrantes e suas funçoes
| Integrante | Área principal | Responsabilidades |
|---|---|---|
| Maria Camily | Piloto e calibração | Testes de dirigibilidade, calibração e operação |
| João Mario | Mecânica | Chassi, direção, transmissão e montagem |
| Pedro Ismael | Projeto e documentação | Arquitetura, desenhos, organização da documentação |
| Flavia Ludmila | Eletrônica e integração elétrica | Alimentação, drivers, motores, sensores e conexões |
| Daniel Medeiros | Software e controle | Comunicação, controle, sensores e automação |

---

## Objetivo do projeto
Desenvolver um veículo terrestre em pequena escala para participação na Competição de Carrinhos do Projeto Integrador. O veículo deverá percorrer a pista definida pela organização, respeitando os requisitos do regulamento e utilizando a interface de controle disponibilizada.

---

## Conceito da solução
-
-
-
-

---

## Arquitetura geral
ainda será organizada

### Subsistemas
- **Mecânica:** Responsável pela estrutura física do carrinho, chassi, fixação de motores, rodas e alinhamento das peças para garantir estabilidade e mobilidade.
- **Eletrônica:** Responsável pela integração dos componentes de hardware, incluindo o microcontrolador (ESP32), drivers de motor e a fiação que conecta todo o circuito.
- **Software:** Desenvolvimento e implementação do código responsável por controlar os motore e receber os comandos externos para fazer o carrinho se movimentar corretamente.
- **Comunicação:** Gerenciamento da forma como o carrinho recebe comandos
- **Alimentação:**  Sistema responsável por fornecer energia estável e segura para todo o circuito, gerenciando baterias e o fluxo elétrico para motores e eletrônica.

---

## Estado atual do projeto
O progresso foi lento no inicio mas agora estamos com ele 50% pronto
Estamos com a parte da eletrônica toda pronta(tanto física como o esquema digital), avançamos no código e no desenho técnico e iniciamos o processo da mecânica no chassi, adaptando a estrutura do chassi.

### Concluído
- [ ] Definição da arquitetura geral
- [X] Projeto mecânico inicial
- [X] Diagrama elétrico inicial
- [ ] Comunicação com o sistema da organização
- [X] Controle dos motores em bancada
- [X] Integração mecânica
- [X] Integração eletroeletrônica
- [X] Teste do veículo em movimento
- [ ] Integração da câmera
- [ ] Outros: ____________________
### Em produção
- a parte mecânica do carro(adaptando ele para uso)
- desenho mecânico do carro 
- código para o carro
- testes para o funcionamento do carro em movimento
  
### Principais pendencias
- teste do carro com o volante
- testar a integração da câmera

---

## planejamento
O registro das atividades semanais esta disponivel em:
[`PROGRESSO.md`](PROGRESSO.md)

---

## Documentação tecnica
```text
docs/
├── arquitetura/
├── mecanica/
├── eletronica/
├── software/
└── testes/
```
### Documentos disponíveis
- **Arquitetura geral:** 
- **Projeto mecânico:** [`mecanica`](mecanica)
- **Diagrama elétrico:** https://u.easyeda.com/join?type=project&key=a5a37572f226f9c19857f67c44e03b58&inviter=37e47553772144d29d3ed184d3266b24
- **Documentação do software:** [`softwares`](softwares)
- **Lista de materiais:** 
- **Registros de testes:**

---

## Materiais e componentes
| Item | Quantidade | Origem | Situação |
|---|---:|---|---|
| ESP32 | 1 | Kit da organização | Disponível |
| Motor DC | 2 | Kit da organização | Disponível |
| Driver de motor | 1 | Kit da organização | Disponível |
| ____________________ | ___ | Equipe / organização | ____________________ |
 
---

## comunicação com a organização
### Comandos
-
-
-
-
### Telemetria
-
-
-

---

## Testes realizados
| Data | Teste | Resultado | Próxima ação |
|---|---|---|---|
| 21/09/2026 |verificamos se os motores, a ponte H e Esp32 do kit estava funcionando |nosso esp estava queimado | substituir o esp32 por outro |


---

## Observações 
- o documento está com algumas pendências mas em breve serão ajustadas.
