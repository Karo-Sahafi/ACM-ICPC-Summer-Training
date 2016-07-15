#include <iostream>
#include <cmath>
using namespace std;
int prime(int a){
    bool s=true;
    int i;
    bool aval=true;
    if(a==1) return 0;
    for(i=2;i<=sqrt(a);i++){

        if(a%i==0)
        {
            aval=false;
            s=s&aval;}
            else{
                aval=true;
            s=s&aval;
            }
            }
        if(s)
            return 1;
        else return 0;

}
int main()
{

    int i=0,j;
    int n=10001;
    int aval=0;
for(i=2;aval<n;i++){
    if(prime(i)){

  aval++;
    j=i;
    }
}
cout<<j;

    return 0;
}
