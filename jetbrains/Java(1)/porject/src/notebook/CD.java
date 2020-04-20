package notebook;

public class CD extends Item{
    //private String title;
    private String artist;
    private int numofTracks;
    private boolean gotIt = false;
    private String comment;

    public CD(String title, String artist, int tracks, int numofTracks, String comment) {
        this.title = title;
        this.artist = artist;
        this.numofTracks = numofTracks;
        this.comment = comment;
    }

//    public void print() {
//        System.out.println("CD" + ":" + title + ":" + artist);
//    }
    public static void main(String[] args) {
        CD cd = new CD("CD" , "a" , 2 , 2 , "...");
        cd.print();
    }
}
