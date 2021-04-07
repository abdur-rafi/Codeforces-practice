#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int q;cin>>q;
    while(--q>=0){
        string s,t,p;
        cin>>s>>t>>p;
        int sc[200]={0};
      //  int tc[200]={0};
    //    int pc[200]={0};
        for(auto d:s) sc[d]++;
        for(auto d:t) sc[d]--;
        for(auto d:p){
            if(sc[d] != 0) sc[d]++;
        }
        bool tr= true;
        loop(i,200,0){
            if(sc[i]!=0){
                tr=false;
                break;
            }
        }
        if(tr) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
