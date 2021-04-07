#include <bits/stdc++.h>
using namespace std;
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n,m,a,b;scanf("%d %d %d %d",&n,&m,&a,&b);
        if(n*a != m*b){
            printf("NO\n");
            continue;
        }
        int arr[n][m];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j) arr[i][j] = 0;
        }
        for(int j=0;j<m;++j){
            for(int i=0;i<b;++i) arr[i][j] = 1;
        }
        int row[n];
        int e[n];
        for(int i=0;i<b;++i){
            row[i] = m;
            e[i] = m-1;
        }
        for(int i=b;i<n;++i){
            row[i] = 0;
            e[i] = 0;
        }
        int take = b-1;
        int pos = 1;
        for(int i=n-1;i>=b;--i){
            while(row[i] < a){
                if(row[take] <= a){
                    --take;
                }
                if(take<0){
                    pos = 0;
                    break;
                }
                printf("i: %d take:%d\n",i,take);
                arr[i][e[take]] = 1;
                arr[take][e[take]] = 0;
                e[take]--;
                row[take]--;
                row[i]++;
            }
        }
        for(int i=0;i<n;++i){
            int s = 0;
            for(int j=0;j<m;++j) s+= arr[i][j];
            if(s!= a){
                pos = 0;
                break;
            }
        }

        if(false) printf("NO\n");
        else{
            printf("YES\n");
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j) printf("%d",arr[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
