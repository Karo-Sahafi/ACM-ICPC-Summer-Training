#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100*2000;
vector<int> adj[MAXN];
int m,n;
bool mark[2501];
void bfs(int v){
    queue<int> q;
    mark[v] = 1;
    q.push(v);
    while(q.size()){
        v = q.front();
        q.pop();
        int u = -1;
        for(int i=0;i<adj[v].size();i++){
            u = adj[v][i];
            if(mark[u] == 1){
                continue;
            }
            mark[u] = 1;
            q.push(u);
         }
    }
}
void clearMark(){
	for(int i=0;i<n;i++)
		mark[i] = false;
}
bool hasWayToAll(){
	for(int i=0;i<n;i++){
		if(mark[i] == false)
			return false;
	}
	return true;
}
int main()
{	
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    while(true){
    	cin>>n>>m;
    	if((n==0)&&(m==0))
    		break;
		int a,b,c;
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			if(c==1){
				adj[a-1].push_back(b-1);
			}
			else{
				adj[a-1].push_back(b-1);
				adj[b-1].push_back(a-1);
			}
		}
		int count =0;
		for(int i=0;i<n;i++){
			bfs(i);
			if(hasWayToAll())
				count++;
			clearMark();
		}
    	if(count == n)
    		cout<<"1"<<endl;
    	else
    		cout<<"0"<<endl;
    		
    	for(int i=0;i<n;i++){
    		while(adj[i].size())
    			adj[i].pop_back();
    	}
    }
    	
	return 0;
}


