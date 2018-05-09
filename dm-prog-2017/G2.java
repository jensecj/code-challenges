import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.TreeSet;

public class G2 {

    private static ArrayList<Entry> entries;
    private static Entry first;

    static class Entry implements Comparable<Entry>{
        int penalty;
        int solved;


        @Override
        public int compareTo(Entry entry) {
            if(solved > entry.solved) {
                return 1;
            } else if(solved == entry.solved) {
                if(penalty < entry.penalty) {
                    return 1;
                } else if(penalty == entry.penalty) {
                    return 0;
                } else {
                    return -1;
                }
            } else {
                return -1;
            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String[] input = reader.readLine().split(" ");

        int teams = Integer.parseInt(input[0]);
        int events = Integer.parseInt(input[1]);

        TreeSet<Entry> above = new TreeSet<Entry>();
        TreeSet<Entry> below = new TreeSet<Entry>();

        entries = new ArrayList<>();
        for(int i = 0; i < teams; i++) {
            entries.add(new Entry());
        }

        for(int i = 1; i < teams; i++) {
            below.add(entries.get(i));
        }

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int place = 1;

        first = entries.get(0);

        for(int i = 0; i < events; i++) {

            String[] lol = reader.readLine().split(" ");
            int team = Integer.parseInt(lol[0]);
            int pen = Integer.parseInt(lol[1]);

            Entry entry = entries.get(team - 1);

            entry.solved++;
            entry.penalty += pen;

            if(entry == first) {
                Set<Entry> headSet = above.headSet(entry, false);
                below.addAll(headSet);
                above.removeAll(headSet);

                place -= headSet.size();

                writer.write(Integer.toString(place) + System.lineSeparator());
            } else {
                if(entry.compareTo(first) > 0) {
                    below.remove(entry);
                    above.add(entry);
                    place++;
                    writer.write(Integer.toString(place) + System.lineSeparator());
                } else {
                    above.remove(entry);
                    below.add(entry);
                    place--;
                    writer.write(Integer.toString(place) + System.lineSeparator());
                }
            }

        }

        writer.flush();
    }
}
