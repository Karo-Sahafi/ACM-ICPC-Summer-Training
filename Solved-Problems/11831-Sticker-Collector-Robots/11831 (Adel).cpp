#include <bits/stdc++.h>
using namespace std;
vector<string> table;
pair<int,int> robotPos;
char orientation;
int collected = 0;
int main() {
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int m,n,s;
    while(true){
	    	cin>>m>>n>>s;
		if(m==0)
			break;
	    string tmp = "";
	    for(int i=0;i<n + 2;i++){
	    	tmp+= "#";
	    }
	    table.push_back(tmp);
	    for(int i=0;i<m;i++){
	    	string buffer = "";
	    	cin>>buffer;
	    	string temp = "#" + buffer + "#";
	    	table.push_back(temp);
	    }
	    table.push_back(tmp);
	    
	    for(int i=1;i<m +1;i++){
	    	for(int j=1;j<n + 1;j++){
	    		switch(table[i][j]){
	    			case 'N':
	    				robotPos.first = i;
	    				robotPos.second = j;
	    				orientation = 'N';
	    				break;
	    			case 'S':
	    				robotPos.first = i;
	    				robotPos.second = j;
	    				orientation = 'S';
	    				break;
	    			case 'L':
	    				robotPos.first = i;
	    				robotPos.second = j;
	    				orientation = 'L';
	    				break;
	    			case 'O':
	    				robotPos.first = i;
	    				robotPos.second = j;
	    				orientation = 'O';
	    				break;
	    		}
	    	}
	    }
	    string instructions = "";
	    cin>>instructions;
	    for(int i=0;i<s;i++){
	    	if(instructions[i] == 'D'){
	    		switch(orientation){
	    			case 'N':
	    				orientation = 'L';
	    				break;
	    			case 'S':
	    				orientation = 'O';
	    				break;
	    			case 'L':
	    				orientation = 'S';
	    				break;
	    			case 'O':
	    				orientation = 'N';
	    				break;
	    		}
	    	}
	    	if(instructions[i] == 'E'){
	    		switch(orientation){
	    			case 'N':
	    				orientation = 'O';
	    				break;
	    			case 'S':
	    				orientation = 'L';
	    				break;
	    			case 'L':
	    				orientation = 'N';
	    				break;
	    			case 'O':
	    				orientation = 'S';
	    				break;
	    		}
	    	}
	    	if(instructions[i] == 'F'){
	    		switch(orientation){
	    			case 'N':
	    				if(table[robotPos.first - 1][robotPos.second] != '#'){
	    					robotPos.first-=1;
	    				}
	    				if(table[robotPos.first][robotPos.second] == '*'){
	    					collected++;
	    					table[robotPos.first][robotPos.second] = '.';
	    				}
	    				break;
	    			case 'S':
	    				if(table[robotPos.first + 1][robotPos.second] != '#'){
	    					robotPos.first+=1;
	    				}
	    				if(table[robotPos.first][robotPos.second] == '*'){
	    					collected++;
	    					table[robotPos.first][robotPos.second] = '.';
	    				}
	    				break;
	    			case 'L':
	    				if(table[robotPos.first][robotPos.second+1] != '#'){
	    					robotPos.second+=1;
	    				}
	    				if(table[robotPos.first][robotPos.second] == '*'){
	    					collected++;
	    					table[robotPos.first][robotPos.second] = '.';
	    				}
	    				break;
	    			case 'O':
	    				if(table[robotPos.first][robotPos.second-1] != '#'){
	    					robotPos.second-=1;
	    				}
	    				if(table[robotPos.first][robotPos.second] == '*'){
	    					collected++;
	    					table[robotPos.first][robotPos.second] = '.';
	    				}
	    				break;
	    		}
	    	}
	    }
	     
	    cout<<collected<<endl;
	    while(table.size()){
	    	table.pop_back();
	    }
	    collected =0;
    }
    return 0;
}
