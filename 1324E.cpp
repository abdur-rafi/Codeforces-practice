#include <bits/stdc++.h>
using namespace std;

int n,h,l,r;
int dp[2010][2010];
int calc(int a[],int i,int j){
    if(i == n) return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int c1 = calc(a,i+1,(j+a[i])%h);
    int c2 = calc(a,i+1,(j+a[i]-1)%h);
    if(l <= (j+a[i])%h && r>=(j+a[i])%h){
        ++c1;
    }
    if(l<=(j+a[i]-1)%h && r>=(j+a[i]-1)%h) ++c2;

    return dp[i][j]=max(c1,c2);

}

int main(){
    scanf("%d %d %d %d",&n,&h,&l,&r);
    int a[n+10];
    for(int i=0;i<n;++i) scanf("%d",a+i);
    for(int i=0;i<=n;++i){
        for(int j=0;j<=h;++j) dp[i][j] = -1;
    }
    printf("%d\n",calc(a,0,0));
}
