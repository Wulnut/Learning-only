package Ex14.clock;

// Display 表示一个小部件，用来交互两个时间，并控制最后的输出

public class Display {


    // private表示私有的,只能用于成员变量和成员函数
    // private 的成员变量只能在在类里面被访问
    private int value = 0; // 当前的值
    private int limit = 0; // 时钟需要反转的上线

    public Display(int limit) {
        this.limit = limit;
    }

    public void increase() {
        value ++;

        if (value == limit) {
            value = 0;
        }
    }

    public int getValue() {
        return value;
    }

}




