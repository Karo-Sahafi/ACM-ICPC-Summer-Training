#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
string init = "";
int direction[8][2] = { {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}};

void init_grid(){
    grid.clear();
    grid.push_back(init);
}

bool go(string in , int row , int col , int dir){
    int l = in.length();
    char ch;

    for (int i = 0 ; i < l ; i++){
        ch = grid[row + i * direction[dir][0]][col + i * direction[dir][1]];

        if (ch != in[i]){
            return false;
        }
    }

    return true;
}

string to_lower(string in){
    string tmp = "";

    for (int i = 0 ; i < in.length() ; i++){
        tmp += tolower(in[i]);
    }

    return tmp;
}

int main(){
    freopen("out.txt" , "w" , stdout);
    freopen("in.txt" , "r" , stdin);

    for (int i = 0 ; i < 60 ; i++){
        init += '-';
    }

    int T , m , n , k;
    string in , tmp;
    bool _find;

    cin >> T;

    while (T--){
        init_grid();

        cin >> m >> n;

        for (int i = 0 ; i < m ; i++){
            cin >> in;

            in = to_lower(in);
            grid.push_back('-' + in + '-');
        }

        grid.push_back(init);

        cin >> k;

        for (int i = 0 ; i < k ; i++){
            cin >> in;
            in = to_lower(in);

            _find = false;

            for (int r = 1 ; r < m + 2 && !_find ; r++){
                for (int c = 1 ; c < n + 2 && !_find ; c++){
                    if (grid[r][c] == in[0]){
                        for (int q = 0 ; q < 8 ; q++){
                            _find = go(in , r , c , q);

                            if (_find){
                                cout << r << " " << c << endl;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (T) cout << endl;
    }

    return 0;
}
