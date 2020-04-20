package castle;

import java.util.HashMap;
import java.lang.StringBuffer;

public class Room {
    private String description;
    private HashMap<String, Room> exits = new HashMap<String, Room>();
//    private Room northExit;
//    private Room southExit;
//    private Room eastExit;
//    private Room westExit;

    public Room(String description) 
    {
        this.description = description;
    }

    public void setExits(String dir, Room room) {
        exits.put(dir, room);
    }

//    public void setExits(Room north, Room east, Room south, Room west)
//    {
//        if(north != null)
//            northExit = north;
//        if(east != null)
//            eastExit = east;
//        if(south != null)
//            southExit = south;
//        if(west != null)
//            westExit = west;
//    }

    public String getDescription() {

        // String 做加法系统开销很大 string是一个不可修改的一种类型，如果我们想去做＋系统就会去再给我们new一个
        // String类型，多个String类型的系统开销就会很大
        // 注意区别StringBuffer 和 StringBuild
        // 需要对字符串进行复杂操作时候就可以用StringBuffer

        StringBuffer sb = new StringBuffer();

        for (String dir : exits.keySet()) {
            sb.append(dir);
            sb.append(' ');
        }

//        if(northExit != null)
//            sb.append("north");
//        if(eastExit != null)
//            sb.append("east");
//        if(southExit != null)
//            sb.append("south");
//        if(westExit != null)
//            sb.append("west");

        return sb.toString();
    }

    public Room getExit(String description) {
        Room ret = null;
        ret = exits.get(description);

//        if(description.equals("north")) {
//            ret = this.northExit;
//        }
//        if(description.equals("east")) {
//            ret = this.eastExit;
//        }
//        if(description.equals("south")) {
//            ret = this.southExit;
//        }
//        if(description.equals("west")) {
//            ret = this.westExit;
//        }

        return ret;
    }

    @Override
    public String toString()
    {
        return description;
    }
}
