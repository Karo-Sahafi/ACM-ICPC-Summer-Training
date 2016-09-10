#include<iostream>
#include<string>
#include<vector>

using namespace std;
bool compute(string name,int ST){
	vector<int>NumName;
	for (int i = 0; i<name.length(); i++){
		NumName.push_back((int)name[i] - 65);
	}
	int M = NumName.size();
	for (int i = 0; i < M; i++){
		NumName[i] += ST;
	}
	vector<int>donbale;
	for (int i = 0; i < M; i++){
		int digit[5] = { 0 };
		digit[4] = NumName[i] % 10;
		digit[3] = (NumName[i] % 100) / 10;
		digit[2] = (NumName[i] % 1000) / 100;
		digit[1] = (NumName[i] % 10000) / 1000;
		digit[0] = NumName[i] / 10000;
		if (NumName[i] >= 10000)
			donbale.push_back(digit[0]);
		if (NumName[i] >= 1000)
			donbale.push_back(digit[1]);
		if (NumName[i] >= 100)
			donbale.push_back(digit[2]);
		if (NumName[i] >= 10)
			donbale.push_back(digit[3]);
		donbale.push_back(digit[4]);
	}
	while (donbale.size()>3){
		for (int k = 0; k < donbale.size()-1;k++)
			donbale[k] = (donbale[k]+donbale[k+1]) % 10;	
		donbale.resize(donbale.size() - 1);
	}
	if(donbale[0]==1&&donbale[1]==0&&donbale[2]==0)
		return true;
	return false;
}
int main()
{
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    
	string name;
	while(cin>>name)
	{
		bool founded = false;
		for(int i=0;i<=10000;i++){
			if(compute(name,i)){
				cout<<i<<endl;
				founded=true;		
				break;
			}
		}
		if(!founded)
			cout<<":(\n";
	}
	return 0;
}



