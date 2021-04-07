#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    int mx=0;
    int mn=1e9;
    int n2=n;
    if(k1>k2){
        swap(k1,k2);
        swap(a1,a2);
    }
    mx += min(a1,n/k1);
    n2 = n - mx*k1;
    mx += min(a2,n2/k2);
    mn = 0;
    n -= (k1-1)*(a1);
    if(n < 0) n=0;
    n -= (k2-1)*(a2);
    if(n < 0) n=0;
    if(n){
        mn=min(n,a1+a2);
    }
    printf("%d %d",mn,mx);
    return 0;
}
