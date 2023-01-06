# flex布局

传统布局模式：盒子布局

## flex布局是什么

Flexble Box（弹性布局），

任何容器都可以指定为flex布局，只要加上`display:flex;`,

行内元素也可以使用flex布局，`display:inline-flex;`,

如果是Webkit内核的浏览器，必须加上`-webkit`前缀。       `display:-webkit-flex;`

指定为flex布局后，子元素的`float`、`clear`和`vertical-align`属性会失效。

容器属性

-   flex-direction控制容器的主轴方向
-   flex-wrap控制项目的换行方式
-   flex-flow   上边两个的组合
-   justify-content控制主轴的的对齐方式
-   align-items项目在交叉轴的对齐方式
-   align-content控制多轴的排列顺序

项目属性

-   flex-grow   放大元素
-   flex-shrink  缩小
-   flex-basis   设置子元素原始所占主轴空间大小
-   align-self    自定义某个项目的对齐方式，覆盖flex-items
-   flex   是`flex-grow`, `flex-shrink` 和 `flex-basis`的简写，默认值为`0 1 auto`。
-   order    排序

### 容器的属性

#### flex-direction

决定主轴的方向(即项目的排列方向)。

```css
.box{
    flex-direction:row(默认值)水平向右排列|row-reverse(水平向左排列)|column(自上而下排列)|column-reverse(自下而上排列)
}
```

#### flex-wrap

```css
.box{
    flex-wrap:nowrap(默认不换行)|wrap(换行，第一行在上方)|wrap-reverse(换行，第一行在下方);
}
```

#### flex-flow

```css
.box{
    flex-flow:<flex-direction>||<flex-wrap>;
}
```

#### justify-content

```css
.box{
    justify-content:flex-start(默认值，左对齐) | flex-end(右对齐) | center(居中) | space-between(两端对齐，项目之间的间隔都相等。) | space-around(每个项目两侧的间隔相等，所以，项目之间的间隔比项目与边框的间隔大一倍。)
}
```

#### align-items

```css
.box{
    align-items:flex-start(交叉轴的起点对齐) | flex-end(交叉轴的终点对齐) | center(交叉轴的中点对齐) | baseline(项目的第一行文字的基线对齐) | stretch(默认值，如果项目未设置高度或设为auto，将占满整个容器的高度);
}
```

#### align-content

```css
.box{
    align-content:flex-start与交叉轴的起点对齐。 | flex-end 与交叉轴的终点对齐。| center 与交叉轴的中点对齐。| space-between 与交叉轴两端对齐，轴线之间的间隔平均分布。| space-around 每根轴线两侧的间隔都相等。所以，轴线之间的间隔比轴线与边框的间隔大一倍。| stretch （默认值）：轴线占满整个交叉轴。;
}
```

### 项目的属性

#### order

定义项目的排列顺序，越小越靠前，默认0

```css
.item {
    order:<integer>;
}
```

#### flex-grow

项目的放大比例，默认为零，即如果存在剩余空间也不放大

```css
.item{
    flex-grow: number
}
```

#### flex-shrink

```css
.item{
    flex-shrink:number
}
```

#### flex-basis

```css
.item{
    flex-basis: length | auto;
}
```

#### flex

```css
.item {
  flex: none | [ <'flex-grow'> <'flex-shrink'>? || <'flex-basis'> ]
}
```

#### align-self      

允许单个项目有与其他项目不一样的对齐方式，可覆盖`align-items`属性。默认值为`auto`，表示继承父元素的`align-items`属性，如果没有父元素，则等同于`stretch`。

```css
.item {
  align-self: auto | flex-start | flex-end | center | baseline | stretch;
}
```

### 实列



















































