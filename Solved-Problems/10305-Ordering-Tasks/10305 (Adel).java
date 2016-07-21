import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main  {
    static String output = "";
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n,m;
            n=sc.nextInt();
            m=sc.nextInt();
            if((n==0)&&(m==0))
                break;
            List<int[]> ioj = new ArrayList<>();
                for(int i=0;i<m;i++){
                    int[] ij = new int[2];
                    ij[0] = sc.nextInt();
                    ij[1] = sc.nextInt();
                    ioj.add(ij);
                }
            int[] tasks = new int[n+1];
            for(int i=1;i<=n;i++)
                tasks[i] = i;
             while(countRights(tasks , ioj) != m){
                for(int[] ij : ioj){
                    if(indexOf(tasks, ij[0]) > indexOf(tasks, ij[1]))
                        tasks = swap(tasks, indexOf(tasks, ij[0]), indexOf(tasks, ij[1]));
                }
            }
             for(int i=1;i<tasks.length -1 ; i++){
                 output +=tasks[i] + " ";
             }
                 output+= tasks[tasks.length - 1] + "\n" ;
        }
        output = output.trim();
        System.out.println(output);
    }
    public static int indexOf(int[] task , int number){
        int pos = 0;
        for(int i=1;i<task.length;i++){
            if(task[i] == number)
                pos = i;
        }
        return pos;
    }
    public static int countRights(int[] task , List<int[]> ioj){
        int count =0;
        for(int[] ij  : ioj){
            if(indexOf(task,ij[0]) < indexOf(task, ij[1])){
                count++;
            }
        }
        return count;
    }
    public static int[] swap(int[] task , int pos1,int pos2){
        int temp =0;
        temp =task[pos2];
        task[pos2] = task[pos1];
        task[pos1] = temp;
        return task;
    }
}