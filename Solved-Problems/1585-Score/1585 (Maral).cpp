#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifdef ONLINE_JUDGE
    #else
       // freopen("in.txt","r",stdin);
       #endif
    char s[80];

    int m,k,l,i;
    long int score=0;
    int j=1,T;
cin>>T;
for( k=0;k<T;k++)
{
cin>>s;

l= strlen(s);
for(i=0;i<=l;i++)
  {
 if(s[i]=='O'){
score=score+j;

j++;
 }
 if(s[i]=='X')
    j=1;

}
cout<<score<<endl;
 score=0;
 j=1;

}




	return 0;
}

