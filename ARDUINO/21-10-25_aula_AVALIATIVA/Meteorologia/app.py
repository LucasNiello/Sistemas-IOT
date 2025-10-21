import serial
import threading
import time
import json
from flask import Flask, jsonify, render_template

app = Flask(__name__)

temperatura_atual = None
umidade_atual = None

estado_leds = {1: False, 2: False}

# Tente abrir a porta serial (troque 'COM3' pela sua porta correta)
try:
    ser = serial.Serial('COM3', 9600, timeout=1)
    print("Porta serial aberta com sucesso.")
except serial.SerialException:
    print("Erro: Porta serial não encontrada. Verifique a conexão e a porta.")
    ser = None

def ler_serial():
    global temperatura_atual, umidade_atual
    while True:
        if ser is None:
            time.sleep(1)
            continue
        try:
            linha = ser.readline().decode('utf-8').strip()
            if linha:
                # Esperamos JSON, ex: {"temperatura":25.4,"umidade":60.1}
                dados = json.loads(linha)
                temperatura_atual = dados.get("temperatura")
                umidade_atual = dados.get("umidade")
                print(f"Lido Serial - Temp: {temperatura_atual}, Umid: {umidade_atual}")
        except Exception as e:
            print(f"Erro ao ler Serial: {e}")
        time.sleep(0.1)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/get_data')
def get_data():
    global temperatura_atual, umidade_atual
    if temperatura_atual is None or umidade_atual is None:
        return jsonify({"error": "Dados não disponíveis"})
    return jsonify({
        "temperatura": temperatura_atual,
        "umidade": umidade_atual
    })

@app.route('/controlar/<int:led_num>/<string:acao>')
def controlar_led(led_num, acao):
    global estado_leds
    if led_num not in estado_leds:
        return jsonify({"status": "erro", "mensagem": "LED inválido"}), 400
    if acao not in ['on', 'off']:
        return jsonify({"status": "erro", "mensagem": "Ação inválida"}), 400

    estado_leds[led_num] = (acao == 'on')
    print(f"LED {led_num} {'ligado' if estado_leds[led_num] else 'desligado'}")
    return jsonify({"status": "sucesso", "led": led_num, "acao": acao})

if __name__ == '__main__':
    # Thread para leitura da Serial
    thread_serial = threading.Thread(target=ler_serial)
    thread_serial.daemon = True
    thread_serial.start()

    app.run(debug=True)
