<div align='center'><font size='70'; face="宋体">Axios</font></div>

> axios是一个专注于网络请求的库

1. 调用axios方法，得到的返回值是 Promise对象
2. axios请求的接口返回值外层会套上一层壳

## vue中axios的使用

> 封装axios

1. 安装依赖

​		`npm install axios --save`

2. 在src目录下新建一个<font color="red">接口文件夹</font>（文件夹名字可以自己取，一般叫api或者http)。在<font color="red">接口文件夹</font>下新建一个http.js(<font color="skyblue">用来封装axios</font>)和一个api.js(<font color="skyblue">用来统一管理接口</font>)。

```js
/*
http.js
封装axios
*/


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

