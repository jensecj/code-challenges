import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner scan = new Scanner(System.in);

        BigInteger n = new BigInteger(scan.next());
        BigInteger hit = new BigInteger(scan.next());
        BigInteger t = new BigInteger(scan.next());

        ArrayList<BigInteger> mons = new ArrayList<BigInteger>();
        for(BigInteger i = BigInteger.valueOf(0); i.compareTo(n) < 0; i = i.add(BigInteger.ONE)) {
            mons.add(new BigInteger(scan.next()));
        }

        Collections.sort(mons);

        BigInteger total_dmg = t.multiply(hit);


        BigInteger sum = BigInteger.ZERO;
        BigInteger kills = BigInteger.ZERO;

        for(int i = 0; i < n.intValue(); i++) {
            if(sum.add(mons.get(i)).compareTo(total_dmg) > 0)
                break;

            sum = sum.add(mons.get(i));
            kills = kills.add(BigInteger.ONE);
        }
        System.out.println(kills);
    }
}
