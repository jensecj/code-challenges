import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class G {

    private static ArrayList<Entry> entries;
    private static Entry first;

    static class Entry {
        int penalty;
        int solved;

        Entry back;
        Entry front;

        public Entry(Entry back, Entry front) {
            this.back = back;
            this.front = front;
        }

        public Entry() {
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String[] input = reader.readLine().split(" ");

        int teams = Integer.parseInt(input[0]);
        int events = Integer.parseInt(input[1]);

        entries = new ArrayList<>();
        for(int i = 0; i < teams; i++) {
            entries.add(new Entry());
        }

        for(int i = 1; i < teams; i++) {
            entries.get(i).front = entries.get(i - 1);
        }

        for(int i = 0; i < teams - 1; i++) {
            entries.get(i).back = entries.get(i + 1);
        }

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int place = 1;

        first = entries.get(0);

        for(int i = 0; i < events; i++) {

            String[] lol = reader.readLine().split(" ");
            int team = Integer.parseInt(lol[0]);
            int pen = Integer.parseInt(lol[1]);

            Entry eventTeam = entries.get(team - 1);

            eventTeam.solved++;
            eventTeam.penalty = eventTeam.penalty + pen;


            if(eventTeam.front == null) {
                writer.write(Integer.toString(place) + System.lineSeparator());
                continue;
            }
            disconnect(eventTeam);

            int overtakings = 0;
            boolean overtook1 = false;

            while(true) {

                if(compare(eventTeam, eventTeam.front)) {
                    if(eventTeam.front == first) {
                       // System.out.println("Overtook 1");
                        overtook1 = true;
                    }

                    overtakings++;

                    // Further up
                    if(eventTeam.front.front == null) {
                        eventTeam.back = eventTeam.front;
                        eventTeam.front.front = eventTeam;
                        eventTeam.front = null;
                        break;
                    } else {
                        eventTeam.front  = eventTeam.front.front;

                    }

                } else {
                    //System.out.println("Found stop");
                    // This is it?
                    eventTeam.back = eventTeam.front.back;

                    eventTeam.front.back.front = eventTeam;

                    break;
                }
            }

            if(eventTeam == first) {
                place -= overtakings;
                writer.write(Integer.toString(place) + System.lineSeparator());
            } else {
                if(overtook1) {
                    place++;
                }
                writer.write(Integer.toString(place) + System.lineSeparator());
            }
        }

        writer.flush();
    }


    private static boolean compare(Entry a, Entry b) {
        if(a.solved > b.solved) {
            return true;
        } else if(a.solved == b.solved) {
            return a.penalty < b.penalty;
        } else {
            return false;
        }
    }



    private static void disconnect(Entry eventTeam) {
        eventTeam.front.back = eventTeam.back;

        if(eventTeam.back != null) {

            eventTeam.back.front = eventTeam.front;
        }

    }
}
