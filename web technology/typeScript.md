<div align='center'><font size='70'; face="宋体">TypeScript</font></div>

# <font size='5' face='宋体' color='#ff6700'>安装</font>

> 安装ts： npm i -g typescript

# <font size='5' face='宋体' color='#ff6700'>编译</font>

> ts文件最终需要编译成js文件

​	编译方法：

- 手动编译  控制台>tsc 要编译的文件名

- 自动编译  :

> 1. 安装 ts-node  `npm i -g ts-node`
>1. 创建配置文件   tsconfig.json
> 1. 设置配置选项
>
> ```json
> {
>     /*
>     	"include",指定哪些ts文件需要编译
>     	"exclude",指定不需要被编译的文件目录
>     		一般默认有：["node_modules", "bower_compoonents", "json_packages"]
>     	路径中的**和*分别表示任意目录和任意文件
>     */
>     "include": [
>         "./src/**/*"
>     ],
>     "exclude": [
>         
>     ]
>     
>     /*
>     	compilerOptions  编译器的选项
>     	它决定了编译器如何对ts文件进行编译
>     */
>     
>     "compilerOptions":{
>     	// target 用来指定ts文件将编译成ES的哪个版本，
>     	// 通过输入一个错误的值，可以在控制台查看可输入的值
>     	"target": "es2015",
>     	// module 指定要使用的模块化规范
>     	// 和上面一样查看可输入的值
>     	"module": "es2015,dom",
>     	// outDir 指定编译后的文件存放目录
>     	"outDir": "./dist",
>     	// 将所有编译后的Ts文件代码合并到一个文件中(一般不用)
>     	"outFile": "./dist/app.js"
>     	// 是否编译js文件，默认false
>     	"allowJs": true,
>     	// 检查js代码是否符合语法规范，默认false
>     	"checkJs": truue,
>     	// 是否删除注释
>     	"removeComments": true,
> 		// 不生成编译后的文件
>     	"noEmit": false,
>     	// 当有错误时不生成编译后的文件
>     	"noEmitOnError": true,
>     	// 严格检查总开关
>    		"strict": true,
>     	// 编译后的文件是否使用严格模式
>     	"alwaysStrict": true,
>     	// 不允许隐式的any类型
>     	"noImplicitAny": true,
>     	// 不允许没有明确类型的this
>     	"noImplicitThis": true,
>     	// 严格的检查空值
>     	"strictNullChecks": true
> 	}
> 	
> }
> ```

<font color='red'>注意：</font>即使ts代码报错，也能编译成js代码

> flow：静态类型检查器

> 配置文件

# <font size='5' face='宋体' color='#ff6700'>数据类型</font>

变量的声明

```ts
var a: number = 1;
let b: String = '字符串';
const c: boolean = true;
let arr: number[] = [1,2,34,5,6,7,8];
let arr2:string[] = ['one','two','there'];
let Array<number> = [1,2,4,5,6,7,8];
let arr3:[number,string];
arr3 = [12,'字符串']；
let n: null = null;
let u: undefined = undefined;
any  任意数据类型
void  没有任何类型
never
组合类型   一个变量可以赋予多种类型
enum flag{
    name = "sw",
    age = "30",
    sex = "man",
};
let one:flag = flag.sex;

function sum (d: number, e:number){
    return d+e;
}
sum(d:123, e:456); // 正常
sum(d:123, e:'456'); //类型不对，会报错



```

ts中的数据类型

- number
- string
- boolean
- 字面量
- any(任意类型)
- unknown(未知类型)
- void (表示没有返回值)
- never(永远不会返回结果)
- object(对象类型)
- array(数组类型)
- tuple元组类型(固定长度的数组)
- enum(枚举类型)
- 函数类型

`类型断言`

```ts

```

# <font size='5' face='宋体' color='#ff6700'>面向对象</font>

# <font size='5' face='宋体' color='#ff6700'>接口</font>

`interFace`



# <font size='5' face='宋体' color='#ff6700'>类</font>

`class`

```ts
// 定义类   通过class关键字定义
class Person{
    // 属性
    // 实例属性
    nusicName:"生活因你而火热";
    singer: "新裤子乐队";
    commentNum: 5264;
    
    //静态属性（类属性） static
    static age：number = 18;
    
    //readonly 只读属性
    readonly name: string = '没有理想的人不伤心';
    
    // readonly & static
    static readonly age: number = 18;
    // 方法
    static sayHello(){
        console.log('我会和，她结婚！');
    }
}
const per = new Person();  //实例化Person类w
console.log(per); // 打印Person类
per.sayHello(); // 调用实例方法
Person.sayHello(); // 调用类方法
```

> 构造函数&this

# <font size='5' face='宋体' color='#ff6700'>泛型</font>

> 解释：”泛：泛指“ 不确定的类型，定义函数或类时，遇到类型不明确可以使用泛型

