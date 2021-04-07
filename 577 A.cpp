 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll n,m;cin>>n>>m;
    string a[n];
    loop(i,n,0) cin>>a[i];
    ll fre[m][5];
    loop(i,m,0){
        loop(j,5,0) fre[i][j]=0;
    }
    loop(j,m,0){
        loop(i,n,0) fre[j][a[i][j]-'A']++;
    }
    ll mark[m];
    loop(i,m,0) cin>>mark[i];
    ll res=0;
    loop(i,m,0){
        ll b=0;
        loop(j,5,0) b=max(b,fre[i][j]);
        res+= mark[i]*b;
    }
    cout<<res;
    return 0;
}
