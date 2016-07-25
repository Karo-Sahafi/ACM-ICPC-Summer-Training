#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=10000*200;
vector<int> graph[maxn];
vector<int> graph_back[maxn];
vector<string> name;
stack<int> stack_;
vector<int> print;
bool used[maxn];
void input(int m);
void find_comps();
void dfs(int a);
void dfs_back(int a);
int main()
{

#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int m,num=0;
    while(true)
    {

        num++;
        cin>>n>>m;
        name.clear();
        for(int i=0; i<n ; i++)
        {
            graph[i].clear();
            graph_back[i].clear();
        }
        while (stack_.size())
        {
            stack_.pop();
        }
        if(n==0 && m==0)
            return 0;
        if(num != 1) cout<<endl;
        input(m);
        cout<<"Calling circles for data set "<<num<<":"<<endl;
        find_comps();

    }
}
void find_comps()
{
    fill_n(used,n,0);
    for(int i=0 ; i<n ; i++)
    {
        if(!used[i])
        {
            dfs(i);
        }
    }
    fill_n(used,n,0);
    while (stack_.size())
    {
        if(!used[stack_.top()])
        {
            dfs_back(stack_.top());
            for(int i=0; i<print.size(); i++)
            {
                if(i!=0)cout<<", ";
                cout<<name[print[i]];
            }
            cout<<endl;
            print.clear();
        }
        stack_.pop();
    }

}
void dfs(int a)
{
    used[a]=true;
    for(int i=0 ; i<graph[a].size() ; i++)
    {
        if(!used[graph[a][i]])
        {
            dfs(graph[a][i]);
        }
    }
    stack_.push(a);
    return ;
}
void dfs_back(int a)
{
    used[a]=true;
    print.push_back(a);
    for(int i=0; i<graph_back[a].size() ; i++)
    {
        if(!used[graph_back[a][i]])
        {
            dfs_back(graph_back[a][i]);
        }
    }

}
void input(int m)
{

    for(int i=0 ; i<m ; i++)
    {
        string a,b;
        bool e=false,f=false;
        cin>>a>>b;
        for(int k=0 ; k<name.size() ; k++)
        {
            if(name[k] == a )
                e=true;
            if(name[k] == b )
                f=true;
        }
        if(!e)
            name.push_back(a);
        if(!f)
            name.push_back(b);
        int name_1,name_2;
        for(int k=0 ; k<name.size() ; k++)
        {
            if(name[k]==a)
                name_1=k;
            if(name[k]==b)
                name_2=k;
        }
        graph_back[name_2].push_back(name_1);
        graph[name_1].push_back(name_2);
    }
    return ;
}
