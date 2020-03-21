package Ex14.clock;

// 一个类是由两个类来组成的

public class Clock {
    private Display hours = new Display(24); 
    private Display minutes = new Display(60); 

    // 将两个对象进行互动
    public void start() {
        minutes.increase();

        if (minutes.getValue() == 0) {
            hours.increase();
        }

        System.out.printf("%02d:%02d\n", hours.getValue(), minutes.getValue()); // 0表示如果有空位用0来填冲2表示占两个字符
    }
    public static void main(String[] args) {
        Clock clock = new Clock();
        clock.start();
    }
}