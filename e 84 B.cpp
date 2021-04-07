#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        vector<int> adj[n+1];
        for(int i=0;i<n;++i){
            int k;scanf("%d",&k);
            for(int j=0;j<k;++j){
                int a;scanf("%d",&a);
                adj[i].push_back(a);
            }
        }
        int taken[n+1];
        for(int i=0;i<=n;++i) taken[i] = 0;
        int married = 0;
        vector<int> nm;
        for(int i=0;i<n;++i){
            if(!adj[i].empty()){
                int b = 0;
                for(auto p : adj[i]){
                    if(!taken[p]){
                        taken[p] = 1;
                        married++;
                         b = 1;
                        break;
                    }
                }
                if(!b) nm.push_back(i);
            }
            else nm.push_back(i);

        }
        if(married == n){
            printf("OPTIMAL\n");
            continue;
        }
        vector<int> nmb;
        for(int i=1;i<=n;++i){
            if(!taken[i]) nmb.push_back(i);
        }
        int lst = *(nmb.end()-1);
        printf("IMPROVE\n%d %d\n",nm[0]+1,lst);
    }

}

