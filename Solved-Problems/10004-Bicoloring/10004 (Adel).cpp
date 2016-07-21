#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100*200;
vector<int> adj[MAXN];
bool mark[201];
int colored[201];
int invert(int a){
    if(a ==1)
        return 0;
    return 1;
}
bool isBIO(int nods){
	bool isBIO = true;
	for(int i=0;i<nods;i++){
		for(int j=0;j<adj[i].size();j++){
			if(colored[i] == colored[adj[i][j]])
				isBIO =false;
		}
	}
	return isBIO;
}
void bfs(int v){
    queue<int> q;
    mark[v] = 1;
    q.push(v);
    while(q.size()){
        v = q.front();
        q.pop();
        for(int i=0;i<adj[v].size();i++){
            int u = adj[v][i];
            colored[u] = invert(colored[v]);
            if(mark[u] == 1)
                continue;
            mark[u] = 1;
            q.push(u);
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
    int m,n;
    while(true){
    	cin>>n;
    	if(n==0)
    		break;
    	cin>>m;
	    for(int i=0;i<m;i++){
	        int v,u;
	        cin>>v>>u;
	        adj[v].push_back(u);
	        adj[u].push_back(v);
	    }
	    colored[0] = 0;
	    bfs(0);
	    if(isBIO(n))
	    	cout<<"BICOLORABLE."<<endl;
	    else
	    	cout<<"NOT BICOLORABLE."<<endl;
	    for(int i=0;i<n;i++){
	    	adj[i].clear();	
			colored[i] = 0;
			mark[i] = 0;
	    }
			
	}
    
    
    return 0;
}

