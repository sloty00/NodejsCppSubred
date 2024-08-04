# Calculadora de IP con Node.js y C++

Este proyecto es una calculadora de IP simple creada con Node.js y C++. Proporciona funciones básicas para calcular direcciones IP, detalles de red, máscaras de subred y más.

## Caracteriticas

- Calcular IP address con los detalles (network, broadcast, subnet mask)
- Calcular primer rango de subnets basada en IP and prefix
- Construir el Node.js y C++ para Performance.

## Instalacion

1. **Clonar el Repositorio**

    ```bash
    git clone https://github.com/your-username/IP_Calc-NodejsCpp.git
    cd IP_Calc-NodejsCpp
    ```

2. **Instalacion de dependencias**

    Asegúrate de tener instalado Node.js. Si no es así, descárgalo e instálalo desde [nodejs.org](https://nodejs.org/).

    ```bash
    npm install
    ```

3. **Construccion del C++ addon**

    Asegúrate de tener instaladas las herramientas de compilación necesarias. Para Windows, necesitarás: Visual Studio 2022 Profesional o VS CODE.

    ```bash
    node-gyp configure
    node-gyp build
    ```

## Usar

1. **Start the server with:**

    ```bash
    npm start
    ```

2. **El servidor esta corriendo en: http://localhost:3000.**

    POST /calculate

    Request body:
    
    ```bash

    {
    "ip": "192.168.1.1",
    "prefix": 27
    }

    ```

    Response:
    
    ```bash
    {
      "ip": "192.168.1.1",
      "network": "192.168.1.0",
      "broadcast": "192.168.1.31",
      "subnetMask": "255.255.255.224"
    }
    ```
