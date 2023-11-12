<div align='center'><font size='70'; face="宋体">JavaScript</font></div>

# ECMAScript

## 变量

### var

作用：关键字，声明一个可改变的值

用法：

```js
var num = 123
```

特性：

- 变量名不能以数字开头，并且不能是关键字或保留字

扩展：

## 数据类型

### 基本数据类型

- Number
- String
- Boolean
- null
- undefined

#### 数据类型转换

> toSstring()、String()、字符串拼接
>
> Number()、parseInt()、parseFloat()
>
> Boolean()

#### 数据类型判断

> typeof
>
> instanceof

### number

作用：数字类型，一种表示数字的类型

用法：

```js
var num = 123;
```

特性：

扩展：

typeof数据类型判断..............。。，。，。

Number.MAX_VALUE大于零的数字最大值

Number.MIN_VALUE大于零的数字最小值

Infinity无穷大

-Infinity无穷小

NaN 不是一个数字Not a Number

Number(value);类型转换

### string

作用：字符串类型，一种表示字符串的类型

用法：

```js
var str = "我的祖国";
```

特性：

扩展：

String(value);类型转换

转义字符

### boolean

作用：一种表示真假的类型，只有两个值true/false

用法：

```js
var boo = true;
```

特性：

扩展：

类型转换

- 显示转换

Boolean(value);

- 隐式转换

### null

作用：表示一个为空的对象，只有一个值null

用法：

特性：

扩展：

### undefined

作用：没有被定义

用法：

特性：

扩展：

## 运算符

+、-、*、/、%、++、--、>、<、>=、<=、

- 逻辑运算符

&&、||、！

- 赋值运算符

=、+=、-=、*=、/=、%=

- 比较运算符

==、===、!=、!==、

- unicode编码
- 条件运算符

a=b?val1:val2

- 位运算符

> 按位与(&)
>
> 按位或(|)
>
> 按位异或(^)
>
> 按位非(~)
>
> 左移(<<)
>
> 右移(>>)
>
> 无符号右移(>>>)

- 空值合并运算符

??

- 逗号运算符

> ，
>
> *let a = (1 + 2, 3 + 4);* alert( a ); // 7（3 + 4 的结果）

- 运算符优先级
- in运算符

> 检查对象中是否包含某属性

## 条件判断语句

### if语句

```js
if(true){
    ...
}

if(true){
    ...
}else{
    ...
}
    
if(a){
    ...
}else if(b){
    ...
}else if(c){
    ...
}...{
    ...
}else{
    ...
}
```

### switch语句

```js
var num = 1;
switch(num){
    case 1:
        console.log(1);
    break;
    case 2:
        console.log(2);
    break;
    case 3:
        console.log(3);
    break;
    default:
        console.log('以上条件都不符合');
    break;
}
```

## 循环语句

#### for语句

```js
// 基本循环语句
for(初始化表达式 ; 条件表达式 ; 更新表达式){
    语句...
}
    
// for...in   多用于对象
for (key in object){
    循环体
}

// for...of  多用于数组
let fruits = ["Apple", "Orange", "Plum"];
for (let fruit of fruits) {
  alert( fruit );
}
```



#### while语句

```js
while(循环条件){
    循环体
}

    
do{
    循环体
}while(循环条件)
```

## 对象

### OBJECT

> 删除对象中的某个属性

- delete    对象.属性名

> 遍历对象

1. for.....in

用法：

```js
// 语法
var obj1 = new Object(); // 构造函数语法
var obj2 = {}; // 字面量语法(较常用)

// 对象中的内容，键和值，可以称之为属性
var obj = {
    name:"牛掰",
    // 对象中的键值对之间必须以“,”分隔
    age: 1,
    // 键还可以写成多个词语,但必须加上引号
    "my money": "数不过来",
}

// 操作对象中的属性
  // 用"."操作符的方式
alert(obj.name); // 牛掰
  // 用"delete"操作符
delete user.age;
alert(obj.age); // undefined
  // 键名中违反了变量命名规范时用不了"."操作符,可以用下面的"[]"操作符操作,"[]"可以用于任何字符串
alert(obj["my money"]);// 数不过来
  // "in"操作符可以检查对象中是否存在该属性
var user = {
    name,
    age:18,
}
alert("age" in user); // true  存在
alert("howMunchMoney" in user);  // false  不存在 

// 方法属性
// 如果对象中的值指向的是function，那么这个属性就是这个对象的方法属性，使用方法属性时末尾必须加上"()"
```

特性：

> 键和值一样的时候可以简写，只写一个就行
>
> 对象的键名没有命名限制
>
> 对象的键名只能是字符串类型或Symbol类型

扩展：

#### 引用

对象的引用只是给了操作该对象的权限，对象还是一个，可操作的变量多了。

##### 拷贝

如果想实现复制，就需要创建一个空的对象，通过循环遍历想要复制的对象

Object.assign(目标对象名, [要复制的对象1,要复制的对象2,要复制的对象3...])。此方法也可实现复制。

##### 深层拷贝

