#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll t;scanf("%lld",&t);
    while(--t>=0){
        ll b,p,f;scanf("%lld %lld %lld",&b,&p,&f);
        ll h,c;scanf("%lld %lld",&h,&c);
        ll res=0;
        if(h>c){
            if(2*p<=b){
                res += h*p;
                b-=2*p;
                res += min(b/2,f)*c;
            }
            else{
                res += (b/2)*h;
            }

        }
        else{
            if(2*f<=b){
                res += c*f;
                b-=2*f;
                res += min(b/2,p)*h;
            }
            else{
                res += (b/2)*c;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
