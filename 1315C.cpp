#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        int b[n];
        for(int i=0;i<n;++i) scanf("%d",b+i);
        int res[2*n];
        int mp[2*n+1];
        for(int i=0;i<=2*n;++i) mp[i] = 0;
        for(int i=0;i<n;++i) mp[b[i]] = 1;
        int pos = 1;
        for(int i=0;i<n;++i){
            int nxt = b[i]+1;
            while(nxt <= 2*n && mp[nxt]) ++nxt;
            if(nxt>2*n){
                printf("-1\n");
                pos = 0;
                break;
            }
            res[2*i] = b[i];
            res[2*i+1] = nxt;
            mp[nxt] = 1;

        }
        if(pos){
            for(int i=0;i<2*n;++i) printf("%d ",res[i]);
            printf("\n");
        }
    }

}
