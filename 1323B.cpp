#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,k;scanf("%lld %lld %lld",&n,&m,&k);
    ll a[n],b[m];
    for(int i=0;i<n;++i) scanf("%lld",a+i);
    for(int i=0;i<m;++i) scanf("%lld",b+i);
    vector<pair<ll,ll>> afr,bfr;
    int fre[max(n,m)+100];
    for(int i=1;i<=n;++i) fre[i] = 0;
    int s = 0;
    for(int i=0;i<n;++i){
        if(a[i]) ++s;
        else{
            fre[s]++;
            s = 0;
        }
    }
    fre[s]++;
    ll mx = 0;
    for(ll i=1;i<=n;++i){
        if(fre[i]){
            afr.push_back({i,fre[i]});
            mx = max(mx,i);
        }
    }
    for(int i=1;i<=m;++i) fre[i] = 0;
    s = 0;
    for(int i=0;i<m;++i){
        if(b[i]) ++s;
        else{
            fre[s]++;
            s = 0;
        }
    }
    fre[s]++;
    for(ll i=1;i<=m;++i){
        if(fre[i]){
            bfr.push_back({i,fre[i]});
            mx = max(mx,i);
        }
    }
    vector<ll> div;
    for(ll i=1; i*i<=k && i<=mx;++i){
        if(k%i== 0 &&k/i <= mx) div.push_back(i);
    }
 //   cout<<"mx: "<<mx<<"\n";
 //   for(auto d:div) cout<<d<<" ";
    ll res = 0;
    for(int i=0;i<afr.size();++i){
        for(int j=0;j<bfr.size();++j){
            ll curr = 0;
            ll width = bfr[j].first;
            ll height = afr[i].first;
            for(int i=0;i<div.size();++i){
                ll a = div[i];
                ll b = k/div[i];
                ll frw = max(0LL,width-b+1);
                ll frh = max(0LL,height-a+1);
                curr += frw*frh;
                if(a == b) continue;
                frw = max(0LL,width-a+1);
                frh = max(0LL,height-b+1);
                curr += frw*frh;
            }
            res += curr*afr[i].second*bfr[j].second;
        }
    }
    printf("%lld\n",res);
}
