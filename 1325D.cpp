#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll u,v;scanf("%lld %lld",&u,&v);
    if(u > v || u % 2 != v % 2){
        printf("-1");
        return 0;
    }
    if(u == v){
        if(!u){
            printf("0");
        }
        else{
            printf("1\n%lld",u);
        }
        return 0;
    }
    ll x = (v-u)/2;
    if(x&u){
        printf("3\n%lld %lld %lld",u,x,x);
    }
    else{
        printf("2\n%lld %lld",u+x,x);
    }
}
