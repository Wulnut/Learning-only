document.writeln("hello world");

// throw new Error表示的是扔出报错， 目的是为了防止出现传出参数错误

// 类之间的类型比较实用instanceof 不同类型之间的比较实用typeof
function handleMessage(message, handle) {
    if (typeof handle == "function") {
        return handle(message);
    } else {
        throw new Error("the 2nd argument should be a function");
    }
}

var variable = "out";

function func() {
    let variable = "in";
    console.log(variable);
}

func();
console.log(variable);

var object = {
    field : "self",
    printInfo : function() {
        console.log(this.field);
    }
}

for (let key in object) {
    console.log(key + ":" + object[key]);
}

console.clear();

// 声明对象方法一(但是更像是声明字典)
var object1 = {
    field : "self",
    printInfo : function () {
        console.log(this.field);
    },
    outter : {
        inner : "inner text",
        printInnerText : function () {
            console.log(this.inner);
        }
    }
};

for (let key in object1) {
    console.log(key + ":" + object1[key]);
}

console.clear();

// .运算符的特殊情况（不建议这样写）
var ref = {
    id : "referencel",
    func : function() {
        return this.id;
    }
};

var obj = {
    id : "object1",
    "self.ref" : ref
};

obj["self.ref"].func();

console.clear();

// 声明方式为对象的方法二
function Base(name) {
    this.name = name;
    this.getName = function () {
        return this.name;
    }
}

function Child(id) {
    this.id = id;
    this.getId = function () {
        return this.id;
    }
}

Child.prototype = new Base("base");

var c1 = new Child("child");

console.log(c1.getId());
console.log(c1.getName());

console.clear();

// 声明对象的方法三
var base = new Object();

base.name = "hello";
base.id = 12;

for (let key in base) {
    console.log(key);
}

console.clear();

/*
类用function的方式来写可以省去写构造函数的时间，比较方便
 */

// 构造一个类
function Address(street, xno) {
    this.street = street || 'Huang Quan Road';
    this.xno    = xno    || 123;
    this.toString = function () {
        return "street: " + this.street + ", No: " + this.xno;
    }
}

function Persion(name, age, addr) {
    this.name    = name || 'unknow';
    this.addr    = addr || new Address(null, null);
    this.age      = age;
    this.getNmae = function () {return this.name}
    this.getAge  = function () {return this.age}
    this.getAddr = function () {return this.addr.toString()}
}

var jack    = new Persion('jack', 26, new Address('Qing Hai Road', 124));
var abruzzi = new Persion('abruzzi', 26);

console.log(jack.getNmae());
console.log(jack.getAge());
console.log(jack.getAddr());

console.log('\n');

console.log(abruzzi.getNmae());
console.log(abruzzi.getAddr());
console.log(abruzzi.getAge());

console.clear();

// json = javascript object notation
// 这是一种对象的声明方式就是json
var test = {
    name : "abruzzi",
    age  : 26,
    birthday : new Date(1983, 4, 5),
    addr : {
        street : "Huang Quan Road",
        xno    : "135"
    }
}
console.clear();

// 对象的特殊用法
function point(left, top) {
    this.left = left;
    this.top  = top;
    return {x: this.left, y: this.top};
}

var pos = point(3, 4);
// pos.x
// pos.y



