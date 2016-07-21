#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
#else
     freopen("in.txt","r",stdin);
#endif

    multiset<long int>s;
    long int SUM=0;
    long int Max,Min,n,m,a,d;
    long int i,j;
    while(cin>>n){
        SUM = 0;
        if(n == 0){
            return 0;
        }
        s.clear();
        for(i=0; i<n; i++)
        {
            cin>>m;
            for(j=0; j<m; j++){
                cin>>a;
                s.insert(a);
            }

            Max=*(s.rbegin());
            Min=*(s.begin());
            d=Max-Min;
            SUM+=d;
            s.erase(s.find(Max));
            s.erase(s.find(Min));
        }
        cout<<SUM << endl;
    }
    return 0;
}
