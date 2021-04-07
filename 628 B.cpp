#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d",&t);
    while(--t>=0){
        int n;scanf("%d",&n);
        set<int> s;
        for(int i=0;i<n;++i){
            int b;scanf("%d",&b);
            s.insert(b);
        }
        printf("%d\n",s.size());
    }

}
