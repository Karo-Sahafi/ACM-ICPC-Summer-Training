#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i,sum1=0,sum2=0;
    int n=0;
    for( i=1;i<=100;i++)
    {
       sum1=pow(i,2)+sum1;
       sum2+=i;
    }
 n= pow(sum2,2)-sum1+1;

   cout<<n<<endl;
    return 0;
}
