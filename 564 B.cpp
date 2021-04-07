#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = 0;
    for(int i = 1; i <= n;++i)
    {
        int a = 2*i - 1;
        if(a >= n)
        {
            m = i;
            break;
        }
    }
    cout << m << '\n';
    for(int i = 1; i <= m && i <= n;++i)
    {
        cout << 1 << ' ' << i << '\n';
    }
    n -= m;
    for(int i = 0; i < n;++i)
    {
        cout << i+2 << ' ' << m << '\n';
    }
}
