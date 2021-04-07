#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    if(n == 2){
        printf("0");
        return 0;
    }
    vector<pair<int,int>> edge;
    int degree[n+1];
    int res[n+1];
    for(int i=0;i<=n;++i) res[i] = -1;
    for(int i=0;i<=n;++i) degree[i] = 0;
    for(int i=1;i<n;++i){
        int a,b;scanf("%d %d",&a,&b);
        degree[a]++;
        degree[b]++;
        edge.push_back({a,b});

    }
    int mex = 0;
    for(int i=1;i<=n;++i){
        if(degree[i] == 1) res[i] = mex++;
    }
    for(auto p : edge){
        if(res[p.first] != -1 || res[p.second] != -1){
            printf("%d\n",max(res[p.first],res[p.second]));
        }
        else printf("%d\n",mex++);
    }
}
