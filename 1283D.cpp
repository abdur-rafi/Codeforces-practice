#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;scanf("%lld %lld",&n,&m);
    ll a[n];
    for(int i=0;i<n;++i) scanf("%lld",a+i);
    map<ll,ll> index;
    for(int i=0;i<n;++i) index[a[i]] = i;

    sort(a,a+n);
    vector<pair<ll,ll>> diff;
    vector<ll> res[n];
    for(int i=0;i+1<n;++i){
        if(a[i+1]-a[i])
            diff.push_back({a[i+1]-a[i]-1,a[i]});
    }
    ll pre = 0;
    ll cost = 0;
    sort(diff.begin(),diff.end());
    for(ll i=1;i<=m;++i){
        ll bound = 2*i-1;
        while(pre<diff.size() && diff[pre].first<bound){
            ++pre;
        }
        for(int j=pre;j<diff.size();++j){
            if(!m) break;
            res[index[diff[j].second]].push_back(diff[j].second+i);
            cost += i;
            --m;
            if(diff[j].first > bound && m ){
                res[index[diff[j].second+diff[j].first+1]].push_back(diff[j].second+diff[j].first-i+1);
                --m;
                cost += i;
            }
        }
        if(!m) break;
        res[index[a[0]]].push_back(a[0]-i);
        --m;
        cost += i;
        if(m){
            res[index[a[n-1]]].push_back(a[n-1]+i);
            --m;
            cost += i;
        }
        if(!m) break;
    }
    printf("%lld\n",cost);
    for(int i=0;i<n;++i){

        for(auto p:res[i]) printf("%lld ",p);
    }
}
