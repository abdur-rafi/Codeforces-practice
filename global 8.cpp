
#include <bits/stdc++.h>
using namespace std;
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef unsigned long long ll;

int main(){
    int t;//scanf("%d",&t);
    t = 1;
    while(--t>=0){
        ll k;scanf("%lld",&k);
        int fr[10];
        char str[] = "codeforces";
        loop(i,10,0) fr[i] = 1;
        ll c = 1;
        ll tot = 1;
        while(tot<k){
            loop(i,10,0){
                tot /= fr[i];
                fr[i]++;
                tot *= fr[i];
                if(tot >= k) break;
            }
        }
        loop(i,10,0){
            while(fr[i]--){
                printf("%c",str[i]);
            }
        }
    }

    return 0;
}
