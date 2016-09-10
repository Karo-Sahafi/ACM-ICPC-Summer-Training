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
		int n,x=1,y=2,add=0,turn=1;
		cin>>n;
		if(n==0)break;
		if(n==1){
			x=1;
			y=1;
			goto hell;
		}
		n-=2;
		while(n){
			add++;
			if(turn==1){
				if(n>add){
					x+=add;
					n-=add;
				}
				else{
					x+=n;
					goto hell;
				}
				if(n>add){
					y-=add;
					n-=add;
				}
				else{
					y-=n;
					goto hell;
				}
				x++;
				n--;
				if(n==0)goto hell;
			}		
			else{
				if(n>add){
					y+=add;
					n-=add;
				}
				else{
					y+=n;
					goto hell;
				}
				if(n>add){
					x-=add;
					n-=add;
				}
				else{
					x-=n;
					goto hell;
				}
				y++;
				n--;
				if(n==0)goto hell;
			}
			turn*=-1;
		}
		hell : cout<<x<<" "<<y<<endl;
    }
	return 0;
}

