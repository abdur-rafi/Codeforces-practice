#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n,k;scanf("%d %d",&n,&k);
        int a[n];
        for(int i=0;i<n;++i) scanf("%d",a+i);
        set<int> s;
        int fre[110];
        for(int i=0;i<110;++i) fre[i] = 0;
        int mx = 0;
        for(int i=0;i<n;++i){
            s.insert(a[i]);
            fre[a[i]]++;
            mx = max(mx,fre[a[i]]);
        }
        if(s.size()>k){
            printf("-1\n");
            continue;
        }
        vector<int> res;
        for(auto &p:s) res.push_back(p);
        for(int i=res.size();i<k;++i) res.push_back(1);
        printf("%d\n",res.size()*n);
        for(int i=0;i<n;++i){
            for(auto &p:res) printf("%d ",p);
        }
        printf("\n");

    }
}
