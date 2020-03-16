console.log("hello world");

var name = "good";
console.log(name);

var fontColor="red";
console.log(fontColor);


var a = 5;
var b = 6;
var c = a + b;

console.log(c);


//const FIVE_SECONDS = 5000;

//const buttom = new Button();

var vissible = true;
var isEqual = false;

console.log(vissible);

// JS 是全类型数据类型

var notInitialized;

console.log(notInitialized);

var emptyValue = null;
console.log(emptyValue);

console.log(typeof vissible);

var num = 100;
var str = "hello";

var result = num + " " + str;

console.log(result);

var strNum = "123";
console.log(parseInt(strNum) + num);

// parseInt() 将字符串转变为整形
// parseFloat() 将字符串转换为浮点型

/*
下方的代码是为了一下操作
1.获取表单的值
2.提交表单
*/

// 下面的注释为文档注释, number 是数字类型
/**
 * @param {number} a
 * @param {number} b
 * @return 返回两个操作数的和
 */

 function add(a, b) {
     return a + b;
 }

var re = add(1, 3);

console.log(re);


var x = 10;
var y = 10;

console.log(x, y);// 可以同时打印两个数字中间并友空行

console.clear(); // 清空控制台

var negativeNum = -5;

console.log(negativeNum);

var strNum =+ "3";

console.log(strNum, typeof strNum);

var num = 8;
console.log("this " + num++);
console.log(num);

console.clear();


// 运算符
console.log("7 / 2 = ", 7 / 2);

console.log("7 %  2 = ", 7 % 2);

console.log("4 ** 2 = ", 4 ** 2);


// 比较操作符
console.clear();

console.log("1 > 5", 1 > 5);
console.log("1 >= 5", 1 >= 5);
console.log("5 == 5", 5 == 5);
console.log('5 == "5"', 5 == "5");
console.log('5 === "5"', 5 === "5"); // === 是对类型进行比较
console.log("undefined == null", undefined == null);
console.log("undefined === null", undefined === null);

// 位运算符
console.clear();

// 5 101
// 3 011
// 与
console.log("5 & 3", 5 & 3);

// 或
console.log("5 | 3", 5 | 3);

// 亦或
console.log("5 ^ 3", 5 ^ 3);

// 逻辑取反
console.log("~ 5", ~ 5);
console.log("~ 3", ~ 3);

// 左移 = 移动一位相当于乘2
console.log("5 << 1", 5 << 1);
// 右移 = 移动一位相当于除2
console.log("5 >> 1", 5 >> 1);

// 无符号右移
console.log("-5 >>> 1", -5 >>> 1);


// if ... else
console.clear();

// prompt是浏览器自带的输入框
/*
var passcode = prompt("请输入密码")
var login = "123";
if (passcode === login) {
    alert("登陆成功");
}
else{
    alert("登陆失败");
}
*/
// if ... else if ... else
/*
var role = prompt("请输入用户权限");
if (role === "超级用户管理员") {
    alert("跳转到超级管理员界面");
}
else if (role === "管理员") {
    alert("跳转到管理员页面");
}
else {
    alert("跳转到用户界面");
}
*/


/*
// switch.. case 

var role = prompt("请输入用户权限");

switch (role) {
    case "超级管理元" :
        alert("高级管理员");
        break;
    case "管理员" :
        alert("管理员");
        break;
    case "一般用户" :
        alert("一般用户");
        break;
    default :
        alert("其他页面");
}

*/


// 自执行函数
console.clear();

var num1 = 10;

// 自执行函数
(function() {
    var num1 = 20;
    console.log(num1);
})();


/**
 * 可以防止函数里面的变量和外面变量命名冲突
 */

console.log(num1);

// 函数柯里化
console.clear();

function addThreeNumsCurry(a) {
    return function(b) {
        return function(c) {
            return a + b + c;
        }
    }
}

console.log(addThreeNumsCurry(1)(2)(3));

var fixedTwo = addThreeNumsCurry(1)(2);
console.log(fixedTwo(4));
console.log(fixedTwo(7));


// 回调函数,一般作为参数传入另一个函数，回调函数也可以有参数

console.clear();

var a = "success";

function request(cb, a) {
    console.log("请求数据");
    cb(a);
    console.log("请求结束");
}

function callback() {
    console.log("执行回调");
    console.log("执行结果");
}

function callback2(result) {
    console.log("执行回调");
    console.log("执行结果 " + result);
}
//可以用箭头函数来简化回调函数, 但是箭头函数不能复用

