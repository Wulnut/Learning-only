import java.util.*;

// 不能直接比较浮点数之间的是否相等，讲两者相减，得到小于1e-6可以认为两者相等

/*
   关于boolean
  在Java中boolean只有两个值 true and false
 
*/

public class Ex9 {
    public static void main(String[] args) {
        /*
        double a = 1.0;

        double b = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

        System.out.println(Math.abs(a - b) < 1e-6); // 判断连个浮点数的方法

        Scanner in = new Scanner(System.in); // in 初始化

        int amount = in.nextInt();

        if (amount >= 10) {
            System.out.println("ok");
        }

        in.close(); // in 关闭*

        */

        /*
        Scanner in  = new Scanner(System.in);

        int tpye = in.nextInt();

        switch(tpye) {
            case 1:
                System.out.println("ok");
                break;
            case 2:
                System.out.println("hello");
                break;
            case 3:
                System.out.println("nb");
                break;
            case 4:
                System.out.println("great");
                break;
            default: 
                System.out.println("...");
                break;
        }

        in.close();

        */

        Scanner in = new Scanner(System.in);

        in.close();
    }
}









