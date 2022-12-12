# webpack

### 什么是webpack

> 打包工具
>
> 前端项目工程化的具体解决方案。

### 核心概念

`入口entry`、`输出output`、`loader`、`插件plugins`

### 基本使用

### 安装

`npm install webpack@5.42.1 webpack-cli@4.7.2 -D`

### 配置

根目录下创建webpack.config.js

### webpac.config.js

#### 基本结构

```js
const path = require('path');
module.exports = {
    // entry（入口）指示webpack从哪个文件开始打包
    entry: '',
    // output（输出）指示webpack打包完的文件输出到哪里去，如何命名等
    output:{},
    // loader （加载器）webpack本身只能处理js、json等资源，其它资源需要借助loader，webpack才能解析
    module:{
        rules:[
           test:,  // 正则表达式，识别哪些文件会被转换
           use:'' // 定义使用哪个loader
        ]
    },
    // plugins（插件）扩展webpack的功能
    plugins:[],
    // mode （模式） 开发模式：development，生产模式：production
    mode:''
}
```

#### 开发模式下webpack配置文件处理

```js
module.exports = {
  // 单个入口语法
  entry: './src/main.js', 
  entry: ['./src/main.js', './src/app.js']
  // 多个入口语法
  entry: {
    	main: './src/main.js',
    	app: './src/app.js',
  },
};

// entry 指定了打包的文件范围，并且既可以只指定一个打包范围，也可以指定多个不同的打包范围，区别是语法上有些不同
```

```js
const path = require('path');
module.exports = {
    entry: './src/main.js',
    output:{
        path: path.resolve(__dirname, 'dist'),
        filename: 'bundle.js', // 命名随意
    },
};

// output 指定了打包好的文件名和输出的位置，path的值代表输出位置，filename的值代表输出后的文件名
```

```js
const path = require('path');
module.exports = {
    entry: './src/main.js',
    output: {
        path: path.resolve(__dirname,'dist'),
        filename: 'main.js'
    },
    module:{
        rules:[
            {
                test: /\.txt$/, 
                use: 'raw-loader'
            }
        ]
    }
}
```

```js
// 借助loader处理css资源
// npm install --save-dev css-loader style-loader
import css from "file.css";
module.exports = {
  module: {
    rules: [
      {
        test: /\.css$/i,
        use: ["style-loader", "css-loader"],
      },
    ],
  },
};
```

```js
//处理图片资源
// npm install file-loader --save-dev,(将一个文件中的 import/require() 解析为 url，并且将文件发送到输出文件夹)
module.exports = {
        test: /\.(png|jpe?g|gif|webp|svg)$/,
        type: 'asset',
        parser: {
          dataUrlCondition: {
            // 小于10000kb的图片转base64
            // 优点：减少请求数量 缺点：体积会变大
            maxSize: 10000 * 1024 // 100kb
          }
        }
      }
```

处理字体图标文件

```js
{
        test: /\.(ttf|woff2?)$/,
        type: 'asset/resource',
        generator: {
          filename: 'static/media/[hash:5][ext][query]'
        },
      },
```

```js
// 处理js资源文件
// npm install babel-loader @babel/core @babel/preset-env --save-dev

module.exports = {
	module: {
    	rules: [
        	{
        		test: /\.m?js$/,
        		exclude: /(node_modules|bower_components)/,
                use：{
        			loader: 'babel-loader',
        			options: {
          				presets: ['@babel/preset-env']
        			}
					}
      		} 
    	]
	}
}
plugins: [
    // 插件的配置
    new ESLintPlugin({
      // 检测哪些文件
      context: path.resolve(__dirname, "src"),
    }),
  ],
```

```js
// eslint配置  文件名（.eslintrc.js）
// 检查代码语法的工具，默认可以检查js和jsx语法
module.exports = {
  extends: ["eslint:recommended"],
  env: {
    node: true,
    browser:true,
  },
  parserOptions: {
    ecmaVersion: 6, // es语法版本
    sourceType:"module", // es 模块化
    ecmaFeatures: { // es其它特性
        jsx: true // 
    }
  },
  rules: { // 具体规则
    "no-var": 2,
  }
};
```

```js
// babel配置 文件名（babel.config.js）
// 主要用于将es6语法转换为向后兼容的js语法
module.exports = {
  presets: ["@babel/preset-env"], // 允许使用最新js
};
```

```js
// 处理html资源
// 下载插件
const HtmlWebpackPlugin = require('html-webpack-plugin');
new HtmlWebpackPlugin({
      template: path.resolve(__dirname,"public/index.html"),
    }),
```

```js
// 开发服务器，自动化
devServer: {
    static: {
      directory: path.join(__dirname, 'public'),
    },
    compress: true,
    port: 9000,
    open:true,
  },
```



#### 生产模式下webpack配置文件处理

css兼容性处理

```js

```

css压缩

```js

```

```js
module.exports = {
    entry:{},
    output:{
        filename:'bundle.js',
    },
    module:{
        ruless:[
            {test:/\.css$/,use:'css-loader'},
            {test:/\.ts$/,use:'ts-loader'}
        ]
    }
}
```



### 高级配置

#### 提升开发体验

sourceMap(源代码映射)

#### 提升打包构建速度
