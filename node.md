# node

> nodejs是一个环境，不是一个语言

### 环境搭建

#### 普通搭建

搭建node环境请参考 [超详细的Node.js环境搭建](https://blog.csdn.net/weixin_41092938/article/details/111300088?ops_request_misc=&request_id=&biz_id=102&utm_term=node%E7%8E%AF%E5%A2%83%E6%90%AD%E5%BB%BA&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-111300088.nonecase&spm=1018.2226.3001.4187)

#### 通过nvm搭建

> 好处：nvm 是一个 nodejs 的版本管理工具。通过它可以安装和切换不同版本的 nodejs，解决 node 各种版本存在不兼容现象。

[nvm详细安装使用教程(nvm-node多版本管理工具）](https://blog.csdn.net/weixin_57844432/article/details/127788884?ops_request_misc=&request_id=&biz_id=102&utm_term=nvm&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-3-127788884.142^v96^pc_search_result_base8&spm=1018.2226.3001.4187)

### 同步和异步

> 异步解决了同步代码阻塞的问题

#### 异步代码的表现形式

> 定时器setTimeOut()、

#### 异步的特点

> 回调函数`callback`，通过回调函数的方式返回结果

#### 异步存在的问题

> 异步代码容易产生回调地狱，不利于代码维护和调试

#### 解决异步回调地狱的方法

> Promise

##### Promise用法

###### 创建promise

promise通过构造函数方式创建，new Promise()

> promise中包含一个callback参数

```js
new Promise(function(){
    
})
```

> callback中包含两个参数resolve和reject

```js
new Promise(function(resolve,reject){
    // resolve和reject是两个函数
    // resolve存储程序执行正常时的数据
    // reject存储程序执行错误时的数据
})
```

###### 读取Promise中的数据

要想读取Promise中的数据，需要调用promise的实例方法`.then()`

`.then`方法接受两个callback作为参数，第一个callback用来处理正常返回的数据，第二个callback处理异常返回的数据

```js
new Promise(function(resolve,reject){
    resolve('正常数据');
    reject('异常数据')
}).then(function(result){
    console.log(result);
},function(err){
    console.log(err);
})

// 为了便于阅读代码和代码的简洁，我们将new promise()实例赋值给一个变量Promise，将callback改造成箭头函数的形式
let Promise = new Promise((resolve,reject)=>{
    resolve('正常数据');
    reject('异常数据')
})
Promise.then((result)=>{
    console.log(result);
},(err)=>{
    console.log(err);
})
```

专门处理异常数据的实例方法`.catch()`

`.catch`方法只接受一个callback作为参数，相当于只传入`.then`方法中的第二个参数`then(null,(err)=>{})`，并且它只会在promise被拒绝时调用，它是专门用来处理promise异常的方法

```js
let Promise = new Promise((resolve,reject)=>{
    resolve('正常数据');
    reject('异常数据')
})
Promise.then((result)=>{
    console.log(result);
}).catch(err=>{
    console.log(err)
})
```

无论返回数据异常与否都会执行的实例方法`.finally()`

`.finally`方法的callback参数不会接收到数据

```js
```

promise的实例方法最终都会return一个新的promise

##### Promise原理

> promise维护了两个私有属性`PromiseResult`和`PromiseState`

- `PromiseResult`

  > 用来存储数据

- `PromiseState`

  > 用来记录Promise的状态，promise有三种状态，`pending`、`fulfilled`、`rejected`

  - pending （进行中）

    一开始执行时的状态

  - fulfilled （完成）

    通过resolve存储数据时的状态

  - rejected（拒绝，报错）

    报错或者通过reject存储数据时的状态

  > PromiseState的状态只能修改一次，状态改变之后永远不会再变

  - 举例说明：

  ```js
  let Promise = new Promise((resolve,reject)=>{
      resolve('正常数据');// 状态改变了为fulfilled
      reject('这里永远不会执行')
  })
  Promise.then((result)=>{
      console.log(result);
  },(err)=>{
    // 这里永远不会打印  
      console.log(err);
  })
  ```

  > 三种状态的执行流程

  promise创建时，状态为`pending`(进行中)。

  resolve调用时状态变为`fulfilled`(完成)，这时PromiseResult值为resolve存储的数据

  reject调用时状态变为`rejjected`(拒绝，报错)，这时PromiseResult值为reject存储的数据或错误对象

  > then方法执行原理

  调用`.then`方法时相当于为Promise设置了两个callback

  如果PromiseState的状态为fulfilled，这时then方法会执行第一个callback返回数据

  如果PromiseState的状态为rejected，这时then方法会执行第二个callback返回数据

### js宏任务和微任务

> 前置知识

- js的运行机制
- 内存机制
- 任务队列

### 模块化

> 模块化是一种规范，它将一些单独的功能从程序中抽离出来，放入一个独立的文件中形成模块（相当于**一个文件就是一个模块**），模块之间相互独立，通过特定的语法**导入和导出**模块使模块之间建立联系。

为什么要实现模块化？

> 提高代码可复用性，提升开发效率，减少重复代码，方便后期维护

> 前端常用的模块化规范

- commonjs规范、
- ES规范、

#### commonjs规范

[CommonJS](https://blog.csdn.net/xun__xing/article/details/108041714?ops_request_misc=&request_id=&biz_id=102&utm_term=commonjs&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-2-108041714.nonecase&spm=1018.2226.3001.4187)

[【前端模块化】-关于CommonJS规范](https://blog.csdn.net/weixin_53478983/article/details/128230038?ops_request_misc=&request_id=&biz_id=102&utm_term=commonjs&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-128230038.nonecase&spm=1018.2226.3001.4187)

> commonjs是node默认的模块化规范

##### 如何导入模块

##### 如何导出模块

#### ES规范

> ES规范是ECMAScript2015定义的js规范

##### 如何导入模块

##### 如何导出模块

### Global

> node的全局对象

[参考链接](https://blog.csdn.net/qq_44034384/article/details/99687422)

### package.json

[参考链接](https://javascript.ruanyifeng.com/nodejs/packagejson.html)

### 内置模块

#### fs文件系统模块

[api文档](https://nodejs.org/docs/v0.4.0/api/fs.html)

[中文官方文档](https://nodejs.cn/api/fs.html)

[阮一峰](https://javascript.ruanyifeng.com/nodejs/fs.html)

[阿里云教程](https://developer.aliyun.com/article/1203017)

#### path路径模块

[csdn教程](https://blog.csdn.net/u014711690/article/details/111639640)

#### http模块

#### url模块

[腾讯云教程](https://cloud.tencent.com/developer/article/1653911)

#### os操作系统模块

[阮一峰](https://javascript.ruanyifeng.com/nodejs/os.html)

### 上传模块到npm

[参考链接](https://juejin.cn/post/6864776736812236808)

### npm

[npm命令大全](https://bbs.huaweicloud.com/blogs/343692)

### 三方模块

#### express





