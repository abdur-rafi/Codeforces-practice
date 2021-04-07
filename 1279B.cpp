#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n,s;scanf("%d %d",&n,&s);
        int a[n];
        for(int i=0;i<n;++i) scanf("%d",a+i);
        int mx = 0;
        int mxi = 0;
        int f = -1;
        for(int i=0;i<n;++i){
            if(s>=a[i]) s-=a[i];
            else{
                if(a[i]>mx){
                    f = i;
                    break;
                }
                else{
                    f = mxi;
                    break;
                }
            }
            if(mx<a[i]){
                mx = a[i];
                mxi = i;
            }
        }
        f++;
        printf("%d\n",f);
    }

}
