#include <iostream>
#include <vector>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
#define inp(x) cin >> x
#define VI vector<int>
#define V vector
int main()
{
    int n,m;
    cin >> n >> m;
    int a[n],seg[m][2];
    int mx = -1e9;
    int mn = 1e9;
    int res;
    loop(i,n,0)
    {
        cin >> a[i];
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    res = mx-mn;

    loop(i,m,0)
    {
        cin >> seg[i][0] >> seg[i][1];
        --seg[i][0];
        --seg[i][1];
    }
    vector<int> r;
    loop(i,n,0)
    {
        vector<int> v(n+1);
        vector<int> curr;
        loop(j,m,0)
        {
            if(!(seg[j][0] <= i && seg[j][1] >= i))
            {
                curr.push_back(j);
                loop(k,seg[j][1]+1,seg[j][0])
                    --v[k];
            }
        }
            mx = -1e9;
            mn = 1e9;
            loop(i,n,0)
            {
                mx = max(mx,a[i]+v[i]);
                mn = min(mn,a[i]+v[i]);
            }
            if(res <= mx-mn)
            {
                res = mx-mn;
                r = curr;
            }


    }
    cout << res << '\n' << r.size() << '\n';
    for(auto p = r.begin(); p != r.end();++p)
        cout << *p+1 << ' ';
}
