 #include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    string s,t;cin>>s>>t;
    int left[t.size()],right[t.size()];
    int i=0;
    for(int j=0;j<s.size();++j){
        if(s[j] == t[i]){
            left[i]=j;
            ++i;
            if(i == t.size()) break;
        }
    }
    i = t.size()-1;
    for(int j=s.size();j>=0;--j){
        if(s[j] == t[i]){
            right[i]=j;
            --i;
            if(i == -1) break;
        }
    }
    int mx=0;
    int n=s.size();
    int m=t.size();
    mx=max(mx,n-left[m-1]-1);
    mx=max(mx,right[0]);
    for(int i=0;i<t.size()-1;++i){
        mx=max(mx,right[i+1]-left[i]-1);
    }
    printf("%ld",mx);
    return 0;
}
