 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int t;cin>>t;
    while(--t>=0){
        int n,m,k;cin>>n>>m>>k;
        int a[n];
        loop(i,n,0) cin>>a[i];
        bool pos=true;
        loop(i,n-1,0){
            if(a[i+1]<=a[i]){
                m += a[i]-a[i+1];
                m += min(k,a[i+1]);
            }
            else{
                if((a[i+1]-a[i])<=k) m += min(k-(a[i+1]-a[i]),a[i]);
                else m -= a[i+1]-a[i]-k;
            }
            if(m<0){
                pos=false;break;
            }
        }
        if(pos) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
