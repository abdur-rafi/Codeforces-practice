#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> inp(n);
    for(int i = 0; i < n;++i)
        cin >> inp[i];
    vector<vector<int>> left(n),right(n);
    vector<pair<int,int>> seg(m);
    for(int i = 0; i < m;++i)
    {
        cin >> seg[i].first >> seg[i].second;
        seg[i].first--;
        seg[i].second--;
        left[seg[i].second].push_back(seg[i].first);
        right[seg[i].first].push_back(seg[i].second);
    }
    vector<int> add(n+1,0);
    vector<int> res(n,-1e9);
    int mn = inp[0];
    for(int i = 0; i < n;++i)
    {
        res[i] = max(res[i],inp[i]-mn);
        for(auto l : left[i])
        {
            for(int k = l; k <= i;++k)
            {
                add[k]--;
                mn = min(mn,inp[k]+add[k]);
            }
        }
        mn = min(mn,inp[i]+add[i]);
    }
    add = vector<int> (n+1,0);
    mn = inp[n-1];
    for(int i = n-1; i >= 0;--i)
    {
        res[i] = max(res[i],inp[i]-mn);
        for(auto l : right[i])
        {
            for(int k = l; k >= i;--k)
            {
                add[k]--;
                mn = min(mn,inp[k]+add[k]);
            }
        }
        mn = min(mn,inp[i]+add[i]);
    }
    int ans = *max_element(res.begin(),res.end());
    vector<int> s;
    for(int i = 0; i < n;++i)
    {
        if(res[i] == ans)
        {
            for(int j = 0; j < m;++j)
            {
                if(!(seg[j].first <= i && seg[j].second >= i))
                {
                    s.push_back(j);
                }
            }
            break;
        }
    }
    cout << ans << '\n';
    cout << s.size() << '\n';
    for(auto p : s)
        cout << p+1 << ' ';
}
