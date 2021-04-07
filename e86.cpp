#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;scanf("%d %d",&n,&k);
    int m[n];
    for(int i=0;i<n;++i) scanf("%d",m+i);
    int c[k+1];
    for(int i=0;i<k;++i) scanf("%d",c+i);
    int fre[k+1];
    for(int i=0;i<=k;++i) fre[i] = 0;
    for(int i=0;i<n;++i){
        fre[m[i]]++;
    }
    int pref[k+10];
    for(int i=0;i<=k+5;++i) pref[i] = 0;
    for(int i=k;i>=1;--i){
        pref[i] = pref[i+1]+fre[i];
    }
    int mx = 0;
    for(int i=1;i<=k;++i){
        int fr = pref[i]/c[i-1];
        if(pref[i]%c[i-1]) ++fr;
        mx = max(mx,fr);
    }
    printf("%d\n",mx);
    vector<int> res[mx];
    sort(m,m+n,greater<int>());
    for(int i=0;i<n;++i) res[i%mx].push_back(m[i]);
    for(int i=0;i<mx;++i){
            printf("%d ",res[i].size());
        for(auto p : res[i]){
            printf("%d ",p);
        }
        printf("\n");
    }
}