request(result => {
    console.log("success");
})

//request(callback2, a);

// 数组
console.clear();

// 方法1，直接赋值
var arr1 = [1, 2, 3, 4, 5, 6, 7];

console.log(arr1);

// 方法2，通过构造函数
var arr2 = new Array(1, 2, 3, 4, 5);

console.log(arr2);

// 方法3，通过数组的对象直接创建

var arr3 = Array(1, 2, 3, 4);

console.log(arr3);

// 方法4,用Array.of

var arr4 = Array.of(10,11,12);

console.log(arr4);

// 注意如果要创建的数组中只放一个值的时候只能用方法1和方法4。
// 如果使用方法2和方法3传入一个值表示数组的长度

var arrSingle = Array(6);
console.log(arrSingle);

var arrSingle2 = new Array(7);
console.log(arrSingle2);

var arrSingle3 = Array.of(4);
console.log(arrSingle3);

var arrSingle4 = [2];
console.log(arrSingle4);

// 访问数组

console.clear();

var arr = [1, 2, 3];

console.log(arr.length);

console.log(arr[2]);
console.log(arr[3]);

// 添加元素
// 可以在末尾添加新的元素，如果在一个很远的地方添加一元素，中间是empty来表示一般返回undefined
console.clear();

var arr = [1, 2, 3];
arr[0] = 4;
console.log(arr[0]);
console.log(arr);

arr[8] = 9;

console.log(arr);
console.log(arr[6]);

// 删除元素
console.clear();

var arr = [1, 2, 3];

arr.length = 2;//表示将数组改成长度改为2，也就是删除最后为一位
console.log(arr);

arr.length = 0; // 表示清空整个数组
console.log(arr);

var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];

arr.splice(2, 1); // splice第一个参数表示索引的位置，第二表示删除的个数
console.log(arr);

arr.splice(2, 2);
console.log(arr);

arr.splice(1, 2, 3, 7, 8); // splice这个函数从第三个参数开始就是从索引为2的地方，删除原本元素然后插入元素
console.log(arr);

arr.splice(1, 0, 9, 10); // 表示所引的位置但是删除0个也就是可以进行插入，在索引为1的后面插入9， 10
console.log(arr);

// 数组地而遍历

console.clear();
var arr = [1,2,3];
// for循环
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}

// for...of遍历

console.log("for...of");
for (let ele of arr) {
    console.log(ele);
}

// for each遍历

arr.forEach((ele, index, self) =>{
    console.log(ele, index, self);
})

// forEach整个方法接受一个回调函数，第一个表示遍历到的元素，第二表示遍历到的索引，第三个表示数组本身

// 栈模式
console.clear();
// 这里的stack只是一个名字而已
var stack = [1, 2, 3];
// 入栈
stack.push(4);
console.log(stack);

// 出栈
var last = stack.pop();
console.log(last);
console.log(stack);

// 放分栈顶元素
console.log("栈顶元素: " + stack[stack.length - 1]);

// 队列

console.clear();

var queue = [1, 2, 3];

//入队
queue.push(4, 5, 6);
console.log(queue);

// 出队
var first = queue.shift();
console.log(first);
console.log(queue);

// 从队列头部插入
queue.unshift(10, 11, 12);
console.log(queue);

// 反转数组

console.clear();

var arr = [1, 2, 3];
console.log(arr.reverse());
// reverse不是将数组反转打印，而是讲数组中住元素进行反转，交换位置
console.log(arr);

// 反转字符串
// split是将字符串中的每个字符分割， 下面操作表示不任何分割符
//join是split的反向操作，下面操作表示不加任何分割符
console.log("hello".split("").reverse().join(""));

// split 和join中间可以加什么还有什么操作

// 数组的排序
console.clear();

var arr = [3, 2, 1];
arr.sort();// 升序
console.log(arr);

arr.sort((a, b) => {
    if (a > b) {
        return -1; // 将a放在前面
    } 
    else if (a < b) {
        return 1; // 将a放在后面
    }
    else {
        return 0; // 位置不变
    }
})// 降序（针对于所有数据类型）

//降序简写（仅只针对于对数字排序）

arr.sort((a, b) => b - a);
console.log(arr);

// 数组的连接 使用concat方法
console.clear();

var arr1 = [1, 2, 3];
var arr2 = [4, 5, 6];
console.log(arr1.concat(arr1, arr2));

// 数组的裁切
console.clear();

var arr = [1, 2, 3, 4, 5, 6];

