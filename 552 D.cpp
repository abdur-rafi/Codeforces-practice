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
    int n,b,a;
    cin >> n >> b >> a;
    int a1 = a, b1 = b;
    int res = 0;
    loop(i,n,0)
    {
        if(a == 0 && b == 0)
            break;
        int e;
        cin >> e;
        if(e == 0)
        {
            if(a)
                --a;
            else if(b)
                --b;
            else
                break;
        }
        else
        {
            if(a == a1)
            {
                --a;
            }
            else if(b > 0)
            {
                --b;
                ++a;
            }
            else if(a)
                --a;
            else
                break;
        }
        ++res;
    }
    cout << res;
}
