 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n,k;scanf("%lld %lld",&n,&k);
    ll a[n];
    loop(i,n,0) scanf("%lld",a+i);
    sort(a,a+n);
    ll c=a[n/2];
    ll f=1;
    bool comp=true;
    for(ll i=n/2+1;i<n;++i){
        ll diff=(a[i]-c)*f;
        if(diff <= k){
            k-=diff;
            c=a[i];
            ++f;
        }
        else{
            break;
        }
    }
    c += k/f;
    printf("%lld",c);
    return 0;
}
