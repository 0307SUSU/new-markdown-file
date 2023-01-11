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

### commonJS规范

> `exports` 输出
>
> `require` 输入
>
> `module` 
>
> `__filename` 当前模块绝对路径
>
> `__dirname` 当前文件所在目录路径

### 内置模块

Node中的全局对象`global` (标准名称叫做`globalThis`)

`process` 全局对象

> 属性和方法
>
> 

#### fs文件处理模块

#### path路径处理模块

#### http服务器模块

### 自定义模块

#### 模块化规范CommonJS规范

### 第三方模块

# <font color="#006d0e">包</font>

### npm包

### Express（基于http模块封装出来的）

##### 路由

##### 中间件

# 底层（v8引擎）



