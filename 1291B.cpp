#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;++i) scanf("%d",a+i);
        int p = 1;
        int d = 0;
        for(int i=0;i<n;++i){
            if(a[i]<i){
                d = 1;
                int b = a[i];
                if(i>0){
                    if(a[i] == a[i-1]) --b;
                }
                if(b<0){
                    p = 0;
                    break;
                }
                for(int j=i+1;j<n;++j){
                    if(a[j]>=b) b = b-1;
                    else{
                        b = a[j];
                    }
                    if(b<0) {
                        p = 0;
                        break;
                    }
                }
            }
            if(d) break;

        }
        if(p) printf("YES\n");
        else printf("NO\n");
    }

}
