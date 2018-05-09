import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class E {

    private static int h;
    private static int w;

    static class node implements Comparable<node>{
        public int largest_seen;
        public int value;
        public int x, y;
        public boolean seen;

        public node(int largest_seen, int value, int x, int y) {
            this.largest_seen = largest_seen;
            this.value = value;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(node node) {
            return value-node.value;
        }
    }

    static node[][] map;
    static PriorityQueue<node> q = new PriorityQueue<node>();

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String[] input = reader.readLine().split(" ");
        h = Integer.parseInt(input[0]);
        w = Integer.parseInt(input[1]);

        map = new node[h][w];


        for(int j = 0; j < h; j++) {
            input = reader.readLine().split(" ");
            for (int i = 0; i < w; i++) {
                map[j][i] = new node(-10000000,Integer.parseInt(input[i]),j,i);
            }
        }
        input = reader.readLine().split(" ");
        int i = Integer.parseInt(input[0]);
        int j = Integer.parseInt(input[1]);
        DFS(i,j);

    }

    private static void DFS(int starti, int startj) {

        q.add(map[starti-1][startj-1]);
        long drained = 0;
        while(!q.isEmpty()) {
            node curr = q.remove();
            if(curr.seen || curr.value >= 0) continue;
            //System.out.println("looking at " + curr.x + " " + curr.y);
            curr.seen = true;
            if(curr.largest_seen > curr.value)
                drained += - curr.largest_seen;
            else
                drained += - curr.value;

            ArrayList<node> neigh = neigh(curr.x, curr.y);
            for(node n : neigh) {
                if(!n.seen && n.value < 0) {
                    n.largest_seen = Math.max(curr.largest_seen, curr.value);
                    q.add(n);
                }
            }
        }
        System.out.println(drained);
    }

    private static ArrayList<node> neigh(int x, int y) {
        //System.out.println("neigh: " + x + " " + y);
        ArrayList<node> res = new ArrayList<>();
        if(x > 0 && y > 0) res.add(map[x-1][y-1]);
        if(         y > 0) res.add(map[x  ][y-1]);
        if(x < h-1 && y > 0) res.add(map[x+1][y-1]);
        if(x > 0         ) res.add(map[x-1][y  ]);
        if(x < h-1         ) res.add(map[x+1][y  ]);
        if(x > 0 && y < w-1) res.add(map[x-1][y+1]);
        if(         y < w-1) res.add(map[x  ][y+1]);
        if(x < h-1 && y < w-1) res.add(map[x+1][y+1]);
        return res;
    }

}