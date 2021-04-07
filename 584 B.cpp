#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int table[110][10000];
int main(){
    int n;cin>>n;
    string s;cin>>s;
    PII a[n];
    loop(i,n,0) cin>>a[i].second>>a[i].first;
    loop(i,n,0){
        int c=0;
        for(int j=0;j<10000;++j){
            if(c % 2 == 0) table[i][j]=(s[i]-'0');
            else table[i][j]=!(s[i]-'0');
            if((j+1)>=a[i].first+c*a[i].second) ++c;
        }
    }
    int fr=0;
    int mx=0;
    for(int i=0;i<n;++i){
        for(int j=1;j<30;++j) printf("%d ",table[i][j]);
        printf("\n");
    }
    for(int j=1;j<10000;++j){
        for(int i=0;i<n;++i){
            if(table[i][j]) ++fr;
        }
        mx=max(mx,fr);
        fr=0;
    }
    printf("%d",mx);
    return 0;
}
