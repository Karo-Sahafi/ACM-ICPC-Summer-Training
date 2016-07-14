import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = -1;
        while(n!=0){
            n=sc.nextLong();
            long jazr = (long)Math.sqrt(n);
            if(n==1l)
                System.out.println("yes");
            if(n==2l)
                System.out.println("no");
            if(n==3l)
                System.out.println("no");
            if(n>3l)
                if(jazr*jazr == n)
                    System.out.println("yes");
                else
                    System.out.println("no");
        }
    }
}