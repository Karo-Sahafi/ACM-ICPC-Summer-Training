import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[][] board = new char[8][8];
        List<Integer> games = new ArrayList<>();
        while(true){
            for(int i=0;i<8;i++){
            String temp = sc.next();
            board[i]=temp.toCharArray();
            }
            if(EmptyBoard(board)){
                break;
            }
            games.add(checkCheck(board));
        }
        for(int i=0;i<games.size();i++){
            switch (games.get(i)){
                case 0:
                    System.out.println("Game #"+(i+1)+": no king is in check.");
                    break;
                case 1:
                    System.out.println("Game #"+(i+1)+": white king is in check.");
                    break;
                case 2:
                    System.out.println("Game #"+(i+1)+": black king is in check.");
                    break;
            }
        }
    }     
    public static int checkCheck(char [][] board){
        int kingX=-2,kingY=-2,KingX=-2,KingY=-2,result=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j] == 'k'){
                    kingX=i;
                    kingY=j;
                }
                if(board[i][j] == 'K'){
                    KingX=i;
                    KingY=j;
                }
            }
        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                switch (board[i][j]){
                    case 'r':
                        if(checkRook(KingX, KingY, i, j,board)){
                            result=1;}
                        break;
                    case 'R':
                        if(checkRook(kingX, kingY, i, j,board)){
                            result=2;}
                        break;
                    case 'b':
                        if(checkBishop(KingX, KingY, i, j,board)){
                            result=1;}
                        break;
                    case 'B':
                        if(checkBishop(kingX, kingY, i, j,board)){
                            result=2;}
                        break;
                    case 'n':
                        if(checkKnigt(KingX, KingY, i, j)){
                            result=1;}
                        break;
                    case 'N':
                        if(checkKnigt(kingX, kingY, i, j)){
                            result=2;}
                        break;    
                    case 'q':
                        if(checkQueen(KingX, KingY, i, j,board)){
                            result=1;}
                        break;
                    case 'Q':
                        if(checkQueen(kingX, kingY, i, j,board)){
                            result=2;}
                        break;
                    case 'p':
                        if(checkpawn(KingX, KingY, i, j)){
                            result=1;}
                        break;
                    case 'P':
                        if(checkPawn(kingX, kingY, i, j)){
                            result=2;}
                        break;
                    case '.':
                        break;
                }
            }
        }
        return result;
      }
    public static boolean checkRook(int kingX,int kingY,int rookX,int rookY,char[][]board){
        if(kingX == rookX){
            boolean hasWay=true;
            for(int i=min(kingY,rookY)+1;i<max(kingY,rookY);i++){
                if(board[kingX][i] !='.')
                    hasWay =false;
            }
            if(hasWay)
                return true;
        }
        if(kingY == rookY){
            boolean hasWay=true;
            for(int i=min(kingX,rookX)+1;i<max(kingX,rookX);i++){
                if(board[i][kingY] !='.')
                    hasWay =false;
            }
            if(hasWay)
                return true;
        }
        return false;
    }
    public static boolean checkKnigt(int kingX,int kingY,int knightX,int knightY){
                if((abs(kingX - knightX)==1)&&(abs(kingY - knightY))==2){
                    return true;
                }
                if((abs(kingX - knightX)==2)&&(abs(kingY - knightY))==1){
                    return true;
                }
        return false;
    }
    public static boolean checkBishop(int kingX,int kingY,int bishopX,int bishopY,char[][]board){
        boolean hasWay =true;
        if(abs(kingX-bishopX)==abs(kingY-bishopY)){
            if((kingX-bishopX)*(kingY-bishopY)>0){
                for(int i=min(kingX,bishopX) + 1, j=min(kingY,bishopY)+1;i<max(kingX,bishopX);i++,j++){
                        if(board[i][j] != '.'){
                            hasWay= false;
                        }
                }
                if(hasWay)
                    return true;
            }
            else{
                for(int i=max(kingX,bishopX) -1, j=min(kingY,bishopY) + 1;i>=min(kingX,bishopX)+1;i--,j++){
                        if(board[i][j] != '.'){
                            hasWay= false;
                        }
                }
                if(hasWay)
                    return true;
            }
        }
        return false;
    }
    public static boolean checkQueen(int kingX,int kingY,int queenX,int queenY,char board[][]){
        if(checkBishop(kingX,kingY,queenX,queenY,board)||checkRook(kingX,kingY,queenX,queenY,board))
          return true;
        return false;
    }
    public static boolean checkpawn(int kingX,int kingY,int pawnX,int pawnY){
        if((abs(kingY-pawnY)==1)&&(kingX-pawnX ==1))
          return true;
        return false;
    }
    public static boolean checkPawn(int kingX,int kingY,int pawnX,int pawnY){
        if((abs(kingY-pawnY)==1)&&(pawnX-kingX ==1))
          return true;
        return false;
    }
    public static boolean EmptyBoard(char[][] b){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(b[i][j] !='.')
                    return false;
            }
        }
        return true;
    }
    public static int abs(int a){
        if(a<0)
        a = -a;
        return a;
    }
    public static int min(int a,int b){
        if(a<b)
        return a;
        return b;
    }
    public static int max(int a,int b){
        if(a<b)
        return b;
        return a;
    }
}