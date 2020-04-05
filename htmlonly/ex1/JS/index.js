// 方法一
function demo() {
    var nv = document.getElementById("p1");
    nv.innerHTML = "Hello World";
} // 注意： 绝对不要再文档加载完成之后使用document.write()。这回覆盖该文档

// 方法二
function demo1() {
    document.getElementById("p2").innerHTML = "Hello World";
}

// 该百年HTML属性
function demo2() {
    document.getElementById("a1").href = "http://baidu.com";
}

// 寻找元素
// 通过id找到HTML元素
// 通过标签名找到HTML标签(不建议
// 改变HTML内容使用属性：innerHTML
// 改变HTML属性使用：attribute

// 修改css属性

function demo3() {
    document.getElementById("p1").style.color = "#f4f4f4";
    document.getElementById("p1").style.background = "#b4c3c3";
}

/*******************************
 * 1. DOM EventListener:
 * 方法： addEventLitener(); 添加一个句柄
 *       removeEventListener();  移除当前的句柄
 * 2. addEventListener():
 */

 var x = document.getElementById("btn");
 x.addEventListener("click", Hello());
 x.addEventListener("click",world());
 x.removeEventListener("click",Hello());
 function Hello() {
     alert("Hello");
 }
 function world() {
     alert("World");
 }

 /********
  * 1.事件流：
  *   描述的是在页面中接受事件的顺序
  * 2.事件冒泡(使用的最多)
  *   由最具体的元素接受，然后逐级向上传播到最不具体的元素节点（文档）
  * 3.事件捕获
  *    最不具体的节点先接收事件，而最具体的节点应该是最后接收事件
  */

/****************************
 * 1.HTML事件处理：
 *      直接添加到HTML结构中
 * 2.DOM0级事件处理
 *      把一个函数赋值给一个事件处理程序属性
 * 3.DOM2级事件处理
 *      addEventListener("事件名", "事件处理函数", "布尔值")
 *      true:事件捕获
 *      false：事件冒泡
 *      removeEventListener();
 * 4.IE事件处理程序(版本小于等于8)
 *      attachEvent
 *      detachEvent
 */

