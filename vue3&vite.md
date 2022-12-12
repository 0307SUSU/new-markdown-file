<div align='center'><font size='7'; face="宋体">vue3&vite</font></div>

# 第一遍

## vite

> 定义：下一代前端开发与构建工具

构建工具有哪些？

> - webpack
>
> - rollup.js
> - vite

为什么要有构建工具？

> 

<font face="仿宋" size='5'>**vite的使用**</font>

## vue3

### setup

> 定义：一个函数，新的配置项，用不着data和method了

`用法`

```vue
<template>
  <div>
	<h1>歌曲信息</h1>
	<!--属性名可以直接用，不用再加this-->
	<h2>歌曲名{{musicName}}</h2>
	<h2>歌手{{singer}}</h2>
	<h2>评论数{{numDiscuss}}</h2>
  <button @click="MusicInfo">歌曲信息</button>
  <button @click="lyrics">歌词</button>
  <audio controls>
  	<source src="../M500002NMnJ60sMnKX.mp3" type="audio/ogg">
  	<source src="../M500002NMnJ60sMnKX.mp3" type="audio/mpeg">
	</audio>
  </div>
</template>

<script>
// 引入渲染函数
// import {h} from 'vue'
	export default {
        name:'App',
        setup(){
            //数据‘data’
            let musicName = '因为理想'
            let singer = '逃跑计划'
            let numDiscuss = 335
            //方法‘method’
            function MusicInfo(){
                // 因为数据是定义在函数内的，所以属性不用再指定this
                alert(`music name:${musicName},singer:${singer},number of discussions:${numDiscuss}`)
            }
            function lyrics(){
              // console.log(lyricsShow);
              // lyricsShow = true;
            }
            // 返回函数中的信息
            return{
               musicName,
               singer,
               numDiscuss,
               MusicInfo,
               lyrics,
            }
        }
    }
</script>
```

### ref

> 定义：一个函数，和vue2用的不是一个东西，互不影响

> 作用：修改配置项中的信息，实现响应式

#### `用法`

```vue
<template>
  <div>
	<h1>歌曲信息</h1>
	<!--属性名可以直接用，不用再加this-->
  <button @click="lyrics">歌词</button>
  <audio controls>
  	<source src="../M500002NMnJ60sMnKX.mp3" type="audio/ogg">
  	<source src="../M500002NMnJ60sMnKX.mp3" type="audio/mpeg">
	</audio>
  <div v-show="lyricsShow">
    <div style="text-align:center;color:#41555d;font-size:36px;font-family:仿宋;">因为理想</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#41555d;">当阳光穿过阴霾</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">希望在慢慢醒来</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#70f3ff;">天空是蔚蓝</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">熟悉的脚步匆忙</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">依旧是那样奔放</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">青春不再回来</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">理想不会像鲜花</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">美丽却经不起风雨考验</div>

<div style="text-align:center;font-size:18px;font-family:仿宋; color:#75664d">他会像黎明光芒一样</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#161823">冲破黑夜</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">如果歌声让你看见未来</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">那是青春的呼喊</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">擦去泪水我们一起</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">让一切重来</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">如果相聚让你没有恐惧</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">那是心灵的梦幻</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">因为理想</div>

<div style="text-align:center;font-size:18px;font-family:仿宋;color:#0aa344;">才是未来</div>
  </div>
  </div>
</template>

<script>
// 引入ref函数
import {ref} from 'vue'
	export default {
        name:'App',
        setup(){
            //数据‘data’
            let lyricsShow = ref(false); // 将需要修改的值传给ref函数
            //方法‘method’
            function lyrics(){
              // 打印一下使用了ref后的变量输出结果
              console.log(lyricsShow);
              // 通过修改变量lyricsShow的值，实现歌词的显示和隐藏
              lyricsShow.value = !lyricsShow.value;
            }
            // 返回函数中的信息
            return{
               lyricsShow,
               lyrics,
            }
        }
    }
</script>
```

> <font face='宋体' color='red'>lyricsShow为什么要加.value？</font>

先看一下console.log(lyricsShow);的打印结果

![image-20220113171512652](C:\Users\25369\AppData\Roaming\Typora\typora-user-images\image-20220113171512652.png)

从结果可以看出，lyricsShow的值变成了一个对象，这是因为ref函数将lyricsShow的值处理成了一个<font color="#8c4b31">引用对象</font>，而对象里的value属性值，就是原本lyricsShow的值，所以要改变lyricsShow的值，就得改变value的值。<font color="#2f90b9">至于ref为什么这么做，这里暂时先不解释</font>

> <font face='宋体' color='red'>特性</font>

- 对象类型的值用法不一样

```js
let obj = ref({
	musicName:'阳光照进回忆里',
	singer:'逃跑计划',
	numDiscuss:1026,
})

function musicInfo(){
    // 打印使用ref函数后obj对象的结果
    console.log(obj)
    console.log(obj.value)
    console.log(obj.value.musicName.value) //undefined
    console.log(obj.value.singer)
    console.log(obj.value.numDiscuss)
}
```

查看打印结果

![image-20220113183400858](C:\Users\25369\AppData\Roaming\Typora\typora-user-images\image-20220113183400858.png)

从结果可以看出，ref处理对象类型的值value返回的是一个proxy对象，而proxy对象值的结构和原对象结构一致，所以对象里边的属性值不需要再通过.value获取。<font color="#2f90b9">至于ref为什么这么做，这里暂时先不解释</font>
