#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        char str[n+10];
        scanf("%s",str);
        int sum = 0;
        for(int i=0;i<n;++i){
            sum += str[i]-'0';
        }
        if(sum%2 == 1){
            for(int i=0;i<n;++i){
                if((str[i]-'0') % 2){
                    str[i] = -1;
                    break;
                }
            }
        }
    //    printf("%s\n",str);
        int i = n-1;
        while(i>=0){
            if(str[i] != -1 && (str[i]-'0') % 2 == 0){
                str[i] = -1;
            }
            if(str[i] != -1) break;
            --i;
        }
        i = 0;
        while(i<n && (str[i] == '0' || str[i] == -1)){
            str[i] = -1;N
            ++i;
        }
        int f = 0;
      //  printf("res: ");
        for(int i=0;i<n;++i){
            if(str[i]!=-1){
                printf("%c",str[i]);
                f = 1;
            }
        }
        if(!f) printf("-1");
        printf("\n");
    }
}
