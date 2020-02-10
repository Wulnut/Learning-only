import java.util.*;

public class Ex4 {
	public static void main(String[] args) {
		int a [];

		Random rand = new Random(47);
		a = new int [rand.nextInt(20)];

		System.out.println("length of a =" + a.length);
		System.out.println(Arrays.toString(a));//Arrays.toString()是将数组转换成字符串的形式；
	}
}