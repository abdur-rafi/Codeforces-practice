#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;scanf("%lld",&t);
    while(--t>=0){
        ll n,m;scanf("%lld %lld",&n,&m);
        ll a[n];
        for(ll i=0;i<n;++i) scanf("%lld",a+i);
        ll b[m];
        for(ll i=0;i<m;++i) scanf("%lld",b+i);
        ll vis[n+1];
        for(ll i=0;i<=n;++i) vis[i] = 0;
        ll cost = 0;
        ll i = 0;
        ll j = 0;
        while(i<m){
            while(a[j] != b[i]){
                vis[a[j]] = 1;
                j++;
            }
            vis[a[j]] = 1;
            cost += 2*(j-i)+1;
            while(i+1<m && vis[b[i+1]]){
                cost++;
                i++;
            }
            ++i;
        }
        printf("%lld\n",cost);
    }
}

