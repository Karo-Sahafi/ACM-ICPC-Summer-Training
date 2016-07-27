#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
#endif
    int m, n, idx, c = 1;
    bool used[25], matrix[25][25];
    vector<string> names;
    map<string, int> nameIdx;
    string from, to;
    while (true) {
        cin >> n >> m;
        if(!n)
            break;
        if(c > 1)
            cout << endl;
        cout << "Calling circles for data set " << c++ << ":" << endl;
        names.clear();
        nameIdx.clear();
        for(int i = 0 ; i < n ; i++){
            used[i] = false;
            for(int j = 0 ; j < n ; j++)
                matrix[i][j] = false;
        }
        idx = 0;
        for(int i = 0 ; i < m ; i++){
            cin >> from >> to;
            if(nameIdx[from] == 0){
                names.push_back(from);
                nameIdx[from] = ++idx;
            }
            if(nameIdx[to] == 0){
                names.push_back(to);
                nameIdx[to] = ++idx;
            }
            matrix[nameIdx[from]-1][nameIdx[to]-1] = true;
        }
        for(int i = 0; i < n ; i++)
            for( int j = 0 ; j < n ; j++)
                for( int k = 0 ; k < n ; k++)
                    if( matrix[j][i] && matrix[i][k])
                        matrix[j][k] = true;
        for(int i = 0 ; i < n ; i++){
            if(used[i])
                continue;
            cout << names[i];
            for(int j = 0 ; j < n ; j++){
                if(i == j || !matrix[i][j] || !matrix[j][i])
                    continue;
                used[j] = true;
                cout << ", " << names[j];
            }
            cout << endl;
        }
    }
    return 0;
}
