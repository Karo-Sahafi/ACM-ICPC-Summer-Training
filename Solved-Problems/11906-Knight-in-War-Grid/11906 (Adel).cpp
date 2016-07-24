#include <bits/stdc++.h>
using namespace std;
int table[100][100];
int mark[100][100];
pair<int,int> workingPair;
vector<pair<int , int> > adj[100][100];
bool contains( int a, int b ,int x, int y){
	workingPair.first = a;
	workingPair.second = b;
	for(int k=0;k<adj[x][y].size();k++){
		if(adj[x][y][k] == workingPair)
			return true;
	}
	return false;
}
void bfs(){
	queue<pair<int,int> > q;
	workingPair.first = 0;
	workingPair.second = 0;
	mark[0][0] = 1;
	q.push(workingPair);
	while(q.size()){
		pair<int,int> v = q.front();
    	q.pop();
    	for(int i=0;i<adj[v.first][v.second].size();i++){
    		pair<int ,int> u = adj[v.first][v.second][i];
    		if(mark[u.first][u.second] ==1)
    			continue;
    		mark[u.first][u.second] = 1;
    		workingPair.first = u.first;
    		workingPair.second = u.second;
    		q.push(workingPair);
    	}
	} 
}
int main()
{	
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int cases;
    cin >>cases;
    for(int h=0;h<cases;h++){
    	int R,C,M,N;
	    cin>>R>>C>>M>>N;
	    //filling table with 0
	    for(int i=0;i<R;i++){
	    	for(int j=0;j<C;j++){
	    		table[i][j] = 0;
	    	}
	    }
	    int waterCount;
	    cin>>waterCount;
	    //filling water places with 1
	    for(int i=0;i<waterCount;i++){
	    	pair<int,int> waterPos;
	    	cin>>waterPos.first>>waterPos.second;
	    	table[waterPos.first][waterPos.second] = 1;
	    }
	    //end of filling water places
	    //filling adj
		for(int i=0;i<R;i++){
	    	for(int j=0;j<C;j++){
	    		if(table[i][j] == 0){
	    			if((i+M < R)&&(j+N < C)){
						workingPair.first = i+M;
						workingPair.second = j +N;
						if(!contains(workingPair.first,workingPair.second , i , j))
							if(table[workingPair.first][workingPair.second] != 1)
								adj[i][j].push_back(workingPair);
	    			}
	    			if((i+M < R)&&(j-N>= 0)){
						workingPair.first = i+M;
						workingPair.second = j - N;
						if(!contains(workingPair.first,workingPair.second , i , j))
							if(table[workingPair.first][workingPair.second] != 1)
						adj[i][j].push_back(workingPair);
	    			}
	   	 			if((i-M >= 0)&&(j+N< C)){
						workingPair.first = i-M;
						workingPair.second = j +N;
						if(!contains(workingPair.first,workingPair.second , i , j))
							if(table[workingPair.first][workingPair.second] != 1)
						adj[i][j].push_back(workingPair);
	    			}
	    			if((i-M >= 0)&&(j-N>= 0)){
						workingPair.first = i-M;
						workingPair.second = j-N;
						if(!contains(workingPair.first,workingPair.second , i , j))
							if(table[workingPair.first][workingPair.second] != 1)
						adj[i][j].push_back(workingPair);
	    			}
	    			if((i+N < R)&&(j+M < C)){
						workingPair.first = i+N;
						workingPair.second = j +M;
						if(!contains(workingPair.first,workingPair.second , i , j))
							if(table[workingPair.first][workingPair.second] != 1)
						adj[i][j].push_back(workingPair);
	    			}
	    			if((i+N < R)&&(j-M >= 0)){
						workingPair.first = i+N;
						workingPair.second = j-M;
						if(!contains(workingPair.first,workingPair.second , i , j))
							if(table[workingPair.first][workingPair.second] != 1)
						adj[i][j].push_back(workingPair);
	    			}
	    			if((i-N >= 0)&&(j+M < C)){
						workingPair.first = i-N;
						workingPair.second = j+M;
						if(!contains(workingPair.first,workingPair.second , i , j))
							if(table[workingPair.first][workingPair.second] != 1)
						adj[i][j].push_back(workingPair);
	    			}
	    			if((i-N >= 0)&&(j-M >= 0)){
						workingPair.first = i-N;
						workingPair.second = j-M;
						if(!contains(workingPair.first,workingPair.second , i , j))
							if(table[workingPair.first][workingPair.second] != 1)
						adj[i][j].push_back(workingPair);
	    			}
	    		}
	    	}
	    }
	    //end of filling adj
	    bfs();
	    int even=0,odd=0;
	    for(int i=0;i<R;i++){
	    	for(int j=0;j<C;j++){
	    		if(mark[i][j]  == 1){
	    			if(adj[i][j].size() % 2 == 0){
	    				even++;
	    			}else{
	    				odd++;
	    			}
	    		}
	    	}
	    }
	    cout <<"Case "<<h+1<<": "<<even<<" "<<odd <<endl;
	    for(int i=0;i<R;i++){
	    	for(int j=0;j<C;j++){
	    		mark[i][j] =0;
	    		while(adj[i][j].size())
				adj[i][j].pop_back();
	    	}
	    }
    }
		return 0;
}
