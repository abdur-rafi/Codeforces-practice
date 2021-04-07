#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;scanf("%d",&n);
    int mx[n],mn[n];
    for(int i=0;i<n;++i){
        int l;
        scanf("%d",&l);
        int mxc,mnc;
        int c;
        scanf("%d",&c);
        mxc=mnc=c;
        for(int j=1;j<l;++j){
            scanf("%d",&c);
            if(mnc<c){
                mnc = -1;
                mxc = INT_MAX;
            }
            mxc = max(mxc,c);
            mnc = min(mnc,c);
        }
        mx[i] = mxc;
        mn[i] = mnc;
    }
    sort(mx,mx+n);
    long long res = 0;
    for(int i=0;i<n;++i){
        if(mn[i] == -1){
            res += n;
            continue;
        }
        res += mx+n - upper_bound(mx,mx+n,mn[i]);
    }
    printf("%lld\n",res);

}
