#include<bits/stdc++.h>

using namespace std;
const int MAX = 200000+100;
int fre[MAX][26];
int main(){
    char str[MAX];
    scanf("%s",str);
    int n = strlen(str);
    for(int i=1;i<=n;++i){
        for(int j=0;j<26;++j) fre[i][j] += fre[i-1][j];
        fre[i][str[i-1]-'a']++;
    }
    int q;scanf("%d",&q);
    for(int i=0;i<q;++i){
        int l,r;scanf("%d %d",&l,&r);
        int c = 0;
        for(int j=0;j<26;++j){
            if(fre[r][j]-fre[l-1][j]) ++c;
        }
        if(l == r || str[l-1] != str[r-1] || c>2 ){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }
}
