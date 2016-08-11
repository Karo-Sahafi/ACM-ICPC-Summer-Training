#include <bits/stdc++.h>
using namespace std;
int main()
{	
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    while(true){
    	int n;
	    cin>>n;
	    if(n==0)break;
	    vector<int> adj;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			adj.push_back(a);
		}
	    int maxn=-999999,maxOfAll=-999999,sum=adj[0];
		for(int i=0;i<n - 1;i++){
			sum = adj[i];
			for(int j=i+1;j<n;j++){
				sum+=adj[j];
				maxn = max(sum,maxn);
			}
		    maxOfAll = max(maxOfAll,maxn);
		}
		if(n==1)
		maxOfAll = adj[0];
		if(maxOfAll>0)
			cout<<"The maximum winning streak is "<<maxOfAll<<"."<<endl;
			else
			cout<<"Losing streak.\n";
		}
    
	return 0;
}
