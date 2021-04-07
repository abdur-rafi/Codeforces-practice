#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;scanf("%d",&n);
    pair<ll,ll> a[n];
    for(int i=0;i<n;++i){
        ll b;scanf("%lld",&b);
        a[i].first = b;
    }
    for(int i=0;i<n;++i){
        ll b;scanf("%lld",&b);
        a[i].second = b;
    }
    sort(a,a+n);
    int i = 0;
    ll cost = 0 ;
    priority_queue<pair<ll,ll>> pq;
    while(i<n){
        int j = i;
        while(i+1<n && a[i].first == a[i+1].first) ++i;
        while(j<=i){
            pq.push({a[j].second,a[j].first});
            ++j;
        }
        ll curr = a[i].first;
        ll diff = INT_MAX;
        if(i+1<n) diff = a[i+1].first-a[i].first;
        while(diff && !pq.empty()){
            cost += (curr-pq.top().second)*pq.top().first;
            pq.pop();
            --diff;
            ++curr;
        }
        ++i;
    }
    printf("%lld\n",cost);
}
