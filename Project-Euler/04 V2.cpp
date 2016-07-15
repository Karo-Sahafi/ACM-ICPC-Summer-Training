#include <iostream>

using namespace std;




int static motegharen(long int a)
{
    bool c =false;
    bool s=true;
   long int b[100],i=0,j;
 while(a!=0)
    {
       b[i]=a%10;
       i++;
       a=a/10;
    }
    for(j=0;j<i/2;j++){

if(b[j]==b[i-j-1]){
    c=true;
    s=s&&c;
}
else{
    c=false;
    s=s&&c;
    }
    }
    if(s)
return 1;
    else
return 0;
}

int main(){


 long int m=0,i,j,k;
for(i=100;i<1000;i++){
    for(j=100;j<1000;j++){


if(motegharen(i*j)){

if(i*j>m)
    m=i*j;
    k=i;

}

    }
}
cout<<m<<endl<<k<<endl<<m/k;
return 0;
}
//cout<<m;



