import java.util.Scanner;
public class Main  {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String s = sc.nextLine();
            int max =0,current=0;
	    for(int i=0;i<s.length();i++){
		if(s.charAt(i)== ' '){
                    current++;
                    if(current>max)max=current;
		}
		else
		   current=0;
	    }
            System.out.println(count(max));
        }
    }
    public static int count(int n){
        int sum =0;
	while(n!=1){
		if(n%2==0){
			n/=2;
			sum++;
		}		
		else{
			n--;
			n/=2;
			sum++;
			n++;
		}
	}
	return sum;
    }
}

