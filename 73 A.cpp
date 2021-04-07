#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll q;scanf("%lld",&q);
    for(int i=0;i<q;++i){
        ll n;scanf("%lld",&n);
        ll a[n];
        for(int i=0;i<n;++i) scanf("%lld",a+i);
        sort(a,a+n);
        map<ll,ll> m;
        set<ll> s;
        for(auto d:a){
            m[d]++;
            s.insert(d);
        }
        vector<ll> v;
        for(auto d:s) v.push_back(d);
        ll p=0;
        bool pos=false;
        for(int i=0;i<v.size();++i){
            ll curr=v[i];
            if(curr == 2048){
                pos=true;break;
            }
            ll fre=m[curr] + p;
            if(i+1<v.size()){
                while(curr != v[i+1] && fre){
                    fre/=2;
                    if(fre)
                    curr *= 2;
                    if(curr == 2048){
                        pos=true;
                        break;
                    }
                }
            }
            else{
                while(fre){
                    fre/=2;
                    if(fre)
                    curr*=2;
                    if(curr == 2048){
                        pos = true;break;
                    }
                }
            }
            p = fre;
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
}
