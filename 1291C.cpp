#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n,m,k;scanf("%d %d %d",&n,&m,&k);
        int arr[n];
        for(int i=0;i<n;++i) scanf("%d",arr+i);
        if(k>=m){
            int res = 0;
            for(int i=0;i<m;++i) res = max(res,arr[i]);
            for(int j=n-1;j>n-1-m;--j) res = max(res,arr[j]);
            printf("%d\n",res);
            continue;
        }
        int res = 0;
        for(int a=0;a<=k;++a){
            int mn = (1e9)+10;
            int b = k-a;
            for(int c=0;c<=m-k-1;++c){
                int mx = 0;
                int d = m-k-1-c;
                int li = a+c;
                int ri = n-1-b-d;
                mx = max(arr[li],arr[ri]);
                mn = min(mn,mx);
            }
            res = max(res,mn);
        }
        printf("%d\n",res);

    }
}
