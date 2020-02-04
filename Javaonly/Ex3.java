/*
* 在for循环中且只能用于for循环中使用**逗号操作符**
*可以使代码更简洁
*
*/

import java.util.*;
public class Ex3 {
    public static void main(String[] args) {
        for (int i = 1, j = i + 10; i < 5; i++, j = i * 2) {
            System.out.println("i = " + i + " j = " + j);
        }
    }
}