import java.io.*;

public class Hello {
    public static void main(String[] args) {
        System.out.println("hello world");
        int[] buf = new int[10];

        for (int i = 0; i < buf.length; ++ i) {
            buf[i] = (int)i;
        }

        try {
            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(
                            new FileOutputStream("note.txt")
                    )
            );
            int i = 0xcafebabe;
            out.write(int);
            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
