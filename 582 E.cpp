#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
string diff[] ={ "abcabc","acbacb","bacbac","bcabca"
                "cabcab","cbacba"
                };
string same[] = { "abc","acb","bac","bca","cab","cba"};
int main(){
    ll n;cin>>n;
    string a,b;
    cin>>a>>b;
    loop(i,6,0){
        string curr=diff[i];
        bool af=false,bf=false;
        for(int i=0;i<5;++i){
            if(a[0]==curr[i] && a[1]==curr[i+1]) af=true;
            if(b[0]==curr[i] && b[1]==curr[i+1]) bf=true;
        }
        if(bf==false && af==false){
            cout<<"YES\n";
            for(int i=1;i<=(n/2);++i) cout<<curr;
            if(n%2==1){
                loop(i,3,0) cout<<curr[i];
            }
            return 0;
        }
    }
    loop(i,6,0){
        string curr=same[i];
        bool af=false,bf=false;
        for(int i=0;i<3;++i){
            if(a[0]==curr[i] && a[1]==curr[i+1]) af=true;
            if(b[0]==curr[i] && b[1]==curr[i+1]) bf=true;
        }
        if(bf==false && af==false){
            cout<<"YES\n";
            for(int i=1;i<=n;++i) cout<<curr[0];
            for(int i=1;i<=n;++i) cout<<curr[1];
            for(int i=1;i<=n;++i) cout<<curr[2];
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
