#include <bits/stdc++.h>
using namespace std;
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        ll n,m;scanf("%lld %lld",&n,&m);
        ll res = ((n/2)*m)+(n%2)*(m/2+m%2);
        printf("%lld\n",res);
    }
    return 0;
}
