
#include <bits/stdc++.h>
using namespace std;
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef unsigned long long ll;

char str[1000000+100];
int main(){
    int t = 1;scanf("%d",&t);
    while(--t>=0){
        scanf("%s",str);
        int n = strlen(str);
        ll res = 0;
        int c = 0;
        int curr = 0;
        loop(i,n,0){
           // printf("curr:%d\n",curr);
            if(str[i] == '+') ++curr;
            else --curr;
            if(curr < 0){
                res += i+1;
                ++c;
                curr =0 ;
            }
        }
        res += n;
        printf("%lld\n",res);
    }
    return 0;
}
