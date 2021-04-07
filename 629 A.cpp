#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        int a[n+10];
        for(int i=0;i<n;++i) scanf("%d",a+i);
        int color[n+1];
        int curr = 0;
        color[0] = 0;
        int mx = 0;
        for(int i = 1;i<n;++i){
            if(a[i] != a[i-1]){
                curr = (curr+1)%2;
                mx = max(mx,curr);
            }
            color[i] = curr;
        }
        if(a[0] != a[n-1]){
            if(color[0] == color[n-1]){
                bool pos = 0;
                for(int i=n-1;i>0;--i){
                    if(a[i-1] == a[i]){
                        pos = 1;
                        for(int j = i;j<n;++j){
                            color[j] = (color[j]+1)%2;
                        }
                        break;
                    }
                }
                if(!pos){
                    color[n-1] = 2;
                    mx = 2;
                }
            }
        }
        printf("%d\n",mx+1);
        for(int i=0;i<n;++i){
            printf("%d ",color[i]+1);
        }
        printf("\n");

    }
}
