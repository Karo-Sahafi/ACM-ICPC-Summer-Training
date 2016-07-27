#include <bits/stdc++.h>
using namespace std;
int p,q,r,s,t,u;
double f(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main()
{
	#ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    while( cin>>p>>q>>r>>s>>t>>u){
	    double x;
	    double a=0,b=1,c=0.5;
	    int deghat =150;
	    //if F is increasing in (0,1)
	    if(f(0) == 0){
            cout << "0.0000" << endl;
            continue;
	    }
	    if(f(1) == 0){
            cout<< "1.0000" << endl;
            continue;
	    }
		if((f(a) < 0)&&(f(b) > 0)){
	    	while((deghat--)&&((f(a) < 0)&&(f(b) > 0))){
	    		c=(a+b)/2;
		    	if(f(c) < 0)
		    		a = c;
		    	else
					b = c;
	    	}
	    	cout<<fixed<<setprecision(4)<<c<<endl;
	    }
	    //if F is decreasing in (0,1)
	    else if((f(a) > 0)&&(f(b) < 0)){
	    	while((deghat--)&&((f(a) > 0)&&(f(b) < 0))){
	    		c=(a+b)/2;
		    	if(f(c) < 0)
		    		b = c;
		    	else
		    		a = c;
	    	}
	    	cout<<fixed<<setprecision(4)<<c<<endl;
	    }
	    else{
	    	cout<<"No solution"<<endl;
	    }
	}
	return 0;
}
