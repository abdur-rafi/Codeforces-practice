#include <bits/stdc++.h>
using namespace std;
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
typedef unsigned long long ll;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n,k;scanf("%d %d",&n,&k);
        char str[n+1];
        scanf("%s",str);
        int fre[26] = {0};
        loop(i,n,0) fre[str[i]-'a']++;
        vector<int> av;
        loop(i,26,0){
            if(fre[i]) av.push_back(fre[i]);
        }
        sort(av.begin(),av.end());
        reverse(av);
        vector<int> divs;
        for(int i=1;i*i<=k;++i){
            if(k % i == 0){
                divs.push_back(i);
                if(k/i != i) divs.push_back(k/i);
            }
        }
        int res = 0 ;
        for(auto len:divs){
            if(len > n) continue;
            int curr = av[len-1];

            int i = 0;
            int j = len-1;
            int c = 1;
            while(i<j){
                if(av[i]/(c+1) > av[j]){

                }
            }
        }

    }
    return 0;
}
