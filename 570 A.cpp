#include <iostream>
#include <map>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
ll maxll(ll a,ll b){
    return (a>b)?a:b;
}
int main(){
    ll q;
    cin >> q;
    while(--q >= 0){
        map<ll,ll> m;
        ll n,k;cin >> n >> k;
        loop(i,n,0){
            ll a;cin >> a;
            ll f,s;
            f = maxll(1,a-k);
            s = a+k;
            m[f]++;
            m[s+1]--;
        }
        ll c=0;
        ll res=0;
        ll res2=-1;
        for(auto p:m){
            if(c==res)res2=p.first;
            c += p.second;
            res=maxll(res,c);
        }
        if(res!=n)res2=0;
        cout <<res2-1<<'\n';
    }
    return 0;
}
