#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    vector<long long> pre(n+1,0);
    for(int i=0;i<n;++i){
        int d;scanf("%d",&d);
        pre[i+1] = pre[i]+d;
    }
    set<long long> st={0};
    int i=0,j=1;
    long long res = 0;
    while(i < n || j <= n){
       // printf("res%lld i:%d j:%d\n",res,i,j);
        if(j <= n){
            if(st.find(pre[j]) != st.end()){
                res += j-i-1;
                st.erase(pre[i]);
                ++i;

            }
            else{
                st.insert(pre[j]);
                ++j;
            }
        }
        else{
            res +=  j-i-1;
            i++;

        }
    }
    printf("%lld",res);
}
