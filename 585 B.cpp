#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n;
    scanf("%lld",&n);
    ll a[n];
    loop(i,n,0) scanf("%lld",a+i);
    ll pos=0,neg=0;
    if(a[0]<0) neg=1;
    else pos=1;
    ll rp=pos,rn=neg;
    loop(i,n,1){
        if(a[i]<0){
            ll t=pos;
            pos=neg;
            neg=t;
            neg++;
            rp+=pos;
            rn+=neg;
        }
        else{
            pos++;
            rp+=pos;
            rn+=neg;
        }

    }
    printf("%lld %lld",rn,rp);
    return 0;
}
