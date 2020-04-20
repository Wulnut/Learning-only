package notebook;

import java.util.HashMap;
import java.util.Scanner;
/**
 * 在HashMap中和HashSet类似都是如果遇见相同的value那么HashMap只会从中存入最后一个存入的value
 * */

public class Hash {
    private HashMap<Integer, String> coinnames = new HashMap<Integer, String>();

    public Hash() {
        coinnames.put(1, "penny");
        coinnames.put(10, "dime");
        coinnames.put(25, "quarter");
        coinnames.put(50, "half-dolar");

        // HashMap遍历输出的方法，只有这一种
        for (Integer k : coinnames.keySet()) {
            String s = coinnames.get(k);
            System.out.println(s);
        }
    }

    public String getName(int amount) {

        if (coinnames.containsKey(amount))
            return coinnames.get(amount);
        else
            return "NOT FOUND";

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int amount = in.nextInt();
        Hash coin = new Hash();
        String name = coin.getName(amount);
        System.out.println(name);
    }
}
