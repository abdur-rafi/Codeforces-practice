#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        int i=0,j=n;
        long long f=0,s=0;
        for(int i=1;i<n/2;++i){
            f += (1<<i);
        }
        for(int i=n/2;i<n;++i) s += (1<<i);
        f += (1<<n);
        printf("%lld\n",f-s);

    }
}
