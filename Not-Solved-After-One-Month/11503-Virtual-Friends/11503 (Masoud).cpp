#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
//    freopen("inp", "r", stdin);
    map<string, int> groupID;
    map<int,set<string>> groups;
    int n, t, idx, tidx;
    string f1, f2;
    cin >> t;
    while(t--){
        cin >> n;
        groups.clear();
        groupID.clear();
        idx = 1;
        while(n--){
            cin >> f1 >> f2;
            if(groupID[f1] == 0 && groupID[f2] == 0){
               groupID[f1] = idx;
               groupID[f2] = idx;
               groups[idx].insert(f1);
               groups[idx].insert(f2);
               tidx = idx++;
            }
            else if(groupID[f1] != 0 && groupID[f2] == 0){
                groupID[f2] = groupID[f1];
                groups[groupID[f1]].insert(f2);
                tidx = groupID[f1];
            }
            else if(groupID[f1] == 0 && groupID[f2] != 0){
                groupID[f1] = groupID[f2];
                groups[groupID[f2]].insert(f1);
                tidx = groupID[f2];
            }
            else if(groupID[f1] != groupID[f2]){
                for(auto v : groups[groupID[f2]]){
                    groups[groupID[f1]].insert(v);
                    groupID[v] = groupID[f1];
                }
                tidx = groupID[f1];
            }
            else
                tidx = groupID[f1];
            cout << groups[tidx].size() << endl;
        }
    }
    return 0;
}
