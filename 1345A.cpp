#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e9)+10;
int main(){
    int t;scanf("%d",&t);
    vector<int> res;
    res.push_back(2);
    int s = 2;
    int inc = 5;
    while(s+inc <= MAX){
        res.push_back(s+inc);
        s += inc;
        inc += 3;
    }
    while(--t>=0){
        int n;scanf("%d",&n);
        int id = upper_bound(res.begin(),res.end(),n)-res.begin();
        --id;
        if(n == 1) printf("0\n");
        else{
            int c = 0;
            while(id>=0 && n > 1 ){
                if(res[id]<=n){
                    int fr = n/res[id];
                    n -= fr*res[id];
                    c += fr;
                }
                --id;
            }
            printf("%d\n",c);
        }

    }
}
