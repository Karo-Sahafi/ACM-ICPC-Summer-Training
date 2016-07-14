#include <bits/stdc++.h>

using namespace std;

vector<string> puzzle;
string _init;

void init(){
    puzzle.clear();
    puzzle.push_back(_init);
}

bool get_configuration(){
    cin.clear();
    char ch;
    bool error = false;
    pair<int , int> position , tmp;
    string str;

    for (int i = 1 ; i <= 5 ; i++){
        for (int j = 1 ; j <= 5 ; j++){
            if (puzzle[i][j] == ' '){
                position.first = i;
                position.second = j;
            }
        }
    }

    while (true){
        cin >> str;
        int l = str.length();

        for (int j = 0 ; j < l ; j++){
            ch = str[j];

            if (ch == '0'){
                return error;
            } else if (ch == 'A' && !error){
                if (puzzle[position.first - 1][position.second] == '*'){
                    error = true;
                } else {
                    tmp.first = position.first - 1;
                    tmp.second = position.second;

                    puzzle[position.first][position.second] = puzzle[tmp.first][tmp.second];
                    puzzle[tmp.first][tmp.second] = ' ';
                    position.first = tmp.first;
                    position.second = tmp.second;
                }

            } else if (ch == 'B' && !error){
                if (puzzle[position.first + 1][position.second] == '*'){
                    error = true;
                } else {
                    tmp.first = position.first + 1;
                    tmp.second = position.second;

                    puzzle[position.first][position.second] = puzzle[tmp.first][tmp.second];
                    puzzle[tmp.first][tmp.second] = ' ';
                    position.first = tmp.first;
                    position.second = tmp.second;
                }
            } else if (ch == 'R' && !error){
                if (puzzle[position.first][position.second + 1] == '*'){
                    error = true;
                } else {
                    tmp.first = position.first;
                    tmp.second = position.second + 1;

                    puzzle[position.first][position.second] = puzzle[tmp.first][tmp.second];
                    puzzle[tmp.first][tmp.second] = ' ';
                    position.first = tmp.first;
                    position.second = tmp.second;
                }
            } else if (ch == 'L' && !error){
                if (puzzle[position.first][position.second - 1] == '*'){
                    error = true;
                } else {
                    tmp.first = position.first;
                    tmp.second = position.second - 1;

                    puzzle[position.first][position.second] = puzzle[tmp.first][tmp.second];
                    puzzle[tmp.first][tmp.second] = ' ';
                    position.first = tmp.first;
                    position.second = tmp.second;
                }
            } else {
                error = true;
            }
        }
    }
}

void print(){
    for (int i = 1 ; i <= 5 ; i++){
        for (int j = 1 ; j <= 5 ; j++){
            if (j < 5)   cout << puzzle[i][j] << " ";
            else         cout << puzzle[i][j];
        }

        cout << endl;
    }
}

int main(){
    freopen("out.txt" , "w" , stdout);
    freopen("in.txt" , "r" , stdin);

    string str;
    int counter = 1;

    for (int i = 0 ; i < 10 ; i++){
        _init += '*';
    }

    while (true){
        init();
        bool result = false;

        for (int i = 0 ; i < 5 ; i++){
            getline(cin , str);

            if (str.length() == 1 && str[0] == 'Z'){
                return 0;
            }

            for (int i = str.length() ; i < 5; i++){
                str.append(" ");
            }

            puzzle.push_back('*' + str + '*');
        }

        puzzle.push_back(_init);
        result = get_configuration();

        cin.ignore();

        if (counter > 1){
            cout << endl;
        }

        cout << "Puzzle #" << counter << ":" << endl;

        if (result == true){
            cout << "This puzzle has no final configuration." << endl;
        } else {
            print();
        }

        counter++;
    }

    return 0;
}
