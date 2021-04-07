#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(--t>=0){
        char str[110];
        char res[220];
        scanf("%s",str);
        bool one = true;
        for(int i=1;str[i];++i){
            if(str[i]!=str[i-1]){
                one = false;
                break;
            }
        }
        if(one || strlen(str)<=2){
            printf("%s\n",str);
            continue;
        }
        int i=1;
        int j=1;
        res[0] = str[0];
        while(str[i]){
            if(str[i] == str[i-1]){
                res[j++] = ((str[i]-'0')+1)%2 + '0';
            }
            res[j++] = str[i++];
        }
        res[j] = '\0';
        printf("%s\n",res);
    }
}
