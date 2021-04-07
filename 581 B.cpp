#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n,l,r;scanf("%lld %lld %lld",&n,&l,&r);
    ll mn=0;
    ll p=1;
    for(ll i=0;i<l;++i){
        mn += p;
        p*=2;
    }
    mn += n-l;
    ll mx=0;
    p=1;
    for(ll i=0;i<r;++i){
        mx+=p;
        p*=2;
    }
    mx += (n-r)*(p/2);
    printf("%lld %lld",mn,mx);
    return 0;
}
