#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifdef ONLINE_JUDGE
    #else
       freopen("in.txt" , "r" , stdin);
    #endif
    int arra[30],arrb[30];
    string a,b;
    while (getline(cin , a)){
        getline(cin , b);
        fill(arra,arra+30,0);
        fill(arrb,arrb+30,0);
        for(int i=0 ; i < a.size() ; i++){
            arra[a[i]-'a']++;
        }
        for(int i=0 ; i < b.size() ; i++){
            arrb[b[i]-'a']++;
        }

        for(int i=0;i<30;i++ ){
            for(int j=0; j < min(arra[i],arrb[i]) ;j++){
                cout << (char)('a'+i);
            }
        }
        cout<<endl;
    }


    return 0;

}
