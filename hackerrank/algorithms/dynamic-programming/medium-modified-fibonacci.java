/*
  tags: big integer, bigint, fibonacci
  task: given a modified fibonacci formula, implement it
  note: this problem is under dynamic programming, but does not fit at
  all, instead it about really big numbers.
*/
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public static BigInteger fib(BigInteger a, BigInteger b, BigInteger n){
        BigInteger b_squared = b.pow(2);
        BigInteger answer = a.add(b_squared);

        a = b;
        b = answer;

        for(int i = 3; i < n.intValue(); i++){
            b_squared = b.pow(2);
            answer = a.add(b_squared);
            a = b;
            b = answer;
        }

        return answer;
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t1 = scan.nextInt();
        int t2 = scan.nextInt();
        int n = scan.nextInt();

        System.out.println(fib(BigInteger.valueOf(t1), BigInteger.valueOf(t2), BigInteger.valueOf(n)));
    }
}
