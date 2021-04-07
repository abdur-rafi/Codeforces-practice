 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
const ll MAX=(1e18)+10;
ll gcd(ll a,ll b){
    if(!b) return a;
    return gcd(b,a%b);
}
ll bs(ll i,ll j,ll a,ll nr,bool bef){
//    printf("i:%lld j:%lld nr:%lld\n",i,j,nr);
    ll m;
    while(i<=j){
        m=(i+j)>>1;
        if(m*nr>a) j=m-1;
        else i=m+1;
    }
    if(bef) return i-1;
    return j+1;
}
int main(){
    ll n,m,q;scanf("%lld %lld %lld",&n,&m,&q);
    ll nc=n,mc=m;
    ll nr,mr;
    ll i1=gcd(n,m);
    nr=n/i1;
    mr=m/i1;
    while(--q>=0){
        bool pos=false;
        ll ax,a,bx,b,ac,bc;
        scanf("%lld %lld %lld %lld",&ax,&a,&bx,&b);
        ll pre=0;
        ll nxt=0;
        if(ax==1){
            if(a%nr){
                pre=bs(0,n/nr,a,nr,1);
                nxt=bs(0,n/nr,a,nr,0);
          //      printf("pre:%lld nxt:%lld\n",pre*nr,nxt*nr);
            }
            else{
                if(a-1==0) pre=0;
                else pre=bs(0,n/nr,a-1,nr,1);
                nxt=a/nr;
           //     printf("pre:%lld nxt:%lld\n",pre*nr,nxt*nr);
            }
        }
        else{
            if(a%mr){
                pre=bs(0,m/mr,a,mr,1);
                nxt=bs(0,m/mr,a,mr,0);
           //     printf("pre:%lld nxt:%lld\n",pre*mr,nxt*mr);
            }
            else{
                if(a-1==0) pre=0;
                else pre=bs(0,m/mr,a-1,mr,1);
                nxt=a/mr;
            //    printf("pre:%lld nxt:%lld\n",pre*mr,nxt*mr);
            }
        }
     //   printf("pre:%lld nxt:%lld\n",pre,nxt);
        if(bx==1){
            pre*=nr;
            nxt*=nr;
        }
        else{
            pre*=mr;
            nxt*=mr;
        }
        if(b>pre&&b<=nxt) pos=true;
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
