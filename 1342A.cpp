#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(--t>=0){
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        ll res = 0;
        if(2*a<=b){
            res = (x+y)*a;
        }
        else{
             ll d = min(x,y);
             res = b*d;
             x -= d;
             y -= d;
             res += a*(x+y);
        }
        cout<<res<<"\n";
    }
}
