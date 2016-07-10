#include <bits/stdc++.h>

#define PAIR pair<int , int>

using namespace std;

double func (PAIR a , PAIR b , PAIR c){
    double area = 0.5 * ((c.second - a.second) * (b.first - a.first) - (b.second - a.second) * (c.first - a.first));

    return abs(area);
}

int main(){
    //freopen("out.txt" , "w" , stdout);
    //freopen("in.txt" , "r" , stdin);

    vector<pair<char , PAIR > > v;
    int n , a , b;
    char ch;
    double max_area = 0 , area;

    while(true){
        max_area = 0;
        string str;

        cin >> n;

        if (n == 0){
            return 0;
        }

        v.clear();

        while (n--){
            cin >> ch >> a >> b;
            v.push_back(make_pair(ch , make_pair(a , b)));
        }

        int l = v.size();

        for (int i = 0 ; i < l ; i++){
            for (int j = i + 1 ; j < l ; j++){
                for (int k = j + 1 ; k < l ; k++){
                    area = func(v[i].second , v[j].second , v[k].second);

                    if (area > max_area){
                        double test;
                        bool check = false;

                        for (int m = 0 ; m < l ; m++){
                            if (m == i || m == j || m == k){
                                continue;
                            }

                            test = func(v[i].second , v[j].second , v[m].second) + func(v[i].second , v[k].second , v[m].second) + func(v[j].second , v[k].second , v[m].second);

                            if (test == area){
                                check = true;
                                break;
                            }
                        }

                        if (check == false){
                            max_area = area;

                            str = (i + 'A');
                            str += (j + 'A');
                            str += (k + 'A');
                        }
                    }
                }
            }
        }

        cout << str << endl;
    }

    return 0;
}
