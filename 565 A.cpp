#include <bits/stdc++.h>

using namespace std;

int main()
{
     long long n,q;
     cin >> q;
     while(--q >= 0)
     {
         bool p = true;
         cin >> n;
         long long fre = 0;
         while(n != 1)
         {
             if(n % 2 == 0)
                n /= 2;
             else if(n % 3 == 0)
             {
                 n /= 3;
                 n *= 2;
             }
             else if(n % 5 == 0)
             {
                 n /= 5;
                 n *= 4;
             }
             else
             {
                 p = false;
                 break;
             }
             ++fre;
         }
         if(p)
         cout << fre << '\n';
         else
            cout << -1 << '\n';
     }
    return 0;
}
