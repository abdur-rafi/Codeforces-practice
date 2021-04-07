#include <bits/stdc++.h>
using namespace std;
string nb[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;++i) scanf("%d",a+i);
        int fre[n];
        for(int i=0;i<n;++i) fre[i] = 0;
        vector<int> adj[n+1];
        for(int i=0;i<n;++i){
            adj[a[i]].push_back(i);
        }
        int mxi =-1;
        int p = 1;
        for(int i=1;i<=n;++i){
            int id = adj[i][0];
            if(mxi !=-1 && id != mxi){
                p = 0;
                break;
            }
            fre[id] = 1;
            mxi = id+1;

            if(mxi > n-1) mxi = -1;
            else if(fre[mxi]) mxi = -1;
        }
        if(p){
            printf("Yes\n");
        }
        else printf("No\n");

    }
}
