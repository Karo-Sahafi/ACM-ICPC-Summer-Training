import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a , b;
        String ch;
        
        while (sc.hasNext()){
            a = sc.nextBigInteger();
            ch = sc.next();
            b = sc.nextBigInteger();

            if (ch.equals("/")){
                System.out.println(a.divide(b));
            } else if (ch.equals("%")){
                System.out.println(a.mod(b));
            }
        }
    }
}
