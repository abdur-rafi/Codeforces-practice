#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        ll n;scanf("%lld",&n);
        ++n;
        ll s = 2;
        ll res = 0;
        while(1){
      //      printf("s:%lld\n",s);
            ll fr = n / s;
            if(fr > 0) res += fr + fr-1;
            if(fr != 0 &&  n % s) ++res;
            if(n % s > s/2) ++res;
            else{
                if(fr == 0) break;
            }
            s *= 2;
       //     printf("res: %lld\n",res);
        }
        printf("%lld\n",res);


    }
}
