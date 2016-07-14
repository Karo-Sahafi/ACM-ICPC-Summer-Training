import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
    static String output = "";
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int k = 0; k < cases; k++) {
            int m,n;
            m=sc.nextInt();
            n=sc.nextInt();
            String[] DNAs = new String[n];
            for(int i=0;i<m;i++){
                String temp = new String();
                temp = sc.next();
                DNAs[i]=temp;
            }
            int totalError = 0;
            for(int i=0;i<n;i++){
                String temp = "";
                for(int j=0;j<m;j++){
                    temp+= DNAs[j].charAt(i);
                }
                output += checkLine(temp, m);
                totalError+= countError(temp ,checkLine(temp, m));
            }
            output += "\n" + totalError + "\n";
        }
        output = output.trim();
        System.out.println(output);
    }
    public static char checkLine(String chars,int m){
        char[] characters = chars.toCharArray();
        int aCount = 0,cCount =0,gCount=0,tCount=0,max = 0;
        for(int i=0;i<m;i++){
            switch(characters[i]){
                case 'A':
                    aCount++;
                    if(aCount>max)
                        max = aCount;
                    break;
                case 'C':
                    cCount++;
                    if(cCount>max)
                        max = cCount;
                    break;
                case 'G':
                    gCount++;
                    if(gCount>max)
                        max = gCount;
                    break;
                case 'T':
                    tCount++;
                    if(tCount>max)
                        max = tCount;
                    break;
            }
        }
            if(max == aCount)
                return 'A';
            if(max == cCount)
                return 'C';
            if(max == gCount)
                return 'G';
            if(max == tCount)
                return 'T';
            return 'X';
        }
    public static int countError(String chars,char a){
        int error = 0;
        char[] characters = chars.toCharArray();
        for(char c:characters){
        if(c!=a)
            error++;
        }
        return error;
    }
}