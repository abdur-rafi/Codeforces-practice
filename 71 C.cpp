#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll t;cin>>t;
    while(--t>=0){
        ll n,a,b;cin>>n>>a>>b;
        string s;cin>>s;
        int i=0;
        ll res=0;
        while(i<n && s[i] !='1'){
            res+=a+b;
            ++i;
        }
        if(i<n){
            res +=a;
        }
        else{
            res+=b;
        }
    //    cout<<res<<'\n';
        while(i<n){
            while(i<n && s[i]=='1'){
                res+=a+2*b;
                ++i;
            }
            ll f=0;
            res+=2*b;
     //       cout<<res<<'\n';
            while(i<n && s[i]=='0'){
                ++i;
                ++f;
            }
        //    printf("f:%lld\n",f);
            if(i>=n){
                res += 2*a;
                res += f*b+(f-1)*a;
            }
            else{
                ll g=(f-1)*2*b;
                g += f*a;
                ll h=(f-1)*b;
                h += (f+2)*a;
                res +=min(g,h);
          //      printf("g:%lld f:%lld r;%lld\n",g,h,res);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
