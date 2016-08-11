#include <bits/stdc++.h>
using namespace std;
int C(double a){
	if(a - int(a) == 0){
		return a;
	}
	return (int)a  +1;
}
int main()
{
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int len;
    int TCase ;
    cin>>TCase;
    for(int k=1;k<=TCase;k++){
		vector<char> field;
    	 cin>>len;
    	 if(len==0)
    	 	break;
	    field.push_back('#');
	    	char c;
	    for(int i=0;i<len;i++) {
	        cin>>c;
	        field.push_back(c);
	    }
	    field.push_back('#');
	    int grownables = 0;
	    int sum = 0;
		for(int i=0;i<field.size();i++){
			if(field[i] == '.')
	            grownables++;
	        else{
	        	if(grownables%3 == 1){
	        		double d = (double)grownables/3;
	        		if(d>0)
	        			sum += C(d);
	        		grownables = -1;
	        	}
	        	else{
	        		double d = (double)grownables/3;
	        		if(d>0)
	        			sum += C(d);
	        		grownables = 0;
	        	}
	        }	    	
	    }
	    cout<<"Case "<<k<<": "<<sum<<endl;
    }
    return 0;
}
