#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        char str[n];
        scanf("%s",str);
        int mx[n],mn[n];
        int curr = 1;
        int i=0;
        mx[0] = 1;
        while(i<n-1){
            int inc = 0;
            while(i<n-1 && str[i] == '>'){
                ++inc;
                i++;
            }
            if(inc){
                int incc = inc;
                for(int j=i-inc;j<=i;++j){
                    mx[j] = curr+incc;
                    --incc;
                }
                curr += inc;
            }
            while(i<n-1 && str[i] == '<'){
                mx[i+1] = curr+1;
                ++curr;++i;
            }

        }
        i = 0;
        curr = n;
        mn[0] = curr;
         while(i<n-1){
            int dec = 0;
            while(i<n-1 && str[i] == '<'){
                ++dec;
                i++;
            }
            if(dec){
                int decc = dec;
                for(int j=i-dec;j<=i;++j){
                    mn[j] = curr-decc;
                    --decc;
                }
                curr -= dec;
            }
            while(i<n-1 && str[i] == '>'){
                mn[i+1] = --curr;
                ++i;
            }
        }
        for(int i=0;i<n;++i) printf("%d ",mn[i]);
            printf("\n");
        for(int i=0;i<n;++i) printf("%d ",mx[i]);
        printf("\n");
    }

}
