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
ll pow2[100];
vector<ll> res;
ll b_search(ll n,ll m,ll rem,ll index)
{
    ll i = 0;
    ll j = m;
    ll mid;
    while(i <= j)
    {
        mid = (i+j) >> 1;
        ll d = mid*pow2[n];
        if(d <= rem)
            i = mid+1;
        else
            j = mid-1;
    }
    if(i == 0)
        return 0;
    res[index] += (i-1);
    for(int j = 1; j <= n;++j  )
    {
        res[j+index] += pow2[j-1]*(i-1);
    }
    return pow2[n]*(i-1);
}

int main()
{
    ll q,a,b,m;
    cin >> q;
    pow2[0] = 1;
    for(int i = 1; i <= 55;++i)
    {
        pow2[i] = 2*pow2[i-1];
    }
    loop(i22,q,0)
    {
        res.clear();
        cin >> a >> b >> m;
        ll b1 = b;
        ll c = 0;
        if(b > m)
            b -= m;
        else if(a != b)
        {
            cout << 2 << ' ' << a <<  ' ' << b << '\n';
            continue;
        }
        else
        {
            cout << 1 << ' ' << a << '\n';
            continue;
        }
        for(int i = 0; i <= 55;++i)
        {
            ll d = pow2[i]*a+pow2[i]-1;
            if(d > b)
            {
                c = i-1;
                b -= (pow2[i-1]*a+pow2[i-1]-1);
                break;
            }
        }
        loop(i,c,0)
        {
            res.push_back(pow2[i]*a+pow2[i]);
        }
        loop(i,c,0)
        {
            b -= b_search(c-i-1,m-1,b,i);

        }
        if(b == 0)
        {
            cout << res.size()+2 << ' ';
            cout << a << ' ';
            for(int i = 0; i < c;++i)
                cout << res[i] << ' ';
            cout << b1 << '\n';
        }
        else
            cout << "-1\n";

    }
}
