#include <bits/stdc++.h>
using namespace std;
multiset<int>::iterator it;
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
    	if(n==0)
    		break;
    	multiset<int> numbers;
    	int a;
	    for(int i=0;i<n;i++){
	    	cin>>a;
	    	numbers.insert(a);
	    }
	    int cost =0 ,sum = 0;
	    for(int i=0;i<n - 1;i++){
	    	it=numbers.begin();
	    	cost = *it + *(++it);
	    	it=numbers.begin();
	    	numbers.erase(it);
	    	it=numbers.begin();
	    	numbers.erase(it);
	    	sum+= cost;
	    	numbers.insert(cost);
	    }
	    cout<<sum<<endl;
    }
	return 0;
}
