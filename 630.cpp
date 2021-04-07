#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int t;scanf("%d",&t);
    int pr[]={ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    while(--t>=0){
        int n,k;scanf("%d %d",&n,&k);
        char str[n+10];scanf("%s",str);
        int fre[n+1][26];
        if(k == n){
            int i=0;
            int j = n-1;
            int cst=0;
            while(i<=j){
                if(str[i] != str[j]) ++cst;
                i++;
                j--;
            }
            printf("%d\n",cst);
            continue;
        }
        if(k == 1){
            int fr[26];
            for(int i=0;i<26;++i) fr[i] = 0;
            int mx = 0;
            for(int i=0;i<n;++i){
                fr[str[i]-'a']++;
                mx = max(mx,fr[str[i]-'a']);
            }
            printf("%d\n",n-mx);
            continue;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<26;++j) fre[i][j] = 0;
        }
        for(int i=0;i<n;++i){
            fre[i][str[i]-'a']++;
        }
        for(int i=0;i<k;++i){
            for(int j=k+i;j<n;j+=k){
                for(int x=0;x<26;++x){
                    fre[j][x] += fre[j-k][x];
                }
            }
        }
       // printf("%d\n",fre[n-1][1]);
        int fr = 0;

        for(int i=0;i<k/2;++i){
            int mx = 0;
            for(int j=0;j<26;++j){
                mx = max(mx,fre[n-k+i][j]+fre[n-1-i][j]);
            }
            fr += mx;
        }
        int mx = 0;
        if(k % 2 == 1){
            for(int j=0;j<26;++j){
                mx = max(mx,fre[n-k+(k/2)][j]);
            }
        }
        fr += mx;
        printf("%d\n",n-fr);

    }

    return 0;
}
