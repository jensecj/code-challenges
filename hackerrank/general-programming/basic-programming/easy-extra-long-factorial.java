/*
  tags: big integer, bigint, factorial
  task: find the factorial of some large number (~100, which is quite large for factorials)
*/
import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {

    public static BigInteger factorial(BigInteger n) {
        BigInteger result = BigInteger.ONE;

        while (!n.equals(BigInteger.ZERO)) {
            result = result.multiply(n);
            n = n.subtract(BigInteger.ONE);
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        System.out.println(factorial(BigInteger.valueOf(n)));
    }
}
