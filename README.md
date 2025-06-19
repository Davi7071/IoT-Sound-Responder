# IoT Sound‑Activated Feedback Device

Um projeto de dispositivo IoT baseado em ESP32 que reconhece um som configurável via app (Expo/React Native) e responde com movimento de servo, LED e buzzer.

---

## 📋 Descrição

Este projeto conecta um microfone, um servo motor, um LED e um buzzer a um ESP32 DevKit.  
Através de um app mobile feito em Expo/React Native, você pode configurar o “som de ativação” (por exemplo, um estalo de palmas ou um assobio). Quando o ESP32 detecta esse padrão sonoro, ele:

1. **Aciona o servo** (movimenta-se para uma posição predefinida).  
2. **Liga o LED** (indica visualmente a detecção).  
3. **Toca um som no buzzer** (feedback sonoro).

Tudo isso em um único dispositivo compacto, ideal para protótipos de automação, brinquedos interativos ou projetos de acessibilidade.

---

## 🛠️ Tecnologias e Bibliotecas

- **Hardware**  
  - ESP32 DevKit C V4  
  - Microfone MEMS (tipo Wokwi)  
  - Servo motor (5 V)  
  - LED vermelho + resistor 220 Ω  
  - Buzzer piezo

- **Firmware**  
  - Arduino IDE / PlatformIO  
  - Biblioteca [ESP32Servo] para controle de servo

- **Software Mobile**  
  - Expo (React Native)  
  - BLE (Bluetooth Low Energy) para comunicação com o ESP32

---

## 🔗 Esquema de Ligações

Com base no arquivo `diagram.json`, o circuito está montado da seguinte forma:

| Dispositivo     | Pino ESP32     | Conexão         |
| --------------- | -------------- | --------------- |
| Microfone VIN   | 3V3 / 5V       | Entrada de energia  |
| Microfone GND   | GND            | Terra           |
| Microfone OUT   | GPIO 15        | Sinal de áudio  |
| Servo V+        | 5V             | Entrada de energia  |
| Servo GND       | GND            | Terra           |
| Servo PWM       | GPIO 18        | Controle PWM    |
| LED → Resistor  | GPIO 2         | Sinal digital   |
| Buzzer +        | GPIO 4         | Sinal digital   |
| Buzzer –        | GND            | Terra           |

> Consulte `diagram.json` para detalhes de posicionamento e roteamento.

---

## 🚀 Como Rodar

### 1. Firmware (ESP32)

1. Abra o Arduino IDE (ou PlatformIO).  
2. Instale a placa **ESP32 Dev Module** (pelo “Boards Manager”).  
3. Instale a biblioteca **ESP32Servo** via Library Manager.  
4. Carregue este repositório e abra `sketch.ino`.  
5. Selecione a porta e o modelo “ESP32 Dev Module” em **Tools** → **Board**.  
6. Clique em **Upload**.

### 2. App Mobile (Expo)

1. Instale o Expo CLI (se ainda não tiver):
   ```bash
   npm install -g expo-cli
   ```
2. No diretório `app/`, instale dependências:
   ```bash
   npm install
   ```
3. Execute o app em desenvolvimento:
   ```bash
   expo start
   ```
4. No app, conecte‑se via Bluetooth ao seu ESP32 e selecione ou grave o som de ativação.

---

## 📱 Simulação Online

Você pode testar uma versão virtual no Wokwi:
- Projeto Wokwi: https://wokwi.com/projects/431515491564407809

---

## 📝 Estrutura de Arquivos

```
├── diagram.json          ← Esquema de ligações Wokwi
├── libraries.txt         ← Lista de bibliotecas usadas
├── sketch.ino            ← Código Arduino para ESP32
└── app/                  ← Código Expo/React Native (mobile)
```

---

## ⚙️ Configurações

- **Sensibilidade do microfone** e **padrão de som** podem ser ajustados diretamente no código ou via comandos BLE enviados pelo app.  
- **Ângulo do servo**, **duração do LED** e **frequência do buzzer** também estão parametrizados no firmware.

---

## 📄 Licença

Este projeto está licenciado sob a **MIT License** — veja o arquivo [`LICENSE`](./LICENSE) para mais detalhes.

---

> Desenvolvido por você, entusiasta de IoT e prototipagem rápida!  
> Feedbacks e contribuições são bem‑vindos. 😊
