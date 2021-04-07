 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll t;cin>>t;
    while(--t>=0){
        ll str,intel,exp;cin>>str>>intel>>exp;
        ll x=(intel-str+exp)/2;
        if(str+x<=intel+exp-x) ++x;
        if(x<0){
            cout<<exp+1<<'\n';
            continue;
        }
        cout<<max((ll)0,exp-x+1)<<'\n';
    }
    return 0;
}
