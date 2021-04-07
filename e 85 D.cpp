#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void of_first_portion(ll n,vector<ll> &res,ll l,ll r){
    ll curr = 0;
    ll start = 0;
    ll starti = 0;
    for(ll i = 1;i<n;++i){
        curr += 2*(n-i);
        if(curr >= l){
      //      printf("i:%d\n",i);
            curr -= 2*(n-i);
            ll tmp = l - curr;
            ll c = tmp/2 + i;
            bool i_first = 0;
            if(tmp % 2){
                ++c;
                i_first = 1;
            }

            while(l<=r){
                if(i_first){
                    res.push_back(i);
                    ++l;
                    i_first = 0;
                }
                else{
                    res.push_back(c);
                    ++l;
                    ++c;
                    if(c>n){
                        c = i+2;
                        i++;
                        if(i == n){
                            if(l<=r){
                                res.push_back(1);
                            }
                            return;
                        }
                    }
                    i_first = 1;
                }
            }
            return ;

        }
    }
    res.push_back(1);
}

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        ll n,l,r;scanf("%lld %lld %lld",&n,&l,&r);
        vector<ll> res;
        of_first_portion(n,res,l,r);
        for(auto p : res){
            printf("%lld ",p);
        }
        printf("\n");
    }

}
