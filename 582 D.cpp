#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
ll mp[1000000];
ll fre[1000000];
int main(){
    ll n,k;scanf("%lld %lld",&n,&k);
    ll a[n];
    loop(i,n,0) scanf("%lld",a+i);
    sort(a,a+n);
    loop(i,1000000,0){
        mp[i]=0;
        fre[i]=0;
    }

    loop(i,n,0){
        ll b=a[i];
        ll c=0;
        while(b){
            if(fre[b]<k){
                fre[b]++;
                mp[b]+=c;
            }
            b/=2;
            c++;
        }
        if(fre[b]<k){
            fre[b]++;
            mp[b]+=c;
        }
    }
    ll res=1e12;
    loop(i,1000000,0){
        if(fre[i]>=k){
            res=min(res,mp[i]);
        }
    }
    printf("%lld",res);
    return 0;
}
