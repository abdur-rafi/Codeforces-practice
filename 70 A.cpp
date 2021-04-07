 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int t;cin>>t;
    loop(ii2,t,0){
        string a,b;cin>>a>>b;
        int ind=0;
        for(int i=b.size()-1;i>=0;--i){
            if(b[i]=='1'){
                break;
            }
            ++ind;
        }
        int res=0;
        for(int i=a.size()-ind-1;i>=0;--i){
            ++res;
            if(a[i]=='1')
                break;
        }
        cout<<res-1<<'\n';
    }
    return 0;
}
