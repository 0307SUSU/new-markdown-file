## js面试题

### 冒泡

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

### js的数据存储

- sessionStorage

> 仅在当前会话下有效，关闭页面或浏览器后被清除

- localStorage

> 用于长久保存整个网站的数据，保存的数据没有过期时间，直到手动去删除
>
> localStorage和sessionStorage最大一般为5MB，仅在客户端（即浏览器）中保存，不参与和服务器的通信；

- cookier

> Cookie 是一些数据, 存储于你电脑上的文本文件中，用于存储 web 页面的用户信息
> Cookie 数据是以键值对的形式存在的，每个键值对都有过期时间。如果不设置时间，浏览器关闭，cookie就会消失，当然用户也可以手动清除cookie
> Cookie每次都会携带在HTTP头中，如果使用cookie保存过多数据会带来性能问题
> Cookie内存大小受限，一般每个域名下是4K左右，每个域名大概能存储50个键值对



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

### this指向

js中，this就指当前的意思，this.xxx就指当前对象的xxx

谁调用就指向谁。全局调用就指向window（全局对象）

函数中的this指向要看函数属于哪个对象。全局作用域下定义的函数this就指向window。对象中定义的函数this就指向离它最近的那个对象,**闭包除外**

箭头函数本身没有this，所以所有箭头函数中的this都指向全局window

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

### vue双向数据绑定原理

- vue双向数据绑定是通过数据劫持(proxy)、组合、发布订阅模式的方式来实现，数据和视图同步，数据发生变化，视图跟着变化，视图变化，数据也随之发生改变。
- 通过 Object.defineProperty()来劫持各个属性的 setter，getter，在数据变动时发布消息给订阅者，触发相应的监听回调。
- Vue.js 3.0, 放弃了Object.defineProperty ，使用更快的ES6原生 Proxy (访问对象拦截器, 也称代理器)

### $nextTick 

当你修改了data的值然后马上获取这个dom元素的值，是不能获取到更新后的值，你需要使用$nextTick这个回调，让修改后的data值渲染更新到dom元素之后在获取，才能成功。

### vue组件传参

父传子，子传父，兄弟间传参

- props
- $emit
- vuex

### v-show和v-if指令

- 相同点:都可以控制dom元素的显示和隐藏
- 不同点:v-show只是改变display属性，dom元素并未消失，切换时不需要重新渲染页面
- v-if直接将dom元素从页面删除，再次切换需要重新渲染页面

### keep-alive

主要是用于需要频繁切换的组件时进行缓存，不需要重新渲染页面

### vue中获取dom

ref

### v-model的使用

- v-model用于表单的双向绑定，可以实时修改数据

### vuex

vue的状态管理

有五个核心属性

state、getter、mutation、action、module

state： 基本数据(数据源存放地)
getters： 从基本数据派生出来的数据
mutations ： 提交更改数据的方法，同步！
actions ： 像一个装饰器，包裹mutations，使之可以异步。
modules ： 模块化Vuex

### v-for 与 v-if 的优先级

v-for 和 v-if 同时使用，有一个先后运行的优先级，v-for 比 v-if 优先级更高，这就说明在
v-for 每次的循环赋值中每一次调用 v-if 的判断，所以不推荐 v-if 和 v-for 在同一个标签中同时使用。

### vue路由跳转

### Computed和Watch的区别

computed 计算属性 : 依赖其它属性值,并且 computed 的值有缓存,只有它依赖的 属性值发生改变,下一次获取 computed 的值时才会重新计算 computed 的值。

watch 侦听器 : 更多的是观察的作用,无缓存性,类似于某些数据的监听回调,每 当监听的数据变化时都会执行回调进行后续操作。

运用场景：

当我们需要进行数值计算,并且依赖于其它数据时,应该使用 computed,因为可以利用 computed的缓存特性,避免每次获取值时,都要重新计算。
当我们需要在数据变化时执行异步或开销较大的操作时,应该使用 watch,使用 watch 选项允许我们执行异步操作 ( 访问一个 API ),限制我们执行该操作的频率, 并在我们得到最终结果前,设置中间状态。这些都是计算属性无法做到的。
多个因素影响一个显示，用Computed；一个因素的变化影响多个其他因素、显示，用Watch;

### vue常用修饰符

事件修饰符

.stop 阻止事件继续传播
.prevent 阻止标签默认行为
.capture 使用事件捕获模式，即元素自身触发的事件先在此处处理，然后才交由内部元素进行处理
.self 只当在 event.target 是当前元素自身时触发处理函数
.once 事件只会触发一次
.passive 告诉浏览器你不想阻止事件的默认行为
v-model 的修饰符

.lazy 通过这个修饰符，转变为在 change 事件再同步
.number 自动将用户输入值转化为数值类型
.trim 自动过滤用户输入的收尾空格
键盘事件修饰符

.enter
.tab
.delete (捕获“删除”和“退格”键)
.esc
.space
.up
.down
.left
.right
系统修饰符

.ctrl
.alt
.shift
.meta

**鼠标按钮修饰符**

- .left
- .right
- .middle

### vue常用指令

v-model 多用于表单元素实现双向数据绑定（同angular中的ng-model）
v-bind 动态绑定 作用： 及时对页面的数据进行更改
v-on:click 给标签绑定函数，可以缩写为@，例如绑定一个点击函数 函数必须写在methods里面
v-for 格式： v-for=“字段名 in(of) 数组json” 循环数组或json(同angular中的ng-repeat)
v-show 显示内容 （同angular中的ng-show）
v-hide 隐藏内容（同angular中的ng-hide）
v-if 显示与隐藏 （dom元素的删除添加 同angular中的ng-if 默认值为false）
v-else-if 必须和v-if连用
v-else 必须和v-if连用 不能单独使用 否则报错 模板编译错误
v-text 解析文本
v-html 解析html标签
v-bind:class 三种绑定方法
					对象型 ‘{red:isred}’
					三元型 ‘isred?“red”:“blue”’
					数组型 ‘[{red:“isred”},{blue:“isblue”}]’
v-once 进入页面时 只渲染一次 不在进行渲染
v-cloak 防止闪烁
v-pre 把标签内部的元素原位输出

### $route和$router的区别

$route是“路由信息对象”，包括path，params，hash，query，fullPath，matched，name等路由信息参数。
$router是“路由实例”对象包括了路由的跳转方法，钩子函数等