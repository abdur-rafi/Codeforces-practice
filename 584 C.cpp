#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
bool comp(PII a,PII b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int bs(vector<int> &a,int val){
    int i=0;
    int j=a.size();
    if(a.empty()) return -1;
    if(a[a.size()-1]<val) return -1;
    if(a[0]>val) return a[0];
    while(i<=j){
        m=(i+j)>>1;
        if(a[m]<val) i=m+1;
        else j=m-1;
    }
    return j+1;
}
int main(){
    int t;
    cin>>t;
    while(--t>=0){
        int n;cin>>n;
        string s;cin>>s;
        vector<int> a[10];
        vector<int> b[10];
        loop(i,n,0){
            a[s[i]-'0'].push_back(i);
        }
        int r=0;
        for(int i=0;i<10;++i){
            if(a[i].empty()) continue;
            int l = bs(a[i],r);
            if(l == -1){
                for(int j=0;j<a[i].size();++j) b[i].push_back(2);
            }
            else{

            }
        }
    }

    return 0;
}
