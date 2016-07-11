import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num =sc.nextInt();
        List<String> data = new ArrayList<>();
        for(int i=0;i<num;i++){
            String temp = sc.next();
            data.add(findSmaller(temp));
        }
        for(String s:data)
            System.out.println(s);
    }
    public static String findSmaller(String dna){
        List<String> cycledDna = new ArrayList<>();
        String nextDna = cycle(dna);
        cycledDna.add(nextDna);
        for(int i=0;i<dna.length()-1;i++){
            nextDna = cycle(nextDna);
            cycledDna.add(nextDna);
        }
            String smaller = dna;
        for(String DNA:cycledDna){
            if(DNA.compareTo(smaller)<0){
              smaller = DNA;
            }
        }
        return smaller;
    }
    public static String cycle(String dna){
        String out = "";
        char temp = dna.charAt(dna.length() -1);
        out += temp;
        for(int i=0;i<dna.length() -1;i++){
            out += dna.charAt(i);
        }
        return out;
    }   
}