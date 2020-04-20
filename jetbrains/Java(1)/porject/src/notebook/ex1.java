package notebook;

import java.util.HashSet;
/**
 * HashSet是一种集合，这里的集合的意思和数学中的集合类似，一个集合里面不存在两个相同的东西
 * HashSet是不排序的，
 * 如果再java中实现了一个 public String toString(){" " + value} 这样的一个函数
 * java在输出一个类的时候就会自动的调用这个函数,这也就是为什么我们也可以直接输出一个容器里面的对象并得到一个字符串
 * */

public class ex1 {
    public static void main(String[] args) {
        HashSet<String> s = new HashSet<String>();
        s.add("first");
        s.add("second");
        s.add("first");

//        for (String k : s) {
//            System.out.println(k);
//        } // set遍历方法

        System.out.println(s);
    }
}
