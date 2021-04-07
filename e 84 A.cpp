#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        ll n,k;scanf("%lld %lld",&n,&k);
        if(k*k>n){
            printf("NO\n");
        }
        else{
            if(k%2 == 1 && n%2 == 1){
                printf("YES\n");
            }
            else if(k%2 == 0 && n%2 == 0){
                printf("YES\n");
            }
            else printf("NO\n");
        }

    }

}
