#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(cin >> n)
    {
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;

        bool    qb = true,
                sb = true,
                pqb = true;

        int command, number;
        while(n --)
        {
            cin >> command >> number;

            if(command == 1)
            {
                q.push(number);
                s.push(number);
                pq.push(number);
            }
            else
            {
                int qr,sr,pqr;

                if(q.empty())
                    qb = false;
                if(qb){
                    qr = q.front();
                    q.pop();
                    if(qr != number)
                        qb = false;
                }

                if(s.empty())
                    sb = false;
                if(sb){
                    sr = s.top();
                    s.pop();
                    if(sr != number)
                        sb = false;
                }

                if(pq.empty())
                    pqb = false;
                if(pqb){
                    pqr = pq.top();
                    pq.pop();
                    if(pqr != number)
                        pqb = false;
                }
            }
        }
        if(qb && !sb && !pqb)
            cout << "queue";
        else if(!qb && sb && !pqb)
            cout << "stack";
        else if(!qb && !sb && pqb)
            cout << "priority queue";
        else if(!qb && !sb && !pqb)
            cout << "impossible";
        else
            cout << "not sure";

        cout << endl;
    }
    return 0;
}
