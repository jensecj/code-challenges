import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class test {

    static class Runner {
        String name;
        double first;
        double other;

        public Runner(String name, double first, double other) {
            this.name = name;
            this.first = first;
            this.other = other;
        }
    }

    static class Solution {
        double score;
        Runner first;
        Runner second;
        Runner third;
        Runner forth;

        public Solution(Runner first, Runner second, Runner third, Runner forth) {
            score = first.first + second.other + third.other + forth.other;
            this.first = first;
            this.second = second;
            this.third = third;
            this.forth = forth;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = readInt(reader);

        List<Runner> runners = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            String[] line = reader.readLine().split(" ");

            runners.add(new Runner(
                                   line[0],
                                   Double.parseDouble(line[1]),
                                   Double.parseDouble(line[2])
                                   ));
        }

        Collections.sort(runners, new Comparator<Runner>() {
                @Override
                public int compare(Runner runner, Runner t1) {
                    return Double.compare(runner.other, t1.other);
                }
            });

        Solution best = null;
        for(int i = 0; i < n; i++) {
            Runner first = runners.get(i);

            Runner second = runners.get(0);
            Runner third = runners.get(1);
            Runner forth = runners.get(2);

            if(i == 0) {
                second = runners.get(3);
            }
            if(i == 1) {
                third = runners.get(3);
            }
            if(i == 2) {
                forth = runners.get(3);
            }

            Solution solution = new Solution(first, second, third, forth);

            if(best == null || best.score > solution.score) {
                best = solution;
            }

        }

        // System.out.println(runners.stream().map(r -> r.name).collect(Collectors.joining()));

        /*
          6
          ASH 9.9 8.85
          BL 9.69 8.72
          BO 9.58 8.43
          CA 9.78 8.93
          FR 9.88 8.92
          PO 9.72 8.61
        */

        System.out.println(best.score);
        System.out.println(best.first.name);
        System.out.println(best.second.name);
        System.out.println(best.third.name);
        System.out.println(best.forth.name);
    }

    private static int readInt(BufferedReader reader) throws IOException {
        return Integer.parseInt(reader.readLine());
    }

    private static double readDouble(BufferedReader reader) throws IOException {
        return Double.parseDouble(reader.readLine());
    }
}
