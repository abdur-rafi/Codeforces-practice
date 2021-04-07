#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll q;cin>>q;
    while(--q>=0){
        ll n,k;cin>>n>>k;
        ll a[n];
        loop(i,n,0) cin>>a[i];
        vector<int> res;
        int oc=0;
        int i;
        for(i=0;i<n;++i){
            if(k==1) break;
            if(a[i]%2)++oc;
            if(oc){
                oc=0;
                res.push_back(i+1);
                --k;
            }
        }
        oc=0;
        while(i<n){
            if(a[i]%2) ++oc;
            ++i;
        }
        if(i==n&&k==1&&(oc%2==1)){
            cout<<"YES\n";
            for(auto p:res) cout<<p<<' ';
            cout<<n;
            cout<<'\n';
        }
        else cout<<"NO\n";
    }
    return 0;
}
