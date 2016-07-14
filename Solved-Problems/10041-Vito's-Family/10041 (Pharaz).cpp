#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "rt", stdin);
    #endif // ONLINE_JUDGE
    map<int, int> numbers;
    int n, r;
    cin >> n;
    while(n--)
    {
        numbers.clear();
        cin >> r;
        int temp;
        for(int i = 0; i < r; i++)
        {
            cin >> temp;
            numbers[temp]++;
        }
        map<int, int>::iterator it = numbers.begin(), it2 = numbers.begin();
        int prev = 0, prevc = it->second, prevn = it->first;
        r -= it->second;
        for(it2++; it2 != numbers.end(); it2++)
        {
            prev += (it2->first - prevn) * it2->second;
        }
        it2 = numbers.begin();
        int ans = prev;
        for(it2++; it2 != numbers.end(); it2++)
        {
            r -= it2->second;
            prev = prev + (it2->first - prevn) * prevc - (it2->first - prevn) * r - (it2->first - prevn) * it2->second;
            prevc += it2->second;
            prevn = it2->first;
            if(prev < ans)
                ans = prev;
        }
        cout << ans << endl;
    }
    return 0;

}
