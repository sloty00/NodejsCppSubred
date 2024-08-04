const express = require('express');
const addon = require('./build/Release/ipcalculator');
const app = express();
const port = 3000;

app.use(express.json());

app.post('/calculate', (req, res) => {
    const { ip, prefix } = req.body;
    if (typeof ip === 'string' && typeof prefix === 'number') {
        const result = addon.calculateIP(ip, prefix);

        // Aquí parseamos el resultado y lo dividimos en partes
        const [ipResult, networkResult, broadcastResult, maskResult] = result.split(', ');

        // Creamos el objeto JSON para la respuesta
        const jsonResponse = {
            ip: ipResult.split(': ')[1],
            network: networkResult.split(': ')[1],
            broadcast: broadcastResult.split(': ')[1],
            subnetMask: maskResult.split(': ')[1]
        };

        res.json(jsonResponse); // Enviamos el objeto JSON como respuesta
    } else {
        res.status(400).send('Invalid input');
    }
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});