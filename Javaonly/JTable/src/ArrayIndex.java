// 异常

import java.util.Scanner;

public class ArrayIndex {

    public static void fun() {
        int [] a = new int[10];
        a[10] = 10;
        System.out.println("hello");
    }

    public static void main(String[] args) {
//        int [] a = new int[10];
//        int idx;
//
//        Scanner in = new Scanner(System.in);
//        idx = in.nextInt();
//
//        // 异常
//        try {
//            // 把可能出现的异常放在try里面
//            a[idx] = 10;
//            System.out.println("hello");
//        }
//        catch (ArrayIndexOutOfBoundsException e) {
//            System.out.println("Caught");
//        } // 后面可有多个异常
//
        try {
            fun();
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("caught1");
            System.out.println(e.getMessage());
            System.out.println(e);
            e.printStackTrace();// 查看异常调用轨迹
        }

        System.out.println("main");
    }

}
