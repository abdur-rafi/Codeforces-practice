#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll q;scanf("%lld",&q);
    loop(i,q,0){
        ll n,m;
        scanf("%lld %lld",&n,&m);
        ll a[10];
        ll s=0;
        for(int i=0;i<10;++i){
            a[i]=(m*(i+1))%10;
            s+=a[i];
        }
        ll p=n/m;
        ll res=(p/10)*s;
        p %=10;
        for(int i=0;i<p;++i) res+=a[i];
        printf("%lld\n",res);
    }
    return 0;
}
