#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    ll q;cin>>q;
    while(--q>=0){
        ll n,m;cin>>n>>m;
        ll a[n][m];
        loop(i,n,0){
            string s;cin>>s;
            loop(j,m,0){
                if(s[j]=='.') a[i][j]=0;
                else a[i][j]=1;
            }
        }
        ll r[n]={0};
        ll c[m]={0};
        loop(i,n,0){
            ll cn=0;
            loop(j,m,0){
                if(a[i][j] == 0)++cn;
            }
            r[i]=cn;
        }
        loop(i,m,0){
            ll cn=0;
            loop(j,n,0){
                if(a[j][i] == 0) ++cn;
            }
            c[i]=cn;
        }
        int mn=1e9;
        loop(i,n,0){
            loop(j,m,0){
                int re=r[i]+c[j];
                if(a[i][j]==0)--re;
                mn = min(mn,re);
            }
        }
        cout<<mn<<'\n';
    }
    return 0;
}
