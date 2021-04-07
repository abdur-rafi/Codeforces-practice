#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
const long long M = 4294967295;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
#define inp(x) cin >> x
#define VI vector<int>
#define V vector

int main()
{
    int l;
    cin >> l;
    ll x = 0;
    ll cash2 = 1;
    int lv = 0;
    stack<int> s2;
    cin >> ws;
    while(--l >= 0)
    {
        string s;
        cin >> ws;
        cin >> s;
        if(s == "for")
        {
            int d;
            cin >> ws;
            cin >> d;
            cash2 *= d;
            s2.push(d);
        }
        else if( s == "add")
        {
            if(cash2 > M)
            {
                cout << "OVERFLOW!!!";
                return 0;
            }
            x += cash2;
            if(x > M)
            {
                cout << "OVERFLOW!!!";
                return 0;
            }
        }
        else if(s == "end")
        {
            cash2 /= s2.top();
            s2.pop();
        }
    }

    cout << x ;
}
