import java.util.*;

public class Ex6 {

    public enum Spiciness {
        NOT, MILD, MEDUUM, HOT, FLAMING
    }

    public static void main(String[] args) {
        for (Spiciness s : Spiciness.values()) {
            System.out.println(s + ".ordonal " + s.ordinal());
        }
    }
}