 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n;scanf("%lld",&n);
    ll c=0;
    ll a[n];loop(i,n,0) scanf("%lld",a+i);
    ll r=0;
    ll z=0;
    loop(i,n,0){
        if(a[i]>=1){
            r+=a[i]-1;
            a[i]=1;
        }
        else if(a[i]==0){
            ++z;
        }
        else{
            r+= abs(a[i])-1;
            a[i]=-1;
            ++c;
        }
    }
    r+=z;
    if(z==0 && c%2==1) r+=2;
    printf("%lld",r);
    return 0;
}
