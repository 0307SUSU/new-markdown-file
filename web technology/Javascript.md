<div align='center'><font size='70'; face="宋体">JavaScript</font></div>

## 变量

- var

### var

作用：关键字，声明一个可改变的值

用法：

```js
var num = 123
```

特性：

- 变量名不能以数字开头，并且不能是关键字或保留字

扩展：

## 基本数据类型

- Number
- String
- Boolean
- null
- undefined

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

- 算数运算符

+、-、*、/、%、**

- 逻辑运算符

&&、||、！

- 自增自减运算符

++、--

- 赋值运算符

=、+=、-=、*=、/=

- 比较运算符

==、===、!=、!==、>、<、>=、<=、

- unicode编码
- 条件运算符

条件表达式？条件为true执行：条件为false执行

条件表达式？条件表达式？条件为true执行：条件为false执行(另一个条件)?条件表达式？条件为true执行：条件为false执行

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
for(循环条件){
    循环体
}
// 嵌套循环语句
for(循环条件){
    for(循环条件){
        循环体
    }
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

## 引用数据类型

### OBJECT

作用：

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

作用：

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