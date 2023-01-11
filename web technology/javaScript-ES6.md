<div align='center'><font size='70'; face="宋体">ECMAScript-<span style="color: skyblue;">(2015-2021)</span></font></div>

- let变量
- const常量
- 解构赋值
- 模板字符串 
- 对象简化写法
- 箭头函数
- 函数参数默认值
- rest剩余参数
- 扩展运算符
- Symbol数据类型唯一的
- 迭代器
- Promise
- set数据结构
- Map数据结构
- class
- 数值的扩展方法
- 对象扩展方法
- 模块化
- 数组的方法扩展
- async函数和await表达式
- 正则表达式的扩展
- 私有属性
- 可选链操作符
- 动态import
- Bigint大整型
- globalThis

### let

作用：定义变量

特点：块级作用域,只能在所声明的块儿内起作用

### const

作用：定义常量

特点：块级作用域、值不可改变（保存值的地址不可改变）

### 解构赋值

作用：提取数组和对象的值，赋值给变量

用法：

```js

```

特点：简化代码，

### 模板字符串

作用：声明字符串

用法：

```js
``
```

特点：可换行书写、可通过${}嵌入js代码,

### 对象字面量增强

作用：简化对象的书写，减少代码量

特点：

用法：

### 对象扩展方法

```js
// Object.assign()  将多个源对象中的属性复制到一个目标对象中

// Object.is()  判断两个值是否相等
```



### 箭头函数

作用：函数的一种

用法：

```js

```

特点：简化函数书写、this只指向声明时的变量

### 函数参数默认值

作用：给函数参数设置初始值

用法：

```js

```

特点：便于开发

### 剩余参数rest（...）

作用：获取函数实参，代替arguments

用法：

特点：

### 扩展运算符 `...`

作用：操作数组（将数组转化为逗号分隔的序列）

用法：

```js

```

特点：

### Symbol

作用：新增的数据类型，表示唯一的标识符

用法：

```js
let fuck = Symbol();
// 也可以给它一个名，这个名不是唯一的谁都可以叫，也没什么作用
let fuck = Symbol("bitch");
```

特点：

### 迭代器

作用：一种接口

用法：

特点：

### Promise

什么是单线程？

> 就是按顺序执行，一次只能执行一个任务

单线程有什么好处和坏处？

> 好处就是容易实现，执行环境相对单纯，坏处是容易造成阻塞，影响后续程序执行

程序阻塞举例

```js
// 死循环，定时器，突出表现就是导致任务执行时间过长浏览器无响应
```

如何解决程序阻塞问题？

> js将任务的执行分为同步任务(Synchronous)和异步任务(Asynchronous)。

什么是同步？

> 指按照顺序执行的任务，也就是单线程

什么是异步？

> 将任务区分不同的线程同时处理。也就是多线程

异步编程有什么好处？

> 充分利用cpu的计算能力，同时处理多个任务。
>
> 解决同步编程下程序任务阻塞问题
>
> 耗时长的任务都该用异步执行

异步编程的方案有哪些？

- 回调函数

> 最基本的异步编程方案

什么是回调函数？

> 函数作为参数传递给另一个函数并在其父函数完成后执行的函数。

代码示例

```js
function dosomething(msg,callback){
    alert(msg);
    if(typeof callback == "function")
    callback();
}
dosomething("回调函数",function(){
    alert("匿名函数实现回调！");
})

// 异步请求的回调函数
$.get("请求接口url",function(data,status){
    alert("接口返回的数据："+data+"接口返回的状态："+status)
})
// get相当于一个函数，有两个参数，一个是url地址，一个是函数，函数里的data和status是地址请求的返回值，作为参数传递给它


//数组遍历的回调函数
array1.forEach(element=>console.log(element));
//forEach属于数组array1的函数方法，element箭头函数作为forEach的参数传递给了forEach。像这种的还有很多，只要是函数作为另一个函数的参数并且在其内部执行的就属于回调函数
```

回调函数有什么优点和缺点？

> 优点就是容易理解，缺点容易造成回调地狱，不利于阅读和维护，缺点大于优点。

回调地狱例子

```js
ajax(url,()=>{
    ajax(url1,()=>{
        ajax(url2,()=>{
            ...
        })
    })
})
```

- 事件监听

