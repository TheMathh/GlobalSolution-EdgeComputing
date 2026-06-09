# 🚀 OrbitalWatch — Monitoramento Inteligente de Satélite

## 📌 Descrição do Projeto

O **OrbitalWatch** é um sistema de monitoramento embarcado desenvolvido para a disciplina de **Edge Computing & Computer Systems da FIAP**.

O projeto simula um sistema presente em um satélite, capaz de acompanhar informações importantes para seu funcionamento, como temperatura, luminosidade e comunicação com uma estação de controle.

A solução utiliza sensores conectados a um Arduino para coletar dados do ambiente, analisar as condições e gerar alertas visuais e sonoros quando alguma situação fora do esperado acontece.


---

## 🎯 Objetivo da Solução

O objetivo do projeto é desenvolver uma solução capaz de monitorar condições essenciais de um satélite e identificar possíveis falhas.

Em um ambiente espacial, fatores como variações extremas de temperatura, exposição à luz solar e perda de comunicação podem comprometer o funcionamento dos equipamentos.

Com isso, o OrbitalWatch busca representar um sistema de monitoramento que:

- Analisa dados em tempo real;
- Identifica condições normais ou críticas;
- Alerta sobre possíveis problemas;
- Auxilia na tomada de decisão.


---

## ⚙️ Funcionamento do Sistema

O sistema realiza a leitura de três principais informações:

### 🌡️ Temperatura

Um sensor **NTC** é utilizado para medir a temperatura simulada do satélite.

O Arduino interpreta os valores recebidos e classifica a condição em:

🟢 Normal  
🟡 Atenção  
🔴 Crítico


### ☀️ Luminosidade

Um sensor **LDR** mede a intensidade da luz recebida.

Essa informação representa a exposição do satélite à iluminação externa, como a luz solar.


### 📡 Comunicação

Um botão é utilizado para simular o estado do sinal do satélite:

- Botão pressionado → comunicação funcionando;
- Botão solto → perda de sinal.


Quando ocorre uma falha crítica:

- O LED vermelho é ativado;
- O buzzer emite um alerta;
- O LCD informa o problema identificado.


---

## 🧰 Componentes Utilizados

- Arduino Uno
- Sensor NTC (temperatura)
- Sensor LDR (luminosidade)
- Push Button (simulação de sinal)
- Display LCD 16x2 com módulo I2C
- LED Verde
- LED Amarelo
- LED Vermelho
- Buzzer
- Resistores
- Protoboard
- Jumpers


---

## 🔌 Estrutura do Circuito

O circuito foi desenvolvido utilizando um Arduino Uno conectado aos sensores responsáveis pelo monitoramento do satélite.

| Componente | Pino Arduino |
|---|---|
| Sensor NTC | A1 |
| Sensor LDR | A0 |
| Botão (sinal) | 6 |
| Buzzer | 7 |
| LED Verde | 8 |
| LED Amarelo | 9 |
| LED Vermelho | 10 |
| LCD I2C | SDA / SCL |


### Funcionamento das conexões:

O **NTC** realiza a leitura da temperatura através de um sinal analógico.

O **LDR** realiza a leitura da luminosidade presente no ambiente.

O **botão** representa a comunicação do satélite:

- Pressionado → sinal recebido;
- Solto → sinal perdido.


Os LEDs indicam o estado geral:

🟢 LED Verde:
Sistema funcionando normalmente.

🟡 LED Amarelo:
Alguma condição precisa de atenção.

🔴 LED Vermelho:
Problema crítico detectado.


O buzzer é utilizado como alerta sonoro em situações críticas.


---

## 💻 Tecnologias Utilizadas

- Arduino C/C++
- Sistemas embarcados
- Edge Computing
- Sensoriamento
- Processamento de dados em tempo real


---

## 📚 Dependências

Para executar o projeto é necessário:

- Arduino IDE

Biblioteca utilizada:

```
LiquidCrystal_I2C
```


Para instalar:

Arduino IDE → Ferramentas → Gerenciar Bibliotecas

Pesquisar:

```
LiquidCrystal_I2C
```

e instalar.


---

## ▶️ Instruções de Execução

### 1. Clone o repositório

```bash
git clone https://github.com/TheMathh/OrbitalWatch-GS-1ESPQ
```


### 2. Abra o projeto

Abra o arquivo:

```
OrbitalWatch.ino
```

utilizando a Arduino IDE.


### 3. Instale as dependências

Instale a biblioteca:

```
LiquidCrystal_I2C
```


### 4. Execute o projeto

Após iniciar o circuito:

- Ajuste o sensor NTC para alterar a temperatura;
- Altere o LDR para modificar a luminosidade;
- Pressione o botão para simular o sinal chegando;
- Solte o botão para simular perda de comunicação.


O LCD exibirá os valores coletados e os LEDs indicarão o estado atual do sistema.


---

## 📂 Código Fonte

O código do projeto foi desenvolvido em **Arduino/C++**.

O arquivo principal está disponível no repositório:

```
OrbitalWatch.ino
```

O código contém:

- Leitura dos sensores;
- Tratamento dos dados;
- Análise das condições;
- Controle dos LEDs;
- Controle do buzzer;
- Exibição das informações no LCD.


---

## 🎥 Demonstração

O vídeo de apresentação do projeto está disponível no repositório:

```
video/OrbitalWatch-apresentacao.mp4
```


---

## 👥 Integrantes do Grupo

- Mateus Alves Borges — RM 571424
- Arthur de Sá — RM 569526
- Anthony Leal Monteiro — RM 569616
- Gustavo Bidin — RM 570272


---

## 🛰️ Projeto Acadêmico

FIAP — Edge Computing & Computer Systems