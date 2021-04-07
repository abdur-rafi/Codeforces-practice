#include <bits/stdc++.h>

using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
ll minll(ll a, ll b){
return (a>b)? b:a;
}
int main()
{
    ll x,y,z;
    cin >> x >> y >> z;
    ll res = (x / z) + (y / z);
    x %= z;
    y %= z;
    if(x+y < z)
    {
        cout <<res << ' ' << 0;
        return 0;
    }
    ll m = z+1;
    m = minll(z-x,z-y);
    cout << res+1 << ' ' << m;
}
