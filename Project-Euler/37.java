public class Euler {

    public static void main(String[] args) {
        int sum = 0 , i = 0;
        int k=10;
        while( i < 11 ){
            if(jalib (k)){
                sum+=k;
                i++;
                //System.out.println(k);
            }
            k++;
        }
        System.out.println(sum);
        //System.out.println(jalib(3797));
    }
    public static boolean jalib (int a){
        if(a< 10 ) return false;
        int n=a;
        boolean t=true;
        
        while(n !=0 && t){
            if (isprime(n))
                n=shiftberast(n);
            else
                t=false;
        }
        
         while(a >0 && t){
            if (isprime(a)){
                a=shiftbechap(a);
            }
            else 
                t=false;
        }
         return t;
    }
    
    private static int shiftberast(int n) {
        
        return (int)n/10;
        
    }
    private static int shiftbechap(int n) {
        if(Integer.toString(n).length()==1)
            return 0;
        String ss=Integer.toString(n).substring(1, Integer.toString(n).length());
        return Integer.parseInt(ss);
    }
    public static boolean isprime(int a){
        if(a==2 || a==3 || a==5 ||a==7) 
            return true;
        if(a==1 || a==0)
            return false;
        for (int i=2 ; i <=Math.sqrt(a);i++)
            if(a%i==0) return false;
        return true;
    }
}