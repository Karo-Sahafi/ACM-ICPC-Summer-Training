#include <bits/stdc++.h>
using namespace std;
const int maxn=205;
vector<string> dic;
vector<int> graph[maxn];
int n=0;
int bfs(int a,int b);
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
#endif
    int num;
    cin>>num;
    while(num--)
    { dic.clear();
      for(int i=0 ; i<maxn ;i++)graph[i].clear();
        while(true)
        {
            string word;
            cin>>word;
            if(word=="*")break;
            dic.push_back(word);
        }


        for(int i=0 ; i<dic.size() ; i++ )
        {
            for(int j=i+1 ; j<dic.size() ; j++ )
            {
                if(dic[i].size() == dic[j].size() )
                {
                    int cnt=0;
                    bool e=true;
                    for(int k=0 ; k<dic[j].size() ; k++ )
                    {
                        if(dic[i][k] != dic[j][k])cnt++;
                        if(cnt>1)
                        {
                            e=false;
                            break;
                        }
                    }
                    if(e)
                    {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
        }
        n=dic.size();


        string a,b;
        cin.ignore();
         while(true){
            string s;

            getline(cin,s);
            if(s == ""){
                if(cin.peek()>0)
                cout << endl;
                break;
            }

            string a,b;
            stringstream myStream(s);
            myStream >> a;
            myStream >> b;


            int a1,b1;
            for(int i=0; i<dic.size() ; i++)
            {
                if(dic[i]==a)a1=i;
                if(dic[i]==b)b1=i;
            }
            int min_path=bfs(a1,b1);
            cout<<a<<" "<<b<<" ";
            cout<<min_path<<endl;
        }

    }
    return 0;
}
int bfs(int a,int b)
{
    if(a==b)return 0 ;
    int space[n];
    fill_n(space , n , 0);
    queue<int> myqueue;
    bool mark[n];
    fill_n(mark , n , 0 );
    myqueue.push(a);
    mark[a]=true;
    int v;

    while (myqueue.size())
    {

        v=myqueue.front();
        myqueue.pop();

        for(int i=0 ; i<graph[v].size() ; i++ )
        {
            int u=graph[v][i];

            if(mark[u])continue;
            space[u]=space[v]+1;
            if(u==b) return space[u];

            mark[u]=true;
            myqueue.push(u);
        }

    }


}
