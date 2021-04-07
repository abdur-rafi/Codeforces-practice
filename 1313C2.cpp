#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 500000+10;
ll a[MAX];
ll n;
void next_lesser_element(vector<ll> &ls){
    stack<pair<ll,ll>> s;
    s.push({a[n-1],n-1});
    for(ll i=n-2;i>=0;--i){
        while(!s.empty() && s.top().first>a[i]){
            ls[s.top().second] = i;
            s.pop();
        }
        s.push({a[i],i});
    }
    while(!s.empty()){
        ls[s.top().second] = -1;
        s.pop();
    }
}

void increasing(vector<ll> &inc_right,vector<pair<ll,ll>> &rcr){
    vector<ll> ls_right(n);
    next_lesser_element(ls_right);
    inc_right[0] = a[0];
    rcr[0] = {a[0],0};
    for(ll i=1;i<n;++i){
        if(a[i]>=a[i-1]){
            inc_right[i] = inc_right[i-1]+a[i];
            rcr[i] = {a[i],i};
        }
        else{
            ll id = ls_right[i];
            if(id == -1){
                inc_right[i] = a[i]*(i+1);
                rcr[i] = {a[i],0};
            }
            else{
                inc_right[i] = inc_right[id]+(i-id)*a[i];
                rcr[i] = {a[i],id+1};
            }
        }
     //   printf("inc_[%d]:%d\n",i,inc_right[i]);

    }
}
void build(vector<pair<ll,ll>> &lcr,ll b){
    for(ll i=b;i>=0;){
        for(ll j = i;j>=lcr[i].second;--j){
            lcr[j].first = lcr[i].first;
        }
        i = lcr[i].second-1;
    }
}

int main(){
    scanf("%lld",&n);
    for(ll i=0;i<n;++i) scanf("%lld",a+i);
    vector<ll> right(n),left(n);
    vector<pair<ll,ll>> rcr(n),lcr(n);
    increasing(right,rcr);
    reverse(a,a+n);
    increasing(left,lcr);
    reverse(a,a+n);
    ll res = 0;
    ll resId = 0;
    reverse(left.begin(),left.end());

    for(ll i=0;i<n;++i){
        ll curr = left[i]+right[i]-a[i];
        if(curr>res){
            res = curr;
            resId = i;
        }
    }
    build(rcr,resId);
    build(lcr,n-resId-1);
    for(ll i=0;i<=resId;++i){
        printf("%lld ",rcr[i].first);
    }
    for(ll i=n-resId-2;i>=0;--i){
        printf("%lld ",lcr[i].first);
    }
  //  increasing(left);

}
