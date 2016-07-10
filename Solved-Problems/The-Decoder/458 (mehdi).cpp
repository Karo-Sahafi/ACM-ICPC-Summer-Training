#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("out.txt" , "w" , stdout);
    //freopen("in.txt" , "r" , stdin);

    string str;

    while (getline(cin , str)){
        int l = str.length();

        for (int i = 0 ; i < l ; i++){
            cout << (char)(str[i] - 7);
        }

        cout << endl;
    }

    return 0;
}
