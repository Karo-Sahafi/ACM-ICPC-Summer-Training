import java.util.Scanner;
public class Main {
    static String output = "";
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int n = sc.nextInt();
        while (N!=0) {
            char[][] A = new char[N][N];
            char[][] B = new char[n][n];
            for(int i=0;i<N;i++){
                String temp = sc.next();
                A[i] = temp.toCharArray();
            }
            for(int i=0;i<n;i++){
                String temp = sc.next();
                B[i] = temp.toCharArray();
            }
             char[][] B90 =  rotate90(B, n);
             char[][] B180 = rotate90(B90, n);
             char[][] B270 = rotate90(B180, n);
             output += apearedInCounter(A, B, N, n) + " "+ apearedInCounter(A, B90, N, n)+" "+ apearedInCounter(A, B180, N, n)+" "+ apearedInCounter(A, B270, N, n) + "\n";
            N = sc.nextInt();
            n = sc.nextInt();
        } 
        output = output.trim();
         System.out.println(output);
    }
    public static char[][] rotate90(char[][] table,int n){
        char[][] rotated = new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rotated[i][j] = table[n-j-1][i];
            }
        }
        return rotated;
    }
    public static int apearedInCounter(char[][] A,char[][] B ,int N,int n){
        int count =0;
        for(int i=0;i<=N-n;i++){
            for(int j=0;j<=N-n;j++){
                int temp =0;
                    for(int k=0;k<n;k++){
                        for(int p=0;p<n;p++){
                            if(A[i+k][j+p] == B[k][p]){
                                temp++;
                            }
                            else{
                                temp=0;
                            }
                        }
                    }
                    if(temp == n*n){
                         count++;
                         temp =0;
                    }else{
                        temp =0;
                    }
            }
        }
        return count;
    }
}
