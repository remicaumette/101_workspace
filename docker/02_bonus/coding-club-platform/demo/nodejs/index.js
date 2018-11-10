const http = require('http');

http.createServer((req, res) => {
    res.end('Hello world!');
}).listen(process.env.PORT || 3000);
