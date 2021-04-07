#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n;scanf("%lld",&n);
    if(n%2 == 0){
        printf("NO");
        return 0;
    }
    ll a[2*n];
    loop(i,2*n,0) a[i]=0;
    ll k=1;
    loop(i,n,0){
        a[i]=k;
        a[i+n]=k+1;
        k+=2;
    }
    for(int i=1;i<n;i+=2){
        swap(a[i],a[i+n]);
    }
    printf("YES\n");
    loop(i,2*n,0){
        printf("%lld ",a[i]);
    }
    return 0;
}
