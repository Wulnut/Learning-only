package Ex13;
// 写一个类

public class VendorMachine {
    // this变量（Java中）
    // this指针（c++中用处差不多但是是指针）
    /**
     * 成员变量和函数只能在类里面用要与本地变量相区别
     * java在类中会自动给一个0作为初始值
     * Java在对于本地变量中一定要赋值，不然编译无法通过
     * 定义成员变量的时候是可以给其初始化的， 还可以用函数给其赋值
     */
    int price;
    int balance;
    int total = f(); // 是可以这样操作的

    int f() {
       return this.total = 10;
    }

    // 构造函数
    /**
     * 如果由一个成员函数的名字和类的名字完全相同，则在创建这个类的每个对象的时候会自动调用这个函数 -> 构造函数
     * 构造函数可以由参数，如果new的时候有参数，会用有参数的构造函数，如果没有参数就会去用没有参数的构造函数
     * 这个函数不能由返回类型
     */
    VendorMachine() {
        total = 0;
        balance = 1;
        price = 2;
    }
    // 亦是构造函数，这个函数也是构造函数
    VendorMachine(int price) {
        this.price = price;
    }

    void showPrompt() {
        System.out.println("Welcome");
    }

    void insertMoney(int amount) {
        balance += amount;
    }

    void showBalance() {
        System.out.println(this.balance);
        System.out.println(balance); // this.balance == balance 在这里两个是一样的
    }

    void getFood() {
        if (balance >= price) {
            System.out.println("Here you are");
            balance = balance - price;
            total += price;
        }
    }

    void setPrice(int price) {
        this.price = price; // 表示给本地price进行赋值（前提是price月成员变量名称相同时候）
        showBalance();
        this.showBalance(); // 上下两种操作是一样的
    }

    public static void main(String[] args) {
        VendorMachine vm = new VendorMachine();
        VendorMachine vm1 = new VendorMachine();
        vm.showPrompt();
    }
}
