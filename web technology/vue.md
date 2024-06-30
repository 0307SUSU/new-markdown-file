<div align='center'><font size='70'; face="宋体" color="#35ae92">vue</font></div>

## <font color="#35ae92">为什么要学习vue框架？</font>

传统dom操作带来的问题

> 简化dom操作，原生dom操作繁杂，代码繁杂
>
> dom操作与逻辑代码混合，可维护性差
>
> 不同功能区域写在一起，可维护性低
>
> 模块之间的依赖关系复杂

vue解决了这些问题

什么是vue？ 

> 渐进式的javascript框架

vue的核心特性

> 1. 数据驱动视图
>
> - 单项数据绑定
>
> - 双向数据绑定，适用于可输入元素
>
> 数据驱动视图实现原理（mvvm开发思想）
>
> model数据层>view视图模板>viewModel业务逻辑处理代码，中间处理层
>
> 数据驱动视图的优缺点
>
> - 解放DOM操作
> - viiew与model处理分离，降低代码耦合度
> - 缺点是双向绑定时bug调试难度增大
> - 大型项目下view与model过多，维护成本高
>
> 2. 组件化开发
>
> 什么是组件？就是自定义的html标签
>
> 可以将不同的功能封装成单独的组件，使用时直接调用组件即可，可复用性强
>

## <font color="#35ae92">vue的原理</font>

## <font color="#35ae92">keep-alive</font>

## <font color="#35ae92">单页面应用程序（spa）</font>

## <font color="#35ae92">vue-cli</font>

> cli创建项目流程

## <font color="#35ae92">项目结构（构建工具的使用，webpack,vite）</font>

> vue项目是由vue-cli创建的，不同的项目结构也会不同，但是它们都有一个基本结构，这个是不变的，并且以后开发过程都是在项目结构中完成的。所以在深入学习vue之前有必要先了解一下它的基本结构，再根据结构进行深入的学习。

## <font color="#35ae92">组件</font>

> vue项目是由多个单文件组件构成的，它以`.vue`为后缀。我们实现项目功能的代码一般都是在这里边完成的，并且后边要学习的大多数内容都是在这里边使用的，既然如此，在学习其它内容之前有必要先了解一下在单文件组件中代码应该如何书写。

## <font color="#35ae92">指令</font>

- `{{}} 插值表达式`

- `v-html`

- `v-text`

- `v-if`
- `v-else`
- `v-show`
- `v-for`
- `v-on`
- `v-bind`

- `v-model`
- `v-clock`
- `v-once`
- `v-pre`

```bash
##### vue指令之v-for和key属性

        <!-- 注意在遍历对象身上的键值对的时候,除了有 val 和 key,在第三个位置还有一个索引 -->
        <p v-for="(value,key,i) in user">{{value}} --- {{key}}----{{i}}</p>

        数组
        <p v-for="(user,i) in list">索引是:{{i}}---id:{{user.id}} --- name:{{user.name}}</p>

        循环遍历数字:
         <p v-for='count in 10'>这是第 {{count}} 次循环</p>

         v-for迭代数字:起始是从1开始

p18
##### v-for 中 key的问题
        v-for循环的时候,key属性只能使用 number 获取 string
        只能使用v-bind 属性绑定的形式指定key的值
        item身上的id是唯一的.

        以后都这样写:<p v-for='item in list' :key="item.id">
        保证数据的唯一性:

        在组件中使用v-for循环的时候,或者在一些特殊的情况中如果有问题,
        必须指定唯一的字符串.数字类型  :key值

p19
##### v-if  和  v-show 的 使用


        当v-if 和 v-show 均为false时

        v-if每次都会重新删除或者创建元素(有较高的切换性能消耗)

        v-show 不会进行dom的删除操作 (有较高的初始渲染消耗)
        
        只是切换了元素的 display:none 样式

        如果元素涉及到频繁的切换,最好不要使用 v-if
        如果元素永远不会显示出来被用户看到,最好使用v-if
```

## <font color="#35ae92">生命周期</font>

初始化》beforCreate》created》beformounte》mounted》beforUpdate》updated》beforeDestory》destoryed

## <font color="#35ae92">路由</font>

SPA(单页面应用)与路由

什么是路由？

工作方式

vue-router基本用法：

2.3挂载路由模块

2.4声明路由链接和占位符

​	2.4.2在路由模块中声明路由规则 (链接和组件之间的对应关系)

2.4.3 使用`router-link`代替a链接

vue-router常见用法：

2.1声明子路由链接和占位符

2.3默认子路由

- 编程式导航

push、replace、go

- hash和history模式

> Hash模式

`https://music.163.com/#/playlist?id=3102961863`

onhashchange

> History模式

`https://music.163.com/playlist/3102961863`

history.pushState()

history.replaceState()

## <font color="#35ae92">状态管理（vuex，pinia）</font>

## <font color="#35ae92">计算属性（computed）</font>

## <font color="#35ae92">监听器（watch）</font>

## <font color="#35ae92">过滤器（filter）</font>

## <font color="#35ae92">方法（method）</font>

## <font color="#35ae92">插槽（sort）</font>

## <font color="#35ae92">插件</font>

## <font color="#35ae92">混入mixin</font>

## <font color="#35ae92">深入响应式原理</font>