> 任务的执行不取决于代码的顺序，取决于事件是否发生。

举例

1. 鼠标点击事件
2. 回车事件等

事件监听有什么优点和缺点？

> 优点是可以绑定多个事件，每个事件可以指定多个回调函数，并且可以去耦合，利于实现模块化。缺点是任务的执行变成事件驱动型，整个运行流程变得异常不清晰。
>
> 什么是耦合？
>
> 耦合就是程序代码之间的依赖关系，低耦合就是程序中不同模块之间的代码依赖关系较低，相互不产生影响，高耦合就是不同模块之间代码高度依赖，相互影响较深。不利于阅读和理解。所以一般会避免书写高耦合的代码。
>
> 解决高耦合代码的方法叫做程序的解耦
>
> 解耦就是降低代码中模块与模块之间的依赖

- 发布/订阅

> 一个发布者对应多个订阅者，当发布者状态改变时所有依赖于它的订阅者都将得到通知，从而做出相应的处理。

发布/订阅的优缺点？

>  发布/订阅模式的优点是对象之间解耦，异步编程中，可以更松耦合的代码编写；缺点是创建订阅者本身要消耗一定的时间和内存，虽然可以弱化对象之间的联系，多个发布者和订阅者嵌套一起的时候，程序难以跟踪维护。

- promise

> es2015引入的一种处理异步代码的方式，promise是一个对象，代表一个异步操作，有三种状态，(pending)运行时，(fuifilled)成功和(rejected)失败

传统异步方案有什么问题？

> 1. 容易造成回调地狱，代码耦合性高
> 2. 代码运行流程不清晰，不利于阅读理解
> 3. 消耗内存不利于跟踪维护

promise解决了传统异步的什么问题？

> - 解决回调地狱问题

promise必然处于这三种状态中的一种，并且它必然以pending状态开始，以fulfilled或rejected状态结束。

promise对象有哪些方法？

1. 定义在原型上的方法
   - then()
   - catch()
   - finally()
2. 其余方法
   - resolve()
   - reject()
   - all()
   - race()
   - allsettled()
   - any()



```js
const p = new Promise(function (resolve,reject){
    setTimeout(function(){
        //成功的返回 
        let data = '数据';
        let err = '数据读取失败';
        resolve(data);
        reject(err);
    },1000);
});
//调用promise对象的then方法
p.then(function (value){
    //打印成功后的值
    console.log(value);
},function(reason){
    //打印失败后的值
    console.error(reason);
})


//例子   用promise封装AJAX请求
const p = new Promise((resolve,reject) =>{
    //AJAX请求
    1. 创建对象
    const xhr = new XMLHttpRequest();
    2.初始化
    xhr.open("请求方法","请求地址");
    3.发送请求
    xhr.send();
    4.绑定事件，处理请求返回的结果
    xhr.onreadystatechange = function (){
        if(xhr.readyState === 4) {
            if(xhr.status >= 200 && xhr.status < 300){
                //如果判断条件成立，这时就可以将返回结果给promise中成功的回调resolve
                resolve(xhr.response);
            }else{
                //如果判断条件不成立，将返回结果给promise中失败的回调reject
                reject(xhr.status);
            }
        }
    }
})
  //利用promise的then方法处理成功和失败的回调
p.then(valuue =>{
    // 打印判断条件成立返回的结果
    console.log(value);
},reason =>{
    // 打印判断条件不成立返回的结果
    console.error(reason);
});
```

`then`

```js
getJSON("/post/1.json").then(
	post => getJSON(post.commentURL)
).then(
	comments => console.log("resolved:",comments),
    err => console.log("rejected:",err)
)
```

- async/await



### class类关键词

作用：

用法：

```js

```

特点:

### Set数据结构

作用：

用法：

特点：

### Map数据结构

作用：

用法：

特点：

# 第二遍

`字符串的扩展方法`

```js
// 判断字符串当中是否包含指定内容
// startsWith()

// endsWith()

// includes()
```

`proxy类型`

作用：代理对象

用法：

```js

```

特点:

`Reflect静态对象`

作用: 

```js

```

用法:

特点：

 `for...of循环`

作用：遍历所有数据结构的统一方式

用法：

特点：

`iterable可迭代接口`

`iterator迭代器`

`Generator生成器`

`Modules`

# 函数式编程



函数组合



