#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int k;scanf("%d",&k);
    if(k == 0){
        printf("1 1\n1");
        return 0;
    }
    int lft = 0;
    int index = 0;
    while(index <= 20){
        if(k & (1<<index)){
            lft = index;
        }
        index++;
    }
    ++lft;
    int shifted = k + (1<<lft);
    printf("3 3\n");
    printf("%d %d %d\n",shifted,shifted,(1<<lft));
    printf("%d %d %d\n",(1<<lft),k,shifted);
    printf("%d %d %d",shifted,shifted,k);

    return 0;
}
