#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
bool comp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
ll ub(ll a[],ll val,ll n,bool lb){
    ll i=0,j=n-1,m;
    while(i<=j){
        m=(i+j)>>1;
        if(a[m]<val) i=m+1;
        else j=m-1;
    }
    if(lb) return i-1;
    return j+1;
}

int main(){
    ll n,m,k,q;scanf("%lld %lld %lld %lld",&n,&m,&k,&q);
    pair<ll,ll> pairs[k];
    loop(i,k,0) scanf("%lld %lld",&pairs[i].first,&pairs[i].second);
    sort(pairs,pairs+k,comp);
    ll safe_columns[q];
    loop(i,q,0) scanf("%lld",safe_columns+i);
    pair<ll,ll> curr={1,1};
    ll res=0;
  /*  for(int i=0;i<k;++i){
        printf("pairs:%lld %lld\n",pairs[i].first,pairs[i].second);
    }*/
    sort(safe_columns,safe_columns+q);
  //  loop(i,q,0) printf("%lld\n",safe_columns[i]);
    for(int i=0;i<k;++i){
        if(pairs[i].first==curr.first){
            res += abs(pairs[i].second-curr.second);
            curr.second=pairs[i].second;
        }
        else{
            ll a,b;
            a=ub(safe_columns,curr.second,q,0);
            b=ub(safe_columns,curr.second,q,1);
            printf("%lld %lld\n",a,b);
            ll c=(1e18);
            ll ind;
            if(a<q){
                ll fre=0;
                fre=abs(curr.second-safe_columns[a])+abs(pairs[i].second-safe_columns[a]);
                c=min(c,fre);
            }
            if(b>-1){
                ll fre=0;
                fre=abs(curr.second-safe_columns[b])+abs(pairs[i].second-safe_columns[b]);
                c=min(fre,c);
            }
            a=ub(safe_columns,pairs[i].second,q,0);
            b=ub(safe_columns,pairs[i].second,q,1);
            printf("%lld %lld\n",a,b);
            if(a<q){
                ll fre=0;
                fre=abs(curr.second-safe_columns[a])+abs(pairs[i].second-safe_columns[a]);
                c=min(c,fre);
            }
            if(b>-1){
                ll fre=0;
                fre=abs(curr.second-safe_columns[b])+abs(pairs[i].second-safe_columns[b]);
                c=min(fre,c);
            }
            res += c+abs(curr.first-pairs[i].first);
            curr=pairs[i];
        }
    }
    printf("%lld",res);
    return 0;
}
