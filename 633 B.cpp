#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;++i) scanf("%d",a+i);
        int mx_time = 0;
        for(int i=0;i<n-1;++i){
            if(a[i] > a[i+1]){
                long long diff = a[i]-a[i+1];
                a[i+1] = a[i];
                int id = 0;
                while(diff){
                    diff = diff / 2;
                    ++id;
                }
                mx_time = max(mx_time,id);
            }
        }
        printf("%d\n",mx_time);

    }
}
