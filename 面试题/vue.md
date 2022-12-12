[TOC]



### vue组件封装

##### vue组件封装的优点

组件([Component](https://so.csdn.net/so/search?q=Component&spm=1001.2101.3001.7020))是Vue.js最强大的功能之一
组件可以扩展HTML元素，
封装可重用代码 组件是可复用的Vue 实例

组件可以提升整个项目的开发效率。能够把页面抽象成多个相对独立的模块，解决了我们传统项目开发：效率低、难维护、复用性低等问题。

##### 组件封装的大概过程

使用Vue.extend方法创建一个组件，然后使用Vue.component方法注册组件。但是我们一般用脚手架开发项目，每个 .vue单文件就是一个组件。在另一组件import 导入，并在components中注册，子组件需要数据，可以在props中接受定义。而子组件修改好数据后，想把数据传递给父组件。可以采用emit方法。

### vue组件监听

- $emit

子组件使用 `$emit()` 方法触发事件，父组件使用 `v-on` 指令监听子组件的自定义事件。

- .native

在组件上也可以监听原生事件，在使用 `v-on` 命令时，添加一个 `.native` 修饰符即可。

- .sync

在某些情况下，可能需要对一个组件的 prop 进行双向绑定，Vue.js 推进以 update: myPropName 模式触发事件来实现。

为了方便起见，Vue.js 为了上述这种模式提供了一个缩写，即 `.sync` 修饰符（在 v-bind 指令上使用）

### vue工作原理

vue双向数据绑定原理

数据驱动视图，利用mvvm设计思想

vue 是一套用于构建用户界面的渐进式[框架](https://so.csdn.net/so/search?q=框架&spm=1001.2101.3001.7020)。它的核心库只关注视图，采用的mvvm设计模式。vue的中心思想就是：数据驱动视图

- vue双向数据绑定是通过数据劫持(proxy)、组合、发布订阅模式的方式来实现，数据和视图同步，数据发生变化，视图跟着变化，视图变化，数据也随之发生改变。
- 通过 Object.defineProperty()来劫持各个属性的 setter，getter，在数据变动时发布消息给订阅者，触发相应的监听回调。
- Vue.js 3.0, 放弃了Object.defineProperty ，使用更快的ES6原生 Proxy (访问对象拦截器, 也称代理器)

### mvvm

采用mvvm设计模式，model数据层与view视图层通过viewmodel视图模型处理实现数据层到视图层的双向绑定。

数据层在vue中体现就是书写在data中的数据，vm通过监听data中的数据变化，继而更新页面展示内容。

vm是如何处理data数据的？

Object.defineProperty()数据代理

get和set方法

数据劫持

数据代理就是将data中的数据添加到vm实例中，方便书写，然后vm通过Object.defineProperty()中的get和set方法对data中的数据进行处理

vm层（视图模型层）通过接口从后台m层（[model](https://so.csdn.net/so/search?q=model&spm=1001.2101.3001.7020)层）请求数据，vm层继而和v（view层）实现数据的双向绑定。

mvc和[mvvm](https://so.csdn.net/so/search?q=mvvm&spm=1001.2101.3001.7020)的关系？

改进版

数据分离

视图模型层

c（控制层）被换成了vm（viewmodel）层

MVVM是Model-View-ViewModel的简写。它本质上就是MVC 的改进版。

mvvm层实现了前后端更好的分离（前端需要的数据只需要请求后端的接口即可）

### 数据更新视图不更新

Vue 无法检测实例被创建时不存在于 `data` 中的变量

vue也不能检测到data中对象的动态添加和删除

异步获取接口数据，DOM数据不发现变化

循环嵌套层级太深，视图不更新

路由参数变化时，页面不更新(数据不更新)

### $nextTick 

当你修改了data的值然后马上获取这个dom元素的值，是不能获取到更新后的值，你需要使用$nextTick这个回调，让修改后的data值渲染更新到dom元素之后在获取，才能成功。

一般created的时候dom没有渲染，如果要操作dom，最好放在this.$nextTick(()=>{})回调函数 中完成

### keep-alive

主要是用于需要频繁切换的组件时进行缓存，不需要重新渲染页面

### 组件

> 实现应用中局部功能代码和资源的集合
>
> 组件化，利用组件将特定的功能拆分成功不同的组件
>
> 模块化，将js代码拆分成不同的模块

### 单文件组件



### 组件通信方式

- props/$emit

- 插槽slot

> 默认插槽、具名插槽、作用域插槽

用于父组件向子组件传递"标签数据"。也即子组件先有一个"占位符", 等待父组件传入具体的标签，子组件在进行渲染。

- vuex状态管理

- ref / $refs

这种方式也是实现父子组件之间的通信

ref：这个属性用在子组件上，它的用用就指向了子组件的实例，可以通过实例来访问组件的数据和方法

- $parent / $children

使用$parent可以让组件访问父组件的实例（访问的是上一级父组件的属性和方法）。

使用 $children 可以让组件访问子组件的实例，但是， $children 并不能保证顺序，并且访问的数据也不是响应式的。

组件通信的几种方式

1、父子组件通信

2、兄弟组件通信

3、跨多层级组件通信

4、任意组件（vuex）

### 怎样使用自定义组件

import导入》compontents注册》template中使用

### vue生命周期

beforeCreate :创建vue实例 data computed watch methods不能访问;
created: 可以对data数据进行操作, 可进行一些请求,但不易过多,避免白屏时间太长
beforeMount:判断是否有template进行渲染保存到内存当中,但还未挂载在页面上;
mounted: 将内存中的模块挂载到页面上 ,此时可以操作页面上的DOM节点,但还未挂载在页面上
beforeUpdate: 页面显示的数据是旧的,此时data里的数据是最新,页面数据和data数据还没同步;
updated : 根据data里的最新数据渲染出最新的DOM树 然后挂载到页面
beforeDestroy:此时组件从运行进入到销毁阶段 data和methods可用 销毁还未执行;
destroyed : 组件已经完全销毁,所有的方法指令等都不可使用

### vuex

vue的状态管理

有五个核心属性

state、getter、mutation、action、module

state： 基本数据(数据源存放地)
getters： 从基本数据派生出来的数据
mutations ： 提交更改数据的方法，同步！
actions ： 像一个装饰器，包裹mutations，使之可以异步。
modules ： 模块化Vuex

### 路由的传参方式

params

query

### 路由跳转

router-link

this.$router.push

this.$router.replace

### $route 和 $router 的区别

router为VueRouter的实例，相当于一个全局的路由器对象，里面含有很多属性和子对象，
例如history对象,经常用的跳转链接就可以用this.$router.push，和router-link跳转一样。。。
route是一个跳转的路由对象，每一个路由都会有一个route对象，是一个局部的对象，可以获取对应的name,path,params,query等

$route是“路由信息对象”，包括path，params，hash，query，fullPath，matched，name等路由信息参数。
$router是“路由实例”对象包括了路由的跳转方法，钩子函数等

### 路由守卫 / 导航守卫

既然是守卫，首先是对咱们后台页面访问的一层保护，如果我没有进行登陆过，后台的操作页面是不允许用户访问的
我们是用到vue路由中的一个钩子函数beforeEach，那么这个函数中有三个参数，分别是to from next
to是去哪里 from是从哪里来 next下一步说通俗点就是放行
主要逻辑是判断我们有没有登录，那么我们可以通过登录后获取到的token来判断 如果有token就直接next()放行
如果没有的前提下，我们再判断用户访问的页面是不是登陆页面吗，是的话就放行 不是就跳回登录页

token失效期，我们前端该如何处理。 

### axios封装

安装依赖》

在src目录下新建一个<font color="red">接口文件夹</font>（文件夹名字可以自己取，一般叫api或者http)。在<font color="red">接口文件夹</font>下新建一个http.js(<font color="skyblue">用来封装axios</font>)和一个api.js(<font color="skyblue">用来统一管理接口</font>)。

相关配置

```js
// 1.引入所需资源
import axios from 'axios'; // 引入axios
import QS from 'qs'; // 引入qs模块，用于序列化post类型的数据
import {message} from 'element'; // 引入ui组件中的提示框组件(这里引入的ui组件以你项目使用的ui组件为准)


// 2. 项目环境切换，(我们的项目环境一般会有开发环境、测试环境、和生产环境。不同的环境ip地址也会不同)
process.env.NODE_ENV == 'development'? axios.defaults.baseURL ='开发环境地址';
:process.env.NODE_ENV == 'debug'? axios.defaults.baseURL = '测试环境地址';
:process.env.NODE_ENV == 'production'?axios.defaults.baseURL = '生产环境地址';:'';


// 3. 设置请求超时时间
axios.defaults.timeout = 1000*60*10;


// 4. 设置post请求头(post请求的时候，我们需要加上一个请求头)
axios.defaults.headers.post['Content-Type'] = 'application/x-www-form-urlencoded;charset=UTF-8';


// 5. 设置请求拦截，(开发中有时会需要在请求被触发了但还未发送时做一些操作，这时就用到了请求拦截器)。
// 先导入vuex,因为我们要使用到里面的状态对象
// vuex的路径根据自己的路径去写
import store from '@/store/index';
axios.interceptors.request.use(config => {        
        // 每次发送请求之前判断vuex中是否存在token        
        // 如果存在，则统一在http请求的header都加上token，这样后台根据token判断你的登录情况
        // 即使本地存在token，也有可能token是过期的，所以在响应拦截器中要对返回状态进行判断 
        const token = store.state.token;        
        token && (config.headers.Authorization = token);
        return config;    
    },    
    error => {        
        return Promise.error(error);    
})


// 6. 设置响应拦截，(开发中接口返回时会需要判断接口返回的状态，根据状态做一些操作，这时就用到了响应拦截器)。
axios.interceptors.response.use(
    // 接口返回成功状态的处理
	response =>{
        response.status===200?return Promise.resolve(response);
        :return Promise.reject(response);
    },
    /*
    只要接口返回的状态码不是以2开头的，都属于错误状态。
    不同错误状态码所代表的含义需要与后端协商
    协商好后根据返回的错误状态吗进行一些操做，(一般做错误提示)。
    */
    // 接口返回错误状态的处理
    error =>{
        if(error.response.status){
            switch(error.response.status){
                case 401:
                    //状态码为401时的处理
                    break;
                    
                case 404:
                    //状态码为404时的处理
                    break;
                default:
                    //除上面列举的错误以外的错误处理
            }
            return Promise.reject(error.response);
        }
    });
```

### computed与watch区别

computed是计算属性；watch是监听，监听data中的数据变化。
2、computed支持缓存，当其依赖的属性的值发生变化时，计算属性会重新计算，反之，则使用缓存中的属性值；watch不支持缓存，当对应属性发生变化的时候，响应执行。
3、computed不支持异步，有异步操作时无法监听数据变化；watch支持异步操作。
4、computed第一次加载时就监听；watch默认第一次加载时不监听。

immediate 组件创建时刻执行与否
immediate: true,第一次加载时监听（默认为false）
deep 深度监听 不推荐使用(非常的消耗性能)
监听的属性是对象的话 不开启deep 对象子属性变化不会触发watch
开启了deep 对象内部所有子属性变化 都会触发watch
5、computed中的函数必须调用return；watch不是。
6、使用场景：
computed：一个属性受到多个属性影响，如：购物车商品结算。
watch：一个数据影响多条数据，如：搜索数据。
数据变化响应，执行异步操作，或高性能消耗的操作，watch为最佳选择。

当需要进行数值计算,并且依赖于其它数据时,应该使用 computed,因为可以利用 computed的缓存特性,避免每次获取值时,都要重新计算。
当我们需要在数据变化时执行异步或开销较大的操作时,应该使用 watch,使用 watch 选项允许我们执行异步操作 ( 访问一个 API ),限制我们执行该操作的频率, 并在我们得到最终结果前,设置中间状态。这些都是计算属性无法做到的。
多个因素影响一个显示，用Computed；一个因素的变化影响多个其他因素、显示，用Watch;

### v-for与v-if

当它们处于同一个**元素节点**时，v-for的[优先级](https://so.csdn.net/so/search?q=优先级&spm=1001.2101.3001.7020)高于v-if。因此，v-if将重复运行于每个v-for循环中。

### v-if与v-show

都是用来控制元素显示或隐藏

v-if 当值为 true时，显示div ，当值为false时，改元素消失，代码也会消失，相当于将代码删除了，当在为true时，页面会重新渲染div;
而v-show 控制的隐藏出现，只是将css属性设为了display：none 或block;

### 如何解决跨域

当一个请求url的**协议、域名、端口**三者之间任意一个与当前页面url不同即为跨域 

nginx反向代理

在vue开发中实现跨域：在vue项目根目录下找到vue.config.js文件（如果没有该文件则自己创建），在proxy中设置跨域

```js
devServer: {
    proxy: {  //配置跨域
      '/api': {
        target: 'http://121.121.67.254:8185/',  //这里后台的地址模拟的;应该填写你们真实的后台接口
        changOrigin: true,  //允许跨域
        pathRewrite: {
          /* 重写路径，当我们在浏览器中看到请求的地址为：http://localhost:8080/api/core/getData/userInfo 时
            实际上访问的地址是：http://121.121.67.254:8185/core/getData/userInfo,因为重写了 /api
           */
          '^/api': '' 
        }
      },
    }
  }
```

### key

key就是一个标识，被使用在Vue中。再详细一点，key被使用在Vue中的虚拟DOM中，并不会出现在真实DOM中。

### vue项目优化

### 插槽

组件化时候，有时需要让内容显示到指定位置，用slot的写法，展示出默认内容或自定义内容。

### 单向数据流

数据从父级组件传递给子组件,子组件内部不能直接修改从父级传递过来的数据。这样防止子组件意外改变父组件的状态

### v-on可以监听多个方法么? 要注意什么

可以,
1.当没有参数传递时，方法名称后面可以不加小括号
2.当需要传递参数时，且只有一个参数需要传递，而没有进行传递，会默认输出浏览器的eve

### ref

获取dom元素

### vue常用修饰符

- 事件修饰符


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

- 键盘事件修饰符

.enter
.tab
.delete (捕获“删除”和“退格”键)
.esc
.space
.up
.down
.left
.right

- 系统修饰符

.ctrl
.alt
.shift
.meta

- 鼠标按钮修饰符


.left

.right

.middle

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

### mixin混入







