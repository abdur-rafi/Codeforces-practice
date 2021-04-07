#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll  t;scanf("%lld",&t);
    while(--t>=0){
        int pos = 0;
        int x,n,m;scanf("%d %d %d",&x,&n,&m);
        if(m*10 >= x) pos = 1;
        if(pos){
            printf("YES\n");
            continue;
        }
        for(int i=0;i<n;++i){
            x /= 2;
            x += 10;
            if(m*10 >= x){
                pos = 1;
            }
        }
        if(m*10>=x) pos = 1;
        if(pos) printf("YES\n");
        else printf("NO\n");
    }


}

