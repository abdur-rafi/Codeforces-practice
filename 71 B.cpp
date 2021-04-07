#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int n,m;scanf("%d %d",&n,&m);
    int a[n][m],b[n][m];
    loop(i,n,0){
        loop(j,m,0){
            scanf("%d",&a[i][j]);
            b[i][j]=0;
        }
    }
    vector<PII> res;
    for(int i=0;i<n-1;++i){
        for(int j=0;j<m-1;++j){
            if(a[i][j]==1 && a[i][j+1] == 1 && a[i+1][j] == 1 && a[i+1][j+1] == 1){
                b[i][j]=1; b[i][j+1] = 1; b[i+1][j] = 1 ;b[i+1][j+1] = 1;
                res.push_back({i+1,j+1});
            }
        }
    }
    bool pos=true;
    loop(i,n,0){
        loop(j,m,0){
            if(a[i][j] != b[i][j]){
                pos=false;break;
            }
        }
    }
    if(!pos) printf("-1");
    else{
        printf("%d\n",res.size());
        for(auto p:res){
            printf("%d %d\n",p.first,p.second);
        }
    }
    return 0;
}
