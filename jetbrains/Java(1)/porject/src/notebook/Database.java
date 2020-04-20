package notebook;

import java.util.ArrayList;

public class Database {
//    private ArrayList<CD> listCD = new ArrayList<CD>();
//    private ArrayList<DVD> listDVD = new ArrayList<DVD>();
    private  ArrayList<Item> listItem = new ArrayList<Item>();

//    public void add (DVD dvd) {
//        listDVD.add(dvd);
//    }
//    public void add (CD cd) {
//        listCD.add(cd);
//    }
    public void add (Item item) {
        listItem.add(item);
    }

//    public void list() {
//        for (CD cd : listCD) {
//            cd.print();
//        }
//
//        for (DVD dvd : listDVD) {
//            dvd.print();
//        }
//    }

    public void list() {
        for (Item item : listItem) {
            item.print();
        }
    }

    public static void main(String[] args) {
        Database db = new Database();
        db.add(new CD("abc","abc",4,60,"..."));
        db.add(new DVD("xxx","aaa",60,"..."));
        db.list();
    }

}
