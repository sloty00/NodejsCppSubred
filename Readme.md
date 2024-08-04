# IP Calculator with Node.js and C++

This project is a simple IP calculator built with Node.js and C++. It provides basic functionality to calculate IP addresses, network details, subnet masks, and more.

## Features

- Calculate IP address details (network, broadcast, subnet mask)
- Calculate subnets based on IP address and prefix
- Built with Node.js and C++ for performance

## Installation

1. **Clone the repository**

    ```bash
    git clone https://github.com/your-username/IP_Calc-NodejsCpp.git
    cd IP_Calc-NodejsCpp
    ```

2. **Install dependencies**

    Make sure you have Node.js installed. If not, download and install it from [nodejs.org](https://nodejs.org/).

    ```bash
    npm install
    ```

3. **Build the C++ addon**

    Ensure you have the required build tools installed. For Windows, you'll need Visual Studio Build Tools.

    ```bash

    node-gyp configure
    node-gyp build

    ```

## Usage

1. **Start the server with:**

    ```bash

    npm start
    ```

2. **The server will be running at http://localhost:3000.**

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
