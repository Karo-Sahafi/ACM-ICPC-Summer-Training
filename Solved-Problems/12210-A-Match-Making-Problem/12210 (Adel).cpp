#include <bits/stdc++.h>
using namespace std;
int main()
{
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int p=0;
    while(true){
    	p++;
    	int b,s;
	    cin>>b>>s;
	    if(b==0&&s==0)break;
	    int bachelor;
        vector<int> bachelors;
        for(int i=0;i<b;i++){
            cin>>bachelor;
            bachelors.push_back(bachelor);
        }
	     int spinster;
	     for(int i=0;i<s;i++)
	            cin>>spinster;
	    if(s>=b)
	        cout<<"Case "<<p<<": 0\n";
	    else{
	        sort(bachelors.begin(),bachelors.end());
		 	for(int i=0;i<s;i++)
		 		bachelors.pop_back();
		 	cout<<"Case "<<p<<": "<<bachelors.size()<<" "<<bachelors[0]<<endl;
	    }
    }
    return 0;
}

