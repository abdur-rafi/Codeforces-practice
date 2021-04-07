#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;++i) scanf("%d",a+i);
        vector<int> adj[n+1];
        int fr[n+1];
        set<int> s;
        for(int i=0;i<=n;++i) fr[i] = 0;
        for(int i=0;i<n;++i){
            s.insert(a[i]);
            adj[a[i]].push_back(i);
            fr[a[i]] = 1;
        }
        if(s.size() == n){
            for(int i=0;i<n;++i) --a[i];
        }
        else{
            int j = 0;
            int mex = -1;
            for(int i=0;i<n;++i){
                if(fr[i] == 0){
                    mex = i;
                    if(adj[j].size() > 1 || (j == n && adj[j].size()>0)){
                        int id = adj[adj[j].size()-1];
                        a[id] = mex;
                        adj[j].pop_back();
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        if(a[0] == 0){
            int c = 1;
            int curr = a[n-1];
            a[n-1] = n;
            while(c < n){
                a[curr] = curr;

            }
        }
    }
}
