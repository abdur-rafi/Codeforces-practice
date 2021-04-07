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

        }
        ll c=0;
        ll res=0;
        for(auto p:m){
            c += p.second;
            res=maxll(res,c);
        }
        cout<<res<<'\n';
        if(c==0)c=-1;
    }
    return 0;
}

