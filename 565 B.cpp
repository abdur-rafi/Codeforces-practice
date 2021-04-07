#include <bits/stdc++.h>

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
        int n;
        cin >> n;
        vector<int> a;
        int res = 0;
        int fre1 = 0;
        int fre2 = 0;
        loop(i,n,0)
        {
            int d;
            cin >> d;
            d %= 3;
            if(d == 1)
                ++fre1;
            else if(d == 2)
                ++fre2;
            else
                ++res;
        }
        int m = min(fre1,fre2);
        res += m;
        fre1 -= m;
        fre2 -= m;
        res += fre1/3;
        res += fre2/3;
        cout << res << '\n';
    }
    return 0;
}
