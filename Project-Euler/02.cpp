#include <iostream>

using namespace std;

int main()
{   int a=1,b=2,c,counter=0;
    while (true){
        c=a+b;
        if(c>4000000)break;
        if(c%2==0)counter+=c;
        a=b;
        b=c;
    }

    cout<<counter+2;
    return 0;
}
