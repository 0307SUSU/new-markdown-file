<div align="center"><font face="仿宋" size="6" color="#006d0e">Node</font></div>

# <font color="#006d0e">安装</font>

- 去官网https://nodejs.org/en/下载LTS稳定版

![image-20220126154238304](C:\Users\25369\AppData\Roaming\Typora\typora-user-images\image-20220126154238304.png)

- 单击下好的软件，按提示默认安装
- 安装结束之后通过查看软件版本的方式检查是否安装成功

> win+R键输入cmd，打开windows终端，在终端中输入node空格-v指令回车，如果出现下方图片红色圈中的内容，说明安装成功

![image-20220126155049906](C:\Users\25369\AppData\Roaming\Typora\typora-user-images\image-20220126155049906.png)

> 如果没有显示版本号，说明安装不成功，需重新安装。

# <font color="#006d0e">终端常用命令</font>

```bash
cd 路径地址   #去往指定的目录下
esc   # 清除当前已输入的命令
tab   # 快速补全文件名
cls命令   #清空终端内容
```

# <font color="#006d0e">模块化（Natives modules）</font>

<font color="skyblue">使用模块化无非需要注意两件事导出和引入</font>

### commonJS规范 `Node.js中默认使用的模块化标准`

> `exports` 输出 ，module中的属性（也可以单独作为变量使用，用来指定模块的输出内容）
>
> `require` 输入 （获取指定模块暴露的内容，不可用于加载ES6模块，ES6模块有单独的引入方法“import()”）
>
> `module` 是一个全局对象，存储了当前模块基本信息
>
> `__filename` 当前模块绝对路径
>
> `__dirname` 当前文件所在目录路径

commonJS模块最外层会被一个函数包裹，上边的五个属性会作为该函数的参数传入，所以每个模块都可以直接使用这些参数

```js
(function(exports, require, module, __filename, __dirname) {
// 模块代码会被放到这里
});
```

### ES module 规范  `ES的内置模块化标准`

> export  导出
>
> import 引入



### 内置模块

Node中的全局对象`global` (标准名称叫做`globalThis`)

`process` 操作当前的node进程

> 属性和方法
>
> process.exit()   结束进程
>
> process.nextTick()  tick任务队列中添加任务

#### fs文件处理模块

writeFile、copyFile、readFile、unlink、appendFile、rename、

readdir、rmdir、stat、mkdir、exists、copyDir

watch、open、read、

"fs-extra"、"compressing"、

#### path路径处理模块

#### http（网络协议）服务器模块

createServer、

- createServer
  - on
  - listen



### 自定义模块

### 第三方模块

# <font color="#006d0e">包</font>

### npm命令

```bash
# 
```



### Express（基于http模块封装出来的）

### koa

##### 路由

##### 中间件

##### 如何解决跨域

# 底层（v8引擎）



npm、内置模块、自定义模块、第三方模块

fs、path、url、http

express、

process
