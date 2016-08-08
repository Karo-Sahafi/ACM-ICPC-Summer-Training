#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>  adj[200000] ;
bool wakedUp[27];
int countWakedUp(){
	int count = 0;
	for(int i=0;i<27;i++)
		if(wakedUp[i])
			count++;
	return count;
}
int main()
{	
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    	while(true){
    		if(cin.eof())
    			break;
    		int connectionCount;
		    cin>>n>>connectionCount;
		    char c;
		    for(int i=0;i<3;i++){
		    	cin>>c;
				wakedUp[c - 65] = true;   //-65 for converting char to int
		    }
		    char a,b;
		    for(int i=0;i<connectionCount;i++){
		    	cin>>a>>b;
		    	adj[a - 65].push_back(b - 65);
		    	adj[b - 65].push_back(a - 65);
		    }
		    int yearCount =0;
		    queue<int> q;
		    while(1){
		    	yearCount++;
		    	bool added = false;
			    for(int i=0;i<27;i++){
			    	if(!wakedUp[i]){
			    		int w = 0;
			    		for(int j=0;j<adj[i].size();j++){
			    			if(wakedUp[adj[i][j]])
			    				w++;
			    		}
			    		if(w >= 3){
			    			q.push(i);
			    			added = true;
			    		}
			    	}
			    }
			    if(!added){
			    	yearCount--;
			    	break;
			    }
			    while(q.size()){
			    	int u=q.front();
			    	q.pop();
			    	wakedUp[u] = true;
			    }
			}
			if(!cin.eof()){
				if(countWakedUp() == n && n != 0)		
				cout<<"WAKE UP IN, "<<yearCount<<", YEARS\n" ;
				else
				cout<<"THIS BRAIN NEVER WAKES UP\n";
			}
			for(int i=0;i<27;i++){
				adj[i].clear();
				wakedUp[i] = false;
			}
    	}
    
		
	return 0;
}
