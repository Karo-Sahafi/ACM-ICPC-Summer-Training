#include <bits/stdc++.h>
using namespace std;
vector<string> table;
int shipAlive = 0;
int main()
{	
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int cases =0;
    cin>>cases;
    for(int p=0;p<cases;p++){
	    int n;
		cin>>n;
		string edges = "";
		for(int i=0;i<n+2;i++){
			edges+=".";
		}
		table.push_back(edges);
		for(int i=0;i<n;i++){
			string temp ="";
			cin>>temp;
			temp = "." + temp + ".";
			table.push_back(temp);
		}
		table.push_back(edges);
		for(int i=1;i<n+1;i++){
			for(int j=1;j<n+1;j++){
				if((table[i][j] == 'x')||(table[i][j] == '@')){
									
					int xcount =0,andcount=0,count=0;
					while(table[i][j + count] != '.'){
						if(table[i][j+count] == 'x')
							xcount++;
						if(table[i][j+count] == '@')
							andcount++;
						count++;
					}
					
					if((count>1)&&(xcount>0)){
						for(int k=0;k<count;k++){
							table[i][j+k] = '.';
						}
						shipAlive++;
					}
					xcount =0,andcount=0,count=0;
					while(table[i+ count][j ] != '.'){
						if(table[i+count][j] == 'x')
							xcount++;
						if(table[i+count][j] == '@')
							andcount++;
						count++;
					}
					
					if((count>1)&&(xcount>0)){
						for(int k=0;k<count;k++){
							table[i+k][j] = '.';
						}
						shipAlive++;
					}
				}
				if(table[i][j] == 'x'){
						if((table[i+1][j+1] == '.')&&(table[i+1][j] == '.')&&(table[i+1][j-1] == '.') 
						&&(table[i][j-1] == '.') &&(table[i][j+1] == '.') &&(table[i-1][j+1] == '.')
						 &&(table[i-1][j] == '.')&&(table[i-1][j-1] == '.'))  
							table[i][j] = '.';
							shipAlive++;
					}
			}
		}
		cout<<"Case "<<p+1<<": "<<shipAlive<<endl;
		shipAlive = 0;
		
		while(table.size())
		table.pop_back();
    }
	return 0;
}
