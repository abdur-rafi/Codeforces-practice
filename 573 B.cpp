#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int ch(vector<int> a){
    if(a.size()==0) return 3;
    if(a.size()==1) return 2;
    if(a.size()==2){
        sort(a.begin(),a.end());
        if(a[1]-a[0]<=2)return 1;
        return 2;
    }
    if(a.size()==3){
        sort(a.begin(),a.end());
        if((a[0]+1==a[1]&&a[1]+1==a[2])||(a[0]==a[1]&&a[1]==a[2])) return 0;
        else if(a[1]-a[0]<=2||a[2]-a[1]<=2) return 1;
        else return 2;
    }
    return 3;
}
int main(){
    map<char,vector<int>> m;
    loop(i,3,0){
        string s;cin>>s;
        m[s[1]].push_back(s[0]-'0');
    }
    int res=4;
    for(auto p:m){
        res=min(res,ch(p.second));
    }
    cout<<res;
    return 0;
}