如果对象的某个属性值还是一个对象该怎么拷贝？

为了解决这个问题，我们应该使用一个拷贝循环来检查 `user[key]` 的每个值，如果它是一个对象，那么也复制它的结构。这就是所谓的“深拷贝”。

###### 递归

#### 垃圾回收

可达性，如果某个根下面的某个类型的值不能通过任何方式引用或者操作，就表示它是不可达的，这时就会被js的垃圾回收器回收掉。

垃圾回收器会定期检查所有对象，标记可达对象（就是可以被访问到的值），删除不可达对象(就是访问不到的值)。

#### function

作用：函数可以使一段代码多次调用，并且不需要重复书写

用法：

```js
// 声明函数
function fun(a,b){
    ...
}
// 匿名函数
function(a,b){
    ...
}
// 表达式函数
let sayHi = function(){
  ...  
};
// 回调函数
```

特性：

扩展：

> 函数默认值

```js
function morenzhi(from,text = "不传第二个实参，我就会出现"){
    console.log(from + ":" + text);
}
morenzhi("如果"); // 如果：不传第二个实参，我就会出现
```

> 递归

```js
求x的n次方的方法

// 原始迭代思路
function pow(x, n) {
  let result = 1;
  // 再循环中，用 x(2) 乘以 result n(4) 次
  for (let i = 0; i < n; i++) {
    result *= x;
  }
  return result;
}
alert( pow(2, 4) );  //16
// 递归思路
function pow(x, n) {
  if (n == 1) {
    return x;
  } else {
    return x * pow(x, n - 1);
  }
}
alert( pow(2, 4) ); // 16
// 递归思路分析
如果参数n等于1值就等于x本身，所以先得到x的值，依次向上递增二次方等于x乘以1次方，三次方等于x乘以2次方...以此类推10次方等于x乘以10-1次方n次方等于x*(n-1)次方。那么这样就好办了，只要先得到一次方的值后面的值就很好解了，一次方就是x本身
pow (2,4) = 2 * pow(2,3)
pow (2,3) = 2 * pow(2,2)
pow (2,2) = 2 * pow(2,1)
pow (2,1) = 2 * 1
递归将函数调用简化为一个更简单的函数调用，然后再将其简化为一个更简单的函数，以此类推，直到结果变得显而易见。

// 递归代码优化,更简洁一目了然
function pow(x,n){
    return (n == 1) ? (x : x*pow(x,n-1));
}
```

#### Array

作用：

用法：

```js
let arr = [1,2,3,4,5,6,7,8,9,10]
// pop  从数组末尾提取元素,会改变原数组
	console.log(arr.pop()); // 10
	console.log(arr); // 1,2,3,4,5,6,7,8,9
// push  在数组末尾添加元素，会改变原数组
	console.log(arr.push(10)); // 1,2,3,4,5,6,7,8,9,10
// shift  从数组开始位置提取元素，会改变原数组
	console.log(arr.shift()); // 1
	console.log(arr); // 2,3,4,5,6,7,8,9,10
// unshift 在数组开始位置添加元素，会改变原数组
	arr.unshift(1);
	console.log(arr); // 1,2,3,4,5,6,7,8,9,10
// splice  添加删除和插入元素

	arr.splice(1,1); // 从索引一开始删除一个元素
	alert(arr); // 1,3,4,5,6,7,8,9,10

	arr.splice(0,2,2,3); // 删除数组的前两项，并用其他内容代替
	alert(arr); // 2,3,4,5,6,7,8,9,10

	// 从索引 2 开始
	// 删除 0 个元素
	// 然后插入 "complex" 和 "language"
	arr.splice(2, 0, "complex", "language");
	alert( arr ); // "I", "study", "complex", "language", "JavaScript"
// slice  复制选定范围的元素并生成一个新数组
	let arr = [1,2,3,4,5,6,7]
	arr.slice(start,end);
	alert(arr.slice(1,3)); // 2,3
	alert(arr.slice(-2)); // 6,7
	
// concat  合并并生成一个新的数组
	let arr = [1, 2];
	alert( arr.concat([3, 4]) ); // 1,2,3,4
	alert( arr.concat([3, 4], [5, 6]) ); // 1,2,3,4,5,6
	alert( arr.concat([3, 4], 5, 6) ); // 1,2,3,4,5,6
// forEach  遍历数组元素
	let arr = ["Bilbo", "Gandalf", "Nazgul"];
	arr.forEach((item, index, array) => {
  		alert(`${item} is at index ${index} in ${array}`);
	});
// indexOf  从指定位置开始向右搜索指定元素，如果没有则返回-1
// lastIndexOf  从指定位置开始向左搜索指定元素，如果没有则返回-1
// includes  从指定位置开始搜索指定元素，如果有返回true，没有返回false
	

// find  查找具有特定条件的对象元素，有则返回当前元素，无则返回undefined
// findIndex  查找具有特定条件的对象元素，有则返回元素索引，没有则返回-1


// filter

// map


// sort(fn)
// reverse
// split
// join
// reduce
// reduceRight
// isArray
```

