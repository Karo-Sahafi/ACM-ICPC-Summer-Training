#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[1001][1001];
int table[1001][1001];
int timeTable[1002][1002];
int mark[1001][1001];
pair<int,int> workPair;
int bfs(int startX,int startY,int destX,int destY){
	queue<pair<int,int> > q;
    mark[startX][startY] = 1;
    workPair.first= startX;
    workPair.second = startY;
    q.push(workPair);
    timeTable[startX][startY] = 0;
    while(q.size()){
    	pair<int,int> v = q.front();
    	q.pop();
    	for(int i=0;i<adj[v.first][v.second].size();i++){
    		pair<int ,int> u = adj[v.first][v.second][i];
    		if(mark[u.first][u.second] ==1)
    			continue;
    		mark[u.first][u.second] = 1;
    		timeTable[u.first][u.second] = timeTable[v.first][v.second] + 1;
    		workPair.first = u.first;
    		workPair.second = u.second;
    		q.push(workPair);
    	}
    }
    return timeTable[destX][destY];
}
int main()
{	
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
	int R,C,B;
	while(true){
		cin>>R>>C;
		if(R==0)
			break;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				table[i][j] = 0;
			}
		}
		cin>>B;
		for(int i=0;i<B;i++){
			int bombRow,bombCount;
			cin>>bombRow>>bombCount;
			for(int j=0;j<bombCount;j++){
				int bombCol;
				cin>>bombCol;
				table[bombRow][bombCol] = 1;
			}
		}
		//filling adj
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(table[i][j] == 0){
					if(table[i][j+1] == 0){
						workPair.first = i;
						workPair.second = j + 1;
						adj[i][j].push_back(workPair);
					}
					if(table[i + 1][j] == 0){
						workPair.first = i + 1;
						workPair.second = j;
						adj[i][j].push_back(workPair);
					}
					if(i - 1 >= 0){
							if(table[i - 1][j] == 0){
							workPair.first = i - 1;
							workPair.second = j;
							adj[i][j].push_back(workPair);
						}
					}				
					if(j - 1 >= 0){
						if(table[i][j - 1] == 0){
							workPair.first = i;
							workPair.second = j - 1;
							adj[i][j].push_back(workPair);
						}
					}
				}
			}
		}
		pair<int,int> start,dest;
		cin>>start.first>>start.second;
		cin>>dest.first>>dest.second;
		cout<<bfs(start.first,start.second,dest.first,dest.second)<<endl;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				mark[i][j]=0;
				while(adj[i][j].size())
					adj[i][j].pop_back();
			}
		}
		
	}
	
	
}
