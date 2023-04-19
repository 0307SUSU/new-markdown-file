# js中的window对象(浏览器的宿主对象)

### URL

> 将blob或者file读取成一个url

```JS
window.URL.createObjectURL(file/blob)// URL.createObjectURL() 静态方法会创建一个 DOMString，其中包含一个表示参数中给出的对象的URL
window.URL.revokeObjectURL() //释放一个之前已经存在的、通过调用 URL.createObjectURL() 创建的 URL 对象
```

### navigator

> 



