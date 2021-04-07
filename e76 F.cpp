#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
map<vector<ll>,ll> m;
const ll sh = 15;
int main() {
    ll n;scanf("%lld",&n);
    ll inp[n];
    for(ll i=0;i<n;++i){
        scanf("%lld",inp+i);
    }
    for(ll i = 0; i < (1<<15); ++i){
        vector<ll> v(n);
        for(ll j = 0;j < n;++j){
            ll d = 0;
            d = ~d;
            d = d << sh;
            d = ~d;
            d = d & inp[j];
        //    printf("d:%lld\n",d);
            v[j] = __builtin_popcountll(d ^ i);
        }
        vector<ll> v2(n-1);
        for(int j = 1;j<n;++j){
            v2[j-1] = v[j]-v[0];
        }
        m[v2]=i+1;
    }
    ll res=-1;
    for(ll i =0;i<(1<<15);++i){
        vector<ll> v(n);
        for(ll j =0;j<n;++j){
            ll d = 0;
            d = ~d;
            d = d << 15;
            d = ~d;
            d = d << 15;
            d = d & inp[j];
       //     printf("d:%lld\n",d);
            v[j] = __builtin_popcountll(d^(i<<15));
        }
        vector<ll> v2(n-1);
        for(ll j=1;j<n;++j){
            v2[j-1] = v[0] - v[j];
        }
        if(m[v2] != 0){
            res = m[v2]-1+(i<<15);
            break;
        }

    }
    printf("%lld\n",res);
    return 0;
}
