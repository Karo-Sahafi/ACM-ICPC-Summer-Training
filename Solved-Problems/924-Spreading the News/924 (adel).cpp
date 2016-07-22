#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100*2000;
vector<int> adj[MAXN];
bool mark[2501];
int day[MAXN];

int findMax(int a[],int b,int c){
	int counter=0;
	for(int i=0;i<b;i++){
		if(a[i] == c)
			counter++;
	}
	return counter;
}

void bfs(int v){
    queue<int> q;
    mark[v] = 1;
    q.push(v);
    day[v] = 0;
    while(q.size()){
        v = q.front();
        q.pop();
        int u = -1;
        for(int i=0;i<adj[v].size();i++){
            u = adj[v][i];
            if(mark[u] == 1){
                continue;
            }
            day[u] = day[v] + 1;
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
    	cin>>n;
    	for(int i=0;i<n;i++){
    		cin>>m;
    		for(int j=0;j<m;j++){
    			int u;
    			cin >> u;
    			adj[i].push_back(u);
    		}
    	}
    	int cases =0;
    	cin>>cases;
    	for(int i=0;i<cases;i++){
    		int employee;
    		cin>>employee;
    		bfs(employee);
    		int max=findMax(day,n,1),maxDay = 1;
	    	for(int j=1;j<n;j++){
				if(findMax(day,n,j) > max){
					max =findMax(day,n,j);
					maxDay = j;
				}
	    	}
	    	
	    	if(adj[employee].size())
				 cout<<max<<" "<<maxDay<<endl;
			else
			cout<<"0"<<endl;
	    	
			for(int i=0;i<m;i++){	
				day[i]=0;
	    	}	
	    	for(int i=0;i<n;i++){	
				mark[i] = 0;
				day[i] = 0;
	    	}
		}
    return 0;
}

