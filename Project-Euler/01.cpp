#include <iostream>

using namespace std;

int main()
{
    int sum=0,i=0;
  for(i=1;i<1000;i++)
  {
      if(i%3==0)
        sum+=i;
      if(i%5==0)
        sum+=i;
      if(i%15==0)
       sum-=i;
  }
  cout<<sum;
    return 0;
}
