#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        ll n;scanf("%lld",&n);
        ll sum = 1;
        ll curr = 2;
        vector<ll> res;
        res.push_back(1);
        ll rem = 0;
        while(1){
            if(sum+curr<=n){
                res.push_back(curr);
                sum += curr;
                if(sum == n) break;
                curr *= 2;
            }
            else{
                rem = n-sum;
                break;
            }
        }
        for(int i=0;i<res.size();++i){
            if(rem!=0 && res[i]<=rem && 2*res[i]>=rem){
                res.insert(res.begin()+i+1,rem);
                rem = 0;
            }
        }
        printf("%d\n",res.size()-1);
        for(int i=1;i<res.size();++i){
            printf("%lld ",res[i]-res[i-1]);
        }
        printf("\n");
    }
}
