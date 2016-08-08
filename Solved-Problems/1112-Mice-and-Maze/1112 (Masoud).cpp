#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("inp","r",stdin);
#endif
    int t, n, e, time, m, from, to, w;
    int matrix[100][100];
    cin >> t;
    while(t--){
        cin >> n >> e >> time >> m;
        for(int i = 0; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                matrix[i][j] = (i == j) ? 0 : INT_MAX;
        for(int i = 0 ; i < m ; i++){
            cin >> from >> to >> w;
            matrix[from - 1][to - 1] = w;
        }
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0; j < n ; j++)
                    if( matrix[i][k] != INT_MAX &&  matrix[k][j] != INT_MAX)
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        int count = 0;
        for(int i = 0 ; i < n ; i++)
            if(matrix[i][e - 1] <= time)
                count++;
        cout << count << endl;
        if(t != 0)
            cout << endl;
    }
    return 0;
}
