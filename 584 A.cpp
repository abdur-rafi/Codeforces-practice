#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int n;scanf("%d",&n);
    int a[n];
    loop(i,n,0) scanf("%d",a+i);
    sort(a,a+n);
    int flag[n];
    loop(i,n,0) flag[i]=0;
    int c=0;
    loop(i,n,0){
        if(flag[i]) continue;
        int curr=a[i];
        loop(j,n,0){
            if(a[j]%curr == 0) flag[j]=1;
        }
        ++c;
    }
    printf("%d",c);
    return 0;
}
