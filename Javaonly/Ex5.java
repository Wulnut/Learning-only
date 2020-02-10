import java.util.*;

public class Ex5 {
    static void printArray(Object... args) {//可变参数列表
        for (Object obj : args) {
            System.out.print(obj + " ");
        }

        System.out.println();
    }

    public static void main(String[] args) {
        
        printArray(47, 3.14F, 11.11);
        printArray("one", "two", "three");
        printArray((Object[]) new Integer[] {1, 2, 3});
    }
}