#include <bits/stdc++.h>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
#define inp(x) cin >> x
#define VI vector<int>
#define V vector
vector<int> odd;
vector<int> even;
void bfs(vector<vector<int>> adj,int n)
{
    odd.clear();
    even.clear();
    int l = 1;
    vector<bool> vis(n+1,false);
    vis[1] = true;
    queue<int> q;
    q.push(1);
    q.push(-1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == -1)
        {
            ++l;
            if(!q.empty())
                q.push(-1);
            continue;
        }
        if(l % 2 == 0)
            even.push_back(u);
        else
            odd.push_back(u);
        for(auto d : adj[u])
        {
            if(!vis[d])
            {
                vis[d] = true;
                q.push(d);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(--t >= 0)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        loop(i,m,0)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs(adj,n);
        if(odd.size() < even.size())
        {
            cout << odd.size() << '\n';
            for(auto d : odd)
                cout << d << ' ';
            cout << '\n';
        }
        else
        {
            cout << even.size() << '\n';
            for(auto d : even)
                cout << d << ' ';
            cout << '\n';
        }
    }
}
