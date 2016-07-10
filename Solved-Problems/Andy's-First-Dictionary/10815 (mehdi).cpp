#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("out.txt" , "w" , stdout);
    //freopen("in.txt" , "r" , stdin);

    string str;
    set<string> my_set;
    set<string>::iterator it;

    while (getline(cin , str)){
        int l = str.length();
        string tmp;

        for (int i = 0 ; i <= l ; i++){
            if (isalpha(str[i])){
                tmp += tolower(str[i]);
            } else {
                if (tmp.length() > 0){
                    my_set.insert(tmp);
                }

                tmp.clear();
            }
        }
    }

    for (it = my_set.begin() ; it != my_set.end() ; ++it){
        cout << *it << endl;
    }

    return 0;
}
