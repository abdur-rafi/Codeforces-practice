#include <bits/stdc++.h>
using namespace std;


int main(){
    int _;scanf("%d",&_);
    while(--_>=0){
        long long n,x;scanf("%lld %lld",&n,&x);
        long long a[n];
        for(int i=0;i<n;++i) scanf("%lld",a+i);
        sort(a,a+n,greater<long long>());
     //   for(int i=0;i<n;++i) printf("%lld ",a[i]);
    //    printf("\n");
        long long sum = 0;
        int  res = 0;
        for(int i=0;i<n;++i){
            sum += a[i];
            if(sum/(i+1) >= x){
                res = i+1;
            }
            else break;
        }
        printf("%d\n",res);
    }

}
