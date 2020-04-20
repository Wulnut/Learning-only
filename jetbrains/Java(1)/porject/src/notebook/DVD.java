package notebook;

/**
 * extends 扩展
 * 如果加入了extends就成为了item的子类
 * */

public class DVD extends Item{
    private String title;
    private String director;
    private int playingTime;
    private boolean gotIt = false;
    private String comment;

    public DVD(String title, String director, int playingTime, String comment) {
        this.title = title;
        this.director = director;
        this.playingTime = playingTime;
        this.comment = comment;
    }

    public void print() {
        System.out.println("DVD" + ":" + title + ":" + director);
    }
}
