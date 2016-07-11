import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> scores = new ArrayList<>();
        for(int i=0;i<n;i++){
            String temp = sc.next();
            scores.add(calcScore(temp));
        }
        for(int score:scores)
            System.out.println(score);
    }
    public static int calcScore(String s){
        int j=1,score=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='O'){
                score +=j;
                j++;
            }
            if(s.charAt(i)=='X'){
            j=1;
            }
        }
        return score;
    }
}

