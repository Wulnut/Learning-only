/*
** 编写package的时候要注意，top是对应一个文件夹，wulnut对应一个文件夹，util对用一个文件夹
这样才算是一个完整的路径。而这个top文件夹内不能用引用该package的java文件。
Java的lib中的方法是通过多个文件加的方式，来防止冲突。
*/
//top/wulnut/util/Print.java
package top.wulnut.util;

//import java.util.*;
import java.io.*;

public class Print {
    public static void print(Object obj) {
        System.out.println(obj);
    }

    public static void print() {
        System.out.println();
    }

    public static void printb(Object obj) {
        System.out.print(obj);
    }

    public static PrintStream
    printf(String format, Object... args) {
        return System.out.printf(format, args);
    }
}