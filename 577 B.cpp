 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n;scanf("%lld",&n);
    ll a[n];
    loop(i,n,0) scanf("%lld",a+i);
    sort(a,a+n);
    ll sum=0;
    loop(i,n,0) sum+=a[i];
    if(sum % 2 == 0 && sum-a[n-1]>=a[n-1]) printf("YES\n");
    else printf("NO\n");
    return 0;
}
