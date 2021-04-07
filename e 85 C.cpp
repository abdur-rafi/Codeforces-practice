#include <bits/stdc++.h>
using namespace std;

int main(){
    int _;scanf("%d",&_);
    while(--_>=0){
        int n;scanf("%d",&n);
        long long bullet = 0;
        long long health[n],explosion_damage[n];
        for(int i=0;i<n;++i){
            scanf("%lld %lld",health+i,explosion_damage+i);
        }
        int pre = n-1;
        long long add = explosion_damage[n-1];
        for(int i=0;i<n;++i){
            bullet += max((long long)0,health[i]-explosion_damage[pre]);
            add = min(add,min(health[i],explosion_damage[pre]));
            pre = i;
        }
        printf("%lld\n",bullet+add);
    }

}