console.log(arr.slice(1));
// slice(1)表示数组保留从索引为1开始的后面的数据

var arr2 = [1, 2, 3, 4, 5, 6];
console.log(arr2.slice(1, 3));
// slice(1, 3)表示数组保留从索引为1开始的到3结束但不包含3

var arr3 = [1, 2, 3, 4, 5, 6];
console.log(arr3.slice(1, -1));
// slice(1, -1)表示数组保留从索引为1开始， -1表示倒数索引为1的数结束包含该数

// 数组 map
// 三个参数和for Each意义一样
// 回返回对数组的操作，但是不会改变数组
console.clear();

var arr = [1, 2, 3, 4];
var mappedArr = arr.map(ele => ele * 2);
console.log(mappedArr);
console.log(arr);

// 数组 reduce
// 四个参数（需要查一下）
// reduce 是对数组的操作结果
console.clear();

var arr = [1, 2, 3, 4, 5];
// 对数组进行求和操作
// previous表示前一个操作后的数值， current表示当前索引到的数值,(这是回调函数的内容)
// 第二个参数表述一个初始值，表示前一个的值为0， 即previous = 0；
var result = arr.reduce((previous, current) => previous + current, 0);
console.log(result);
// 如果没有第二个参数表示, 将数组的第一个元素和第二个元素相加作为previous，然后后从第三个值开始作为current进行操作
var result = arr.reduce((first, second) => first + second);
console.log(result);

// 数组过滤
console.clear();
// filter接收一个回调函数,后面的参数和for Each相同
// 回调函数要返回boolean类型
var arr = [1, 2, 3, 4, 5, 6];

var filteredArray = arr.filter(item => item > 4);
console.log(filteredArray);

// 数组测试
console.clear();
// 检测所有数组
// every可以所接受的参数含for Each一样
// 下面表示的意义是是否数组中的元素都大于0
var arr = [1, 2, 3, 4, 5, 6];
var result = arr.every(item => item > 0);
console.log(result)

// 检测数组中是否有一个或一个以上的元素值大于5
var resultSome = arr.some(item => item > 5);
console.log(resultSome)

// destructuring 结构操作符
// 是将数组的元素赋值给变量
console.clear();

var arr = [1, 2, 3];
// a, b, c 要于想获取的数值的位置相对应
var [a, b, c] = arr;
console.log(a, b, c);

var [d, e] = arr;
console.log(d, e);

var [, f] = arr;
console.log(f);

function multipleReturns() {
    let name = "ok";
    let position = "123";

    return [name, position];
}
// 进行结构
var [myName, myPosition] = multipleReturns();
console.log(myName, myPosition);

// rest 操作符
console.clear();

var arr = [1, 2, 3, 4, 5, 6, 7, 8];
var [a, b, ...rest] = arr;
console.log(a, b, rest);

// 2这个值每个空位, rest在这里只是一个名字 rest操作符是...变量名
var [a, , b, ...rest] = arr;
console.log(a, b, rest);

// 函数中可以作为参数用于接受不固定的参数
function variousArgs(...args) {
    console.log(args);
}

variousArgs(1, 2, 3, 4, 5);

/*
// 多为数组
console.clear();

var arr = [];
for (let i = 0; i < 5; i++) {
    arr[i] = [];
    for (let j = 0; i < 4; j++) {
        arr[i][j] = i + j;
    }
}
console.log(arr);
*/

// 创建对象
console.clear();

// 创建方法1 冒号后面要打空格
var employee = {
    name: "张三",
    age: 20,
    position: "前端",
    signIn: function() {
        console.log("张三打卡");
    }
};

//创建方法2
var employee2 = new Object();
employee2.name = "李四";
employee2.sigIn = function() {
    console.log("李四打卡");
}

// 对象属性

console.log(employee.name);
console.log(employee["name"]);
//对成员进行更新
employee.name = "张五";
console.log(employee.name);

employee["name"] = "张六";
console.log(employee.name);

console.log(employee2.age);


employee2.age = 22;
console.log(employee2.age);


// 如果在给对象命名的时候有“-”，要用双引号给引起来
// 在后面引用的时候只能用[]来进行索引.
// 不建议这么写
var employee3 = {
    name: "王五",
    "birth-date": "2017-03"
};

console.log(employee3["birth-date"]);

// 省略key
// 如果在对象外面已经声明了相同名字的就可以在对象里面省略了
console.clear();

var name = "李四";

var employee4 = {
    name,
    sigIn() {
        console.log("李四打卡");
    }
};


