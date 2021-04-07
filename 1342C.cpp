#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int a,b,q;scanf("%d %d %d",&a,&b,&q);
        int mx = max(a,b);
        int gcd = __gcd(a,b);
        gcd = (a*b)/gcd;
        int pref[gcd];
        for(int i=0;i<gcd;++i){
            if((i%a)%b != (i%b)%a) pref[i] = 1;
            else pref[i]=0;
        }
     //   for(int i=0;i<gcd;++i) printf("%d ",pref[i]);
     //   printf("\n");
        for(int i=1;i<gcd;++i) pref[i] += pref[i-1];
        for(int i=0;i<q;++i){
            long long l,r;scanf("%lld %lld",&l,&r);
            long long lft = l / gcd + 1;
            long long res = 0;
            long long bg = lft*gcd;
            if(r>=bg){
                res += pref[gcd-1];
                if(l%gcd > 0){
                    res -= pref[(l%gcd)-1];
                }
                res += pref[r%gcd];
                long long rt = r/gcd;
          //      if(r%gcd == 0) --rt;
                res += (rt-lft)*pref[gcd-1];
            }
            else{
                res += pref[(r%gcd)];
                if(l%gcd > 0){
                    res -= pref[(l%gcd)-1];
                }
            }
            printf("%lld ",res);

        }
        printf("\n");
    }
}
