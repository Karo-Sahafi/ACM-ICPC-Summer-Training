#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    const int size = 150;
#ifndef ONLINE_JUDGE
    freopen("inp","r",stdin);
#endif
    int matrix[size][size], S[size][size], n, t, temp;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++){
                cin >> temp;
                matrix[i][j] = temp;
                matrix[i][j+n] = temp;
                matrix[i+n][j] = temp;
                matrix[i+n][j+n] = temp;
            }
        for(int i = 0 ; i < 2 * n ; i++)
            for( int j = 0 ; j < 2 * n ; j++){
                S[i][j] = matrix[i][j];
                if(i > 0)
                    S[i][j] += S[i-1][j];
                if(j > 0)
                    S[i][j] += S[i][j-1];
                if( i > 0 && j > 0)
                    S[i][j] -= S[i-1][j-1];
            }
        int max = matrix[0][0];
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                for(int k = i ; k < i + n ; k++)
                    for(int l = j ; l < j + n ; l++){
                        int s = S[k][l];
                        if(i > 0)
                            s -= S[i-1][l];
                        if(j > 0)
                            s -= S[k][j-1];
                        if(i > 0 && j > 0)
                            s += S[i-1][j-1];
                        if(s > max)
                            max = s;
                    }
        cout << max << endl;
    }
    return 0;
}
