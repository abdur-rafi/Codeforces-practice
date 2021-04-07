#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        ll d,m;scanf("%lld %lld",&d,&m);
        ll n = 0;
        ll tmp = d;
        if(d == 1){
            if(m == 1) printf("0\n");
            else printf("1\n");
            continue;
        }
        while(tmp){
            tmp /= 2;
            ++n;
        }
     //   printf("n:%lld\n",n);
        vector<ll> power(n+1);
        ll flag = 1;
        for(int i=1;i<=n;++i){
            power[i] = flag<<(i-1);
        }
        power[n] = d - (flag<<n-1)+1;
        for(int i=1;i<=n;++i){
         //    printf("power[%d]:%lld\n",i,power[i]);
        }
        ll dp[n+1][n+1];

        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j) dp[i][j] = 0;
        }
        for(int i=1;i<=n;++i){
            dp[1][i] = power[i]%m;
        }
        for(int i=2;i<=n;++i){
            for(int p=i;p<=n;++p){
                for(int j=1;j<p;++j){
                    dp[i][p] = (dp[i][p] + (dp[i-1][j] * power[p])%m) % m;
                }
            }
        }

        ll res = 0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                res = (res+dp[i][j])%m;
            }
        }
        printf("%lld\n",res);
    }
}
