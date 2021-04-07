#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



 int main(){
    int t;
    t = 1;
    while(--t>=0){
        int n;scanf("%d",&n);
        int a[n];
        int got[n+1];
        for(int i=0;i<=n;++i) got[i] = 0;
        vector<int> give;
        for(int i=0;i<n;++i) scanf("%d",a+i);
        for(int i=0;i<n;++i){
            if(!a[i]) give.push_back(i);
            else{
                got[a[i]-1] = 1;
            }

        }
        vector<int> rec;
        for(int i=0;i<n;++i){
            if(!got[i]) rec.push_back(i);
        }
        for(int i=0;i<give.size();++i){
            if(rec[rec.size()-1] != give[i]){
                a[give[i]] = rec[rec.size()-1]+1;
                rec.pop_back();
            }
            else{
                if(rec.size() == 1){
                    a[give[i]] = a[give[0]];
                    a[give[0]] = give[i]+1;
                    continue;
                }
                a[give[i]] = rec[rec.size()-2]+1;
                rec[rec.size()-2] = give[i];
                rec.pop_back();
            }

        }
        for(int i=0;i<n;++i){
            printf("%d ",a[i]);
        }
    }

 }

