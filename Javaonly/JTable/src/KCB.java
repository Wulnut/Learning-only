// MVC
// model view control

import javax.swing.*;

public class KCB {
    public static void main(String[] args) {
        // JFrame 用来实现画面
        JFrame frame = new JFrame();
        JTable table = new JTable(new KCBdata());
        // JScrollPane 用来画
        JScrollPane pane = new JScrollPane(table);

        frame.add(pane);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

    }
}
