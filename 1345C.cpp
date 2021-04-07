#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;++i) scanf("%d",a+i);
        set<int> s;
        bool pos = true;
        for(int i=0;i<n;++i){
            if(s.empty() == false && s.find(((i+a[i])%n+n)%n) != s.end()){
                pos = false;
                break;
            }
            s.insert(((i+a[i])%n+n)%n);
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
}
