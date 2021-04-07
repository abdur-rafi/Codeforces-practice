#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
ll maxll(ll a,ll b){
    return (a>b)?a:b;
}
int main(){
    ll q;cin >> q;
    while(--q >= 0){
        ll n;cin>>n;
        map<ll,ll> m;
        loop(i,n,0){
            ll d;
            cin >> d;
            m[d]++;
        }
        vector<ll> a;
        vector<ll>b;
        for(auto p:m){
            a.push_back(p.second);
        }
        sort(a.begin(),a.end());
    /*    for(auto p : a)
            cout << p << ' ';
        cout <<'\n';*/
        ll res=0;
        b=a;
        ll mn=a[a.size()-1];
        res +=mn;
        for(int i = a.size()-2;i >= 0;--i){
            if(a[i]>=mn){
                res+=maxll(mn-1,0);
                --mn;
            }
            else{
                res += a[i];
                mn=a[i];
            }
        }
     /*   for(auto p:a)
            cout <<p << ' ';
        cout<< '\n';*/
        cout <<res<< '\n';
    }
}
