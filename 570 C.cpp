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
ll minll(ll a, ll b){
    return (a<b)?a:b;
}
int main(){
    ll q;cin >> q;
    while(--q>=0){
        ll k,n,a,b;cin>>k>>n>>a>>b;
        ll r=maxll(0,k-a);
        ll res;
        ll t=r/a;
        if(r%a!=0)++t;
        res=t;
        k-=t*a;
        ll r2=maxll(0,k-b);
        t+=r2/b;
        if(r2%b!=0)++t;
        if(t>=n)cout<<minll(n,res)<<'\n';
        else cout << -1 << '\n';
    }
    return 0;
}

