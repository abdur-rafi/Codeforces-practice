 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n,k;cin>>n>>k;
    ll a[n][n];
    loop(i,n,0){
        string s;cin>>s;
        loop(j,s.size(),0){
            if(s[j]=='W') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    ll rsum[n][n+1];
    loop(i,n,0){
        loop(j,n+1,0) rsum[i][j]=0;
    }
    loop(i,n,0){
        loop(j,n+1,1){
            rsum[i][j]=rsum[i][j-1]+a[i][j-1];
        }
    }
    ll rowres[n][n];
    loop(i,n,0){
        loop(j,n,0) rowres[i][j]=0;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n-k+1;++j){
            int a=rsum[i][n]-rsum[i][j+k];
            a += rsum[i][j];
            if(!a) rowres[i][j]=1;
        }
    }
   /* loop(i,n,0){
        loop(j,n,0) printf("%lld ",rowres[i][j]);
        printf("\n");
    }*/
    loop(j,n,0){
        loop(i,n,1) rowres[i][j]+=rowres[i-1][j];
    }
    ll colsum[n][n];
    loop(j,n,0){
        loop(i,n,0){
            colsum[i][j]=a[i][j];
            if(i-1>-1) colsum[i][j]+=colsum[i-1][j];
        }
    }
    ll colres[n][n];
    loop(i,n,0){
        loop(j,n,0) colres[i][j]=0;
    }
    for(int i=0;i<n-k+1;++i){
        for(int j=0;j<n;++j){
            ll g=0;
            g = colsum[n-1][j]-colsum[i+k-1][j];
            if(i>0) g+=colsum[i-1][j];
            if(!g) colres[i][j]=1;
        }
    }
    loop(i,n,0){
        loop(j,n,1){
            colres[i][j]+=colres[i][j-1];
        }
    }
    ll rowsum[n];
    loop(i,n,0){
        ll b=0;
        loop(j,n,0) b+=a[i][j];
        if(b) rowsum[i]=0;
        else rowsum[i]=1;
        if(i>0) rowsum[i]+=rowsum[i-1];
    }
    ll csum[n];
    loop(j,n,0){
        ll b=0;
        loop(i,n,0) b+=a[i][j];
        if(b) csum[j]=0;
        else csum[j]=1;
        if(j>0) csum[j]+=csum[j-1];
    }
    ll res=0;
    for(int i=0;i<n-k+1;++i){
        ll c=0;
        if(i>0) c+=rowsum[i-1];
        c += rowsum[n-1]-rowsum[i+k-1];
        for(int j=0;j<n-k+1;++j){
            ll d=rowres[i+k-1][j];
            if(i>0) d-=rowres[i-1][j];
            d+=colres[i][j+k-1];
            if(j>0) d-=colres[i][j-1];
            ll e=0;
            e=csum[n-1]-csum[j+k-1];
            if(j>0) e+=csum[j-1];
            res=max(res,d+c+e);

        }
    }
    printf("%lld",res);
    return 0;
}
