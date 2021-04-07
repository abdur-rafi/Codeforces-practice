#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
       int n;scanf("%d",&n);
       int a[n+10];
       for(int i=0;i<n;++i) scanf("%d",a+i);
       vector<int> adj[27];
       int fre[n][27];
       for(int i=0;i<n;++i){
        for(int j = 0;j <= 26;++j) fre[i][j] = 0;
       }
       int max_len = 1;
       for(int i=0;i<n;++i){
            if(i != 0){
                for(int l = 0; l <= 26;++l){
                    fre[i][l] = fre[i-1][l];
                }
            }
            fre[i][a[i]]++;
            adj[a[i]].push_back(i);
            if(adj[a[i]].size()>1){
                int curr = a[i];
                int j = 0;
                int k = adj[curr].size() -1 ;
            //    max_len = max(max_len,adj[curr].size());
                while(j < k){
                    int mx_fre=0;
                    for(int l = 1;l <= 26;++l){
                        if(l != curr)
                            mx_fre = max(mx_fre,fre[adj[curr][k]][l]-fre[adj[curr][j]][l]);
                        else
                            mx_fre = max(mx_fre,fre[adj[curr][k]][l]-fre[adj[curr][j]][l]-1);
                    }
                    j++;
                    k--;
                    max_len = max(max_len,mx_fre+2*j);
                }
            }

       }
       printf("%d\n",max_len);

    }

}
