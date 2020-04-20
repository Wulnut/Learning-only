package notebook;

import java.util.ArrayList;

public class NoteBook {
    // ArrayList<> 是一个容器
    // notes 是一个对象管理者
    private ArrayList<String> notes = new ArrayList<String>(); // 用来存输入进来的数据

    public void add(String s){
        notes.add(s);
    }

    public int getSize() {
        return notes.size();
    }

    public void add(String s, int location) {
        notes.add(location, s);
    }

    public String getNote(int index) {
        return notes.get(index); // 通过索引，查看数据
    }

    public void removeNote(int index) {
         notes.remove(index);
    }

    public String[] list() {
        String[] a = new String[notes.size()];
        notes.toArray(a);
        return a;
    }

    public static void main(String[] args) {

        NoteBook nb = new NoteBook();

        nb.add("first");
        nb.add("second");
        nb.add("third", 1);

        System.out.println(nb.getSize());
        System.out.println(nb.getNote(0));
        System.out.println(nb.getNote(1));

        nb.removeNote(1);
        String[] a = nb.list();

        System.out.println();
        for (String s : a) {
            System.out.println(s);
        }
    }
}
