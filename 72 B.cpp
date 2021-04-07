 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
ll bs(ll val,ll mx,ll mx1){
    ll i=1,j=1e9;
    ll m;
    while(i<=j){
        m=(i+j)>>1;
        ll d=(m-1)*mx1+mx;
        if(d<val) i=m+1;
        else j=m-1;
    }
    return j+1;
}
int main(){
    ll t;scanf("%lld",&t);
    while(--t>=0){
        ll n,x;scanf("%lld %lld",&n,&x);
        pair<ll,ll> blow[n];
        bool z=false;
        ll mx=-1;
        loop(i,n,0){
            scanf("%lld %lld",&blow[i].first,&blow[i].second);
            if(blow[i].first>=x) z=true;
            mx=max(mx,blow[i].first);
        }
        if(z){
            printf("1\n");
            continue;
        }
        ll mx1=-1;
        loop(i,n,0){
            if(blow[i].first-blow[i].second > mx1){
                mx1 = blow[i].first-blow[i].second;
            }
        }
        if(mx1<=0){
            printf("-1\n");
            continue;
        }
        ll d=bs(x,mx,mx1);
        while((d-2)*mx1+mx > x) --d;
        printf("%lld\n",d);
    }
    return 0;
}
