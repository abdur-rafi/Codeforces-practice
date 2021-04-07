#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        ll n,x,y;scanf("%lld %lld %lld",&n,&x,&y);
        if(x+y<=n){
            printf("1 %lld\n",x+y-1);
        }
        else{
            printf("%lld %lld\n",min(x+y-n+1,n),n);
        }
    }
}
