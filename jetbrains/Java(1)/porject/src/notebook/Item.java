package notebook;

/**
 * 父类中用private修饰的变量于函数只能在父类
 * 使用protected则既可以在父类中用也可以在子类中用
 * */
public class Item {
    protected String title;

    public Item(String title) {
        this.title = title;
    }

    public void print() {
        System.out.println("item");
    }
}
