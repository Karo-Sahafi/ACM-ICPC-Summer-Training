import java.util.Scanner;
public class Main {
    static String output = "";
    static int cases = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int casesCount = Integer.parseInt(sc.nextLine());
        for(int c=0;c<casesCount;c++){
            String s1 = sc.nextLine();
            String sentence = clearString(s1);
            int tableK = jazr(sentence.length());
            if(tableK != 0){
                char[][] table = new char[tableK][tableK];
                int collector =0;
                for(int i=0;i<tableK;i++){
                    for(int j=0;j<tableK;j++){
                        table[i][j] = sentence.charAt(collector);
                        collector++;
                    }
                }
                if((checkLTR(table, sentence, tableK))&&(checkRTL(table, sentence, tableK))&&(checkUTD(table, sentence, tableK))&&(checkDTU(table, sentence, tableK)))
                {
                    cases++;
                    output += "\nCase #" + cases + ":\n";
                    output += tableK;
                }
                else{
                    cases++;
                    output += "\nCase #" +cases+ ":\nNo magic :(";
                }
            }
            else{
                cases++;
                output += "\nCase #" +cases+ ":\nNo magic :(";
            }
        }
        output = output.trim();
        System.out.println(output);
     }
    public static boolean checkLTR(char[][] table,String sentence,int k){
        int checker = 0;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(table[i][j] == sentence.charAt(checker))
                    checker++;
            }
        }
        if(checker == k*k)
            return true;
        return false;
    }
    public static String clearString(String s){
        String out = "";
        for(char c:s.toCharArray()){
            if((c!='\'')&&(c!='"')&&(c!=' ')&&(c!=';')&&(c!='(')&&(c!=')')&&(c!='!')&&(c!='?')&&(c!='.')&&(c!=','))
                out+=c;
        }
        return out;
    }
    public static boolean checkRTL(char[][] table,String sentence,int k){
        int checker = 0;
        for(int i=k-1;i>=0;i--){
            for(int j=k-1;j>=0;j--){
                if(table[i][j] == sentence.charAt(checker))
                    checker++;
            }
        }
        if(checker == k*k)
            return true;
        return false;
    }
    public static boolean checkUTD(char[][] table,String sentence,int k){
        int checker = 0;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(table[j][i] == sentence.charAt(checker))
                    checker++;
            }
        }
        if(checker == k*k)
            return true;
        return false;
    }
     public static boolean checkDTU(char[][] table,String sentence,int k){
        int checker = 0;
        for(int i=k-1;i>=0;i--){
            for(int j=k-1;j>=0;j--){
                if(table[j][i] == sentence.charAt(checker))
                    checker++;
            }
        }
        if(checker == k*k)
            return true;
        return false;
    }
    
    public static int jazr(int number){
        int jazr =0;
        for(int i=1;i<=number;i++){
            if(i*i == number){
                jazr = i;
            }
        }
        return jazr;
    }
}