特性：

扩展：

## 数据类型深入研究

### NUMBER

作用：

用法：

```js
// length字符串长度
let str = "我是你爸爸";
console.log(str.length);// 4
```

特性：

扩展：

> Math对象
>
> 

### STRING

作用：

用法：

特性：

扩展：

> 特殊字符

### BOOLEAN

作用：

用法：

特性：

扩展：

### NULL

作用：

用法：

特性：

扩展：

### UNDEFINED

作用：

用法：

特性：

扩展：

### OBJECT

作用：

用法：

特性：

扩展：

window对象:

​	`window.location.hash`

`window.onhashchange()`

``

## 正则表达式

## 操作数据类型

### 操作基本数据类型

### 操作引用数据类型

## 异步

### DOM节点\BOM节点(接口nodeAPI)

### 事件

### generator

<div align='center'><font size='70'; face="宋体">JavaScript-<span style="color: skyblue;">ES6</span></font></div>

<font color="red">学习完后将es6新增内容归类给js中相应的模块</font>

# 第一遍

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
- 对象扩展
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

特点：块级作用域

### const

作用：定义常量

特点：块级作用域、值不可改变（保存值的地址不可改变）

### 解构赋值

作用：提取数组和对象的值，赋值给变量

用法：

特点：简化代码，

### 模板字符串

作用：声明字符串

用法：

特点：可换行书写、拼接变量

### 对象简化写法

作用：简化对象的书写，减少代码量

特点：

用法：

### 箭头函数

作用：函数的一种

用法：

```js
// 箭头函数
let fun = (a,b) => {...,...};
let fun1 = a =>{...,...};
let fun2 = b => ...;
let fun3 = () => ...;
```

特点：简化函数书写、this只指向声明时的变量

### 函数参数默认值

作用：给函数参数设置初始值

用法：

特点：

### rest

作用：获取函数实参，代替arguments

用法：

特点：

### 扩展运算符 `...`

作用：操作数组（将数组转化为逗号分隔的序列）

用法：

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

> 1. 新的异步编程的解决方案,解决回调地狱问题

用法：

```js
// promise对象主要有三种状态，初始化》成功（resolve）>失败(reject)
// const p = new Promise((resolve,reject) =>{resolve();reject();})  //promise的基本结构
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

promise中的方法：

`then`

```js

```

- ``

特点：

> 

# 第二遍

`字符串的扩展方法`

`对象增强`

`proxy`

`Reflect静态对象`

`静态方法static`

 `for...of循环`

`iterable可迭代接口`

`iterator迭代器`

`Generator生成器`

`Modules`

# 对象方法

### 对象

#### 对象遍历

#### 合并对象

- assign

#### 类型转换

- keys
- values
- entries
- fromEntries
- getOwnPropertyNames
- getOwnPropertySymbols

#### 其它

- create
- valueOf
- hasOwnProperty
- hasOwn
- freeze
- isFrozen
- seal
- isSealed
- is
- delete
- defineProperty
- Reflect.defineProperty
- defineProperties
- getOwnPropertyDescriptor
- getOwnPropertyDescriptors
- Reflect.ownKeys(obj)
- Reflect.deleteProperty(obj,"c")
- preventExtensions
- isExtensible
- getPrototypeOf
- setPrototypeOf

#### 应用场景

### 数组对象

#### 数组遍历

- map
- foreach
- filter

#### 增删改查

- push
- pop
- shift
- unshift
- slice
- splice
- concat
- fill

#### 排序

- reserve
- sort

#### 类型转换

- toString
- join

#### 合并数组



#### 其它

- reverse
- some
- find
- every
- instanceof
- isArray
- indexOf
- alstIndexOf

#### 应用场景

### 字符串对象方法

- length
- substr
- substring
- trim
- trimLeft
- trimRight
- toUpperCase
- toLowerCase
- split
- charAt
- charCodeAt
- fromCharCode
- concat
- indexof
- lastIndexOf
- slice
- replace
- replaceAll
- repeat

#### 类型转换

#### 应用场景

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

> 发布/订阅模式的优点是对象之间解耦，异步编程中，可以更松耦合的代码编写；缺点是创建订阅者本身要消耗一定的时间和内存，虽然可以弱化对象之间的联系，多个发布者和订阅者嵌套一起的时候，程序难以跟踪维护。

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

# 啥是原型和对象？

每个函数都有一个prototype属性指向一个对象(原型对象)，

每个对象都有一个 ____proto____ (隐式原型)属性，它指向创建此对象的函数中的prototype属性，

> Object对象是是所有对象的祖宗，也叫顶层对象，顶层对象的原型对象指向是null，表明没有原型对象

Object对象中的属性和方法可以被任何一个对象使用，因为所有对象都继承了Object的对象实例

# 遍历

# 数据类型存储与内存机制堆和栈

# 函数

### 函数的种类

# 对象

### 创建对象的方式

> #### 字面量创建

```js

```

> #### 工厂方法

```js

```

> #### 构造函数方法

```js

```



# 错误处理

> 介绍

