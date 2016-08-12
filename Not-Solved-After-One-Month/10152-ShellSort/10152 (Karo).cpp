#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    int kase;
    cin >> kase;
    stack<string> fir;
    stack<string> sec;

    while(kase--){
        int n;
        cin >> n;
        string dest;
        getline(cin,dest);

        for(int i = 0; i < n; i++){
            string str;
            getline(cin,str);
            fir.push(str);
        }

        for(int i = 0; i < n; i++){
            string str;
            getline(cin,str);
            sec.push(str);
        }

        while(!fir.empty()){
            if(sec.top() == fir.top()){
                fir.pop();
                sec.pop();
            } else {
                fir.pop();
            }
        }
        while(!sec.empty()){
            cout << sec.top() << endl;
            sec.pop();
        }
        //if(kase > 0){
            cout << endl;
        //}
    }

}
