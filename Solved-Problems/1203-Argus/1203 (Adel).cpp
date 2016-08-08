#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> wp;
int main()
{	
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    string s;
    int ID,period;
	vector<pair<int,int> > myVec;
	int BMM =0;
	int MinTime=INT_MAX;
    while(1){
    	if(!getline(cin,s) || s=="#")
			  break;
		sscanf(s.c_str(), "Register %d %d", &ID, &period);
		if (period < MinTime)
		MinTime = period;
		myVec.push_back(wp(ID,period));
	}
	for(int i=1;i<=myVec[0].first;i++){
		int count=0;
		for(int j=0;j<myVec.size();j++){
			if(myVec[j].first % i ==0){
				count++;
			}
		}
		if(count == myVec.size() &&  i > BMM)
			BMM = i;
	}
	sort(myVec.begin(),myVec.end());
    int n,time =0;
    cin>>n;
    while(n>0){
    	time+= BMM;
	   	for(int j=0;j<myVec.size();j++){
	   		if(time%myVec[j].second== 0){
	   			cout<<myVec[j].first<<endl;
				n--;
				if(n==0)
				break;
	   		}
		}
    }
	return 0;
}
