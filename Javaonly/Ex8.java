// 使用了top中的lib

import static top.wulnut.util.Range.*;

public class Ex8 {
    public static void main(String[] args) {
        int[] arr;
        int j = 10;
        int i = 5;
        //int a = 0;
        arr = range(i);
        for (int a = 0; a < arr.length; a++) {
            System.out.println(arr[a]);
        }
        
        System.out.println();
        i =5;
        arr = range(i, j);
        for (int a = 0; a < arr.length; a++) {
            System.out.println(arr[a]);
        }

        System.out.println();
        int step =2;
        arr = range(i, j, step);
        for (int a = 0; a < arr.length; a++) {
            System.out.println(arr[a]);
        }
        
    }
}