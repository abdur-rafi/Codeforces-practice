#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n;scanf("%lld",&n);
    int a[n];
    loop(i,n,0){
        scanf("%lld",a+i);
    }
    ll res=1e10;
    loop(i,n,0){
        ll mp=a[i];
        ll curr=0;
        loop(j,n,0){
            if(j == i) continue;
            if(abs(mp-a[j])%2==1) ++curr;
        }
        res=min(res,curr);
    }
    printf("%lld",res);
    return 0;
}
