#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("out.txt" , "w" , stdout);
    //freopen("in.txt" , "r" , stdin);

    string str;

    while (getline(cin , str)){
        int l = str.length();
        int tmp = 0;

        if (l == 1){
            cout << endl;
            continue;
        }

        for (int i = 0 ; i < l ; i++){
            if (isdigit(str[i])){
                tmp += (str[i] - '0');
            } else if (isalpha(str[i]) || str[i] == '*'){
                if (str[i] == 'b'){
                    for (int j = 0 ; j < tmp ; j++){
                        cout << ' ';
                    }
                } else {
                    for (int j = 0 ; j < tmp ; j++){
                        cout << str[i];
                    }
                }

                tmp = 0;
            } else if (str[i] == '!'){
                cout << endl;
            }
        }

        cout << endl;
    }

    return 0;
}
