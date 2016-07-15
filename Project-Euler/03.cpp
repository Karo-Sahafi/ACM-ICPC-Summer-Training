#include <iostream>
#include <math.h>
using namespace std;

int main()
{   long num=(600851475143);

    bool b=true;
    for(long i=sqrt(num);i>0;i--){
            b=true;
        if(num%i==0){
            for(long j=2;j<i;j++){
                if(i%j==0){
                    b=false;
                }
            }
           if(b==true){
            cout<<i<<endl;
             return 0;
           }
        }

    }

    return 0;
}

