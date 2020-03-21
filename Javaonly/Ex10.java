
//import java.util.Scanner;

public class Ex10 {

    // 计算 1-1/2+1/3-1/4...+1/n;
    /*
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        double sum = 0.0;
        int sign = 1;

        for (int i = 1; i <= n ; i++, sign = -sign) {
            sum += sign * 1.0 / i;
        }
        
        System.out.println(sum);

        System.out.printf("%.2f", sum);

        in.close();
    }
    */

    /*
    // 计算两个数的最大公约数
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int gcd = 1;
    */

        // 方法一、枚举
        /*
        for (int i = 2; i <= a && i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                gcd = i;
            }
        }
        System.out.println(a + "和" + b + "的最大公约数是" + gcd);
        */

        // 方法而辗转相除法
        /**
         * 1.如果b等于0，计算结束，a就是最大公约数；
         * 2.否则，计算a除以b的余数，让a等于b，而b等于那个余数
         * 3.回到第一步
         */
    /*
        int oa = a;
        int ob = b;

        while (b != 0) {
            int r = a % b;
            System.out.println(a + ", " + b + "," + r);
            a = b;
            b = r;
        }
        
        System.out.println(oa + "和" + ob + "的最大公约数是" + a);

        
        in.close();
    }
    */


    
    // 数组
    //public static void main(String[] args) {
        /**     目的
         * 1.如何写一个程序计算哟弄个胡输入的数字的平均数，并输出所有大于平均数的数
         * 2.必须先记录每一个输入的数字，计算平均数之后，再检查记录下来的每一个数字，与平均数比较，决定是否输出
         */

        
        /**
         * 下面的这种动态创建相对比较安全
         */
        /*
        Scanner in = new Scanner(System.in);
        double sum = 0;
        int cnt = 0;// 统计一共输入了多少个数字

        cnt = in.nextInt();

        if (cnt > 0) {

            int[] numbers = new int[cnt]; //数组

            for (int i = 0; i < cnt; i++){

                    numbers[i] = in.nextInt();
                    sum += numbers[i];
            }  

            double avaerage = sum / cnt;

            // 输出大于平局数的成员
            // numbers.length 表示遍历整个数组
                    for (int i = 0; i < numbers.length; i++) {
                        if (numbers[i] > avaerage) {

                            System.out.println(numbers[i]);
                        }
                    }

                    // 输出平均值
                    System.out.println(sum/cnt);
        }
        in.close();
    }
    */

    // 数组变量
    /**
     * 1.数组变量是数组的管理者而非数组本身
     * 2.数组必须创建出来然后交给数组变量来管理
     * 3.数组变量之间的赋值时管理权限的赋予
     * 4.数组变量之间的比较是判断是否管理同一个数组
     * 
     */
    /*
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int [] a = new int[10];

        a[0] = 5;
        
        int[] b = a;
        System.out.println(a[0]);

        b[0] = 16;

        System.out.println(b[0]);
        System.out.println(a[0]);

        */

        /**
         * int[] a = new int[10];中后面那个10个内存并不是赋给了a，a相当于那块内存的管理者
         * 而普通的变量是是内存的拥有者，所以普通变量是可以相互赋值。
         * 当 int[] b = a; 时责表示b管理a的那块内存则a,b两个都取管理了同一块内存;
         */

         /*
        int[] c = {1,2,3,4,5,6,7};
        int[] d = c;

        System.out.println(c == d);

        int[] e = {1,2,3,4,5,6,7};
        int[] f = {1,2,3,4,5,6};

        System.out.println(e == f);


        // 复制数组只能使用遍历的方式复制给另一个数组

        int[] g = {1,2,3,4,5,6};
        int[] h = new int[g.length];

        for (int i = 0; i < h.length; i++) {
            h[i] = g[i];
        }

        in.close();
    }
    */

    
}