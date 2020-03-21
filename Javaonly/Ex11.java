import java.util.Scanner;

public class Ex11 {
    //public static void main(String[] args) {

        /* 两种二维数组的初始化方式
        int[][] a = new [3][5];

        int[][] a = {
            {1, 2, 3, 4},
            {1, 2, 3}
        };
        */

        /*
        // 实现＃字棋
        Scanner in = new Scanner(System.in);
        final int SIZE = 3;
        int[][] board = new int[SIZE][SIZE];
        boolean gotResult = false;
        int numOFx = 0;
        int numOFy = 0;

        // 读入矩阵
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                
                board[i][j] = in.nextInt();
            }
        }

        in.close();

        // 先检查行

        // 检查列

        // 检查对角线

        if (!gotResult) {
            numOFx = 0;
            numOFy = 0;

            for (int i = 0; i < SIZE; i ++) {

                if (board[i][SIZE - i - 1] == 1) {
                    numOFx++;
                }
                else {
                    numOFy++;
                }
            }

            if (numOFx == SIZE || numOFy == SIZE) {
                gotResult = true;
            }
        }
     
        */

        // 字符类型
    //public static void main(String[] args) {
        /*
        Scanner in  = new Scanner(System.in);
        in.close();
        char c = 'A';
        char d = 'D';
        char a = '\u0041'; // A
        char e = 65; // A

        System.out.println(e);
        */
    //}

    // 包裹类型

        /*
    public static void main(String[] args) {
        // Integer int的大类 可以表示高精度类
        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.toString(123));
        // Character
        System.out.println(Character.isDigit('1'));// isDigit可以判断是否为数字(仅限阿拉伯数字)

        System.out.println(Character.isLowerCase('I')); // isLowerCase可以判断是否为小写

        System.out.println((Character.toLowerCase('I'))); // isLowerCase可以做大转变为小写转换
    }
    */

   // public static void main(String[] args) {
        /**
         * String s
         * String 是一个类，String的变量是对象的管理者而非所有者
         * 就像数组变量一样
         */

         //String s = new String("a string"); // 用String类来创建一个字符串的类，并交给s管理

         /**
          *  用➕号可以连接两个字符串 "hello" + "world" -> "HelloWorld"
          *  当这个+的一边是字符串而另一边不是时，会将另一边表达为字符串然后做连接
          *  "I'm" + 18 -> "I'm 18"
          * 1 + 2 + "age" -> "3age"
          * "age" + 1 + 2 -> "age3"
          */

        /*
          Scanner in = new Scanner(System.in);
          String s;
          //s = in.next(); // next只读取到空格就结束了，空格为由 space tab 回车
          s = in.nextLine(); // nextLine表示为 读取一行到回车截至
          System.out.println(s + " world");
        */

        /*
        Scanner in = new Scanner(System.in);
        String s = in.next();
        in.close();
        System.out.println(s);
        System.out.println(s == "bye"); // 普通的 == 表示为两个是否为同一个字符串（即是否管理同一个字符串），不会比较内容
        System.out.println(s.equals("bye")); // equals() 比较两个字符串的内容是否相等
        */

        // String比较大小（根据编码进行比较）

        /**
         * s1.compareTo(s2)
         * 如果s1比s2小，那么结果是负的，如果s1和s2相等，那么结果是0，如果s1比s2大那么结果是正的
         * compareToIgnoreCase可以不区分大小写来比较大小
         */
        /*
         String s1 = "abc";
         String s2 = "abb";
         System.out.println(s1.compareTo(s2));
         System.out.println("abcd".compareTo("abcd")); //可以直接为一个常量

         String name = "hellokugou";
         System.out.println(name.length()); // 测量长度

         // chartAt(index) 用来访问字符串
         // 返回在index上的单个字符
         // index的范围是0到length()-1
         // 不能使用for-each循环来遍历数组
         //注意不会检查边界

         System.out.println(s1.charAt(2));

         for (int i = 0; i < s1.length(); i++){
             System.out.println(s1.charAt(i)); // 对字符串进行遍历
         }

         // s.substring(n) 得到从n号位置末尾的全部内容
         // s.substring(b,e) 得到从b号位置到e号位置之前的内容
         */

   // }

   // Math
   // abs pow random round(四舍五入)
   /*
   public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       System.out.println(Math.abs(-12));
       System.out.println(Math.round(10.1234));
       System.out.println(Math.random()*100);
       System.out.println(Math.pow(10,2));
   }
   */

   // 函数

   public static boolean isPrime(int i) {
       boolean isPrime = true;

       for (int k = 2; k < i; k++) {
           if (i % k == 0) {
               isPrime = false;
               break;
           }
       }

       return isPrime;
   }
   public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int m = in.nextInt();
    int n = in.nextInt();
    in.close();

    if (m == 1) m = 2;
    int cnt = 0;
    int sum = 0;
    
    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            cnt ++;
            sum += i;
        }
    }

    System.out.println("在" + m + "和" + n + "之间有" + cnt + "个素数，总和为" + sum);
   }
}