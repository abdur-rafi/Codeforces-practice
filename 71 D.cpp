#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
struct pairs{
    ll x,y;
};
bool comp1(pairs a,pairs b){
    if(a.x==b.x) return a.y<b.y;
    return (a.x<b.x);
}
bool comp2(pairs a,pairs b){
    if(a.y==b.y) return a.x<b.x;
    return (a.y<b.y);
}
ll const M=998244353;
ll perm[300010];
int main(){
    perm[0]=1;
    loop(i,300010,1){
        perm[i]=(perm[i-1]*i)%M;
    }
    ll n;scanf("%lld",&n);
    pairs a[n];
    loop(i,n,0){
        scanf("%lld %lld",&a[i].x,&a[i].y);
    }
    bool eq1=true,eq2=true;
    loop(i,n-1,0){
        if(a[i].x!=a[i+1].x) eq1=false;
        if(a[i].y!=a[i+1].y) eq2=false;
    }
    if(eq1||eq2){
        printf("0");
        return 0;
    }
    sort(a,a+n,comp1);
    ll p1=1;
    int i=0;
    while(i<n){
        ll f=1;
        int j=i;
        while(i<n-1 && a[i].x==a[i+1].x){
            ++i;++f;
        }
        bool eq=true;
        if(f>1){
            for(int k=j;k<i-1;++k){
                if(a[k].x!=a[k+1].x || a[k].y!=a[k+1].y) eq=false;
            }
        }
        if(!eq)
            p1 = (p1 * perm[f]) % M;
        if(i>=n-1) break;
        else{
            if(a[i].x!=a[i+1].x) ++i;
        }
    }
    ll p2=1;
    i=0;
    sort(a,a+n,comp2);
    while(i<n){
        ll f=1;
        int j=i;
        while(i<n-1 && a[i].y==a[i+1].y){
            ++i;++f;
        }
        printf("f:%lld\n",f);
        bool eq=true;
        if(f>1){
            for(int k=j;k<i-1;++k){
                if(a[k].x!=a[k+1].x || a[k].y!=a[k+1].y) eq=false;
            }
        }
        if(!eq)
            p2 = (p2 * perm[f]) % M;
   //     if(eq) printf("sdf");
        if(i>=n-1) break;
        else{
            if(a[i].y!=a[i+1].y) ++i;
        }
    }
    p1=(p1+p2)%M;
    ll r=(perm[n]+M-p1)%M;
    printf("%lld",r);
    return 0;
}
