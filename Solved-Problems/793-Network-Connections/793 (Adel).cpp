#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200000];
int mark[200000];
char line[200000];
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
int main()
{	
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
	string s;
    int Cases;
    cin>>Cases;
    while(Cases--){
    	int computers;
    	scanf("\n%d\n",&computers);
		int successfull=0,unsuccessfull=0;
		for(int i=0;i<computers;i++)
     		adj[i].push_back(i);
    	while(true){
    		char qOrc;
			int a ,b;
    		if(!getline(cin,s) || s.empty())
			  break;
			sscanf(s.c_str(), "%c %d %d", &qOrc, &a, &b);
			if(qOrc  == 'c'){
				adj[a - 1].push_back(b - 1);
				adj[b - 1].push_back(a - 1);
			}
			else if(qOrc == 'q'){
				bfs(a - 1);
				if(mark[b - 1])
					successfull++;
				else
					unsuccessfull++;
				for(int i=0;i<computers;i++)
					mark[i] = 0;
			}
    	}
    	if(Cases == 0)
    	cout<<successfull<<","<<unsuccessfull<<endl;
    	else
		cout<<successfull<<","<<unsuccessfull<<endl<<endl;
		
		for(int i=0;i<computers;i++){
				mark[i] = 0;
				adj[i].clear();
		}
	
    }
	return 0;
}
