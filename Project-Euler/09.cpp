#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool f=true;
    int i,j,k=10000,n;
for(i=1;i<k&&f;i++)
for(j=1;j<k&&f;j++)
for(n=1;n<k&&f;n++)
    if((i*i+j*j)==n*n ){
cout<<i<<"^2  "<<j<<"^2   "<<"  =  "<<n<<"  n "<<endl;
if(i+j+n==1000){
    cout<<i*j*n;
   f=false;
}
}
 return 0;

    }
