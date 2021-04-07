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
        int pc[200]={0};
        for(auto d:p) pc[d]++;
        int i=0,j=0;
        bool pos = true;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]) ++i,++j;
            else if(pc[t[j]]>0){
                pc[t[j]]--;
                ++j;
            }
            else{
                p=false;
                break;
            }
        }
        if(i !=s.size()) pos = false;
        while(j< t.size()){
            if(pc[t[j]]>0){
                pc[t[j]]--;
                j++;
            }
            else{
                pos=false;
                break;
            }

        }
        if(pos) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
