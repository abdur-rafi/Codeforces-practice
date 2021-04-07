#include <bits/stdc++.h>

using namespace std;
int food[] = {0,1,2,0,2,1,0};
int mx(int a[],int b)
{
    int c = 0;
    int k = 0;
    while(k < 7)
    {
        int f = food[b];
        if(a[f])
        {
            ++c;
            a[f]--;
        }
        else
            break;
        ++k;
        ++b;
        if(b > 6)
            b %= 7;
    }
    return c;
}
int main()
{
    int a[3];
   // cin >> a[0] >> a[1] >> a[2];
   scanf("%d %d %d",&a[0],&a[1],&a[2]);
    int m = a[0];
    m = min(m,a[0]/3);
    m = min(m,a[1]/2);
    m = min(m,a[2]/2);
    a[0] -= m * 3;
    a[1] -= m * 2;
    a[2] -= m * 2;
    int M = -1;
    for(int i = 0; i < 7;++i)
    {
        int b[3];
        for(int j = 0; j < 3;++j)
            b[j] = a[j];
        M = max(M,mx(b,i));
    }
 //   cout << (m*7)+M << '\n';
 printf("%d",(m*7)+M);
}
