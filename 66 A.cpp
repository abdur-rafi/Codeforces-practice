#include <iostream>

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
    int t;
    cin >> t;
    while(--t >= 0)
    {
        ll n,k;
        cin >> n >> k;
        ll fre = 0;
        while(n)
        {
            if(n % k == 0)
            {
                n /= k;
                ++fre;
            }
            else
            {
                fre += n % k;
                n -= n%k;
            }
        }
        cout << fre << '\n';
    }
}
