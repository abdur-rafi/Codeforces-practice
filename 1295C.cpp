#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000+10;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        char s[MAX],t[MAX];
        scanf("%s %s",s,t);
        vector<int> adj[26];
        for(int i=0;s[i];++i){
            adj[s[i]-'a'].push_back(i);
        }
        int prev = -1;
        int res = 0;
        bool pos = true;
        for(int i=0;t[i];++i){
            auto f = upper_bound(adj[t[i]-'a'].begin(),adj[t[i]-'a'].end(),prev);
            if(f == adj[t[i]-'a'].end()){
                ++res;
                if(prev == -1){
                    pos = false;
                    break;
                }
                prev = -1;
                --i;
            }
            else{
                prev = *f;
                if(!t[i+1]){
                    ++res;
                }
            }
        }
        if(!pos){
            printf("-1\n");
            continue;
        }
        printf("%d\n",res);
    }

}
