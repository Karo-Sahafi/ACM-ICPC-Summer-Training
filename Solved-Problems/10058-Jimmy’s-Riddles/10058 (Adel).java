import java.util.Scanner;
import java.util.Vector;
public class Main {
   static String NOUNS[]= {"tom","jerry","goofy","mickey","jimmy","dog","cat","mouse"};
   static String VERBS[]= {"hates","loves","knows","likes","hate","love","know","like"};
   static String ARTICLES[]={"a","the"};
   static String s = "tom hates jerry  , tom and jerry and goofy hate jimmy";
    public static void main(String[] args) {
       Scanner scanner= new Scanner(System.in);
       while (scanner.hasNextLine()){
        s = scanner.nextLine();
        if(statementCheck(s))
            System.out.println("YES I WILL");
        else
            System.out.println("NO I WON'T");
      }
    }
    public static boolean statementCheck(String tmp){
        String[] statementsToCheck = tmp.split(" , ");
        for(String s:statementsToCheck){
            s=s.trim();
            if(!actionCheck(s))
                return false;
        }
        return true;
    }
    public static boolean actionCheck(String tmp){
        String verbFound="";
        for(String verb:VERBS){
            if(tmp.indexOf(verb)!=-1){
                verbFound=verb;
                break;
            }
        }
        if(verbFound==""&&tmp!=""&&tmp!=" ")
            return false;
        String[] activelistsToCheck = tmp.split(" "+verbFound+" ");
        for(String al:activelistsToCheck){
            if(!activeListCheck(al))
                return false;
        }
        return true;
    }
    public static boolean activeListCheck(String tmp){
        String[] actors = tmp.split(" and ");
        for(String actor:actors){
            if(!actorCheck(actor))
                return false;
        }
        return true;
    }
    public static boolean actorCheck(String tmp){
        tmp = tmp.replaceAll("the ", "");
        tmp = tmp.replaceAll("a ", "");
        for(String noun:NOUNS){
             if(noun.compareTo(tmp)==0)
                 return true;
        }
        return false;
    }
}
