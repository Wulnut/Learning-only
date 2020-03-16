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
