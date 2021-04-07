#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll t;scanf("%lld",&t);
    loop(i,t,0){
        ll n;scanf("%lld",&n);
        stack<ll> st;
        ll res=0;
        loop(i,n,0){
            ll a;scanf("%lld",&a);
            while(!st.empty() && st.top()>a){
                st.pop();++res;
            }
            st.push(a);
        }
        printf("%lld\n",res);
    }
    return 0;
}
