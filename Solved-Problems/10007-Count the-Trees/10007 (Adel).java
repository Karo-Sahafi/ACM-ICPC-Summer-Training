import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        while(true){
            n= sc.nextInt();
            if(n==0)break;
            BigInteger res = new BigInteger("1");
            for(int i=n+2;i<=2*n;i++)
                res = res.multiply(BigInteger.valueOf(i));
            System.out.println(res);
        }
    }
}
