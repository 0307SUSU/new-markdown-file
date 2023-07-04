# express
1. 创建基本的web服务器
```js
  // 创建服务器需要用到node的一个基本模块'http',故此要先引入该模块
  const http = require('http');
  // 接着使用该模块中提供的一个API，'createServer'创建服务器实例
  // http.createServer 方法将函数作为一个参数，每次有HTTP 请求发送过来就会调用那个函数。
  http.createServer((req,res)=>{
    res.writeHead(200,{'Content-Type':'text/html'});
    res.end('hellow world!');
  }).listen(9988);

```