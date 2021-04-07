#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
#define loop(x,n,a) for(int x =a; x < n;++x)
#define loop_rev(x,n,a) for(int x = n-1; x >= a;--x)
int main(){
    int n,k;
    cin >> n >> k;
    string s;cin >> s;
    vector<int> adj[26];
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            adj[s[i]-'a'].push_back(s[j]-'a');
        }
    }
    queue<int> q1;
    queue<string> q2;
    set<string>res;

}
