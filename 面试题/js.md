[TOC]

面试官您好，19年毕业于郑州信息工程学院，计算机专业，目前在杭州，从事前端工作两年，主要使用vue框架。个人性格上比较有耐心，平时比较喜欢逛一些技术类网站csdn、掘金等，喜欢钻研一些新技术，能够接受叫高强度的工作，平时会喜欢听一些音乐或者通过运动缓解工作压力。

js面试题

毕业时间、专业、参加工作时间、用过什么框架、开发过哪些项目，主要负责什么

### 事件循环机制

event loop、消息队列、宏任务、微任务

![img](https://img-blog.csdnimg.cn/20201231134039732.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NoZXJyeUNvbGFfemps,size_16,color_FFFFFF,t_70)

先走主线程上的任务，遇到异步任务就放到消息队列中等待执行，主线程接着往下执行，主线程执行完毕后，事件循环网消息队列中找可以执行的异步任务，放回到主线程中执行，这样循环，直到消息队列中的异步任务执行完毕。

异步任务又分宏任务和微任务，异步也有执行顺序，一般先执行微任务接着执行宏任务

### 同步和异步

js是单线程语言

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

### promise

> 异步编程的一种解决方案，解决了传统回调函数的回调地狱问题

三个状态：

1. pending 运行时
2. resolved 成功
3. rejected 失败

根据状态发现promise的执行结果只有两种，要么成功要么失败，并且结果一旦确定就不能再改变其状态

方法：

then()、catch()、all()、race()、finally()。

- then()

接受两个参数，第一个表示成功的回调（resolved），第二个表示失败的回调（rejected）

then会返回一个新的promise实例，所以可以采用链式写法。

- catch()

相当于then方法的第二个回调，也就是接受失败的回调，并且它可以捕获前面then方法执行中的错误，更接近同步的写法

- all()

将多个实例包装成一个新的实例

`p`的状态由`p1`、`p2`、`p3`决定，分成两种情况。

（1）只有`p1`、`p2`、`p3`的状态都变成`fulfilled`，`p`的状态才会变成`fulfilled`，此时`p1`、`p2`、`p3`的返回值组成一个数组，传递给`p`的回调函数。

（2）只要`p1`、`p2`、`p3`之中有一个被`rejected`，`p`的状态就变成`rejected`，此时第一个被`reject`的实例的返回值，会传递给`p`的回调函数。

- finally()【ES2018】

不管promise对象的状态如何，它都会执行。

- race()

作用与all()方法相似

区别在于race方法只要`p1`、`p2`、`p3`之中有一个实例率先改变状态，`p`的状态就跟着改变。

### 事件冒泡/捕获，以及事件委托

捕获: 从document开始,层层子元素传递,直到点击到当前子元素
冒泡: 从点击当前子元素开始,层层父级传递,直到document
事件委托: 将子元素的事件交给父元素处理(主要是添加新的节点,是无法绑定事件,这个时候需要事件委派)
给父元素绑定事件,通过捕获的过程来获取事件,并通过etarget来获取目标元素

### 函数的防抖和节流

防抖的作用是：当用户多次触发回调函数时，只触发最后一次操作的，其余的全部忽略掉；
函数节流：是确保函数特定的时间内至多执行一次

区别： 函数节流不管事件触发有多频繁，都会保证在规定时间内一定会执行一次真正的事件处理函数，而函数防抖只是在最后一次事件后才触发一次函数。 比如在页面的无限加载场景下，我们需要用户在滚动页面时，每隔一段时间发一次 Ajax 请求，而不是在用户停下滚动页面操作时才去请求数据。这样的场景，就适合用节流技术来实现。

### js的数据存储

- sessionStorage

> 仅在当前会话下有效，关闭页面或浏览器后被清除

- localStorage

> 用于长久保存整个网站的数据，保存的数据没有过期时间，直到手动去删除
>
> localStorage和sessionStorage最大一般为5MB，仅在客户端（即浏览器）中保存，不参与和服务器的通信；

- cookie

> Cookie 是一些数据, 存储于你电脑上的文本文件中，用于存储 web 页面的用户信息
> Cookie 数据是以键值对的形式存在的，每个键值对都有过期时间。如果不设置时间，浏览器关闭，cookie就会消失，当然用户也可以手动清除cookie
> Cookie每次都会携带在HTTP头中，如果使用cookie保存过多数据会带来性能问题
> Cookie内存大小受限，一般每个域名下是4K左右，每个域名大概能存储50个键值对

### 内存机制

内存的生命周期

分配》使用》回收

内存泄漏：不用的变量内存没有及时回收

垃圾回收机制：

有两种方式： 标记清除、引用计数

js中有自动垃圾回收机制，会通过标记清除的算法识别哪些变量对象不再使用，对其进行销毁。

### 闭包

> 闭包就是能够读取其他函数内部变量的函数
>
> 外层函数return了一个内层函数，内层函数内又使用了外层函数的变量

- js的变量作用域全局变量和局部变量

js中局部作用域内可以读取全局变量，但是在局部作用域外部却不能读取局部作用域内定义的变量也就是局部变量。简单说就是全局变量可以在任何地方被读取，局部变量只能在局部作用域内被读取。js有一种链式作用域的结构，子对象可以访问父对象内所有的数据。

有时候我们就想在函数外部读取函数内的变量，所以就产生了一种方法**闭包**

```js
function f1(){
    var n= 100;
    function f2(){
        console.log(n); // 100
    }
    return f2;
}
var result = f1();
result(); // 100
```

闭包两个最大的特点就是可以在函数外部读取函数内部的变量，并且可以让变量的值始终保存在内存中不被销毁。

使用闭包要注意内存消耗和内存泄露，还有一点就是避免在父函数外部改变父函数内部变量的值。

### 深浅拷贝

前置知识，为什么会有深浅拷贝？

> js分为基本数据类型和引用数据类型，在内存中，js的基本数据类型存放在栈中，引用数据类型存放在堆中

浅拷贝：拷贝基本数据类型时，不受任何影响，当拷贝引用类型时，修改拷贝对象，源对象也会被修改

举例：

```js
let a = {
   name : '张三',
    age : '18'
}
let b = a;
b.name = '李四';
console.log(a); // {name:'李四'，age:'18'}
console.log(b); // {name:'李四'，age: '18'}
```

深拷贝：深拷贝就是在内存的堆区域中开辟一个新的空间完全拷贝一份新的对象出来，这样修改拷贝对象就不会影响原来的对象。

<font color="red">实现深拷贝的方法，其实就是拷贝对象是否在内存中开辟了新的空间</font>

举例：

```js
// 1. es6的展开语法
let a = {
   name : '张三',
    age : '18'
}
let b = {...a};
b.name = '李四';
console.log('a：',a);
console.log('b：',b);


// 2. JSON.parse(JSON.stringify(待拷贝对象))
缺点：没法拷贝对象中的函数
let a = {
    name:'张三',
    age:'18',
    like(){
        alert('会唱歌');
    }
}
let b = JSON.parse(JSON.stringify(a));
b.name = '李四';
console.log(a); // { name:'张三', age:'18', like(){alert('会唱歌');}}
console.log(b); //{ name:'李四', age:'18'}


// 3. Array的拷贝方法slice和concat
let origin = [1,2,3,4];
let new_data = origin.slice()
new_data.push(5)
console.log('origin:',origin); // [1,2,3,4]
console.log('new_data:',new_data); // [1,2,3,4,5]
缺点：只能深拷贝第一层，对于多层拷贝无效
let origin = [[1,1],2,3,4];
let new_data = origin.slice()
new_data[0].push(5)
console.log(origin); // [[1,1,5],2,3,4]
console.log(new_data); // [[1,1,5],2,3,4]


// 4. jQuery中的$.extend(添加true就是深拷贝，不添加就是浅拷贝)
let origin = [[1,1],2,3,4];
let new_data = []
$.extend(true,new_data,origin)
new_data[0].push(5)
console.log(origin); // [[1,1],2,3,4]
console.log(new_data); // [[1,1,5],2,3,4]


// 5. 利用递归的方式实现深拷贝
const origin = {
    name: '张三',
    age: '18',
    like(){
        alert('张三喜欢游走在法律的边缘,人称法外狂徒张三');
    }，
    a:[[1,1],2,3,4]
}

function extend(origin,deep){
    // deep true 启动深拷贝
    // false 浅拷贝
    let obj = {}
    // 数组对象
    if(origin instanceof Array){
        // true 数组  obj  就得是数组
        obj = []
    }
    for(let key in origin){
        let value = origin[key]
        // 确定value是不是引用类型，前提是deep是true
        obj[key] =(!!deep && typeof value === "object" && value != null) ? extend(value,deep) : value
    }
    return obj
}
const new_data = extend(origin,true)

new_data.a[0].push(6666)
console.log(origin) // {a:[[1,1],2,3,4],age:"18",like(){alert('张三喜欢游走在法律的边缘,人称法外狂徒张三')},name:"张三"}
console.log(new_data) // {a:[[1,1，6666],2,3,4],age:"18",like(){alert('张三喜欢游走在法律的边缘,人称法外狂徒张三')},name:"张三"}
```

<font color="red">所以深浅拷贝就是针对于引用数据类型的</font>

### 递归

> js中函数自己调用自己，就称为递归

斐波那契数列

从第三个数开始，每一个数等于前两个数的和

```js
function f(n){
    if(n === 1 || n === 2){
        return 1;
    }
    return f(n-1)+f(n-2);
}
console.log(f(8)); // 21
```

递归可以实现多级遍历，和深拷贝

```js
var obj == {
    name:'ls',
    age:4,
    sex:'nan',
    friend:{
        name:'djw',
        age:24,
        sex:'nan',
        student:{
            name:'xlq',
            age:23,
            sex:'nan'
        }
    }
}

function clone(obj){
    if(typeof obj != 'object'){
        return obj;
    }
    var newObj = {}
    for (k in obj){
        newObj[k] = clone(obj[k]);
    }
    return newObj;
}
```

### 原型原型链

原型分为显式(prototype)和隐式(__proto__)两种

> 所有的__proto __属性都会指向它的构造函数的prototype属性

如果在对象中找不到某个属性，就会去它的__ proto __（隐式原型）属性上去找，也就是说去这个对象的构造函数的prototype（显式原型）属性中去找，直到找到该属性，或者返回null为止，这种一层一层的寻找，就形成了原型链。

原型举例：

```js
function foo(name,age){
    this.name = name;
    this.age = age;
}

foo.prototype={
    showName:function(){
        console.log("i'm"+this.name);
    },
    showAge:function(){
        console.log("And I'm"+this.age);
    }
}
var fn = new foo('张三',19)
fn.showName(); // i'm张三
fn.showAge(); //And I'm 19
```

原型链举例：

```js
function foo(name,age){
    this.name = name;
    this.age = age;
}

Object.prototype.toString=function(){
    console.log(this.name+this.age);
}
var fn = new foo('张三',40);
fn.toString(); //张三 40
console.log(fn.toString===Foo.prototype.__proto__.toString); //true
console.log(fn.__proto__ ===Foo.prototype)//true
console.log(Foo.prototype.__proto__===Object.prototype)//true
console.log(Object.prototype.__proto__===null)//true
```

### this指向

js中，this就指当前的意思，this.xxx就指当前对象的xxx

谁调用就指向谁。全局调用就指向window（全局对象）

函数中的this指向要看函数属于哪个对象。全局作用域下定义的函数this就指向window。对象中定义的函数this就指向离它最近的那个对象,**闭包除外**

箭头函数本身没有this，所以所有箭头函数中的this都指向上层对象。

```js
let obj = {
    name:"张三",
    skill:function(){
        name:"李四";
        console.log(this.name)
    }
}
obj.skill(); // 张三


var name = "张三";
var object = {
    name:"李四",
    skill:function(){
        return function(){
            return this.name;
        }
    }
};
console.log(object.skill()()); // 张三
// 分析log的执行顺序，先执行了skill方法并且此方法返回了一个函数，此时返回的这个函数是在全局作用域下的，这时候在全局作用域下再去执行返回的这个函数，函数内部的this就会指向全局作用域下的对象。也就是window对象


let obj = {
    name:"张三",
    skill:() => {
        console.log(this);
    },
    obj2:{
        skill2:() =>{
            console.log(this);
        },
        obj3:{
            name:"李四",
            skill3:function(){
                console.log(this.name);
                return function(){
                    console.log(this.name);
                }
            }
        }
    }
}
obj.skill();// window
obj.obj2.skill2();//window
obj.obj2.obj3.skill3()();//李四  张三
```

 **箭头函数（this指向问题）**

![img](file:///C:/Users/25369/AppData/Local/Temp/msohtmlclip1/01/clip_image002.jpg)

绑定this的方法call、applay、bind

都是用来改变函数的this对象的指向的

```js
var f = function () {
  return this;
};

f() === window // true
f.call(obj) === obj // true

```

call和applay指定函数内部this的指向，然后调用这个函数，两个方法第一个参数都是this所要指向的那个对象，不同的是call方法的参数需要一个一个添加，apply方法的参数需要以数组形式添加

bind将函数体内的this绑定到指定的对象上去，然后返回一个新的函数

### Array对象方法

- Array.isArray()

> 用来判断参数是否为数组，属于静态方法

- valueOf(),toString()

> 通用方法，valueOf()表示对该对象求值，toString()将数组转成字符串

- push(),pop()

> push在数组末端添加元素，返回数组长度，会改变原数组
>
> pop删除数组最后一个元素，返回删除的元素，会改变原数组

- shift(),unshift()

> shift删除数组的第一个元素，返回删除的元素，会改变原数组
>
> unshift在数组头部添加元素，返回数组长度，会改变原数组

- join()

> 指定元素的分隔符

- concat()

> 合并多个数组，返回新数组，原数组不变

- reverse()

> 反转数组，返回反转后的数组，会改变原数组

- slice()

> 截取部分元素，返回新数组，原数组不变，接收两个参数第一个为开始位置的下标，第二个为结束位置的下标

- splice()

> 删除部分元素并可在删除部分添加新成员，返回被删除的元素，会改变原数组

- sort()

> 排序，默认按字典顺序排序，会改变原数组，如要按自定义方式排序可以传入一个函数做参数

- map()

> 遍历原数组返回新数组

- forEach()

> 遍历操作数组，不返回值。并且此方法无法中断执行

- filter()

> 过滤数组元素，满足条件的元素组成新数组返回，不改变原数组

- some()，every()

### 数组去重的方法

1. 先将原数组排序，在与相邻的进行比较，如果不同则存入新数组。
2. 利用数组的indexOf方法。
3. 利用数组原型对象上的includes方法。
4. 利用数组原型对象上的 filter 和 includes方法
5. 利用数组原型对象上的 forEach 和 includes方法
6. 利用数组原型对象上的 lastIndexOf 方法
7. 利用 ES6的set 方法。

```js
 function unique10(arr) {
            //Set数据结构，它类似于数组，其成员的值都是唯一的
            return Array.from(new Set(arr)); // 利用Array.from将Set结构转换成数组
        }
        console.log(unique10([1, 1, 2, 3, 5, 3, 1, 5, 6, 7, 4]));
```

### 数组遍历方法

- for
- for...of
- for...in
- forEach
- map
- filter

### 数组排序方法

1. 数组自身sort方法排序
2. 冒泡排序
3. 选择排序
4. 插入排序
5. 快排

### es6新增特性

let和const、解构赋值、模板字符串、扩展运算符、对象简写、箭头函数、函数参数设置默认值、symbol、promise、set,map数据结构、class

### let和const 的区别是什么

- let 命令不存在变量提升，如果在 let 前使用，会导致报错
- 如果块区中存在 let 和 const 命令，就会形成封闭作用域
- 不允许重复声明
- const定义的是常量，不能修改，但是如果定义的是对象，可以修改对象内部的数据

### 项目性能优化

减少 HTTP 请求数
减少 DNS 查询
使用 CDN
避免重定向
图片懒加载
减少 DOM 元素数量
减少 DOM 操作
使用外部 JavaScript 和 CSS
压缩 JavaScript、CSS、字体、图片等
优化 CSS Sprite
使用 iconfont
多域名分发划分内容到不同域名
尽量减少 iframe 使用
避免图片 src 为空
把样式表放在 link 中
把 JavaScript 放在页面底部

### 冒泡排序

1. 相邻两个元素比较

> 利用双重for循环将要比较的数组元素进行相邻两个数的两两比对，如果前一个比后一个大，则交换位置。

```js
var arr = [3,1,2,5,4];

function arr_sort(data){
    for(var i = 0;i<data.length-1;i++){
        for(var j = 0;j<data.length - i; j++){
            if(data[j]>data[j+1]){
                swap = data[j+1]
                data[j] = data[j+1]
                data[j+1] = swap
            }
        }
    }
}
arr_sort(arr)
```

> 定义一个变量，通过循环判断相邻两个元素，如果前一个比后一个大，交换位置

```js
function arr_sort(data){
    let n = data.length
    let flag = true // 标记顺数是否发生变化
    let swap
    while(flag){
        flag = false
        for(var j = 1; j<n; j++){
            if(data[j-1]>data[j]){
                swap = data[j -1]
                data[j-1]=data[j]
                data[j] = swap
                flag = true
            }
        }
        n--
    }
}
arr_sort(arr)
```
